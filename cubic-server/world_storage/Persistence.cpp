#include "Persistence.hpp"
#include "nbt.hpp"
#include "world_storage/LevelData.hpp"
#include <cstdint>
#include <mutex>
#include <stdexcept>
#include <vector>
#include <zlib.h>
#include <filesystem>
#include "logging/Logger.hpp"

// TODO(huntears): Add better error messages
#define GET_VALUE(type, dst, src) do { \
        auto __tmp = data->getValue(src); \
        if (!__tmp || __tmp->getType() != nbt::TagType::type) \
            throw std::runtime_error(""); \
        dest-> dst = ((nbt::type *)__tmp)->get_value(); \
    } while (0)

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
    GET_VALUE(Double, borderCenterX, "BorderCenterX");
    GET_VALUE(Double, borderCenterZ, "BorderCenterZ");
    GET_VALUE(Double, borderDamagePerBlock, "BorderDamagePerBlock");
    GET_VALUE(Double, borderSafeZone, "BorderSafeZone");
    GET_VALUE(Double, borderSize, "BorderSize");
    GET_VALUE(Double, borderSizeLerpTarget, "BorderSizeLerpTarget");
    GET_VALUE(Long, borderSizeLerpTime, "BorderSizeLerpTime");
    GET_VALUE(Double, borderWarningBlocks, "BorderWarningBlocks");
    GET_VALUE(Double, borderWarningTime, "BorderWarningTime");
    // TODO(huntears): The rest of the fields

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

}
