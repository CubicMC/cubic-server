#include "Inventory.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "entities/ArmorStats.hpp"
#include "protocol/container/Container.hpp"
#include <variant>

using Inventory = protocol::container::Inventory;

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

Inventory::Inventory(
    // std::array<protocol::Slot, INVENTORY_SIZE> &playerInventory, std::array<protocol::Slot, HOTBAR_SIZE> &hotbar, std::array<protocol::Slot, ARMOR_SIZE> &armor,
    // protocol::Slot &offhand
):
    Container(0, 0, "Inventory")
//     Container(0, 0, "Inventory"),
//     _playerInventory(playerInventory),
//     _hotbar(hotbar),
//     _armor(armor),
//     _offhand(offhand)
{
}

protocol::Slot &Inventory::at(int16_t index)
{
    if (index == -1)
        return cursor();
    else if (index < 5)
        return _craftingGrid.at(index);
    else if (index < 9)
        return _armor.at(index - 5);
    else if (index < 36)
        return _playerInventory.at(index - 9);
    else if (index < 45)
        return _hotbar.at(index - 36);
    else if (index == 45)
        return _offhand;
    else
        throw std::out_of_range("Index out of range");
}

const protocol::Slot &Inventory::at(int16_t index) const
{
    if (index == -1)
        return cursor();
    else if (index < 5)
        return _craftingGrid.at(index);
    else if (index < 9)
        return _armor.at(index - 5);
    else if (index < 36)
        return _playerInventory.at(index - 9);
    else if (index < 45)
        return _hotbar.at(index - 36);
    else if (index == 45)
        return _offhand;
    else
        throw std::out_of_range("Index out of range");
}

void Inventory::insert(protocol::Slot &slot)
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

bool Inventory::canInsert(const protocol::Slot &slot)
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

void Inventory::onClick(std::shared_ptr<Player> player, int16_t index, uint8_t buttonId, uint8_t mode, const std::vector<protocol::ClickContainer::SlotWithIndex> &updates)
{
    switch (mode) {
    case (int32_t) ClickMode::ShiftClick:
        if (index >= 9 && index < 36)
            swapContainer(at(index), _hotbar);
        else
            swapContainer(at(index), _playerInventory);
        player->updateEquipment(true, true, false, false, false, false);
        break;

    case (int32_t) ClickMode::Keys:
        if (buttonId == 40)
            std::swap(_offhand, at(index));
        else
            std::swap(_hotbar.at(buttonId), at(index));
        player->updateEquipment(true, true, false, false, false, false);
        break;

    default:
        Container::onClick(player, index, buttonId, mode, updates);
        player->updateEquipment(true, true, true, true, true, true);
        break;
    }

    int8_t defense = 0;
    int8_t toughness = 0;

    for (int16_t armorPos = 0; armorPos < 4; armorPos++) {
        if (!this->_armor[armorPos].present)
            continue;
        for (const armor::ArmorPiece &gear : armor::armors) {
            if (this->_armor[armorPos].itemID == ITEM_CONVERTER.fromItemToProtocolId(gear.item)) {
                defense += gear.protectionLevel;
                toughness += gear.toughnessLevel;
            }
        }
    }
    player->setDefense(defense);
    player->setToughness(toughness);
}
