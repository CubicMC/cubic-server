#ifndef D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432
#define D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432

#include <arpa/inet.h>
#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include <nbt.h>

#include "LevelData.hpp"
#include "Player.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Palette.hpp"
#include "world_storage/PlayerData.hpp"

namespace world_storage {

struct RegionLocation {
    uint32_t data;

    inline uint32_t getOffset() const { return ((data & 0x00FF0000) >> 16) | (data & 0x0000FF00) | ((data & 0x000000FF) << 16); }

    inline uint8_t getSize() const { return data >> 24; }

    inline bool isEmpty() const { return data == 0; }
};

struct RegionTimestamp {
    uint32_t data;
};

constexpr uint32_t maxXPerRegion = 32;
constexpr uint32_t maxZPerRegion = 32;
constexpr uint32_t numChunksPerRegion = maxXPerRegion * maxZPerRegion;
constexpr uint64_t regionChunkAlignment = 0x1000;

struct __attribute__((__packed__)) RegionHeader {
    RegionLocation locationTable[numChunksPerRegion];
    RegionLocation timestampTable[numChunksPerRegion];
};

struct __attribute__((__packed__)) ChunkHeader {
    uint32_t length;
    uint8_t compressionScheme;

    inline uint32_t getLength() const { return ntohl(length); }

    inline uint8_t getCompressionScheme() const { return compressionScheme; }
};

/**
 * @brief Helper class to provide level persistence (Loading/Saving)
 *
 */
class Persistence {
private:
    /**
     * @brief Points to the folder containing the world
     *
     */
    std::string _folder;

    /**
     * @brief Global lock for any persistence actions
     *
     */
    std::mutex _accessMutex;

    /**
     * @brief Storage of the currently loaded regions in memory
     *
     */
    std::vector<Position2D> _regionStore;

public:
    /**
     * @brief Construct a new Persistence object
     *
     * @param folder Points to the folder containing the world
     */
    Persistence(const std::string &folder);

    /**
     * @brief Loads the level.dat from disk
     *
     * This is the preferred way of loading level.dat, as it
     * doesn't copy the final object, though the whole object
     * will not be reset, it will only fill in the data that
     * is in the level.dat file.
     *
     * @param dest The LevelData object to fill
     */
    void loadLevelData(LevelData &dest);

    /**
     * @brief Loads the level.dat from disk
     *
     * loadLevelData(LevelData *dest) is preferred over this
     * method, as it copies over the whole data instead of
     * just filling an existing object
     *
     * @return LevelData The whole level.dat file content
     */
    LevelData loadLevelData();

    /**
     * @brief Loads player data from disk
     *
     * @param uuid Player to load data from
     * @param dest The PlayerData object to fill
     */
    void loadPlayerData(u128 uuid, PlayerData &dest);

    /**
     * @brief Loads player data from disk
     *
     * loadPlayerData(u128 uuid, PlayerData *dest) is preferred over this
     * method, as it copies over the whole data instead of
     * just filling an existing object;
     *
     * @param uuid Player to load data from
     * @return PlayerData The loaded player data
     */
    PlayerData loadPlayerData(u128 uuid);

    /**
     * @brief Loads player data from disk
     *
     * @param player Player to load data from
     * @param dest The PlayerData object to fill
     */
    void loadPlayerData(const Player &player, PlayerData &dest);

    /**
     * @brief Loads player data from disk
     *
     * loadPlayerData(const Player *player, PlayerData *dest) is preferred over this
     * method, as it copies over the whole data instead of
     * just filling an existing object;
     *
     * @param player Player to load data from
     * @return PlayerData The loaded player data
     */
    PlayerData loadPlayerData(const Player &player);

    /**
     * @brief Loads a region from disk
     *
     * @param dim The dimension to load the region in
     * @param x The X coordinate of the region
     * @param z The Z coordinate of the region
     */
    void loadRegion(Dimension &dim, int x, int z);

    /**
     * @brief Checks if a chunk is loaded in the dimension
     *
     * This function will trigger a region load if the region hasn't
     * been loaded before
     *
     * @param dim The dimension to check
     * @param x The X coordinate of the region
     * @param z The Z coordinate of the region
     * @return true The chunk is loaded in memory
     * @return false The chunk is not loaded in memory
     */
    bool isChunkLoaded(Dimension &dim, int x, int z);

private:
    void _regionLoadHeightmaps(ChunkColumn &chunk, nbt_tag_t *data);
    void _regionLoadPalette(BlockPalette &paletteMapping, nbt_tag_t *blockStates);
    void _regionLoadSection(ChunkColumn &chunk, nbt_tag_t *section);
    void _regionLoadChunk(Dimension &dim, uint16_t cx, uint16_t cz, int x, int z, nbt_tag_t *data);
    void _regionLoadLights(uint8_t sectionY, nbt_tag_t *section, ChunkColumn &chunk);
    void _regionLoadBlocks(uint8_t sectionY, nbt_tag_t *section, ChunkColumn &chunk);
};

}

#endif /* D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432 */
