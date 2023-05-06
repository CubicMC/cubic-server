#include "PolishedDeepslateWall.hpp"
namespace Blocks {
namespace PolishedDeepslateWall {
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
                            return 22063;
                        case Properties::West::LOW:
                            return 22064;
                        case Properties::West::TALL:
                            return 22065;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22066;
                        case Properties::West::LOW:
                            return 22067;
                        case Properties::West::TALL:
                            return 22068;
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
                            return 22069;
                        case Properties::West::LOW:
                            return 22070;
                        case Properties::West::TALL:
                            return 22071;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22072;
                        case Properties::West::LOW:
                            return 22073;
                        case Properties::West::TALL:
                            return 22074;
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
                            return 22075;
                        case Properties::West::LOW:
                            return 22076;
                        case Properties::West::TALL:
                            return 22077;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22078;
                        case Properties::West::LOW:
                            return 22079;
                        case Properties::West::TALL:
                            return 22080;
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
                            return 22081;
                        case Properties::West::LOW:
                            return 22082;
                        case Properties::West::TALL:
                            return 22083;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22084;
                        case Properties::West::LOW:
                            return 22085;
                        case Properties::West::TALL:
                            return 22086;
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
                            return 22087;
                        case Properties::West::LOW:
                            return 22088;
                        case Properties::West::TALL:
                            return 22089;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22090;
                        case Properties::West::LOW:
                            return 22091;
                        case Properties::West::TALL:
                            return 22092;
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
                            return 22093;
                        case Properties::West::LOW:
                            return 22094;
                        case Properties::West::TALL:
                            return 22095;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22096;
                        case Properties::West::LOW:
                            return 22097;
                        case Properties::West::TALL:
                            return 22098;
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
                            return 22099;
                        case Properties::West::LOW:
                            return 22100;
                        case Properties::West::TALL:
                            return 22101;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22102;
                        case Properties::West::LOW:
                            return 22103;
                        case Properties::West::TALL:
                            return 22104;
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
                            return 22105;
                        case Properties::West::LOW:
                            return 22106;
                        case Properties::West::TALL:
                            return 22107;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22108;
                        case Properties::West::LOW:
                            return 22109;
                        case Properties::West::TALL:
                            return 22110;
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
                            return 22111;
                        case Properties::West::LOW:
                            return 22112;
                        case Properties::West::TALL:
                            return 22113;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22114;
                        case Properties::West::LOW:
                            return 22115;
                        case Properties::West::TALL:
                            return 22116;
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
                            return 22117;
                        case Properties::West::LOW:
                            return 22118;
                        case Properties::West::TALL:
                            return 22119;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22120;
                        case Properties::West::LOW:
                            return 22121;
                        case Properties::West::TALL:
                            return 22122;
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
                            return 22123;
                        case Properties::West::LOW:
                            return 22124;
                        case Properties::West::TALL:
                            return 22125;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22126;
                        case Properties::West::LOW:
                            return 22127;
                        case Properties::West::TALL:
                            return 22128;
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
                            return 22129;
                        case Properties::West::LOW:
                            return 22130;
                        case Properties::West::TALL:
                            return 22131;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22132;
                        case Properties::West::LOW:
                            return 22133;
                        case Properties::West::TALL:
                            return 22134;
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
                            return 22135;
                        case Properties::West::LOW:
                            return 22136;
                        case Properties::West::TALL:
                            return 22137;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22138;
                        case Properties::West::LOW:
                            return 22139;
                        case Properties::West::TALL:
                            return 22140;
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
                            return 22141;
                        case Properties::West::LOW:
                            return 22142;
                        case Properties::West::TALL:
                            return 22143;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22144;
                        case Properties::West::LOW:
                            return 22145;
                        case Properties::West::TALL:
                            return 22146;
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
                            return 22147;
                        case Properties::West::LOW:
                            return 22148;
                        case Properties::West::TALL:
                            return 22149;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22150;
                        case Properties::West::LOW:
                            return 22151;
                        case Properties::West::TALL:
                            return 22152;
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
                            return 22153;
                        case Properties::West::LOW:
                            return 22154;
                        case Properties::West::TALL:
                            return 22155;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22156;
                        case Properties::West::LOW:
                            return 22157;
                        case Properties::West::TALL:
                            return 22158;
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
                            return 22159;
                        case Properties::West::LOW:
                            return 22160;
                        case Properties::West::TALL:
                            return 22161;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22162;
                        case Properties::West::LOW:
                            return 22163;
                        case Properties::West::TALL:
                            return 22164;
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
                            return 22165;
                        case Properties::West::LOW:
                            return 22166;
                        case Properties::West::TALL:
                            return 22167;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22168;
                        case Properties::West::LOW:
                            return 22169;
                        case Properties::West::TALL:
                            return 22170;
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
                            return 22171;
                        case Properties::West::LOW:
                            return 22172;
                        case Properties::West::TALL:
                            return 22173;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22174;
                        case Properties::West::LOW:
                            return 22175;
                        case Properties::West::TALL:
                            return 22176;
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
                            return 22177;
                        case Properties::West::LOW:
                            return 22178;
                        case Properties::West::TALL:
                            return 22179;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22180;
                        case Properties::West::LOW:
                            return 22181;
                        case Properties::West::TALL:
                            return 22182;
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
                            return 22183;
                        case Properties::West::LOW:
                            return 22184;
                        case Properties::West::TALL:
                            return 22185;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22186;
                        case Properties::West::LOW:
                            return 22187;
                        case Properties::West::TALL:
                            return 22188;
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
                            return 22189;
                        case Properties::West::LOW:
                            return 22190;
                        case Properties::West::TALL:
                            return 22191;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22192;
                        case Properties::West::LOW:
                            return 22193;
                        case Properties::West::TALL:
                            return 22194;
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
                            return 22195;
                        case Properties::West::LOW:
                            return 22196;
                        case Properties::West::TALL:
                            return 22197;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22198;
                        case Properties::West::LOW:
                            return 22199;
                        case Properties::West::TALL:
                            return 22200;
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
                            return 22201;
                        case Properties::West::LOW:
                            return 22202;
                        case Properties::West::TALL:
                            return 22203;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22204;
                        case Properties::West::LOW:
                            return 22205;
                        case Properties::West::TALL:
                            return 22206;
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
                            return 22207;
                        case Properties::West::LOW:
                            return 22208;
                        case Properties::West::TALL:
                            return 22209;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22210;
                        case Properties::West::LOW:
                            return 22211;
                        case Properties::West::TALL:
                            return 22212;
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
                            return 22213;
                        case Properties::West::LOW:
                            return 22214;
                        case Properties::West::TALL:
                            return 22215;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22216;
                        case Properties::West::LOW:
                            return 22217;
                        case Properties::West::TALL:
                            return 22218;
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
                            return 22219;
                        case Properties::West::LOW:
                            return 22220;
                        case Properties::West::TALL:
                            return 22221;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22222;
                        case Properties::West::LOW:
                            return 22223;
                        case Properties::West::TALL:
                            return 22224;
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
                            return 22225;
                        case Properties::West::LOW:
                            return 22226;
                        case Properties::West::TALL:
                            return 22227;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22228;
                        case Properties::West::LOW:
                            return 22229;
                        case Properties::West::TALL:
                            return 22230;
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
                            return 22231;
                        case Properties::West::LOW:
                            return 22232;
                        case Properties::West::TALL:
                            return 22233;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22234;
                        case Properties::West::LOW:
                            return 22235;
                        case Properties::West::TALL:
                            return 22236;
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
                            return 22237;
                        case Properties::West::LOW:
                            return 22238;
                        case Properties::West::TALL:
                            return 22239;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22240;
                        case Properties::West::LOW:
                            return 22241;
                        case Properties::West::TALL:
                            return 22242;
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
                            return 22243;
                        case Properties::West::LOW:
                            return 22244;
                        case Properties::West::TALL:
                            return 22245;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22246;
                        case Properties::West::LOW:
                            return 22247;
                        case Properties::West::TALL:
                            return 22248;
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
                            return 22249;
                        case Properties::West::LOW:
                            return 22250;
                        case Properties::West::TALL:
                            return 22251;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22252;
                        case Properties::West::LOW:
                            return 22253;
                        case Properties::West::TALL:
                            return 22254;
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
                            return 22255;
                        case Properties::West::LOW:
                            return 22256;
                        case Properties::West::TALL:
                            return 22257;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22258;
                        case Properties::West::LOW:
                            return 22259;
                        case Properties::West::TALL:
                            return 22260;
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
                            return 22261;
                        case Properties::West::LOW:
                            return 22262;
                        case Properties::West::TALL:
                            return 22263;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22264;
                        case Properties::West::LOW:
                            return 22265;
                        case Properties::West::TALL:
                            return 22266;
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
                            return 22267;
                        case Properties::West::LOW:
                            return 22268;
                        case Properties::West::TALL:
                            return 22269;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22270;
                        case Properties::West::LOW:
                            return 22271;
                        case Properties::West::TALL:
                            return 22272;
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
                            return 22273;
                        case Properties::West::LOW:
                            return 22274;
                        case Properties::West::TALL:
                            return 22275;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22276;
                        case Properties::West::LOW:
                            return 22277;
                        case Properties::West::TALL:
                            return 22278;
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
                            return 22279;
                        case Properties::West::LOW:
                            return 22280;
                        case Properties::West::TALL:
                            return 22281;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22282;
                        case Properties::West::LOW:
                            return 22283;
                        case Properties::West::TALL:
                            return 22284;
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
                            return 22285;
                        case Properties::West::LOW:
                            return 22286;
                        case Properties::West::TALL:
                            return 22287;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22288;
                        case Properties::West::LOW:
                            return 22289;
                        case Properties::West::TALL:
                            return 22290;
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
                            return 22291;
                        case Properties::West::LOW:
                            return 22292;
                        case Properties::West::TALL:
                            return 22293;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22294;
                        case Properties::West::LOW:
                            return 22295;
                        case Properties::West::TALL:
                            return 22296;
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
                            return 22297;
                        case Properties::West::LOW:
                            return 22298;
                        case Properties::West::TALL:
                            return 22299;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22300;
                        case Properties::West::LOW:
                            return 22301;
                        case Properties::West::TALL:
                            return 22302;
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
                            return 22303;
                        case Properties::West::LOW:
                            return 22304;
                        case Properties::West::TALL:
                            return 22305;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22306;
                        case Properties::West::LOW:
                            return 22307;
                        case Properties::West::TALL:
                            return 22308;
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
                            return 22309;
                        case Properties::West::LOW:
                            return 22310;
                        case Properties::West::TALL:
                            return 22311;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22312;
                        case Properties::West::LOW:
                            return 22313;
                        case Properties::West::TALL:
                            return 22314;
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
                            return 22315;
                        case Properties::West::LOW:
                            return 22316;
                        case Properties::West::TALL:
                            return 22317;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22318;
                        case Properties::West::LOW:
                            return 22319;
                        case Properties::West::TALL:
                            return 22320;
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
                            return 22321;
                        case Properties::West::LOW:
                            return 22322;
                        case Properties::West::TALL:
                            return 22323;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22324;
                        case Properties::West::LOW:
                            return 22325;
                        case Properties::West::TALL:
                            return 22326;
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
                            return 22327;
                        case Properties::West::LOW:
                            return 22328;
                        case Properties::West::TALL:
                            return 22329;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22330;
                        case Properties::West::LOW:
                            return 22331;
                        case Properties::West::TALL:
                            return 22332;
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
                            return 22333;
                        case Properties::West::LOW:
                            return 22334;
                        case Properties::West::TALL:
                            return 22335;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22336;
                        case Properties::West::LOW:
                            return 22337;
                        case Properties::West::TALL:
                            return 22338;
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
                            return 22339;
                        case Properties::West::LOW:
                            return 22340;
                        case Properties::West::TALL:
                            return 22341;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22342;
                        case Properties::West::LOW:
                            return 22343;
                        case Properties::West::TALL:
                            return 22344;
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
                            return 22345;
                        case Properties::West::LOW:
                            return 22346;
                        case Properties::West::TALL:
                            return 22347;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22348;
                        case Properties::West::LOW:
                            return 22349;
                        case Properties::West::TALL:
                            return 22350;
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
                            return 22351;
                        case Properties::West::LOW:
                            return 22352;
                        case Properties::West::TALL:
                            return 22353;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22354;
                        case Properties::West::LOW:
                            return 22355;
                        case Properties::West::TALL:
                            return 22356;
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
                            return 22357;
                        case Properties::West::LOW:
                            return 22358;
                        case Properties::West::TALL:
                            return 22359;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22360;
                        case Properties::West::LOW:
                            return 22361;
                        case Properties::West::TALL:
                            return 22362;
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
                            return 22363;
                        case Properties::West::LOW:
                            return 22364;
                        case Properties::West::TALL:
                            return 22365;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22366;
                        case Properties::West::LOW:
                            return 22367;
                        case Properties::West::TALL:
                            return 22368;
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
                            return 22369;
                        case Properties::West::LOW:
                            return 22370;
                        case Properties::West::TALL:
                            return 22371;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22372;
                        case Properties::West::LOW:
                            return 22373;
                        case Properties::West::TALL:
                            return 22374;
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
                            return 22375;
                        case Properties::West::LOW:
                            return 22376;
                        case Properties::West::TALL:
                            return 22377;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22378;
                        case Properties::West::LOW:
                            return 22379;
                        case Properties::West::TALL:
                            return 22380;
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
                            return 22381;
                        case Properties::West::LOW:
                            return 22382;
                        case Properties::West::TALL:
                            return 22383;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 22384;
                        case Properties::West::LOW:
                            return 22385;
                        case Properties::West::TALL:
                            return 22386;
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
