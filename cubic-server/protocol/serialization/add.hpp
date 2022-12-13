#ifndef PROTOCOL_SERIALIZATION_ADD_HPP
#define PROTOCOL_SERIALIZATION_ADD_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "ParseExceptions.hpp"
#include "common.hpp"
#include "Structures.hpp"
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
} // namespace protocol

#endif
