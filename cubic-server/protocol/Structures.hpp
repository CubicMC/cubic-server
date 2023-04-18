#pragma once
#ifndef CUBICSERVER_PROTOCOL_STRUCTURES_HPP
#define CUBICSERVER_PROTOCOL_STRUCTURES_HPP

#include <cstdint>

#include "nbt.hpp"

namespace protocol {
struct Slot {
    bool present;
    int32_t itemID;
    int8_t itemCount;
    // NBT nbt;
};

// For chunk and light updates
struct BlockEntity {
    int8_t sectionCoordinate;
    int16_t height;
    int32_t type;
    nbt::Compound data;
};
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_STRUCTURES_HPP
