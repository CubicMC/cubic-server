#include "Redstone.hpp"

using namespace Redstone::Activated;

void Piston::contract(void)
{
    Position chunkPos = { this->_pos.x % 16, this->_pos.y % 16, this->_pos.z % 16 };
    Position pos = chunkPos + Position({1,0,0});

    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(pos.x, pos.z)).updateBlock(chunkPos, 0); // air
    this->_extended = false;
    // TODO make contract noise (863)
}

void Piston::extend(void)
{
    Position chunkPos = { this->_pos.x % 16, this->_pos.y % 16, this->_pos.z % 16 };
    Position pos = chunkPos + Position({1,0,0});

    if (0) // TODO extend denied = there are 15 blocks in front of the piston
        return;
    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(chunkPos.x, chunkPos.z)).updateBlock(chunkPos,
        this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(chunkPos.x, chunkPos.z)).getBlock(pos)); // pushed block
    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(pos.x, pos.z)).updateBlock(chunkPos, 34); // piston head
    this->_extended = true;
    // TODO make extend noise (864)
}

Piston::Piston(std::shared_ptr<Dimension> dim, Position pos, Facing facing, bool ext, bool bud):
    Redstone::RedstoneItem(dim, pos),
    _facing(facing),
    _extended(false), // TODO check for eventual environmental powering
    _budded(bud)
{
    if (_extended)
        this->extend();
    if (_budded)
        ; // TODO handle event bud
}

Piston::~Piston(void) {}