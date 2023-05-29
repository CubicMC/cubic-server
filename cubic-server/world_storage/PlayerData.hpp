#ifndef BB29A0D8_B040_402D_94D4_111CCB889663
#define BB29A0D8_B040_402D_94D4_111CCB889663

#include "types.hpp"
#include <cstdint>
#include <string>

namespace world_storage {

/**
 * @brief 1:1 mappings of a player's data
 *
 * Some stuff is not implemented yet (Or I just don't know
 * how it works at all/what is the purpose of it).
 * 
 */
struct PlayerData
{
    float absorptionAmount;
    int16_t air;
    // TODO(huntears): Attributes
    // TODO(huntears): Brain
    int32_t dataVersion;
    int16_t deathTime;
    std::string dimension;
    // TODO(huntears): EnderItems
    float fallDistance;
    int8_t fallFlying;
    int32_t fire;
    float health;
    int32_t hurtByTimestamp;
    int16_t hurtTime;
    // TODO(huntears): Inventory
    int8_t invulnerable;
    struct {
        double x; // TODO(huntears): check if those are right
        double y;
        double z;
    } motion;
    int8_t onGround;
    int32_t portalCooldown;
    struct {
        double x; // TODO(huntears): check if those are right
        double y;
        double z;
    } pos;
    struct {
        float yaw; // TODO(huntears): check if those are right
        float pitch;
    } rotation;
    int32_t score;
    int32_t selectedItemSlot;
    int16_t sleepTimer;
    u128 uuid;
    int32_t xpLevel;
    float xpP; //TODO(huntears): What is this ?
    int32_t xpSeed;
    int32_t xpTotal;
    // TODO(huntears): abilities
    float foodExhaustionLevel;
    int32_t foodLevel;
    float foodSaturationLevel;
    int32_t foodTickTimer;
    int32_t playerGameType;
    // TODO(huntears): recipeBook
    int8_t seenCredits;
    // TODO(huntears): warden_spawn_tracker
};

}

#endif /* BB29A0D8_B040_402D_94D4_111CCB889663 */
