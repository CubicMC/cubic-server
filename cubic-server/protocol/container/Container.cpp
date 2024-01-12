#include "Container.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "PlayerAttributes.hpp"
#include "entities/Item.hpp"
#include "logging/logging.hpp"
#include "protocol/Structures.hpp"
#include <nbt.h>

using Container = protocol::container::Container;

bool Container::canInsert(const protocol::Slot &slot)
{
    if (!slot.present)
        return false;

    int8_t toInsert = slot.itemCount;

    for (uint64_t i = 0; i < size(); i++) {
        if (!at(i).present)
            return true;
        if (at(i) == slot && at(i).itemCount < 64) {
            if (at(i).itemCount + toInsert > 64) {
                toInsert -= 64 - at(i).itemCount;
                at(i).itemCount = 64;
            } else {
                at(i).itemCount += toInsert;
                return true;
            }
        }
    }
    return false;
}

void Container::close(std::shared_ptr<Player> player)
{
    if (_cursor.present) {
        player->getDimension()->makeEntity<Item>(_cursor)->dropItem(player->getPosition());
        _cursor.reset();
    }
}

void Container::onClick(std::shared_ptr<Player> player, int16_t index, uint8_t buttonId, uint8_t mode, const std::vector<protocol::ClickContainer::SlotWithIndex> &updates)
{
    bool isCreative = player->getGamemode() == player_attributes::Gamemode::Creative;

    switch (mode) {
    case (int32_t) ClickMode::Click:
        if (index == -999) {
            if (!_cursor.present)
                break;
            if (buttonId == 0) {
                player->getDimension()->makeEntity<Item>(_cursor)->dropItem(player->getPosition());
                _cursor.reset();
            } else {
                player->getDimension()->makeEntity<Item>(_cursor.takeOne())->dropItem(player->getPosition());
            }
        } else if (buttonId == 0) {
            at(index).swap(_cursor);
        } else {
            if (!_cursor.present) {
                at(index).swap(_cursor, at(index).itemCount / 2);
            } else {
                _cursor.swap(at(index), 1);
            }
        }
        break;

    case (int32_t) ClickMode::ShiftClick:
        // TODO: I can't do this here, I don't know what diff
        break;

    // numbers and offhand swap
    case (int32_t) ClickMode::Keys:
        // TODO: I con't do this here, I don't know what diff
        break;

    case (int32_t) ClickMode::MiddleClick:
        LDEBUG("Middle click {} {}", _cursor.itemID, at(index).itemID);
        if (!isCreative)
            break;
        _cursor = at(index);
        _cursor.itemCount = 64;
        break;

    case (int32_t) ClickMode::DropButton:
        // We need this because of a bug in the client
        // The client sends a drop packet when you click outside of the inventory instead of a click packet
        if (index == -999)
            break;
        if (_cursor.present)
            break;
        if (!at(index).present)
            break;
        if (buttonId == 0) {
            player->getDimension()->makeEntity<Item>(at(index).takeOne())->dropItem(player->getPosition());
        } else {
            player->getDimension()->makeEntity<Item>(at(index))->dropItem(player->getPosition());
            at(index).reset();
        }
        break;

    case (int32_t) ClickMode::Drag:
        // Start drag
        if (buttonId == 0 && index == -999 && _state == (int32_t) State::Normal) {
            if (!_cursor.present)
                break;
            _state = (int32_t) State::LeftDrag;
        } else if (buttonId == 4 && index == -999 && _state == (int32_t) State::Normal) {
            if (!_cursor.present)
                break;
            _state = (int32_t) State::RightDrag;
        } else if (buttonId == 8 && index == -999 && _state == (int32_t) State::Normal && isCreative) {
            if (!_cursor.present)
                break;
            _state = (int32_t) State::MiddleDrag;
        }

        // Dragging
        else if (buttonId == 1 && _state == (int32_t) State::LeftDrag) {
            if (!_cursor.present)
                break;
            LDEBUG("Dragging left click with update size {}", updates.size());
        }

        // End drag
        else if (buttonId == 2 && index == -999 && _state == (int32_t) State::LeftDrag) {
            LDEBUG("End left drag with update size {}", updates.size());
            int16_t rest = _cursor.itemCount % updates.size();
            int16_t addedStack = _cursor.itemCount / updates.size();

            for (auto update : updates) {
                if (at(update.slotNumber).present) {
                    if (at(update.slotNumber) == _cursor && at(update.slotNumber).itemCount < 64) {
                        at(update.slotNumber).itemCount += addedStack;
                        if (at(update.slotNumber).itemCount > 64) {
                            rest += at(update.slotNumber).itemCount - 64;
                            at(update.slotNumber).itemCount = 64;
                        } else
                            addedStack = 0;
                    }
                } else {
                    at(update.slotNumber) = _cursor;
                    at(update.slotNumber).itemCount = addedStack;
                }
            }
            if (rest > 0)
                _cursor.itemCount = rest;
            else
                _cursor.reset();

            _state = (int32_t) State::Normal;
        } else
            // Something went wrong (packet out of order or something)
            _state = (int32_t) State::Normal;
        break;

    case (int32_t) ClickMode::DoubleClick:
        if (at(index).present || _cursor.itemCount == 64 || !_cursor.present)
            break;

        for (uint64_t i = 0; i < size(); i++) {
            if (_cursor == at(i)) {
                _cursor.itemCount += at(i).itemCount;
                if (_cursor.itemCount > 64) {
                    at(i).itemCount = _cursor.itemCount - 64;
                    _cursor.itemCount = 64;
                } else
                    at(i).reset();
            }
        }
        break;
    default:
        break;
    }
}
