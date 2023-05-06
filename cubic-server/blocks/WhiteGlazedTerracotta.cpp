#include "WhiteGlazedTerracotta.hpp"
namespace Blocks {
namespace WhiteGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12039;
    case Properties::Facing::SOUTH:
        return 12040;
    case Properties::Facing::WEST:
        return 12041;
    case Properties::Facing::EAST:
        return 12042;
    default:
        return 0;
    }
    return 0;
}
}

}
