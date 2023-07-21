#include "Redstone.hpp"

using namespace Redstone::Activated;

void Piston::retract(void)
{
    // TODO handle event retract
    this->_extended = false;
    // TODO make retract noise
}

void Piston::push(void)
{
    if (0) // TODO push denied = there are 15 blocks in front of the piston
        return;
    // TODO handle event push
    this->_extended = true;
    // TODO make push noise
}

Piston::Piston(bool ext, bool bud):
    _extended(ext),
    _budded(bud)
{
    if (_extended)
        this->push();
    // TODO make noise upon activation
}

Piston::~Piston(void) {}