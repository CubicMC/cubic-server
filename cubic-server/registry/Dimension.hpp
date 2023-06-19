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
    bool operator==(const std::string &) const override;

// Getters
public:
    constexpr std::string name() const { return _name; }
    constexpr int32_t id() const { return _id; }
    constexpr bool ultrawarm() const { return _ultrawarm; }
    constexpr int32_t logicalHeight() const { return _logicalHeight; }
    constexpr std::string infiniburn() const { return _infiniburn; }
    constexpr bool piglinSafe() const { return _piglinSafe; }
    constexpr float ambientLight() const { return _ambientLight; }
    constexpr bool hasSkylight() const { return _hasSkylight; }
    constexpr std::string effects() const { return _effects; }
    constexpr bool hasRaids() const { return _hasRaids; }
    constexpr int32_t monsterSpawnBlockLightLimit() const { return _monsterSpawnBlockLightLimit; }
    constexpr bool respawnAnchorWorks() const { return _respawnAnchorWorks; }
    constexpr int32_t height() const { return _height; }
    constexpr bool hasCeiling() const { return _hasCeiling; }
    constexpr MonsterSpawnLightLevel monsterSpawnLightLevel() const { return _monsterSpawnLightLevel; }
    constexpr bool natural() const { return _natural; }
    constexpr int32_t minY() const { return _minY; }
    constexpr float coordinateScale() const { return _coordinateScale; }
    constexpr bool bedWorks() const { return _bedWorks; }

// Setters
public:
    constexpr DimensionElement &name(std::string name);
    constexpr DimensionElement &id(int32_t id);
    constexpr DimensionElement &ultrawarm(bool ultrawarm);
    constexpr DimensionElement &logicalHeight(int32_t logicalHeight);
    constexpr DimensionElement &infiniburn(std::string infiniburn);
    constexpr DimensionElement &piglinSafe(bool piglinSafe);
    constexpr DimensionElement &ambientLight(float ambientLight);
    constexpr DimensionElement &hasSkylight(bool hasSkylight);
    constexpr DimensionElement &effects(std::string effects);
    constexpr DimensionElement &hasRaids(bool hasRaids);
    constexpr DimensionElement &monsterSpawnBlockLightLimit(int32_t monsterSpawnBlockLightLimit);
    constexpr DimensionElement &respawnAnchorWorks(bool respawnAnchorWorks);
    constexpr DimensionElement &height(int32_t height);
    constexpr DimensionElement &hasCeiling(bool hasCeiling);
    constexpr DimensionElement &monsterSpawnLightLevel(MonsterSpawnLightLevel monsterSpawnLightLevel);
    constexpr DimensionElement &natural(bool natural);
    constexpr DimensionElement &minY(int32_t minY);
    constexpr DimensionElement &coordinateScale(float coordinateScale);
    constexpr DimensionElement &bedWorks(bool bedWorks);

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

constexpr void setupDefaultsDimension(Dimension &registry);

} // namespace registry

constexpr registry::DimensionElement &registry::DimensionElement::name(std::string name)
{
    _name = name;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::id(int32_t id)
{
    _id = id;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::ultrawarm(bool ultrawarm)
{
    _ultrawarm = ultrawarm;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::logicalHeight(int32_t logicalHeight)
{
    _logicalHeight = logicalHeight;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::infiniburn(std::string infiniburn)
{
    _infiniburn = infiniburn;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::piglinSafe(bool piglinSafe)
{
    _piglinSafe = piglinSafe;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::ambientLight(float ambientLight)
{
    _ambientLight = ambientLight;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::hasSkylight(bool hasSkylight)
{
    _hasSkylight = hasSkylight;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::effects(std::string effects)
{
    _effects = effects;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::hasRaids(bool hasRaids)
{
    _hasRaids = hasRaids;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::monsterSpawnBlockLightLimit(int32_t monsterSpawnBlockLightLimit)
{
    _monsterSpawnBlockLightLimit = monsterSpawnBlockLightLimit;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::respawnAnchorWorks(bool respawnAnchorWorks)
{
    _respawnAnchorWorks = respawnAnchorWorks;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::height(int32_t height)
{
    _height = height;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::hasCeiling(bool hasCeiling)
{
    _hasCeiling = hasCeiling;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::monsterSpawnLightLevel(MonsterSpawnLightLevel monsterSpawnLightLevel)
{
    _monsterSpawnLightLevel = monsterSpawnLightLevel;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::natural(bool natural)
{
    _natural = natural;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::minY(int32_t minY)
{
    _minY = minY;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::coordinateScale(float coordinateScale)
{
    _coordinateScale = coordinateScale;
    return *this;
}

constexpr registry::DimensionElement &registry::DimensionElement::bedWorks(bool bedWorks)
{
    _bedWorks = bedWorks;
    return *this;
}

constexpr void registry::setupDefaultsDimension(registry::Dimension &registry)
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
            .value = {
                .maxInclusive = 7,
                .minInclusive = 0,
            },
        })
        .natural(true)
        .minY(-64)
        .coordinateScale(1.0)
        .bedWorks(true);

    // TODO: Add the rest of the dimensions
}

#endif // CUBICSERVER_REGISTRY_DIMENSION_HPP
