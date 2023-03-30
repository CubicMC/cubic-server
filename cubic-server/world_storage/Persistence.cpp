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
#define GET_VALUE(type, dst, src, root) do { \
        auto __tmp = root->getValue(src); \
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

template <typename T, nbt::TagType Tag>
static inline const T *getConstElement(const nbt::Compound *root, const std::string &name)
{
    auto __tmp = root->getValue(name);
    if (!__tmp || __tmp->getType() != Tag)
        throw std::runtime_error(""); // TODO(huntears): Better error message
    return (const T *) __tmp;
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
    GET_VALUE(Double, borderCenterX, "BorderCenterX", data);
    GET_VALUE(Double, borderCenterZ, "BorderCenterZ", data);
    GET_VALUE(Double, borderDamagePerBlock, "BorderDamagePerBlock", data);
    GET_VALUE(Double, borderSafeZone, "BorderSafeZone", data);
    GET_VALUE(Double, borderSize, "BorderSize", data);
    GET_VALUE(Double, borderSizeLerpTarget, "BorderSizeLerpTarget", data);
    GET_VALUE(Long, borderSizeLerpTime, "BorderSizeLerpTime", data);
    GET_VALUE(Double, borderWarningBlocks, "BorderWarningBlocks", data);
    GET_VALUE(Double, borderWarningTime, "BorderWarningTime", data);
    GET_VALUE(Int, dataVersion, "DataVersion", data);
    GET_VALUE(Long, dayTime, "DayTime", data);
    GET_VALUE(Byte, difficulty, "Difficulty", data);
    GET_VALUE(Byte, difficultyLocked, "DifficultyLocked", data);
    GET_VALUE(Int, gameType, "GameType", data);
    GET_VALUE(Long, lastPlayed, "LastPlayed", data);
    GET_VALUE(String, levelName, "LevelName", data);
    GET_VALUE(Float, spawnAngle, "SpawnAngle", data);
    GET_VALUE(Int, spawnX, "SpawnX", data);
    GET_VALUE(Int, spawnY, "SpawnY", data);
    GET_VALUE(Int, spawnZ, "SpawnZ", data);
    GET_VALUE(Long, time, "Time", data);

    const nbt::Compound *__tmpCompound = getConstElement<nbt::Compound, nbt::TagType::Compound>(data, "Version");
    GET_VALUE_TO(Int, id, "Id", __tmpCompound, dest->mcVersion);
    GET_VALUE_TO(String, name, "Name", __tmpCompound, dest->mcVersion);
    GET_VALUE_TO(String, series, "Series", __tmpCompound, dest->mcVersion);
    GET_VALUE_TO(Byte, snapshot, "Snapshot", __tmpCompound, dest->mcVersion);

    GET_VALUE(Int, wanderingTraderSpawnChance, "WanderingTraderSpawnChance", data);
    GET_VALUE(Int, wanderingTraderSpawnDelay, "WanderingTraderSpawnDelay", data);
    GET_VALUE(Byte, wasModded, "WasModded", data);

    __tmpCompound = getConstElement<nbt::Compound, nbt::TagType::Compound>(data, "WorldGenSettings");
    GET_VALUE_TO(Byte, bonus_chest, "bonus_chest", __tmpCompound, dest->worldGenSettings);
    GET_VALUE_TO(Byte, generateFeatures, "generate_features", __tmpCompound, dest->worldGenSettings);
    GET_VALUE_TO(Long, seed, "seed", __tmpCompound, dest->worldGenSettings);

    GET_VALUE(Byte, allowCommands, "allowCommands", data);
    GET_VALUE(Int, clearWeatherTime, "clearWeatherTime", data);
    GET_VALUE(Byte, hardcore, "hardcore", data);
    GET_VALUE(Byte, initialized, "initialized", data);
    GET_VALUE(Int, rainTime, "rainTime", data);
    GET_VALUE(Byte, raining, "raining", data);
    GET_VALUE(Int, thunderTime, "thunderTime", data);
    GET_VALUE(Byte, thundering, "thundering", data);
    GET_VALUE(Int, version, "version", data);

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
    GET_VALUE(Float, absorptionAmount, "AbsorptionAmount", root);
    GET_VALUE(Short, air, "Air", root);
    GET_VALUE(Int, dataVersion, "DataVersion", root);
    GET_VALUE(Short, deathTime, "DeathTime", root);
    GET_VALUE(String, dimension, "Dimension", root);
    GET_VALUE(Float, fallDistance, "FallDistance", root);
    GET_VALUE(Byte, fallFlying, "FallFlying", root);
    GET_VALUE(Short, fire, "Fire", root);
    GET_VALUE(Float, health, "Health", root);
    GET_VALUE(Int, hurtByTimestamp, "HurtByTimestamp", root);
    GET_VALUE(Short, hurtTime, "HurtTime", root);
    GET_VALUE(Byte, invulnerable, "Invulnerable", root);
    {
        auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Motion");
        if (__tmpList->getValues().size() != 3)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Double)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->motion.x = ((nbt::Double *)__tmpList->getValues().at(0))->get_value();
        dest->motion.y = ((nbt::Double *)__tmpList->getValues().at(1))->get_value();
        dest->motion.z = ((nbt::Double *)__tmpList->getValues().at(2))->get_value();
    }
    GET_VALUE(Byte, onGround, "OnGround", root);
    GET_VALUE(Int, portalCooldown, "PortalCooldown", root);
    {
        auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Pos");
        if (__tmpList->getValues().size() != 3)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Double)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->pos.x = ((nbt::Double *)__tmpList->getValues().at(0))->get_value();
        dest->pos.y = ((nbt::Double *)__tmpList->getValues().at(1))->get_value();
        dest->pos.z = ((nbt::Double *)__tmpList->getValues().at(2))->get_value();
    }
    {
        auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Rotation");
        if (__tmpList->getValues().size() != 2)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Float)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->rotation.yaw = ((nbt::Float *)__tmpList->getValues().at(0))->get_value();
        dest->rotation.pitch = ((nbt::Float *)__tmpList->getValues().at(1))->get_value();
    }
    GET_VALUE(Int, score, "Score", root);
    GET_VALUE(Int, selectedItemSlot, "SelectedItemSlot", root);
    GET_VALUE(Short, sleepTimer, "SleepTimer", root);
    {
        auto __tmpArray = getConstElement<nbt::IntArray, nbt::TagType::IntArray>(root, "UUID");
        if (__tmpArray->getValues().size() != 4)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        // I know this is really ugly but augh
        dest->uuid.most = *(uint64_t *)&__tmpArray->getValues().at(0);
        dest->uuid.least = *(uint64_t *)&__tmpArray->getValues().at(2);
        dest->uuid.swapEndianness();
    }
    GET_VALUE(Int, xpLevel, "XpLevel", root);
    GET_VALUE(Float, xpP, "XpP", root);
    GET_VALUE(Int, xpSeed, "XpSeed", root);
    GET_VALUE(Int, xpTotal, "XpTotal", root);
    GET_VALUE(Float, foodExhaustionLevel, "foodExhaustionLevel", root);
    GET_VALUE(Int, foodLevel, "foodLevel", root);
    GET_VALUE(Float, foodSaturationLevel, "foodSaturationLevel", root);
    GET_VALUE(Int, foodTickTimer, "foodTickTimer", root);
    GET_VALUE(Int, playerGameType, "playerGameType", root);
    GET_VALUE(Byte, seenCredits, "seenCredits", root);

    // Clean temporary data
    root->destroy();
    delete root;
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
