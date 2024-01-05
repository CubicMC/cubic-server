#ifndef PROTOCOL_CONTAINER_CONTAINERCLASS_HPP
#define PROTOCOL_CONTAINER_CONTAINERCLASS_HPP

#include "chat/Message.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/Structures.hpp"
#include <cstdint>

namespace protocol::container {

enum State {
    Normal = 0,
    LeftDrag = 1,
    RightDrag = 2,
    MiddleDrag = 3,
};

enum ClickMode {
    Click = 0,
    ShiftClick = 1,
    Keys = 2,
    MiddleClick = 3,
    DropButton = 4,
    Drag = 5,
    DoubleClick = 6,
};

// I was obligated to rename the enum to avoid conflict
// with the different classes of each type
enum InventoryType {
    TypeGeneric9x1 = 0,
    TypeGeneric9x2 = 1,
    TypeGeneric9x3 = 2,
    TypeGeneric9x4 = 3,
    TypeGeneric9x5 = 4,
    TypeGeneric9x6 = 5,
    TypeGeneric3x3 = 6,
    TypeAnvil = 7,
    TypeBeacon = 8,
    TypeBlastFurnace = 9,
    TypeBrewingStand = 10,
    TypeCrafting = 11,
    TypeEnchantment = 12,
    TypeFurnace = 13,
    TypeGrindstone = 14,
    TypeHopper = 15,
    TypeLectern = 16,
    TypeLoom = 17,
    TypeMerchant = 18,
    TypeShulkerBox = 19,
    TypeSmothing = 20,
    TypeSmoker = 21,
    TypeCartography = 22,
    TypeStoneCutter = 23
};

class Container {
public:
    Container(uint8_t id, int32_t type, chat::Message title):
        _id(id),
        _type(type),
        _state(State::Normal),
        _title(std::move(title)),
        _cursor(false),
        _cariedItemIndex(0)
    {
    }

    virtual ~Container() = default;

    virtual constexpr protocol::Slot &at(int16_t index) = 0;
    virtual constexpr const protocol::Slot &at(int16_t index) const = 0;
    virtual constexpr inline uint64_t size() const = 0;

    /**
     * @brief Insert the given slot in the container
     * If the slot is already present, the item count will be added to the existing slot
     * this will modify the slot to reflect what is left after the insertion
     *
     * @param slot
     */
    virtual void insert(protocol::Slot &slot) = 0;

    NODISCARD virtual bool canInsert(const protocol::Slot &slot);

    protocol::Slot &operator[](int16_t index) { return at(index); }
    const protocol::Slot &operator[](int16_t index) const { return at(index); }
    constexpr protocol::Slot &cursor() { return _cursor; }
    constexpr void setCariedItemIndex(int16_t index) { _cariedItemIndex = index; }

    virtual void onClick(std::shared_ptr<Player> player, int16_t index, uint8_t buttonId, uint8_t mode, const std::vector<protocol::ClickContainer::SlotWithIndex> &updates);
    virtual void onButtonClick(UNUSED std::shared_ptr<Player> player, UNUSED uint8_t buttonId) {};
    virtual void close(UNUSED std::shared_ptr<Player> player);

    NODISCARD constexpr inline uint8_t id() const { return _id; }
    NODISCARD constexpr inline int32_t type() const { return _type; }
    NODISCARD constexpr inline int32_t state() const { return _state; }
    NODISCARD constexpr inline const chat::Message &title() const { return _title; }
    NODISCARD constexpr inline const protocol::Slot &cursor() const { return _cursor; }
    NODISCARD constexpr inline const protocol::Slot &cariedItem() const { return at(_cariedItemIndex); }

private:
    uint8_t _id;
    int32_t _type;
    int32_t _state;
    chat::Message _title;
    protocol::Slot _cursor;
    int16_t _cariedItemIndex;
};

} // namespace protocol::inventory_screen

#endif // PROTOCOL_WINDOW_WINDOWCLASS_HPP
