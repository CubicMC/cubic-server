#include "GlowLichen.hpp"
namespace Blocks {
namespace GlowLichen {
BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
    switch (down) {
    case Properties::Down::TRUE:
        switch (east) {
        case Properties::East::TRUE:
            switch (north) {
            case Properties::North::TRUE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6639;
                            case Properties::West::FALSE:
                                return 6640;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6641;
                            case Properties::West::FALSE:
                                return 6642;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6643;
                            case Properties::West::FALSE:
                                return 6644;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6645;
                            case Properties::West::FALSE:
                                return 6646;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6647;
                            case Properties::West::FALSE:
                                return 6648;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6649;
                            case Properties::West::FALSE:
                                return 6650;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6651;
                            case Properties::West::FALSE:
                                return 6652;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6653;
                            case Properties::West::FALSE:
                                return 6654;
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
            case Properties::North::FALSE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6655;
                            case Properties::West::FALSE:
                                return 6656;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6657;
                            case Properties::West::FALSE:
                                return 6658;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6659;
                            case Properties::West::FALSE:
                                return 6660;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6661;
                            case Properties::West::FALSE:
                                return 6662;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6663;
                            case Properties::West::FALSE:
                                return 6664;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6665;
                            case Properties::West::FALSE:
                                return 6666;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6667;
                            case Properties::West::FALSE:
                                return 6668;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6669;
                            case Properties::West::FALSE:
                                return 6670;
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
        case Properties::East::FALSE:
            switch (north) {
            case Properties::North::TRUE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6671;
                            case Properties::West::FALSE:
                                return 6672;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6673;
                            case Properties::West::FALSE:
                                return 6674;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6675;
                            case Properties::West::FALSE:
                                return 6676;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6677;
                            case Properties::West::FALSE:
                                return 6678;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6679;
                            case Properties::West::FALSE:
                                return 6680;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6681;
                            case Properties::West::FALSE:
                                return 6682;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6683;
                            case Properties::West::FALSE:
                                return 6684;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6685;
                            case Properties::West::FALSE:
                                return 6686;
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
            case Properties::North::FALSE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6687;
                            case Properties::West::FALSE:
                                return 6688;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6689;
                            case Properties::West::FALSE:
                                return 6690;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6691;
                            case Properties::West::FALSE:
                                return 6692;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6693;
                            case Properties::West::FALSE:
                                return 6694;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6695;
                            case Properties::West::FALSE:
                                return 6696;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6697;
                            case Properties::West::FALSE:
                                return 6698;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6699;
                            case Properties::West::FALSE:
                                return 6700;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6701;
                            case Properties::West::FALSE:
                                return 6702;
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
        default:
            return 0;
        }
    case Properties::Down::FALSE:
        switch (east) {
        case Properties::East::TRUE:
            switch (north) {
            case Properties::North::TRUE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6703;
                            case Properties::West::FALSE:
                                return 6704;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6705;
                            case Properties::West::FALSE:
                                return 6706;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6707;
                            case Properties::West::FALSE:
                                return 6708;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6709;
                            case Properties::West::FALSE:
                                return 6710;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6711;
                            case Properties::West::FALSE:
                                return 6712;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6713;
                            case Properties::West::FALSE:
                                return 6714;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6715;
                            case Properties::West::FALSE:
                                return 6716;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6717;
                            case Properties::West::FALSE:
                                return 6718;
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
            case Properties::North::FALSE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6719;
                            case Properties::West::FALSE:
                                return 6720;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6721;
                            case Properties::West::FALSE:
                                return 6722;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6723;
                            case Properties::West::FALSE:
                                return 6724;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6725;
                            case Properties::West::FALSE:
                                return 6726;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6727;
                            case Properties::West::FALSE:
                                return 6728;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6729;
                            case Properties::West::FALSE:
                                return 6730;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6731;
                            case Properties::West::FALSE:
                                return 6732;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6733;
                            case Properties::West::FALSE:
                                return 6734;
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
        case Properties::East::FALSE:
            switch (north) {
            case Properties::North::TRUE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6735;
                            case Properties::West::FALSE:
                                return 6736;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6737;
                            case Properties::West::FALSE:
                                return 6738;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6739;
                            case Properties::West::FALSE:
                                return 6740;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6741;
                            case Properties::West::FALSE:
                                return 6742;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6743;
                            case Properties::West::FALSE:
                                return 6744;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6745;
                            case Properties::West::FALSE:
                                return 6746;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6747;
                            case Properties::West::FALSE:
                                return 6748;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6749;
                            case Properties::West::FALSE:
                                return 6750;
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
            case Properties::North::FALSE:
                switch (south) {
                case Properties::South::TRUE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6751;
                            case Properties::West::FALSE:
                                return 6752;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6753;
                            case Properties::West::FALSE:
                                return 6754;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6755;
                            case Properties::West::FALSE:
                                return 6756;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6757;
                            case Properties::West::FALSE:
                                return 6758;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6759;
                            case Properties::West::FALSE:
                                return 6760;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6761;
                            case Properties::West::FALSE:
                                return 6762;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6763;
                            case Properties::West::FALSE:
                                return 6764;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6765;
                            case Properties::West::FALSE:
                                return 6766;
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
