#ifndef D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432
#define D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432

#include <mutex>
#include <string>
#include <vector>

#include "LevelData.hpp"
#include "Player.hpp"
#include "types.hpp"
#include "world_storage/PlayerData.hpp"

namespace world_storage {

/**
 * @brief Helper class to provide level persistence (Loading/Saving)
 *
 */
class Persistence {
private:
    /**
     * @brief Name of the world folder
     *
     */
    const std::string level_name;

    /**
     * @brief Global lock for any persistence actions
     *
     */
    std::mutex accessMutex;

    /**
     * @brief Opens a gz compressed file and uncompresses it
     *
     * @param filepath File to read from
     * @param data Output data vector
     */
    void uncompressFile(const std::string &filepath, std::vector<uint8_t> &data);

public:
    /**
     * @brief Construct a new Persistence object
     *
     * @param level_folder_name The folder name of the wanted level
     */
    Persistence(const std::string &level_folder_name);

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

    void loadRegion(int x, int z);
};

}

#endif /* D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432 */
