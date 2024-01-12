#include "wandering.hpp"
#include "Dimension.hpp"
#include "Server.hpp"
#include "blocks.hpp"
#include "entities/Entity.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include "world_storage/Level.hpp"

namespace ai {
Wandering::Wandering(Entity &entity):
    AI(entity)
{
}

Wandering::~Wandering() { }

bool Wandering::see() { return true; }

void Wandering::think()
{
    Vector3<double> actualPos = this->_entity.getPosition();

    int x = utility::PseudoRandomGenerator::getInstance()->generateNumber(-9, 9);
    int z = utility::PseudoRandomGenerator::getInstance()->generateNumber(-9, 9);

    Vector3<double> finalPos = {actualPos.x + x, actualPos.y, actualPos.z + z};

    if (!_entity.getDimension()->hasChunkLoaded(transformBlockPosToChunkPos(finalPos.x), transformBlockPosToChunkPos(finalPos.z)))
        return;
    if (_entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y) - 1, int(finalPos.z)}) == Blocks::Air::toProtocol() ||
        _entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y), int(finalPos.z)}) != Blocks::Air::toProtocol())
        return;

    /* DEBUG CODE
    // place a bedrock block at the final position
    // _entity.getDimension()->modifyBlock({int(finalPos.x), int(finalPos.y), int(finalPos.z)}, Blocks::Bedrock::toProtocol());

    // display some important informations
    // LINFO(Vector3<double> {finalPos.x, finalPos.y - 1, finalPos.z});
    // LINFO(GLOBAL_PALETTE.fromProtocolIdToBlock(_entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y) - 1, int(finalPos.z)})).name);
    // LINFO(_entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y) - 1, int(finalPos.z)}) == Blocks::Air::toProtocol());
    // LINFO(finalPos);
    // LINFO(GLOBAL_PALETTE.fromProtocolIdToBlock(_entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y), int(finalPos.z)})).name);
    // LINFO(_entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y), int(finalPos.z)}) != Blocks::Air::toProtocol());
    // LINFO(
    //     "total of conditions {}",
    //     _entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y) - 1, int(finalPos.z)}) == Blocks::Air::toProtocol() ||
    //         _entity.getDimension()->getBlock({int(finalPos.x), int(finalPos.y), int(finalPos.z)}) != Blocks::Air::toProtocol()
    // );
    */

    // get the straight line equation between the two points
    // m = (z2 - z1) / (x2 - x1)
    // b = z1 - mx1
    // z = mx + b
    double m = (finalPos.z - actualPos.z) / (finalPos.x - actualPos.x);
    double b = actualPos.z - m * actualPos.x;
    // get the x and z values for the next position
    auto distance = actualPos.distance(finalPos);
    for (int i = 1; i <= distance * 10; i++) {
        double x = actualPos.x + ((finalPos.x - actualPos.x) / (distance * 10)) * i;
        double z = m * x + b;
        // set the next position
        this->_path.push({x, actualPos.y, z});
    }
    this->_path.push(finalPos);
}

void Wandering::act()
{
    auto pos = _path.front();
    this->_entity.setPosition(pos, true);
    _path.pop();
}
} // namespace ai
