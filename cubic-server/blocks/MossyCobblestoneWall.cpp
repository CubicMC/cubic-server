#include "MossyCobblestoneWall.hpp"
#include <stdexcept>

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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8016;
                                case Properties::West::LOW:
                                    return 8017;
                                case Properties::West::TALL:
                                    return 8018;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8022;
                                case Properties::West::LOW:
                                    return 8023;
                                case Properties::West::TALL:
                                    return 8024;
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
                                    return 8025;
                                case Properties::West::LOW:
                                    return 8026;
                                case Properties::West::TALL:
                                    return 8027;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8028;
                                case Properties::West::LOW:
                                    return 8029;
                                case Properties::West::TALL:
                                    return 8030;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8034;
                                case Properties::West::LOW:
                                    return 8035;
                                case Properties::West::TALL:
                                    return 8036;
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
                                    return 8037;
                                case Properties::West::LOW:
                                    return 8038;
                                case Properties::West::TALL:
                                    return 8039;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8040;
                                case Properties::West::LOW:
                                    return 8041;
                                case Properties::West::TALL:
                                    return 8042;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8046;
                                case Properties::West::LOW:
                                    return 8047;
                                case Properties::West::TALL:
                                    return 8048;
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
                                    return 8049;
                                case Properties::West::LOW:
                                    return 8050;
                                case Properties::West::TALL:
                                    return 8051;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8052;
                                case Properties::West::LOW:
                                    return 8053;
                                case Properties::West::TALL:
                                    return 8054;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8058;
                                case Properties::West::LOW:
                                    return 8059;
                                case Properties::West::TALL:
                                    return 8060;
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
                                    return 8061;
                                case Properties::West::LOW:
                                    return 8062;
                                case Properties::West::TALL:
                                    return 8063;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8064;
                                case Properties::West::LOW:
                                    return 8065;
                                case Properties::West::TALL:
                                    return 8066;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8070;
                                case Properties::West::LOW:
                                    return 8071;
                                case Properties::West::TALL:
                                    return 8072;
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
                                    return 8073;
                                case Properties::West::LOW:
                                    return 8074;
                                case Properties::West::TALL:
                                    return 8075;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8076;
                                case Properties::West::LOW:
                                    return 8077;
                                case Properties::West::TALL:
                                    return 8078;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8082;
                                case Properties::West::LOW:
                                    return 8083;
                                case Properties::West::TALL:
                                    return 8084;
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
                                    return 8085;
                                case Properties::West::LOW:
                                    return 8086;
                                case Properties::West::TALL:
                                    return 8087;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8088;
                                case Properties::West::LOW:
                                    return 8089;
                                case Properties::West::TALL:
                                    return 8090;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8094;
                                case Properties::West::LOW:
                                    return 8095;
                                case Properties::West::TALL:
                                    return 8096;
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
                                    return 8097;
                                case Properties::West::LOW:
                                    return 8098;
                                case Properties::West::TALL:
                                    return 8099;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8100;
                                case Properties::West::LOW:
                                    return 8101;
                                case Properties::West::TALL:
                                    return 8102;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8106;
                                case Properties::West::LOW:
                                    return 8107;
                                case Properties::West::TALL:
                                    return 8108;
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
                                    return 8109;
                                case Properties::West::LOW:
                                    return 8110;
                                case Properties::West::TALL:
                                    return 8111;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8112;
                                case Properties::West::LOW:
                                    return 8113;
                                case Properties::West::TALL:
                                    return 8114;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8118;
                                case Properties::West::LOW:
                                    return 8119;
                                case Properties::West::TALL:
                                    return 8120;
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
                                    return 8121;
                                case Properties::West::LOW:
                                    return 8122;
                                case Properties::West::TALL:
                                    return 8123;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8124;
                                case Properties::West::LOW:
                                    return 8125;
                                case Properties::West::TALL:
                                    return 8126;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8130;
                                case Properties::West::LOW:
                                    return 8131;
                                case Properties::West::TALL:
                                    return 8132;
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
                                    return 8133;
                                case Properties::West::LOW:
                                    return 8134;
                                case Properties::West::TALL:
                                    return 8135;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8136;
                                case Properties::West::LOW:
                                    return 8137;
                                case Properties::West::TALL:
                                    return 8138;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8142;
                                case Properties::West::LOW:
                                    return 8143;
                                case Properties::West::TALL:
                                    return 8144;
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
                                    return 8145;
                                case Properties::West::LOW:
                                    return 8146;
                                case Properties::West::TALL:
                                    return 8147;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8148;
                                case Properties::West::LOW:
                                    return 8149;
                                case Properties::West::TALL:
                                    return 8150;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8154;
                                case Properties::West::LOW:
                                    return 8155;
                                case Properties::West::TALL:
                                    return 8156;
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
                                    return 8157;
                                case Properties::West::LOW:
                                    return 8158;
                                case Properties::West::TALL:
                                    return 8159;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8160;
                                case Properties::West::LOW:
                                    return 8161;
                                case Properties::West::TALL:
                                    return 8162;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8166;
                                case Properties::West::LOW:
                                    return 8167;
                                case Properties::West::TALL:
                                    return 8168;
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
                                    return 8169;
                                case Properties::West::LOW:
                                    return 8170;
                                case Properties::West::TALL:
                                    return 8171;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8172;
                                case Properties::West::LOW:
                                    return 8173;
                                case Properties::West::TALL:
                                    return 8174;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8178;
                                case Properties::West::LOW:
                                    return 8179;
                                case Properties::West::TALL:
                                    return 8180;
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
                                    return 8181;
                                case Properties::West::LOW:
                                    return 8182;
                                case Properties::West::TALL:
                                    return 8183;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8184;
                                case Properties::West::LOW:
                                    return 8185;
                                case Properties::West::TALL:
                                    return 8186;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8190;
                                case Properties::West::LOW:
                                    return 8191;
                                case Properties::West::TALL:
                                    return 8192;
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
                                    return 8193;
                                case Properties::West::LOW:
                                    return 8194;
                                case Properties::West::TALL:
                                    return 8195;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8196;
                                case Properties::West::LOW:
                                    return 8197;
                                case Properties::West::TALL:
                                    return 8198;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8202;
                                case Properties::West::LOW:
                                    return 8203;
                                case Properties::West::TALL:
                                    return 8204;
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
                                    return 8205;
                                case Properties::West::LOW:
                                    return 8206;
                                case Properties::West::TALL:
                                    return 8207;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8208;
                                case Properties::West::LOW:
                                    return 8209;
                                case Properties::West::TALL:
                                    return 8210;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8214;
                                case Properties::West::LOW:
                                    return 8215;
                                case Properties::West::TALL:
                                    return 8216;
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
                                    return 8217;
                                case Properties::West::LOW:
                                    return 8218;
                                case Properties::West::TALL:
                                    return 8219;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8220;
                                case Properties::West::LOW:
                                    return 8221;
                                case Properties::West::TALL:
                                    return 8222;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8226;
                                case Properties::West::LOW:
                                    return 8227;
                                case Properties::West::TALL:
                                    return 8228;
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
                                    return 8229;
                                case Properties::West::LOW:
                                    return 8230;
                                case Properties::West::TALL:
                                    return 8231;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8232;
                                case Properties::West::LOW:
                                    return 8233;
                                case Properties::West::TALL:
                                    return 8234;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8238;
                                case Properties::West::LOW:
                                    return 8239;
                                case Properties::West::TALL:
                                    return 8240;
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
                                    return 8241;
                                case Properties::West::LOW:
                                    return 8242;
                                case Properties::West::TALL:
                                    return 8243;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8244;
                                case Properties::West::LOW:
                                    return 8245;
                                case Properties::West::TALL:
                                    return 8246;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8250;
                                case Properties::West::LOW:
                                    return 8251;
                                case Properties::West::TALL:
                                    return 8252;
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
                                    return 8253;
                                case Properties::West::LOW:
                                    return 8254;
                                case Properties::West::TALL:
                                    return 8255;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8256;
                                case Properties::West::LOW:
                                    return 8257;
                                case Properties::West::TALL:
                                    return 8258;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8262;
                                case Properties::West::LOW:
                                    return 8263;
                                case Properties::West::TALL:
                                    return 8264;
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
                                    return 8265;
                                case Properties::West::LOW:
                                    return 8266;
                                case Properties::West::TALL:
                                    return 8267;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8268;
                                case Properties::West::LOW:
                                    return 8269;
                                case Properties::West::TALL:
                                    return 8270;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8274;
                                case Properties::West::LOW:
                                    return 8275;
                                case Properties::West::TALL:
                                    return 8276;
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
                                    return 8277;
                                case Properties::West::LOW:
                                    return 8278;
                                case Properties::West::TALL:
                                    return 8279;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8280;
                                case Properties::West::LOW:
                                    return 8281;
                                case Properties::West::TALL:
                                    return 8282;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8286;
                                case Properties::West::LOW:
                                    return 8287;
                                case Properties::West::TALL:
                                    return 8288;
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
                                    return 8289;
                                case Properties::West::LOW:
                                    return 8290;
                                case Properties::West::TALL:
                                    return 8291;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8292;
                                case Properties::West::LOW:
                                    return 8293;
                                case Properties::West::TALL:
                                    return 8294;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8298;
                                case Properties::West::LOW:
                                    return 8299;
                                case Properties::West::TALL:
                                    return 8300;
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
                                    return 8301;
                                case Properties::West::LOW:
                                    return 8302;
                                case Properties::West::TALL:
                                    return 8303;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8304;
                                case Properties::West::LOW:
                                    return 8305;
                                case Properties::West::TALL:
                                    return 8306;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8310;
                                case Properties::West::LOW:
                                    return 8311;
                                case Properties::West::TALL:
                                    return 8312;
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
                                    return 8313;
                                case Properties::West::LOW:
                                    return 8314;
                                case Properties::West::TALL:
                                    return 8315;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8316;
                                case Properties::West::LOW:
                                    return 8317;
                                case Properties::West::TALL:
                                    return 8318;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8322;
                                case Properties::West::LOW:
                                    return 8323;
                                case Properties::West::TALL:
                                    return 8324;
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
                                    return 8325;
                                case Properties::West::LOW:
                                    return 8326;
                                case Properties::West::TALL:
                                    return 8327;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8328;
                                case Properties::West::LOW:
                                    return 8329;
                                case Properties::West::TALL:
                                    return 8330;
                                }
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
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 8334;
                                case Properties::West::LOW:
                                    return 8335;
                                case Properties::West::TALL:
                                    return 8336;
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
