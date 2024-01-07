#include "Furnace.hpp"
#include "Player.hpp"
#include "logging/logging.hpp"
#include "types.hpp"

using namespace tile_entity;
Furnace::Furnace(BlockId blockId, const Position &position, nbt_tag_t *nbt):
    TileEntity("minecraft:furnace", position, nbt),
    _burningTime(0),
    _burnTimeCurrentFuel(0),
    _cookTime(0),
    _ingredient(),
    _fuel(),
    _result(),
    _lit(Blocks::Furnace::Properties::Lit::FALSE),
    _facing(Blocks::Furnace::Properties::Facing::NORTH),
    _players()
{
    for (auto [name, value] : GLOBAL_PALETTE.fromProtocolIdToBlock(blockId).properties) {
        if (name == "lit") {
            if (value == "TRUE")
                _lit = Blocks::Furnace::Properties::Lit::TRUE;
            if (value == "FALSE")
                _lit = Blocks::Furnace::Properties::Lit::FALSE;
        }
        if (name == "facing") {
            if (value == "north")
                _facing = Blocks::Furnace::Properties::Facing::NORTH;
            if (value == "south")
                _facing = Blocks::Furnace::Properties::Facing::SOUTH;
            if (value == "west")
                _facing = Blocks::Furnace::Properties::Facing::WEST;
            if (value == "east")
                _facing = Blocks::Furnace::Properties::Facing::EAST;
        }
    }
    LINFO("Created Furnace with facing: {} and lit: {}", _facing, _lit == Blocks::Furnace::Properties::Lit::TRUE);
}

void Furnace::tick()
{
    bool updateFuelLeft = false;
    bool updateMaximumFuelBurnTime = false;
    bool updateProgressArrow = false;
    bool updateIngredientSlot = false;

    if (_burningTime == 0) {
        if (_fuel.itemCount > 0 && _ingredient.itemCount > 0) {
            _burningTime = _burnTimeCurrentFuel =
                1600; // TODO: get the right value with a convertor function (item name -> burning time) (for now, it's the burning time of a coal)
            _fuel.itemCount--;
            updateMaximumFuelBurnTime = true;
            if (_lit == Blocks::Furnace::Properties::Lit::FALSE) {
                _needBlockUpdate = true;
                _lit = Blocks::Furnace::Properties::Lit::TRUE;
            }
        } else {
            if (_lit == Blocks::Furnace::Properties::Lit::TRUE) {
                _needBlockUpdate = true;
                _lit = Blocks::Furnace::Properties::Lit::FALSE;
            }
        }
    }
    if (_burningTime > 0 && _ingredient.itemCount > 0) { // TODO: add a check to see if the ingredient can be cooked and if the result can be added to the result slot
        _cookTime++;
        if (_cookTime == 200) {
            _cookTime = 0;
            _ingredient.itemCount -= 1;
            if (_result.itemCount == 0) {
                _result = {true, 923, 1}; // TODO: create a function that take the ingredient and result and return the result (for now, it's cooked chicken)
            } else {
                _result.itemCount += 1;
            }
            updateIngredientSlot = true;
        }
        updateProgressArrow = true;
    } else {
        _cookTime = 0;
    }
    if (_burningTime > 0) {
        _burningTime--;
        updateFuelLeft = true;
    }
    bool updatePlayerList = false;
    if (_players.size() > 0) {
        for (auto &[player, windowId] : _players) {
            if (player.expired()) {
                updatePlayerList = true;
                continue;
            }
            if (updateFuelLeft)
                player.lock()->sendSetContainerProperty({windowId, 0, _burningTime});
            if (updateMaximumFuelBurnTime) {
                player.lock()->sendSetContainerProperty({windowId, 1, _burnTimeCurrentFuel});
                player.lock()->sendSetContainerSlot({player.lock()->getContainer(windowId), 1});
            }
            if (updateProgressArrow)
                player.lock()->sendSetContainerProperty({windowId, 2, _cookTime});
            if (updateIngredientSlot)
                player.lock()->sendSetContainerContent({player.lock()->getContainer(windowId)});
        }
    }
    if (updatePlayerList)
        _players.erase(std::remove_if(_players.begin(), _players.end(), [](const auto &pair) {
            auto &[player, windowId] = pair;
            return player.expired();
        }));
}

void Furnace::addPlayer(std::weak_ptr<Player> player, uint8_t windowId)
{
    _players.push_back({player, windowId});
    player.lock()->sendSetContainerProperty({windowId, 3, 200});
}

void Furnace::removePlayer(int id)
{
    auto playerToRemove = std::find_if(_players.begin(), _players.end(), [id](const auto &pair) {
        auto &[player, windowId] = pair;
        return !player.expired() && player.lock()->getId() == id;
    });
    if (playerToRemove != _players.end())
        _players.erase(playerToRemove);
}
