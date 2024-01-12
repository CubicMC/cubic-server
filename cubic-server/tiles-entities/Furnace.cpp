#include "Furnace.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "items/fuels.hpp"
#include "logging/logging.hpp"
#include "recipes/Smelting.hpp"
#include "types.hpp"
#include <algorithm>

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
    _players(),
    _recipes(RECIPES.getRecipesByType<Recipe::Smelting>("minecraft"))
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
        if (_fuel.itemCount > 0 && _ingredient.itemCount > 0 && canCook()) {
            auto fuel = std::find_if(Items::fuels.begin(), Items::fuels.end(), [this](const auto &fuel) {
                return ITEM_CONVERTER.fromProtocolIdToItem(_fuel.itemID).find(fuel.name) != std::string::npos;
            });
            if (fuel != Items::fuels.end()) {
                LTRACE("Fuel {} (name: {}) found as a fuel. Using its burning time ({})", _fuel.itemID, ITEM_CONVERTER.fromProtocolIdToItem(_fuel.itemID), fuel->burnTime);
                _burnTimeCurrentFuel = _burningTime = fuel->burnTime;
            } else {
                LERROR("Fuel {} (name: {}) not found as a fuel. Using coal burning time ({})", _fuel.itemID, ITEM_CONVERTER.fromProtocolIdToItem(_fuel.itemID), 1600);
                _burnTimeCurrentFuel = _burningTime = 1600;
            }
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
            if (_cookTime > 0) {
                _cookTime -= 2;
                if (_cookTime < 0)
                    _cookTime = 0;
                updateProgressArrow = true;
            }
        }
    }
    if (_burningTime > 0 && _ingredient.itemCount > 0 && canCook()) {
        _cookTime++;
        if (_cookTime == 200) {
            _cookTime = 0;
            _ingredient.itemCount -= 1;
            if (_result.itemCount == 0) {
                // clang-format off
                ItemId resultId = std::find_if(_recipes.begin(), _recipes.end(), [this](const auto &recipe) {
                    return recipe.second->getIngredient() == _ingredient.itemID;
                })->second->getResult();
                // clang-format on
                _result = {true, resultId, 1};
            } else {
                _result.itemCount += 1;
            }
            updateIngredientSlot = true;
        }
        updateProgressArrow = true;
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
                player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::FuelLeft), _burningTime});
            if (updateMaximumFuelBurnTime) {
                player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::MaximumFuelBurnTime), _burnTimeCurrentFuel});
                player.lock()->sendSetContainerSlot({player.lock()->getContainer(windowId), 1});
            }
            if (updateProgressArrow)
                player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::ProgressArrow), _cookTime});
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
    player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::FuelLeft), _burningTime});
    player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::MaximumFuelBurnTime), _burnTimeCurrentFuel});
    player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::ProgressArrow), _cookTime});
    player.lock()->sendSetContainerProperty({windowId, int16_t(ContainerProperty::MaximumProgress), 200});
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

bool Furnace::canCook() const
{
    for (auto &[name, recipe] : _recipes) {
        if (recipe->getIngredient() == _ingredient.itemID) {
            if (_result.itemCount == 0)
                return true;
            if (recipe->getResult() == _result.itemID && _result.itemCount < 64)
                return true;
        }
    }
    return false;
}
