#include "BambooDoor.hpp"
namespace Blocks {
namespace BambooDoor {
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
                        return 11659;
                    case Properties::Powered::FALSE:
                        return 11660;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11661;
                    case Properties::Powered::FALSE:
                        return 11662;
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
                        return 11663;
                    case Properties::Powered::FALSE:
                        return 11664;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11665;
                    case Properties::Powered::FALSE:
                        return 11666;
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
                        return 11667;
                    case Properties::Powered::FALSE:
                        return 11668;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11669;
                    case Properties::Powered::FALSE:
                        return 11670;
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
                        return 11671;
                    case Properties::Powered::FALSE:
                        return 11672;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11673;
                    case Properties::Powered::FALSE:
                        return 11674;
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
                        return 11675;
                    case Properties::Powered::FALSE:
                        return 11676;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11677;
                    case Properties::Powered::FALSE:
                        return 11678;
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
                        return 11679;
                    case Properties::Powered::FALSE:
                        return 11680;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11681;
                    case Properties::Powered::FALSE:
                        return 11682;
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
                        return 11683;
                    case Properties::Powered::FALSE:
                        return 11684;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11685;
                    case Properties::Powered::FALSE:
                        return 11686;
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
                        return 11687;
                    case Properties::Powered::FALSE:
                        return 11688;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11689;
                    case Properties::Powered::FALSE:
                        return 11690;
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
                        return 11691;
                    case Properties::Powered::FALSE:
                        return 11692;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11693;
                    case Properties::Powered::FALSE:
                        return 11694;
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
                        return 11695;
                    case Properties::Powered::FALSE:
                        return 11696;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11697;
                    case Properties::Powered::FALSE:
                        return 11698;
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
                        return 11699;
                    case Properties::Powered::FALSE:
                        return 11700;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11701;
                    case Properties::Powered::FALSE:
                        return 11702;
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
                        return 11703;
                    case Properties::Powered::FALSE:
                        return 11704;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11705;
                    case Properties::Powered::FALSE:
                        return 11706;
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
                        return 11707;
                    case Properties::Powered::FALSE:
                        return 11708;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11709;
                    case Properties::Powered::FALSE:
                        return 11710;
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
                        return 11711;
                    case Properties::Powered::FALSE:
                        return 11712;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11713;
                    case Properties::Powered::FALSE:
                        return 11714;
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
                        return 11715;
                    case Properties::Powered::FALSE:
                        return 11716;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11717;
                    case Properties::Powered::FALSE:
                        return 11718;
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
                        return 11719;
                    case Properties::Powered::FALSE:
                        return 11720;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11721;
                    case Properties::Powered::FALSE:
                        return 11722;
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
