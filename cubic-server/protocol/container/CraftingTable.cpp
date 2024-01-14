#include "CraftingTable.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "entities/Item.hpp"
#include "protocol/container/Container.hpp"
#include <algorithm>
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

CraftingTable::CraftingTable(std::weak_ptr<Player> player):
    Container(player.lock()->getWindowId(), (int32_t) protocol::container::InventoryType::Crafting, "Crafting"),
    _playerInventory(player.lock()->getInventory()->playerInventory()),
    _hotbar(player.lock()->getInventory()->hotbar()),
    _offhand(player.lock()->getInventory()->offhand())
{
    player.lock()->sendOpenScreen({this->id(), this->type(), this->title()});
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
    std::shared_ptr<protocol::container::Container> thisTable = player->getContainer(this->id());

    switch (mode) {
    case (int32_t) ClickMode::ShiftClick:
        if (index >= 9 && index < 36)
            swapContainer(at(index), _hotbar);
        else
            swapContainer(at(index), _craftingGrid);
        break;

    case (int32_t) ClickMode::Keys:
        if (buttonId == 40)
            std::swap(_offhand, at(index));
        else
            std::swap(_hotbar.at(buttonId), at(index));
        break;
    case (int32_t) ClickMode::Click:
        if (index == -999) {
            if (!this->cursor().present)
                break;
            if (buttonId == 0) {
                player->getDimension()->makeEntity<Item>(cursor())->dropItem(player->getPosition());
                cursor().reset();
            } else {
                player->getDimension()->makeEntity<Item>(cursor().takeOne())->dropItem(player->getPosition());
            }
        } else if (buttonId == 0) {
            if (index == 0) { // clicked on crafted item
                if (this->cursor().present) { // already item on cursor
                    if (this->cursor() == this->_craftedItem && this->_craftedItem.itemCount + this->cursor().itemCount <= 64) // same item with enough stack space
                        this->cursor().itemCount += this->craftOne().itemCount;
                    else // different item or not enough stack space
                        break;
                } else // no item on cursor
                    this->cursor() = this->craftOne();
                player->sendSetContainerContent({thisTable});
            } else
                at(index).swap(cursor());
        } else {
            if (!cursor().present) {
                at(index).swap(cursor(), at(index).itemCount / 2);
            } else {
                cursor().swap(at(index), 1);
            }
        }
        break;
    default:
        Container::onClick(player, index, buttonId, mode, updates);
        break;
    }

    this->checkRecipe();
    player->sendSetContainerSlot({thisTable, 0});
}

void CraftingTable::close(UNUSED std::shared_ptr<Player> player)
{
    for (protocol::Slot &craftingSlot : this->_craftingGrid) {
        if (craftingSlot.present)
            swapContainer(craftingSlot, this->_hotbar);
        if (craftingSlot.present)
            swapContainer(craftingSlot, this->_playerInventory);
    }
}

bool CraftingTable::checkRecipe()
{
    // check shaped crafts
    const std::unordered_map<std::string, std::shared_ptr<Recipe::CraftingShaped>> shapedCrafts = RECIPES.getRecipesByType<Recipe::CraftingShaped>("minecraft");
    for (const auto &[_, recipe] : shapedCrafts) {
        if (this->checkCraftingShaped(recipe)) {
            return (true);
        }
    }

    // no shaped craft, check shapeless crafts
    const std::unordered_map<std::string, std::shared_ptr<Recipe::CraftingShapeless>> shapelessCrafts = RECIPES.getRecipesByType<Recipe::CraftingShapeless>("minecraft");
    for (const auto &[_, recipe] : shapelessCrafts) { // every
        if (this->checkCraftingShapeless(recipe)) {
            return (true);
        }
    }
    // no craft found, empty crafted item slot
    this->_craftedItem.reset();
    return (false);
}

bool CraftingTable::checkCraftingShaped(const std::shared_ptr<Recipe::CraftingShaped> craft)
{
    size_t x_offset = this->getXCraftingOffset();
    size_t y_offset = this->getYCraftingOffset();

    // returns if craft size exceeds remaining space
    if (3 - x_offset < craft->getXSize() || 3 - y_offset < craft->getYSize())
        return (false);

    size_t y = 0;
    for (y = 0; y + y_offset < 3 && y < craft->getYSize(); y++) {
        size_t x = 0;
        for (x = 0; x + x_offset < 3 && x < craft->getXSize(); x++) {
            if (craft->getPattern()[(y * craft->getXSize()) + x] == ' ') {
                // key ' ' implies empty slot, returns false if item found
                if (this->_craftingGrid.at(((y + y_offset) * 3) + x + x_offset).present)
                    return (false);
            } else {
                // other key, check if item is valid for craft at position
                // item should be present but is not
                if (!this->_craftingGrid.at(((y + y_offset) * 3) + x + x_offset).present)
                    return (false);
                // not right item at (x,y)
                if (!(craft->getKeys().at((craft->getPattern()).at((y * craft->getXSize()) + x))->contains(this->_craftingGrid.at(((y + y_offset) * 3) + x + x_offset).itemID)))
                    return (false);
            }
        }
        for (; x + x_offset < 3; x++) {
            // returns if craft's checked line correct but other items at its right
            if (this->_craftingGrid[((y + y_offset) * 3) + x + x_offset].present)
                return (false);
        }
    }
    for (; y + y_offset < 3; y++) {
        for (size_t x = 0; x < 3; x++) {
            // returns if craft correct but other items below it
            if (this->_craftingGrid[((y + y_offset) * 3) + x + x_offset].present)
                return (false);
        }
    }

    // recipe found, set crafted item in its slot
    this->_craftedItem.present = true;
    this->_craftedItem.itemID = craft->getCraftedItem();
    this->_craftedItem.itemCount = craft->getCraftedItemCount();
    return (true);
}

bool CraftingTable::checkCraftingShapeless(const std::shared_ptr<Recipe::CraftingShapeless> craft)
{
    size_t count = 0;
    for (const protocol::Slot &craftingSlot : this->_craftingGrid) {
        if (craftingSlot.present)
            count++;
    }
    if (count != craft->getIngredients().size()) {
        return (false);
    }
    LTRACE("could be shapeless craft {} ({}/{})", craft->getIdentifier(), count, craft->getIngredients().size());

    std::unordered_set<size_t> foundItems;
    for (size_t pos = 0; pos < 9; pos++) {
        if (!this->_craftingGrid.at(pos).present)
            continue;
        size_t ingredient = 0;
        while (ingredient < craft->getIngredients().size()) {
            if (!foundItems.contains(ingredient)) {
                if (craft->getIngredients().at(ingredient).contains(this->_craftingGrid.at(pos).itemID)) {
                    foundItems.insert(ingredient);
                    LTRACE("in crafting shapeless {}, found item {}", craft->getIdentifier(), ITEM_CONVERTER.fromProtocolIdToItem(this->_craftingGrid.at(pos).itemID));
                    break;
                }
            }
            ingredient++;
        }
    }
    if (foundItems.size() == craft->getIngredients().size()) {
        this->_craftedItem.present = true;
        this->_craftedItem.itemID = craft->getCraftedItem();
        this->_craftedItem.itemCount = craft->getCraftedItemCount();
        return (true);
    }
    return (false);
}

size_t CraftingTable::getXCraftingOffset() const
{
    for (size_t col = 0; col < 3; col++) {
        for (size_t row = 0; row < 3; row++) {
            if (this->_craftingGrid[col + (row * 3)].present)
                return (col);
        }
    }
    return (0);
}

size_t CraftingTable::getYCraftingOffset() const
{
    for (size_t pos = 0; pos < 9; pos++) {
        if (this->_craftingGrid[pos].present)
            return (pos / 3);
    }
    return (0);
}

protocol::Slot CraftingTable::craftOne()
{
    if (!this->_craftedItem.present)
        return (protocol::Slot());
    for (protocol::Slot &craftingSlot : this->_craftingGrid) {
        if (craftingSlot.present)
            craftingSlot.takeOne();
    }
    return (this->_craftedItem);
}

int8_t CraftingTable::maxCraftable() const
{
    int8_t count = 64;

    if (!this->_craftedItem.present)
        return (0);
    for (const protocol::Slot &craftingSlot : this->_craftingGrid) {
        if (craftingSlot.present)
            count = std::min(count, craftingSlot.itemCount);
    }
    return (count);
}
