#ifndef CUBICSERVER_REGISTRY_DIMENSION_HPP
#define CUBICSERVER_REGISTRY_DIMENSION_HPP

#include "Registry.hpp"
#include <cstdint>

namespace registry {

constexpr const char DIMENSION_REGISTRY_NAME[] = "minecraft:dimension_type";

class DimensionElement : public Entry {
public:
    struct MonsterSpawnLightLevel {
        std::string _type;
        struct {
            int32_t _maxInclusive;
            int32_t _minInclusive;
        } _value;
    };

public:
    DimensionElement(
        std::string name, int32_t id, bool ultrawarm, int32_t logicalHeight, std::string infiniburn, bool piglinSafe, float ambientLight, bool hasSkylight, std::string effects,
        bool hasRaids, int32_t monsterSpawnBlockLightLimit, bool respawnAnchorWorks, int32_t height, bool hasCeiling, MonsterSpawnLightLevel monsterSpawnLightLevel, bool natural,
        int32_t minY, float coordinateScale, bool bedWorks
    );

    std::shared_ptr<nbt::Base> toNBT() const override;
    bool operator==(const std::string &) const override;

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

// NBT_MAKE(nbt::Compound, "minecraft:dimension_type", {
//     NBT_MAKE(nbt::String, "type", "minecraft:dimension_type"),
//     NBT_MAKE(nbt::List, "value", {
//         NBT_MAKE(nbt::Compound, "", {
//             NBT_MAKE(nbt::String, "name", "minecraft:overworld"),
//             NBT_MAKE(nbt::Int, "id", 0),
//             NBT_MAKE(nbt::Compound, "element", {
//                 NBT_MAKE(nbt::Byte, "ultrawarm", 0),
//                 NBT_MAKE(nbt::Int, "logical_height", 256),
//                 NBT_MAKE(nbt::String, "infiniburn", "#minecraft:infiniburn_overworld"),
//                 NBT_MAKE(nbt::Byte, "piglin_safe", 0),
//                 NBT_MAKE(nbt::Float, "ambient_light", 0.0),
//                 NBT_MAKE(nbt::Byte, "has_skylight", 1),
//                 NBT_MAKE(nbt::String, "effects", "minecraft:overworld"),
//                 NBT_MAKE(nbt::Byte, "has_raids", 1),
//                 NBT_MAKE(nbt::Int, "monster_spawn_block_light_limit", 0),
//                 NBT_MAKE(nbt::Byte, "respawn_anchor_works", 0),
//                 NBT_MAKE(nbt::Int, "height", 384),
//                 NBT_MAKE(nbt::Byte, "has_ceiling", 0),
//                 NBT_MAKE(nbt::Compound, "monster_spawn_light_level", {
//                     NBT_MAKE(nbt::String, "type", "minecraft:uniform"),
//                     NBT_MAKE(nbt::Compound, "value", {
//                         NBT_MAKE(nbt::Int, "max_inclusive", 7),
//                         NBT_MAKE(nbt::Int, "min_inclusive", 0)
//                     })
//                 }),
//                 NBT_MAKE(nbt::Byte, "natural", 1),
//                 NBT_MAKE(nbt::Int, "min_y", -64),
//                 NBT_MAKE(nbt::Float, "coordinate_scale", 1.0),
//                 NBT_MAKE(nbt::Byte, "bed_works", 1)
//             })
//         })
//     })
// })

} // namespace registry

#endif
