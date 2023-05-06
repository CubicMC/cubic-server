#include "MangroveTrapdoor.hpp"
namespace Blocks {
namespace MangroveTrapdoor {
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
                        return 6180;
                    case Properties::Waterlogged::FALSE:
                        return 6181;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6182;
                    case Properties::Waterlogged::FALSE:
                        return 6183;
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
                        return 6184;
                    case Properties::Waterlogged::FALSE:
                        return 6185;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6186;
                    case Properties::Waterlogged::FALSE:
                        return 6187;
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
                        return 6188;
                    case Properties::Waterlogged::FALSE:
                        return 6189;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6190;
                    case Properties::Waterlogged::FALSE:
                        return 6191;
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
                        return 6192;
                    case Properties::Waterlogged::FALSE:
                        return 6193;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6194;
                    case Properties::Waterlogged::FALSE:
                        return 6195;
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
                        return 6196;
                    case Properties::Waterlogged::FALSE:
                        return 6197;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6198;
                    case Properties::Waterlogged::FALSE:
                        return 6199;
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
                        return 6200;
                    case Properties::Waterlogged::FALSE:
                        return 6201;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6202;
                    case Properties::Waterlogged::FALSE:
                        return 6203;
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
                        return 6204;
                    case Properties::Waterlogged::FALSE:
                        return 6205;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6206;
                    case Properties::Waterlogged::FALSE:
                        return 6207;
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
                        return 6208;
                    case Properties::Waterlogged::FALSE:
                        return 6209;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6210;
                    case Properties::Waterlogged::FALSE:
                        return 6211;
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
                        return 6212;
                    case Properties::Waterlogged::FALSE:
                        return 6213;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6214;
                    case Properties::Waterlogged::FALSE:
                        return 6215;
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
                        return 6216;
                    case Properties::Waterlogged::FALSE:
                        return 6217;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6218;
                    case Properties::Waterlogged::FALSE:
                        return 6219;
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
                        return 6220;
                    case Properties::Waterlogged::FALSE:
                        return 6221;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6222;
                    case Properties::Waterlogged::FALSE:
                        return 6223;
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
                        return 6224;
                    case Properties::Waterlogged::FALSE:
                        return 6225;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6226;
                    case Properties::Waterlogged::FALSE:
                        return 6227;
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
                        return 6228;
                    case Properties::Waterlogged::FALSE:
                        return 6229;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6230;
                    case Properties::Waterlogged::FALSE:
                        return 6231;
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
                        return 6232;
                    case Properties::Waterlogged::FALSE:
                        return 6233;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6234;
                    case Properties::Waterlogged::FALSE:
                        return 6235;
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
                        return 6236;
                    case Properties::Waterlogged::FALSE:
                        return 6237;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6238;
                    case Properties::Waterlogged::FALSE:
                        return 6239;
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
                        return 6240;
                    case Properties::Waterlogged::FALSE:
                        return 6241;
                    default:
                        return 0;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 6242;
                    case Properties::Waterlogged::FALSE:
                        return 6243;
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
