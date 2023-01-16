#ifndef WORLD_STORAGE_GLOBAL_PALETTE_HPP
#define WORLD_STORAGE_GLOBAL_PALETTE_HPP

// TODO: generate this file LOL

#include "logging/Logger.hpp"
#include "world_storage/ChunkColumn.hpp"

namespace world_storage {

constexpr uint32_t getGlobalPaletteIdFromBlock(const std::string &name)
{
    if (name == "minecraft:air") return 0;
    else if (name == "minecraft:grass_block") return 2;
    else if (name == "minecraft:dirt") return 3;
    else if (name == "minecraft:bedrock") return 7;

    logging::Logger::get_instance()->error("Unknown block name: " + name);
}

uint32_t getGlobalPaletteIdFromBlock(const Block &block)
{
    return getGlobalPaletteIdFromBlock(block.toString());
}

constexpr std::string getBlockFromGlobalPaletteId(uint32_t id)
{
    if (id == 0) return "minecraft:air";
    else if (id == 2) return "minecraft:grass_block";
    else if (id == 3) return "minecraft:dirt";
    else if (id == 7) return "minecraft:bedrock";

    logging::Logger::get_instance()->error("Unknown block id: " + std::to_string(id));
}

} // namespace world_storage

#endif // WORLD_STORAGE_GLOBAL_PALETTE_HPP
