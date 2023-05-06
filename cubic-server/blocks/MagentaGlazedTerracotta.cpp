#include "MagentaGlazedTerracotta.hpp"
namespace Blocks {
namespace MagentaGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing) {
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12047;
    case Properties::Facing::SOUTH:
        return 12048;
    case Properties::Facing::WEST:
        return 12049;
    case Properties::Facing::EAST:
        return 12050;
    default:
        return 0;
    }
    return 0;
}
}

}
