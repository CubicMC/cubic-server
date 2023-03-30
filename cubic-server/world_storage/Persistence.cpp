#include "Persistence.hpp"
#include "nbt.hpp"
#include "world_storage/LevelData.hpp"
#include <cstdint>
#include <mutex>
#include <stdexcept>
#include <string_view>
#include <vector>
#include <zlib.h>
#include <filesystem>
#include "logging/Logger.hpp"
#include "world_storage/PlayerData.hpp"

// TODO(huntears): Add better error messages
#define GET_VALUE(type, dst, src) do { \
        auto __tmp = data->getValue(src); \
        if (!__tmp || __tmp->getType() != nbt::TagType::type) \
            throw std::runtime_error(""); \
        dest-> dst = ((nbt::type *)__tmp)->get_value(); \
    } while (0)

#define GET_VALUE_TO(type, dst, src, root, dstroot) do { \
        auto __tmp = root->getValue(src); \
        if (!__tmp || __tmp->getType() != nbt::TagType::type) \
            throw std::runtime_error(""); \
        dstroot . dst = ((nbt::type *)__tmp)->get_value(); \
    } while (0)

static inline const nbt::Compound *getConstCompound(const nbt::Compound *root, const std::string &name)
{
    auto __tmp = root->getValue(name);
    if (!__tmp || __tmp->getType() != nbt::TagType::Compound)
        throw std::runtime_error(""); // TODO(huntears): Better error message
    return (const nbt::Compound *) __tmp;
}

using namespace world_storage;

namespace world_storage {

Persistence::Persistence(const std::string &level_folder_name)
    : level_name(level_folder_name)
{
}

void Persistence::uncompressFile(const std::string &filepath, std::vector<uint8_t> &data)
{
    // Thanks StackOverflow
    // https://stackoverflow.com/a/17062022
    constexpr uint64_t readBufferSize = 8192;

    gzFile inFileZ = gzopen(filepath.c_str(), "rb");
    if (inFileZ == NULL)
        throw std::runtime_error("Error: Failed to gzopen " + filepath);

    uint8_t unzipBuffer[readBufferSize];
    unsigned int unzippedBytes;
    while (true) {
        unzippedBytes = gzread(inFileZ, unzipBuffer, readBufferSize);
        if (unzippedBytes > 0) {
            data.insert(data.end(), unzipBuffer, unzipBuffer + unzippedBytes);
        } else {
            break;
        }
    }
    gzclose(inFileZ);
}

void Persistence::loadLevelData(LevelData *dest)
{
    std::unique_lock<std::mutex> lock(accessMutex);

    const std::filesystem::path file = std::filesystem::path(level_name) / "level.dat";
    std::vector<uint8_t> unzippedData;
    this->uncompressFile(file, unzippedData);

    // Parse data
    uint8_t *start = unzippedData.data();
    nbt::Compound *root = nbt::parseCompound(start, start + unzippedData.size() - 1);

    // Map data
    auto data = (nbt::Compound *)root->getValue("Data");
    if (!data)
        throw std::runtime_error(""); //TODO(huntears): Better error message
    
    // TODO(huntears): Find a better way to map the values
    GET_VALUE(Double, borderCenterX, "BorderCenterX");
    GET_VALUE(Double, borderCenterZ, "BorderCenterZ");
    GET_VALUE(Double, borderDamagePerBlock, "BorderDamagePerBlock");
    GET_VALUE(Double, borderSafeZone, "BorderSafeZone");
    GET_VALUE(Double, borderSize, "BorderSize");
    GET_VALUE(Double, borderSizeLerpTarget, "BorderSizeLerpTarget");
    GET_VALUE(Long, borderSizeLerpTime, "BorderSizeLerpTime");
    GET_VALUE(Double, borderWarningBlocks, "BorderWarningBlocks");
    GET_VALUE(Double, borderWarningTime, "BorderWarningTime");
    GET_VALUE(Int, dataVersion, "DataVersion");
    GET_VALUE(Long, dayTime, "DayTime");
    GET_VALUE(Byte, difficulty, "Difficulty");
    GET_VALUE(Byte, difficultyLocked, "DifficultyLocked");
    GET_VALUE(Int, gameType, "GameType");
    GET_VALUE(Long, lastPlayed, "LastPlayed");
    GET_VALUE(String, levelName, "LevelName");
    GET_VALUE(Float, spawnAngle, "SpawnAngle");
    GET_VALUE(Int, spawnX, "SpawnX");
    GET_VALUE(Int, spawnY, "SpawnY");
    GET_VALUE(Int, spawnZ, "SpawnZ");
    GET_VALUE(Long, time, "Time");

    const nbt::Compound *__tmpCompound = getConstCompound(data, "Version");
    GET_VALUE_TO(Int, id, "Id", __tmpCompound, dest->mcVersion);
    GET_VALUE_TO(String, name, "Name", __tmpCompound, dest->mcVersion);
    GET_VALUE_TO(String, series, "Series", __tmpCompound, dest->mcVersion);
    GET_VALUE_TO(Byte, snapshot, "Snapshot", __tmpCompound, dest->mcVersion);

    GET_VALUE(Int, wanderingTraderSpawnChance, "WanderingTraderSpawnChance");
    GET_VALUE(Int, wanderingTraderSpawnDelay, "WanderingTraderSpawnDelay");
    GET_VALUE(Byte, wasModded, "WasModded");

    __tmpCompound = getConstCompound(data, "WorldGenSettings");
    GET_VALUE_TO(Byte, bonus_chest, "bonus_chest", __tmpCompound, dest->worldGenSettings);
    GET_VALUE_TO(Byte, generateFeatures, "generate_features", __tmpCompound, dest->worldGenSettings);
    GET_VALUE_TO(Long, seed, "seed", __tmpCompound, dest->worldGenSettings);

    GET_VALUE(Byte, allowCommands, "allowCommands");
    GET_VALUE(Int, clearWeatherTime, "clearWeatherTime");
    GET_VALUE(Byte, hardcore, "hardcore");
    GET_VALUE(Byte, initialized, "initialized");
    GET_VALUE(Int, rainTime, "rainTime");
    GET_VALUE(Byte, raining, "raining");
    GET_VALUE(Int, thunderTime, "thunderTime");
    GET_VALUE(Byte, thundering, "thundering");
    GET_VALUE(Int, version, "version");

    // Clean temporary data
    root->destroy();
    delete root;
}

LevelData Persistence::loadLevelData()
{
    LevelData data;

    this->loadLevelData(&data);
    // I sure do hope this gets inlined T_T
    return data;
}

void Persistence::loadPlayerData(u128 uuid, PlayerData *dest)
{
    std::unique_lock<std::mutex> lock(accessMutex);

    // TODO
    const std::filesystem::path file = std::filesystem::path(level_name) / "playerdata" / (uuid.toString() + ".dat");
    std::vector<uint8_t> unzippedData;
    this->uncompressFile(file, unzippedData);

    // Parse data
    uint8_t *start = unzippedData.data();
    nbt::Compound *root = nbt::parseCompound(start, start + unzippedData.size() - 1);

    // TODO(huntears): Map the values to the destination object

}

PlayerData Persistence::loadPlayerData(u128 uuid)
{
    PlayerData data;

    this->loadPlayerData(uuid, &data);
    return data;
}

void Persistence::loadPlayerData(const Player *player, PlayerData *dest)
{
    loadPlayerData(player->getUuid(), dest);
}

PlayerData Persistence::loadPlayerData(const Player *player)
{
    return loadPlayerData(player->getUuid());
}

}
