#include "DumpChunk.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/Logger.hpp"
#include "protocol/serialization/add.hpp"
#include "protocol/serialization/popPrimaryType.hpp"
#include "protocol_id_converter/blockStates.hpp"
#include "world_storage/Palette.hpp"
#include "world_storage/Section.hpp"
#include <cstdint>

void command_parser::DumpChunk::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { return; }

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
    LDEBUG("Testing chunk...");

    auto dim = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld");

    if (!dim->hasChunkLoaded(std::stoi(args[0]), std::stoi(args[1]))) {
        LDEBUG("Chunk is not loaded");
        return;
    }
    LDEBUG("Chunk is loaded");

    auto chunk = dim->getChunk(std::stoi(args[0]), std::stoi(args[1]));
    auto sections = chunk.getSections();

    // for (const auto &section : sections) {
    //     for (int idx = 0; idx < world_storage::SECTION_3D_SIZE; idx++) {
    //         auto block = section.getBlock(idx);
    //         auto name = GLOBAL_PALETTE.fromProtocolIdToBlock(block).name;
    //         if (GLOBAL_PALETTE.fromBlockToProtocolId({name, {}}) != block || (block == 0 && name != "minecraft:air"))
    //             LDEBUG("ERROR: " << name << " has id " << block << " but should have id " << GLOBAL_PALETTE.fromBlockToProtocolId({name, {}}));
    //     }
    // }
    LDEBUG("Dumping palette...");
    for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_PLAYABLE_SECTIONS; sectionID++) {
        const auto &section = sections[sectionID];
        LDEBUG("Section " << (int) sectionID);

        LDEBUG("Bits: " << (int) section.getBlockPalette().getBits());
        LDEBUG("Size: " << section.getBlockPalette().size());
        LDEBUG("Total Count: " << section.getBlockPalette().getTotalCount());
        if (section.getBlockPalette().getTotalCount(true) != world_storage::SECTION_3D_SIZE)
            LDEBUG("ERROR: Block palette does not have the right size: " << section.getBlockPalette().getTotalCount(true) << " != " << world_storage::SECTION_3D_SIZE);
        if (section.getBlockPalette().getTotalCount() + section.getBlockPalette().getCount(0) != world_storage::SECTION_3D_SIZE)
            LDEBUG("ERROR: Block palette does not have the right size: " << section.getBlockPalette().getTotalCount() << " + " << section.getBlockPalette().getCount(0) << " != " << world_storage::SECTION_3D_SIZE);
        for (uint16_t i = 0; i < section.getBlockPalette().size(); i++) {
            auto block = section.getBlockPalette().getGlobalId(i);
            LDEBUG("\tPalette[" << i << "]: (" << block << ") -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(block).name << " " << section.getBlockPalette().getCount(block));
        }
    }

    LDEBUG("--- CHUNK DATA ---");

    LDEBUG("Checking palette...");
    for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_PLAYABLE_SECTIONS; sectionID++) {
        const auto &section = sections[sectionID];
        LDEBUG("Section " << (int) sectionID);

        // world_storage::BlockPalette blockPalette;
        // world_storage::BiomePalette biomePalette;
        // blockPalette.setCount(0, world_storage::SECTION_3D_SIZE);
        // biomePalette.setCount(0, world_storage::BIOME_SECTION_3D_SIZE);

        // uint16_t blockInsideSection = 0;
        // if (blockPalette.getTotalCount(true) != world_storage::SECTION_3D_SIZE || blockPalette.getTotalCount() != 0)
        //     LERROR("New block palette has not the right size: " << blockPalette.getTotalCount(true) << " && " << blockPalette.getTotalCount());

        // for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
        //     auto block = section.getBlock(i);
        //     blockPalette.add(section.getBlockPalette().getGlobalId(block));
        //     if (block != 0)
        //         blockInsideSection++;
        // }
        // for (uint16_t i = 0; i < world_storage::BIOME_SECTION_3D_SIZE; i++) {
        //     auto biome = section.getBiome(i);
        //     biomePalette.add(section.getBiomePalette().getGlobalId(biome));
        // }

        // // Palette testing
        // if (section.getBlockPalette().getTotalCount() != blockInsideSection)
        //     LWARN("Block count is not consistant " << blockInsideSection << " != " << section.getBlockPalette().getTotalCount());

        // if (blockPalette.getBits() != section.getBlockPalette().getBits())
        //     LWARN("Block palette bits is not consistant " << (int) blockPalette.getBits() << " != " << (int) section.getBlockPalette().getBits());

        // if (blockPalette.size() != section.getBlockPalette().size()) {
        //     LWARN("Block palette size is not consistant " << blockPalette.size() << " != " << section.getBlockPalette().size());
        //     for (uint16_t i = 0; i < blockPalette.size(); i++) {
        //         auto block = blockPalette.getGlobalId(i);
        //         LWARN("\ttemporary palette[" << i << "]: (" << block << ") -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(block).name);
        //     }
        //     for (uint16_t i = 0; i < section.getBlockPalette().size(); i++) {
        //         auto block = section.getBlockPalette().getGlobalId(i);
        //         LWARN("\tstored palette[" << i << "]: (" << block << ") -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(block).name);
        //     }
        // }

        // if (biomePalette.getBits() != section.getBiomePalette().getBits())
        //     LWARN("Biome palette bits is not consistant " << (int) biomePalette.getBits() << " != " << (int) section.getBiomePalette().getBits());

        // if (biomePalette.size() != section.getBiomePalette().size())
        //     LWARN("Biome palette size is not consistant " << biomePalette.size() << " != " << section.getBiomePalette().size());

        for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            auto block = section.getBlock(i);
            if (std::find(section.getBlockPalette().begin(), section.getBlockPalette().end(), block) == section.getBlockPalette().end())
                LWARN("Block " << block << " is not in the palette");
        }

        // for (uint16_t i = 0; i < blockPalette.size(); i++) {
        //     auto block = blockPalette.getGlobalId(i);
        //     auto block2 = section.getBlockPalette().getGlobalId(i);
        //     if (block != block2)
        //         LWARN("Block palette is not consistant " << GLOBAL_PALETTE.fromProtocolIdToBlock(block).name << " != " << GLOBAL_PALETTE.fromProtocolIdToBlock(block2).name);
        // }

        // for (uint16_t i = 0; i < biomePalette.size(); i++) {
        //     auto biome = biomePalette.getGlobalId(i);
        //     auto biome2 = section.getBiomePalette().getGlobalId(i);
        //     if (biome != biome2)
        //         LWARN("Biome palette is not consistant " << biome << " != " << biome2);
        // }
    }

    // LDEBUG("--- CHUNK PACKET DATA ---");

    // std::vector<uint8_t> data;
    // protocol::addChunkColumn(data, chunk);

    // auto at = data.data();
    // auto eof = data.data() + data.size() - 1;

    // LDEBUG("Chunk data size: " << protocol::popVarInt(at, eof));

    // for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_PLAYABLE_SECTIONS; sectionID++) {
    //     LDEBUG("Section " << std::dec << (int) sectionID);
    //     auto blockCount = protocol::popShort(at, eof);
    //     LDEBUG('\t' << "Block count: " << blockCount);

    //     // Block palette parsing
    //     world_storage::BlockPalette blockPalette;
    //     auto bytePerBlock = protocol::popByte(at, eof);
    //     LDEBUG('\t' << "Palette bit per block: " << (int) bytePerBlock);
    //     if (bytePerBlock == 0)
    //         LDEBUG('\t' << "Single value palette: " << protocol::popVarInt(at, eof));
    //     else if (bytePerBlock <= 8) {
    //         LDEBUG('\t' << "Indirect value palette");
    //         auto paletteSize = protocol::popVarInt(at, eof);
    //         LDEBUG('\t' << "Palette size: " << paletteSize);
    //         for (int32_t i = 0; i < paletteSize; i++) {
    //             auto value = protocol::popVarInt(at, eof);
    //             blockPalette.add(value);
    //             LDEBUG('\t' << '\t' << "Palette entry[" << i << "]: " << value << " -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(value).name);
    //         }
    //     } else
    //         LDEBUG('\t' << "Direct value palette");

    //     // Block data parsing
    //     auto blockDataSize = protocol::popVarInt(at, eof);
    //     LDEBUG('\t' << "Block data size: " << blockDataSize);
    //     if ((blockDataSize > 0 && bytePerBlock == 0) || (blockDataSize == 0 && bytePerBlock > 0))
    //         LDEBUG('\t' << "ERROR: Block data size and palette bit per block are not compatible");
    //     if (bytePerBlock > 0 && blockDataSize * (64 / bytePerBlock) < blockCount)
    //         LDEBUG('\t' << "ERROR: Block data size is too small");
    //     for (int32_t i = 0; i < blockDataSize; i++) {
    //         uint64_t value = protocol::popLong(at, eof);
    //         for (uint64_t blockIdx = 0; blockIdx < world_storage::SECTION_3D_SIZE; blockIdx++) {
    //             auto block = (value >> ((blockIdx % (64 / bytePerBlock)) * bytePerBlock)) & ((1 << bytePerBlock) - 1);
    //             auto blockGlobalId = blockPalette.getGlobalId(block);
    //             if (blockGlobalId == -1) {
    //                 LDEBUG("WARNING: Block " << block << " is not in the palette");
    //                 blockGlobalId = sections[sectionID].getBlockPalette().getGlobalId(block);
    //             }
    //             LDEBUG('\t' << '\t' << "Block data entry " << i << " block " << blockIdx << ": " << block << " -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(blockGlobalId).name);
    //         }
    //         LDEBUG('\t' << '\t' << "Block data entry " << i << ": " << std::hex << value);
    //     }

    //     // Biome palette parsing
    //     auto bytePerBiome = protocol::popByte(at, eof);
    //     LDEBUG('\t' << "Palette bit per biome: " << (int) bytePerBiome);
    //     if (bytePerBiome == 0)
    //         LDEBUG('\t' << "Single value palette: " << protocol::popVarInt(at, eof));
    //     else if (bytePerBiome <= 8) {
    //         LDEBUG('\t' << "Indirect value palette");
    //         auto paletteSize = protocol::popVarInt(at, eof);
    //         LDEBUG('\t' << "Palette size: " << paletteSize);
    //         for (int32_t i = 0; i < paletteSize; i++) {
    //             auto value = protocol::popVarInt(at, eof);
    //             LDEBUG('\t' << '\t' << "Palette entry " << i << ": " << value << " -> " << GLOBAL_PALETTE.fromProtocolIdToBlock(value).name);
    //         }
    //     } else
    //         LDEBUG('\t' << "Direct value palette");

    //     // Biome data parsing
    //     auto biomeDataSize = protocol::popVarInt(at, eof);
    //     LDEBUG('\t' << "Biome data size: " << biomeDataSize);
    //     for (int32_t i = 0; i < biomeDataSize; i++) {
    //         auto value = protocol::popLong(at, eof);
    //         LDEBUG('\t' << '\t' << "Biome data entry " << std::dec << i << ": " << std::hex << value);
    //     }
    // }

    // if (at != eof + 1)
    //     LDEBUG("ERROR: Not all data was read: " << (eof - at));
    // else
    //     LDEBUG("All data was read");

    // LDEBUG("--- CHUNK PACKET DATA END ---");

    // LINFO("Done");
}

void command_parser::DumpChunk::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // invoker->sendMessage("Usage: /dumpchunk <x> <z>");
    } else {
        LINFO("Usage: /dumpchunk <x> <z>");
    }
}
