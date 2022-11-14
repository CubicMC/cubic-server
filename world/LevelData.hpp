#include <stdint.h>
#include <string>
class LevelData
{
public:
    LevelData();
    ~LevelData();
private:
    uint8_t _hardcore;
    uint8_t _mapFeatures;
    uint8_t _raining;
    uint8_t _thundering;
    uint32_t _gameType;
    uint32_t _generatorVersion;
    uint32_t _rainTime;
    uint32_t _spawnX;
    uint32_t _spawnY;
    uint32_t _spawnZ;
    uint32_t _thunderTime;
    uint32_t _version;
    uint64_t _lastPlayed;
    uint64_t _randomSeed;
    uint64_t _sizeOnDisk;
    uint64_t _time;
    std::string _generatorName;
    std::string _levelName;
};