#include "World.hpp"

const LevelData &World::getLevelData() const
{
    return _levelData;
}

void World::setLevelData(const LevelData &value)
{
    _levelData = value;
}

const std::vector<std::string> World::getLevelNames() const
{
    std::vector<std::string> levelNames;
    for (auto const &[key, val] : _levels) {
        levelNames.push_back(key);
    }
    return levelNames;
}

const Level &World::getLevel(std::string &levelName) const
{
    return _levels.at(levelName);
}

void World::addLevel(std::string &levelName, Level &level)
{
    _levels.insert({levelName, level});
}

void World::addLevel(std::string &levelName)
{
    Level level;
    _levels.insert({levelName, level});
}

void World::removeLevel(std::string &levelName)
{
    _levels.erase(levelName);
}