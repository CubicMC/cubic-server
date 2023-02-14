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
                                    return 13044;
                                case Properties::West::LOW:
                                    return 13045;
                                case Properties::West::TALL:
                                    return 13046;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13047;
                                case Properties::West::LOW:
                                    return 13048;
                                case Properties::West::TALL:
                                    return 13049;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13050;
                                case Properties::West::LOW:
                                    return 13051;
                                case Properties::West::TALL:
                                    return 13052;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13053;
                                case Properties::West::LOW:
                                    return 13054;
                                case Properties::West::TALL:
                                    return 13055;
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
                                    return 13056;
                                case Properties::West::LOW:
                                    return 13057;
                                case Properties::West::TALL:
                                    return 13058;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13059;
                                case Properties::West::LOW:
                                    return 13060;
                                case Properties::West::TALL:
                                    return 13061;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13062;
                                case Properties::West::LOW:
                                    return 13063;
                                case Properties::West::TALL:
                                    return 13064;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13065;
                                case Properties::West::LOW:
                                    return 13066;
                                case Properties::West::TALL:
                                    return 13067;
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
                                    return 13068;
                                case Properties::West::LOW:
                                    return 13069;
                                case Properties::West::TALL:
                                    return 13070;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13071;
                                case Properties::West::LOW:
                                    return 13072;
                                case Properties::West::TALL:
                                    return 13073;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13074;
                                case Properties::West::LOW:
                                    return 13075;
                                case Properties::West::TALL:
                                    return 13076;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13077;
                                case Properties::West::LOW:
                                    return 13078;
                                case Properties::West::TALL:
                                    return 13079;
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
                                    return 13080;
                                case Properties::West::LOW:
                                    return 13081;
                                case Properties::West::TALL:
                                    return 13082;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13083;
                                case Properties::West::LOW:
                                    return 13084;
                                case Properties::West::TALL:
                                    return 13085;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13086;
                                case Properties::West::LOW:
                                    return 13087;
                                case Properties::West::TALL:
                                    return 13088;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13089;
                                case Properties::West::LOW:
                                    return 13090;
                                case Properties::West::TALL:
                                    return 13091;
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
                                    return 13092;
                                case Properties::West::LOW:
                                    return 13093;
                                case Properties::West::TALL:
                                    return 13094;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13095;
                                case Properties::West::LOW:
                                    return 13096;
                                case Properties::West::TALL:
                                    return 13097;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13098;
                                case Properties::West::LOW:
                                    return 13099;
                                case Properties::West::TALL:
                                    return 13100;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13101;
                                case Properties::West::LOW:
                                    return 13102;
                                case Properties::West::TALL:
                                    return 13103;
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
                                    return 13104;
                                case Properties::West::LOW:
                                    return 13105;
                                case Properties::West::TALL:
                                    return 13106;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13107;
                                case Properties::West::LOW:
                                    return 13108;
                                case Properties::West::TALL:
                                    return 13109;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13110;
                                case Properties::West::LOW:
                                    return 13111;
                                case Properties::West::TALL:
                                    return 13112;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13113;
                                case Properties::West::LOW:
                                    return 13114;
                                case Properties::West::TALL:
                                    return 13115;
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
                                    return 13116;
                                case Properties::West::LOW:
                                    return 13117;
                                case Properties::West::TALL:
                                    return 13118;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13119;
                                case Properties::West::LOW:
                                    return 13120;
                                case Properties::West::TALL:
                                    return 13121;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13122;
                                case Properties::West::LOW:
                                    return 13123;
                                case Properties::West::TALL:
                                    return 13124;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13125;
                                case Properties::West::LOW:
                                    return 13126;
                                case Properties::West::TALL:
                                    return 13127;
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
                                    return 13128;
                                case Properties::West::LOW:
                                    return 13129;
                                case Properties::West::TALL:
                                    return 13130;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13131;
                                case Properties::West::LOW:
                                    return 13132;
                                case Properties::West::TALL:
                                    return 13133;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13134;
                                case Properties::West::LOW:
                                    return 13135;
                                case Properties::West::TALL:
                                    return 13136;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13137;
                                case Properties::West::LOW:
                                    return 13138;
                                case Properties::West::TALL:
                                    return 13139;
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
                                    return 13140;
                                case Properties::West::LOW:
                                    return 13141;
                                case Properties::West::TALL:
                                    return 13142;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13143;
                                case Properties::West::LOW:
                                    return 13144;
                                case Properties::West::TALL:
                                    return 13145;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13146;
                                case Properties::West::LOW:
                                    return 13147;
                                case Properties::West::TALL:
                                    return 13148;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13149;
                                case Properties::West::LOW:
                                    return 13150;
                                case Properties::West::TALL:
                                    return 13151;
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
                                    return 13152;
                                case Properties::West::LOW:
                                    return 13153;
                                case Properties::West::TALL:
                                    return 13154;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13155;
                                case Properties::West::LOW:
                                    return 13156;
                                case Properties::West::TALL:
                                    return 13157;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13158;
                                case Properties::West::LOW:
                                    return 13159;
                                case Properties::West::TALL:
                                    return 13160;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13161;
                                case Properties::West::LOW:
                                    return 13162;
                                case Properties::West::TALL:
                                    return 13163;
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
                                    return 13164;
                                case Properties::West::LOW:
                                    return 13165;
                                case Properties::West::TALL:
                                    return 13166;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13167;
                                case Properties::West::LOW:
                                    return 13168;
                                case Properties::West::TALL:
                                    return 13169;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13170;
                                case Properties::West::LOW:
                                    return 13171;
                                case Properties::West::TALL:
                                    return 13172;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13173;
                                case Properties::West::LOW:
                                    return 13174;
                                case Properties::West::TALL:
                                    return 13175;
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
                                    return 13176;
                                case Properties::West::LOW:
                                    return 13177;
                                case Properties::West::TALL:
                                    return 13178;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13179;
                                case Properties::West::LOW:
                                    return 13180;
                                case Properties::West::TALL:
                                    return 13181;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13182;
                                case Properties::West::LOW:
                                    return 13183;
                                case Properties::West::TALL:
                                    return 13184;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13185;
                                case Properties::West::LOW:
                                    return 13186;
                                case Properties::West::TALL:
                                    return 13187;
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
                                    return 13188;
                                case Properties::West::LOW:
                                    return 13189;
                                case Properties::West::TALL:
                                    return 13190;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13191;
                                case Properties::West::LOW:
                                    return 13192;
                                case Properties::West::TALL:
                                    return 13193;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13194;
                                case Properties::West::LOW:
                                    return 13195;
                                case Properties::West::TALL:
                                    return 13196;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13197;
                                case Properties::West::LOW:
                                    return 13198;
                                case Properties::West::TALL:
                                    return 13199;
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
                                    return 13200;
                                case Properties::West::LOW:
                                    return 13201;
                                case Properties::West::TALL:
                                    return 13202;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13203;
                                case Properties::West::LOW:
                                    return 13204;
                                case Properties::West::TALL:
                                    return 13205;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13206;
                                case Properties::West::LOW:
                                    return 13207;
                                case Properties::West::TALL:
                                    return 13208;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13209;
                                case Properties::West::LOW:
                                    return 13210;
                                case Properties::West::TALL:
                                    return 13211;
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
                                    return 13212;
                                case Properties::West::LOW:
                                    return 13213;
                                case Properties::West::TALL:
                                    return 13214;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13215;
                                case Properties::West::LOW:
                                    return 13216;
                                case Properties::West::TALL:
                                    return 13217;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13218;
                                case Properties::West::LOW:
                                    return 13219;
                                case Properties::West::TALL:
                                    return 13220;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13221;
                                case Properties::West::LOW:
                                    return 13222;
                                case Properties::West::TALL:
                                    return 13223;
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
                                    return 13224;
                                case Properties::West::LOW:
                                    return 13225;
                                case Properties::West::TALL:
                                    return 13226;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13227;
                                case Properties::West::LOW:
                                    return 13228;
                                case Properties::West::TALL:
                                    return 13229;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13230;
                                case Properties::West::LOW:
                                    return 13231;
                                case Properties::West::TALL:
                                    return 13232;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13233;
                                case Properties::West::LOW:
                                    return 13234;
                                case Properties::West::TALL:
                                    return 13235;
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
                                    return 13236;
                                case Properties::West::LOW:
                                    return 13237;
                                case Properties::West::TALL:
                                    return 13238;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13239;
                                case Properties::West::LOW:
                                    return 13240;
                                case Properties::West::TALL:
                                    return 13241;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13242;
                                case Properties::West::LOW:
                                    return 13243;
                                case Properties::West::TALL:
                                    return 13244;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13245;
                                case Properties::West::LOW:
                                    return 13246;
                                case Properties::West::TALL:
                                    return 13247;
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
                                    return 13248;
                                case Properties::West::LOW:
                                    return 13249;
                                case Properties::West::TALL:
                                    return 13250;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13251;
                                case Properties::West::LOW:
                                    return 13252;
                                case Properties::West::TALL:
                                    return 13253;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13254;
                                case Properties::West::LOW:
                                    return 13255;
                                case Properties::West::TALL:
                                    return 13256;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13257;
                                case Properties::West::LOW:
                                    return 13258;
                                case Properties::West::TALL:
                                    return 13259;
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
                                    return 13260;
                                case Properties::West::LOW:
                                    return 13261;
                                case Properties::West::TALL:
                                    return 13262;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13263;
                                case Properties::West::LOW:
                                    return 13264;
                                case Properties::West::TALL:
                                    return 13265;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13266;
                                case Properties::West::LOW:
                                    return 13267;
                                case Properties::West::TALL:
                                    return 13268;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13269;
                                case Properties::West::LOW:
                                    return 13270;
                                case Properties::West::TALL:
                                    return 13271;
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
                                    return 13272;
                                case Properties::West::LOW:
                                    return 13273;
                                case Properties::West::TALL:
                                    return 13274;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13275;
                                case Properties::West::LOW:
                                    return 13276;
                                case Properties::West::TALL:
                                    return 13277;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13278;
                                case Properties::West::LOW:
                                    return 13279;
                                case Properties::West::TALL:
                                    return 13280;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13281;
                                case Properties::West::LOW:
                                    return 13282;
                                case Properties::West::TALL:
                                    return 13283;
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
                                    return 13284;
                                case Properties::West::LOW:
                                    return 13285;
                                case Properties::West::TALL:
                                    return 13286;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13287;
                                case Properties::West::LOW:
                                    return 13288;
                                case Properties::West::TALL:
                                    return 13289;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13290;
                                case Properties::West::LOW:
                                    return 13291;
                                case Properties::West::TALL:
                                    return 13292;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13293;
                                case Properties::West::LOW:
                                    return 13294;
                                case Properties::West::TALL:
                                    return 13295;
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
                                    return 13296;
                                case Properties::West::LOW:
                                    return 13297;
                                case Properties::West::TALL:
                                    return 13298;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13299;
                                case Properties::West::LOW:
                                    return 13300;
                                case Properties::West::TALL:
                                    return 13301;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13302;
                                case Properties::West::LOW:
                                    return 13303;
                                case Properties::West::TALL:
                                    return 13304;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13305;
                                case Properties::West::LOW:
                                    return 13306;
                                case Properties::West::TALL:
                                    return 13307;
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
                                    return 13308;
                                case Properties::West::LOW:
                                    return 13309;
                                case Properties::West::TALL:
                                    return 13310;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13311;
                                case Properties::West::LOW:
                                    return 13312;
                                case Properties::West::TALL:
                                    return 13313;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13314;
                                case Properties::West::LOW:
                                    return 13315;
                                case Properties::West::TALL:
                                    return 13316;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13317;
                                case Properties::West::LOW:
                                    return 13318;
                                case Properties::West::TALL:
                                    return 13319;
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
                                    return 13320;
                                case Properties::West::LOW:
                                    return 13321;
                                case Properties::West::TALL:
                                    return 13322;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13323;
                                case Properties::West::LOW:
                                    return 13324;
                                case Properties::West::TALL:
                                    return 13325;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13326;
                                case Properties::West::LOW:
                                    return 13327;
                                case Properties::West::TALL:
                                    return 13328;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13329;
                                case Properties::West::LOW:
                                    return 13330;
                                case Properties::West::TALL:
                                    return 13331;
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
                                    return 13332;
                                case Properties::West::LOW:
                                    return 13333;
                                case Properties::West::TALL:
                                    return 13334;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13335;
                                case Properties::West::LOW:
                                    return 13336;
                                case Properties::West::TALL:
                                    return 13337;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13338;
                                case Properties::West::LOW:
                                    return 13339;
                                case Properties::West::TALL:
                                    return 13340;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13341;
                                case Properties::West::LOW:
                                    return 13342;
                                case Properties::West::TALL:
                                    return 13343;
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
                                    return 13344;
                                case Properties::West::LOW:
                                    return 13345;
                                case Properties::West::TALL:
                                    return 13346;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13347;
                                case Properties::West::LOW:
                                    return 13348;
                                case Properties::West::TALL:
                                    return 13349;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13350;
                                case Properties::West::LOW:
                                    return 13351;
                                case Properties::West::TALL:
                                    return 13352;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13353;
                                case Properties::West::LOW:
                                    return 13354;
                                case Properties::West::TALL:
                                    return 13355;
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
                                    return 13356;
                                case Properties::West::LOW:
                                    return 13357;
                                case Properties::West::TALL:
                                    return 13358;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13359;
                                case Properties::West::LOW:
                                    return 13360;
                                case Properties::West::TALL:
                                    return 13361;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13362;
                                case Properties::West::LOW:
                                    return 13363;
                                case Properties::West::TALL:
                                    return 13364;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13365;
                                case Properties::West::LOW:
                                    return 13366;
                                case Properties::West::TALL:
                                    return 13367;
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
