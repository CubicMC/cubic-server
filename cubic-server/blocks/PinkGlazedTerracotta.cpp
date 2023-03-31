#include "PinkGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
namespace PinkGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12063;
    case Properties::Facing::SOUTH:
        return 12064;
    case Properties::Facing::WEST:
        return 12065;
    case Properties::Facing::EAST:
        return 12066;
    }
    return 0;
}
}

}
