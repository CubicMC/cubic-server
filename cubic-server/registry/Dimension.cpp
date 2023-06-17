#include "Dimension.hpp"
#include "nbt.hpp"

registry::DimensionElement::DimensionElement(
        std::string name, int32_t id, bool ultrawarm, int32_t logicalHeight, std::string infiniburn, bool piglinSafe, float ambientLight, bool hasSkylight, std::string effects,
        bool hasRaids, int32_t monsterSpawnBlockLightLimit, bool respawnAnchorWorks, int32_t height, bool hasCeiling, MonsterSpawnLightLevel monsterSpawnLightLevel, bool natural,
        int32_t minY, float coordinateScale, bool bedWorks
    ):
    registry::Entry(),
    _name(name),
    _id(id),
    _ultrawarm(ultrawarm),
    _logicalHeight(logicalHeight),
    _infiniburn(infiniburn),
    _piglinSafe(piglinSafe),
    _ambientLight(ambientLight),
    _hasSkylight(hasSkylight),
    _effects(effects),
    _hasRaids(hasRaids),
    _monsterSpawnBlockLightLimit(monsterSpawnBlockLightLimit),
    _respawnAnchorWorks(respawnAnchorWorks),
    _height(height),
    _hasCeiling(hasCeiling),
    _monsterSpawnLightLevel(monsterSpawnLightLevel),
    _natural(natural),
    _minY(minY),
    _coordinateScale(coordinateScale),
    _bedWorks(bedWorks)
{}

std::shared_ptr<nbt::Base> registry::DimensionElement::toNBT() const
{
    return NBT_MAKE(nbt::Compound, "", {});
}
