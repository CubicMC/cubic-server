#pragma once

#include <cstdint>

#include "common.hpp"

namespace protocol
{
    struct Position
    {
        int64_t x;
        int64_t z;
        int64_t y;
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
        // NBT data;
    };
} // namespace protocol

