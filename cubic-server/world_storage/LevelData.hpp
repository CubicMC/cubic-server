#ifndef LEVELDATA_HPP
#define LEVELDATA_HPP

#include <stdint.h>
#include <string>

namespace world_storage {

class LevelData {
public:
    LevelData();
    ~LevelData();

    uint8_t getHardcore() const;
    void setHardcore(uint8_t value);

    uint8_t getMapFeatures() const;
    void setMapFeatures(uint8_t value);

    uint8_t getRaining() const;
    void setRaining(uint8_t value);

    uint8_t getThundering() const;
    void setThundering(uint8_t value);

    uint32_t getGameType() const;
    void setGameType(uint32_t value);

    uint32_t getGeneratorVersion() const;
    void setGeneratorVersion(uint32_t value);

    uint32_t getRainTime() const;
    void setRainTime(uint32_t value);

    uint32_t getSpawnX() const;
    void setSpawnX(uint32_t value);
    uint32_t getSpawnY() const;
    void setSpawnY(uint32_t value);
    uint32_t getSpawnZ() const;
    void setSpawnZ(uint32_t value);

    uint32_t getThunderTime() const;
    void setThunderTime(uint32_t value);

    uint32_t getVersion() const;
    void setVersion(uint32_t value);

    uint64_t getLastPlayed() const;
    void setLastPlayed(uint64_t value);

    uint64_t getSeed() const;
    void setSeed(uint64_t value);

    uint64_t getSizeOnDisk() const;
    void setSizeOnDisk(uint64_t value);

    uint64_t getTime() const;
    void setTime(uint64_t value);

    const std::string &getGeneratorName() const;
    void setGeneratorName(const std::string &value);

    const std::string &getLevelName() const;
    void setLevelName(const std::string &value);

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

}

#endif // LEVELDATA_HPP
