#include "Redstone.hpp"

using namespace Redstone::Activated;

void Piston::contract(void)
{
    // TODO handle event contract
    this->_extended = false;
    // TODO make contract noise (863)
}

void Piston::extend(void)
{
    if (0) // TODO extend denied = there are 15 blocks in front of the piston
        return;
    // TODO handle event extend
    this->_extended = true;
    // TODO make extend noise (864)
}

Piston::Piston(bool ext, bool bud):
    _extended(ext),
    _budded(bud)
{
    if (_extended)
        this->extend();
    if (_budded)
        ; // TODO handle event bud
}

Piston::~Piston(void) {}