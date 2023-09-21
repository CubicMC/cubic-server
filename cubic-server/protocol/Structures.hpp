#ifndef CUBICSERVER_PROTOCOL_STRUCTURES_HPP
#define CUBICSERVER_PROTOCOL_STRUCTURES_HPP

#include <cstdint>

#include "nbt.hpp"
#include <nbt.h>

namespace protocol {
struct Slot {
    constexpr ~Slot()
    {
        // Lol can't do that because we can copy the slot, fml
        // if (this->present && this->nbt != nullptr)
        //     nbt_free_tag(this->nbt);
    }
    bool present = false;
    int32_t itemID = 0;
    int8_t itemCount = 0;
    nbt_tag_t *nbt = nullptr;
    inline void reset();
    inline void swap(Slot &other);
    inline void swap(Slot &other, int8_t count);
};

inline bool operator==(const Slot &lhs, const Slot &rhs) { return lhs.present == rhs.present && lhs.itemID == rhs.itemID /* && lhs.nbt == rhs.nbt */; }

inline void Slot::reset()
{
    present = false;
    itemID = 0;
    itemCount = 0; /* nbt = nbt::Compound(); */
}

void Slot::swap(protocol::Slot &other)
{
    if (this->itemID == other.itemID && this->itemID != 0) {
        auto rest = this->itemCount + other.itemCount - 64;
        if (rest > 0) {
            this->itemCount = 64;
            other.itemCount = rest;
            return;
        }

        this->itemCount += other.itemCount;
        other.reset();
        return;
    }
    std::swap(*this, other);
}

void Slot::swap(protocol::Slot &other, int8_t x)
{
    if (this->present && other.present && this->itemID != other.itemID)
        return this->swap(other);
    if (this->itemCount <= x)
        return this->swap(other);

    other.present = true;
    other.itemID = this->itemID;
    this->itemCount -= x;
    other.itemCount += x;
    if (other.itemCount > 64) {
        this->itemCount += other.itemCount - 64;
        other.itemCount = 64;
    }
}

// For chunk and light updates
struct BlockEntity {
    int8_t sectionCoordinate;
    int16_t height;
    int32_t type;
    nbt::Compound data;
};
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_STRUCTURES_HPP
