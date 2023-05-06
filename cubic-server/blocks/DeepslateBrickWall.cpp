#include "DeepslateBrickWall.hpp"
namespace Blocks {
namespace DeepslateBrickWall {
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
                            return 22885;
                        case Properties::West::LOW:
                            return 22886;
                        case Properties::West::TALL:
                            return 22887;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22888;
                        case Properties::West::LOW:
                            return 22889;
                        case Properties::West::TALL:
                            return 22890;
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
                            return 22891;
                        case Properties::West::LOW:
                            return 22892;
                        case Properties::West::TALL:
                            return 22893;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22894;
                        case Properties::West::LOW:
                            return 22895;
                        case Properties::West::TALL:
                            return 22896;
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
                            return 22897;
                        case Properties::West::LOW:
                            return 22898;
                        case Properties::West::TALL:
                            return 22899;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22900;
                        case Properties::West::LOW:
                            return 22901;
                        case Properties::West::TALL:
                            return 22902;
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
                            return 22903;
                        case Properties::West::LOW:
                            return 22904;
                        case Properties::West::TALL:
                            return 22905;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22906;
                        case Properties::West::LOW:
                            return 22907;
                        case Properties::West::TALL:
                            return 22908;
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
                            return 22909;
                        case Properties::West::LOW:
                            return 22910;
                        case Properties::West::TALL:
                            return 22911;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22912;
                        case Properties::West::LOW:
                            return 22913;
                        case Properties::West::TALL:
                            return 22914;
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
                            return 22915;
                        case Properties::West::LOW:
                            return 22916;
                        case Properties::West::TALL:
                            return 22917;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22918;
                        case Properties::West::LOW:
                            return 22919;
                        case Properties::West::TALL:
                            return 22920;
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
                            return 22921;
                        case Properties::West::LOW:
                            return 22922;
                        case Properties::West::TALL:
                            return 22923;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22924;
                        case Properties::West::LOW:
                            return 22925;
                        case Properties::West::TALL:
                            return 22926;
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
                            return 22927;
                        case Properties::West::LOW:
                            return 22928;
                        case Properties::West::TALL:
                            return 22929;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22930;
                        case Properties::West::LOW:
                            return 22931;
                        case Properties::West::TALL:
                            return 22932;
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
                            return 22933;
                        case Properties::West::LOW:
                            return 22934;
                        case Properties::West::TALL:
                            return 22935;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22936;
                        case Properties::West::LOW:
                            return 22937;
                        case Properties::West::TALL:
                            return 22938;
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
                            return 22939;
                        case Properties::West::LOW:
                            return 22940;
                        case Properties::West::TALL:
                            return 22941;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22942;
                        case Properties::West::LOW:
                            return 22943;
                        case Properties::West::TALL:
                            return 22944;
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
                            return 22945;
                        case Properties::West::LOW:
                            return 22946;
                        case Properties::West::TALL:
                            return 22947;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22948;
                        case Properties::West::LOW:
                            return 22949;
                        case Properties::West::TALL:
                            return 22950;
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
                            return 22951;
                        case Properties::West::LOW:
                            return 22952;
                        case Properties::West::TALL:
                            return 22953;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22954;
                        case Properties::West::LOW:
                            return 22955;
                        case Properties::West::TALL:
                            return 22956;
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
                            return 22957;
                        case Properties::West::LOW:
                            return 22958;
                        case Properties::West::TALL:
                            return 22959;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22960;
                        case Properties::West::LOW:
                            return 22961;
                        case Properties::West::TALL:
                            return 22962;
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
                            return 22963;
                        case Properties::West::LOW:
                            return 22964;
                        case Properties::West::TALL:
                            return 22965;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22966;
                        case Properties::West::LOW:
                            return 22967;
                        case Properties::West::TALL:
                            return 22968;
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
                            return 22969;
                        case Properties::West::LOW:
                            return 22970;
                        case Properties::West::TALL:
                            return 22971;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22972;
                        case Properties::West::LOW:
                            return 22973;
                        case Properties::West::TALL:
                            return 22974;
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
                            return 22975;
                        case Properties::West::LOW:
                            return 22976;
                        case Properties::West::TALL:
                            return 22977;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22978;
                        case Properties::West::LOW:
                            return 22979;
                        case Properties::West::TALL:
                            return 22980;
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
                            return 22981;
                        case Properties::West::LOW:
                            return 22982;
                        case Properties::West::TALL:
                            return 22983;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22984;
                        case Properties::West::LOW:
                            return 22985;
                        case Properties::West::TALL:
                            return 22986;
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
                            return 22987;
                        case Properties::West::LOW:
                            return 22988;
                        case Properties::West::TALL:
                            return 22989;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22990;
                        case Properties::West::LOW:
                            return 22991;
                        case Properties::West::TALL:
                            return 22992;
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
                            return 22993;
                        case Properties::West::LOW:
                            return 22994;
                        case Properties::West::TALL:
                            return 22995;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22996;
                        case Properties::West::LOW:
                            return 22997;
                        case Properties::West::TALL:
                            return 22998;
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
                            return 22999;
                        case Properties::West::LOW:
                            return 23000;
                        case Properties::West::TALL:
                            return 23001;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23002;
                        case Properties::West::LOW:
                            return 23003;
                        case Properties::West::TALL:
                            return 23004;
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
                            return 23005;
                        case Properties::West::LOW:
                            return 23006;
                        case Properties::West::TALL:
                            return 23007;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23008;
                        case Properties::West::LOW:
                            return 23009;
                        case Properties::West::TALL:
                            return 23010;
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
                            return 23011;
                        case Properties::West::LOW:
                            return 23012;
                        case Properties::West::TALL:
                            return 23013;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23014;
                        case Properties::West::LOW:
                            return 23015;
                        case Properties::West::TALL:
                            return 23016;
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
                            return 23017;
                        case Properties::West::LOW:
                            return 23018;
                        case Properties::West::TALL:
                            return 23019;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23020;
                        case Properties::West::LOW:
                            return 23021;
                        case Properties::West::TALL:
                            return 23022;
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
                            return 23023;
                        case Properties::West::LOW:
                            return 23024;
                        case Properties::West::TALL:
                            return 23025;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23026;
                        case Properties::West::LOW:
                            return 23027;
                        case Properties::West::TALL:
                            return 23028;
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
                            return 23029;
                        case Properties::West::LOW:
                            return 23030;
                        case Properties::West::TALL:
                            return 23031;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23032;
                        case Properties::West::LOW:
                            return 23033;
                        case Properties::West::TALL:
                            return 23034;
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
                            return 23035;
                        case Properties::West::LOW:
                            return 23036;
                        case Properties::West::TALL:
                            return 23037;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23038;
                        case Properties::West::LOW:
                            return 23039;
                        case Properties::West::TALL:
                            return 23040;
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
                            return 23041;
                        case Properties::West::LOW:
                            return 23042;
                        case Properties::West::TALL:
                            return 23043;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23044;
                        case Properties::West::LOW:
                            return 23045;
                        case Properties::West::TALL:
                            return 23046;
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
                            return 23047;
                        case Properties::West::LOW:
                            return 23048;
                        case Properties::West::TALL:
                            return 23049;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23050;
                        case Properties::West::LOW:
                            return 23051;
                        case Properties::West::TALL:
                            return 23052;
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
                            return 23053;
                        case Properties::West::LOW:
                            return 23054;
                        case Properties::West::TALL:
                            return 23055;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23056;
                        case Properties::West::LOW:
                            return 23057;
                        case Properties::West::TALL:
                            return 23058;
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
                            return 23059;
                        case Properties::West::LOW:
                            return 23060;
                        case Properties::West::TALL:
                            return 23061;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23062;
                        case Properties::West::LOW:
                            return 23063;
                        case Properties::West::TALL:
                            return 23064;
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
                            return 23065;
                        case Properties::West::LOW:
                            return 23066;
                        case Properties::West::TALL:
                            return 23067;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23068;
                        case Properties::West::LOW:
                            return 23069;
                        case Properties::West::TALL:
                            return 23070;
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
                            return 23071;
                        case Properties::West::LOW:
                            return 23072;
                        case Properties::West::TALL:
                            return 23073;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23074;
                        case Properties::West::LOW:
                            return 23075;
                        case Properties::West::TALL:
                            return 23076;
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
                            return 23077;
                        case Properties::West::LOW:
                            return 23078;
                        case Properties::West::TALL:
                            return 23079;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23080;
                        case Properties::West::LOW:
                            return 23081;
                        case Properties::West::TALL:
                            return 23082;
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
                            return 23083;
                        case Properties::West::LOW:
                            return 23084;
                        case Properties::West::TALL:
                            return 23085;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23086;
                        case Properties::West::LOW:
                            return 23087;
                        case Properties::West::TALL:
                            return 23088;
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
                            return 23089;
                        case Properties::West::LOW:
                            return 23090;
                        case Properties::West::TALL:
                            return 23091;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23092;
                        case Properties::West::LOW:
                            return 23093;
                        case Properties::West::TALL:
                            return 23094;
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
                            return 23095;
                        case Properties::West::LOW:
                            return 23096;
                        case Properties::West::TALL:
                            return 23097;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23098;
                        case Properties::West::LOW:
                            return 23099;
                        case Properties::West::TALL:
                            return 23100;
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
                            return 23101;
                        case Properties::West::LOW:
                            return 23102;
                        case Properties::West::TALL:
                            return 23103;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23104;
                        case Properties::West::LOW:
                            return 23105;
                        case Properties::West::TALL:
                            return 23106;
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
                            return 23107;
                        case Properties::West::LOW:
                            return 23108;
                        case Properties::West::TALL:
                            return 23109;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23110;
                        case Properties::West::LOW:
                            return 23111;
                        case Properties::West::TALL:
                            return 23112;
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
                            return 23113;
                        case Properties::West::LOW:
                            return 23114;
                        case Properties::West::TALL:
                            return 23115;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23116;
                        case Properties::West::LOW:
                            return 23117;
                        case Properties::West::TALL:
                            return 23118;
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
                            return 23119;
                        case Properties::West::LOW:
                            return 23120;
                        case Properties::West::TALL:
                            return 23121;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23122;
                        case Properties::West::LOW:
                            return 23123;
                        case Properties::West::TALL:
                            return 23124;
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
                            return 23125;
                        case Properties::West::LOW:
                            return 23126;
                        case Properties::West::TALL:
                            return 23127;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23128;
                        case Properties::West::LOW:
                            return 23129;
                        case Properties::West::TALL:
                            return 23130;
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
                            return 23131;
                        case Properties::West::LOW:
                            return 23132;
                        case Properties::West::TALL:
                            return 23133;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23134;
                        case Properties::West::LOW:
                            return 23135;
                        case Properties::West::TALL:
                            return 23136;
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
                            return 23137;
                        case Properties::West::LOW:
                            return 23138;
                        case Properties::West::TALL:
                            return 23139;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23140;
                        case Properties::West::LOW:
                            return 23141;
                        case Properties::West::TALL:
                            return 23142;
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
                            return 23143;
                        case Properties::West::LOW:
                            return 23144;
                        case Properties::West::TALL:
                            return 23145;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23146;
                        case Properties::West::LOW:
                            return 23147;
                        case Properties::West::TALL:
                            return 23148;
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
                            return 23149;
                        case Properties::West::LOW:
                            return 23150;
                        case Properties::West::TALL:
                            return 23151;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23152;
                        case Properties::West::LOW:
                            return 23153;
                        case Properties::West::TALL:
                            return 23154;
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
                            return 23155;
                        case Properties::West::LOW:
                            return 23156;
                        case Properties::West::TALL:
                            return 23157;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23158;
                        case Properties::West::LOW:
                            return 23159;
                        case Properties::West::TALL:
                            return 23160;
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
                            return 23161;
                        case Properties::West::LOW:
                            return 23162;
                        case Properties::West::TALL:
                            return 23163;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23164;
                        case Properties::West::LOW:
                            return 23165;
                        case Properties::West::TALL:
                            return 23166;
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
                            return 23167;
                        case Properties::West::LOW:
                            return 23168;
                        case Properties::West::TALL:
                            return 23169;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23170;
                        case Properties::West::LOW:
                            return 23171;
                        case Properties::West::TALL:
                            return 23172;
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
                            return 23173;
                        case Properties::West::LOW:
                            return 23174;
                        case Properties::West::TALL:
                            return 23175;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23176;
                        case Properties::West::LOW:
                            return 23177;
                        case Properties::West::TALL:
                            return 23178;
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
                            return 23179;
                        case Properties::West::LOW:
                            return 23180;
                        case Properties::West::TALL:
                            return 23181;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23182;
                        case Properties::West::LOW:
                            return 23183;
                        case Properties::West::TALL:
                            return 23184;
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
                            return 23185;
                        case Properties::West::LOW:
                            return 23186;
                        case Properties::West::TALL:
                            return 23187;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23188;
                        case Properties::West::LOW:
                            return 23189;
                        case Properties::West::TALL:
                            return 23190;
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
                            return 23191;
                        case Properties::West::LOW:
                            return 23192;
                        case Properties::West::TALL:
                            return 23193;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23194;
                        case Properties::West::LOW:
                            return 23195;
                        case Properties::West::TALL:
                            return 23196;
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
                            return 23197;
                        case Properties::West::LOW:
                            return 23198;
                        case Properties::West::TALL:
                            return 23199;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23200;
                        case Properties::West::LOW:
                            return 23201;
                        case Properties::West::TALL:
                            return 23202;
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
                            return 23203;
                        case Properties::West::LOW:
                            return 23204;
                        case Properties::West::TALL:
                            return 23205;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 23206;
                        case Properties::West::LOW:
                            return 23207;
                        case Properties::West::TALL:
                            return 23208;
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
