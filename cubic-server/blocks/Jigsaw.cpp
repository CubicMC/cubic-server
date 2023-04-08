#include "Jigsaw.hpp"
#include <stdexcept>

namespace Blocks {
namespace Jigsaw {
BlockId toProtocol(Properties::Orientation orientation)
{
    switch (orientation) {
    case Properties::Orientation::DOWN_EAST:
        return 18732;
    case Properties::Orientation::DOWN_NORTH:
        return 18733;
    case Properties::Orientation::DOWN_SOUTH:
        return 18734;
    case Properties::Orientation::DOWN_WEST:
        return 18735;
    case Properties::Orientation::UP_EAST:
        return 18736;
    case Properties::Orientation::UP_NORTH:
        return 18737;
    case Properties::Orientation::UP_SOUTH:
        return 18738;
    case Properties::Orientation::UP_WEST:
        return 18739;
    case Properties::Orientation::WEST_UP:
        return 18740;
    case Properties::Orientation::EAST_UP:
        return 18741;
    case Properties::Orientation::NORTH_UP:
        return 18742;
    case Properties::Orientation::SOUTH_UP:
        return 18743;
    }
    return 0;
}
}

}
