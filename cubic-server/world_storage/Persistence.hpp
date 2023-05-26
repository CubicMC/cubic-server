#ifndef D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432
#define D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "LevelData.hpp"
#include "Player.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/PlayerData.hpp"

namespace world_storage {

/**
 * @brief Helper class to provide level persistence (Loading/Saving)
 *
 */
class Persistence {
private:
    std::string _folder;

    /**
     * @brief Global lock for any persistence actions
     *
     */
    std::mutex accessMutex;

public:
    std::vector<Position2D> regionStore; // TODO(huntears): Get proper getter/setter

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
    void loadLevelData(LevelData *dest);

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
    void loadPlayerData(u128 uuid, PlayerData *dest);

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
    void loadPlayerData(const Player *player, PlayerData *dest);

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
    PlayerData loadPlayerData(const Player *player);

    void loadRegion(Dimension &dim, int x, int z);

    bool isChunkLoaded(Dimension &dim, int x, int z);
};

}

#endif /* D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432 */
