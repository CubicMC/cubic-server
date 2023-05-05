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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11661;
                            case Properties::Powered::FALSE:
                                return 11662;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11663;
                            case Properties::Powered::FALSE:
                                return 11664;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11665;
                            case Properties::Powered::FALSE:
                                return 11666;
                            }
                        }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11669;
                            case Properties::Powered::FALSE:
                                return 11670;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11671;
                            case Properties::Powered::FALSE:
                                return 11672;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11673;
                            case Properties::Powered::FALSE:
                                return 11674;
                            }
                        }
                    }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11677;
                            case Properties::Powered::FALSE:
                                return 11678;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11679;
                            case Properties::Powered::FALSE:
                                return 11680;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11681;
                            case Properties::Powered::FALSE:
                                return 11682;
                            }
                        }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11685;
                            case Properties::Powered::FALSE:
                                return 11686;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11687;
                            case Properties::Powered::FALSE:
                                return 11688;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11689;
                            case Properties::Powered::FALSE:
                                return 11690;
                            }
                        }
                    }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11693;
                            case Properties::Powered::FALSE:
                                return 11694;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11695;
                            case Properties::Powered::FALSE:
                                return 11696;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11697;
                            case Properties::Powered::FALSE:
                                return 11698;
                            }
                        }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11701;
                            case Properties::Powered::FALSE:
                                return 11702;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11703;
                            case Properties::Powered::FALSE:
                                return 11704;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11705;
                            case Properties::Powered::FALSE:
                                return 11706;
                            }
                        }
                    }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11709;
                            case Properties::Powered::FALSE:
                                return 11710;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11711;
                            case Properties::Powered::FALSE:
                                return 11712;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11713;
                            case Properties::Powered::FALSE:
                                return 11714;
                            }
                        }
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
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11717;
                            case Properties::Powered::FALSE:
                                return 11718;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11719;
                            case Properties::Powered::FALSE:
                                return 11720;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 11721;
                            case Properties::Powered::FALSE:
                                return 11722;
                            }
                        }
                    }
                }
            }
            return 0;
        }
    }

}
