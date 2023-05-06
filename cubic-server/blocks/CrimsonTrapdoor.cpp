#include "CrimsonTrapdoor.hpp"
namespace Blocks {
    namespace CrimsonTrapdoor {
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
                                return 18120;
                            case Properties::Waterlogged::FALSE:
                                return 18121;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18122;
                            case Properties::Waterlogged::FALSE:
                                return 18123;
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
                                return 18124;
                            case Properties::Waterlogged::FALSE:
                                return 18125;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18126;
                            case Properties::Waterlogged::FALSE:
                                return 18127;
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
                                return 18128;
                            case Properties::Waterlogged::FALSE:
                                return 18129;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18130;
                            case Properties::Waterlogged::FALSE:
                                return 18131;
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
                                return 18132;
                            case Properties::Waterlogged::FALSE:
                                return 18133;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18134;
                            case Properties::Waterlogged::FALSE:
                                return 18135;
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
                                return 18136;
                            case Properties::Waterlogged::FALSE:
                                return 18137;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18138;
                            case Properties::Waterlogged::FALSE:
                                return 18139;
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
                                return 18140;
                            case Properties::Waterlogged::FALSE:
                                return 18141;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18142;
                            case Properties::Waterlogged::FALSE:
                                return 18143;
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
                                return 18144;
                            case Properties::Waterlogged::FALSE:
                                return 18145;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18146;
                            case Properties::Waterlogged::FALSE:
                                return 18147;
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
                                return 18148;
                            case Properties::Waterlogged::FALSE:
                                return 18149;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18150;
                            case Properties::Waterlogged::FALSE:
                                return 18151;
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
                                return 18152;
                            case Properties::Waterlogged::FALSE:
                                return 18153;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18154;
                            case Properties::Waterlogged::FALSE:
                                return 18155;
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
                                return 18156;
                            case Properties::Waterlogged::FALSE:
                                return 18157;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18158;
                            case Properties::Waterlogged::FALSE:
                                return 18159;
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
                                return 18160;
                            case Properties::Waterlogged::FALSE:
                                return 18161;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18162;
                            case Properties::Waterlogged::FALSE:
                                return 18163;
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
                                return 18164;
                            case Properties::Waterlogged::FALSE:
                                return 18165;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18166;
                            case Properties::Waterlogged::FALSE:
                                return 18167;
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
                                return 18168;
                            case Properties::Waterlogged::FALSE:
                                return 18169;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18170;
                            case Properties::Waterlogged::FALSE:
                                return 18171;
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
                                return 18172;
                            case Properties::Waterlogged::FALSE:
                                return 18173;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18174;
                            case Properties::Waterlogged::FALSE:
                                return 18175;
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
                                return 18176;
                            case Properties::Waterlogged::FALSE:
                                return 18177;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18178;
                            case Properties::Waterlogged::FALSE:
                                return 18179;
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
                                return 18180;
                            case Properties::Waterlogged::FALSE:
                                return 18181;
                            default:
                                return 0;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18182;
                            case Properties::Waterlogged::FALSE:
                                return 18183;
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
