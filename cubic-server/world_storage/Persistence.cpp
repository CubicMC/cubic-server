#include "Persistence.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
#include "nbt.hpp"
#include "types.hpp"
#include "world_storage/Block.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/LevelData.hpp"
#include "world_storage/PlayerData.hpp"
#include <cstdint>
#include <filesystem>
#include <mutex>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
#include <zlib.h>

// TODO(huntears): Add better error messages
#define GET_VALUE(type, dst, src, root)                       \
    do {                                                      \
        auto __tmp = root->getValue(src);                     \
        if (!__tmp || __tmp->getType() != nbt::TagType::type) \
            throw std::runtime_error("");                     \
        dest->dst = ((nbt::type *) __tmp)->get_value();       \
    } while (0)

#define GET_VALUE_TO(type, dst, src, root, dstroot)           \
    do {                                                      \
        auto __tmp = root->getValue(src);                     \
        if (!__tmp || __tmp->getType() != nbt::TagType::type) \
            throw std::runtime_error("");                     \
        dstroot.dst = ((nbt::type *) __tmp)->get_value();     \
    } while (0)

template <typename T, nbt::TagType Tag> static inline const T *getConstElement(const nbt::Compound *root, const std::string &name)
{
    auto __tmp = root->getValue(name);
    if (!__tmp || __tmp->getType() != Tag)
        throw std::runtime_error(""); // TODO(huntears): Better error message
    return (const T *) __tmp;
}

using namespace world_storage;

namespace world_storage {

Persistence::Persistence(const std::string &level_folder_name):
    level_name(level_folder_name)
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
    auto data = (nbt::Compound *) root->getValue("Data");
    if (!data)
        throw std::runtime_error(""); // TODO(huntears): Better error message

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
        dest->motion.x = ((nbt::Double *) __tmpList->getValues().at(0))->get_value();
        dest->motion.y = ((nbt::Double *) __tmpList->getValues().at(1))->get_value();
        dest->motion.z = ((nbt::Double *) __tmpList->getValues().at(2))->get_value();
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
        dest->pos.x = ((nbt::Double *) __tmpList->getValues().at(0))->get_value();
        dest->pos.y = ((nbt::Double *) __tmpList->getValues().at(1))->get_value();
        dest->pos.z = ((nbt::Double *) __tmpList->getValues().at(2))->get_value();
    }
    {
        auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Rotation");
        if (__tmpList->getValues().size() != 2)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Float)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->rotation.yaw = ((nbt::Float *) __tmpList->getValues().at(0))->get_value();
        dest->rotation.pitch = ((nbt::Float *) __tmpList->getValues().at(1))->get_value();
    }
    GET_VALUE(Int, score, "Score", root);
    GET_VALUE(Int, selectedItemSlot, "SelectedItemSlot", root);
    GET_VALUE(Short, sleepTimer, "SleepTimer", root);
    {
        auto __tmpArray = getConstElement<nbt::IntArray, nbt::TagType::IntArray>(root, "UUID");
        if (__tmpArray->getValues().size() != 4)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        // I know this is really ugly but augh
        dest->uuid.most = *(uint64_t *) &__tmpArray->getValues().at(0);
        dest->uuid.least = *(uint64_t *) &__tmpArray->getValues().at(2);
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

void Persistence::loadPlayerData(const Player *player, PlayerData *dest) { loadPlayerData(player->getUuid(), dest); }

PlayerData Persistence::loadPlayerData(const Player *player) { return loadPlayerData(player->getUuid()); }

int inflatebruh(const void *src, int srcLen, void *dst, int dstLen)
{
    z_stream strm = {0};
    strm.total_in = strm.avail_in = srcLen;
    strm.total_out = strm.avail_out = dstLen;
    strm.next_in = (Bytef *) src;
    strm.next_out = (Bytef *) dst;

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;

    int err = -1;
    int ret = -1;

    err = inflateInit2(&strm, (15 + 32)); // 15 window bits, and the +32 tells zlib to to detect if using gzip or zlib
    if (err == Z_OK) {
        err = inflate(&strm, Z_FINISH);
        if (err == Z_STREAM_END) {
            ret = strm.total_out;
        } else {
            inflateEnd(&strm);
            return err;
        }
    } else {
        inflateEnd(&strm);
        return err;
    }

    inflateEnd(&strm);
    return ret;
}

void Persistence::loadRegion(int x, int z)
{
    std::unique_lock<std::mutex> lock(accessMutex);

    if (regionStore.find({x, z}) != regionStore.end())
        return; // TODO(huntears): Change this later when we can unload regions

    LINFO("Loading region ", x, " ", z);

    regionStore[{x, z}] = {};

    const std::string regionSlice = "r." + std::to_string(x) + "." + std::to_string(z) + ".mca";
    const std::filesystem::path file = std::filesystem::path(level_name) / "region" / regionSlice;

    struct RegionLocation {
        uint32_t data;

        constexpr uint32_t getOffset() const { return ((data & 0x00FF0000) >> 16) | (data & 0x0000FF00) | ((data & 0x000000FF) << 16); }

        constexpr uint8_t getSize() const { return data >> 24; }

        constexpr bool isEmpty() const { return data == 0; }
    };

    struct RegionTimestamp {
        uint32_t data;
    };

    constexpr uint32_t maxXPerRegion = 32;
    constexpr uint32_t maxZPerRegion = 32;
    constexpr uint32_t numChunksPerRegion = maxXPerRegion * maxZPerRegion;

    struct __attribute__((__packed__)) RegionHeader {
        RegionLocation locationTable[numChunksPerRegion];
        RegionLocation timestampTable[numChunksPerRegion];
    };

    struct __attribute__((__packed__)) ChunkHeader {
        uint32_t length;
        uint8_t compressionScheme;

        uint32_t getLength() const { return ntohl(length); }

        uint8_t getCompressionScheme() const { return compressionScheme; }
    };

    std::ifstream testFile(file, std::ios::binary);
    const std::vector<uint8_t> fileContents((std::istreambuf_iterator<char>(testFile)), std::istreambuf_iterator<char>());

    const RegionHeader *header = (const RegionHeader *) fileContents.data();

    // std::cout << "offset : 0x" << std::hex << header->locationTable[0].getOffset() << std::endl;
    // std::cout << "size : 0x" << std::hex << (int) header->locationTable[0].getSize() << std::endl;

    char *buf = (char *) malloc(100000);
    const auto globalPalette = Server::getInstance()->getGlobalPalette();
    for (uint16_t cx = 0; cx < maxXPerRegion; cx++) {
        for (uint16_t cz = 0; cz < maxZPerRegion; cz++) {
            const uint16_t currentOffset = cx + cz * maxXPerRegion;

            if (header->locationTable[currentOffset].isEmpty())
                continue;

            const uint64_t chunkOffset = header->locationTable[currentOffset].getOffset() * 0x1000;

            const ChunkHeader *cHeader = (const ChunkHeader *) (fileContents.data() + chunkOffset);

            // std::cout << "chunk x : " << std::dec << cx << std::endl;
            // std::cout << "chunk z : " << std::dec << cz << std::endl;
            // std::cout << "chunk offset : 0x" << std::hex << chunkOffset << std::endl;
            // std::cout << "chunk length : 0x" << std::hex << cHeader->getLength() << std::endl;
            // std::cout << "chunk compression : 0x" << std::hex << (int) cHeader->getCompressionScheme() << std::endl;

            int ret = inflatebruh(((char *) cHeader) + sizeof(*cHeader), cHeader->getLength() - 1, buf, 100000);

            if (ret == Z_BUF_ERROR) {
                std::cout << "bruh1" << std::endl;
            } else if (ret == Z_MEM_ERROR) {
                std::cout << "bruh2" << std::endl;
            } else if (ret == Z_DATA_ERROR) {
                std::cout << "bruh3" << std::endl;
            }
            // std::cout << "xd : " << ret << std::endl;

            uint8_t *at = (uint8_t *) buf;
            uint8_t *end = ((uint8_t *) buf) + ret - 1;

            auto data = nbt::parseCompound(at, end);

            if (getConstElement<nbt::String, nbt::TagType::String>(data, "Status")->get_value() != "full")
                continue; // TODO(huntears): Handle non complete chunk later somehow

            // std::cout << std::hex << data << std::endl;

            // Fill a chunk
            const auto chunkX = cx + x * 32;
            const auto chunkZ = cz + z * 32;
            auto chunk = new ChunkColumn({chunkX, chunkZ});

            // Section
            const auto sections = getConstElement<nbt::List, nbt::TagType::List>(data, "sections");
            for (const nbt::Base *i : sections->getValues()) {
                if (i->getType() != nbt::TagType::Compound)
                    throw std::runtime_error("");
                const nbt::Compound *section = (const nbt::Compound *) i;
                const auto blockStates = getConstElement<nbt::Compound, nbt::TagType::Compound>(section, "block_states");
                const auto palette = getConstElement<nbt::List, nbt::TagType::List>(blockStates, "palette");
                const auto sizePalette = palette->getValues().size();

                BlockPalette paletteMapping;
                for (const auto ii : palette->getValues()) {
                    if (ii->getType() != nbt::TagType::Compound)
                        throw std::runtime_error("");
                    const nbt::Compound *pal = (const nbt::Compound *) ii;

                    Blocks::Block __tmpBlock = {getConstElement<nbt::String, nbt::TagType::String>(pal, "Name")->get_value(), {}};

                    if (pal->hasValue("Properties")) {
                        for (const auto iii : getConstElement<nbt::Compound, nbt::TagType::Compound>(pal, "Properties")->getValues()) {
                            if (iii->getType() != nbt::TagType::String)
                                throw std::runtime_error("");
                            __tmpBlock.properties.push_back({iii->getName(), ((const nbt::String *) iii)->get_value()});
                        }
                    }

                    paletteMapping.add(globalPalette.fromBlockToProtocolId(__tmpBlock));
                }

                // for (const auto blk : getConstElement<nbt::LongArray, nbt::TagType::LongArray>(blockStates, "data")->getValues()) { }

                if (!blockStates->hasValue("data"))
                    continue; // TODO(huntears): Handle single value palettes properly

                auto dataArray = getConstElement<nbt::LongArray, nbt::TagType::LongArray>(blockStates, "data")->getValues();

                auto bitsPerBlock = paletteMapping.getBytePerEntry();

                uint32_t individualValueMask = (uint32_t) ((1 << bitsPerBlock) - 1);

                for (int ly = 0; ly < SECTION_HEIGHT; ly++) {
                    for (int lz = 0; lz < SECTION_WIDTH; lz++) {
                        for (int lx = 0; lx < SECTION_WIDTH; lx++) {
                            int blockNumber = (((ly * SECTION_HEIGHT) + lz) * SECTION_WIDTH) + lx;
                            int startLong = (blockNumber * bitsPerBlock) / 64;
                            int startOffset = (blockNumber * bitsPerBlock) % 64;
                            int endLong = ((blockNumber + 1) * bitsPerBlock - 1) / 64;

                            uint16_t data;
                            if (startLong == endLong) {
                                data = (uint16_t) (dataArray[startLong] >> startOffset);
                            } else {
                                int endOffset = 64 - startOffset;
                                data = (uint16_t) (dataArray[startLong] >> startOffset | dataArray[endLong] << endOffset);
                            }
                            data &= individualValueMask;

                            auto sectionY = getConstElement<nbt::Byte, nbt::TagType::Byte>(section, "Y");

                            chunk->_blocks.at(calculateBlockIdx({lx, ly + 16 * sectionY->get_value(), lz})) = paletteMapping.getGlobalId(data);
                        }
                    }
                }
            }

            // Heightmaps
            const auto heightmaps = getConstElement<nbt::Compound, nbt::TagType::Compound>(data, "Heightmaps");

            const auto motionBlocking = getConstElement<nbt::LongArray, nbt::TagType::LongArray>(heightmaps, "MOTION_BLOCKING")->getValues();
            for (auto i = 0; i < motionBlocking.size(); i++) {
                chunk->_heightMap.motionBlocking.at(i) = motionBlocking.at(i);
            }

            const auto worldSurface = getConstElement<nbt::LongArray, nbt::TagType::LongArray>(heightmaps, "WORLD_SURFACE")->getValues();
            for (auto i = 0; i < worldSurface.size(); i++) {
                chunk->_heightMap.worldSurface.at(i) = worldSurface.at(i);
            }

            regionStore.at({x, z})[{cx, cz}] = chunk;

            data->destroy();
            delete data;
        }
    }
    free(buf);
    LINFO("Loaded region ", x, " ", z);
}

bool Persistence::isChunkLoaded(int x, int z)
{
    const int rx = x / 32;
    const int rz = z / 32;

    this->loadRegion(rx, rz);
    if (!regionStore.contains({rx, rz}))
        return false;
    return regionStore.at({rz, rz}).contains({x - rx * 32, z - rz * 32});
}

}
