#include "wandering.hpp"
#include "entities/Entity.hpp"
#include "math/Vector3.hpp"
#include "logging/logging.hpp"

namespace ai {
Wandering::Wandering(Entity &entity):
    AI(entity)
{
}

Wandering::~Wandering() { }

bool Wandering::see() { return true; }

void Wandering::think()
{
    Vector3<double> pos = this->_entity.getPosition();
    Vector3<double> finalPos = {pos.x + 1, pos.y, pos.z - 1};
    // get the straight line equation between the two points
    // z = mx + b
    // m = (z2 - z1) / (x2 - x1)
    // b = z1 - mx1
    double m = (finalPos.z - pos.z) / (finalPos.x - pos.x);
    double b = pos.z - m * pos.x;
    // get the x and z values for the next position
    for (int i = 1; i <= 40; i++) {
        double x = pos.x + i/40.0;
        double z = m * x + b;
        // set the next position
        this->_path.push({x, pos.y, z});
    }
}

void Wandering::act()
{
    auto pos = _path.front();
    this->_entity.setPosition(pos, true);
    _path.pop();
}
} // namespace ai
