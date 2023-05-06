#include "BigDripleafStem.hpp"
namespace Blocks {
namespace BigDripleafStem {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21534;
        case Properties::Waterlogged::FALSE:
            return 21535;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21536;
        case Properties::Waterlogged::FALSE:
            return 21537;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21538;
        case Properties::Waterlogged::FALSE:
            return 21539;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21540;
        case Properties::Waterlogged::FALSE:
            return 21541;
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
