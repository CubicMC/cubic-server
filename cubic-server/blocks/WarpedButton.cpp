#include "WarpedButton.hpp"
namespace Blocks {
    namespace WarpedButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18496;
                    case Properties::Powered::FALSE:
                        return 18497;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18498;
                    case Properties::Powered::FALSE:
                        return 18499;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18500;
                    case Properties::Powered::FALSE:
                        return 18501;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18502;
                    case Properties::Powered::FALSE:
                        return 18503;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18504;
                    case Properties::Powered::FALSE:
                        return 18505;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18506;
                    case Properties::Powered::FALSE:
                        return 18507;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18508;
                    case Properties::Powered::FALSE:
                        return 18509;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18510;
                    case Properties::Powered::FALSE:
                        return 18511;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18512;
                    case Properties::Powered::FALSE:
                        return 18513;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18514;
                    case Properties::Powered::FALSE:
                        return 18515;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18516;
                    case Properties::Powered::FALSE:
                        return 18517;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18518;
                    case Properties::Powered::FALSE:
                        return 18519;
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
