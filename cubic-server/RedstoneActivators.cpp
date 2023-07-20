#include "Redstone.hpp"

using namespace Redsone::Activators;

void Button::deactivate(void) {
    // TODO retract power
    this->_activated = false;
    if (this->_material.find("_wood") != std::string::npos)
        ;// TODO make activation noise (1272)
    else // stone
        ;// TODO make activation noise (1106)
}
void Button::activate(void) {
    // TODO deliver power level 15 to attached and adjacent blocks
    // note: a powered button is equivalent to having:
    //       a redstone block in lieu of the button + a redstone block in lieu of the attached block
    // don't forget to check orientation
    this->_activated = true;
    // TODO start tick clock
    if (this->_material.find("_wood") != std::string::npos)
        ;// TODO make activation noise (1273)
    else // stone
        ;// TODO make activation noise (1107)
    // TODO when clock reaches _duration, launch deactivation
}

Button::Button(std::string material):
    Lever(),
    _material(material),
    _duration(_material.find("stone") != std::string::npos ? 10 : 15) // ticks
{}
Button::~Button(void) {}

void Lever::deactivate(void) {
    // TODO retract power
    this->_activated = false;
    // TODO make deactivation noise (591)
}
void Lever::activate(void) {
    // TODO deliver power level 15 to attached and adjacent blocks
    this->_activated = true;
    // TODO make activation noise (591)
}
Lever::Lever(void):
    _activated(false)
{
    // TODO deliver power level 15 to attached and adjacent blocks
}
Lever::~Lever(void) {}