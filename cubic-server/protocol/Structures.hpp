#ifndef CUBICSERVER_PROTOCOL_STRUCTURES_HPP
#define CUBICSERVER_PROTOCOL_STRUCTURES_HPP

#include <cassert>
#include <cstdint>
#include <variant>

#include "items/UsableItem.hpp"
#include "items/usable-items/Bow.hpp"
#include "items/usable-items/FlintAndSteel.hpp"
#include "items/usable-items/Hoe.hpp"
#include "nbt.h"
#include "nbt.hpp"

namespace protocol {
// TODO(huntears): Add better error messages
#define GET_VALUE(t, type_accessor, dst, src, root)    \
    do {                                               \
        auto *__tmp = nbt_tag_compound_get(root, src); \
        assert(__tmp);                                 \
        assert(__tmp->type == t);                      \
        dst = __tmp->type_accessor.value;              \
    } while (0)

#define GET_VALUE_INT(dst, src, root) GET_VALUE(NBT_TYPE_INT, tag_int, dst, src, root)
#define GET_VALUE_BYTE(dst, src, root) GET_VALUE(NBT_TYPE_BYTE, tag_byte, dst, src, root)
#define GET_VALUE_SHORT(dst, src, root) GET_VALUE(NBT_TYPE_SHORT, tag_short, dst, src, root)
#define GET_VALUE_LONG(dst, src, root) GET_VALUE(NBT_TYPE_LONG, tag_long, dst, src, root)
#define GET_VALUE_FLOAT(dst, src, root) GET_VALUE(NBT_TYPE_FLOAT, tag_float, dst, src, root)
#define GET_VALUE_DOUBLE(dst, src, root) GET_VALUE(NBT_TYPE_DOUBLE, tag_double, dst, src, root)
#define GET_VALUE_STRING(dst, src, root)                                    \
    do {                                                                    \
        auto *__tmp = nbt_tag_compound_get(root, src);                      \
        assert(__tmp);                                                      \
        assert(__tmp->type == NBT_TYPE_STRING);                             \
        dst = std::string(__tmp->tag_string.value, __tmp->tag_string.size); \
    } while (0)

#define SET_VALUE(t, type_accessor, dst, src, root)    \
    do {                                               \
        auto *__tmp = nbt_tag_compound_get(root, src); \
        assert(__tmp);                                 \
        assert(__tmp->type == t);                      \
        __tmp->type_accessor.value = dst;              \
    } while (0)

#define SET_VALUE_INT(dst, src, root) SET_VALUE(NBT_TYPE_INT, tag_int, dst, src, root)

typedef std::variant<Items::UsableItem, Items::FlintAndSteel, Items::Hoe, Items::Bow>
    ItemType; /**< Used to get the right type of Usable item, to be able to use the right functions afterwards */
struct Slot {
    constexpr ~Slot()
    {
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

    inline void reset();
    inline void swap(Slot &other);
    inline void swap(Slot &other, int8_t count);
    inline Slot takeOne();
    /** damageTaken = damageTaken + 1, breaks item if (damageTaken > maxDurability) */
    void updateDamage();

    /**
     * @brief Get the UsableItem from Slot
     *
     * @return A UsableItem of the right type
     */
    const ItemType getUsableItemFromSlot();

public:
    bool present = false; /**< Slot: The inventory slot the item is in. */
    int32_t itemID = 0; /**< Item/Block ID. If not specified, gets treated as air, resulting in the item being removed. */
    int8_t itemCount = 0; /**< Count: Number of items stacked in this inventory slot. Values below 0 cause the item to be treated as air, resulting in the item being removed. */
    nbt_tag_t *nbt = nullptr; /**< TAG_compound. Additional information about the item. This tag is optional for most items. */
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

inline Slot Slot::takeOne()
{
    if (this->itemCount == 1) {
        Slot slot = std::move(*this);
        nbt = nullptr;
        this->reset();
        return slot;
    }
    if (this->itemCount > 1) {
        this->itemCount--;
        return Slot(true, this->itemID, 1, nbt_copy_tag(this->nbt));
    }
    return Slot();
}

// For chunk and light updates
struct BlockEntity {
    int8_t sectionCoordinate;
    int16_t height;
    int32_t type;
    nbt_tag_t *data;
};
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_STRUCTURES_HPP
