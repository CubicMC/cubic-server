#include "GraniteWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GraniteWall {
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
                                    return 14828;
                                case Properties::West::LOW:
                                    return 14829;
                                case Properties::West::TALL:
                                    return 14830;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14831;
                                case Properties::West::LOW:
                                    return 14832;
                                case Properties::West::TALL:
                                    return 14833;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14834;
                                case Properties::West::LOW:
                                    return 14835;
                                case Properties::West::TALL:
                                    return 14836;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14837;
                                case Properties::West::LOW:
                                    return 14838;
                                case Properties::West::TALL:
                                    return 14839;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14840;
                                case Properties::West::LOW:
                                    return 14841;
                                case Properties::West::TALL:
                                    return 14842;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14843;
                                case Properties::West::LOW:
                                    return 14844;
                                case Properties::West::TALL:
                                    return 14845;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14846;
                                case Properties::West::LOW:
                                    return 14847;
                                case Properties::West::TALL:
                                    return 14848;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14849;
                                case Properties::West::LOW:
                                    return 14850;
                                case Properties::West::TALL:
                                    return 14851;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14852;
                                case Properties::West::LOW:
                                    return 14853;
                                case Properties::West::TALL:
                                    return 14854;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14855;
                                case Properties::West::LOW:
                                    return 14856;
                                case Properties::West::TALL:
                                    return 14857;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14858;
                                case Properties::West::LOW:
                                    return 14859;
                                case Properties::West::TALL:
                                    return 14860;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14861;
                                case Properties::West::LOW:
                                    return 14862;
                                case Properties::West::TALL:
                                    return 14863;
                                }
                            }
                        }
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
                                    return 14864;
                                case Properties::West::LOW:
                                    return 14865;
                                case Properties::West::TALL:
                                    return 14866;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14867;
                                case Properties::West::LOW:
                                    return 14868;
                                case Properties::West::TALL:
                                    return 14869;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14870;
                                case Properties::West::LOW:
                                    return 14871;
                                case Properties::West::TALL:
                                    return 14872;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14873;
                                case Properties::West::LOW:
                                    return 14874;
                                case Properties::West::TALL:
                                    return 14875;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14876;
                                case Properties::West::LOW:
                                    return 14877;
                                case Properties::West::TALL:
                                    return 14878;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14879;
                                case Properties::West::LOW:
                                    return 14880;
                                case Properties::West::TALL:
                                    return 14881;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14882;
                                case Properties::West::LOW:
                                    return 14883;
                                case Properties::West::TALL:
                                    return 14884;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14885;
                                case Properties::West::LOW:
                                    return 14886;
                                case Properties::West::TALL:
                                    return 14887;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14888;
                                case Properties::West::LOW:
                                    return 14889;
                                case Properties::West::TALL:
                                    return 14890;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14891;
                                case Properties::West::LOW:
                                    return 14892;
                                case Properties::West::TALL:
                                    return 14893;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14894;
                                case Properties::West::LOW:
                                    return 14895;
                                case Properties::West::TALL:
                                    return 14896;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14897;
                                case Properties::West::LOW:
                                    return 14898;
                                case Properties::West::TALL:
                                    return 14899;
                                }
                            }
                        }
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
                                    return 14900;
                                case Properties::West::LOW:
                                    return 14901;
                                case Properties::West::TALL:
                                    return 14902;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14903;
                                case Properties::West::LOW:
                                    return 14904;
                                case Properties::West::TALL:
                                    return 14905;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14906;
                                case Properties::West::LOW:
                                    return 14907;
                                case Properties::West::TALL:
                                    return 14908;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14909;
                                case Properties::West::LOW:
                                    return 14910;
                                case Properties::West::TALL:
                                    return 14911;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14912;
                                case Properties::West::LOW:
                                    return 14913;
                                case Properties::West::TALL:
                                    return 14914;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14915;
                                case Properties::West::LOW:
                                    return 14916;
                                case Properties::West::TALL:
                                    return 14917;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14918;
                                case Properties::West::LOW:
                                    return 14919;
                                case Properties::West::TALL:
                                    return 14920;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14921;
                                case Properties::West::LOW:
                                    return 14922;
                                case Properties::West::TALL:
                                    return 14923;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14924;
                                case Properties::West::LOW:
                                    return 14925;
                                case Properties::West::TALL:
                                    return 14926;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14927;
                                case Properties::West::LOW:
                                    return 14928;
                                case Properties::West::TALL:
                                    return 14929;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14930;
                                case Properties::West::LOW:
                                    return 14931;
                                case Properties::West::TALL:
                                    return 14932;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14933;
                                case Properties::West::LOW:
                                    return 14934;
                                case Properties::West::TALL:
                                    return 14935;
                                }
                            }
                        }
                    }
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
                                    return 14936;
                                case Properties::West::LOW:
                                    return 14937;
                                case Properties::West::TALL:
                                    return 14938;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14939;
                                case Properties::West::LOW:
                                    return 14940;
                                case Properties::West::TALL:
                                    return 14941;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14942;
                                case Properties::West::LOW:
                                    return 14943;
                                case Properties::West::TALL:
                                    return 14944;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14945;
                                case Properties::West::LOW:
                                    return 14946;
                                case Properties::West::TALL:
                                    return 14947;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14948;
                                case Properties::West::LOW:
                                    return 14949;
                                case Properties::West::TALL:
                                    return 14950;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14951;
                                case Properties::West::LOW:
                                    return 14952;
                                case Properties::West::TALL:
                                    return 14953;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14954;
                                case Properties::West::LOW:
                                    return 14955;
                                case Properties::West::TALL:
                                    return 14956;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14957;
                                case Properties::West::LOW:
                                    return 14958;
                                case Properties::West::TALL:
                                    return 14959;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14960;
                                case Properties::West::LOW:
                                    return 14961;
                                case Properties::West::TALL:
                                    return 14962;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14963;
                                case Properties::West::LOW:
                                    return 14964;
                                case Properties::West::TALL:
                                    return 14965;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14966;
                                case Properties::West::LOW:
                                    return 14967;
                                case Properties::West::TALL:
                                    return 14968;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14969;
                                case Properties::West::LOW:
                                    return 14970;
                                case Properties::West::TALL:
                                    return 14971;
                                }
                            }
                        }
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
                                    return 14972;
                                case Properties::West::LOW:
                                    return 14973;
                                case Properties::West::TALL:
                                    return 14974;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14975;
                                case Properties::West::LOW:
                                    return 14976;
                                case Properties::West::TALL:
                                    return 14977;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14978;
                                case Properties::West::LOW:
                                    return 14979;
                                case Properties::West::TALL:
                                    return 14980;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14981;
                                case Properties::West::LOW:
                                    return 14982;
                                case Properties::West::TALL:
                                    return 14983;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14984;
                                case Properties::West::LOW:
                                    return 14985;
                                case Properties::West::TALL:
                                    return 14986;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14987;
                                case Properties::West::LOW:
                                    return 14988;
                                case Properties::West::TALL:
                                    return 14989;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14990;
                                case Properties::West::LOW:
                                    return 14991;
                                case Properties::West::TALL:
                                    return 14992;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14993;
                                case Properties::West::LOW:
                                    return 14994;
                                case Properties::West::TALL:
                                    return 14995;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14996;
                                case Properties::West::LOW:
                                    return 14997;
                                case Properties::West::TALL:
                                    return 14998;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14999;
                                case Properties::West::LOW:
                                    return 15000;
                                case Properties::West::TALL:
                                    return 15001;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15002;
                                case Properties::West::LOW:
                                    return 15003;
                                case Properties::West::TALL:
                                    return 15004;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15005;
                                case Properties::West::LOW:
                                    return 15006;
                                case Properties::West::TALL:
                                    return 15007;
                                }
                            }
                        }
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
                                    return 15008;
                                case Properties::West::LOW:
                                    return 15009;
                                case Properties::West::TALL:
                                    return 15010;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15011;
                                case Properties::West::LOW:
                                    return 15012;
                                case Properties::West::TALL:
                                    return 15013;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15014;
                                case Properties::West::LOW:
                                    return 15015;
                                case Properties::West::TALL:
                                    return 15016;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15017;
                                case Properties::West::LOW:
                                    return 15018;
                                case Properties::West::TALL:
                                    return 15019;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15020;
                                case Properties::West::LOW:
                                    return 15021;
                                case Properties::West::TALL:
                                    return 15022;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15023;
                                case Properties::West::LOW:
                                    return 15024;
                                case Properties::West::TALL:
                                    return 15025;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15026;
                                case Properties::West::LOW:
                                    return 15027;
                                case Properties::West::TALL:
                                    return 15028;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15029;
                                case Properties::West::LOW:
                                    return 15030;
                                case Properties::West::TALL:
                                    return 15031;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15032;
                                case Properties::West::LOW:
                                    return 15033;
                                case Properties::West::TALL:
                                    return 15034;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15035;
                                case Properties::West::LOW:
                                    return 15036;
                                case Properties::West::TALL:
                                    return 15037;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15038;
                                case Properties::West::LOW:
                                    return 15039;
                                case Properties::West::TALL:
                                    return 15040;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15041;
                                case Properties::West::LOW:
                                    return 15042;
                                case Properties::West::TALL:
                                    return 15043;
                                }
                            }
                        }
                    }
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
                                    return 15044;
                                case Properties::West::LOW:
                                    return 15045;
                                case Properties::West::TALL:
                                    return 15046;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15047;
                                case Properties::West::LOW:
                                    return 15048;
                                case Properties::West::TALL:
                                    return 15049;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15050;
                                case Properties::West::LOW:
                                    return 15051;
                                case Properties::West::TALL:
                                    return 15052;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15053;
                                case Properties::West::LOW:
                                    return 15054;
                                case Properties::West::TALL:
                                    return 15055;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15056;
                                case Properties::West::LOW:
                                    return 15057;
                                case Properties::West::TALL:
                                    return 15058;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15059;
                                case Properties::West::LOW:
                                    return 15060;
                                case Properties::West::TALL:
                                    return 15061;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15062;
                                case Properties::West::LOW:
                                    return 15063;
                                case Properties::West::TALL:
                                    return 15064;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15065;
                                case Properties::West::LOW:
                                    return 15066;
                                case Properties::West::TALL:
                                    return 15067;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15068;
                                case Properties::West::LOW:
                                    return 15069;
                                case Properties::West::TALL:
                                    return 15070;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15071;
                                case Properties::West::LOW:
                                    return 15072;
                                case Properties::West::TALL:
                                    return 15073;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15074;
                                case Properties::West::LOW:
                                    return 15075;
                                case Properties::West::TALL:
                                    return 15076;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15077;
                                case Properties::West::LOW:
                                    return 15078;
                                case Properties::West::TALL:
                                    return 15079;
                                }
                            }
                        }
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
                                    return 15080;
                                case Properties::West::LOW:
                                    return 15081;
                                case Properties::West::TALL:
                                    return 15082;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15083;
                                case Properties::West::LOW:
                                    return 15084;
                                case Properties::West::TALL:
                                    return 15085;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15086;
                                case Properties::West::LOW:
                                    return 15087;
                                case Properties::West::TALL:
                                    return 15088;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15089;
                                case Properties::West::LOW:
                                    return 15090;
                                case Properties::West::TALL:
                                    return 15091;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15092;
                                case Properties::West::LOW:
                                    return 15093;
                                case Properties::West::TALL:
                                    return 15094;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15095;
                                case Properties::West::LOW:
                                    return 15096;
                                case Properties::West::TALL:
                                    return 15097;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15098;
                                case Properties::West::LOW:
                                    return 15099;
                                case Properties::West::TALL:
                                    return 15100;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15101;
                                case Properties::West::LOW:
                                    return 15102;
                                case Properties::West::TALL:
                                    return 15103;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15104;
                                case Properties::West::LOW:
                                    return 15105;
                                case Properties::West::TALL:
                                    return 15106;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15107;
                                case Properties::West::LOW:
                                    return 15108;
                                case Properties::West::TALL:
                                    return 15109;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15110;
                                case Properties::West::LOW:
                                    return 15111;
                                case Properties::West::TALL:
                                    return 15112;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15113;
                                case Properties::West::LOW:
                                    return 15114;
                                case Properties::West::TALL:
                                    return 15115;
                                }
                            }
                        }
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
                                    return 15116;
                                case Properties::West::LOW:
                                    return 15117;
                                case Properties::West::TALL:
                                    return 15118;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15119;
                                case Properties::West::LOW:
                                    return 15120;
                                case Properties::West::TALL:
                                    return 15121;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15122;
                                case Properties::West::LOW:
                                    return 15123;
                                case Properties::West::TALL:
                                    return 15124;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15125;
                                case Properties::West::LOW:
                                    return 15126;
                                case Properties::West::TALL:
                                    return 15127;
                                }
                            }
                        }
                    case Properties::South::LOW:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15128;
                                case Properties::West::LOW:
                                    return 15129;
                                case Properties::West::TALL:
                                    return 15130;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15131;
                                case Properties::West::LOW:
                                    return 15132;
                                case Properties::West::TALL:
                                    return 15133;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15134;
                                case Properties::West::LOW:
                                    return 15135;
                                case Properties::West::TALL:
                                    return 15136;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15137;
                                case Properties::West::LOW:
                                    return 15138;
                                case Properties::West::TALL:
                                    return 15139;
                                }
                            }
                        }
                    case Properties::South::TALL:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15140;
                                case Properties::West::LOW:
                                    return 15141;
                                case Properties::West::TALL:
                                    return 15142;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15143;
                                case Properties::West::LOW:
                                    return 15144;
                                case Properties::West::TALL:
                                    return 15145;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15146;
                                case Properties::West::LOW:
                                    return 15147;
                                case Properties::West::TALL:
                                    return 15148;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15149;
                                case Properties::West::LOW:
                                    return 15150;
                                case Properties::West::TALL:
                                    return 15151;
                                }
                            }
                        }
                    }
                }
            }
            return 0;
        }
    }

}
