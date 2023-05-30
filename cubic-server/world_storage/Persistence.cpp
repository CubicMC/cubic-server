#include "Persistence.hpp"
#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"
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
#include <sys/stat.h>
#include <vector>
#include <zlib.h>

// TODO(huntears): Add better error messages
#define GET_VALUE(t, type_accessor, dst, src, root)    \
    do {                                               \
        auto *__tmp = nbt_tag_compound_get(root, src); \
        assert(__tmp);                                 \
        assert(__tmp->type == t);                      \
        dest.dst = __tmp->type_accessor.value;         \
    } while (0)

#define GET_VALUE_BYTE(dst, src, root) GET_VALUE(NBT_TYPE_BYTE, tag_byte, dst, src, root)
#define GET_VALUE_INT(dst, src, root) GET_VALUE(NBT_TYPE_INT, tag_int, dst, src, root)
#define GET_VALUE_SHORT(dst, src, root) GET_VALUE(NBT_TYPE_SHORT, tag_short, dst, src, root)
#define GET_VALUE_LONG(dst, src, root) GET_VALUE(NBT_TYPE_LONG, tag_long, dst, src, root)
#define GET_VALUE_FLOAT(dst, src, root) GET_VALUE(NBT_TYPE_FLOAT, tag_float, dst, src, root)
#define GET_VALUE_DOUBLE(dst, src, root) GET_VALUE(NBT_TYPE_DOUBLE, tag_double, dst, src, root)
#define GET_VALUE_STRING(dst, src, root)                                         \
    do {                                                                         \
        auto *__tmp = nbt_tag_compound_get(root, src);                           \
        assert(__tmp);                                                           \
        assert(__tmp->type == NBT_TYPE_STRING);                                  \
        dest.dst = std::string(__tmp->tag_string.value, __tmp->tag_string.size); \
    } while (0)

#define GET_VALUE_TO(t, type_accessor, dst, src, root, dstroot) \
    do {                                                        \
        auto *__tmp = nbt_tag_compound_get(root, src);          \
        assert(__tmp);                                          \
        assert(__tmp->type == t);                               \
        dstroot.dst = __tmp->type_accessor.value;               \
    } while (0)

#define GET_VALUE_TO_BYTE(dst, src, root, dstroot) GET_VALUE_TO(NBT_TYPE_BYTE, tag_byte, dst, src, root, dstroot)
#define GET_VALUE_TO_INT(dst, src, root, dstroot) GET_VALUE_TO(NBT_TYPE_INT, tag_int, dst, src, root, dstroot)
#define GET_VALUE_TO_SHORT(dst, src, root, dstroot) GET_VALUE_TO(NBT_TYPE_SHORT, tag_short, dst, src, root, dstroot)
#define GET_VALUE_TO_LONG(dst, src, root, dstroot) GET_VALUE_TO(NBT_TYPE_LONG, tag_long, dst, src, root, dstroot)
#define GET_VALUE_TO_FLOAT(dst, src, root, dstroot) GET_VALUE_TO(NBT_TYPE_FLOAT, tag_float, dst, src, root, dstroot)
#define GET_VALUE_TO_DOUBLE(dst, src, root, dstroot) GET_VALUE_TO(NBT_TYPE_DOUBLE, tag_double, dst, src, root, dstroot)
#define GET_VALUE_TO_STRING(dst, src, root, dstroot)                                \
    do {                                                                            \
        auto *__tmp = nbt_tag_compound_get(root, src);                              \
        assert(__tmp);                                                              \
        assert(__tmp->type == NBT_TYPE_STRING);                                     \
        dstroot.dst = std::string(__tmp->tag_string.value, __tmp->tag_string.size); \
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

Persistence::Persistence(const std::string &folder):
    _folder(folder)
{
}

struct _userData {
    char *start;
    char *end;
};

static size_t _readMem(void *ud, uint8_t *d, size_t s)
{
    _userData *u = (_userData *) ud;
    if (u->start > u->end)
        return 0;
    const auto max = ((size_t) u->end) - ((size_t) u->start) + 1;
    const auto toCopy = std::min(max, s);
    memcpy(d, u->start, toCopy);
    u->start += toCopy;
    return toCopy;
}

static int64_t getFileSize(const std::string &filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

static char *loadFile(const std::string &file, size_t *size)
{
    if (!std::filesystem::exists(file))
        return nullptr;

    auto fileSize = getFileSize(file);
    if (fileSize == -1)
        return nullptr;

    char *fileContents = (char *) malloc(fileSize);

    FILE *openedFile = fopen(file.c_str(), "r");

    *size = fread(fileContents, 1, fileSize, openedFile);

    if (*size != (size_t) fileSize) {
        LFATAL("Could not read everything from {}", file);
        free(fileContents);
        return nullptr;
    }
    return fileContents;
}

void Persistence::loadLevelData(LevelData &dest)
{
    std::unique_lock<std::mutex> lock(_accessMutex);

    const std::filesystem::path file = std::filesystem::path(_folder) / "level.dat";

    size_t fileSize = 0;
    char *fileData = loadFile(file, &fileSize);
    if (!fileData)
        throw std::runtime_error("Could not open file " + _folder);

    // clang-format off
    _userData ud = {
        fileData,
        fileData + fileSize - 1
    };
    nbt_reader_t reader = {
        _readMem,
        &ud
    };
    // clang-format on
    auto *root = nbt_parse(reader, NBT_PARSE_FLAG_USE_ZLIB);
    assert(root);
    assert(root->type == NBT_TYPE_COMPOUND);

    // Map data
    auto *data = nbt_tag_compound_get(root, "Data");
    assert(data);
    assert(data->type == NBT_TYPE_COMPOUND);

    // TODO(huntears): Find a better way to map the values
    GET_VALUE_DOUBLE(borderCenterX, "BorderCenterX", data);
    GET_VALUE_DOUBLE(borderCenterZ, "BorderCenterZ", data);
    GET_VALUE_DOUBLE(borderDamagePerBlock, "BorderDamagePerBlock", data);
    GET_VALUE_DOUBLE(borderSafeZone, "BorderSafeZone", data);
    GET_VALUE_DOUBLE(borderSize, "BorderSize", data);
    GET_VALUE_DOUBLE(borderSizeLerpTarget, "BorderSizeLerpTarget", data);
    GET_VALUE_LONG(borderSizeLerpTime, "BorderSizeLerpTime", data);
    GET_VALUE_DOUBLE(borderWarningBlocks, "BorderWarningBlocks", data);
    GET_VALUE_DOUBLE(borderWarningTime, "BorderWarningTime", data);
    GET_VALUE_INT(dataVersion, "DataVersion", data);
    GET_VALUE_LONG(dayTime, "DayTime", data);
    GET_VALUE_BYTE(difficulty, "Difficulty", data);
    GET_VALUE_BYTE(difficultyLocked, "DifficultyLocked", data);
    GET_VALUE_INT(gameType, "GameType", data);
    GET_VALUE_LONG(lastPlayed, "LastPlayed", data);
    GET_VALUE_STRING(levelName, "LevelName", data);
    GET_VALUE_FLOAT(spawnAngle, "SpawnAngle", data);
    GET_VALUE_INT(spawnX, "SpawnX", data);
    GET_VALUE_INT(spawnY, "SpawnY", data);
    GET_VALUE_INT(spawnZ, "SpawnZ", data);
    GET_VALUE_LONG(time, "Time", data);

    {
        // const auto __tmpCompound = getConstElement<nbt::Compound, nbt::TagType::Compound>(data, "Version");
        auto *__tmpCompound = nbt_tag_compound_get(data, "Version");
        assert(__tmpCompound);
        assert(__tmpCompound->type == NBT_TYPE_COMPOUND);

        GET_VALUE_TO_INT(id, "Id", __tmpCompound, dest.mcVersion);
        GET_VALUE_TO_STRING(name, "Name", __tmpCompound, dest.mcVersion);
        GET_VALUE_TO_STRING(series, "Series", __tmpCompound, dest.mcVersion);
        GET_VALUE_TO_BYTE(snapshot, "Snapshot", __tmpCompound, dest.mcVersion);
    }

    GET_VALUE_INT(wanderingTraderSpawnChance, "WanderingTraderSpawnChance", data);
    GET_VALUE_INT(wanderingTraderSpawnDelay, "WanderingTraderSpawnDelay", data);
    GET_VALUE_BYTE(wasModded, "WasModded", data);

    {
        auto *__tmpCompound = nbt_tag_compound_get(data, "WorldGenSettings");
        assert(__tmpCompound);
        assert(__tmpCompound->type == NBT_TYPE_COMPOUND);

        GET_VALUE_TO_BYTE(bonus_chest, "bonus_chest", __tmpCompound, dest.worldGenSettings);
        GET_VALUE_TO_BYTE(generateFeatures, "generate_features", __tmpCompound, dest.worldGenSettings);
        GET_VALUE_TO_LONG(seed, "seed", __tmpCompound, dest.worldGenSettings);
    }

    GET_VALUE_BYTE(allowCommands, "allowCommands", data);
    GET_VALUE_INT(clearWeatherTime, "clearWeatherTime", data);
    GET_VALUE_BYTE(hardcore, "hardcore", data);
    GET_VALUE_BYTE(initialized, "initialized", data);
    GET_VALUE_INT(rainTime, "rainTime", data);
    GET_VALUE_BYTE(raining, "raining", data);
    GET_VALUE_INT(thunderTime, "thunderTime", data);
    GET_VALUE_BYTE(thundering, "thundering", data);
    GET_VALUE_INT(version, "version", data);
}

LevelData Persistence::loadLevelData()
{
    LevelData data;

    this->loadLevelData(data);
    return data;
}

void Persistence::loadPlayerData(u128 uuid, PlayerData &dest)
{
    std::unique_lock<std::mutex> lock(_accessMutex);

    // TODO
    const std::filesystem::path file = std::filesystem::path(_folder) / "playerdata" / (uuid.toString() + ".dat");

    size_t fileSize = 0;
    char *fileData = loadFile(file, &fileSize);
    if (!fileData)
        throw std::runtime_error("Could not open file " + _folder);

    // clang-format off
    _userData ud = {
        fileData,
        fileData + fileSize - 1
    };
    nbt_reader_t reader = {
        _readMem,
        &ud
    };
    // clang-format on
    auto *root = nbt_parse(reader, NBT_PARSE_FLAG_USE_ZLIB);
    assert(root);
    assert(root->type == NBT_TYPE_COMPOUND);

    // TODO(huntears): Map the values to the destination object
    GET_VALUE_FLOAT(absorptionAmount, "AbsorptionAmount", root);
    GET_VALUE_SHORT(air, "Air", root);
    GET_VALUE_INT(dataVersion, "DataVersion", root);
    GET_VALUE_SHORT(deathTime, "DeathTime", root);
    GET_VALUE_STRING(dimension, "Dimension", root);
    GET_VALUE_FLOAT(fallDistance, "FallDistance", root);
    GET_VALUE_BYTE(fallFlying, "FallFlying", root);
    GET_VALUE_SHORT(fire, "Fire", root);
    GET_VALUE_FLOAT(health, "Health", root);
    GET_VALUE_INT(hurtByTimestamp, "HurtByTimestamp", root);
    GET_VALUE_SHORT(hurtTime, "HurtTime", root);
    GET_VALUE_BYTE(invulnerable, "Invulnerable", root);
    {
        auto *__tmpList = nbt_tag_compound_get(root, "Motion");
        assert(__tmpList);
        assert(__tmpList->type == NBT_TYPE_LIST);
        assert(__tmpList->tag_list.size == 3);
        assert(__tmpList->tag_list.type == NBT_TYPE_DOUBLE);
        dest.motion.x = __tmpList->tag_list.value[0]->tag_double.value;
        dest.motion.y = __tmpList->tag_list.value[1]->tag_double.value;
        dest.motion.z = __tmpList->tag_list.value[2]->tag_double.value;
    }
    GET_VALUE_BYTE(onGround, "OnGround", root);
    GET_VALUE_INT(portalCooldown, "PortalCooldown", root);
    {
        auto *__tmpList = nbt_tag_compound_get(root, "Pos");
        assert(__tmpList);
        assert(__tmpList->type == NBT_TYPE_LIST);
        assert(__tmpList->tag_list.size == 3);
        assert(__tmpList->tag_list.type == NBT_TYPE_DOUBLE);
        dest.pos.x = __tmpList->tag_list.value[0]->tag_double.value;
        dest.pos.y = __tmpList->tag_list.value[1]->tag_double.value;
        dest.pos.z = __tmpList->tag_list.value[2]->tag_double.value;
    }
    {
        auto *__tmpList = nbt_tag_compound_get(root, "Rotation");
        assert(__tmpList);
        assert(__tmpList->type == NBT_TYPE_LIST);
        assert(__tmpList->tag_list.size == 2);
        assert(__tmpList->tag_list.type == NBT_TYPE_FLOAT);
        dest.rotation.yaw = __tmpList->tag_list.value[0]->tag_float.value;
        dest.rotation.pitch = __tmpList->tag_list.value[1]->tag_float.value;
    }
    GET_VALUE_INT(score, "Score", root);
    GET_VALUE_INT(selectedItemSlot, "SelectedItemSlot", root);
    GET_VALUE_SHORT(sleepTimer, "SleepTimer", root);
    {
        auto *__tmpArray = nbt_tag_compound_get(root, "Rotation");
        assert(__tmpArray);
        assert(__tmpArray->type == NBT_TYPE_INT_ARRAY);
        assert(__tmpArray->tag_int_array.size == 4);
        dest.uuid.most = *(uint64_t *) &__tmpArray->tag_int_array.value[0];
        dest.uuid.least = *(uint64_t *) &__tmpArray->tag_int_array.value[2];
        dest.uuid.swapEndianness();
    }
    GET_VALUE_INT(xpLevel, "XpLevel", root);
    GET_VALUE_FLOAT(xpP, "XpP", root);
    GET_VALUE_INT(xpSeed, "XpSeed", root);
    GET_VALUE_INT(xpTotal, "XpTotal", root);
    GET_VALUE_FLOAT(foodExhaustionLevel, "foodExhaustionLevel", root);
    GET_VALUE_INT(foodLevel, "foodLevel", root);
    GET_VALUE_FLOAT(foodSaturationLevel, "foodSaturationLevel", root);
    GET_VALUE_INT(foodTickTimer, "foodTickTimer", root);
    GET_VALUE_INT(playerGameType, "playerGameType", root);
    GET_VALUE_BYTE(seenCredits, "seenCredits", root);
}

PlayerData Persistence::loadPlayerData(u128 uuid)
{
    PlayerData data;

    this->loadPlayerData(uuid, data);
    return data;
}

void Persistence::loadPlayerData(const Player &player, PlayerData &dest) { loadPlayerData(player.getUuid(), dest); }

PlayerData Persistence::loadPlayerData(const Player &player) { return loadPlayerData(player.getUuid()); }

void Persistence::loadRegion(Dimension &dim, int x, int z)
{
    std::unique_lock<std::mutex> lock(_accessMutex);

    if (std::find(_regionStore.begin(), _regionStore.end(), Position2D(x, z)) != _regionStore.end())
        return; // TODO(huntears): Change this later when we can unload regions

    LDEBUG("Loading region ", x, " ", z);

    _regionStore.emplace_back(x, z);

    const std::string regionSlice = "r." + std::to_string(x) + "." + std::to_string(z) + ".mca";
    const std::filesystem::path file = std::filesystem::path(_folder) / "region" / regionSlice;

    size_t fileSize = 0;
    char *fileContents = loadFile(file, &fileSize);
    if (!fileContents)
        return;

    const RegionHeader *header = (const RegionHeader *) fileContents;

    for (uint16_t cx = 0; cx < maxXPerRegion; cx++) {
        for (uint16_t cz = 0; cz < maxZPerRegion; cz++) {
            const uint16_t currentOffset = cx + cz * maxXPerRegion;

            if (header->locationTable[currentOffset].isEmpty())
                continue;

            const uint64_t chunkOffset = header->locationTable[currentOffset].getOffset() * regionChunkAlignment;

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

            _regionLoadChunk(dim, cx, cz, x, z, data);
        }
    }
    free(fileContents);
    LDEBUG("Loaded region ", x, " ", z);
}

void Persistence::_regionLoadChunk(Dimension &dim, uint16_t cx, uint16_t cz, int x, int z, nbt_tag_t *data)
{
    auto status = nbt_tag_compound_get(data, "Status");
    assert(status);
    if (status->tag_string.size != sizeof("full") - 1 || strcmp(status->tag_string.value, "full"))
        return; // TODO(huntears): Handle non complete chunk later somehow

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

        _regionLoadSection(chunk, section);
    }

    _regionLoadHeightmaps(chunk, data);

    chunk._ready = true;

    nbt_free_tag(data);
}

void Persistence::_regionLoadSection(ChunkColumn &chunk, nbt_tag_t *section)
{
    auto *sectionYnbt = nbt_tag_compound_get(section, "Y");
    assert(sectionYnbt);
    assert(sectionYnbt->type == NBT_TYPE_BYTE);
    const uint8_t sectionY = sectionYnbt->tag_byte.value + 5;

    _regionLoadBlocks(sectionY, section, chunk);
    _regionLoadLights(sectionY, section, chunk);
}

void Persistence::_regionLoadBlocks(uint8_t sectionY, nbt_tag_t *section, ChunkColumn &chunk)
{
    auto *blockStates = nbt_tag_compound_get(section, "block_states");
    if (!blockStates)
        return;
    assert(blockStates->type == NBT_TYPE_COMPOUND);

    BlockPalette &paletteMapping = chunk.getSection(sectionY).getBlockPalette();
    paletteMapping.clear();
    _regionLoadPalette(paletteMapping, blockStates);

    auto *dataArray = nbt_tag_compound_get(blockStates, "data");
    if (!dataArray)
        return; // TODO(huntears): Handle single value palettes properly

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
}

void Persistence::_regionLoadLights(uint8_t sectionY, nbt_tag_t *section, ChunkColumn &chunk)
{
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

void Persistence::_regionLoadPalette(BlockPalette &paletteMapping, nbt_tag_t *blockStates)
{
    const auto &globalPalette = Server::getInstance()->getGlobalPalette();

    auto *palette = nbt_tag_compound_get(blockStates, "palette");
    assert(palette);
    assert(palette->type == NBT_TYPE_LIST);

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
}

void Persistence::_regionLoadHeightmaps(ChunkColumn &chunk, nbt_tag_t *data)
{
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
}

bool Persistence::isChunkLoaded(Dimension &dim, int x, int z)
{
    const int rx = transformChunkPosToRegionPos(x);
    const int rz = transformChunkPosToRegionPos(z);

    this->loadRegion(dim, rx, rz);
    if (std::find(_regionStore.begin(), _regionStore.end(), Position2D(rx, rz)) == _regionStore.end())
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
