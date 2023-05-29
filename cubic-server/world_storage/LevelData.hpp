#ifndef LEVELDATA_HPP
#define LEVELDATA_HPP

#include <cstdint>
#include <string>

namespace world_storage {

/**
 * @brief 1:1 mappings of the level.dat file
 *
 * Some stuff is not implemented yet (Or I just don't know
 * how it works at all/what is the purpose of it).
 *
 */
struct LevelData {
    double borderCenterX;
    double borderCenterZ;
    double borderDamagePerBlock;
    double borderSafeZone;
    double borderSize;
    double borderSizeLerpTarget;
    int64_t borderSizeLerpTime;
    double borderWarningBlocks;
    double borderWarningTime;
    // TODO(huntears): CustomBossEvents
    // TODO(huntears): DataPacks
    int32_t dataVersion;
    int64_t dayTime;
    int8_t difficulty;
    int8_t difficultyLocked;
    // TODO(huntears): DragonFight
    // TODO(huntears): Gamerules
    int32_t gameType;
    int64_t lastPlayed;
    std::string levelName;
    // TODO(huntears): ScheduledEvents
    // TODO(huntears): ServerBrands
    float spawnAngle;
    int32_t spawnX;
    int32_t spawnY;
    int32_t spawnZ;
    int64_t time;
    // Named `Version` in the level.dat file -> Caused a conflict with `version`
    struct {
        int32_t id;
        std::string name;
        std::string series;
        int8_t snapshot;
    } mcVersion;
    int32_t wanderingTraderSpawnChance;
    int32_t wanderingTraderSpawnDelay;
    int8_t wasModded;
    struct {
        int8_t bonus_chest;
        // TODO(huntears): dimensions
        int8_t generateFeatures;
        int64_t seed;
    } worldGenSettings;
    int8_t allowCommands;
    int32_t clearWeatherTime;
    int8_t hardcore;
    int8_t initialized;
    int32_t rainTime;
    int8_t raining;
    int32_t thunderTime;
    int8_t thundering;
    int32_t version;
};

}

#endif // LEVELDATA_HPP
