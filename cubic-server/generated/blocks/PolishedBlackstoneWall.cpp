#include "PolishedBlackstoneWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedBlackstoneWall {
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
                                    return 17986;
                                case Properties::West::LOW:
                                    return 17987;
                                case Properties::West::TALL:
                                    return 17988;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17989;
                                case Properties::West::LOW:
                                    return 17990;
                                case Properties::West::TALL:
                                    return 17991;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17992;
                                case Properties::West::LOW:
                                    return 17993;
                                case Properties::West::TALL:
                                    return 17994;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17995;
                                case Properties::West::LOW:
                                    return 17996;
                                case Properties::West::TALL:
                                    return 17997;
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
                                    return 17998;
                                case Properties::West::LOW:
                                    return 17999;
                                case Properties::West::TALL:
                                    return 18000;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18001;
                                case Properties::West::LOW:
                                    return 18002;
                                case Properties::West::TALL:
                                    return 18003;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18004;
                                case Properties::West::LOW:
                                    return 18005;
                                case Properties::West::TALL:
                                    return 18006;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18007;
                                case Properties::West::LOW:
                                    return 18008;
                                case Properties::West::TALL:
                                    return 18009;
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
                                    return 18010;
                                case Properties::West::LOW:
                                    return 18011;
                                case Properties::West::TALL:
                                    return 18012;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18013;
                                case Properties::West::LOW:
                                    return 18014;
                                case Properties::West::TALL:
                                    return 18015;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18016;
                                case Properties::West::LOW:
                                    return 18017;
                                case Properties::West::TALL:
                                    return 18018;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18019;
                                case Properties::West::LOW:
                                    return 18020;
                                case Properties::West::TALL:
                                    return 18021;
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
                                    return 18022;
                                case Properties::West::LOW:
                                    return 18023;
                                case Properties::West::TALL:
                                    return 18024;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18025;
                                case Properties::West::LOW:
                                    return 18026;
                                case Properties::West::TALL:
                                    return 18027;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18028;
                                case Properties::West::LOW:
                                    return 18029;
                                case Properties::West::TALL:
                                    return 18030;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18031;
                                case Properties::West::LOW:
                                    return 18032;
                                case Properties::West::TALL:
                                    return 18033;
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
                                    return 18034;
                                case Properties::West::LOW:
                                    return 18035;
                                case Properties::West::TALL:
                                    return 18036;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18037;
                                case Properties::West::LOW:
                                    return 18038;
                                case Properties::West::TALL:
                                    return 18039;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18040;
                                case Properties::West::LOW:
                                    return 18041;
                                case Properties::West::TALL:
                                    return 18042;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18043;
                                case Properties::West::LOW:
                                    return 18044;
                                case Properties::West::TALL:
                                    return 18045;
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
                                    return 18046;
                                case Properties::West::LOW:
                                    return 18047;
                                case Properties::West::TALL:
                                    return 18048;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18049;
                                case Properties::West::LOW:
                                    return 18050;
                                case Properties::West::TALL:
                                    return 18051;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18052;
                                case Properties::West::LOW:
                                    return 18053;
                                case Properties::West::TALL:
                                    return 18054;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18055;
                                case Properties::West::LOW:
                                    return 18056;
                                case Properties::West::TALL:
                                    return 18057;
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
                                    return 18058;
                                case Properties::West::LOW:
                                    return 18059;
                                case Properties::West::TALL:
                                    return 18060;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18061;
                                case Properties::West::LOW:
                                    return 18062;
                                case Properties::West::TALL:
                                    return 18063;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18064;
                                case Properties::West::LOW:
                                    return 18065;
                                case Properties::West::TALL:
                                    return 18066;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18067;
                                case Properties::West::LOW:
                                    return 18068;
                                case Properties::West::TALL:
                                    return 18069;
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
                                    return 18070;
                                case Properties::West::LOW:
                                    return 18071;
                                case Properties::West::TALL:
                                    return 18072;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18073;
                                case Properties::West::LOW:
                                    return 18074;
                                case Properties::West::TALL:
                                    return 18075;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18076;
                                case Properties::West::LOW:
                                    return 18077;
                                case Properties::West::TALL:
                                    return 18078;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18079;
                                case Properties::West::LOW:
                                    return 18080;
                                case Properties::West::TALL:
                                    return 18081;
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
                                    return 18082;
                                case Properties::West::LOW:
                                    return 18083;
                                case Properties::West::TALL:
                                    return 18084;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18085;
                                case Properties::West::LOW:
                                    return 18086;
                                case Properties::West::TALL:
                                    return 18087;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18088;
                                case Properties::West::LOW:
                                    return 18089;
                                case Properties::West::TALL:
                                    return 18090;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18091;
                                case Properties::West::LOW:
                                    return 18092;
                                case Properties::West::TALL:
                                    return 18093;
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
                                    return 18094;
                                case Properties::West::LOW:
                                    return 18095;
                                case Properties::West::TALL:
                                    return 18096;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18097;
                                case Properties::West::LOW:
                                    return 18098;
                                case Properties::West::TALL:
                                    return 18099;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18100;
                                case Properties::West::LOW:
                                    return 18101;
                                case Properties::West::TALL:
                                    return 18102;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18103;
                                case Properties::West::LOW:
                                    return 18104;
                                case Properties::West::TALL:
                                    return 18105;
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
                                    return 18106;
                                case Properties::West::LOW:
                                    return 18107;
                                case Properties::West::TALL:
                                    return 18108;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18109;
                                case Properties::West::LOW:
                                    return 18110;
                                case Properties::West::TALL:
                                    return 18111;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18112;
                                case Properties::West::LOW:
                                    return 18113;
                                case Properties::West::TALL:
                                    return 18114;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18115;
                                case Properties::West::LOW:
                                    return 18116;
                                case Properties::West::TALL:
                                    return 18117;
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
                                    return 18118;
                                case Properties::West::LOW:
                                    return 18119;
                                case Properties::West::TALL:
                                    return 18120;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18121;
                                case Properties::West::LOW:
                                    return 18122;
                                case Properties::West::TALL:
                                    return 18123;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18124;
                                case Properties::West::LOW:
                                    return 18125;
                                case Properties::West::TALL:
                                    return 18126;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18127;
                                case Properties::West::LOW:
                                    return 18128;
                                case Properties::West::TALL:
                                    return 18129;
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
                                    return 18130;
                                case Properties::West::LOW:
                                    return 18131;
                                case Properties::West::TALL:
                                    return 18132;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18133;
                                case Properties::West::LOW:
                                    return 18134;
                                case Properties::West::TALL:
                                    return 18135;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18136;
                                case Properties::West::LOW:
                                    return 18137;
                                case Properties::West::TALL:
                                    return 18138;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18139;
                                case Properties::West::LOW:
                                    return 18140;
                                case Properties::West::TALL:
                                    return 18141;
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
                                    return 18142;
                                case Properties::West::LOW:
                                    return 18143;
                                case Properties::West::TALL:
                                    return 18144;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18145;
                                case Properties::West::LOW:
                                    return 18146;
                                case Properties::West::TALL:
                                    return 18147;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18148;
                                case Properties::West::LOW:
                                    return 18149;
                                case Properties::West::TALL:
                                    return 18150;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18151;
                                case Properties::West::LOW:
                                    return 18152;
                                case Properties::West::TALL:
                                    return 18153;
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
                                    return 18154;
                                case Properties::West::LOW:
                                    return 18155;
                                case Properties::West::TALL:
                                    return 18156;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18157;
                                case Properties::West::LOW:
                                    return 18158;
                                case Properties::West::TALL:
                                    return 18159;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18160;
                                case Properties::West::LOW:
                                    return 18161;
                                case Properties::West::TALL:
                                    return 18162;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18163;
                                case Properties::West::LOW:
                                    return 18164;
                                case Properties::West::TALL:
                                    return 18165;
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
                                    return 18166;
                                case Properties::West::LOW:
                                    return 18167;
                                case Properties::West::TALL:
                                    return 18168;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18169;
                                case Properties::West::LOW:
                                    return 18170;
                                case Properties::West::TALL:
                                    return 18171;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18172;
                                case Properties::West::LOW:
                                    return 18173;
                                case Properties::West::TALL:
                                    return 18174;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18175;
                                case Properties::West::LOW:
                                    return 18176;
                                case Properties::West::TALL:
                                    return 18177;
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
                                    return 18178;
                                case Properties::West::LOW:
                                    return 18179;
                                case Properties::West::TALL:
                                    return 18180;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18181;
                                case Properties::West::LOW:
                                    return 18182;
                                case Properties::West::TALL:
                                    return 18183;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18184;
                                case Properties::West::LOW:
                                    return 18185;
                                case Properties::West::TALL:
                                    return 18186;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18187;
                                case Properties::West::LOW:
                                    return 18188;
                                case Properties::West::TALL:
                                    return 18189;
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
                                    return 18190;
                                case Properties::West::LOW:
                                    return 18191;
                                case Properties::West::TALL:
                                    return 18192;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18193;
                                case Properties::West::LOW:
                                    return 18194;
                                case Properties::West::TALL:
                                    return 18195;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18196;
                                case Properties::West::LOW:
                                    return 18197;
                                case Properties::West::TALL:
                                    return 18198;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18199;
                                case Properties::West::LOW:
                                    return 18200;
                                case Properties::West::TALL:
                                    return 18201;
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
                                    return 18202;
                                case Properties::West::LOW:
                                    return 18203;
                                case Properties::West::TALL:
                                    return 18204;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18205;
                                case Properties::West::LOW:
                                    return 18206;
                                case Properties::West::TALL:
                                    return 18207;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18208;
                                case Properties::West::LOW:
                                    return 18209;
                                case Properties::West::TALL:
                                    return 18210;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18211;
                                case Properties::West::LOW:
                                    return 18212;
                                case Properties::West::TALL:
                                    return 18213;
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
                                    return 18214;
                                case Properties::West::LOW:
                                    return 18215;
                                case Properties::West::TALL:
                                    return 18216;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18217;
                                case Properties::West::LOW:
                                    return 18218;
                                case Properties::West::TALL:
                                    return 18219;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18220;
                                case Properties::West::LOW:
                                    return 18221;
                                case Properties::West::TALL:
                                    return 18222;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18223;
                                case Properties::West::LOW:
                                    return 18224;
                                case Properties::West::TALL:
                                    return 18225;
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
                                    return 18226;
                                case Properties::West::LOW:
                                    return 18227;
                                case Properties::West::TALL:
                                    return 18228;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18229;
                                case Properties::West::LOW:
                                    return 18230;
                                case Properties::West::TALL:
                                    return 18231;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18232;
                                case Properties::West::LOW:
                                    return 18233;
                                case Properties::West::TALL:
                                    return 18234;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18235;
                                case Properties::West::LOW:
                                    return 18236;
                                case Properties::West::TALL:
                                    return 18237;
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
                                    return 18238;
                                case Properties::West::LOW:
                                    return 18239;
                                case Properties::West::TALL:
                                    return 18240;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18241;
                                case Properties::West::LOW:
                                    return 18242;
                                case Properties::West::TALL:
                                    return 18243;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18244;
                                case Properties::West::LOW:
                                    return 18245;
                                case Properties::West::TALL:
                                    return 18246;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18247;
                                case Properties::West::LOW:
                                    return 18248;
                                case Properties::West::TALL:
                                    return 18249;
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
                                    return 18250;
                                case Properties::West::LOW:
                                    return 18251;
                                case Properties::West::TALL:
                                    return 18252;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18253;
                                case Properties::West::LOW:
                                    return 18254;
                                case Properties::West::TALL:
                                    return 18255;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18256;
                                case Properties::West::LOW:
                                    return 18257;
                                case Properties::West::TALL:
                                    return 18258;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18259;
                                case Properties::West::LOW:
                                    return 18260;
                                case Properties::West::TALL:
                                    return 18261;
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
                                    return 18262;
                                case Properties::West::LOW:
                                    return 18263;
                                case Properties::West::TALL:
                                    return 18264;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18265;
                                case Properties::West::LOW:
                                    return 18266;
                                case Properties::West::TALL:
                                    return 18267;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18268;
                                case Properties::West::LOW:
                                    return 18269;
                                case Properties::West::TALL:
                                    return 18270;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18271;
                                case Properties::West::LOW:
                                    return 18272;
                                case Properties::West::TALL:
                                    return 18273;
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
                                    return 18274;
                                case Properties::West::LOW:
                                    return 18275;
                                case Properties::West::TALL:
                                    return 18276;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18277;
                                case Properties::West::LOW:
                                    return 18278;
                                case Properties::West::TALL:
                                    return 18279;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18280;
                                case Properties::West::LOW:
                                    return 18281;
                                case Properties::West::TALL:
                                    return 18282;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18283;
                                case Properties::West::LOW:
                                    return 18284;
                                case Properties::West::TALL:
                                    return 18285;
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
                                    return 18286;
                                case Properties::West::LOW:
                                    return 18287;
                                case Properties::West::TALL:
                                    return 18288;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18289;
                                case Properties::West::LOW:
                                    return 18290;
                                case Properties::West::TALL:
                                    return 18291;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18292;
                                case Properties::West::LOW:
                                    return 18293;
                                case Properties::West::TALL:
                                    return 18294;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18295;
                                case Properties::West::LOW:
                                    return 18296;
                                case Properties::West::TALL:
                                    return 18297;
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
                                    return 18298;
                                case Properties::West::LOW:
                                    return 18299;
                                case Properties::West::TALL:
                                    return 18300;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18301;
                                case Properties::West::LOW:
                                    return 18302;
                                case Properties::West::TALL:
                                    return 18303;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18304;
                                case Properties::West::LOW:
                                    return 18305;
                                case Properties::West::TALL:
                                    return 18306;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 18307;
                                case Properties::West::LOW:
                                    return 18308;
                                case Properties::West::TALL:
                                    return 18309;
                                }
                            }
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 6)
            throw std::runtime_error("Invalid number of properties");
            Properties::East east;
            Properties::North north;
            Properties::South south;
            Properties::Up up;
            Properties::Waterlogged waterlogged;
            Properties::West west;
            for (auto prop : properties) {
                if (prop.first == "east") {
                    if (prop.second == "none") {
                        east = Properties::East::NONE;
                    } else if (prop.second == "low") {
                        east = Properties::East::LOW;
                    } else if (prop.second == "tall") {
                        east = Properties::East::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"east\" value");
                    }
                } else if (prop.first == "north") {
                    if (prop.second == "none") {
                        north = Properties::North::NONE;
                    } else if (prop.second == "low") {
                        north = Properties::North::LOW;
                    } else if (prop.second == "tall") {
                        north = Properties::North::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"north\" value");
                    }
                } else if (prop.first == "south") {
                    if (prop.second == "none") {
                        south = Properties::South::NONE;
                    } else if (prop.second == "low") {
                        south = Properties::South::LOW;
                    } else if (prop.second == "tall") {
                        south = Properties::South::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"south\" value");
                    }
                } else if (prop.first == "up") {
                    if (prop.second == "true") {
                        up = Properties::Up::TRUE;
                    } else if (prop.second == "false") {
                        up = Properties::Up::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"up\" value");
                    }
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else if (prop.first == "west") {
                    if (prop.second == "none") {
                        west = Properties::West::NONE;
                    } else if (prop.second == "low") {
                        west = Properties::West::LOW;
                    } else if (prop.second == "tall") {
                        west = Properties::West::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"west\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(east, north, south, up, waterlogged, west);
        }
    }

}
