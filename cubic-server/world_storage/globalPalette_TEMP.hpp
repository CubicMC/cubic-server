#ifndef WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP
#define WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP

// TODO: generate this file LOL

#include "Block.hpp"
#include "types.hpp"

namespace world_storage
{

constexpr GlobalBlockId getGlobalPaletteIdFromBlockName(const std::string &name)
{
    if (name == "minecraft:air") return 0;
    else if (name == "minecraft:bedrock") return 76;
    else if (name == "minecraft:grass_block") return 9;
    else if (name == "minecraft:grass") return 1954;
    else if (name == "minecraft:stone") return 1;
    else if (name == "minecraft:water") return 92;
    else if (name == "minecraft:sand") return 109;
    else if (name == "minecraft:dirt") return 10;
    else if (name == "minecraft:oak_log") return 120;
    else if (name == "minecraft:oak_leaves") return 241;
    else if (name == "minecraft:glass") return 468;
    else if (name == "minecraft:cobblestone") return 14;
    else if (name == "minecraft:pink_terracotta") return 8966;
    else if (name == "minecraft:purple_carpet") return 10261;

    // Default
    return 0;
}

GlobalBlockId getGlobalPaletteIdFromBlock(const Block &block);

constexpr std::string getBlockFromGlobalPaletteId(GlobalBlockId id)
{
    if (id == 0) return "minecraft:air";
    else if (id == 76) return "minecraft:bedrock";
    else if (id == 9) return "minecraft:grass_block";
    else if (id == 1954) return "minecraft:grass";
    else if (id == 10) return "minecraft:dirt";
    else if (id == 120) return "minecraft:oak_log";
    else if (id == 241) return "minecraft:oak_leaves";
    else if (id == 468) return "minecraft:glass";
    else if (id == 14) return "minecraft:cobblestone";
    else if (id == 8966) return "minecraft:pink_terracotta";
    else if (id == 10261) return "minecraft:purple_carpet";

    // Default
    return "minecraft:air";
}

} // namespace world_storage

#endif // WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP
