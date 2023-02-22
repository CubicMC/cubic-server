#include "DumpChunk.hpp"
#include "Server.hpp"
#include "World.hpp"

#include "world_storage/globalPalette_TEMP.hpp"

#include <iostream>


void command_parser::DumpChunk::autocomplete(std::vector<std::string>& args) const
{
    return;
}

void command_parser::DumpChunk::execute(std::vector<std::string>& args) const
{
    if (args.size() != 2) {
        std::cout << "Usage: /dumpChunk <x> <z>" << std::endl;
        return;
    }
    std::cout << "Testing chunk..." << std::endl;

    auto dim = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld");

    if (!dim->hasChunkLoaded(std::stoi(args[0]), std::stoi(args[1]))) {
        std::cout << "Chunk is not loaded" << std::endl;
        return;
    }
    std::cout << "Chunk is loaded" << std::endl;

    auto chunk = dim->getChunk(std::stoi(args[0]), std::stoi(args[1]));
    auto blocks = chunk.getBlocks();

    for (const auto &block : blocks) {
        auto name = world_storage::getBlockFromGlobalPaletteId(block);
        if (world_storage::getGlobalPaletteIdFromBlockName(name) != block || (block == 0 && name != "minecraft:air"))
            std::cout << "ERROR: " << name << " has id " << block << " but should have id " << world_storage::getGlobalPaletteIdFromBlockName(name) << std::endl;
    }
    std::cout << "--- CHUNK DATA ---" << std::endl;
    {
        auto sectionStart = blocks.begin();
        for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_SECTIONS; sectionID++) {
            auto section = sectionStart + (sectionID * world_storage::SECTION_3D_SIZE);
            std::cout << "Section " << (int)sectionID << std::endl;

            world_storage::BlockPalette blockPalette;
            uint16_t blockInsideSection = 0;

            for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
                auto &block = section[i];
                blockPalette.add(block);
                if (block != 0)
                    blockInsideSection++;
            }

            std::cout << '\t' << "Block count: " << blockInsideSection << std::endl;
        }
    }

    std::cout << "--- CHUNK PACKET DATA ---" << std::endl;

    std::vector<uint8_t> data;
    protocol::addChunkColumn(data, chunk);

    auto at = data.data();
    auto eof = data.data() + data.size() - 1;

    std::cout << "Chunk data size: " << protocol::popVarInt(at, eof) << std::endl;

    for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_SECTIONS; sectionID++) {
        std::cout << "Section " << std::dec << (int)sectionID << std::endl;
        auto blockCount = protocol::popShort(at, eof);
        std::cout << '\t' << "Block count: " << blockCount << std::endl;

        // Block palette parsing
        auto bytePerBlock = protocol::popByte(at, eof);
        std::cout << '\t' << "Palette bit per block: " << (int)bytePerBlock << std::endl;
        if (bytePerBlock == 0)
            std::cout << '\t' << "Single value palette: " << protocol::popVarInt(at, eof) << std::endl;
        else if (bytePerBlock <= 8) {
            std::cout << '\t' << "Indirect value palette" << std::endl;
            auto paletteSize = protocol::popVarInt(at, eof);
            std::cout << '\t' << "Palette size: " << paletteSize << std::endl;
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                std::cout << '\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << world_storage::getBlockFromGlobalPaletteId(value) << std::endl;
            }
        } else
            std::cout << '\t' << "Direct value palette" << std::endl;

        // Block data parsing
        auto blockDataSize = protocol::popVarInt(at, eof);
        std::cout << '\t' << "Block data size: " << blockDataSize << std::endl;
        if ((blockDataSize > 0 && bytePerBlock == 0) || (blockDataSize == 0 && bytePerBlock > 0))
            std::cout << '\t' << "ERROR: Block data size and palette bit per block are not compatible" << std::endl;
        if (bytePerBlock > 0 && blockDataSize * (64 / bytePerBlock) < blockCount)
            std::cout << '\t' << "ERROR: Block data size is too small" << std::endl;
        for (int32_t i = 0; i < blockDataSize; i++) {
            uint64_t value = protocol::popLong(at, eof);
            std::cout << '\t' << '\t' << "Block data entry " << i << ": " << std::hex << value << std::endl;
        }

        // Biome palette parsing
        auto bytePerBiome = protocol::popByte(at, eof);
        std::cout << '\t' << "Palette bit per biome: " << (int)bytePerBiome << std::endl;
        if (bytePerBiome == 0)
            std::cout << '\t' << "Single value palette: " << protocol::popVarInt(at, eof) << std::endl;
        else if (bytePerBiome <= 8) {
            std::cout << '\t' << "Indirect value palette" << std::endl;
            auto paletteSize = protocol::popVarInt(at, eof);
            std::cout << '\t' << "Palette size: " << paletteSize << std::endl;
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                std::cout << '\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << world_storage::getBlockFromGlobalPaletteId(value) << std::endl;
            }
        } else
            std::cout << '\t' << "Direct value palette" << std::endl;

        // Biome data parsing
        auto biomeDataSize = protocol::popVarInt(at, eof);
        std::cout << '\t' << "Biome data size: " << biomeDataSize << std::endl;
        for (int32_t i = 0; i < biomeDataSize; i++) {
            auto value = protocol::popLong(at, eof);
            std::cout << '\t' << '\t' << "Biome data entry " << std::dec << i;
            std::cout << ": " << std::hex << value << std::endl;
        }
    }

    if (at != eof + 1)
        std::cout << "ERROR: Not all data was read: " << (eof - at) << std::endl;
    else
        std::cout << "All data was read" << std::endl;

    std::cout << "--- CHUNK PACKET DATA END ---" << std::endl;

    std::cout << "Done" << std::endl;
}

void command_parser::DumpChunk::help(std::vector<std::string>& args) const
{

}
