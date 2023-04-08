#include "AttachedMelonStem.hpp"
#include <stdexcept>

namespace Blocks {
namespace AttachedMelonStem {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 6587;
    case Properties::Facing::SOUTH:
        return 6588;
    case Properties::Facing::WEST:
        return 6589;
    case Properties::Facing::EAST:
        return 6590;
    }
    return 0;
}
}

}
