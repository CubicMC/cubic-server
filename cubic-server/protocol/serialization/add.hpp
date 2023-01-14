#ifndef PROTOCOL_SERIALIZATION_ADD_HPP
#define PROTOCOL_SERIALIZATION_ADD_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "protocol/ParseExceptions.hpp"
#include "protocol/common.hpp"
#include "protocol/Structures.hpp"
#include "addPrimaryType.hpp"

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
} // namespace protocol

#endif
