#include "BigDripleaf.hpp"
namespace Blocks {
namespace BigDripleaf {
BlockId toProtocol(Properties::Facing facing, Properties::Tilt tilt, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (tilt) {
        case Properties::Tilt::NONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21502;
            case Properties::Waterlogged::FALSE:
                return 21503;
            default:
                return 0;
            }
        case Properties::Tilt::UNSTABLE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21504;
            case Properties::Waterlogged::FALSE:
                return 21505;
            default:
                return 0;
            }
        case Properties::Tilt::PARTIAL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21506;
            case Properties::Waterlogged::FALSE:
                return 21507;
            default:
                return 0;
            }
        case Properties::Tilt::FULL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21508;
            case Properties::Waterlogged::FALSE:
                return 21509;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (tilt) {
        case Properties::Tilt::NONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21510;
            case Properties::Waterlogged::FALSE:
                return 21511;
            default:
                return 0;
            }
        case Properties::Tilt::UNSTABLE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21512;
            case Properties::Waterlogged::FALSE:
                return 21513;
            default:
                return 0;
            }
        case Properties::Tilt::PARTIAL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21514;
            case Properties::Waterlogged::FALSE:
                return 21515;
            default:
                return 0;
            }
        case Properties::Tilt::FULL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21516;
            case Properties::Waterlogged::FALSE:
                return 21517;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (tilt) {
        case Properties::Tilt::NONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21518;
            case Properties::Waterlogged::FALSE:
                return 21519;
            default:
                return 0;
            }
        case Properties::Tilt::UNSTABLE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21520;
            case Properties::Waterlogged::FALSE:
                return 21521;
            default:
                return 0;
            }
        case Properties::Tilt::PARTIAL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21522;
            case Properties::Waterlogged::FALSE:
                return 21523;
            default:
                return 0;
            }
        case Properties::Tilt::FULL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21524;
            case Properties::Waterlogged::FALSE:
                return 21525;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (tilt) {
        case Properties::Tilt::NONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21526;
            case Properties::Waterlogged::FALSE:
                return 21527;
            default:
                return 0;
            }
        case Properties::Tilt::UNSTABLE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21528;
            case Properties::Waterlogged::FALSE:
                return 21529;
            default:
                return 0;
            }
        case Properties::Tilt::PARTIAL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21530;
            case Properties::Waterlogged::FALSE:
                return 21531;
            default:
                return 0;
            }
        case Properties::Tilt::FULL:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21532;
            case Properties::Waterlogged::FALSE:
                return 21533;
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
