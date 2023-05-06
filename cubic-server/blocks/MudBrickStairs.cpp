#include "MudBrickStairs.hpp"
namespace Blocks {
namespace MudBrickStairs {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6959;
                case Properties::Waterlogged::FALSE:
                    return 6960;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6961;
                case Properties::Waterlogged::FALSE:
                    return 6962;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6963;
                case Properties::Waterlogged::FALSE:
                    return 6964;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6965;
                case Properties::Waterlogged::FALSE:
                    return 6966;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6967;
                case Properties::Waterlogged::FALSE:
                    return 6968;
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
                    return 6969;
                case Properties::Waterlogged::FALSE:
                    return 6970;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6971;
                case Properties::Waterlogged::FALSE:
                    return 6972;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6973;
                case Properties::Waterlogged::FALSE:
                    return 6974;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6975;
                case Properties::Waterlogged::FALSE:
                    return 6976;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6977;
                case Properties::Waterlogged::FALSE:
                    return 6978;
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
                    return 6979;
                case Properties::Waterlogged::FALSE:
                    return 6980;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6981;
                case Properties::Waterlogged::FALSE:
                    return 6982;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6983;
                case Properties::Waterlogged::FALSE:
                    return 6984;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6985;
                case Properties::Waterlogged::FALSE:
                    return 6986;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6987;
                case Properties::Waterlogged::FALSE:
                    return 6988;
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
                    return 6989;
                case Properties::Waterlogged::FALSE:
                    return 6990;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6991;
                case Properties::Waterlogged::FALSE:
                    return 6992;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6993;
                case Properties::Waterlogged::FALSE:
                    return 6994;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6995;
                case Properties::Waterlogged::FALSE:
                    return 6996;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 6997;
                case Properties::Waterlogged::FALSE:
                    return 6998;
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
                    return 6999;
                case Properties::Waterlogged::FALSE:
                    return 7000;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7001;
                case Properties::Waterlogged::FALSE:
                    return 7002;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7003;
                case Properties::Waterlogged::FALSE:
                    return 7004;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7005;
                case Properties::Waterlogged::FALSE:
                    return 7006;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7007;
                case Properties::Waterlogged::FALSE:
                    return 7008;
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
                    return 7009;
                case Properties::Waterlogged::FALSE:
                    return 7010;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7011;
                case Properties::Waterlogged::FALSE:
                    return 7012;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7013;
                case Properties::Waterlogged::FALSE:
                    return 7014;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7015;
                case Properties::Waterlogged::FALSE:
                    return 7016;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7017;
                case Properties::Waterlogged::FALSE:
                    return 7018;
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
                    return 7019;
                case Properties::Waterlogged::FALSE:
                    return 7020;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7021;
                case Properties::Waterlogged::FALSE:
                    return 7022;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7023;
                case Properties::Waterlogged::FALSE:
                    return 7024;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7025;
                case Properties::Waterlogged::FALSE:
                    return 7026;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7027;
                case Properties::Waterlogged::FALSE:
                    return 7028;
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
                    return 7029;
                case Properties::Waterlogged::FALSE:
                    return 7030;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7031;
                case Properties::Waterlogged::FALSE:
                    return 7032;
                default:
                    return 0;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7033;
                case Properties::Waterlogged::FALSE:
                    return 7034;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7035;
                case Properties::Waterlogged::FALSE:
                    return 7036;
                default:
                    return 0;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7037;
                case Properties::Waterlogged::FALSE:
                    return 7038;
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
