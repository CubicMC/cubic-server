#include <unordered_map>
#include "LevelData.hpp"
#include "Level.hpp"

#ifndef WORLD_STORAGE_HPP
#define WORLD_STORAGE_HPP

class WorldStorage
{
public:
    WorldStorage();
    ~WorldStorage();

    const LevelData &getLevelData() const;
    void setLevelData(const LevelData &value);

    const std::vector<std::string_view> getLevelNames() const;
    const Level *getLevel(std::string_view levelName) const;
    Level *getLevelM(std::string_view levelName);
    void addLevel(std::string_view levelName, Level *level);
    void addLevel(std::string_view levelName);
    void removeLevel(std::string_view levelName);

private:
    LevelData _levelData;
    std::unordered_map<std::string_view, Level *> _levels;
};

#endif // WORLD_STORAGE_HPP
