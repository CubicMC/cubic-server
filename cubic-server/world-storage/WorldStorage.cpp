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

const std::vector<std::string> WorldStorage::getLevelNames() const
{
    std::vector<std::string> levelNames;
    for (auto const &[key, val] : _levels) {
        levelNames.push_back(key);
    }
    return levelNames;
}

const Level &WorldStorage::getLevel(std::string levelName) const
{
    return _levels.at(levelName);
}

Level &WorldStorage::getLevelM(std::string levelName)
{
    return _levels.at(levelName);
}

void WorldStorage::addLevel(std::string levelName, Level &level)
{
    _levels.insert({levelName, level});
}

void WorldStorage::addLevel(std::string levelName)
{
    _levels.insert({levelName, new Level()});
}

void WorldStorage::removeLevel(std::string levelName)
{
    delete _levels.at(levelName);
    _levels.erase(levelName);
}