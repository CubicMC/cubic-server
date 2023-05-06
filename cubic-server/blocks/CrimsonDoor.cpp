#include "CrimsonDoor.hpp"
namespace Blocks {
namespace CrimsonDoor {
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
                        return 18520;
                    case Properties::Powered::FALSE:
                        return 18521;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18522;
                    case Properties::Powered::FALSE:
                        return 18523;
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
                        return 18524;
                    case Properties::Powered::FALSE:
                        return 18525;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18526;
                    case Properties::Powered::FALSE:
                        return 18527;
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
                        return 18528;
                    case Properties::Powered::FALSE:
                        return 18529;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18530;
                    case Properties::Powered::FALSE:
                        return 18531;
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
                        return 18532;
                    case Properties::Powered::FALSE:
                        return 18533;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18534;
                    case Properties::Powered::FALSE:
                        return 18535;
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
                        return 18536;
                    case Properties::Powered::FALSE:
                        return 18537;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18538;
                    case Properties::Powered::FALSE:
                        return 18539;
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
                        return 18540;
                    case Properties::Powered::FALSE:
                        return 18541;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18542;
                    case Properties::Powered::FALSE:
                        return 18543;
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
                        return 18544;
                    case Properties::Powered::FALSE:
                        return 18545;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18546;
                    case Properties::Powered::FALSE:
                        return 18547;
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
                        return 18548;
                    case Properties::Powered::FALSE:
                        return 18549;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18550;
                    case Properties::Powered::FALSE:
                        return 18551;
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
                        return 18552;
                    case Properties::Powered::FALSE:
                        return 18553;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18554;
                    case Properties::Powered::FALSE:
                        return 18555;
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
                        return 18556;
                    case Properties::Powered::FALSE:
                        return 18557;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18558;
                    case Properties::Powered::FALSE:
                        return 18559;
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
                        return 18560;
                    case Properties::Powered::FALSE:
                        return 18561;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18562;
                    case Properties::Powered::FALSE:
                        return 18563;
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
                        return 18564;
                    case Properties::Powered::FALSE:
                        return 18565;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18566;
                    case Properties::Powered::FALSE:
                        return 18567;
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
                        return 18568;
                    case Properties::Powered::FALSE:
                        return 18569;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18570;
                    case Properties::Powered::FALSE:
                        return 18571;
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
                        return 18572;
                    case Properties::Powered::FALSE:
                        return 18573;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18574;
                    case Properties::Powered::FALSE:
                        return 18575;
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
                        return 18576;
                    case Properties::Powered::FALSE:
                        return 18577;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18578;
                    case Properties::Powered::FALSE:
                        return 18579;
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
                        return 18580;
                    case Properties::Powered::FALSE:
                        return 18581;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 18582;
                    case Properties::Powered::FALSE:
                        return 18583;
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
