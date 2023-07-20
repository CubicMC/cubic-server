#include "Redstone.hpp"

using namespace Redstone;

Button::Button(std::string material):
    _duration(material.find("stone") != std::string::npos ? 10 : 15); // ticks
{
    // TODO deliver power level 15 to attached and adjacent blocks
}