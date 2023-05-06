#include "RedGlazedTerracotta.hpp"
namespace Blocks {
namespace RedGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12095;
    case Properties::Facing::SOUTH:
        return 12096;
    case Properties::Facing::WEST:
        return 12097;
    case Properties::Facing::EAST:
        return 12098;
    default:
        return 0;
    }
    return 0;
}
}

}
