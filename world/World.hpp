#include <unordered_map>

#include "LevelData.hpp"
#include "Level.hpp"

class World
{
public:
    World();
    ~World();
private:
    LevelData _levelData;
    std::unordered_map<int, Level> _levels;
};