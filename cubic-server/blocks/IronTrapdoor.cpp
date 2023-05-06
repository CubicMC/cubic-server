#include "IronTrapdoor.hpp"
namespace Blocks {
namespace IronTrapdoor {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9922;
                    case Properties::Waterlogged::FALSE:
                        return 9923;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9924;
                    case Properties::Waterlogged::FALSE:
                        return 9925;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9926;
                    case Properties::Waterlogged::FALSE:
                        return 9927;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9928;
                    case Properties::Waterlogged::FALSE:
                        return 9929;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9930;
                    case Properties::Waterlogged::FALSE:
                        return 9931;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9932;
                    case Properties::Waterlogged::FALSE:
                        return 9933;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9934;
                    case Properties::Waterlogged::FALSE:
                        return 9935;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9936;
                    case Properties::Waterlogged::FALSE:
                        return 9937;
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
        case Properties::Half::TOP:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9938;
                    case Properties::Waterlogged::FALSE:
                        return 9939;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9940;
                    case Properties::Waterlogged::FALSE:
                        return 9941;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9942;
                    case Properties::Waterlogged::FALSE:
                        return 9943;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9944;
                    case Properties::Waterlogged::FALSE:
                        return 9945;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9946;
                    case Properties::Waterlogged::FALSE:
                        return 9947;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9948;
                    case Properties::Waterlogged::FALSE:
                        return 9949;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9950;
                    case Properties::Waterlogged::FALSE:
                        return 9951;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9952;
                    case Properties::Waterlogged::FALSE:
                        return 9953;
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
        case Properties::Half::TOP:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9954;
                    case Properties::Waterlogged::FALSE:
                        return 9955;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9956;
                    case Properties::Waterlogged::FALSE:
                        return 9957;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9958;
                    case Properties::Waterlogged::FALSE:
                        return 9959;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9960;
                    case Properties::Waterlogged::FALSE:
                        return 9961;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9962;
                    case Properties::Waterlogged::FALSE:
                        return 9963;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9964;
                    case Properties::Waterlogged::FALSE:
                        return 9965;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9966;
                    case Properties::Waterlogged::FALSE:
                        return 9967;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9968;
                    case Properties::Waterlogged::FALSE:
                        return 9969;
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
        case Properties::Half::TOP:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9970;
                    case Properties::Waterlogged::FALSE:
                        return 9971;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9972;
                    case Properties::Waterlogged::FALSE:
                        return 9973;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9974;
                    case Properties::Waterlogged::FALSE:
                        return 9975;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9976;
                    case Properties::Waterlogged::FALSE:
                        return 9977;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Half::BOTTOM:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9978;
                    case Properties::Waterlogged::FALSE:
                        return 9979;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9980;
                    case Properties::Waterlogged::FALSE:
                        return 9981;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9982;
                    case Properties::Waterlogged::FALSE:
                        return 9983;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 9984;
                    case Properties::Waterlogged::FALSE:
                        return 9985;
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
