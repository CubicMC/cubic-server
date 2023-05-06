#include "StoneBrickWall.hpp"
namespace Blocks {
    namespace StoneBrickWall {
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
                                    return 15152;
                                case Properties::West::LOW:
                                    return 15153;
                                case Properties::West::TALL:
                                    return 15154;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15155;
                                case Properties::West::LOW:
                                    return 15156;
                                case Properties::West::TALL:
                                    return 15157;
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
                                    return 15158;
                                case Properties::West::LOW:
                                    return 15159;
                                case Properties::West::TALL:
                                    return 15160;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15161;
                                case Properties::West::LOW:
                                    return 15162;
                                case Properties::West::TALL:
                                    return 15163;
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
                                    return 15164;
                                case Properties::West::LOW:
                                    return 15165;
                                case Properties::West::TALL:
                                    return 15166;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15167;
                                case Properties::West::LOW:
                                    return 15168;
                                case Properties::West::TALL:
                                    return 15169;
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
                                    return 15170;
                                case Properties::West::LOW:
                                    return 15171;
                                case Properties::West::TALL:
                                    return 15172;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15173;
                                case Properties::West::LOW:
                                    return 15174;
                                case Properties::West::TALL:
                                    return 15175;
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
                                    return 15176;
                                case Properties::West::LOW:
                                    return 15177;
                                case Properties::West::TALL:
                                    return 15178;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15179;
                                case Properties::West::LOW:
                                    return 15180;
                                case Properties::West::TALL:
                                    return 15181;
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
                                    return 15182;
                                case Properties::West::LOW:
                                    return 15183;
                                case Properties::West::TALL:
                                    return 15184;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15185;
                                case Properties::West::LOW:
                                    return 15186;
                                case Properties::West::TALL:
                                    return 15187;
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
                                    return 15188;
                                case Properties::West::LOW:
                                    return 15189;
                                case Properties::West::TALL:
                                    return 15190;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15191;
                                case Properties::West::LOW:
                                    return 15192;
                                case Properties::West::TALL:
                                    return 15193;
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
                                    return 15194;
                                case Properties::West::LOW:
                                    return 15195;
                                case Properties::West::TALL:
                                    return 15196;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15197;
                                case Properties::West::LOW:
                                    return 15198;
                                case Properties::West::TALL:
                                    return 15199;
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
                                    return 15200;
                                case Properties::West::LOW:
                                    return 15201;
                                case Properties::West::TALL:
                                    return 15202;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15203;
                                case Properties::West::LOW:
                                    return 15204;
                                case Properties::West::TALL:
                                    return 15205;
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
                                    return 15206;
                                case Properties::West::LOW:
                                    return 15207;
                                case Properties::West::TALL:
                                    return 15208;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15209;
                                case Properties::West::LOW:
                                    return 15210;
                                case Properties::West::TALL:
                                    return 15211;
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
                                    return 15212;
                                case Properties::West::LOW:
                                    return 15213;
                                case Properties::West::TALL:
                                    return 15214;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15215;
                                case Properties::West::LOW:
                                    return 15216;
                                case Properties::West::TALL:
                                    return 15217;
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
                                    return 15218;
                                case Properties::West::LOW:
                                    return 15219;
                                case Properties::West::TALL:
                                    return 15220;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15221;
                                case Properties::West::LOW:
                                    return 15222;
                                case Properties::West::TALL:
                                    return 15223;
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
                                    return 15224;
                                case Properties::West::LOW:
                                    return 15225;
                                case Properties::West::TALL:
                                    return 15226;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15227;
                                case Properties::West::LOW:
                                    return 15228;
                                case Properties::West::TALL:
                                    return 15229;
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
                                    return 15230;
                                case Properties::West::LOW:
                                    return 15231;
                                case Properties::West::TALL:
                                    return 15232;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15233;
                                case Properties::West::LOW:
                                    return 15234;
                                case Properties::West::TALL:
                                    return 15235;
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
                                    return 15236;
                                case Properties::West::LOW:
                                    return 15237;
                                case Properties::West::TALL:
                                    return 15238;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15239;
                                case Properties::West::LOW:
                                    return 15240;
                                case Properties::West::TALL:
                                    return 15241;
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
                                    return 15242;
                                case Properties::West::LOW:
                                    return 15243;
                                case Properties::West::TALL:
                                    return 15244;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15245;
                                case Properties::West::LOW:
                                    return 15246;
                                case Properties::West::TALL:
                                    return 15247;
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
                                    return 15248;
                                case Properties::West::LOW:
                                    return 15249;
                                case Properties::West::TALL:
                                    return 15250;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15251;
                                case Properties::West::LOW:
                                    return 15252;
                                case Properties::West::TALL:
                                    return 15253;
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
                                    return 15254;
                                case Properties::West::LOW:
                                    return 15255;
                                case Properties::West::TALL:
                                    return 15256;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15257;
                                case Properties::West::LOW:
                                    return 15258;
                                case Properties::West::TALL:
                                    return 15259;
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
                                    return 15260;
                                case Properties::West::LOW:
                                    return 15261;
                                case Properties::West::TALL:
                                    return 15262;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15263;
                                case Properties::West::LOW:
                                    return 15264;
                                case Properties::West::TALL:
                                    return 15265;
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
                                    return 15266;
                                case Properties::West::LOW:
                                    return 15267;
                                case Properties::West::TALL:
                                    return 15268;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15269;
                                case Properties::West::LOW:
                                    return 15270;
                                case Properties::West::TALL:
                                    return 15271;
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
                                    return 15272;
                                case Properties::West::LOW:
                                    return 15273;
                                case Properties::West::TALL:
                                    return 15274;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15275;
                                case Properties::West::LOW:
                                    return 15276;
                                case Properties::West::TALL:
                                    return 15277;
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
                                    return 15278;
                                case Properties::West::LOW:
                                    return 15279;
                                case Properties::West::TALL:
                                    return 15280;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15281;
                                case Properties::West::LOW:
                                    return 15282;
                                case Properties::West::TALL:
                                    return 15283;
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
                                    return 15284;
                                case Properties::West::LOW:
                                    return 15285;
                                case Properties::West::TALL:
                                    return 15286;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15287;
                                case Properties::West::LOW:
                                    return 15288;
                                case Properties::West::TALL:
                                    return 15289;
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
                                    return 15290;
                                case Properties::West::LOW:
                                    return 15291;
                                case Properties::West::TALL:
                                    return 15292;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15293;
                                case Properties::West::LOW:
                                    return 15294;
                                case Properties::West::TALL:
                                    return 15295;
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
                                    return 15296;
                                case Properties::West::LOW:
                                    return 15297;
                                case Properties::West::TALL:
                                    return 15298;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15299;
                                case Properties::West::LOW:
                                    return 15300;
                                case Properties::West::TALL:
                                    return 15301;
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
                                    return 15302;
                                case Properties::West::LOW:
                                    return 15303;
                                case Properties::West::TALL:
                                    return 15304;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15305;
                                case Properties::West::LOW:
                                    return 15306;
                                case Properties::West::TALL:
                                    return 15307;
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
                                    return 15308;
                                case Properties::West::LOW:
                                    return 15309;
                                case Properties::West::TALL:
                                    return 15310;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15311;
                                case Properties::West::LOW:
                                    return 15312;
                                case Properties::West::TALL:
                                    return 15313;
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
                                    return 15314;
                                case Properties::West::LOW:
                                    return 15315;
                                case Properties::West::TALL:
                                    return 15316;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15317;
                                case Properties::West::LOW:
                                    return 15318;
                                case Properties::West::TALL:
                                    return 15319;
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
                                    return 15320;
                                case Properties::West::LOW:
                                    return 15321;
                                case Properties::West::TALL:
                                    return 15322;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15323;
                                case Properties::West::LOW:
                                    return 15324;
                                case Properties::West::TALL:
                                    return 15325;
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
                                    return 15326;
                                case Properties::West::LOW:
                                    return 15327;
                                case Properties::West::TALL:
                                    return 15328;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15329;
                                case Properties::West::LOW:
                                    return 15330;
                                case Properties::West::TALL:
                                    return 15331;
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
                                    return 15332;
                                case Properties::West::LOW:
                                    return 15333;
                                case Properties::West::TALL:
                                    return 15334;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15335;
                                case Properties::West::LOW:
                                    return 15336;
                                case Properties::West::TALL:
                                    return 15337;
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
                                    return 15338;
                                case Properties::West::LOW:
                                    return 15339;
                                case Properties::West::TALL:
                                    return 15340;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15341;
                                case Properties::West::LOW:
                                    return 15342;
                                case Properties::West::TALL:
                                    return 15343;
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
                                    return 15344;
                                case Properties::West::LOW:
                                    return 15345;
                                case Properties::West::TALL:
                                    return 15346;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15347;
                                case Properties::West::LOW:
                                    return 15348;
                                case Properties::West::TALL:
                                    return 15349;
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
                                    return 15350;
                                case Properties::West::LOW:
                                    return 15351;
                                case Properties::West::TALL:
                                    return 15352;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15353;
                                case Properties::West::LOW:
                                    return 15354;
                                case Properties::West::TALL:
                                    return 15355;
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
                                    return 15356;
                                case Properties::West::LOW:
                                    return 15357;
                                case Properties::West::TALL:
                                    return 15358;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15359;
                                case Properties::West::LOW:
                                    return 15360;
                                case Properties::West::TALL:
                                    return 15361;
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
                                    return 15362;
                                case Properties::West::LOW:
                                    return 15363;
                                case Properties::West::TALL:
                                    return 15364;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15365;
                                case Properties::West::LOW:
                                    return 15366;
                                case Properties::West::TALL:
                                    return 15367;
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
                                    return 15368;
                                case Properties::West::LOW:
                                    return 15369;
                                case Properties::West::TALL:
                                    return 15370;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15371;
                                case Properties::West::LOW:
                                    return 15372;
                                case Properties::West::TALL:
                                    return 15373;
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
                                    return 15374;
                                case Properties::West::LOW:
                                    return 15375;
                                case Properties::West::TALL:
                                    return 15376;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15377;
                                case Properties::West::LOW:
                                    return 15378;
                                case Properties::West::TALL:
                                    return 15379;
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
                                    return 15380;
                                case Properties::West::LOW:
                                    return 15381;
                                case Properties::West::TALL:
                                    return 15382;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15383;
                                case Properties::West::LOW:
                                    return 15384;
                                case Properties::West::TALL:
                                    return 15385;
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
                                    return 15386;
                                case Properties::West::LOW:
                                    return 15387;
                                case Properties::West::TALL:
                                    return 15388;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15389;
                                case Properties::West::LOW:
                                    return 15390;
                                case Properties::West::TALL:
                                    return 15391;
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
                                    return 15392;
                                case Properties::West::LOW:
                                    return 15393;
                                case Properties::West::TALL:
                                    return 15394;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15395;
                                case Properties::West::LOW:
                                    return 15396;
                                case Properties::West::TALL:
                                    return 15397;
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
                                    return 15398;
                                case Properties::West::LOW:
                                    return 15399;
                                case Properties::West::TALL:
                                    return 15400;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15401;
                                case Properties::West::LOW:
                                    return 15402;
                                case Properties::West::TALL:
                                    return 15403;
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
                                    return 15404;
                                case Properties::West::LOW:
                                    return 15405;
                                case Properties::West::TALL:
                                    return 15406;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15407;
                                case Properties::West::LOW:
                                    return 15408;
                                case Properties::West::TALL:
                                    return 15409;
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
                                    return 15410;
                                case Properties::West::LOW:
                                    return 15411;
                                case Properties::West::TALL:
                                    return 15412;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15413;
                                case Properties::West::LOW:
                                    return 15414;
                                case Properties::West::TALL:
                                    return 15415;
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
                                    return 15416;
                                case Properties::West::LOW:
                                    return 15417;
                                case Properties::West::TALL:
                                    return 15418;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15419;
                                case Properties::West::LOW:
                                    return 15420;
                                case Properties::West::TALL:
                                    return 15421;
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
                                    return 15422;
                                case Properties::West::LOW:
                                    return 15423;
                                case Properties::West::TALL:
                                    return 15424;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15425;
                                case Properties::West::LOW:
                                    return 15426;
                                case Properties::West::TALL:
                                    return 15427;
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
                                    return 15428;
                                case Properties::West::LOW:
                                    return 15429;
                                case Properties::West::TALL:
                                    return 15430;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15431;
                                case Properties::West::LOW:
                                    return 15432;
                                case Properties::West::TALL:
                                    return 15433;
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
                                    return 15434;
                                case Properties::West::LOW:
                                    return 15435;
                                case Properties::West::TALL:
                                    return 15436;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15437;
                                case Properties::West::LOW:
                                    return 15438;
                                case Properties::West::TALL:
                                    return 15439;
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
                                    return 15440;
                                case Properties::West::LOW:
                                    return 15441;
                                case Properties::West::TALL:
                                    return 15442;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15443;
                                case Properties::West::LOW:
                                    return 15444;
                                case Properties::West::TALL:
                                    return 15445;
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
                                    return 15446;
                                case Properties::West::LOW:
                                    return 15447;
                                case Properties::West::TALL:
                                    return 15448;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15449;
                                case Properties::West::LOW:
                                    return 15450;
                                case Properties::West::TALL:
                                    return 15451;
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
                                    return 15452;
                                case Properties::West::LOW:
                                    return 15453;
                                case Properties::West::TALL:
                                    return 15454;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15455;
                                case Properties::West::LOW:
                                    return 15456;
                                case Properties::West::TALL:
                                    return 15457;
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
                                    return 15458;
                                case Properties::West::LOW:
                                    return 15459;
                                case Properties::West::TALL:
                                    return 15460;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15461;
                                case Properties::West::LOW:
                                    return 15462;
                                case Properties::West::TALL:
                                    return 15463;
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
                                    return 15464;
                                case Properties::West::LOW:
                                    return 15465;
                                case Properties::West::TALL:
                                    return 15466;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15467;
                                case Properties::West::LOW:
                                    return 15468;
                                case Properties::West::TALL:
                                    return 15469;
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
                                    return 15470;
                                case Properties::West::LOW:
                                    return 15471;
                                case Properties::West::TALL:
                                    return 15472;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15473;
                                case Properties::West::LOW:
                                    return 15474;
                                case Properties::West::TALL:
                                    return 15475;
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
