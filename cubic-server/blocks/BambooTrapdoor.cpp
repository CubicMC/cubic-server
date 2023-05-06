#include "BambooTrapdoor.hpp"
namespace Blocks {
    namespace BambooTrapdoor {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
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
                                return 6244;
                            case Properties::Waterlogged::FALSE:
                                return 6245;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6246;
                            case Properties::Waterlogged::FALSE:
                                return 6247;
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
                                return 6248;
                            case Properties::Waterlogged::FALSE:
                                return 6249;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6250;
                            case Properties::Waterlogged::FALSE:
                                return 6251;
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
                                return 6252;
                            case Properties::Waterlogged::FALSE:
                                return 6253;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6254;
                            case Properties::Waterlogged::FALSE:
                                return 6255;
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
                                return 6256;
                            case Properties::Waterlogged::FALSE:
                                return 6257;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6258;
                            case Properties::Waterlogged::FALSE:
                                return 6259;
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
                                return 6260;
                            case Properties::Waterlogged::FALSE:
                                return 6261;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6262;
                            case Properties::Waterlogged::FALSE:
                                return 6263;
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
                                return 6264;
                            case Properties::Waterlogged::FALSE:
                                return 6265;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6266;
                            case Properties::Waterlogged::FALSE:
                                return 6267;
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
                                return 6268;
                            case Properties::Waterlogged::FALSE:
                                return 6269;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6270;
                            case Properties::Waterlogged::FALSE:
                                return 6271;
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
                                return 6272;
                            case Properties::Waterlogged::FALSE:
                                return 6273;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6274;
                            case Properties::Waterlogged::FALSE:
                                return 6275;
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
                                return 6276;
                            case Properties::Waterlogged::FALSE:
                                return 6277;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6278;
                            case Properties::Waterlogged::FALSE:
                                return 6279;
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
                                return 6280;
                            case Properties::Waterlogged::FALSE:
                                return 6281;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6282;
                            case Properties::Waterlogged::FALSE:
                                return 6283;
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
                                return 6284;
                            case Properties::Waterlogged::FALSE:
                                return 6285;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6286;
                            case Properties::Waterlogged::FALSE:
                                return 6287;
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
                                return 6288;
                            case Properties::Waterlogged::FALSE:
                                return 6289;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6290;
                            case Properties::Waterlogged::FALSE:
                                return 6291;
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
                                return 6292;
                            case Properties::Waterlogged::FALSE:
                                return 6293;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6294;
                            case Properties::Waterlogged::FALSE:
                                return 6295;
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
                                return 6296;
                            case Properties::Waterlogged::FALSE:
                                return 6297;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6298;
                            case Properties::Waterlogged::FALSE:
                                return 6299;
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
                                return 6300;
                            case Properties::Waterlogged::FALSE:
                                return 6301;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6302;
                            case Properties::Waterlogged::FALSE:
                                return 6303;
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
                                return 6304;
                            case Properties::Waterlogged::FALSE:
                                return 6305;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 6306;
                            case Properties::Waterlogged::FALSE:
                                return 6307;
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
