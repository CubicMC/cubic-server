#ifndef PROTOCOL_WINDOW_INVENTORY_HPP
#define PROTOCOL_WINDOW_INVENTORY_HPP

#include "protocol/container/Container.hpp"
#include <cstdint>

constexpr const int16_t INVENTORY_SIZE = 27;
constexpr const int16_t HOTBAR_SIZE = 9;
constexpr const int16_t ARMOR_SIZE = 4;
constexpr const int16_t CRAFTING_GRID_2X2 = 5;
constexpr const int16_t CRAFTING_GRID_3X3 = 10;
constexpr const int16_t HOTBAR_OFFSET = INVENTORY_SIZE + ARMOR_SIZE + CRAFTING_GRID_2X2;

namespace protocol::container {
// Note that this is different from inventory items stored in a player.dat file.
// This may help: https://gist.github.com/459a1691c3dd751db160
class Inventory : public Container {
public:
    explicit Inventory();
    virtual ~Inventory() = default;

    protocol::Slot &at(int16_t index) override;
    const protocol::Slot &at(int16_t index) const override;
    NODISCARD constexpr inline uint64_t size() const override { return INVENTORY_SIZE + HOTBAR_SIZE + ARMOR_SIZE + CRAFTING_GRID_2X2 + 1; }
    void insert(protocol::Slot &slot) override;
    bool canInsert(const protocol::Slot &slot) override;

    void onClick(std::shared_ptr<Player> player, int16_t index, uint8_t buttonId, uint8_t mode, const std::vector<protocol::ClickContainer::SlotWithIndex> &updates) override;

    NODISCARD constexpr inline std::array<protocol::Slot, INVENTORY_SIZE> &playerInventory() { return _playerInventory; }
    NODISCARD constexpr inline std::array<protocol::Slot, HOTBAR_SIZE> &hotbar() { return _hotbar; }
    NODISCARD constexpr inline std::array<protocol::Slot, ARMOR_SIZE> &armor() { return _armor; };
    NODISCARD constexpr inline protocol::Slot &offhand() { return _offhand; }
    NODISCARD constexpr inline std::array<protocol::Slot, CRAFTING_GRID_2X2> &craftingGrid() { return _craftingGrid; }

    NODISCARD constexpr inline const std::array<protocol::Slot, INVENTORY_SIZE> &playerInventory() const { return _playerInventory; }
    NODISCARD constexpr inline const std::array<protocol::Slot, HOTBAR_SIZE> &hotbar() const { return _hotbar; }
    NODISCARD constexpr inline const std::array<protocol::Slot, ARMOR_SIZE> &armor() const { return _armor; };
    NODISCARD constexpr inline const protocol::Slot &offhand() const { return _offhand; }
    NODISCARD constexpr inline const std::array<protocol::Slot, CRAFTING_GRID_2X2> &craftingGrid() const { return _craftingGrid; }

private:
    std::array<protocol::Slot, INVENTORY_SIZE> _playerInventory;
    std::array<protocol::Slot, HOTBAR_SIZE> _hotbar;
    std::array<protocol::Slot, ARMOR_SIZE> _armor;
    protocol::Slot _offhand;
    std::array<protocol::Slot, CRAFTING_GRID_2X2> _craftingGrid;
};

} // namespace protocol::window

#endif // PROTOCOL_WINDOW_INVENTORY_HPP
