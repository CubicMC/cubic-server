#ifndef CUBICSERVER_PROTOCOL_STRUCTURES_HPP
#define CUBICSERVER_PROTOCOL_STRUCTURES_HPP

#include <cstdint>

#include "nbt.h"
#include "nbt.hpp"

namespace protocol {
struct Slot {
    constexpr ~Slot()
    {
        // clang-format off
        if (this->nbt != nullptr)
            nbt_free_tag(this->nbt);
    }

    constexpr Slot(bool present = false, int32_t itemID = 0, int8_t itemCount = 0, nbt_tag_t *nbt = nullptr):
        present(present),
        itemID(itemID),
        itemCount(itemCount),
        nbt(nbt)
    {
    }

    Slot(const Slot &other):
        present(other.present),
        itemID(other.itemID),
        itemCount(other.itemCount),
        nbt(nbt_copy_tag(other.nbt))
    {
    }
    Slot &operator=(const Slot &other)
    {
        this->present = other.present;
        this->itemID = other.itemID;
        this->itemCount = other.itemCount;
        this->nbt = nbt_copy_tag(other.nbt);
        return *this;
    }
    // constexpr Slot(Slot &&other) noexcept = default;
    // constexpr Slot &operator=(Slot &&other) noexcept = default;
    constexpr Slot(Slot &&other) noexcept:
        present(other.present),
        itemID(other.itemID),
        itemCount(other.itemCount),
        nbt(other.nbt)
    {
        other.nbt = nullptr;
    }
    constexpr Slot &operator=(Slot &&other) noexcept
    {
        if (this == &other)
            return *this;
        this->present = other.present;
        this->itemID = other.itemID;
        this->itemCount = other.itemCount;
        this->nbt = other.nbt;
        other.nbt = nullptr;
        return *this;
    }

    bool present = false;                           /* Slot: The inventory slot the item is in. */
    int32_t itemID = 0;                             /* Item/Block ID. If not specified, gets treated as air, resulting in the item being removed. */
    int8_t itemCount = 0;                           /* Count: Number of items stacked in this inventory slot. Values below 0 cause the item to be treated as air, resulting in the item being removed. */
    nbt_tag_t *nbt = nullptr;                       /* TAG_compound. Additional information about the item. This tag is optional for most items. */
    inline void reset();
    inline void swap(Slot &other);
    inline void swap(Slot &other, int8_t count);
    // clang-format on
};

inline bool operator==(const Slot &lhs, const Slot &rhs) { return lhs.present == rhs.present && lhs.itemID == rhs.itemID && nbt_compare_tags(lhs.nbt, rhs.nbt); }

inline void Slot::reset()
{
    present = false;
    itemID = 0;
    itemCount = 0;
    nbt_free_tag(nbt);
    nbt = nullptr;
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
