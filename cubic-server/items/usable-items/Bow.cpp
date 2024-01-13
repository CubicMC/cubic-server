#include "Bow.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "entities/Arrow.hpp"
#include "entities/Entity.hpp"
#include "items/UsableItem.hpp"
#include "logging/logging.hpp"
#include <cmath>
#include <limits>
#include <numbers>

nbt_tag_t *Items::Bow::setNbtTag()
{
    int32_t DAMAGE = 0;
    int32_t UNBREAKABLE = this->_isUnbreakable;
    std::string_view DAMAGE_TAG = "Damage";
    std::string_view UNBREAKABLE_TAG = "Breakable";
    auto root = nbt_new_tag_compound();
    auto damage = nbt_new_tag_int(DAMAGE);
    auto breakable = nbt_new_tag_int(UNBREAKABLE);
    nbt_set_tag_name(damage, DAMAGE_TAG.data(), DAMAGE_TAG.size());
    nbt_set_tag_name(breakable, UNBREAKABLE_TAG.data(), UNBREAKABLE_TAG.size());
    nbt_tag_compound_append(root, damage);
    nbt_tag_compound_append(root, breakable);

    return root;
}

static constexpr float mcAngleToDegrees(uint8_t angle)
{
    const float simpleAngle = ((float) angle) / std::numeric_limits<uint8_t>::max();
    return simpleAngle * 360.0f;
}

static constexpr double mcAngleToRadian(uint8_t angle)
{
    const double degreeAngle = mcAngleToDegrees(angle);
    const double radianConverter = std::numbers::pi / 180.0f;
    return degreeAngle * radianConverter;
}

static Vector3<double> convertAnglesToHeadingVector(uint8_t yaw, uint8_t pitch)
{
    const double radianYaw = -mcAngleToRadian(yaw);
    const double radianPitch = -mcAngleToRadian(pitch);

    return {
        std::sin(radianYaw) * std::cos(radianPitch),
        std::sin(radianPitch),
        std::cos(radianYaw) * std::cos(radianPitch),
    };
}

void Items::Bow::onUse(std::shared_ptr<Dimension> dim, Entity &user, UNUSED UsabilityType usage)
{
    auto &entityRotation = user.getRotation();
    auto arr = dim->makeEntity<Arrow>(user.getId());

    const double arrowSpeed = 20000.0f; // Close enough to vanilla
    const Vector3<double> directionVector = convertAnglesToHeadingVector(entityRotation.x, entityRotation.z);
    const Vector3<double> weightedVector = directionVector * arrowSpeed;
    const uint8_t arrowRotationSignedYaw = -*((int8_t *) &user.getRotation().x);
    const uint8_t arrowRotationSignedPitch = -*((int8_t *) &user.getRotation().z);
    const Vector2<uint8_t> arrowRotation = {
        *((uint8_t *) &arrowRotationSignedYaw),
        *((uint8_t *) &arrowRotationSignedPitch),
    };

    const float playerHeight = 1.8f;
    const float playerEyePosition = playerHeight * 0.85;
    // This is some random value taken from some old forge forum post, I have absolutely no idea what it is, but it works
    // https://forums.minecraftforge.net/topic/33114-solved-18-change-eye-height-amp-held-item-sizelocation/
    const float startingArrowPosition = user.getPosition().y + playerEyePosition - 0.10000000149011612;

    arr->forceSetPosition(user.getPosition().x, startingArrowPosition, user.getPosition().z);
    arr->setRotation(arrowRotation);
    arr->setVelocity(weightedVector);
    dim->spawnEntity(arr);
    arr->setRotation(arrowRotation);

    for (auto &player : dim->getPlayers()) {
        player->sendEntityVelocity({
            arr->getId(),
            (int16_t) weightedVector.x,
            (int16_t) weightedVector.y,
            (int16_t) weightedVector.z,
        });
    }
}
