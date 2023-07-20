#include "Redstone.hpp"

using namespace Redstone;

Lever::Lever(void)
{
    // TODO deliver power level 15 to attached and adjacent blocks
}
Lever::~Lever(void) {}

Button::Button(std::string material):
    _duration(material.find("stone") != std::string::npos ? 10 : 15); // ticks
{
    // TODO deliver power level 15 to attached and adjacent blocks
    // note: a powered button is equivalent to having:
    //       a redstone block in the button block + a redstone block in lieu of the attached block
}
Button::~Button(void) {}