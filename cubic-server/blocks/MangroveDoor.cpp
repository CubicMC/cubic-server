#include "MangroveDoor.hpp"
namespace Blocks {
namespace MangroveDoor {
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
                        return 11595;
                    case Properties::Powered::FALSE:
                        return 11596;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11597;
                    case Properties::Powered::FALSE:
                        return 11598;
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
                        return 11599;
                    case Properties::Powered::FALSE:
                        return 11600;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11601;
                    case Properties::Powered::FALSE:
                        return 11602;
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
                        return 11603;
                    case Properties::Powered::FALSE:
                        return 11604;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11605;
                    case Properties::Powered::FALSE:
                        return 11606;
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
                        return 11607;
                    case Properties::Powered::FALSE:
                        return 11608;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11609;
                    case Properties::Powered::FALSE:
                        return 11610;
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
                        return 11611;
                    case Properties::Powered::FALSE:
                        return 11612;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11613;
                    case Properties::Powered::FALSE:
                        return 11614;
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
                        return 11615;
                    case Properties::Powered::FALSE:
                        return 11616;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11617;
                    case Properties::Powered::FALSE:
                        return 11618;
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
                        return 11619;
                    case Properties::Powered::FALSE:
                        return 11620;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11621;
                    case Properties::Powered::FALSE:
                        return 11622;
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
                        return 11623;
                    case Properties::Powered::FALSE:
                        return 11624;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11625;
                    case Properties::Powered::FALSE:
                        return 11626;
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
                        return 11627;
                    case Properties::Powered::FALSE:
                        return 11628;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11629;
                    case Properties::Powered::FALSE:
                        return 11630;
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
                        return 11631;
                    case Properties::Powered::FALSE:
                        return 11632;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11633;
                    case Properties::Powered::FALSE:
                        return 11634;
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
                        return 11635;
                    case Properties::Powered::FALSE:
                        return 11636;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11637;
                    case Properties::Powered::FALSE:
                        return 11638;
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
                        return 11639;
                    case Properties::Powered::FALSE:
                        return 11640;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11641;
                    case Properties::Powered::FALSE:
                        return 11642;
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
                        return 11643;
                    case Properties::Powered::FALSE:
                        return 11644;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11645;
                    case Properties::Powered::FALSE:
                        return 11646;
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
                        return 11647;
                    case Properties::Powered::FALSE:
                        return 11648;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11649;
                    case Properties::Powered::FALSE:
                        return 11650;
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
                        return 11651;
                    case Properties::Powered::FALSE:
                        return 11652;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11653;
                    case Properties::Powered::FALSE:
                        return 11654;
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
                        return 11655;
                    case Properties::Powered::FALSE:
                        return 11656;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11657;
                    case Properties::Powered::FALSE:
                        return 11658;
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
