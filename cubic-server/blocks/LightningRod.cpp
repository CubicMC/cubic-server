#include "LightningRod.hpp"
namespace Blocks {
    namespace LightningRod {
        BlockId toProtocol(Properties::Facing facing, Properties::Powered powered, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21398;
                    case Properties::Waterlogged::FALSE:
                        return 21399;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21400;
                    case Properties::Waterlogged::FALSE:
                        return 21401;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21402;
                    case Properties::Waterlogged::FALSE:
                        return 21403;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21404;
                    case Properties::Waterlogged::FALSE:
                        return 21405;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21406;
                    case Properties::Waterlogged::FALSE:
                        return 21407;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21408;
                    case Properties::Waterlogged::FALSE:
                        return 21409;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21410;
                    case Properties::Waterlogged::FALSE:
                        return 21411;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21412;
                    case Properties::Waterlogged::FALSE:
                        return 21413;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::UP:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21414;
                    case Properties::Waterlogged::FALSE:
                        return 21415;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21416;
                    case Properties::Waterlogged::FALSE:
                        return 21417;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::DOWN:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21418;
                    case Properties::Waterlogged::FALSE:
                        return 21419;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21420;
                    case Properties::Waterlogged::FALSE:
                        return 21421;
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
