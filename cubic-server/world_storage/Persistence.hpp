#ifndef D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432
#define D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432

#include <mutex>
#include <string>
#include <vector>

#include "LevelData.hpp"

namespace world_storage {

/**
 * @brief Helper class to provide level persistence (Loading/Saving)
 * 
 */
class Persistence
{
private:
    const std::string level_name;
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

};

}

#endif /* D3EBB5BA_3F3F_4BBD_A2B5_05FD6729E432 */
