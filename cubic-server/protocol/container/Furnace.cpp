#include "Furnace.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"

protocol::container::Furnace::Furnace(Player &player, std::shared_ptr<tile_entity::Furnace> furnace):
    Container(player.getWindowId(), protocol::container::InventoryType::TypeFurnace, "Furnace"),
    _ingredient(furnace->ingredient()),
    _fuel(furnace->fuel()),
    _result(furnace->result()),
    _playerInventory(player.getInventory()->playerInventory()),
    _hotbar(player.getInventory()->hotbar())
{
}

protocol::Slot &protocol::container::Furnace::at(int16_t index)
{
    if (index == -1)
        return cursor();
    else if (index == 0)
        return _ingredient;
    else if (index == 1)
        return _fuel;
    else if (index == 2)
        return _result;
    else if (index < 30)
        return _playerInventory.at(index - 3);
    else if (index < 39)
        return _hotbar.at(index - 30);
    else
        throw std::out_of_range("Index out of range");
}

const protocol::Slot &protocol::container::Furnace::at(int16_t index) const
{
    if (index == -1)
        return cursor();
    else if (index == 0)
        return _ingredient;
    else if (index == 1)
        return _fuel;
    else if (index == 2)
        return _result;
    else if (index < 30)
        return _playerInventory.at(index - 3);
    else if (index < 39)
        return _hotbar.at(index - 30);
    else
        throw std::out_of_range("Index out of range");
}

void protocol::container::Furnace::insert(UNUSED protocol::Slot &slot)
{
    LERROR("Furnace::insert not implemented");
    // if (slot.itemCount == 0)
    //     return;
    // if (slot.itemCount == 1) {
    //     if (slot == _ingredient) {
    //         _ingredient.itemCount += 1;
    //         slot.reset();
    //         return;
    //     }
    //     if (slot == _fuel) {
    //         _fuel.itemCount += 1;
    //         slot.reset();
    //         return;
    //     }
    //     if (slot == _result) {
    //         _result.itemCount += 1;
    //         slot.reset();
    //         return;
    //     }
    // }
    // if (slot == _ingredient) {
    //     _ingredient.itemCount += slot.itemCount;
    //     slot.reset();
    //     return;
    // }
    // if (slot == _fuel) {
    //     _fuel.itemCount += slot.itemCount;
    //     slot.reset();
    //     return;
    // }
    // if (slot == _result) {
    //     _result.itemCount += slot.itemCount;
    //     slot.reset();
    //     return;
    // }
    // for (auto &containerSlot : _playerInventory) {
    //     if (containerSlot == slot) {
    //         containerSlot.itemCount += slot.itemCount;
    //         if (containerSlot.itemCount <= 64) {
    //             slot.reset();
    //             return;
    //         }
    //         slot.itemCount = containerSlot.itemCount - 64;
    //         containerSlot.itemCount = 64;
    //     }
    // }
    // for (auto &containerSlot : _playerInventory) {
    //     if (!containerSlot.present) {
    //         containerSlot = slot;
    //         slot.reset();
    //         return;
    //     }
    // }
    // for (auto &containerSlot : _hotbar) {
    //     if (containerSlot == slot) {
    //         containerSlot.itemCount += slot.itemCount;
    //         if (containerSlot.itemCount <= 64) {
    //             slot.reset();
    //             return;
    //         }
    //         slot.itemCount = containerSlot.itemCount - 64;
    //         containerSlot.itemCount = 64;
    //     }
    // }
    // for (auto &containerSlot : _hotbar) {
    //     if (!containerSlot.present) {
    //         containerSlot = slot;
    //         slot.reset();
    //         return;
    //     }
    // }
}
