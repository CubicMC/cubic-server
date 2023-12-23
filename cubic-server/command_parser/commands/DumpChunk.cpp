#include "DumpChunk.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"
#include "protocol/serialization/add.hpp"
#include "protocol/serialization/popPrimaryType.hpp"
#include "protocol_id_converter/blockIdConverter.hpp"
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
    LDEBUG("Testing chunk ", args[0], " ", args[1]);

    auto dim = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld");

    if (!dim->hasChunkLoaded(std::stoi(args[0]), std::stoi(args[1]))) {
        LDEBUG("Chunk is not loaded");
        return;
    }
    LDEBUG("Chunk is loaded");

    LDEBUG("Dumping known global palette id");
    LDEBUG("minecraft:air -> {}", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:air"));
    LDEBUG("minecraft:grass_block -> {}", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:grass_block"));
    LDEBUG("minecraft:dirt -> {}", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:dirt"));
    LDEBUG("minecraft:stone -> {}", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:stone"));
    LDEBUG("minecraft:bedrock -> {}", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:bedrock"));
    LDEBUG("minecraft:water -> {}", GLOBAL_PALETTE.fromBlockToProtocolId("minecraft:water"));

    const auto &chunk = dim->getChunk(std::stoi(args[0]), std::stoi(args[1]));
    const auto &sections = chunk.getSections();

    // for (const auto &section : sections) {
    //     for (int idx = 0; idx < world_storage::SECTION_3D_SIZE; idx++) {
    //         auto block = section.getBlock(idx);
    //         auto name = GLOBAL_PALETTE.fromProtocolIdToBlock(block).name;
    //         if (GLOBAL_PALETTE.fromBlockToProtocolId({name, {}}) != block || (block == 0 && name != "minecraft:air"))
    //             LDEBUG("ERROR: " << name << " has id " << block << " but should have id " << GLOBAL_PALETTE.fromBlockToProtocolId({name, {}}));
    //     }
    // }
    LDEBUG("Dumping palette...");
    for (uint8_t sectionID = 1; sectionID < world_storage::NB_OF_SECTIONS - 1; sectionID++) {
        const auto &section = sections.at(sectionID);
        LINFO("Section {}", sectionID);

        LDEBUG("Bits: {}", section.getBlockPalette().getBits());
        LDEBUG("Size: {}", section.getBlockPalette().size());
        uint16_t blockInsideSection = 0;
        for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            auto block = section.getBlock(i);
            if (block != 0)
                blockInsideSection++;
        }
        LDEBUG("Total Count: {}", blockInsideSection);
        for (uint16_t i = 0; i < section.getBlockPalette().size(); i++) {
            auto block = section.getBlockPalette().getGlobalId(i);
            LDEBUG("\tPalette[{}]: ({}) -> {} ", i, block, GLOBAL_PALETTE.fromProtocolIdToBlock(block).name);
        }
    }

    LDEBUG("--- CHUNK DATA ---");

    LDEBUG("Checking palette...");
    for (uint8_t sectionID = 1; sectionID < world_storage::NB_OF_SECTIONS - 1; sectionID++) {
        const auto &section = sections.at(sectionID);
        LDEBUG("Section {}", sectionID);

        for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            auto block = section.getBlock(i);
            if (std::find(section.getBlockPalette().begin(), section.getBlockPalette().end(), block) == section.getBlockPalette().end())
                LWARN("Block {} is not in the palette", block);
        }
    }

    LDEBUG("--- CHUNK PACKET DATA ---");

    std::vector<uint8_t> data;
    protocol::addChunkColumn(data, chunk);

    auto at = data.data();
    auto eof = data.data() + data.size() - 1;

    auto heightmap = nbt::parse(at, eof);

    LDEBUG("Chunk data size: {}", protocol::popVarInt(at, eof));

    for (uint8_t sectionID = 0; sectionID < world_storage::NB_OF_PLAYABLE_SECTIONS; sectionID++) {
        LDEBUG("Section {}", sectionID);
        auto blockCount = protocol::popShort(at, eof);
        LDEBUG("\tBlock count: {}", blockCount);

        // Block palette parsing
        world_storage::BlockPalette blockPalette;
        auto bytePerBlock = protocol::popByte(at, eof);
        LDEBUG("\t\tPalette bit per block: {}", bytePerBlock);
        if (bytePerBlock == 0)
            LDEBUG("\tSingle value palette: {}", protocol::popVarInt(at, eof));
        else if (bytePerBlock <= 8) {
            LDEBUG("\tIndirect value palette");
            auto paletteSize = protocol::popVarInt(at, eof);
            LDEBUG("\tPalette size: {}", paletteSize);
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                blockPalette.add(value);
                LDEBUG("\t\tPalette entry[{}]: {} -> {}", i, value, GLOBAL_PALETTE.fromProtocolIdToBlock(value).name);
            }
        } else
            LDEBUG("\tDirect value palette");

        // Block data parsing
        // auto entryPerLong = bytePerBlock == 0 ? 0 : 64 / bytePerBlock;
        auto blockDataSize = protocol::popVarInt(at, eof);
        LDEBUG("\tBlock data size: {}", blockDataSize);
        if ((blockDataSize > 0 && bytePerBlock == 0) || (blockDataSize == 0 && bytePerBlock > 0))
            LDEBUG("\tERROR: Block data size and palette bit per block are not compatible");
        if (bytePerBlock > 0 && blockDataSize * (64 / bytePerBlock) < blockCount)
            LDEBUG("\tERROR: Block data size is too small");
        for (int32_t i = 0; i < blockDataSize; i++) {
            uint64_t value = protocol::popLong(at, eof);
            LDEBUG("\t\tBlock data entry {}: {:x}", i, value);
        }

        // Biome palette parsing
        auto bytePerBiome = protocol::popByte(at, eof);
        LDEBUG("\tPalette bit per biome: {}", bytePerBiome);
        if (bytePerBiome == 0)
            LDEBUG("\tSingle value palette: {}", protocol::popVarInt(at, eof));
        else if (bytePerBiome <= 8) {
            LDEBUG("\tIndirect value palette");
            auto paletteSize = protocol::popVarInt(at, eof);
            LDEBUG("\tPalette size: {}", paletteSize);
            for (int32_t i = 0; i < paletteSize; i++) {
                auto value = protocol::popVarInt(at, eof);
                LDEBUG("\t\tPalette entry {}: {} -> {}", i, value, GLOBAL_PALETTE.fromProtocolIdToBlock(value).name);
            }
        } else
            LDEBUG("\tDirect value palette");

        // Biome data parsing
        auto biomeDataSize = protocol::popVarInt(at, eof);
        LDEBUG("\tBiome data size: {}", biomeDataSize);
        for (int32_t i = 0; i < biomeDataSize; i++) {
            auto value = protocol::popLong(at, eof);
            LDEBUG("\t\tBiome data entry {}: {:x}", i, value);
        }
    }

    auto blockEntitiesCount = protocol::popVarInt(at, eof);
    LDEBUG("Block entities count: {}", blockEntitiesCount);

    auto trustEdges = protocol::popBoolean(at, eof);
    LDEBUG("Trust edges: {}", trustEdges);

    auto skyLightMask = protocol::popArray<int64_t, protocol::popLong>(at, eof);
    LDEBUG("Sky light mask: {}: {}", skyLightMask.size(), (skyLightMask.size() != 1 ? "Somthing wrong btw" : std::to_string(skyLightMask.at(0))));

    auto blockLightMask = protocol::popArray<int64_t, protocol::popLong>(at, eof);
    LDEBUG("Block light mask: {}: {}", blockLightMask.size(), (blockLightMask.size() != 1 ? "Somthing wrong btw" : std::to_string(blockLightMask.at(0))));

    auto emptySkyLightMask = protocol::popArray<int64_t, protocol::popLong>(at, eof);
    LDEBUG("Empty sky light mask: {}: {}", emptySkyLightMask.size(), (emptySkyLightMask.size() != 1 ? "Somthing wrong btw" : std::to_string(emptySkyLightMask.at(0))));

    auto emptyBlockLightMask = protocol::popArray<int64_t, protocol::popLong>(at, eof);
    LDEBUG("Empty block light mask: {}: {}", emptyBlockLightMask.size(), (emptyBlockLightMask.size() != 1 ? "Somthing wrong btw" : std::to_string(emptyBlockLightMask.at(0))));

    // Sky light array parsing
    auto SkylightArrayLenght = protocol::popVarInt(at, eof);
    for (int32_t i = 0; i < SkylightArrayLenght; i++) {
        auto value = protocol::popArray<uint8_t, protocol::popByte>(at, eof);
        LDEBUG("Sky light Array[{}]: {}{}", i, value.size(), (value.size() != world_storage::SECTION_3D_SIZE / 2 ? "Somthing wrong btw" : ""));
        for (uint64_t j = 0; j < value.size(); j++) {
            if (value[j] != 15)
                LDEBUG("\tSky light Array[{}]: -> {}: {}", i, j, value[j]);
        }
    }

    // Block light array parsing
    auto BlocklightArrayLength = protocol::popVarInt(at, eof);
    for (int32_t i = 0; i < BlocklightArrayLength; i++) {
        auto value = protocol::popArray<uint8_t, protocol::popByte>(at, eof);
        LDEBUG("Block light Array[{}]: {}{}", i, value.size(), (value.size() != world_storage::SECTION_3D_SIZE / 2 ? "Somthing wrong btw" : ""));
        for (uint64_t j = 0; j < value.size(); j++) {
            if (value[j] != 15)
                LDEBUG("\tBlock light Array[{}]: -> {}{}", i, j, value[j]);
        }
    }

    if (at != eof + 1)
        LDEBUG("ERROR: Not all data was read: {}", (eof - at));
    else
        LDEBUG("All data was read");

    LDEBUG("--- CHUNK PACKET DATA END ---");

    LINFO("Done");
    invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Done", *invoker);
}

void command_parser::DumpChunk::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // invoker->sendMessage("Usage: /dumpchunk <x> <z>");
    } else {
        LINFO("Usage: /dumpchunk <x> <z>");
    }
}
