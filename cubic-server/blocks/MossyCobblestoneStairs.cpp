#include "MossyCobblestoneStairs.hpp"
namespace Blocks {
namespace MossyCobblestoneStairs {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12654;
                case Properties::Waterlogged::FALSE:
                    return 12655;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12656;
                case Properties::Waterlogged::FALSE:
                    return 12657;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12658;
                case Properties::Waterlogged::FALSE:
                    return 12659;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12660;
                case Properties::Waterlogged::FALSE:
                    return 12661;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12662;
                case Properties::Waterlogged::FALSE:
                    return 12663;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12664;
                case Properties::Waterlogged::FALSE:
                    return 12665;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12666;
                case Properties::Waterlogged::FALSE:
                    return 12667;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12668;
                case Properties::Waterlogged::FALSE:
                    return 12669;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12670;
                case Properties::Waterlogged::FALSE:
                    return 12671;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12672;
                case Properties::Waterlogged::FALSE:
                    return 12673;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12674;
                case Properties::Waterlogged::FALSE:
                    return 12675;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12676;
                case Properties::Waterlogged::FALSE:
                    return 12677;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12678;
                case Properties::Waterlogged::FALSE:
                    return 12679;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12680;
                case Properties::Waterlogged::FALSE:
                    return 12681;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12682;
                case Properties::Waterlogged::FALSE:
                    return 12683;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12684;
                case Properties::Waterlogged::FALSE:
                    return 12685;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12686;
                case Properties::Waterlogged::FALSE:
                    return 12687;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12688;
                case Properties::Waterlogged::FALSE:
                    return 12689;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12690;
                case Properties::Waterlogged::FALSE:
                    return 12691;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12692;
                case Properties::Waterlogged::FALSE:
                    return 12693;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12694;
                case Properties::Waterlogged::FALSE:
                    return 12695;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12696;
                case Properties::Waterlogged::FALSE:
                    return 12697;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12698;
                case Properties::Waterlogged::FALSE:
                    return 12699;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12700;
                case Properties::Waterlogged::FALSE:
                    return 12701;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12702;
                case Properties::Waterlogged::FALSE:
                    return 12703;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12704;
                case Properties::Waterlogged::FALSE:
                    return 12705;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12706;
                case Properties::Waterlogged::FALSE:
                    return 12707;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12708;
                case Properties::Waterlogged::FALSE:
                    return 12709;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12710;
                case Properties::Waterlogged::FALSE:
                    return 12711;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12712;
                case Properties::Waterlogged::FALSE:
                    return 12713;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12714;
                case Properties::Waterlogged::FALSE:
                    return 12715;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12716;
                case Properties::Waterlogged::FALSE:
                    return 12717;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12718;
                case Properties::Waterlogged::FALSE:
                    return 12719;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12720;
                case Properties::Waterlogged::FALSE:
                    return 12721;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12722;
                case Properties::Waterlogged::FALSE:
                    return 12723;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12724;
                case Properties::Waterlogged::FALSE:
                    return 12725;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12726;
                case Properties::Waterlogged::FALSE:
                    return 12727;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12728;
                case Properties::Waterlogged::FALSE:
                    return 12729;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12730;
                case Properties::Waterlogged::FALSE:
                    return 12731;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12732;
                case Properties::Waterlogged::FALSE:
                    return 12733;
                default:
                    return 0;
                }
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
