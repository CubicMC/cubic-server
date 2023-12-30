#include "Furnace.hpp"
#include "logging/logging.hpp"
#include "types.hpp"

using namespace tile_entity;
Furnace::Furnace(BlockId blockId, const Position &position, nbt_tag_t *nbt):
    TileEntity("minecraft:furnace", position, nbt),
    _burningTime(0),
    _cookTime(0),
    _ingredient(),
    _fuel(),
    _result()
// _recipes(RECIPES)
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
    LINFO("Furnace::tick()");
    if (_burningTime == 0) {
        if (_fuel.itemCount > 0 && _ingredient.itemCount > 0) {
            _burningTime = 1600; // TODO: get the right value with a convertor function (item name -> burning time) (for now, it's the burning time of a coal)
            --_fuel.itemCount;
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
        ++_cookTime;
        if (_cookTime == 200) {
            _cookTime = 0;
            _ingredient.itemCount -= 1;
            if (_result.itemCount == 0) {
                _result = {true, 923, 1}; // TODO: create a function that take the ingredient and result and return the result (for now, it's cooked chicken)
            } else {
                _result.itemCount += 1;
            }
        }
    } else {
        _cookTime = 0;
    }
    if (_burningTime > 0) {
        --_burningTime;
    }
}
