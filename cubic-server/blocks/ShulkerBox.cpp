#include "ShulkerBox.hpp"
#include <stdexcept>

namespace Blocks {
namespace ShulkerBox {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 11937;
    case Properties::Facing::EAST:
        return 11938;
    case Properties::Facing::SOUTH:
        return 11939;
    case Properties::Facing::WEST:
        return 11940;
    case Properties::Facing::UP:
        return 11941;
    case Properties::Facing::DOWN:
        return 11942;
    }
    return 0;
}
}

}
