#include "LevelData.hpp"

namespace world_storage
{
LevelData::LevelData()
{
}

LevelData::~LevelData()
{
}

uint8_t LevelData::getHardcore() const
{
    return _hardcore;
}

void LevelData::setHardcore(uint8_t value)
{
    _hardcore = value;
}

uint8_t LevelData::getMapFeatures() const
{
    return _mapFeatures;
}

void LevelData::setMapFeatures(uint8_t value)
{
    _mapFeatures = value;
}

uint8_t LevelData::getRaining() const
{
    return _raining;
}

void LevelData::setRaining(uint8_t value)
{
    _raining = value;
}

uint8_t LevelData::getThundering() const
{
    return _thundering;
}

void LevelData::setThundering(uint8_t value)
{
    _thundering = value;
}

uint32_t LevelData::getGameType() const
{
    return _gameType;
}

void LevelData::setGameType(uint32_t value)
{
    _gameType = value;
}

uint32_t LevelData::getGeneratorVersion() const
{
    return _generatorVersion;
}

void LevelData::setGeneratorVersion(uint32_t value)
{
    _generatorVersion = value;
}

uint32_t LevelData::getRainTime() const
{
    return _rainTime;
}

void LevelData::setRainTime(uint32_t value)
{
    _rainTime = value;
}

uint32_t LevelData::getSpawnX() const
{
    return _spawnX;
}

void LevelData::setSpawnX(uint32_t value)
{
    _spawnX = value;
}

uint32_t LevelData::getSpawnY() const
{
    return _spawnY;
}

void LevelData::setSpawnY(uint32_t value)
{
    _spawnY = value;
}

uint32_t LevelData::getSpawnZ() const
{
    return _spawnZ;
}

void LevelData::setSpawnZ(uint32_t value)
{
    _spawnZ = value;
}

uint32_t LevelData::getThunderTime() const
{
    return _thunderTime;
}

void LevelData::setThunderTime(uint32_t value)
{
    _thunderTime = value;
}

uint32_t LevelData::getVersion() const
{
    return _version;
}

void LevelData::setVersion(uint32_t value)
{
    _version = value;
}

uint64_t LevelData::getLastPlayed() const
{
    return _lastPlayed;
}

void LevelData::setLastPlayed(uint64_t value)
{
    _lastPlayed = value;
}

uint64_t LevelData::getSeed() const
{
    return _randomSeed;
}

void LevelData::setSeed(uint64_t value)
{
    _randomSeed = value;
}

uint64_t LevelData::getSizeOnDisk() const
{
    return _sizeOnDisk;
}

void LevelData::setSizeOnDisk(uint64_t value)
{
    _sizeOnDisk = value;
}

uint64_t LevelData::getTime() const
{
    return _time;
}

void LevelData::setTime(uint64_t value)
{
    _time = value;
}

const std::string& LevelData::getGeneratorName() const
{
    return _generatorName;
}

void LevelData::setGeneratorName(const std::string &value)
{
    _generatorName = value;
}

const std::string& LevelData::getLevelName() const
{
    return _levelName;
}

void LevelData::setLevelName(const std::string &value)
{
    _levelName = value;
}
}
