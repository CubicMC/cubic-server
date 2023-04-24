#include "DumpChunk.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "world_storage/Palette.hpp"
#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "protocol/serialization/add.hpp"
#include "protocol/serialization/popPrimaryType.hpp"

#include <iostream>

void command_parser::DumpChunk::autocomplete(std::vector<std::string> &args, Player *invoker) const { return; }

void command_parser::DumpChunk::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2 && !invoker) {
        LDEBUG("Usage: /dumpChunk <x> <z>");
        return;
    }

    if (args.size() == 0 && invoker) {
        args.push_back(std::to_string(transformBlockPosToChunkPos(invoker->getPosition().x)));
        args.push_back(std::to_string(transformBlockPosToChunkPos(invoker->getPosition().z)));
    }
    LDEBUG("Testing chunk ", args[0], " ", args[1]);

    auto dim = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld");

    if (!dim->hasChunkLoaded(std::stoi(args[0]), std::stoi(args[1]))) {
        LDEBUG("Chunk is not loaded");
        return;
    }
    LDEBUG("Chunk is loaded");

    LDEBUG("Dumping known global palette id");
    LDEBUG("minecraft:air -> ", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:air"));
    LDEBUG("minecraft:grass_block -> ", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:grass_block"));
    LDEBUG("minecraft:dirt -> ", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:dirt"));
    LDEBUG("minecraft:stone -> ", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:stone"));
    LDEBUG("minecraft:bedrock -> ", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:bedrock"));
    LDEBUG("minecraft:water -> ", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:water"));

    auto chunk = dim->getChunk(std::stoi(args[0]), std::stoi(args[1]));
    auto blocks = chunk->getBlocks();

    for (const auto &block : blocks) {
        auto name = GLOBAL_PALETTE.fromProtocolIdToBlock(block).name;
        if (GLOBAL_PALETTE.fromBlockToProtocolId(name) != block || (block == 0 && name != "minecraft:air"))
            LDEBUG("ERROR: " << name << " has id " << block << " but should have id " << GLOBAL_PALETTE.fromBlockToProtocolId(name));
    }
    LDEBUG("--- CHUNK DATA ---");
    {
        auto sectionStart = blocks.begin();
        for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_SECTIONS; sectionID++) {
            auto section = sectionStart + (sectionID * world_storage::SECTION_3D_SIZE);
            LDEBUG("Section " << (int) sectionID);

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
    protocol::addChunkColumn(data, *chunk);

    auto at = data.data();
    auto eof = data.data() + data.size() - 1;

    LDEBUG("Chunk data size: " << protocol::popVarInt(at, eof));

    for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_SECTIONS; sectionID++) {
        LDEBUG("Section " << std::dec << (int) sectionID);
        auto blockCount = protocol::popShort(at, eof);
        LDEBUG('\t' << "Block count: " << blockCount);

        // Block palette parsing
        auto bytePerBlock = protocol::popByte(at, eof);
        LDEBUG('\t' << "Palette bit per block: " << (int) bytePerBlock);
        world_storage::BlockPalette localPalette;
        if (bytePerBlock == 0)
            LDEBUG('\t' << "Single value palette: " << protocol::popVarInt(at, eof));
        else if (bytePerBlock <= 8) {
            LDEBUG('\t' << "Indirect value palette");
            auto paletteSize = protocol::popVarInt(at, eof);
            LDEBUG('\t' << "Palette size: " << paletteSize);
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                LDEBUG('\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(value).name);
                localPalette.add(value);
                if (localPalette.getId(value) != i)
                    LDEBUG('\t' << '\t' << "ERROR: Palette entry is not consistent");
            }
        } else
            LDEBUG('\t' << "Direct value palette");

        // Block data parsing
        auto entryPerLong = bytePerBlock == 0 ? 0 : 64 / bytePerBlock;
        auto blockDataSize = protocol::popVarInt(at, eof);
        LDEBUG('\t' << "Block data size: " << blockDataSize);
        if ((blockDataSize > 0 && bytePerBlock == 0) || (blockDataSize == 0 && bytePerBlock > 0))
            LDEBUG('\t' << "ERROR: Block data size and palette bit per block are not compatible");
        if (bytePerBlock > 0 && blockDataSize * (64 / bytePerBlock) < blockCount)
            LDEBUG('\t' << "ERROR: Block data size is too small");
        for (int32_t i = 0; i < blockDataSize; i++) {
            uint64_t value = protocol::popLong(at, eof);
            std::stringstream valueStr;
            std::string blockStr;
            for (auto j = 0; j < entryPerLong; j++) {
                auto block = (value >> (j * bytePerBlock)) & ((1 << bytePerBlock) - 1);
                valueStr << block << " ";
                blockStr += GLOBAL_PALETTE.fromProtocolIdToBlock(localPalette.getGlobalId(block)).name + " ";
            }
            if (entryPerLong == 0)
                valueStr << std::hex << value;
            LDEBUG('\t' << '\t' << "Block data entry " << i << ": " << valueStr.str() << " -> " << blockStr);
        }

        // Biome palette parsing
        auto bytePerBiome = protocol::popByte(at, eof);
        LDEBUG('\t' << "Palette bit per biome: " << (int) bytePerBiome);
        if (bytePerBiome == 0)
            LDEBUG('\t' << "Single value palette: " << protocol::popVarInt(at, eof));
        else if (bytePerBiome <= 8) {
            LDEBUG('\t' << "Indirect value palette");
            auto paletteSize = protocol::popVarInt(at, eof);
            LDEBUG('\t' << "Palette size: " << paletteSize);
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                LDEBUG('\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(value).name);
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

void command_parser::DumpChunk::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // invoker->sendMessage("Usage: /dumpchunk <x> <z>");
    } else {
        LINFO("Usage: /dumpchunk <x> <z>");
    }
}
