#include "CobbledDeepslateWall.hpp"
namespace Blocks {
namespace CobbledDeepslateWall {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
    switch (east) {
    case Properties::East::NONE:
        switch (north) {
        case Properties::North::NONE:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21652;
                        case Properties::West::LOW:
                            return 21653;
                        case Properties::West::TALL:
                            return 21654;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21655;
                        case Properties::West::LOW:
                            return 21656;
                        case Properties::West::TALL:
                            return 21657;
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
                        case Properties::West::NONE:
                            return 21658;
                        case Properties::West::LOW:
                            return 21659;
                        case Properties::West::TALL:
                            return 21660;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21661;
                        case Properties::West::LOW:
                            return 21662;
                        case Properties::West::TALL:
                            return 21663;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21664;
                        case Properties::West::LOW:
                            return 21665;
                        case Properties::West::TALL:
                            return 21666;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21667;
                        case Properties::West::LOW:
                            return 21668;
                        case Properties::West::TALL:
                            return 21669;
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
                        case Properties::West::NONE:
                            return 21670;
                        case Properties::West::LOW:
                            return 21671;
                        case Properties::West::TALL:
                            return 21672;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21673;
                        case Properties::West::LOW:
                            return 21674;
                        case Properties::West::TALL:
                            return 21675;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21676;
                        case Properties::West::LOW:
                            return 21677;
                        case Properties::West::TALL:
                            return 21678;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21679;
                        case Properties::West::LOW:
                            return 21680;
                        case Properties::West::TALL:
                            return 21681;
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
                        case Properties::West::NONE:
                            return 21682;
                        case Properties::West::LOW:
                            return 21683;
                        case Properties::West::TALL:
                            return 21684;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21685;
                        case Properties::West::LOW:
                            return 21686;
                        case Properties::West::TALL:
                            return 21687;
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
        case Properties::North::LOW:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21688;
                        case Properties::West::LOW:
                            return 21689;
                        case Properties::West::TALL:
                            return 21690;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21691;
                        case Properties::West::LOW:
                            return 21692;
                        case Properties::West::TALL:
                            return 21693;
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
                        case Properties::West::NONE:
                            return 21694;
                        case Properties::West::LOW:
                            return 21695;
                        case Properties::West::TALL:
                            return 21696;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21697;
                        case Properties::West::LOW:
                            return 21698;
                        case Properties::West::TALL:
                            return 21699;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21700;
                        case Properties::West::LOW:
                            return 21701;
                        case Properties::West::TALL:
                            return 21702;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21703;
                        case Properties::West::LOW:
                            return 21704;
                        case Properties::West::TALL:
                            return 21705;
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
                        case Properties::West::NONE:
                            return 21706;
                        case Properties::West::LOW:
                            return 21707;
                        case Properties::West::TALL:
                            return 21708;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21709;
                        case Properties::West::LOW:
                            return 21710;
                        case Properties::West::TALL:
                            return 21711;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21712;
                        case Properties::West::LOW:
                            return 21713;
                        case Properties::West::TALL:
                            return 21714;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21715;
                        case Properties::West::LOW:
                            return 21716;
                        case Properties::West::TALL:
                            return 21717;
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
                        case Properties::West::NONE:
                            return 21718;
                        case Properties::West::LOW:
                            return 21719;
                        case Properties::West::TALL:
                            return 21720;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21721;
                        case Properties::West::LOW:
                            return 21722;
                        case Properties::West::TALL:
                            return 21723;
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
        case Properties::North::TALL:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21724;
                        case Properties::West::LOW:
                            return 21725;
                        case Properties::West::TALL:
                            return 21726;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21727;
                        case Properties::West::LOW:
                            return 21728;
                        case Properties::West::TALL:
                            return 21729;
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
                        case Properties::West::NONE:
                            return 21730;
                        case Properties::West::LOW:
                            return 21731;
                        case Properties::West::TALL:
                            return 21732;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21733;
                        case Properties::West::LOW:
                            return 21734;
                        case Properties::West::TALL:
                            return 21735;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21736;
                        case Properties::West::LOW:
                            return 21737;
                        case Properties::West::TALL:
                            return 21738;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21739;
                        case Properties::West::LOW:
                            return 21740;
                        case Properties::West::TALL:
                            return 21741;
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
                        case Properties::West::NONE:
                            return 21742;
                        case Properties::West::LOW:
                            return 21743;
                        case Properties::West::TALL:
                            return 21744;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21745;
                        case Properties::West::LOW:
                            return 21746;
                        case Properties::West::TALL:
                            return 21747;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21748;
                        case Properties::West::LOW:
                            return 21749;
                        case Properties::West::TALL:
                            return 21750;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21751;
                        case Properties::West::LOW:
                            return 21752;
                        case Properties::West::TALL:
                            return 21753;
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
                        case Properties::West::NONE:
                            return 21754;
                        case Properties::West::LOW:
                            return 21755;
                        case Properties::West::TALL:
                            return 21756;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21757;
                        case Properties::West::LOW:
                            return 21758;
                        case Properties::West::TALL:
                            return 21759;
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
    case Properties::East::LOW:
        switch (north) {
        case Properties::North::NONE:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21760;
                        case Properties::West::LOW:
                            return 21761;
                        case Properties::West::TALL:
                            return 21762;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21763;
                        case Properties::West::LOW:
                            return 21764;
                        case Properties::West::TALL:
                            return 21765;
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
                        case Properties::West::NONE:
                            return 21766;
                        case Properties::West::LOW:
                            return 21767;
                        case Properties::West::TALL:
                            return 21768;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21769;
                        case Properties::West::LOW:
                            return 21770;
                        case Properties::West::TALL:
                            return 21771;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21772;
                        case Properties::West::LOW:
                            return 21773;
                        case Properties::West::TALL:
                            return 21774;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21775;
                        case Properties::West::LOW:
                            return 21776;
                        case Properties::West::TALL:
                            return 21777;
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
                        case Properties::West::NONE:
                            return 21778;
                        case Properties::West::LOW:
                            return 21779;
                        case Properties::West::TALL:
                            return 21780;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21781;
                        case Properties::West::LOW:
                            return 21782;
                        case Properties::West::TALL:
                            return 21783;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21784;
                        case Properties::West::LOW:
                            return 21785;
                        case Properties::West::TALL:
                            return 21786;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21787;
                        case Properties::West::LOW:
                            return 21788;
                        case Properties::West::TALL:
                            return 21789;
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
                        case Properties::West::NONE:
                            return 21790;
                        case Properties::West::LOW:
                            return 21791;
                        case Properties::West::TALL:
                            return 21792;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21793;
                        case Properties::West::LOW:
                            return 21794;
                        case Properties::West::TALL:
                            return 21795;
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
        case Properties::North::LOW:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21796;
                        case Properties::West::LOW:
                            return 21797;
                        case Properties::West::TALL:
                            return 21798;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21799;
                        case Properties::West::LOW:
                            return 21800;
                        case Properties::West::TALL:
                            return 21801;
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
                        case Properties::West::NONE:
                            return 21802;
                        case Properties::West::LOW:
                            return 21803;
                        case Properties::West::TALL:
                            return 21804;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21805;
                        case Properties::West::LOW:
                            return 21806;
                        case Properties::West::TALL:
                            return 21807;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21808;
                        case Properties::West::LOW:
                            return 21809;
                        case Properties::West::TALL:
                            return 21810;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21811;
                        case Properties::West::LOW:
                            return 21812;
                        case Properties::West::TALL:
                            return 21813;
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
                        case Properties::West::NONE:
                            return 21814;
                        case Properties::West::LOW:
                            return 21815;
                        case Properties::West::TALL:
                            return 21816;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21817;
                        case Properties::West::LOW:
                            return 21818;
                        case Properties::West::TALL:
                            return 21819;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21820;
                        case Properties::West::LOW:
                            return 21821;
                        case Properties::West::TALL:
                            return 21822;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21823;
                        case Properties::West::LOW:
                            return 21824;
                        case Properties::West::TALL:
                            return 21825;
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
                        case Properties::West::NONE:
                            return 21826;
                        case Properties::West::LOW:
                            return 21827;
                        case Properties::West::TALL:
                            return 21828;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21829;
                        case Properties::West::LOW:
                            return 21830;
                        case Properties::West::TALL:
                            return 21831;
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
        case Properties::North::TALL:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21832;
                        case Properties::West::LOW:
                            return 21833;
                        case Properties::West::TALL:
                            return 21834;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21835;
                        case Properties::West::LOW:
                            return 21836;
                        case Properties::West::TALL:
                            return 21837;
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
                        case Properties::West::NONE:
                            return 21838;
                        case Properties::West::LOW:
                            return 21839;
                        case Properties::West::TALL:
                            return 21840;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21841;
                        case Properties::West::LOW:
                            return 21842;
                        case Properties::West::TALL:
                            return 21843;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21844;
                        case Properties::West::LOW:
                            return 21845;
                        case Properties::West::TALL:
                            return 21846;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21847;
                        case Properties::West::LOW:
                            return 21848;
                        case Properties::West::TALL:
                            return 21849;
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
                        case Properties::West::NONE:
                            return 21850;
                        case Properties::West::LOW:
                            return 21851;
                        case Properties::West::TALL:
                            return 21852;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21853;
                        case Properties::West::LOW:
                            return 21854;
                        case Properties::West::TALL:
                            return 21855;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21856;
                        case Properties::West::LOW:
                            return 21857;
                        case Properties::West::TALL:
                            return 21858;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21859;
                        case Properties::West::LOW:
                            return 21860;
                        case Properties::West::TALL:
                            return 21861;
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
                        case Properties::West::NONE:
                            return 21862;
                        case Properties::West::LOW:
                            return 21863;
                        case Properties::West::TALL:
                            return 21864;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21865;
                        case Properties::West::LOW:
                            return 21866;
                        case Properties::West::TALL:
                            return 21867;
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
    case Properties::East::TALL:
        switch (north) {
        case Properties::North::NONE:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21868;
                        case Properties::West::LOW:
                            return 21869;
                        case Properties::West::TALL:
                            return 21870;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21871;
                        case Properties::West::LOW:
                            return 21872;
                        case Properties::West::TALL:
                            return 21873;
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
                        case Properties::West::NONE:
                            return 21874;
                        case Properties::West::LOW:
                            return 21875;
                        case Properties::West::TALL:
                            return 21876;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21877;
                        case Properties::West::LOW:
                            return 21878;
                        case Properties::West::TALL:
                            return 21879;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21880;
                        case Properties::West::LOW:
                            return 21881;
                        case Properties::West::TALL:
                            return 21882;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21883;
                        case Properties::West::LOW:
                            return 21884;
                        case Properties::West::TALL:
                            return 21885;
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
                        case Properties::West::NONE:
                            return 21886;
                        case Properties::West::LOW:
                            return 21887;
                        case Properties::West::TALL:
                            return 21888;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21889;
                        case Properties::West::LOW:
                            return 21890;
                        case Properties::West::TALL:
                            return 21891;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21892;
                        case Properties::West::LOW:
                            return 21893;
                        case Properties::West::TALL:
                            return 21894;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21895;
                        case Properties::West::LOW:
                            return 21896;
                        case Properties::West::TALL:
                            return 21897;
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
                        case Properties::West::NONE:
                            return 21898;
                        case Properties::West::LOW:
                            return 21899;
                        case Properties::West::TALL:
                            return 21900;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21901;
                        case Properties::West::LOW:
                            return 21902;
                        case Properties::West::TALL:
                            return 21903;
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
        case Properties::North::LOW:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21904;
                        case Properties::West::LOW:
                            return 21905;
                        case Properties::West::TALL:
                            return 21906;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21907;
                        case Properties::West::LOW:
                            return 21908;
                        case Properties::West::TALL:
                            return 21909;
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
                        case Properties::West::NONE:
                            return 21910;
                        case Properties::West::LOW:
                            return 21911;
                        case Properties::West::TALL:
                            return 21912;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21913;
                        case Properties::West::LOW:
                            return 21914;
                        case Properties::West::TALL:
                            return 21915;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21916;
                        case Properties::West::LOW:
                            return 21917;
                        case Properties::West::TALL:
                            return 21918;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21919;
                        case Properties::West::LOW:
                            return 21920;
                        case Properties::West::TALL:
                            return 21921;
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
                        case Properties::West::NONE:
                            return 21922;
                        case Properties::West::LOW:
                            return 21923;
                        case Properties::West::TALL:
                            return 21924;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21925;
                        case Properties::West::LOW:
                            return 21926;
                        case Properties::West::TALL:
                            return 21927;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21928;
                        case Properties::West::LOW:
                            return 21929;
                        case Properties::West::TALL:
                            return 21930;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21931;
                        case Properties::West::LOW:
                            return 21932;
                        case Properties::West::TALL:
                            return 21933;
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
                        case Properties::West::NONE:
                            return 21934;
                        case Properties::West::LOW:
                            return 21935;
                        case Properties::West::TALL:
                            return 21936;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21937;
                        case Properties::West::LOW:
                            return 21938;
                        case Properties::West::TALL:
                            return 21939;
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
        case Properties::North::TALL:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21940;
                        case Properties::West::LOW:
                            return 21941;
                        case Properties::West::TALL:
                            return 21942;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21943;
                        case Properties::West::LOW:
                            return 21944;
                        case Properties::West::TALL:
                            return 21945;
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
                        case Properties::West::NONE:
                            return 21946;
                        case Properties::West::LOW:
                            return 21947;
                        case Properties::West::TALL:
                            return 21948;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21949;
                        case Properties::West::LOW:
                            return 21950;
                        case Properties::West::TALL:
                            return 21951;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21952;
                        case Properties::West::LOW:
                            return 21953;
                        case Properties::West::TALL:
                            return 21954;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21955;
                        case Properties::West::LOW:
                            return 21956;
                        case Properties::West::TALL:
                            return 21957;
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
                        case Properties::West::NONE:
                            return 21958;
                        case Properties::West::LOW:
                            return 21959;
                        case Properties::West::TALL:
                            return 21960;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21961;
                        case Properties::West::LOW:
                            return 21962;
                        case Properties::West::TALL:
                            return 21963;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21964;
                        case Properties::West::LOW:
                            return 21965;
                        case Properties::West::TALL:
                            return 21966;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21967;
                        case Properties::West::LOW:
                            return 21968;
                        case Properties::West::TALL:
                            return 21969;
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
                        case Properties::West::NONE:
                            return 21970;
                        case Properties::West::LOW:
                            return 21971;
                        case Properties::West::TALL:
                            return 21972;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 21973;
                        case Properties::West::LOW:
                            return 21974;
                        case Properties::West::TALL:
                            return 21975;
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
