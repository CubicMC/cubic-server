#ifndef WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP
#define WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP

// TODO: generate this file LOL

#include "Block.hpp"

namespace world_storage
{

constexpr uint32_t getGlobalPaletteIdFromBlockName(const std::string &name)
{
    if (name == "minecraft:air") return 0;
    else if (name == "minecraft:bedrock") return 74;
    else if (name == "minecraft:grass_block") return 9;
    else if (name == "minecraft:grass") return 1596;
    else if (name == "minecraft:dirt") return 10;

    // Default
    return 0;
}

uint32_t getGlobalPaletteIdFromBlock(const Block &block);

constexpr std::string getBlockFromGlobalPaletteId(uint32_t id)
{
    if (id == 0) return "minecraft:air";
    else if (id == 74) return "minecraft:bedrock";
    else if (id == 9) return "minecraft:grass_block";
    else if (id == 1596) return "minecraft:grass";
    else if (id == 10) return "minecraft:dirt";

    // Default
    return "minecraft:air";
}

} // namespace world_storage

#endif // WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP
