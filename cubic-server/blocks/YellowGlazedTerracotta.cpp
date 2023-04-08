#include "YellowGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
namespace YellowGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12055;
    case Properties::Facing::SOUTH:
        return 12056;
    case Properties::Facing::WEST:
        return 12057;
    case Properties::Facing::EAST:
        return 12058;
    }
    return 0;
}
}

}
