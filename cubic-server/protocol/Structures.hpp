#pragma once

#include <cstdint>
#include <ostream>

#include "common.hpp"
#include "nbt.hpp"
#include "types.hpp"

namespace protocol {
struct Slot {
    bool present;
    int32_t itemID;
    int8_t itemCount;
    // NBT nbt;
};

struct Instant {
    long seconds;
    int nanos;
};

// For chunk and light updates
struct BlockEntity {
    int8_t sectionCoordinate;
    int16_t height;
    int32_t type;
    nbt::Compound data;
};

struct ArgumentSignature {
    std::string argument;
    std::vector<uint8_t> signature;
};

struct SlotWithIndex {
    int16_t slot_number;
    Slot slot_data;
};
} // namespace protocol
