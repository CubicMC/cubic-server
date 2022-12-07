#include "WorldStorage.hpp"

WorldStorage::WorldStorage()
{
}

WorldStorage::~WorldStorage()
{
}

const LevelData &WorldStorage::getLevelData() const
{
    return _levelData;
}

void WorldStorage::setLevelData(const LevelData &value)
{
    _levelData = value;
}

const std::vector<std::string_view> WorldStorage::getLevelNames() const
{
    std::vector<std::string_view> levelNames;
    for (auto const &[key, val] : _levels) {
        levelNames.push_back(key);
    }
    return levelNames;
}

const Level *WorldStorage::getLevel(std::string_view levelName) const
{
    return _levels.at(levelName);
}

Level *WorldStorage::getLevelM(std::string_view levelName)
{
    return _levels.at(levelName);
}

void WorldStorage::addLevel(std::string_view levelName, Level *level)
{
    _levels.insert({levelName, level});
}

void WorldStorage::addLevel(std::string_view levelName)
{
    Level *level;
    _levels.insert({levelName, level});
}

void WorldStorage::removeLevel(std::string_view levelName)
{
    free(_levels.at(levelName));
    _levels.erase(levelName);
}
