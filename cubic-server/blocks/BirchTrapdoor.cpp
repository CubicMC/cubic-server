#include "BirchTrapdoor.hpp"
namespace Blocks {
namespace BirchTrapdoor {
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
                        return 5924;
                    case Properties::Waterlogged::FALSE:
                        return 5925;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5926;
                    case Properties::Waterlogged::FALSE:
                        return 5927;
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
                        return 5928;
                    case Properties::Waterlogged::FALSE:
                        return 5929;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5930;
                    case Properties::Waterlogged::FALSE:
                        return 5931;
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
                        return 5932;
                    case Properties::Waterlogged::FALSE:
                        return 5933;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5934;
                    case Properties::Waterlogged::FALSE:
                        return 5935;
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
                        return 5936;
                    case Properties::Waterlogged::FALSE:
                        return 5937;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5938;
                    case Properties::Waterlogged::FALSE:
                        return 5939;
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
                        return 5940;
                    case Properties::Waterlogged::FALSE:
                        return 5941;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5942;
                    case Properties::Waterlogged::FALSE:
                        return 5943;
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
                        return 5944;
                    case Properties::Waterlogged::FALSE:
                        return 5945;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5946;
                    case Properties::Waterlogged::FALSE:
                        return 5947;
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
                        return 5948;
                    case Properties::Waterlogged::FALSE:
                        return 5949;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5950;
                    case Properties::Waterlogged::FALSE:
                        return 5951;
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
                        return 5952;
                    case Properties::Waterlogged::FALSE:
                        return 5953;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5954;
                    case Properties::Waterlogged::FALSE:
                        return 5955;
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
                        return 5956;
                    case Properties::Waterlogged::FALSE:
                        return 5957;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5958;
                    case Properties::Waterlogged::FALSE:
                        return 5959;
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
                        return 5960;
                    case Properties::Waterlogged::FALSE:
                        return 5961;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5962;
                    case Properties::Waterlogged::FALSE:
                        return 5963;
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
                        return 5964;
                    case Properties::Waterlogged::FALSE:
                        return 5965;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5966;
                    case Properties::Waterlogged::FALSE:
                        return 5967;
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
                        return 5968;
                    case Properties::Waterlogged::FALSE:
                        return 5969;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5970;
                    case Properties::Waterlogged::FALSE:
                        return 5971;
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
                        return 5972;
                    case Properties::Waterlogged::FALSE:
                        return 5973;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5974;
                    case Properties::Waterlogged::FALSE:
                        return 5975;
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
                        return 5976;
                    case Properties::Waterlogged::FALSE:
                        return 5977;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5978;
                    case Properties::Waterlogged::FALSE:
                        return 5979;
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
                        return 5980;
                    case Properties::Waterlogged::FALSE:
                        return 5981;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5982;
                    case Properties::Waterlogged::FALSE:
                        return 5983;
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
                        return 5984;
                    case Properties::Waterlogged::FALSE:
                        return 5985;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5986;
                    case Properties::Waterlogged::FALSE:
                        return 5987;
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
