#include "Dimension.hpp"
#include "nbt.hpp"

std::shared_ptr<nbt::Base> registry::DimensionElement::toNBT() const
{
    // clang-format off
    return NBT_MAKE(nbt::Compound, "", {
        NBT_MAKE(nbt::String, "name", _name),
        NBT_MAKE(nbt::Int, "id", _id),
        NBT_MAKE(nbt::Compound, "element", {
            NBT_MAKE(nbt::Byte, "ultrawarm", _ultrawarm),
            NBT_MAKE(nbt::Int, "logical_height", _logicalHeight),
            NBT_MAKE(nbt::String, "infiniburn", _infiniburn),
            NBT_MAKE(nbt::Byte, "piglin_safe", _piglinSafe),
            NBT_MAKE(nbt::Float, "ambient_light", _ambientLight),
            NBT_MAKE(nbt::Byte, "has_skylight", _hasSkylight),
            NBT_MAKE(nbt::String, "effects", _effects),
            NBT_MAKE(nbt::Byte, "has_raids", _hasRaids),
            NBT_MAKE(nbt::Int, "monster_spawn_block_light_limit", _monsterSpawnBlockLightLimit),
            NBT_MAKE(nbt::Byte, "respawn_anchor_works", _respawnAnchorWorks),
            NBT_MAKE(nbt::Int, "height", _height),
            NBT_MAKE(nbt::Byte, "has_ceiling", _hasCeiling),
            NBT_MAKE(nbt::Compound, "monster_spawn_light_level", {
                NBT_MAKE(nbt::String, "type", _monsterSpawnLightLevel.type),
                NBT_MAKE(nbt::Compound, "value", {
                    NBT_MAKE(nbt::Int, "max_inclusive", _monsterSpawnLightLevel.value.maxInclusive),
                    NBT_MAKE(nbt::Int, "min_inclusive", _monsterSpawnLightLevel.value.minInclusive)
                })
            }),
            NBT_MAKE(nbt::Byte, "natural", _natural),
            NBT_MAKE(nbt::Int, "min_y", _minY),
            NBT_MAKE(nbt::Float, "coordinate_scale", _coordinateScale),
            NBT_MAKE(nbt::Byte, "bed_works", _bedWorks)
        })
    });
    // clang-format on
}
