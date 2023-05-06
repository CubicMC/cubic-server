#include "SpruceDoor.hpp"
namespace Blocks {
namespace SpruceDoor {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11275;
                    case Properties::Powered::FALSE:
                        return 11276;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11277;
                    case Properties::Powered::FALSE:
                        return 11278;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11279;
                    case Properties::Powered::FALSE:
                        return 11280;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11281;
                    case Properties::Powered::FALSE:
                        return 11282;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11283;
                    case Properties::Powered::FALSE:
                        return 11284;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11285;
                    case Properties::Powered::FALSE:
                        return 11286;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11287;
                    case Properties::Powered::FALSE:
                        return 11288;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11289;
                    case Properties::Powered::FALSE:
                        return 11290;
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
    case Properties::Facing::SOUTH:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11291;
                    case Properties::Powered::FALSE:
                        return 11292;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11293;
                    case Properties::Powered::FALSE:
                        return 11294;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11295;
                    case Properties::Powered::FALSE:
                        return 11296;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11297;
                    case Properties::Powered::FALSE:
                        return 11298;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11299;
                    case Properties::Powered::FALSE:
                        return 11300;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11301;
                    case Properties::Powered::FALSE:
                        return 11302;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11303;
                    case Properties::Powered::FALSE:
                        return 11304;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11305;
                    case Properties::Powered::FALSE:
                        return 11306;
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
    case Properties::Facing::WEST:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11307;
                    case Properties::Powered::FALSE:
                        return 11308;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11309;
                    case Properties::Powered::FALSE:
                        return 11310;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11311;
                    case Properties::Powered::FALSE:
                        return 11312;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11313;
                    case Properties::Powered::FALSE:
                        return 11314;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11315;
                    case Properties::Powered::FALSE:
                        return 11316;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11317;
                    case Properties::Powered::FALSE:
                        return 11318;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11319;
                    case Properties::Powered::FALSE:
                        return 11320;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11321;
                    case Properties::Powered::FALSE:
                        return 11322;
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
    case Properties::Facing::EAST:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11323;
                    case Properties::Powered::FALSE:
                        return 11324;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11325;
                    case Properties::Powered::FALSE:
                        return 11326;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11327;
                    case Properties::Powered::FALSE:
                        return 11328;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11329;
                    case Properties::Powered::FALSE:
                        return 11330;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11331;
                    case Properties::Powered::FALSE:
                        return 11332;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11333;
                    case Properties::Powered::FALSE:
                        return 11334;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11335;
                    case Properties::Powered::FALSE:
                        return 11336;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11337;
                    case Properties::Powered::FALSE:
                        return 11338;
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
    default:
        return 0;
    }
    return 0;
}
}

}
