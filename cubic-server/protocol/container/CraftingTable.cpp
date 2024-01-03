#include "CraftingTable.hpp"
#include "protocol/container/Container.hpp"
#include <variant>

using CraftingTable = protocol::container::CraftingTable;

template<size_t N>
static void swapContainer(protocol::Slot &slot, std::array<protocol::Slot, N> &container)
{
    for (auto &containerSlot : container) {
        if (containerSlot == slot) {
            containerSlot.itemCount += slot.itemCount;
            if (containerSlot.itemCount <= 64) {
                slot.reset();
                return;
            }
            slot.itemCount = containerSlot.itemCount - 64;
            containerSlot.itemCount = 64;
        }
    }
    for (auto &containerSlot : container) {
        if (!containerSlot.present) {
            containerSlot = slot;
            slot.reset();
            return;
        }
    }
}

CraftingTable::CraftingTable(Player &player):
    Container(player.getWindowId(), protocol::container::InventoryType::TypeCrafting, "Crafting"),
    _playerInventory(player.getInventory()->playerInventory()),
    _hotbar(player.getInventory()->hotbar()),
    _offhand(player.getInventory()->offhand())
{
}

protocol::Slot &CraftingTable::at(int16_t index)
{
    if (index == -1)
        return cursor();
    else if (index == 0)
        return _craftedItem;
    else if (index < 10)
        return _craftingGrid.at(index - 1);
    else if (index < 37)
        return _playerInventory.at(index - 10);
    else if (index < 46)
        return _hotbar.at(index - 37);
    else
        throw std::out_of_range("Index out of range");
}

const protocol::Slot &CraftingTable::at(int16_t index) const
{
    if (index == -1)
        return cursor();
    else if (index == 0)
        return _craftedItem;
    else if (index < 10)
        return _craftingGrid.at(index - 1);
    else if (index < 37)
        return _playerInventory.at(index - 10);
    else if (index < 46)
        return _hotbar.at(index - 37);
    else
        throw std::out_of_range("Index out of range");
}

void CraftingTable::insert(protocol::Slot &slot)
{
    if (!slot.present)
        return;

    int8_t toInsert = slot.itemCount;

    // Insert in existing slot
    for (uint64_t i = 0; i < _hotbar.size(); i++) {
        if (_hotbar.at(i) == slot && _hotbar.at(i).itemCount < 64) {
            if (_hotbar.at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - _hotbar.at(i).itemCount;
                _hotbar.at(i).itemCount = 64;
            } else {
                _hotbar.at(i).itemCount += toInsert;
                return;
            }
        }
    }

    for (uint64_t i = 0; i < _playerInventory.size(); i++) {
        if (_playerInventory.at(i) == slot && _playerInventory.at(i).itemCount < 64) {
            if (_playerInventory.at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - _playerInventory.at(i).itemCount;
                _playerInventory.at(i).itemCount = 64;
            } else {
                _playerInventory.at(i).itemCount += toInsert;
                return;
            }
        }
    }

    // Insert in empty slot
    for (uint64_t i = 0; i < _hotbar.size(); i++) {
        if (!_hotbar.at(i).present) {
            _hotbar.at(i) = slot;
            return;
        }
    }

    for (uint64_t i = 0; i < _playerInventory.size(); i++) {
        if (!_playerInventory.at(i).present) {
            _playerInventory.at(i) = slot;
            return;
        }
    }
}

bool CraftingTable::canInsert(const protocol::Slot &slot)
{
    if (!slot.present)
        return false;

    int8_t toInsert = slot.itemCount;

    for (uint64_t i = 0; i < _hotbar.size(); i++) {
        if (!_hotbar.at(i).present)
            return true;
        if (_hotbar.at(i) == slot && _hotbar.at(i).itemCount < 64) {
            if (_hotbar.at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - _hotbar.at(i).itemCount;
                _hotbar.at(i).itemCount = 64;
            } else {
                _hotbar.at(i).itemCount += toInsert;
                return true;
            }
        }
    }

    for (uint64_t i = 0; i < _playerInventory.size(); i++) {
        if (!_playerInventory.at(i).present)
            return true;
        if (_playerInventory.at(i) == slot && _playerInventory.at(i).itemCount < 64) {
            if (_playerInventory.at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - _playerInventory.at(i).itemCount;
                _playerInventory.at(i).itemCount = 64;
            } else {
                _playerInventory.at(i).itemCount += toInsert;
                return true;
            }
        }
    }
    return false;
}

void CraftingTable::onClick(std::shared_ptr<Player> player, int16_t index, uint8_t buttonId, uint8_t mode, const std::vector<protocol::ClickContainer::SlotWithIndex> &updates)
{
    switch (mode) {
    case ClickMode::ShiftClick:
        if (index >= 9 && index < 36)
            swapContainer(at(index), _hotbar);
        else
            swapContainer(at(index), _craftingGrid);
        break;

    case ClickMode::Keys:
        if (buttonId == 40)
            std::swap(_offhand, at(index));
        else
            std::swap(_hotbar.at(buttonId), at(index));
        break;

    default:
        Container::onClick(player, index, buttonId, mode, updates);
        break;
    }
}
