#include <unordered_map>

#include "LevelData.hpp"
#include "Level.hpp"

class World
{
public:
    World();
    ~World();

    const LevelData &getLevelData() const;
    void setLevelData(const LevelData &value);

    const std::vector<std::string> getLevelNames() const;
    const Level &getLevel(std::string &levelName) const;
    void addLevel(std::string &levelName, Level &level);
    void addLevel(std::string &levelName);
    void removeLevel(std::string &levelName);

private:
    LevelData _levelData;
    std::unordered_map<std::string, Level &> _levels;
};