#include "SandstoneWall.hpp"
#include <stdexcept>

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
                                    return 14988;
                                case Properties::West::LOW:
                                    return 14989;
                                case Properties::West::TALL:
                                    return 14990;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14991;
                                case Properties::West::LOW:
                                    return 14992;
                                case Properties::West::TALL:
                                    return 14993;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14994;
                                case Properties::West::LOW:
                                    return 14995;
                                case Properties::West::TALL:
                                    return 14996;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14997;
                                case Properties::West::LOW:
                                    return 14998;
                                case Properties::West::TALL:
                                    return 14999;
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
                                    return 15000;
                                case Properties::West::LOW:
                                    return 15001;
                                case Properties::West::TALL:
                                    return 15002;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15003;
                                case Properties::West::LOW:
                                    return 15004;
                                case Properties::West::TALL:
                                    return 15005;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15006;
                                case Properties::West::LOW:
                                    return 15007;
                                case Properties::West::TALL:
                                    return 15008;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15009;
                                case Properties::West::LOW:
                                    return 15010;
                                case Properties::West::TALL:
                                    return 15011;
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
                                    return 15012;
                                case Properties::West::LOW:
                                    return 15013;
                                case Properties::West::TALL:
                                    return 15014;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15015;
                                case Properties::West::LOW:
                                    return 15016;
                                case Properties::West::TALL:
                                    return 15017;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15018;
                                case Properties::West::LOW:
                                    return 15019;
                                case Properties::West::TALL:
                                    return 15020;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15021;
                                case Properties::West::LOW:
                                    return 15022;
                                case Properties::West::TALL:
                                    return 15023;
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
                                    return 15024;
                                case Properties::West::LOW:
                                    return 15025;
                                case Properties::West::TALL:
                                    return 15026;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15027;
                                case Properties::West::LOW:
                                    return 15028;
                                case Properties::West::TALL:
                                    return 15029;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15030;
                                case Properties::West::LOW:
                                    return 15031;
                                case Properties::West::TALL:
                                    return 15032;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15033;
                                case Properties::West::LOW:
                                    return 15034;
                                case Properties::West::TALL:
                                    return 15035;
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
                                    return 15036;
                                case Properties::West::LOW:
                                    return 15037;
                                case Properties::West::TALL:
                                    return 15038;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15039;
                                case Properties::West::LOW:
                                    return 15040;
                                case Properties::West::TALL:
                                    return 15041;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15042;
                                case Properties::West::LOW:
                                    return 15043;
                                case Properties::West::TALL:
                                    return 15044;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15045;
                                case Properties::West::LOW:
                                    return 15046;
                                case Properties::West::TALL:
                                    return 15047;
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
                                    return 15048;
                                case Properties::West::LOW:
                                    return 15049;
                                case Properties::West::TALL:
                                    return 15050;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15051;
                                case Properties::West::LOW:
                                    return 15052;
                                case Properties::West::TALL:
                                    return 15053;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15054;
                                case Properties::West::LOW:
                                    return 15055;
                                case Properties::West::TALL:
                                    return 15056;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15057;
                                case Properties::West::LOW:
                                    return 15058;
                                case Properties::West::TALL:
                                    return 15059;
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
                                    return 15060;
                                case Properties::West::LOW:
                                    return 15061;
                                case Properties::West::TALL:
                                    return 15062;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15063;
                                case Properties::West::LOW:
                                    return 15064;
                                case Properties::West::TALL:
                                    return 15065;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15066;
                                case Properties::West::LOW:
                                    return 15067;
                                case Properties::West::TALL:
                                    return 15068;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15069;
                                case Properties::West::LOW:
                                    return 15070;
                                case Properties::West::TALL:
                                    return 15071;
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
                                    return 15072;
                                case Properties::West::LOW:
                                    return 15073;
                                case Properties::West::TALL:
                                    return 15074;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15075;
                                case Properties::West::LOW:
                                    return 15076;
                                case Properties::West::TALL:
                                    return 15077;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15078;
                                case Properties::West::LOW:
                                    return 15079;
                                case Properties::West::TALL:
                                    return 15080;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15081;
                                case Properties::West::LOW:
                                    return 15082;
                                case Properties::West::TALL:
                                    return 15083;
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
                                    return 15084;
                                case Properties::West::LOW:
                                    return 15085;
                                case Properties::West::TALL:
                                    return 15086;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15087;
                                case Properties::West::LOW:
                                    return 15088;
                                case Properties::West::TALL:
                                    return 15089;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15090;
                                case Properties::West::LOW:
                                    return 15091;
                                case Properties::West::TALL:
                                    return 15092;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15093;
                                case Properties::West::LOW:
                                    return 15094;
                                case Properties::West::TALL:
                                    return 15095;
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
                                    return 15096;
                                case Properties::West::LOW:
                                    return 15097;
                                case Properties::West::TALL:
                                    return 15098;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15099;
                                case Properties::West::LOW:
                                    return 15100;
                                case Properties::West::TALL:
                                    return 15101;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15102;
                                case Properties::West::LOW:
                                    return 15103;
                                case Properties::West::TALL:
                                    return 15104;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15105;
                                case Properties::West::LOW:
                                    return 15106;
                                case Properties::West::TALL:
                                    return 15107;
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
                                    return 15108;
                                case Properties::West::LOW:
                                    return 15109;
                                case Properties::West::TALL:
                                    return 15110;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15111;
                                case Properties::West::LOW:
                                    return 15112;
                                case Properties::West::TALL:
                                    return 15113;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15114;
                                case Properties::West::LOW:
                                    return 15115;
                                case Properties::West::TALL:
                                    return 15116;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15117;
                                case Properties::West::LOW:
                                    return 15118;
                                case Properties::West::TALL:
                                    return 15119;
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
                                    return 15120;
                                case Properties::West::LOW:
                                    return 15121;
                                case Properties::West::TALL:
                                    return 15122;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15123;
                                case Properties::West::LOW:
                                    return 15124;
                                case Properties::West::TALL:
                                    return 15125;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15126;
                                case Properties::West::LOW:
                                    return 15127;
                                case Properties::West::TALL:
                                    return 15128;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15129;
                                case Properties::West::LOW:
                                    return 15130;
                                case Properties::West::TALL:
                                    return 15131;
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
                                    return 15132;
                                case Properties::West::LOW:
                                    return 15133;
                                case Properties::West::TALL:
                                    return 15134;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15135;
                                case Properties::West::LOW:
                                    return 15136;
                                case Properties::West::TALL:
                                    return 15137;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15138;
                                case Properties::West::LOW:
                                    return 15139;
                                case Properties::West::TALL:
                                    return 15140;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15141;
                                case Properties::West::LOW:
                                    return 15142;
                                case Properties::West::TALL:
                                    return 15143;
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
                                    return 15144;
                                case Properties::West::LOW:
                                    return 15145;
                                case Properties::West::TALL:
                                    return 15146;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15147;
                                case Properties::West::LOW:
                                    return 15148;
                                case Properties::West::TALL:
                                    return 15149;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15150;
                                case Properties::West::LOW:
                                    return 15151;
                                case Properties::West::TALL:
                                    return 15152;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15153;
                                case Properties::West::LOW:
                                    return 15154;
                                case Properties::West::TALL:
                                    return 15155;
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
                                    return 15156;
                                case Properties::West::LOW:
                                    return 15157;
                                case Properties::West::TALL:
                                    return 15158;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15159;
                                case Properties::West::LOW:
                                    return 15160;
                                case Properties::West::TALL:
                                    return 15161;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15162;
                                case Properties::West::LOW:
                                    return 15163;
                                case Properties::West::TALL:
                                    return 15164;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15165;
                                case Properties::West::LOW:
                                    return 15166;
                                case Properties::West::TALL:
                                    return 15167;
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
                                    return 15168;
                                case Properties::West::LOW:
                                    return 15169;
                                case Properties::West::TALL:
                                    return 15170;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15171;
                                case Properties::West::LOW:
                                    return 15172;
                                case Properties::West::TALL:
                                    return 15173;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15174;
                                case Properties::West::LOW:
                                    return 15175;
                                case Properties::West::TALL:
                                    return 15176;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15177;
                                case Properties::West::LOW:
                                    return 15178;
                                case Properties::West::TALL:
                                    return 15179;
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
                                    return 15180;
                                case Properties::West::LOW:
                                    return 15181;
                                case Properties::West::TALL:
                                    return 15182;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15183;
                                case Properties::West::LOW:
                                    return 15184;
                                case Properties::West::TALL:
                                    return 15185;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15186;
                                case Properties::West::LOW:
                                    return 15187;
                                case Properties::West::TALL:
                                    return 15188;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15189;
                                case Properties::West::LOW:
                                    return 15190;
                                case Properties::West::TALL:
                                    return 15191;
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
                                    return 15192;
                                case Properties::West::LOW:
                                    return 15193;
                                case Properties::West::TALL:
                                    return 15194;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15195;
                                case Properties::West::LOW:
                                    return 15196;
                                case Properties::West::TALL:
                                    return 15197;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15198;
                                case Properties::West::LOW:
                                    return 15199;
                                case Properties::West::TALL:
                                    return 15200;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15201;
                                case Properties::West::LOW:
                                    return 15202;
                                case Properties::West::TALL:
                                    return 15203;
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
                                    return 15204;
                                case Properties::West::LOW:
                                    return 15205;
                                case Properties::West::TALL:
                                    return 15206;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15207;
                                case Properties::West::LOW:
                                    return 15208;
                                case Properties::West::TALL:
                                    return 15209;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15210;
                                case Properties::West::LOW:
                                    return 15211;
                                case Properties::West::TALL:
                                    return 15212;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15213;
                                case Properties::West::LOW:
                                    return 15214;
                                case Properties::West::TALL:
                                    return 15215;
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
                                    return 15216;
                                case Properties::West::LOW:
                                    return 15217;
                                case Properties::West::TALL:
                                    return 15218;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15219;
                                case Properties::West::LOW:
                                    return 15220;
                                case Properties::West::TALL:
                                    return 15221;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15222;
                                case Properties::West::LOW:
                                    return 15223;
                                case Properties::West::TALL:
                                    return 15224;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15225;
                                case Properties::West::LOW:
                                    return 15226;
                                case Properties::West::TALL:
                                    return 15227;
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
                                    return 15228;
                                case Properties::West::LOW:
                                    return 15229;
                                case Properties::West::TALL:
                                    return 15230;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15231;
                                case Properties::West::LOW:
                                    return 15232;
                                case Properties::West::TALL:
                                    return 15233;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15234;
                                case Properties::West::LOW:
                                    return 15235;
                                case Properties::West::TALL:
                                    return 15236;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15237;
                                case Properties::West::LOW:
                                    return 15238;
                                case Properties::West::TALL:
                                    return 15239;
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
                                    return 15240;
                                case Properties::West::LOW:
                                    return 15241;
                                case Properties::West::TALL:
                                    return 15242;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15243;
                                case Properties::West::LOW:
                                    return 15244;
                                case Properties::West::TALL:
                                    return 15245;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15246;
                                case Properties::West::LOW:
                                    return 15247;
                                case Properties::West::TALL:
                                    return 15248;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15249;
                                case Properties::West::LOW:
                                    return 15250;
                                case Properties::West::TALL:
                                    return 15251;
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
                                    return 15252;
                                case Properties::West::LOW:
                                    return 15253;
                                case Properties::West::TALL:
                                    return 15254;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15255;
                                case Properties::West::LOW:
                                    return 15256;
                                case Properties::West::TALL:
                                    return 15257;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15258;
                                case Properties::West::LOW:
                                    return 15259;
                                case Properties::West::TALL:
                                    return 15260;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15261;
                                case Properties::West::LOW:
                                    return 15262;
                                case Properties::West::TALL:
                                    return 15263;
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
                                    return 15264;
                                case Properties::West::LOW:
                                    return 15265;
                                case Properties::West::TALL:
                                    return 15266;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15267;
                                case Properties::West::LOW:
                                    return 15268;
                                case Properties::West::TALL:
                                    return 15269;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15270;
                                case Properties::West::LOW:
                                    return 15271;
                                case Properties::West::TALL:
                                    return 15272;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15273;
                                case Properties::West::LOW:
                                    return 15274;
                                case Properties::West::TALL:
                                    return 15275;
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
                                    return 15276;
                                case Properties::West::LOW:
                                    return 15277;
                                case Properties::West::TALL:
                                    return 15278;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15279;
                                case Properties::West::LOW:
                                    return 15280;
                                case Properties::West::TALL:
                                    return 15281;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15282;
                                case Properties::West::LOW:
                                    return 15283;
                                case Properties::West::TALL:
                                    return 15284;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15285;
                                case Properties::West::LOW:
                                    return 15286;
                                case Properties::West::TALL:
                                    return 15287;
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
                                    return 15288;
                                case Properties::West::LOW:
                                    return 15289;
                                case Properties::West::TALL:
                                    return 15290;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15291;
                                case Properties::West::LOW:
                                    return 15292;
                                case Properties::West::TALL:
                                    return 15293;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15294;
                                case Properties::West::LOW:
                                    return 15295;
                                case Properties::West::TALL:
                                    return 15296;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15297;
                                case Properties::West::LOW:
                                    return 15298;
                                case Properties::West::TALL:
                                    return 15299;
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
                                    return 15300;
                                case Properties::West::LOW:
                                    return 15301;
                                case Properties::West::TALL:
                                    return 15302;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15303;
                                case Properties::West::LOW:
                                    return 15304;
                                case Properties::West::TALL:
                                    return 15305;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15306;
                                case Properties::West::LOW:
                                    return 15307;
                                case Properties::West::TALL:
                                    return 15308;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15309;
                                case Properties::West::LOW:
                                    return 15310;
                                case Properties::West::TALL:
                                    return 15311;
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
