#include "DamagedAnvil.hpp"
namespace Blocks {
namespace DamagedAnvil {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 8719;
    case Properties::Facing::SOUTH:
        return 8720;
    case Properties::Facing::WEST:
        return 8721;
    case Properties::Facing::EAST:
        return 8722;
    default:
        return 0;
    }
    return 0;
}
}

}
