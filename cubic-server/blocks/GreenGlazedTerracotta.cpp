#include "GreenGlazedTerracotta.hpp"
namespace Blocks {
namespace GreenGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12091;
    case Properties::Facing::SOUTH:
        return 12092;
    case Properties::Facing::WEST:
        return 12093;
    case Properties::Facing::EAST:
        return 12094;
    default:
        return 0;
    }
    return 0;
}
}

}
