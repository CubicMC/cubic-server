#include "OakDoor.hpp"
namespace Blocks {
namespace OakDoor {
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
                        return 4506;
                    case Properties::Powered::FALSE:
                        return 4507;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4508;
                    case Properties::Powered::FALSE:
                        return 4509;
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
                        return 4510;
                    case Properties::Powered::FALSE:
                        return 4511;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4512;
                    case Properties::Powered::FALSE:
                        return 4513;
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
                        return 4514;
                    case Properties::Powered::FALSE:
                        return 4515;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4516;
                    case Properties::Powered::FALSE:
                        return 4517;
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
                        return 4518;
                    case Properties::Powered::FALSE:
                        return 4519;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4520;
                    case Properties::Powered::FALSE:
                        return 4521;
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
                        return 4522;
                    case Properties::Powered::FALSE:
                        return 4523;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4524;
                    case Properties::Powered::FALSE:
                        return 4525;
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
                        return 4526;
                    case Properties::Powered::FALSE:
                        return 4527;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4528;
                    case Properties::Powered::FALSE:
                        return 4529;
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
                        return 4530;
                    case Properties::Powered::FALSE:
                        return 4531;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4532;
                    case Properties::Powered::FALSE:
                        return 4533;
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
                        return 4534;
                    case Properties::Powered::FALSE:
                        return 4535;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4536;
                    case Properties::Powered::FALSE:
                        return 4537;
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
                        return 4538;
                    case Properties::Powered::FALSE:
                        return 4539;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4540;
                    case Properties::Powered::FALSE:
                        return 4541;
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
                        return 4542;
                    case Properties::Powered::FALSE:
                        return 4543;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4544;
                    case Properties::Powered::FALSE:
                        return 4545;
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
                        return 4546;
                    case Properties::Powered::FALSE:
                        return 4547;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4548;
                    case Properties::Powered::FALSE:
                        return 4549;
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
                        return 4550;
                    case Properties::Powered::FALSE:
                        return 4551;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4552;
                    case Properties::Powered::FALSE:
                        return 4553;
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
                        return 4554;
                    case Properties::Powered::FALSE:
                        return 4555;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4556;
                    case Properties::Powered::FALSE:
                        return 4557;
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
                        return 4558;
                    case Properties::Powered::FALSE:
                        return 4559;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4560;
                    case Properties::Powered::FALSE:
                        return 4561;
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
                        return 4562;
                    case Properties::Powered::FALSE:
                        return 4563;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4564;
                    case Properties::Powered::FALSE:
                        return 4565;
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
                        return 4566;
                    case Properties::Powered::FALSE:
                        return 4567;
                    default:
                        return 0;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 4568;
                    case Properties::Powered::FALSE:
                        return 4569;
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
