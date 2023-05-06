#include "AcaciaDoor.hpp"
namespace Blocks {
    namespace AcaciaDoor {
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
                                return 11467;
                            case Properties::Powered::FALSE:
                                return 11468;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11469;
                            case Properties::Powered::FALSE:
                                return 11470;
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
                                return 11471;
                            case Properties::Powered::FALSE:
                                return 11472;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11473;
                            case Properties::Powered::FALSE:
                                return 11474;
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
                                return 11475;
                            case Properties::Powered::FALSE:
                                return 11476;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11477;
                            case Properties::Powered::FALSE:
                                return 11478;
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
                                return 11479;
                            case Properties::Powered::FALSE:
                                return 11480;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11481;
                            case Properties::Powered::FALSE:
                                return 11482;
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
                                return 11483;
                            case Properties::Powered::FALSE:
                                return 11484;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11485;
                            case Properties::Powered::FALSE:
                                return 11486;
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
                                return 11487;
                            case Properties::Powered::FALSE:
                                return 11488;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11489;
                            case Properties::Powered::FALSE:
                                return 11490;
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
                                return 11491;
                            case Properties::Powered::FALSE:
                                return 11492;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11493;
                            case Properties::Powered::FALSE:
                                return 11494;
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
                                return 11495;
                            case Properties::Powered::FALSE:
                                return 11496;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11497;
                            case Properties::Powered::FALSE:
                                return 11498;
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
                                return 11499;
                            case Properties::Powered::FALSE:
                                return 11500;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11501;
                            case Properties::Powered::FALSE:
                                return 11502;
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
                                return 11503;
                            case Properties::Powered::FALSE:
                                return 11504;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11505;
                            case Properties::Powered::FALSE:
                                return 11506;
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
                                return 11507;
                            case Properties::Powered::FALSE:
                                return 11508;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11509;
                            case Properties::Powered::FALSE:
                                return 11510;
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
                                return 11511;
                            case Properties::Powered::FALSE:
                                return 11512;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11513;
                            case Properties::Powered::FALSE:
                                return 11514;
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
                                return 11515;
                            case Properties::Powered::FALSE:
                                return 11516;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11517;
                            case Properties::Powered::FALSE:
                                return 11518;
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
                                return 11519;
                            case Properties::Powered::FALSE:
                                return 11520;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11521;
                            case Properties::Powered::FALSE:
                                return 11522;
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
                                return 11523;
                            case Properties::Powered::FALSE:
                                return 11524;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11525;
                            case Properties::Powered::FALSE:
                                return 11526;
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
                                return 11527;
                            case Properties::Powered::FALSE:
                                return 11528;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11529;
                            case Properties::Powered::FALSE:
                                return 11530;
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
