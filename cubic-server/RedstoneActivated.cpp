#include "Redstone.hpp"

using namespace Redstone::Activated;

void Piston::contract(void)
{
//    this->_dim->getSection(this->_pos + Vector3<double>(1,0,0))->updateBlock(this->_pos, 0); // air
    this->_extended = false;
    // TODO make contract noise (863)
}

void Piston::extend(void)
{
    if (0) // TODO extend denied = there are 15 blocks in front of the piston
        return;
//    this->_dim->getSection(this->_pos)->updateBlock(this->_pos + Vector3<double>(1,0,0),
//        this->_dim->getChunk(this->_pos)->getBlock(this->_pos + Vector3<double>(1,0,0))); // pushed block
//    this->_dim->getSection(this->_pos + Vector3<double>(1,0,0))->updateBlock(this->_pos, 34); // piston head
    this->_extended = true;
    // TODO make extend noise (864)
}

Piston::Piston(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing, bool ext, bool bud):
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