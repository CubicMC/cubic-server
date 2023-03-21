#include "Persistence.hpp"
#include "world_storage/LevelData.hpp"

using namespace world_storage;

namespace world_storage {

Persistence::Persistence(const std::string &level_folder_name)
    : level_name(level_folder_name)
{
}

void Persistence::loadLevelData(LevelData *dest)
{
    // TODO(huntears): Implement
}

LevelData Persistence::loadLevelData()
{
    LevelData data;

    this->loadLevelData(&data);
    // I sure do hope this gets inlined T_T
    return data;
}

}
