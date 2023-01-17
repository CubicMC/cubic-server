#pragma once

#include <cstdint>

#include "common.hpp"
#include "nbt.hpp"

namespace protocol
{

    // https://wiki.vg/Data_types#Fixed-point_numbers
    // https://wiki.vg/index.php?title=Protocol&oldid=17753#Custom_Sound_Effect
    // https://wiki.vg/index.php?title=Protocol&oldid=17753#Sound_Effect
    // I think I should move this outside the protocol, but where ? '-'
    struct FloatingPosition
    {
        double x;
        double z;
        double y;
    };

    struct Position
    {
        int64_t x;
        int64_t y;
        int64_t z;
    };

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

    struct Rotation
    {
        float yaw;
        float pitch;
    };
} // namespace protocol

