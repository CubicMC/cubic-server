#ifndef PROTOCOL_SERIALIZATION_ADD_HPP
#define PROTOCOL_SERIALIZATION_ADD_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "protocol/ParseExceptions.hpp"
#include "protocol/common.hpp"
#include "protocol/Structures.hpp"
#include "addPrimaryType.hpp"
#include "world_storage/Palette.hpp"
#include "world_storage/ChunkColumn.hpp"

namespace protocol
{
    constexpr void addClientCommandActionID(std::vector<uint8_t> &out, const ClientCommandActionID &data)
    {
        return addVarInt(out, static_cast<int32_t>(data));
    }

    constexpr void addClientInformationChatMode(std::vector<uint8_t> &out, const ClientInformationChatMode &data)
    {
        return addVarInt(out, static_cast<int32_t>(data));
    }

    constexpr void addBlockEntity(std::vector<uint8_t> &out, const BlockEntity &data)
    {
        addByte(out, data.sectionCoordinate);
        addShort(out, data.height);
        addVarInt(out, data.type);
        addNBT(out, data.data);
    }

    constexpr void addBlockEntities(std::vector<uint8_t> &out, const std::vector<BlockEntity> &data)
    {
        addVarInt(out, data.size());
        for (auto &i : data)
            addBlockEntity(out, i);
    }

    constexpr void addLightArray(std::vector<uint8_t> &out, const std::vector<std::array<uint8_t, LIGHT_ARRAY_SIZE>> &data)
    {
        addVarInt(out, data.size());
        for (auto &lightArray : data) {
            addVarInt(out, lightArray.size());
            for (auto light : lightArray)
                addByte(out, light);
        }
    }

    constexpr void addPalette(std::vector<uint8_t> &out, const world_storage::Palette &data)
    {
    // Byte per block
    auto bytePerBlock = data.getBytePerBlock();
    if (bytePerBlock == 0)
        return;
    if (bytePerBlock <= 4)
        out.push_back(4);
    else if (bytePerBlock <= 8)
        out.push_back(bytePerBlock);
    else
        out.push_back(15); // HARD CODED BECAUSE I DON'T WANT TO THINK ABOUT LOGARITHMS

    auto size = data.size();
    if (size != 1)
        addVarInt(out, data.size());

    for (auto &id : data)
        addVarInt(out, id);
    }

    // https://wiki.vg/Chunk_Format#Serializing
    constexpr void addChunkColumn(std::vector<uint8_t> &out, const world_storage::ChunkColumn &data)
    {
        std::vector<uint8_t> chunkData;

        for (uint8_t sectionIdx = 0; sectionIdx < world_storage::NB_OF_CHUNKS; sectionIdx++) {
            world_storage::Palette blockPalette(4);
            auto section = data.getBlocks().begin() + (sectionIdx * world_storage::SECTION_3D_SIZE);
            uint16_t blockInsideSection = 0;

            for (uint16_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
                auto &block = section[i];
                blockPalette.addBlock(block);
                if (block != 0)
                    blockInsideSection++;
            }
            // Number of block inside the section
            addShort(chunkData, blockInsideSection);
            addPalette(chunkData, blockPalette);

            // Size of the long array
            uint32_t longArraySize = world_storage::SECTION_3D_SIZE * blockPalette.getBytePerBlock() / 64;
            std::vector<uint64_t> longArray;
            longArray.resize(longArraySize);

            // A bitmask that contains bitsPerBlock set bits
            uint32_t individualValueMask = (uint32_t)((1 << blockPalette.getBytePerBlock()) - 1);

            for (uint8_t y = 0; y < world_storage::SECTION_HEIGHT; y++) {
                for (uint8_t z = 0; z < world_storage::SECTION_WIDTH; z++) {
                    for (uint8_t x = 0; x < world_storage::SECTION_WIDTH; x++) {
                        int blockNumber = world_storage::calculateBlockIdx({x, y, z});
                        int startLong = (blockNumber * blockPalette.getBytePerBlock()) / 64;
                        int startOffset = (blockNumber * blockPalette.getBytePerBlock()) % 64;
                        int endLong = ((blockNumber + 1) * blockPalette.getBytePerBlock() - 1) / 64;

                        uint64_t value = blockPalette.getBlockId(section[blockNumber]);
                        value &= individualValueMask;

                        longArray.at(startLong) |= (value << startOffset);

                        if (startLong != endLong)
                            longArray[endLong] = (value >> (64 - startOffset));
                    }
                }
            }
            addArray<uint64_t, addUnsignedLong>(chunkData, longArray);
        }

        // TODO
        // BIOMES
        chunkData.push_back(0);
        addVarInt(chunkData, 0);
        addVarInt(chunkData, 0);

        // Add the chunk data
        addArray<uint8_t, addByte>(out, chunkData);
    }
} // namespace protocol

#endif
