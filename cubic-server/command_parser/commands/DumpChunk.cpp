#include "DumpChunk.hpp"
#include "Server.hpp"
#include "World.hpp"

#include "world_storage/globalPalette_TEMP.hpp"

#include <iostream>


void command_parser::DumpChunk::autocomplete(std::vector<std::string>& args, Player *invoker) const
{
    return;
}

void command_parser::DumpChunk::execute(std::vector<std::string>& args, Player *invoker) const
{
    if (args.size() != 2 && !invoker) {
        LDEBUG("Usage: /dumpChunk <x> <z>");
        return;
    }

    if (args.size() == 0 && invoker) {
        args.push_back(std::to_string(transformBlockPosToChunkPos(invoker->getPosition().x)));
        args.push_back(std::to_string(transformBlockPosToChunkPos(invoker->getPosition().z)));
    }
    LDEBUG("Testing chunk...");

    auto dim = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld");

    if (!dim->hasChunkLoaded(std::stoi(args[0]), std::stoi(args[1]))) {
        LDEBUG("Chunk is not loaded");
        return;
    }
    LDEBUG("Chunk is loaded");

    auto chunk = dim->getChunk(std::stoi(args[0]), std::stoi(args[1]));
    auto blocks = chunk.getBlocks();

    for (const auto &block : blocks) {
        auto name = world_storage::getBlockFromGlobalPaletteId(block);
        if (world_storage::getGlobalPaletteIdFromBlockName(name) != block || (block == 0 && name != "minecraft:air"))
            LDEBUG("ERROR: " << name << " has id " << block << " but should have id " << world_storage::getGlobalPaletteIdFromBlockName(name));
    }
    LDEBUG("--- CHUNK DATA ---");
    {
        auto sectionStart = blocks.begin();
        for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_SECTIONS; sectionID++) {
            auto section = sectionStart + (sectionID * world_storage::SECTION_3D_SIZE);
            LDEBUG("Section " << (int)sectionID);

            world_storage::BlockPalette blockPalette;
            uint16_t blockInsideSection = 0;

            for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
                auto &block = section[i];
                blockPalette.add(block);
                if (block != 0)
                    blockInsideSection++;
            }

            LDEBUG('\t' << "Block count: " << blockInsideSection);
        }
    }

    LDEBUG("--- CHUNK PACKET DATA ---");

    std::vector<uint8_t> data;
    protocol::addChunkColumn(data, chunk);

    auto at = data.data();
    auto eof = data.data() + data.size() - 1;

    LDEBUG("Chunk data size: " << protocol::popVarInt(at, eof));

    for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_SECTIONS; sectionID++) {
        LDEBUG("Section " << std::dec << (int)sectionID);
        auto blockCount = protocol::popShort(at, eof);
        LDEBUG('\t' << "Block count: " << blockCount);

        // Block palette parsing
        auto bytePerBlock = protocol::popByte(at, eof);
        LDEBUG('\t' << "Palette bit per block: " << (int)bytePerBlock);
        if (bytePerBlock == 0)
            LDEBUG('\t' << "Single value palette: " << protocol::popVarInt(at, eof));
        else if (bytePerBlock <= 8) {
            LDEBUG('\t' << "Indirect value palette");
            auto paletteSize = protocol::popVarInt(at, eof);
            LDEBUG('\t' << "Palette size: " << paletteSize);
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                LDEBUG('\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << world_storage::getBlockFromGlobalPaletteId(value));
            }
        } else
            LDEBUG('\t' << "Direct value palette");

        // Block data parsing
        auto blockDataSize = protocol::popVarInt(at, eof);
        LDEBUG('\t' << "Block data size: " << blockDataSize);
        if ((blockDataSize > 0 && bytePerBlock == 0) || (blockDataSize == 0 && bytePerBlock > 0))
            LDEBUG('\t' << "ERROR: Block data size and palette bit per block are not compatible");
        if (bytePerBlock > 0 && blockDataSize * (64 / bytePerBlock) < blockCount)
            LDEBUG('\t' << "ERROR: Block data size is too small");
        for (int32_t i = 0; i < blockDataSize; i++) {
            uint64_t value = protocol::popLong(at, eof);
            LDEBUG('\t' << '\t' << "Block data entry " << i << ": " << std::hex << value);
        }

        // Biome palette parsing
        auto bytePerBiome = protocol::popByte(at, eof);
        LDEBUG('\t' << "Palette bit per biome: " << (int)bytePerBiome);
        if (bytePerBiome == 0)
            LDEBUG('\t' << "Single value palette: " << protocol::popVarInt(at, eof));
        else if (bytePerBiome <= 8) {
            LDEBUG('\t' << "Indirect value palette");
            auto paletteSize = protocol::popVarInt(at, eof);
            LDEBUG('\t' << "Palette size: " << paletteSize);
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                LDEBUG('\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << world_storage::getBlockFromGlobalPaletteId(value));
            }
        } else
            LDEBUG('\t' << "Direct value palette");

        // Biome data parsing
        auto biomeDataSize = protocol::popVarInt(at, eof);
        LDEBUG('\t' << "Biome data size: " << biomeDataSize);
        for (int32_t i = 0; i < biomeDataSize; i++) {
            auto value = protocol::popLong(at, eof);
            LDEBUG('\t' << '\t' << "Biome data entry " << std::dec << i << ": " << std::hex << value);
        }
    }

    if (at != eof + 1)
        LDEBUG("ERROR: Not all data was read: " << (eof - at));
    else
        LDEBUG("All data was read");

    LDEBUG("--- CHUNK PACKET DATA END ---");

    LDEBUG("Done");
}

void command_parser::DumpChunk::help(std::vector<std::string>& args, Player *invoker) const
{
    if (invoker) {
        //invoker->sendMessage("Usage: /dumpchunk <x> <z>");
    } else {
        LINFO("Usage: /dumpchunk <x> <z>");
    }
}
