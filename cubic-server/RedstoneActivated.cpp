#include "Redstone.hpp"

using namespace Redstone::Activated;

void Piston::contract(void)
{
    Position pos = this->_pos + Position({1,0,0});

    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(pos.x, pos.z)).updateBlock(this->_pos, 0); // air
    this->_extended = false;
    // TODO make contract noise (863)
}

void Piston::extend(void)
{
    Position pos = this->_pos + Position({1,0,0});

    if (0) // TODO extend denied = there are 15 blocks in front of the piston
        return;
    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(this->_pos.x, this->_pos.z)).updateBlock(this->_pos,
        this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(this->_pos.x, this->_pos.z)).getBlock(this->_pos)); // pushed block
    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(pos.x, pos.z)).updateBlock(this->_pos, 34); // piston head
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