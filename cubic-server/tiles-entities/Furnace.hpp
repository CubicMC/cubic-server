#ifndef CUBICSERVER_TILEENTITY_FURNACE_HPP
#define CUBICSERVER_TILEENTITY_FURNACE_HPP

#include "Server.hpp"
#include "TileEntity.hpp"
#include "blocks.hpp"
#include "options.hpp"
#include "protocol/Structures.hpp"
#include "tiles-entities/TileEntityList.hpp"
#include "types.hpp"
// #include "recipes/Smelting.hpp"

namespace tile_entity {
class Furnace : public TileEntity {
public:
    Furnace(BlockId blockId, const Position &position, nbt_tag_t *nbt = nullptr);

    Furnace(const Furnace &) = default;

    void tick() override;

    BlockId getBlockId() const override { return Blocks::Furnace::toProtocol(_facing, _lit); }

    int getBurningTime() const { return _burningTime; }
    int getBurnTimeCurrentFuel() const { return _burnTimeCurrentFuel; }
    int getCookTime() const { return _cookTime; }

    protocol::Slot &fuel() { return _fuel; }
    protocol::Slot &ingredient() { return _ingredient; }
    protocol::Slot &result() { return _result; }

    const protocol::Slot &fuel() const { return _fuel; }
    const protocol::Slot &ingredient() const { return _ingredient; }
    const protocol::Slot &result() const { return _result; }

private:
    int _burningTime;
    int _burnTimeCurrentFuel;
    int _cookTime;
    protocol::Slot _ingredient;
    protocol::Slot _fuel;
    protocol::Slot _result;
    Blocks::Furnace::Properties::Lit _lit;
    Blocks::Furnace::Properties::Facing _facing;
    // Recipes &_recipes;
};
}

#endif // CUBICSERVER_TILEENTITY_FURNACE_HPP
