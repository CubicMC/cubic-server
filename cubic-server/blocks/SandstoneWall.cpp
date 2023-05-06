#include "SandstoneWall.hpp"
namespace Blocks {
namespace SandstoneWall {
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
                            return 16772;
                        case Properties::West::LOW:
                            return 16773;
                        case Properties::West::TALL:
                            return 16774;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16775;
                        case Properties::West::LOW:
                            return 16776;
                        case Properties::West::TALL:
                            return 16777;
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
                            return 16778;
                        case Properties::West::LOW:
                            return 16779;
                        case Properties::West::TALL:
                            return 16780;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16781;
                        case Properties::West::LOW:
                            return 16782;
                        case Properties::West::TALL:
                            return 16783;
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
                            return 16784;
                        case Properties::West::LOW:
                            return 16785;
                        case Properties::West::TALL:
                            return 16786;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16787;
                        case Properties::West::LOW:
                            return 16788;
                        case Properties::West::TALL:
                            return 16789;
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
                            return 16790;
                        case Properties::West::LOW:
                            return 16791;
                        case Properties::West::TALL:
                            return 16792;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16793;
                        case Properties::West::LOW:
                            return 16794;
                        case Properties::West::TALL:
                            return 16795;
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
                            return 16796;
                        case Properties::West::LOW:
                            return 16797;
                        case Properties::West::TALL:
                            return 16798;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16799;
                        case Properties::West::LOW:
                            return 16800;
                        case Properties::West::TALL:
                            return 16801;
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
                            return 16802;
                        case Properties::West::LOW:
                            return 16803;
                        case Properties::West::TALL:
                            return 16804;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16805;
                        case Properties::West::LOW:
                            return 16806;
                        case Properties::West::TALL:
                            return 16807;
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
                            return 16808;
                        case Properties::West::LOW:
                            return 16809;
                        case Properties::West::TALL:
                            return 16810;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16811;
                        case Properties::West::LOW:
                            return 16812;
                        case Properties::West::TALL:
                            return 16813;
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
                            return 16814;
                        case Properties::West::LOW:
                            return 16815;
                        case Properties::West::TALL:
                            return 16816;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16817;
                        case Properties::West::LOW:
                            return 16818;
                        case Properties::West::TALL:
                            return 16819;
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
                            return 16820;
                        case Properties::West::LOW:
                            return 16821;
                        case Properties::West::TALL:
                            return 16822;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16823;
                        case Properties::West::LOW:
                            return 16824;
                        case Properties::West::TALL:
                            return 16825;
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
                            return 16826;
                        case Properties::West::LOW:
                            return 16827;
                        case Properties::West::TALL:
                            return 16828;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16829;
                        case Properties::West::LOW:
                            return 16830;
                        case Properties::West::TALL:
                            return 16831;
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
                            return 16832;
                        case Properties::West::LOW:
                            return 16833;
                        case Properties::West::TALL:
                            return 16834;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16835;
                        case Properties::West::LOW:
                            return 16836;
                        case Properties::West::TALL:
                            return 16837;
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
                            return 16838;
                        case Properties::West::LOW:
                            return 16839;
                        case Properties::West::TALL:
                            return 16840;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16841;
                        case Properties::West::LOW:
                            return 16842;
                        case Properties::West::TALL:
                            return 16843;
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
                            return 16844;
                        case Properties::West::LOW:
                            return 16845;
                        case Properties::West::TALL:
                            return 16846;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16847;
                        case Properties::West::LOW:
                            return 16848;
                        case Properties::West::TALL:
                            return 16849;
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
                            return 16850;
                        case Properties::West::LOW:
                            return 16851;
                        case Properties::West::TALL:
                            return 16852;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16853;
                        case Properties::West::LOW:
                            return 16854;
                        case Properties::West::TALL:
                            return 16855;
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
                            return 16856;
                        case Properties::West::LOW:
                            return 16857;
                        case Properties::West::TALL:
                            return 16858;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16859;
                        case Properties::West::LOW:
                            return 16860;
                        case Properties::West::TALL:
                            return 16861;
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
                            return 16862;
                        case Properties::West::LOW:
                            return 16863;
                        case Properties::West::TALL:
                            return 16864;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16865;
                        case Properties::West::LOW:
                            return 16866;
                        case Properties::West::TALL:
                            return 16867;
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
                            return 16868;
                        case Properties::West::LOW:
                            return 16869;
                        case Properties::West::TALL:
                            return 16870;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16871;
                        case Properties::West::LOW:
                            return 16872;
                        case Properties::West::TALL:
                            return 16873;
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
                            return 16874;
                        case Properties::West::LOW:
                            return 16875;
                        case Properties::West::TALL:
                            return 16876;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16877;
                        case Properties::West::LOW:
                            return 16878;
                        case Properties::West::TALL:
                            return 16879;
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
                            return 16880;
                        case Properties::West::LOW:
                            return 16881;
                        case Properties::West::TALL:
                            return 16882;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16883;
                        case Properties::West::LOW:
                            return 16884;
                        case Properties::West::TALL:
                            return 16885;
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
                            return 16886;
                        case Properties::West::LOW:
                            return 16887;
                        case Properties::West::TALL:
                            return 16888;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16889;
                        case Properties::West::LOW:
                            return 16890;
                        case Properties::West::TALL:
                            return 16891;
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
                            return 16892;
                        case Properties::West::LOW:
                            return 16893;
                        case Properties::West::TALL:
                            return 16894;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16895;
                        case Properties::West::LOW:
                            return 16896;
                        case Properties::West::TALL:
                            return 16897;
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
                            return 16898;
                        case Properties::West::LOW:
                            return 16899;
                        case Properties::West::TALL:
                            return 16900;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16901;
                        case Properties::West::LOW:
                            return 16902;
                        case Properties::West::TALL:
                            return 16903;
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
                            return 16904;
                        case Properties::West::LOW:
                            return 16905;
                        case Properties::West::TALL:
                            return 16906;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16907;
                        case Properties::West::LOW:
                            return 16908;
                        case Properties::West::TALL:
                            return 16909;
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
                            return 16910;
                        case Properties::West::LOW:
                            return 16911;
                        case Properties::West::TALL:
                            return 16912;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16913;
                        case Properties::West::LOW:
                            return 16914;
                        case Properties::West::TALL:
                            return 16915;
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
                            return 16916;
                        case Properties::West::LOW:
                            return 16917;
                        case Properties::West::TALL:
                            return 16918;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16919;
                        case Properties::West::LOW:
                            return 16920;
                        case Properties::West::TALL:
                            return 16921;
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
                            return 16922;
                        case Properties::West::LOW:
                            return 16923;
                        case Properties::West::TALL:
                            return 16924;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16925;
                        case Properties::West::LOW:
                            return 16926;
                        case Properties::West::TALL:
                            return 16927;
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
                            return 16928;
                        case Properties::West::LOW:
                            return 16929;
                        case Properties::West::TALL:
                            return 16930;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16931;
                        case Properties::West::LOW:
                            return 16932;
                        case Properties::West::TALL:
                            return 16933;
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
                            return 16934;
                        case Properties::West::LOW:
                            return 16935;
                        case Properties::West::TALL:
                            return 16936;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16937;
                        case Properties::West::LOW:
                            return 16938;
                        case Properties::West::TALL:
                            return 16939;
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
                            return 16940;
                        case Properties::West::LOW:
                            return 16941;
                        case Properties::West::TALL:
                            return 16942;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16943;
                        case Properties::West::LOW:
                            return 16944;
                        case Properties::West::TALL:
                            return 16945;
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
                            return 16946;
                        case Properties::West::LOW:
                            return 16947;
                        case Properties::West::TALL:
                            return 16948;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16949;
                        case Properties::West::LOW:
                            return 16950;
                        case Properties::West::TALL:
                            return 16951;
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
                            return 16952;
                        case Properties::West::LOW:
                            return 16953;
                        case Properties::West::TALL:
                            return 16954;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16955;
                        case Properties::West::LOW:
                            return 16956;
                        case Properties::West::TALL:
                            return 16957;
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
                            return 16958;
                        case Properties::West::LOW:
                            return 16959;
                        case Properties::West::TALL:
                            return 16960;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16961;
                        case Properties::West::LOW:
                            return 16962;
                        case Properties::West::TALL:
                            return 16963;
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
                            return 16964;
                        case Properties::West::LOW:
                            return 16965;
                        case Properties::West::TALL:
                            return 16966;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16967;
                        case Properties::West::LOW:
                            return 16968;
                        case Properties::West::TALL:
                            return 16969;
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
                            return 16970;
                        case Properties::West::LOW:
                            return 16971;
                        case Properties::West::TALL:
                            return 16972;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16973;
                        case Properties::West::LOW:
                            return 16974;
                        case Properties::West::TALL:
                            return 16975;
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
                            return 16976;
                        case Properties::West::LOW:
                            return 16977;
                        case Properties::West::TALL:
                            return 16978;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16979;
                        case Properties::West::LOW:
                            return 16980;
                        case Properties::West::TALL:
                            return 16981;
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
                            return 16982;
                        case Properties::West::LOW:
                            return 16983;
                        case Properties::West::TALL:
                            return 16984;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16985;
                        case Properties::West::LOW:
                            return 16986;
                        case Properties::West::TALL:
                            return 16987;
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
                            return 16988;
                        case Properties::West::LOW:
                            return 16989;
                        case Properties::West::TALL:
                            return 16990;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16991;
                        case Properties::West::LOW:
                            return 16992;
                        case Properties::West::TALL:
                            return 16993;
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
                            return 16994;
                        case Properties::West::LOW:
                            return 16995;
                        case Properties::West::TALL:
                            return 16996;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16997;
                        case Properties::West::LOW:
                            return 16998;
                        case Properties::West::TALL:
                            return 16999;
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
                            return 17000;
                        case Properties::West::LOW:
                            return 17001;
                        case Properties::West::TALL:
                            return 17002;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17003;
                        case Properties::West::LOW:
                            return 17004;
                        case Properties::West::TALL:
                            return 17005;
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
                            return 17006;
                        case Properties::West::LOW:
                            return 17007;
                        case Properties::West::TALL:
                            return 17008;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17009;
                        case Properties::West::LOW:
                            return 17010;
                        case Properties::West::TALL:
                            return 17011;
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
                            return 17012;
                        case Properties::West::LOW:
                            return 17013;
                        case Properties::West::TALL:
                            return 17014;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17015;
                        case Properties::West::LOW:
                            return 17016;
                        case Properties::West::TALL:
                            return 17017;
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
                            return 17018;
                        case Properties::West::LOW:
                            return 17019;
                        case Properties::West::TALL:
                            return 17020;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17021;
                        case Properties::West::LOW:
                            return 17022;
                        case Properties::West::TALL:
                            return 17023;
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
                            return 17024;
                        case Properties::West::LOW:
                            return 17025;
                        case Properties::West::TALL:
                            return 17026;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17027;
                        case Properties::West::LOW:
                            return 17028;
                        case Properties::West::TALL:
                            return 17029;
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
                            return 17030;
                        case Properties::West::LOW:
                            return 17031;
                        case Properties::West::TALL:
                            return 17032;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17033;
                        case Properties::West::LOW:
                            return 17034;
                        case Properties::West::TALL:
                            return 17035;
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
                            return 17036;
                        case Properties::West::LOW:
                            return 17037;
                        case Properties::West::TALL:
                            return 17038;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17039;
                        case Properties::West::LOW:
                            return 17040;
                        case Properties::West::TALL:
                            return 17041;
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
                            return 17042;
                        case Properties::West::LOW:
                            return 17043;
                        case Properties::West::TALL:
                            return 17044;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17045;
                        case Properties::West::LOW:
                            return 17046;
                        case Properties::West::TALL:
                            return 17047;
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
                            return 17048;
                        case Properties::West::LOW:
                            return 17049;
                        case Properties::West::TALL:
                            return 17050;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17051;
                        case Properties::West::LOW:
                            return 17052;
                        case Properties::West::TALL:
                            return 17053;
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
                            return 17054;
                        case Properties::West::LOW:
                            return 17055;
                        case Properties::West::TALL:
                            return 17056;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17057;
                        case Properties::West::LOW:
                            return 17058;
                        case Properties::West::TALL:
                            return 17059;
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
                            return 17060;
                        case Properties::West::LOW:
                            return 17061;
                        case Properties::West::TALL:
                            return 17062;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17063;
                        case Properties::West::LOW:
                            return 17064;
                        case Properties::West::TALL:
                            return 17065;
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
                            return 17066;
                        case Properties::West::LOW:
                            return 17067;
                        case Properties::West::TALL:
                            return 17068;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17069;
                        case Properties::West::LOW:
                            return 17070;
                        case Properties::West::TALL:
                            return 17071;
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
                            return 17072;
                        case Properties::West::LOW:
                            return 17073;
                        case Properties::West::TALL:
                            return 17074;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17075;
                        case Properties::West::LOW:
                            return 17076;
                        case Properties::West::TALL:
                            return 17077;
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
                            return 17078;
                        case Properties::West::LOW:
                            return 17079;
                        case Properties::West::TALL:
                            return 17080;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17081;
                        case Properties::West::LOW:
                            return 17082;
                        case Properties::West::TALL:
                            return 17083;
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
                            return 17084;
                        case Properties::West::LOW:
                            return 17085;
                        case Properties::West::TALL:
                            return 17086;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17087;
                        case Properties::West::LOW:
                            return 17088;
                        case Properties::West::TALL:
                            return 17089;
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
                            return 17090;
                        case Properties::West::LOW:
                            return 17091;
                        case Properties::West::TALL:
                            return 17092;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 17093;
                        case Properties::West::LOW:
                            return 17094;
                        case Properties::West::TALL:
                            return 17095;
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
