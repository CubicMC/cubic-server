#ifndef CUBICSERVER_REGISTRY_DIMENSION_HPP
#define CUBICSERVER_REGISTRY_DIMENSION_HPP

#include "Registry.hpp"
#include <cstdint>

namespace registry {

class DimensionElement : public Entry {
public:
    struct MonsterSpawnLightLevel {
        std::string type;
        struct {
            int32_t maxInclusive;
            int32_t minInclusive;
        } value;
    };

public:
    DimensionElement() = default;
    ~DimensionElement() = default;

    std::shared_ptr<nbt::Base> toNBT() const override;
    bool operator==(const std::string &name) const override { return name == _name; }

    // Getters
public:
    inline std::string name() const { return _name; }
    inline int32_t id() const { return _id; }
    inline bool ultrawarm() const { return _ultrawarm; }
    inline int32_t logicalHeight() const { return _logicalHeight; }
    inline std::string infiniburn() const { return _infiniburn; }
    inline bool piglinSafe() const { return _piglinSafe; }
    inline float ambientLight() const { return _ambientLight; }
    inline bool hasSkylight() const { return _hasSkylight; }
    inline std::string effects() const { return _effects; }
    inline bool hasRaids() const { return _hasRaids; }
    inline int32_t monsterSpawnBlockLightLimit() const { return _monsterSpawnBlockLightLimit; }
    inline bool respawnAnchorWorks() const { return _respawnAnchorWorks; }
    inline int32_t height() const { return _height; }
    inline bool hasCeiling() const { return _hasCeiling; }
    inline MonsterSpawnLightLevel monsterSpawnLightLevel() const { return _monsterSpawnLightLevel; }
    inline bool natural() const { return _natural; }
    inline int32_t minY() const { return _minY; }
    inline float coordinateScale() const { return _coordinateScale; }
    inline bool bedWorks() const { return _bedWorks; }

    // Setters
public:
    inline DimensionElement &name(std::string name);
    inline DimensionElement &id(int32_t id);
    inline DimensionElement &ultrawarm(bool ultrawarm);
    inline DimensionElement &logicalHeight(int32_t logicalHeight);
    inline DimensionElement &infiniburn(std::string infiniburn);
    inline DimensionElement &piglinSafe(bool piglinSafe);
    inline DimensionElement &ambientLight(float ambientLight);
    inline DimensionElement &hasSkylight(bool hasSkylight);
    inline DimensionElement &effects(std::string effects);
    inline DimensionElement &hasRaids(bool hasRaids);
    inline DimensionElement &monsterSpawnBlockLightLimit(int32_t monsterSpawnBlockLightLimit);
    inline DimensionElement &respawnAnchorWorks(bool respawnAnchorWorks);
    inline DimensionElement &height(int32_t height);
    inline DimensionElement &hasCeiling(bool hasCeiling);
    inline DimensionElement &monsterSpawnLightLevel(MonsterSpawnLightLevel monsterSpawnLightLevel);
    inline DimensionElement &natural(bool natural);
    inline DimensionElement &minY(int32_t minY);
    inline DimensionElement &coordinateScale(float coordinateScale);
    inline DimensionElement &bedWorks(bool bedWorks);

private:
    std::string _name;
    int32_t _id;
    bool _ultrawarm;
    int32_t _logicalHeight;
    std::string _infiniburn;
    bool _piglinSafe;
    float _ambientLight;
    bool _hasSkylight;
    std::string _effects;
    bool _hasRaids;
    int32_t _monsterSpawnBlockLightLimit;
    bool _respawnAnchorWorks;
    int32_t _height;
    bool _hasCeiling;
    MonsterSpawnLightLevel _monsterSpawnLightLevel;
    bool _natural;
    int32_t _minY;
    float _coordinateScale;
    bool _bedWorks;
};

DEFINE_REGISTRY_CLASS(Dimension, "minecraft:dimension_type");

inline void setupDefaultsDimension(Dimension &registry);

} // namespace registry

inline registry::DimensionElement &registry::DimensionElement::name(std::string name)
{
    _name = name;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::id(int32_t id)
{
    _id = id;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::ultrawarm(bool ultrawarm)
{
    _ultrawarm = ultrawarm;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::logicalHeight(int32_t logicalHeight)
{
    _logicalHeight = logicalHeight;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::infiniburn(std::string infiniburn)
{
    _infiniburn = infiniburn;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::piglinSafe(bool piglinSafe)
{
    _piglinSafe = piglinSafe;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::ambientLight(float ambientLight)
{
    _ambientLight = ambientLight;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::hasSkylight(bool hasSkylight)
{
    _hasSkylight = hasSkylight;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::effects(std::string effects)
{
    _effects = effects;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::hasRaids(bool hasRaids)
{
    _hasRaids = hasRaids;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::monsterSpawnBlockLightLimit(int32_t monsterSpawnBlockLightLimit)
{
    _monsterSpawnBlockLightLimit = monsterSpawnBlockLightLimit;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::respawnAnchorWorks(bool respawnAnchorWorks)
{
    _respawnAnchorWorks = respawnAnchorWorks;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::height(int32_t height)
{
    _height = height;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::hasCeiling(bool hasCeiling)
{
    _hasCeiling = hasCeiling;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::monsterSpawnLightLevel(MonsterSpawnLightLevel monsterSpawnLightLevel)
{
    _monsterSpawnLightLevel = monsterSpawnLightLevel;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::natural(bool natural)
{
    _natural = natural;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::minY(int32_t minY)
{
    _minY = minY;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::coordinateScale(float coordinateScale)
{
    _coordinateScale = coordinateScale;
    return *this;
}

inline registry::DimensionElement &registry::DimensionElement::bedWorks(bool bedWorks)
{
    _bedWorks = bedWorks;
    return *this;
}

inline void registry::setupDefaultsDimension(registry::Dimension &registry)
{
    registry.addEntry()
        .name("minecraft:overworld")
        .id(0)
        .ultrawarm(false)
        .logicalHeight(256)
        .infiniburn("#minecraft:infiniburn_overworld")
        .piglinSafe(false)
        .ambientLight(0.0)
        .hasSkylight(true)
        .effects("minecraft:overworld")
        .hasRaids(true)
        .monsterSpawnBlockLightLimit(0)
        .respawnAnchorWorks(false)
        .height(384)
        .hasCeiling(false)
        .monsterSpawnLightLevel({
            .type = "uniform",
            .value =
                {
                    .maxInclusive = 7,
                    .minInclusive = 0,
                },
        })
        .natural(true)
        .minY(-64)
        .coordinateScale(1.0)
        .bedWorks(true);

    registry.addEntry()
        .name("minecraft:the_nether")
        .id(2)
        .ultrawarm(true)
        .logicalHeight(256)
        .infiniburn("#minecraft:infiniburn_end")
        .piglinSafe(false)
        .ambientLight(0.1)
        .hasSkylight(false)
        .effects("minecraft:the_nether")
        .hasRaids(false)
        .monsterSpawnBlockLightLimit(0)
        .respawnAnchorWorks(true)
        .height(384)
        .hasCeiling(true)
        .monsterSpawnLightLevel({
            .type = "uniform",
            .value =
                {
                    .maxInclusive = 7,
                    .minInclusive = 0,
                },
        })
        .natural(true)
        .minY(-64)
        .coordinateScale(1.0)
        .bedWorks(false);

    // TODO: Add the rest of the dimensions
}

#endif // CUBICSERVER_REGISTRY_DIMENSION_HPP
