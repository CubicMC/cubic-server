#ifndef CUBICSERVER_TILEENTITY_FURNACE_HPP
#define CUBICSERVER_TILEENTITY_FURNACE_HPP

#include "Server.hpp"
#include "TileEntity.hpp"
#include "blocks.hpp"
#include "options.hpp"
#include "protocol/Structures.hpp"
#include "tiles-entities/TileEntityList.hpp"
#include "types.hpp"

class Player;

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

    void addPlayer(std::weak_ptr<Player> player, uint8_t windowId);
    void removePlayer(int playerId);

private:
    int16_t _burningTime;
    int16_t _burnTimeCurrentFuel;
    int16_t _cookTime;
    protocol::Slot _ingredient;
    protocol::Slot _fuel;
    protocol::Slot _result;
    Blocks::Furnace::Properties::Lit _lit;
    Blocks::Furnace::Properties::Facing _facing;
    std::vector<std::pair<std::weak_ptr<Player>, uint8_t>> _players;
};
}

#endif // CUBICSERVER_TILEENTITY_FURNACE_HPP
