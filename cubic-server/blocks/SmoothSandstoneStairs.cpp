#include "SmoothSandstoneStairs.hpp"
namespace Blocks {
namespace SmoothSandstoneStairs {
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
                    return 12894;
                case Properties::Waterlogged::FALSE:
                    return 12895;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12896;
                case Properties::Waterlogged::FALSE:
                    return 12897;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12898;
                case Properties::Waterlogged::FALSE:
                    return 12899;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12900;
                case Properties::Waterlogged::FALSE:
                    return 12901;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12902;
                case Properties::Waterlogged::FALSE:
                    return 12903;
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
                    return 12904;
                case Properties::Waterlogged::FALSE:
                    return 12905;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12906;
                case Properties::Waterlogged::FALSE:
                    return 12907;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12908;
                case Properties::Waterlogged::FALSE:
                    return 12909;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12910;
                case Properties::Waterlogged::FALSE:
                    return 12911;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12912;
                case Properties::Waterlogged::FALSE:
                    return 12913;
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
                    return 12914;
                case Properties::Waterlogged::FALSE:
                    return 12915;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12916;
                case Properties::Waterlogged::FALSE:
                    return 12917;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12918;
                case Properties::Waterlogged::FALSE:
                    return 12919;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12920;
                case Properties::Waterlogged::FALSE:
                    return 12921;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12922;
                case Properties::Waterlogged::FALSE:
                    return 12923;
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
                    return 12924;
                case Properties::Waterlogged::FALSE:
                    return 12925;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12926;
                case Properties::Waterlogged::FALSE:
                    return 12927;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12928;
                case Properties::Waterlogged::FALSE:
                    return 12929;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12930;
                case Properties::Waterlogged::FALSE:
                    return 12931;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12932;
                case Properties::Waterlogged::FALSE:
                    return 12933;
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
                    return 12934;
                case Properties::Waterlogged::FALSE:
                    return 12935;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12936;
                case Properties::Waterlogged::FALSE:
                    return 12937;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12938;
                case Properties::Waterlogged::FALSE:
                    return 12939;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12940;
                case Properties::Waterlogged::FALSE:
                    return 12941;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12942;
                case Properties::Waterlogged::FALSE:
                    return 12943;
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
                    return 12944;
                case Properties::Waterlogged::FALSE:
                    return 12945;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12946;
                case Properties::Waterlogged::FALSE:
                    return 12947;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12948;
                case Properties::Waterlogged::FALSE:
                    return 12949;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12950;
                case Properties::Waterlogged::FALSE:
                    return 12951;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12952;
                case Properties::Waterlogged::FALSE:
                    return 12953;
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
                    return 12954;
                case Properties::Waterlogged::FALSE:
                    return 12955;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12956;
                case Properties::Waterlogged::FALSE:
                    return 12957;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12958;
                case Properties::Waterlogged::FALSE:
                    return 12959;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12960;
                case Properties::Waterlogged::FALSE:
                    return 12961;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12962;
                case Properties::Waterlogged::FALSE:
                    return 12963;
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
                    return 12964;
                case Properties::Waterlogged::FALSE:
                    return 12965;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12966;
                case Properties::Waterlogged::FALSE:
                    return 12967;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12968;
                case Properties::Waterlogged::FALSE:
                    return 12969;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12970;
                case Properties::Waterlogged::FALSE:
                    return 12971;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12972;
                case Properties::Waterlogged::FALSE:
                    return 12973;
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
