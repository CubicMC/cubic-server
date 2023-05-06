#include "SmallDripleaf.hpp"
namespace Blocks {
namespace SmallDripleaf {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::UPPER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21542;
            case Properties::Waterlogged::FALSE:
                return 21543;
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21544;
            case Properties::Waterlogged::FALSE:
                return 21545;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (half) {
        case Properties::Half::UPPER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21546;
            case Properties::Waterlogged::FALSE:
                return 21547;
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21548;
            case Properties::Waterlogged::FALSE:
                return 21549;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (half) {
        case Properties::Half::UPPER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21550;
            case Properties::Waterlogged::FALSE:
                return 21551;
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21552;
            case Properties::Waterlogged::FALSE:
                return 21553;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (half) {
        case Properties::Half::UPPER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21554;
            case Properties::Waterlogged::FALSE:
                return 21555;
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21556;
            case Properties::Waterlogged::FALSE:
                return 21557;
            default:
                return 0;
            }
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
