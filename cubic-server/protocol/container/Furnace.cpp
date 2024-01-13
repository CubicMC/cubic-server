#include "Furnace.hpp"
#include "Player.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"
#include "tiles-entities/Furnace.hpp"
#include <memory>

protocol::container::Furnace::Furnace(std::weak_ptr<Player> player, std::shared_ptr<tile_entity::Furnace> furnace):
    Container(player.lock()->getWindowId(), (int32_t) protocol::container::InventoryType::Furnace, "Furnace"),
    _ingredient(furnace->ingredient()),
    _fuel(furnace->fuel()),
    _result(furnace->result()),
    _playerInventory(player.lock()->getInventory()->playerInventory()),
    _hotbar(player.lock()->getInventory()->hotbar()),
    _playerId(player.lock()->getId()),
    _furnace(furnace)
{
    player.lock()->sendOpenScreen({this->id(), this->type(), this->title()});
    furnace->addPlayer(player, this->id());
}

protocol::container::Furnace::~Furnace()
{
    if (!_furnace.expired())
        _furnace.lock()->removePlayer(_playerId);
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
