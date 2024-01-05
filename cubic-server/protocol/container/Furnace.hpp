#ifndef PROTOCOL_WINDOW_FURNACE_HPP
#define PROTOCOL_WINDOW_FURNACE_HPP

#include "protocol/Structures.hpp"
#include "protocol/container/Container.hpp"
#include <cstdint>
#include <memory>

constexpr const int16_t FURNACE_SLOT_NUMBER = 3;
constexpr const int16_t PLAYER_INVENTORY_SIZE = 27;
constexpr const int16_t PLAYER_HOTBAR_SIZE = 9;

namespace tile_entity {
class Furnace;
}
class Player;

namespace protocol::container {
class Furnace : public Container {
public:
    explicit Furnace(std::weak_ptr<Player> player, std::shared_ptr<tile_entity::Furnace> furnace);
    ~Furnace();

    protocol::Slot &at(int16_t index) override;
    const protocol::Slot &at(int16_t index) const override;
    NODISCARD constexpr inline uint64_t size() const override { return FURNACE_SLOT_NUMBER + PLAYER_INVENTORY_SIZE + PLAYER_HOTBAR_SIZE; }
    void insert(protocol::Slot &slot) override;
    // bool canInsert(const protocol::Slot &slot) override;

    // void onClick(std::shared_ptr<Player> player, int16_t index, uint8_t buttonId, uint8_t mode, const std::vector<protocol::ClickContainer::SlotWithIndex> &updates) override;

    NODISCARD constexpr inline protocol::Slot &fuel() { return _fuel; }
    NODISCARD constexpr inline protocol::Slot &ingredient() { return _ingredient; }
    NODISCARD constexpr inline protocol::Slot &result() { return _result; }
    NODISCARD constexpr inline std::array<protocol::Slot, PLAYER_INVENTORY_SIZE> &playerInventory() { return _playerInventory; }
    NODISCARD constexpr inline std::array<protocol::Slot, PLAYER_HOTBAR_SIZE> &hotbar() { return _hotbar; }

    NODISCARD constexpr inline const protocol::Slot &fuel() const { return _fuel; }
    NODISCARD constexpr inline const protocol::Slot &ingredient() const { return _ingredient; }
    NODISCARD constexpr inline const protocol::Slot &result() const { return _result; }
    NODISCARD constexpr inline const std::array<protocol::Slot, PLAYER_INVENTORY_SIZE> &playerInventory() const { return _playerInventory; }
    NODISCARD constexpr inline const std::array<protocol::Slot, PLAYER_HOTBAR_SIZE> &hotbar() const { return _hotbar; }

private:
    protocol::Slot &_ingredient;
    protocol::Slot &_fuel;
    protocol::Slot &_result;
    std::array<protocol::Slot, PLAYER_INVENTORY_SIZE> &_playerInventory;
    std::array<protocol::Slot, PLAYER_HOTBAR_SIZE> &_hotbar;
    const int _playerId;
    std::weak_ptr<tile_entity::Furnace> _furnace;
};
}

#endif // PROTOCOL_WINDOW_FURNACE_HPP
