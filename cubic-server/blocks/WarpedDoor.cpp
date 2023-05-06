#include "WarpedDoor.hpp"
namespace Blocks {
    namespace WarpedDoor {
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
                                return 18584;
                            case Properties::Powered::FALSE:
                                return 18585;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18586;
                            case Properties::Powered::FALSE:
                                return 18587;
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
                                return 18588;
                            case Properties::Powered::FALSE:
                                return 18589;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18590;
                            case Properties::Powered::FALSE:
                                return 18591;
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
                                return 18592;
                            case Properties::Powered::FALSE:
                                return 18593;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18594;
                            case Properties::Powered::FALSE:
                                return 18595;
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
                                return 18596;
                            case Properties::Powered::FALSE:
                                return 18597;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18598;
                            case Properties::Powered::FALSE:
                                return 18599;
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
                                return 18600;
                            case Properties::Powered::FALSE:
                                return 18601;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18602;
                            case Properties::Powered::FALSE:
                                return 18603;
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
                                return 18604;
                            case Properties::Powered::FALSE:
                                return 18605;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18606;
                            case Properties::Powered::FALSE:
                                return 18607;
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
                                return 18608;
                            case Properties::Powered::FALSE:
                                return 18609;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18610;
                            case Properties::Powered::FALSE:
                                return 18611;
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
                                return 18612;
                            case Properties::Powered::FALSE:
                                return 18613;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18614;
                            case Properties::Powered::FALSE:
                                return 18615;
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
                                return 18616;
                            case Properties::Powered::FALSE:
                                return 18617;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18618;
                            case Properties::Powered::FALSE:
                                return 18619;
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
                                return 18620;
                            case Properties::Powered::FALSE:
                                return 18621;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18622;
                            case Properties::Powered::FALSE:
                                return 18623;
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
                                return 18624;
                            case Properties::Powered::FALSE:
                                return 18625;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18626;
                            case Properties::Powered::FALSE:
                                return 18627;
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
                                return 18628;
                            case Properties::Powered::FALSE:
                                return 18629;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18630;
                            case Properties::Powered::FALSE:
                                return 18631;
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
                                return 18632;
                            case Properties::Powered::FALSE:
                                return 18633;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18634;
                            case Properties::Powered::FALSE:
                                return 18635;
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
                                return 18636;
                            case Properties::Powered::FALSE:
                                return 18637;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18638;
                            case Properties::Powered::FALSE:
                                return 18639;
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
                                return 18640;
                            case Properties::Powered::FALSE:
                                return 18641;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18642;
                            case Properties::Powered::FALSE:
                                return 18643;
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
                                return 18644;
                            case Properties::Powered::FALSE:
                                return 18645;
                            default:
                                return 0;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 18646;
                            case Properties::Powered::FALSE:
                                return 18647;
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
