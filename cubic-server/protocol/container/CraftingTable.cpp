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
    Container(1, protocol::container::InventoryType::Crafting, "Crafting"),
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
    else if (index < 45)
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
    else if (index < 45)
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

    for (uint64_t i = 0; i < _craftingGrid.size(); i++) {
        if (_craftingGrid.at(i) == slot && _craftingGrid.at(i).itemCount < 64) {
            if (_craftingGrid.at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - _craftingGrid.at(i).itemCount;
                _craftingGrid.at(i).itemCount = 64;
            } else {
                _craftingGrid.at(i).itemCount += toInsert;
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

    for (uint64_t i = 0; i < _craftingGrid.size(); i++) {
        if (!_craftingGrid.at(i).present) {
            _craftingGrid.at(i) = slot;
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

    for (uint64_t i = 0; i < _craftingGrid.size(); i++) {
        if (!_craftingGrid.at(i).present)
            return true;
        if (_craftingGrid.at(i) == slot && _craftingGrid.at(i).itemCount < 64) {
            if (_craftingGrid.at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - _craftingGrid.at(i).itemCount;
                _craftingGrid.at(i).itemCount = 64;
            } else {
                _craftingGrid.at(i).itemCount += toInsert;
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
