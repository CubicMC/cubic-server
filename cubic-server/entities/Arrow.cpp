#include "Arrow.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"

static inline bool isArrowCollidingPlayer(const Vector3<double> &arrowPosition, const Player &player)
{
    // This whole function is fairly verbose, but the compiler will
    // optimize it out anyway (Or at least I hope, I don't care enough
    // to test that assumption).

    // The player will always have a standing hitbox
    // So the hitbox won't change if the player is crouching
    // I don't think that woud be a problem though as Minecraft
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

    // clang-format off
    return (arrowPosition.x <= mostXPos && arrowPosition.x >= leastXPos) &&
        (arrowPosition.y <= mostYPos && arrowPosition.y >= leastYPos) &&
        (arrowPosition.z <= mostZPos && arrowPosition.z >= leastZPos);
    // clang-format on
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
    {
        for (auto player : _dim->getPlayers()) {
            // TODO(huntears): Check gamemode
            if (isArrowCollidingPlayer(newPosition, *player)) {
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
    }

    Entity::tick();
}

void Arrow::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    addMByte(data, 8, 0x01); // Critical arrow
}
