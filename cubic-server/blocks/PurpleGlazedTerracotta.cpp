#include "PurpleGlazedTerracotta.hpp"
namespace Blocks {
namespace PurpleGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12079;
    case Properties::Facing::SOUTH:
        return 12080;
    case Properties::Facing::WEST:
        return 12081;
    case Properties::Facing::EAST:
        return 12082;
    default:
        return 0;
    }
    return 0;
}
}

}
