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

void Persistence::loadLevelData(LevelData *dest)
{
    std::unique_lock<std::mutex> lock(accessMutex);

    // Thanks StackOverflow
    // https://stackoverflow.com/a/17062022
    const std::filesystem::path file = std::filesystem::path(level_name) / "level.dat";
    // TODO(huntears): Put that somewhere else to make it reusable
    gzFile inFileZ = gzopen(file.c_str(), "rb");
    if (inFileZ == NULL)
        throw std::runtime_error("Error: Failed to gzopen " + std::string(file));

    constexpr uint64_t readBufferSize = 8192;
    uint8_t unzipBuffer[readBufferSize];
    unsigned int unzippedBytes;
    std::vector<uint8_t> unzippedData;
    while (true) {
        unzippedBytes = gzread(inFileZ, unzipBuffer, readBufferSize);
        if (unzippedBytes > 0) {
            unzippedData.insert(unzippedData.end(), unzipBuffer, unzipBuffer + unzippedBytes);
        } else {
            break;
        }
    }
    gzclose(inFileZ);

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
