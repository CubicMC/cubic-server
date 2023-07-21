#include "Redstone.hpp"

using namespace Redstone::Activators;

/**************** BUTTON *****************/

void Button::deactivate(void) {
    // TODO retract power
    this->_powered = false;
    if (this->_isWooden)
        ;// TODO make activation noise (1272)
    else // stone
        ;// TODO make activation noise (1106)
}

void Button::activate(void) {
    // TODO deliver power level 15 to attached and adjacent blocks
    // note: a powered button is equivalent to having:
    //       a redstone block in lieu of the button + a redstone block in lieu of the attached block
    // don't forget to check orientation
    this->_powered = true;
    // TODO start tick clock
    if (this->_isWooden)
        ;// TODO make activation noise (1273)
    else // stone
        ;// TODO make activation noise (1107)
    // TODO when clock reaches _duration, launch deactivation
}

Button::Button(bool isWooden):
    Lever(),
    _isWooden(isWooden),
    _duration(isWooden ? 15 : 10) // ticks
{}
Button::~Button(void) {}

/***************** LEVER *****************/

void Lever::deactivate(void) {
    // TODO retract power
    this->_powered = false;
    // TODO make deactivation noise (591)
}

void Lever::activate(void) {
    // TODO deliver power level 15 to attached and adjacent blocks
    this->_powered = true;
    // TODO make activation noise (591)
}

Lever::Lever(void):
    _powered(false)
{
    // TODO deliver power level 15 to attached and adjacent blocks
}
Lever::~Lever(void) {}

using namespace Redstone;

RedstoneCircuit::RedstoneCircuit(void) {}
RedstoneCircuit::~RedstoneCircuit(void) {}