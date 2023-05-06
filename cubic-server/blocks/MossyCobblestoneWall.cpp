#include "MossyCobblestoneWall.hpp"
namespace Blocks {
namespace MossyCobblestoneWall {
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
                            return 8013;
                        case Properties::West::LOW:
                            return 8014;
                        case Properties::West::TALL:
                            return 8015;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8016;
                        case Properties::West::LOW:
                            return 8017;
                        case Properties::West::TALL:
                            return 8018;
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
                            return 8019;
                        case Properties::West::LOW:
                            return 8020;
                        case Properties::West::TALL:
                            return 8021;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8022;
                        case Properties::West::LOW:
                            return 8023;
                        case Properties::West::TALL:
                            return 8024;
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
                            return 8025;
                        case Properties::West::LOW:
                            return 8026;
                        case Properties::West::TALL:
                            return 8027;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8028;
                        case Properties::West::LOW:
                            return 8029;
                        case Properties::West::TALL:
                            return 8030;
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
                            return 8031;
                        case Properties::West::LOW:
                            return 8032;
                        case Properties::West::TALL:
                            return 8033;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8034;
                        case Properties::West::LOW:
                            return 8035;
                        case Properties::West::TALL:
                            return 8036;
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
                            return 8037;
                        case Properties::West::LOW:
                            return 8038;
                        case Properties::West::TALL:
                            return 8039;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8040;
                        case Properties::West::LOW:
                            return 8041;
                        case Properties::West::TALL:
                            return 8042;
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
                            return 8043;
                        case Properties::West::LOW:
                            return 8044;
                        case Properties::West::TALL:
                            return 8045;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8046;
                        case Properties::West::LOW:
                            return 8047;
                        case Properties::West::TALL:
                            return 8048;
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
                            return 8049;
                        case Properties::West::LOW:
                            return 8050;
                        case Properties::West::TALL:
                            return 8051;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8052;
                        case Properties::West::LOW:
                            return 8053;
                        case Properties::West::TALL:
                            return 8054;
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
                            return 8055;
                        case Properties::West::LOW:
                            return 8056;
                        case Properties::West::TALL:
                            return 8057;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8058;
                        case Properties::West::LOW:
                            return 8059;
                        case Properties::West::TALL:
                            return 8060;
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
                            return 8061;
                        case Properties::West::LOW:
                            return 8062;
                        case Properties::West::TALL:
                            return 8063;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8064;
                        case Properties::West::LOW:
                            return 8065;
                        case Properties::West::TALL:
                            return 8066;
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
                            return 8067;
                        case Properties::West::LOW:
                            return 8068;
                        case Properties::West::TALL:
                            return 8069;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8070;
                        case Properties::West::LOW:
                            return 8071;
                        case Properties::West::TALL:
                            return 8072;
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
                            return 8073;
                        case Properties::West::LOW:
                            return 8074;
                        case Properties::West::TALL:
                            return 8075;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8076;
                        case Properties::West::LOW:
                            return 8077;
                        case Properties::West::TALL:
                            return 8078;
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
                            return 8079;
                        case Properties::West::LOW:
                            return 8080;
                        case Properties::West::TALL:
                            return 8081;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8082;
                        case Properties::West::LOW:
                            return 8083;
                        case Properties::West::TALL:
                            return 8084;
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
                            return 8085;
                        case Properties::West::LOW:
                            return 8086;
                        case Properties::West::TALL:
                            return 8087;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8088;
                        case Properties::West::LOW:
                            return 8089;
                        case Properties::West::TALL:
                            return 8090;
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
                            return 8091;
                        case Properties::West::LOW:
                            return 8092;
                        case Properties::West::TALL:
                            return 8093;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8094;
                        case Properties::West::LOW:
                            return 8095;
                        case Properties::West::TALL:
                            return 8096;
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
                            return 8097;
                        case Properties::West::LOW:
                            return 8098;
                        case Properties::West::TALL:
                            return 8099;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8100;
                        case Properties::West::LOW:
                            return 8101;
                        case Properties::West::TALL:
                            return 8102;
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
                            return 8103;
                        case Properties::West::LOW:
                            return 8104;
                        case Properties::West::TALL:
                            return 8105;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8106;
                        case Properties::West::LOW:
                            return 8107;
                        case Properties::West::TALL:
                            return 8108;
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
                            return 8109;
                        case Properties::West::LOW:
                            return 8110;
                        case Properties::West::TALL:
                            return 8111;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8112;
                        case Properties::West::LOW:
                            return 8113;
                        case Properties::West::TALL:
                            return 8114;
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
                            return 8115;
                        case Properties::West::LOW:
                            return 8116;
                        case Properties::West::TALL:
                            return 8117;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8118;
                        case Properties::West::LOW:
                            return 8119;
                        case Properties::West::TALL:
                            return 8120;
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
                            return 8121;
                        case Properties::West::LOW:
                            return 8122;
                        case Properties::West::TALL:
                            return 8123;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8124;
                        case Properties::West::LOW:
                            return 8125;
                        case Properties::West::TALL:
                            return 8126;
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
                            return 8127;
                        case Properties::West::LOW:
                            return 8128;
                        case Properties::West::TALL:
                            return 8129;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8130;
                        case Properties::West::LOW:
                            return 8131;
                        case Properties::West::TALL:
                            return 8132;
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
                            return 8133;
                        case Properties::West::LOW:
                            return 8134;
                        case Properties::West::TALL:
                            return 8135;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8136;
                        case Properties::West::LOW:
                            return 8137;
                        case Properties::West::TALL:
                            return 8138;
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
                            return 8139;
                        case Properties::West::LOW:
                            return 8140;
                        case Properties::West::TALL:
                            return 8141;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8142;
                        case Properties::West::LOW:
                            return 8143;
                        case Properties::West::TALL:
                            return 8144;
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
                            return 8145;
                        case Properties::West::LOW:
                            return 8146;
                        case Properties::West::TALL:
                            return 8147;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8148;
                        case Properties::West::LOW:
                            return 8149;
                        case Properties::West::TALL:
                            return 8150;
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
                            return 8151;
                        case Properties::West::LOW:
                            return 8152;
                        case Properties::West::TALL:
                            return 8153;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8154;
                        case Properties::West::LOW:
                            return 8155;
                        case Properties::West::TALL:
                            return 8156;
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
                            return 8157;
                        case Properties::West::LOW:
                            return 8158;
                        case Properties::West::TALL:
                            return 8159;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8160;
                        case Properties::West::LOW:
                            return 8161;
                        case Properties::West::TALL:
                            return 8162;
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
                            return 8163;
                        case Properties::West::LOW:
                            return 8164;
                        case Properties::West::TALL:
                            return 8165;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8166;
                        case Properties::West::LOW:
                            return 8167;
                        case Properties::West::TALL:
                            return 8168;
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
                            return 8169;
                        case Properties::West::LOW:
                            return 8170;
                        case Properties::West::TALL:
                            return 8171;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8172;
                        case Properties::West::LOW:
                            return 8173;
                        case Properties::West::TALL:
                            return 8174;
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
                            return 8175;
                        case Properties::West::LOW:
                            return 8176;
                        case Properties::West::TALL:
                            return 8177;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8178;
                        case Properties::West::LOW:
                            return 8179;
                        case Properties::West::TALL:
                            return 8180;
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
                            return 8181;
                        case Properties::West::LOW:
                            return 8182;
                        case Properties::West::TALL:
                            return 8183;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8184;
                        case Properties::West::LOW:
                            return 8185;
                        case Properties::West::TALL:
                            return 8186;
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
                            return 8187;
                        case Properties::West::LOW:
                            return 8188;
                        case Properties::West::TALL:
                            return 8189;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8190;
                        case Properties::West::LOW:
                            return 8191;
                        case Properties::West::TALL:
                            return 8192;
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
                            return 8193;
                        case Properties::West::LOW:
                            return 8194;
                        case Properties::West::TALL:
                            return 8195;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8196;
                        case Properties::West::LOW:
                            return 8197;
                        case Properties::West::TALL:
                            return 8198;
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
                            return 8199;
                        case Properties::West::LOW:
                            return 8200;
                        case Properties::West::TALL:
                            return 8201;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8202;
                        case Properties::West::LOW:
                            return 8203;
                        case Properties::West::TALL:
                            return 8204;
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
                            return 8205;
                        case Properties::West::LOW:
                            return 8206;
                        case Properties::West::TALL:
                            return 8207;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8208;
                        case Properties::West::LOW:
                            return 8209;
                        case Properties::West::TALL:
                            return 8210;
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
                            return 8211;
                        case Properties::West::LOW:
                            return 8212;
                        case Properties::West::TALL:
                            return 8213;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8214;
                        case Properties::West::LOW:
                            return 8215;
                        case Properties::West::TALL:
                            return 8216;
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
                            return 8217;
                        case Properties::West::LOW:
                            return 8218;
                        case Properties::West::TALL:
                            return 8219;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8220;
                        case Properties::West::LOW:
                            return 8221;
                        case Properties::West::TALL:
                            return 8222;
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
                            return 8223;
                        case Properties::West::LOW:
                            return 8224;
                        case Properties::West::TALL:
                            return 8225;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8226;
                        case Properties::West::LOW:
                            return 8227;
                        case Properties::West::TALL:
                            return 8228;
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
                            return 8229;
                        case Properties::West::LOW:
                            return 8230;
                        case Properties::West::TALL:
                            return 8231;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8232;
                        case Properties::West::LOW:
                            return 8233;
                        case Properties::West::TALL:
                            return 8234;
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
                            return 8235;
                        case Properties::West::LOW:
                            return 8236;
                        case Properties::West::TALL:
                            return 8237;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8238;
                        case Properties::West::LOW:
                            return 8239;
                        case Properties::West::TALL:
                            return 8240;
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
                            return 8241;
                        case Properties::West::LOW:
                            return 8242;
                        case Properties::West::TALL:
                            return 8243;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8244;
                        case Properties::West::LOW:
                            return 8245;
                        case Properties::West::TALL:
                            return 8246;
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
                            return 8247;
                        case Properties::West::LOW:
                            return 8248;
                        case Properties::West::TALL:
                            return 8249;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8250;
                        case Properties::West::LOW:
                            return 8251;
                        case Properties::West::TALL:
                            return 8252;
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
                            return 8253;
                        case Properties::West::LOW:
                            return 8254;
                        case Properties::West::TALL:
                            return 8255;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8256;
                        case Properties::West::LOW:
                            return 8257;
                        case Properties::West::TALL:
                            return 8258;
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
                            return 8259;
                        case Properties::West::LOW:
                            return 8260;
                        case Properties::West::TALL:
                            return 8261;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8262;
                        case Properties::West::LOW:
                            return 8263;
                        case Properties::West::TALL:
                            return 8264;
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
                            return 8265;
                        case Properties::West::LOW:
                            return 8266;
                        case Properties::West::TALL:
                            return 8267;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8268;
                        case Properties::West::LOW:
                            return 8269;
                        case Properties::West::TALL:
                            return 8270;
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
                            return 8271;
                        case Properties::West::LOW:
                            return 8272;
                        case Properties::West::TALL:
                            return 8273;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8274;
                        case Properties::West::LOW:
                            return 8275;
                        case Properties::West::TALL:
                            return 8276;
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
                            return 8277;
                        case Properties::West::LOW:
                            return 8278;
                        case Properties::West::TALL:
                            return 8279;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8280;
                        case Properties::West::LOW:
                            return 8281;
                        case Properties::West::TALL:
                            return 8282;
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
                            return 8283;
                        case Properties::West::LOW:
                            return 8284;
                        case Properties::West::TALL:
                            return 8285;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8286;
                        case Properties::West::LOW:
                            return 8287;
                        case Properties::West::TALL:
                            return 8288;
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
                            return 8289;
                        case Properties::West::LOW:
                            return 8290;
                        case Properties::West::TALL:
                            return 8291;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8292;
                        case Properties::West::LOW:
                            return 8293;
                        case Properties::West::TALL:
                            return 8294;
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
                            return 8295;
                        case Properties::West::LOW:
                            return 8296;
                        case Properties::West::TALL:
                            return 8297;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8298;
                        case Properties::West::LOW:
                            return 8299;
                        case Properties::West::TALL:
                            return 8300;
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
                            return 8301;
                        case Properties::West::LOW:
                            return 8302;
                        case Properties::West::TALL:
                            return 8303;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8304;
                        case Properties::West::LOW:
                            return 8305;
                        case Properties::West::TALL:
                            return 8306;
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
                            return 8307;
                        case Properties::West::LOW:
                            return 8308;
                        case Properties::West::TALL:
                            return 8309;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8310;
                        case Properties::West::LOW:
                            return 8311;
                        case Properties::West::TALL:
                            return 8312;
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
                            return 8313;
                        case Properties::West::LOW:
                            return 8314;
                        case Properties::West::TALL:
                            return 8315;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8316;
                        case Properties::West::LOW:
                            return 8317;
                        case Properties::West::TALL:
                            return 8318;
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
                            return 8319;
                        case Properties::West::LOW:
                            return 8320;
                        case Properties::West::TALL:
                            return 8321;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8322;
                        case Properties::West::LOW:
                            return 8323;
                        case Properties::West::TALL:
                            return 8324;
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
                            return 8325;
                        case Properties::West::LOW:
                            return 8326;
                        case Properties::West::TALL:
                            return 8327;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8328;
                        case Properties::West::LOW:
                            return 8329;
                        case Properties::West::TALL:
                            return 8330;
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
                            return 8331;
                        case Properties::West::LOW:
                            return 8332;
                        case Properties::West::TALL:
                            return 8333;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8334;
                        case Properties::West::LOW:
                            return 8335;
                        case Properties::West::TALL:
                            return 8336;
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
