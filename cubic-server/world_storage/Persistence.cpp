#include "Persistence.hpp"
#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/Logger.hpp"
#include "nbt.h"
#include "nbt.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Level.hpp"
#include "world_storage/LevelData.hpp"
#include "world_storage/PlayerData.hpp"
#include "world_storage/Section.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <memory>
#include <mutex>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
#include <zlib.h>

// TODO(huntears): Add better error messages
#define GET_VALUE(type, dst, src, root)                                        \
    do {                                                                       \
        auto __tmp = root->getValue(src);                                      \
        if (!__tmp || __tmp->getType() != nbt::TagType::type)                  \
            throw std::runtime_error("");                                      \
        dest->dst = (std::dynamic_pointer_cast<nbt::type>(__tmp))->getValue(); \
    } while (0)

#define GET_VALUE_TO(type, dst, src, root, dstroot)                              \
    do {                                                                         \
        auto __tmp = root->getValue(src);                                        \
        if (!__tmp || __tmp->getType() != nbt::TagType::type)                    \
            throw std::runtime_error("");                                        \
        dstroot.dst = (std::dynamic_pointer_cast<nbt::type>(__tmp))->getValue(); \
    } while (0)

template<typename T, nbt::TagType Tag>
static inline const std::shared_ptr<T> getConstElement(const std::shared_ptr<nbt::Compound> root, const std::string &name)
{
    auto __tmp = root->getValue(name);
    if (!__tmp || __tmp->getType() != Tag)
        throw std::runtime_error(""); // TODO(huntears): Better error message
    return std::dynamic_pointer_cast<T>(__tmp);
}

using namespace world_storage;

namespace world_storage {

Persistence::Persistence(std::weak_ptr<World> world, const std::string &folder):
    _folder(folder),
    _world(world)
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

    const std::filesystem::path file = std::filesystem::path(_folder) / "level.dat";
    std::vector<uint8_t> unzippedData;
    this->uncompressFile(file, unzippedData);

    // Parse data
    uint8_t *start = unzippedData.data();
    auto root = nbt::parseCompound(start, start + unzippedData.size() - 1);

    // Map data
    auto data = std::dynamic_pointer_cast<nbt::Compound>(root->getValue("Data"));
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

    {
        const auto __tmpCompound = getConstElement<nbt::Compound, nbt::TagType::Compound>(data, "Version");
        GET_VALUE_TO(Int, id, "Id", __tmpCompound, dest->mcVersion);
        GET_VALUE_TO(String, name, "Name", __tmpCompound, dest->mcVersion);
        GET_VALUE_TO(String, series, "Series", __tmpCompound, dest->mcVersion);
        GET_VALUE_TO(Byte, snapshot, "Snapshot", __tmpCompound, dest->mcVersion);
    }

    GET_VALUE(Int, wanderingTraderSpawnChance, "WanderingTraderSpawnChance", data);
    GET_VALUE(Int, wanderingTraderSpawnDelay, "WanderingTraderSpawnDelay", data);
    GET_VALUE(Byte, wasModded, "WasModded", data);

    {
        const auto __tmpCompound = getConstElement<nbt::Compound, nbt::TagType::Compound>(data, "WorldGenSettings");
        GET_VALUE_TO(Byte, bonus_chest, "bonus_chest", __tmpCompound, dest->worldGenSettings);
        GET_VALUE_TO(Byte, generateFeatures, "generate_features", __tmpCompound, dest->worldGenSettings);
        GET_VALUE_TO(Long, seed, "seed", __tmpCompound, dest->worldGenSettings);
    }

    GET_VALUE(Byte, allowCommands, "allowCommands", data);
    GET_VALUE(Int, clearWeatherTime, "clearWeatherTime", data);
    GET_VALUE(Byte, hardcore, "hardcore", data);
    GET_VALUE(Byte, initialized, "initialized", data);
    GET_VALUE(Int, rainTime, "rainTime", data);
    GET_VALUE(Byte, raining, "raining", data);
    GET_VALUE(Int, thunderTime, "thunderTime", data);
    GET_VALUE(Byte, thundering, "thundering", data);
    GET_VALUE(Int, version, "version", data);
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
    const std::filesystem::path file = std::filesystem::path(_folder) / "playerdata" / (uuid.toString() + ".dat");
    std::vector<uint8_t> unzippedData;
    this->uncompressFile(file, unzippedData);

    // Parse data
    uint8_t *start = unzippedData.data();
    auto root = nbt::parseCompound(start, start + unzippedData.size() - 1);

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
        const auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Motion");
        if (__tmpList->getValues().size() != 3)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Double)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->motion.x = (std::dynamic_pointer_cast<nbt::Double>(__tmpList->getValues().at(0)))->getValue();
        dest->motion.y = (std::dynamic_pointer_cast<nbt::Double>(__tmpList->getValues().at(1)))->getValue();
        dest->motion.z = (std::dynamic_pointer_cast<nbt::Double>(__tmpList->getValues().at(2)))->getValue();
    }
    GET_VALUE(Byte, onGround, "OnGround", root);
    GET_VALUE(Int, portalCooldown, "PortalCooldown", root);
    {
        const auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Pos");
        if (__tmpList->getValues().size() != 3)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Double)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->pos.x = (std::dynamic_pointer_cast<nbt::Double>(__tmpList->getValues().at(0)))->getValue();
        dest->pos.y = (std::dynamic_pointer_cast<nbt::Double>(__tmpList->getValues().at(1)))->getValue();
        dest->pos.z = (std::dynamic_pointer_cast<nbt::Double>(__tmpList->getValues().at(2)))->getValue();
    }
    {
        auto __tmpList = getConstElement<nbt::List, nbt::TagType::List>(root, "Rotation");
        if (__tmpList->getValues().size() != 2)
            throw std::runtime_error(""); // TODO(huntears): Better error message
        for (auto i : __tmpList->getValues())
            if (i->getType() != nbt::TagType::Float)
                throw std::runtime_error(""); // TODO(huntears): Better error message
        dest->rotation.yaw = (std::dynamic_pointer_cast<nbt::Float>(__tmpList->getValues().at(0)))->getValue();
        dest->rotation.pitch = (std::dynamic_pointer_cast<nbt::Float>(__tmpList->getValues().at(1)))->getValue();
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

#include <sys/stat.h>

static int64_t getFileSize(const std::string &filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

struct _userData {
    char *start;
    char *end;
};

static size_t _readMem(void *ud, uint8_t *d, size_t s)
{
    // TODO
    _userData *u = (_userData *) ud;
    if (u->start > u->end)
        return 0;
    const auto max = ((size_t) u->end) - ((size_t) u->start) + 1;
    const auto toCopy = std::min(max, s);
    memcpy(d, u->start, toCopy);
    u->start += toCopy;
    return toCopy;
}

void Persistence::loadRegion(Dimension &dim, int x, int z)
{
    std::unique_lock<std::mutex> lock(accessMutex);

    if (std::find(regionStore.begin(), regionStore.end(), Position2D(x, z)) != regionStore.end())
        return; // TODO(huntears): Change this later when we can unload regions

    LDEBUG("Loading region ", x, " ", z);

    regionStore.emplace_back(x, z);

    const std::string regionSlice = "r." + std::to_string(x) + "." + std::to_string(z) + ".mca";
    const std::filesystem::path file = std::filesystem::path(_folder) / "region" / regionSlice;

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

    if (!std::filesystem::exists(file))
        return;

    auto fileSize = getFileSize(file);
    if (fileSize == -1)
        return;

    char *fileContents = (char *) malloc(fileSize);

    FILE *openedFile = fopen(file.c_str(), "r");

    auto ret = fread(fileContents, 1, fileSize, openedFile);

    if (ret != (size_t) fileSize) {
        LERROR("Bruh");
        free(fileContents);
        return;
    }

    const RegionHeader *header = (const RegionHeader *) fileContents;

    const auto globalPalette = Server::getInstance()->getGlobalPalette();
    for (uint16_t cx = 0; cx < maxXPerRegion; cx++) {
        for (uint16_t cz = 0; cz < maxZPerRegion; cz++) {
            const uint16_t currentOffset = cx + cz * maxXPerRegion;

            if (header->locationTable[currentOffset].isEmpty())
                continue;

            const uint64_t chunkOffset = header->locationTable[currentOffset].getOffset() * 0x1000;

            const ChunkHeader *cHeader = (const ChunkHeader *) (fileContents + chunkOffset);

            // clang-format off
            _userData ud = {
                ((char *) cHeader) + sizeof(*cHeader),
                ((char *) cHeader) + sizeof(*cHeader) + cHeader->getLength() - 1
            };
            // clang-format on

            // clang-format off
            nbt_reader_t reader = {
                _readMem,
                &ud
            };
            // clang-format on

            auto *data = nbt_parse(reader, NBT_PARSE_FLAG_USE_ZLIB);
            assert(data->type == NBT_TYPE_COMPOUND);

            auto status = nbt_tag_compound_get(data, "Status");
            assert(status);
            if (status->tag_string.size != sizeof("full") - 1 || strcmp(status->tag_string.value, "full"))
                continue; // TODO(huntears): Handle non complete chunk later somehow

            // Fill a chunk
            const auto chunkX = cx + x * 32;
            const auto chunkZ = cz + z * 32;

            auto &chunk = dim.getLevel().addChunkColumn(Position2D(chunkX, chunkZ));

            // Section
            auto *sections = nbt_tag_compound_get(data, "sections");
            assert(sections);
            assert(sections->type == NBT_TYPE_LIST);
            for (size_t currentSection = 0; currentSection < sections->tag_list.size; currentSection++) {
                auto *section = nbt_tag_list_get(sections, currentSection);
                assert(section->type == NBT_TYPE_COMPOUND);

                auto *blockStates = nbt_tag_compound_get(section, "block_states");
                assert(blockStates);
                assert(blockStates->type == NBT_TYPE_COMPOUND);
                auto *palette = nbt_tag_compound_get(blockStates, "palette");
                assert(palette);
                assert(palette->type == NBT_TYPE_LIST);

                auto *sectionYnbt = nbt_tag_compound_get(section, "Y");
                assert(sectionYnbt);
                assert(sectionYnbt->type == NBT_TYPE_BYTE);
                const uint8_t sectionY = sectionYnbt->tag_byte.value + 5;

                BlockPalette &paletteMapping = chunk.getSection(sectionY).getBlockPalette();
                for (size_t ii = 0; ii < palette->tag_list.size; ii++) {
                    auto *pal = nbt_tag_list_get(palette, ii);
                    assert(pal->type == NBT_TYPE_COMPOUND);

                    auto *name = nbt_tag_compound_get(pal, "Name");
                    assert(name);
                    assert(name->type == NBT_TYPE_STRING);

                    Blocks::Block __tmpBlock(std::string(name->tag_string.value, name->tag_string.size), {});

                    auto *properties = nbt_tag_compound_get(pal, "Properties");
                    if (properties) {
                        assert(properties->type == NBT_TYPE_COMPOUND);
                        for (size_t iii = 0; iii < properties->tag_compound.size; iii++) {
                            auto *prop = nbt_tag_compound_getidx(properties, iii);
                            assert(prop->type == NBT_TYPE_STRING);
                            // clang-format off
                            __tmpBlock.properties.push_back({
                                std::string(prop->name, prop->name_size),
                                std::string(prop->tag_string.value, prop->tag_string.size)
                            });
                            // clang-format on
                        }
                    }

                    paletteMapping.add(globalPalette.fromBlockToProtocolId(__tmpBlock));
                }

                auto *dataArray = nbt_tag_compound_get(blockStates, "data");
                if (!dataArray)
                    continue; // TODO(huntears): Handle single value palettes properly

                assert(dataArray->type == NBT_TYPE_LONG_ARRAY);

                chunk.getSection(sectionY).getBlocks().setValueSize(paletteMapping.getBits());
                chunk.getSection(sectionY).getBlocks().data().clear();

                // clang-format off
                chunk.getSection(sectionY).getBlocks().data().insert(
                    chunk.getSection(sectionY).getBlocks().begin(),
                    dataArray->tag_long_array.value,
                    dataArray->tag_long_array.value + dataArray->tag_long_array.size
                );
                // clang-format on

                auto *blockLights = nbt_tag_compound_get(section, "BlockLight");
                if (blockLights) {
                    assert(blockLights->type == NBT_TYPE_BYTE_ARRAY);

                    chunk.getSection(sectionY).getBlockLights().setValueSize(4);
                    chunk.getSection(sectionY).getBlockLights().data().clear();
                    // clang-format off
                    chunk.getSection(sectionY).getBlockLights().data().insert(
                        chunk.getSection(sectionY).getBlockLights().begin(),
                        blockLights->tag_byte_array.value,
                        blockLights->tag_byte_array.value + blockLights->tag_byte_array.size
                    );
                    // clang-format on
                    chunk.getSection(sectionY).recalculateBlockLightCount();
                } else
                    chunk.getSection(sectionY).recalculateBlockLight();

                auto *skyLights = nbt_tag_compound_get(section, "SkyLight");
                if (skyLights) {
                    assert(skyLights->type == NBT_TYPE_BYTE_ARRAY);

                    chunk.getSection(sectionY).getSkyLights().setValueSize(4);
                    chunk.getSection(sectionY).getSkyLights().data().clear();
                    // clang-format off
                    chunk.getSection(sectionY).getSkyLights().data().insert(
                        chunk.getSection(sectionY).getSkyLights().begin(),
                        skyLights->tag_byte_array.value,
                        skyLights->tag_byte_array.value + skyLights->tag_byte_array.size
                    );
                    // clang-format on
                    chunk.getSection(sectionY).recalculateSkyLightCount();
                } else
                    chunk.getSection(sectionY).recalculateSkyLight();
            }

            // Heightmaps
            auto *heightmaps = nbt_tag_compound_get(data, "Heightmaps");
            assert(heightmaps);
            assert(heightmaps->type == NBT_TYPE_COMPOUND);

            auto motionBlocking = std::make_shared<nbt::LongArray>("MOTION_BLOCKING");
            auto *_motionBlocking = nbt_tag_compound_get(heightmaps, "MOTION_BLOCKING");
            assert(_motionBlocking);
            assert(_motionBlocking->type == NBT_TYPE_LONG_ARRAY);
            for (size_t h = 0; h < _motionBlocking->tag_long_array.size; h++)
                motionBlocking->getValues().push_back(_motionBlocking->tag_long_array.value[h]);
            chunk._heightMap.addValue(motionBlocking);

            auto worldSurface = std::make_shared<nbt::LongArray>("WORLD_SURFACE");
            auto *_worldSurface = nbt_tag_compound_get(heightmaps, "WORLD_SURFACE");
            assert(_worldSurface);
            assert(_worldSurface->type == NBT_TYPE_LONG_ARRAY);
            for (size_t h = 0; h < _worldSurface->tag_long_array.size; h++)
                worldSurface->getValues().push_back(_worldSurface->tag_long_array.value[h]);
            chunk._heightMap.addValue(worldSurface);

            chunk._ready = true;

            nbt_free_tag(data);
        }
    }
    free(fileContents);
    LDEBUG("Loaded region ", x, " ", z);
}

bool Persistence::isChunkLoaded(Dimension &dim, int x, int z)
{
    const int rx = transformChunkPosToRegionPos(x);
    const int rz = transformChunkPosToRegionPos(z);

    this->loadRegion(dim, rx, rz);
    if (std::find(regionStore.begin(), regionStore.end(), Position2D(rx, rz)) == regionStore.end())
        return false;

    auto cx = x % 32;
    auto cz = z % 32;
    if (cx < 0)
        cx += 32;
    if (cz < 0)
        cz += 32;
    return dim.hasChunkLoaded(x, z);
}
}
