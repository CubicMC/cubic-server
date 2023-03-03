#pragma once

#include <ostream>
#include <cstdint>

#include "common.hpp"
#include "nbt.hpp"
#include "types.hpp"

namespace protocol
{
    struct Slot
    {
        bool present;
        int32_t itemID;
        int8_t itemCount;
        // NBT nbt;
    };

    enum class ClientCommandActionID
    {
        perform_respawn = 0,
        request_stats = 1,
    };

    enum class ClientInformationChatMode
    {
        enabled = 0,
        commands_only = 1,
        hidden = 2,
    };

    enum class ClientInformationMainHand
    {
        left = 0,
        right = 1,
    };

    struct Instant
    {
        long seconds;
        int nanos;
    };

    // For chunk and light updates
    struct BlockEntity
    {
        int8_t sectionCoordinate;
        int16_t height;
        int32_t type;
        nbt::Compound data;
    };

    struct ArgumentSignature
    {
        std::string argument;
        std::vector<uint8_t> signature;
    };
} // namespace protocol

