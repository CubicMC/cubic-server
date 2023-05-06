#include "Piston.hpp"
namespace Blocks {
namespace Piston {
BlockId toProtocol(Properties::Extended extended, Properties::Facing facing)
{
    switch (extended) {
    case Properties::Extended::TRUE:
        switch (facing) {
        case Properties::Facing::NORTH:
            return 1960;
        case Properties::Facing::EAST:
            return 1961;
        case Properties::Facing::SOUTH:
            return 1962;
        case Properties::Facing::WEST:
            return 1963;
        case Properties::Facing::UP:
            return 1964;
        case Properties::Facing::DOWN:
            return 1965;
        default:
            return 0;
        }
    case Properties::Extended::FALSE:
        switch (facing) {
        case Properties::Facing::NORTH:
            return 1966;
        case Properties::Facing::EAST:
            return 1967;
        case Properties::Facing::SOUTH:
            return 1968;
        case Properties::Facing::WEST:
            return 1969;
        case Properties::Facing::UP:
            return 1970;
        case Properties::Facing::DOWN:
            return 1971;
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
