#include "BlackGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
namespace BlackGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12099;
    case Properties::Facing::SOUTH:
        return 12100;
    case Properties::Facing::WEST:
        return 12101;
    case Properties::Facing::EAST:
        return 12102;
    }
    return 0;
}
}

}
