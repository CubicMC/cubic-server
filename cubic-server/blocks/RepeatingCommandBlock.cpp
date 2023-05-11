#include "RepeatingCommandBlock.hpp"
namespace Blocks {
namespace RepeatingCommandBlock {
BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing)
{
    switch (conditional) {
    case Properties::Conditional::TRUE:
        switch (facing) {
        case Properties::Facing::NORTH:
            return 11890;
        case Properties::Facing::EAST:
            return 11891;
        case Properties::Facing::SOUTH:
            return 11892;
        case Properties::Facing::WEST:
            return 11893;
        case Properties::Facing::UP:
            return 11894;
        case Properties::Facing::DOWN:
            return 11895;
        default:
            return 0;
        }
    case Properties::Conditional::FALSE:
        switch (facing) {
        case Properties::Facing::NORTH:
            return 11896;
        case Properties::Facing::EAST:
            return 11897;
        case Properties::Facing::SOUTH:
            return 11898;
        case Properties::Facing::WEST:
            return 11899;
        case Properties::Facing::UP:
            return 11900;
        case Properties::Facing::DOWN:
            return 11901;
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
