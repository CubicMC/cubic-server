#include "Redstone.hpp"

using namespace Redstone::Activators;

/**************** BUTTON *****************/

void Button::unpress(void) {
    // this->_dim->getBlock(this->_pos)->power(0);
    this->_powered = false;
    if (this->_isWooden)
        ;// TODO make activation noise (1272)
    else // stone
        ;// TODO make activation noise (1106)
}

void Button::press(void) {
    // TODO awaiting BlockId::power();
    // note: a powered button is equivalent to having:
    //       a redstone block in lieu of the button + a redstone block in lieu of the attached block
    if (this->_facing == Facing::Ceiling)
        ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, 1, 0))->power(15);
    else if (this->_facing == Facing::Floor)
        ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, -1, 0))->power(15);
    else { // wall
        if (this->_facing == Facing::North)
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(1, 0, 0))->power(15);
        else if (this->_facing == Facing::South)
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(-1, 0, 0))->power(15);
        else if (this->_facing == Facing::West)
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, 0, 1))->power(15);
        else // east
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, 0, -1))->power(15);
    }
    // this->_dim->getBlock(this->_pos)->power(15);
    this->_powered = true;
    this->_clock.start();
    if (this->_isWooden)
        ;// TODO make activation noise (1273)
    else // stone
        ;// TODO make activation noise (1107)
    if (this->_clock.getTick() == this->_duration) {
        this->unpress();
        this->_clock.stop();
    }
}

Button::Button(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing, bool isWooden):
    Lever(dim, pos, facing),
    _isWooden(isWooden),
    _duration(isWooden ? 15 : 10) // ticks
{}
Button::~Button(void) {}

/***************** LEVER *****************/

void Lever::unpress(void) {
    // TODO retract power
    this->_powered = false;
    // TODO make deactivation noise (591)
}

void Lever::press(void) {
    // TODO deliver power level 15 to attached and adjacent blocks
    this->_powered = true;
    // TODO make activation noise (591)
}

Lever::Lever(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing):
    _dim(dim),
    _pos(pos),
    _facing(facing),
    _powered(false)
{
    // TODO deliver power level 15 to attached and adjacent blocks
}
Lever::~Lever(void) {}

/*************** CIRCUITRY ***************/

using namespace Redstone;

RedstoneCircuit::RedstoneCircuit(void) {}
RedstoneCircuit::~RedstoneCircuit(void) {}