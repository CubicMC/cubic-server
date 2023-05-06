#include "PrismarineWall.hpp"
namespace Blocks {
namespace PrismarineWall {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west)
{
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
                            return 13856;
                        case Properties::West::LOW:
                            return 13857;
                        case Properties::West::TALL:
                            return 13858;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13859;
                        case Properties::West::LOW:
                            return 13860;
                        case Properties::West::TALL:
                            return 13861;
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
                            return 13862;
                        case Properties::West::LOW:
                            return 13863;
                        case Properties::West::TALL:
                            return 13864;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13865;
                        case Properties::West::LOW:
                            return 13866;
                        case Properties::West::TALL:
                            return 13867;
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
                            return 13868;
                        case Properties::West::LOW:
                            return 13869;
                        case Properties::West::TALL:
                            return 13870;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13871;
                        case Properties::West::LOW:
                            return 13872;
                        case Properties::West::TALL:
                            return 13873;
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
                            return 13874;
                        case Properties::West::LOW:
                            return 13875;
                        case Properties::West::TALL:
                            return 13876;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13877;
                        case Properties::West::LOW:
                            return 13878;
                        case Properties::West::TALL:
                            return 13879;
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
                            return 13880;
                        case Properties::West::LOW:
                            return 13881;
                        case Properties::West::TALL:
                            return 13882;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13883;
                        case Properties::West::LOW:
                            return 13884;
                        case Properties::West::TALL:
                            return 13885;
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
                            return 13886;
                        case Properties::West::LOW:
                            return 13887;
                        case Properties::West::TALL:
                            return 13888;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13889;
                        case Properties::West::LOW:
                            return 13890;
                        case Properties::West::TALL:
                            return 13891;
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
                            return 13892;
                        case Properties::West::LOW:
                            return 13893;
                        case Properties::West::TALL:
                            return 13894;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13895;
                        case Properties::West::LOW:
                            return 13896;
                        case Properties::West::TALL:
                            return 13897;
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
                            return 13898;
                        case Properties::West::LOW:
                            return 13899;
                        case Properties::West::TALL:
                            return 13900;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13901;
                        case Properties::West::LOW:
                            return 13902;
                        case Properties::West::TALL:
                            return 13903;
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
                            return 13904;
                        case Properties::West::LOW:
                            return 13905;
                        case Properties::West::TALL:
                            return 13906;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13907;
                        case Properties::West::LOW:
                            return 13908;
                        case Properties::West::TALL:
                            return 13909;
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
                            return 13910;
                        case Properties::West::LOW:
                            return 13911;
                        case Properties::West::TALL:
                            return 13912;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13913;
                        case Properties::West::LOW:
                            return 13914;
                        case Properties::West::TALL:
                            return 13915;
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
                            return 13916;
                        case Properties::West::LOW:
                            return 13917;
                        case Properties::West::TALL:
                            return 13918;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13919;
                        case Properties::West::LOW:
                            return 13920;
                        case Properties::West::TALL:
                            return 13921;
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
                            return 13922;
                        case Properties::West::LOW:
                            return 13923;
                        case Properties::West::TALL:
                            return 13924;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13925;
                        case Properties::West::LOW:
                            return 13926;
                        case Properties::West::TALL:
                            return 13927;
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
                            return 13928;
                        case Properties::West::LOW:
                            return 13929;
                        case Properties::West::TALL:
                            return 13930;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13931;
                        case Properties::West::LOW:
                            return 13932;
                        case Properties::West::TALL:
                            return 13933;
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
                            return 13934;
                        case Properties::West::LOW:
                            return 13935;
                        case Properties::West::TALL:
                            return 13936;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13937;
                        case Properties::West::LOW:
                            return 13938;
                        case Properties::West::TALL:
                            return 13939;
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
                            return 13940;
                        case Properties::West::LOW:
                            return 13941;
                        case Properties::West::TALL:
                            return 13942;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13943;
                        case Properties::West::LOW:
                            return 13944;
                        case Properties::West::TALL:
                            return 13945;
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
                            return 13946;
                        case Properties::West::LOW:
                            return 13947;
                        case Properties::West::TALL:
                            return 13948;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13949;
                        case Properties::West::LOW:
                            return 13950;
                        case Properties::West::TALL:
                            return 13951;
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
                            return 13952;
                        case Properties::West::LOW:
                            return 13953;
                        case Properties::West::TALL:
                            return 13954;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13955;
                        case Properties::West::LOW:
                            return 13956;
                        case Properties::West::TALL:
                            return 13957;
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
                            return 13958;
                        case Properties::West::LOW:
                            return 13959;
                        case Properties::West::TALL:
                            return 13960;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13961;
                        case Properties::West::LOW:
                            return 13962;
                        case Properties::West::TALL:
                            return 13963;
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
                            return 13964;
                        case Properties::West::LOW:
                            return 13965;
                        case Properties::West::TALL:
                            return 13966;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13967;
                        case Properties::West::LOW:
                            return 13968;
                        case Properties::West::TALL:
                            return 13969;
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
                            return 13970;
                        case Properties::West::LOW:
                            return 13971;
                        case Properties::West::TALL:
                            return 13972;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13973;
                        case Properties::West::LOW:
                            return 13974;
                        case Properties::West::TALL:
                            return 13975;
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
                            return 13976;
                        case Properties::West::LOW:
                            return 13977;
                        case Properties::West::TALL:
                            return 13978;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13979;
                        case Properties::West::LOW:
                            return 13980;
                        case Properties::West::TALL:
                            return 13981;
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
                            return 13982;
                        case Properties::West::LOW:
                            return 13983;
                        case Properties::West::TALL:
                            return 13984;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13985;
                        case Properties::West::LOW:
                            return 13986;
                        case Properties::West::TALL:
                            return 13987;
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
                            return 13988;
                        case Properties::West::LOW:
                            return 13989;
                        case Properties::West::TALL:
                            return 13990;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13991;
                        case Properties::West::LOW:
                            return 13992;
                        case Properties::West::TALL:
                            return 13993;
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
                            return 13994;
                        case Properties::West::LOW:
                            return 13995;
                        case Properties::West::TALL:
                            return 13996;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 13997;
                        case Properties::West::LOW:
                            return 13998;
                        case Properties::West::TALL:
                            return 13999;
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
                            return 14000;
                        case Properties::West::LOW:
                            return 14001;
                        case Properties::West::TALL:
                            return 14002;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14003;
                        case Properties::West::LOW:
                            return 14004;
                        case Properties::West::TALL:
                            return 14005;
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
                            return 14006;
                        case Properties::West::LOW:
                            return 14007;
                        case Properties::West::TALL:
                            return 14008;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14009;
                        case Properties::West::LOW:
                            return 14010;
                        case Properties::West::TALL:
                            return 14011;
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
                            return 14012;
                        case Properties::West::LOW:
                            return 14013;
                        case Properties::West::TALL:
                            return 14014;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14015;
                        case Properties::West::LOW:
                            return 14016;
                        case Properties::West::TALL:
                            return 14017;
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
                            return 14018;
                        case Properties::West::LOW:
                            return 14019;
                        case Properties::West::TALL:
                            return 14020;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14021;
                        case Properties::West::LOW:
                            return 14022;
                        case Properties::West::TALL:
                            return 14023;
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
                            return 14024;
                        case Properties::West::LOW:
                            return 14025;
                        case Properties::West::TALL:
                            return 14026;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14027;
                        case Properties::West::LOW:
                            return 14028;
                        case Properties::West::TALL:
                            return 14029;
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
                            return 14030;
                        case Properties::West::LOW:
                            return 14031;
                        case Properties::West::TALL:
                            return 14032;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14033;
                        case Properties::West::LOW:
                            return 14034;
                        case Properties::West::TALL:
                            return 14035;
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
                            return 14036;
                        case Properties::West::LOW:
                            return 14037;
                        case Properties::West::TALL:
                            return 14038;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14039;
                        case Properties::West::LOW:
                            return 14040;
                        case Properties::West::TALL:
                            return 14041;
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
                            return 14042;
                        case Properties::West::LOW:
                            return 14043;
                        case Properties::West::TALL:
                            return 14044;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14045;
                        case Properties::West::LOW:
                            return 14046;
                        case Properties::West::TALL:
                            return 14047;
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
                            return 14048;
                        case Properties::West::LOW:
                            return 14049;
                        case Properties::West::TALL:
                            return 14050;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14051;
                        case Properties::West::LOW:
                            return 14052;
                        case Properties::West::TALL:
                            return 14053;
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
                            return 14054;
                        case Properties::West::LOW:
                            return 14055;
                        case Properties::West::TALL:
                            return 14056;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14057;
                        case Properties::West::LOW:
                            return 14058;
                        case Properties::West::TALL:
                            return 14059;
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
                            return 14060;
                        case Properties::West::LOW:
                            return 14061;
                        case Properties::West::TALL:
                            return 14062;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14063;
                        case Properties::West::LOW:
                            return 14064;
                        case Properties::West::TALL:
                            return 14065;
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
                            return 14066;
                        case Properties::West::LOW:
                            return 14067;
                        case Properties::West::TALL:
                            return 14068;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14069;
                        case Properties::West::LOW:
                            return 14070;
                        case Properties::West::TALL:
                            return 14071;
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
                            return 14072;
                        case Properties::West::LOW:
                            return 14073;
                        case Properties::West::TALL:
                            return 14074;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14075;
                        case Properties::West::LOW:
                            return 14076;
                        case Properties::West::TALL:
                            return 14077;
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
                            return 14078;
                        case Properties::West::LOW:
                            return 14079;
                        case Properties::West::TALL:
                            return 14080;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14081;
                        case Properties::West::LOW:
                            return 14082;
                        case Properties::West::TALL:
                            return 14083;
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
                            return 14084;
                        case Properties::West::LOW:
                            return 14085;
                        case Properties::West::TALL:
                            return 14086;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14087;
                        case Properties::West::LOW:
                            return 14088;
                        case Properties::West::TALL:
                            return 14089;
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
                            return 14090;
                        case Properties::West::LOW:
                            return 14091;
                        case Properties::West::TALL:
                            return 14092;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14093;
                        case Properties::West::LOW:
                            return 14094;
                        case Properties::West::TALL:
                            return 14095;
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
                            return 14096;
                        case Properties::West::LOW:
                            return 14097;
                        case Properties::West::TALL:
                            return 14098;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14099;
                        case Properties::West::LOW:
                            return 14100;
                        case Properties::West::TALL:
                            return 14101;
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
                            return 14102;
                        case Properties::West::LOW:
                            return 14103;
                        case Properties::West::TALL:
                            return 14104;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14105;
                        case Properties::West::LOW:
                            return 14106;
                        case Properties::West::TALL:
                            return 14107;
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
                            return 14108;
                        case Properties::West::LOW:
                            return 14109;
                        case Properties::West::TALL:
                            return 14110;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14111;
                        case Properties::West::LOW:
                            return 14112;
                        case Properties::West::TALL:
                            return 14113;
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
                            return 14114;
                        case Properties::West::LOW:
                            return 14115;
                        case Properties::West::TALL:
                            return 14116;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14117;
                        case Properties::West::LOW:
                            return 14118;
                        case Properties::West::TALL:
                            return 14119;
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
                            return 14120;
                        case Properties::West::LOW:
                            return 14121;
                        case Properties::West::TALL:
                            return 14122;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14123;
                        case Properties::West::LOW:
                            return 14124;
                        case Properties::West::TALL:
                            return 14125;
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
                            return 14126;
                        case Properties::West::LOW:
                            return 14127;
                        case Properties::West::TALL:
                            return 14128;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14129;
                        case Properties::West::LOW:
                            return 14130;
                        case Properties::West::TALL:
                            return 14131;
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
                            return 14132;
                        case Properties::West::LOW:
                            return 14133;
                        case Properties::West::TALL:
                            return 14134;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14135;
                        case Properties::West::LOW:
                            return 14136;
                        case Properties::West::TALL:
                            return 14137;
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
                            return 14138;
                        case Properties::West::LOW:
                            return 14139;
                        case Properties::West::TALL:
                            return 14140;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14141;
                        case Properties::West::LOW:
                            return 14142;
                        case Properties::West::TALL:
                            return 14143;
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
                            return 14144;
                        case Properties::West::LOW:
                            return 14145;
                        case Properties::West::TALL:
                            return 14146;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14147;
                        case Properties::West::LOW:
                            return 14148;
                        case Properties::West::TALL:
                            return 14149;
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
                            return 14150;
                        case Properties::West::LOW:
                            return 14151;
                        case Properties::West::TALL:
                            return 14152;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14153;
                        case Properties::West::LOW:
                            return 14154;
                        case Properties::West::TALL:
                            return 14155;
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
                            return 14156;
                        case Properties::West::LOW:
                            return 14157;
                        case Properties::West::TALL:
                            return 14158;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14159;
                        case Properties::West::LOW:
                            return 14160;
                        case Properties::West::TALL:
                            return 14161;
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
                            return 14162;
                        case Properties::West::LOW:
                            return 14163;
                        case Properties::West::TALL:
                            return 14164;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14165;
                        case Properties::West::LOW:
                            return 14166;
                        case Properties::West::TALL:
                            return 14167;
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
                            return 14168;
                        case Properties::West::LOW:
                            return 14169;
                        case Properties::West::TALL:
                            return 14170;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14171;
                        case Properties::West::LOW:
                            return 14172;
                        case Properties::West::TALL:
                            return 14173;
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
                            return 14174;
                        case Properties::West::LOW:
                            return 14175;
                        case Properties::West::TALL:
                            return 14176;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 14177;
                        case Properties::West::LOW:
                            return 14178;
                        case Properties::West::TALL:
                            return 14179;
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
