#include "Arrow.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "PlayerAttributes.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"

// For all that intersection code, thank you to that guy:
// https://3dkingdoms.com/weekly/weekly.php?a=3
static inline bool getIntersectionLineBox(double fDst1, double fDst2, Vector3<double> p1, Vector3<double> p2, Vector3<double> &hit)
{
    if ((fDst1 * fDst2) >= 0.0f)
        return false;
    if (fDst1 == fDst2)
        return false;
    hit = p1 + (p2 - p1) * (-fDst1 / (fDst2 - fDst1));
    return true;
}

static inline bool isHitInBox(Vector3<double> Hit, Vector3<double> B1, Vector3<double> B2, const int Axis)
{
    if (Axis == 1 && Hit.z >= B1.z && Hit.z <= B2.z && Hit.y >= B1.y && Hit.y <= B2.y)
        return true;
    if (Axis == 2 && Hit.z >= B1.z && Hit.z <= B2.z && Hit.x >= B1.x && Hit.x <= B2.x)
        return true;
    if (Axis == 3 && Hit.x >= B1.x && Hit.x <= B2.x && Hit.y >= B1.y && Hit.y <= B2.y)
        return true;
    return false;
}

static bool isLineIntersectingWithBox(Vector3<double> B1, Vector3<double> B2, Vector3<double> L1, Vector3<double> L2, Vector3<double> &Hit)
{
    if (L2.x < B1.x && L1.x < B1.x)
        return false;
    if (L2.x > B2.x && L1.x > B2.x)
        return false;
    if (L2.y < B1.y && L1.y < B1.y)
        return false;
    if (L2.y > B2.y && L1.y > B2.y)
        return false;
    if (L2.z < B1.z && L1.z < B1.z)
        return false;
    if (L2.z > B2.z && L1.z > B2.z)
        return false;
    if (L1.x > B1.x && L1.x < B2.x && L1.y > B1.y && L1.y < B2.y && L1.z > B1.z && L1.z < B2.z) {
        Hit = L1;
        return true;
    }
    return (
        (getIntersectionLineBox(L1.x - B1.x, L2.x - B1.x, L1, L2, Hit) && isHitInBox(Hit, B1, B2, 1)) ||
        (getIntersectionLineBox(L1.y - B1.y, L2.y - B1.y, L1, L2, Hit) && isHitInBox(Hit, B1, B2, 2)) ||
        (getIntersectionLineBox(L1.z - B1.z, L2.z - B1.z, L1, L2, Hit) && isHitInBox(Hit, B1, B2, 3)) ||
        (getIntersectionLineBox(L1.x - B2.x, L2.x - B2.x, L1, L2, Hit) && isHitInBox(Hit, B1, B2, 1)) ||
        (getIntersectionLineBox(L1.y - B2.y, L2.y - B2.y, L1, L2, Hit) && isHitInBox(Hit, B1, B2, 2)) ||
        (getIntersectionLineBox(L1.z - B2.z, L2.z - B2.z, L1, L2, Hit) && isHitInBox(Hit, B1, B2, 3))
    );
}

static inline bool isArrowCollidingPlayer(const Vector3<double> &previousArrowPosition, const Vector3<double> &arrowPosition, const Player &player)
{
    // This whole function is fairly verbose, but the compiler will
    // optimize it out anyway (Or at least I hope, I don't care enough
    // to test that assumption).

    // The player will always have a standing hitbox
    // So the hitbox won't change if the player is crouching
    // I don't think that would be a problem though as Minecraft
    // arrows are already kinda scuffed in their own way :3
    constexpr double playerWidth = 0.6;
    constexpr double playerHeight = 1.8;
    constexpr double playerHalfWidth = playerWidth / 2;

    const Vector3<double> &playerPosition = player.getPosition();
    const double mostZPos = playerPosition.z + playerHalfWidth;
    const double leastZPos = playerPosition.z - playerHalfWidth;
    const double mostXPos = playerPosition.x + playerHalfWidth;
    const double leastXPos = playerPosition.x - playerHalfWidth;
    const double mostYPos = playerPosition.y + playerHeight;
    const double leastYPos = playerPosition.y;

    Vector3<double> hit;
    Vector3<double> B1 = {leastXPos, leastYPos, leastZPos};
    Vector3<double> B2 = {mostXPos, mostYPos, mostZPos};
    if (isLineIntersectingWithBox(B1, B2, arrowPosition, previousArrowPosition, hit)) {
        LDEBUG("Hit player at point {}, player with bounding box {} to {}, arrow with positions {} to {}", hit, B1, B2, previousArrowPosition, arrowPosition);
        return true;
    }
    return false;
}

void Arrow::tick()
{
    constexpr double baseBlocksPerTicks = 1.0 / 8000.0;
    const Vector3<double> position = this->getPosition();
    const Vector3<double> velocity = this->getVelocity();

    const Vector3<double> newVelocity = {
        velocity.x * 0.99,
        velocity.y * 0.99 - (8000.0f / 20.0f),
        velocity.z * 0.99,
    };
    this->setVelocity(newVelocity);

    for (auto &player : _dim->getPlayers()) {
        player->sendEntityVelocity({
            _id,
            (int16_t) _velocity.x,
            (int16_t) _velocity.y,
            (int16_t) _velocity.z,
        });
    }

    const Vector3<double> movement = newVelocity * baseBlocksPerTicks;
    const Vector3<double> newPosition = movement + position;
    this->setPosition(newPosition, false);

    // Collision checks with players
    for (auto player : _dim->getPlayers()) {
        // Yes the shooter cannot shoot itself and that is different from vanilla
        // But I clearly don't care enough to implement this properly :)
        if (player->getId() == _shotByEntity)
            continue;
        auto playerGamemode = player->getGamemode();
        if (playerGamemode == player_attributes::Gamemode::Creative || playerGamemode == player_attributes::Gamemode::Spectator)
            continue;
        if (isArrowCollidingPlayer(position, newPosition, *player)) {
            constexpr float baseArrowDamage = 2.0;
            const float arrowSpeed = ((float) _velocity.magnitude()) / 8000.0f;
            const float damageToApply = baseArrowDamage * arrowSpeed;

            // We can assume that the damage source comes from the
            // previous position of the arrow, as this should give us
            // the best knockback value.
            player->attack(damageToApply, position);
            break;
        }
    }

    Entity::tick();
}

void Arrow::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    addMByte(data, 8, 0x01); // Critical arrow
}
