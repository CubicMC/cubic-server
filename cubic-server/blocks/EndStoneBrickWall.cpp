#include "EndStoneBrickWall.hpp"
namespace Blocks {
    namespace EndStoneBrickWall {
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
                                    return 17096;
                                case Properties::West::LOW:
                                    return 17097;
                                case Properties::West::TALL:
                                    return 17098;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17099;
                                case Properties::West::LOW:
                                    return 17100;
                                case Properties::West::TALL:
                                    return 17101;
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
                                    return 17102;
                                case Properties::West::LOW:
                                    return 17103;
                                case Properties::West::TALL:
                                    return 17104;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17105;
                                case Properties::West::LOW:
                                    return 17106;
                                case Properties::West::TALL:
                                    return 17107;
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
                                    return 17108;
                                case Properties::West::LOW:
                                    return 17109;
                                case Properties::West::TALL:
                                    return 17110;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17111;
                                case Properties::West::LOW:
                                    return 17112;
                                case Properties::West::TALL:
                                    return 17113;
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
                                    return 17114;
                                case Properties::West::LOW:
                                    return 17115;
                                case Properties::West::TALL:
                                    return 17116;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17117;
                                case Properties::West::LOW:
                                    return 17118;
                                case Properties::West::TALL:
                                    return 17119;
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
                                    return 17120;
                                case Properties::West::LOW:
                                    return 17121;
                                case Properties::West::TALL:
                                    return 17122;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17123;
                                case Properties::West::LOW:
                                    return 17124;
                                case Properties::West::TALL:
                                    return 17125;
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
                                    return 17126;
                                case Properties::West::LOW:
                                    return 17127;
                                case Properties::West::TALL:
                                    return 17128;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17129;
                                case Properties::West::LOW:
                                    return 17130;
                                case Properties::West::TALL:
                                    return 17131;
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
                                    return 17132;
                                case Properties::West::LOW:
                                    return 17133;
                                case Properties::West::TALL:
                                    return 17134;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17135;
                                case Properties::West::LOW:
                                    return 17136;
                                case Properties::West::TALL:
                                    return 17137;
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
                                    return 17138;
                                case Properties::West::LOW:
                                    return 17139;
                                case Properties::West::TALL:
                                    return 17140;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17141;
                                case Properties::West::LOW:
                                    return 17142;
                                case Properties::West::TALL:
                                    return 17143;
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
                                    return 17144;
                                case Properties::West::LOW:
                                    return 17145;
                                case Properties::West::TALL:
                                    return 17146;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17147;
                                case Properties::West::LOW:
                                    return 17148;
                                case Properties::West::TALL:
                                    return 17149;
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
                                    return 17150;
                                case Properties::West::LOW:
                                    return 17151;
                                case Properties::West::TALL:
                                    return 17152;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17153;
                                case Properties::West::LOW:
                                    return 17154;
                                case Properties::West::TALL:
                                    return 17155;
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
                                    return 17156;
                                case Properties::West::LOW:
                                    return 17157;
                                case Properties::West::TALL:
                                    return 17158;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17159;
                                case Properties::West::LOW:
                                    return 17160;
                                case Properties::West::TALL:
                                    return 17161;
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
                                    return 17162;
                                case Properties::West::LOW:
                                    return 17163;
                                case Properties::West::TALL:
                                    return 17164;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17165;
                                case Properties::West::LOW:
                                    return 17166;
                                case Properties::West::TALL:
                                    return 17167;
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
                                    return 17168;
                                case Properties::West::LOW:
                                    return 17169;
                                case Properties::West::TALL:
                                    return 17170;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17171;
                                case Properties::West::LOW:
                                    return 17172;
                                case Properties::West::TALL:
                                    return 17173;
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
                                    return 17174;
                                case Properties::West::LOW:
                                    return 17175;
                                case Properties::West::TALL:
                                    return 17176;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17177;
                                case Properties::West::LOW:
                                    return 17178;
                                case Properties::West::TALL:
                                    return 17179;
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
                                    return 17180;
                                case Properties::West::LOW:
                                    return 17181;
                                case Properties::West::TALL:
                                    return 17182;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17183;
                                case Properties::West::LOW:
                                    return 17184;
                                case Properties::West::TALL:
                                    return 17185;
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
                                    return 17186;
                                case Properties::West::LOW:
                                    return 17187;
                                case Properties::West::TALL:
                                    return 17188;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17189;
                                case Properties::West::LOW:
                                    return 17190;
                                case Properties::West::TALL:
                                    return 17191;
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
                                    return 17192;
                                case Properties::West::LOW:
                                    return 17193;
                                case Properties::West::TALL:
                                    return 17194;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17195;
                                case Properties::West::LOW:
                                    return 17196;
                                case Properties::West::TALL:
                                    return 17197;
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
                                    return 17198;
                                case Properties::West::LOW:
                                    return 17199;
                                case Properties::West::TALL:
                                    return 17200;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17201;
                                case Properties::West::LOW:
                                    return 17202;
                                case Properties::West::TALL:
                                    return 17203;
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
                                    return 17204;
                                case Properties::West::LOW:
                                    return 17205;
                                case Properties::West::TALL:
                                    return 17206;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17207;
                                case Properties::West::LOW:
                                    return 17208;
                                case Properties::West::TALL:
                                    return 17209;
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
                                    return 17210;
                                case Properties::West::LOW:
                                    return 17211;
                                case Properties::West::TALL:
                                    return 17212;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17213;
                                case Properties::West::LOW:
                                    return 17214;
                                case Properties::West::TALL:
                                    return 17215;
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
                                    return 17216;
                                case Properties::West::LOW:
                                    return 17217;
                                case Properties::West::TALL:
                                    return 17218;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17219;
                                case Properties::West::LOW:
                                    return 17220;
                                case Properties::West::TALL:
                                    return 17221;
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
                                    return 17222;
                                case Properties::West::LOW:
                                    return 17223;
                                case Properties::West::TALL:
                                    return 17224;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17225;
                                case Properties::West::LOW:
                                    return 17226;
                                case Properties::West::TALL:
                                    return 17227;
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
                                    return 17228;
                                case Properties::West::LOW:
                                    return 17229;
                                case Properties::West::TALL:
                                    return 17230;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17231;
                                case Properties::West::LOW:
                                    return 17232;
                                case Properties::West::TALL:
                                    return 17233;
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
                                    return 17234;
                                case Properties::West::LOW:
                                    return 17235;
                                case Properties::West::TALL:
                                    return 17236;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17237;
                                case Properties::West::LOW:
                                    return 17238;
                                case Properties::West::TALL:
                                    return 17239;
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
                                    return 17240;
                                case Properties::West::LOW:
                                    return 17241;
                                case Properties::West::TALL:
                                    return 17242;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17243;
                                case Properties::West::LOW:
                                    return 17244;
                                case Properties::West::TALL:
                                    return 17245;
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
                                    return 17246;
                                case Properties::West::LOW:
                                    return 17247;
                                case Properties::West::TALL:
                                    return 17248;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17249;
                                case Properties::West::LOW:
                                    return 17250;
                                case Properties::West::TALL:
                                    return 17251;
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
                                    return 17252;
                                case Properties::West::LOW:
                                    return 17253;
                                case Properties::West::TALL:
                                    return 17254;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17255;
                                case Properties::West::LOW:
                                    return 17256;
                                case Properties::West::TALL:
                                    return 17257;
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
                                    return 17258;
                                case Properties::West::LOW:
                                    return 17259;
                                case Properties::West::TALL:
                                    return 17260;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17261;
                                case Properties::West::LOW:
                                    return 17262;
                                case Properties::West::TALL:
                                    return 17263;
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
                                    return 17264;
                                case Properties::West::LOW:
                                    return 17265;
                                case Properties::West::TALL:
                                    return 17266;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17267;
                                case Properties::West::LOW:
                                    return 17268;
                                case Properties::West::TALL:
                                    return 17269;
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
                                    return 17270;
                                case Properties::West::LOW:
                                    return 17271;
                                case Properties::West::TALL:
                                    return 17272;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17273;
                                case Properties::West::LOW:
                                    return 17274;
                                case Properties::West::TALL:
                                    return 17275;
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
                                    return 17276;
                                case Properties::West::LOW:
                                    return 17277;
                                case Properties::West::TALL:
                                    return 17278;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17279;
                                case Properties::West::LOW:
                                    return 17280;
                                case Properties::West::TALL:
                                    return 17281;
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
                                    return 17282;
                                case Properties::West::LOW:
                                    return 17283;
                                case Properties::West::TALL:
                                    return 17284;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17285;
                                case Properties::West::LOW:
                                    return 17286;
                                case Properties::West::TALL:
                                    return 17287;
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
                                    return 17288;
                                case Properties::West::LOW:
                                    return 17289;
                                case Properties::West::TALL:
                                    return 17290;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17291;
                                case Properties::West::LOW:
                                    return 17292;
                                case Properties::West::TALL:
                                    return 17293;
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
                                    return 17294;
                                case Properties::West::LOW:
                                    return 17295;
                                case Properties::West::TALL:
                                    return 17296;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17297;
                                case Properties::West::LOW:
                                    return 17298;
                                case Properties::West::TALL:
                                    return 17299;
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
                                    return 17300;
                                case Properties::West::LOW:
                                    return 17301;
                                case Properties::West::TALL:
                                    return 17302;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17303;
                                case Properties::West::LOW:
                                    return 17304;
                                case Properties::West::TALL:
                                    return 17305;
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
                                    return 17306;
                                case Properties::West::LOW:
                                    return 17307;
                                case Properties::West::TALL:
                                    return 17308;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17309;
                                case Properties::West::LOW:
                                    return 17310;
                                case Properties::West::TALL:
                                    return 17311;
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
                                    return 17312;
                                case Properties::West::LOW:
                                    return 17313;
                                case Properties::West::TALL:
                                    return 17314;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17315;
                                case Properties::West::LOW:
                                    return 17316;
                                case Properties::West::TALL:
                                    return 17317;
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
                                    return 17318;
                                case Properties::West::LOW:
                                    return 17319;
                                case Properties::West::TALL:
                                    return 17320;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17321;
                                case Properties::West::LOW:
                                    return 17322;
                                case Properties::West::TALL:
                                    return 17323;
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
                                    return 17324;
                                case Properties::West::LOW:
                                    return 17325;
                                case Properties::West::TALL:
                                    return 17326;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17327;
                                case Properties::West::LOW:
                                    return 17328;
                                case Properties::West::TALL:
                                    return 17329;
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
                                    return 17330;
                                case Properties::West::LOW:
                                    return 17331;
                                case Properties::West::TALL:
                                    return 17332;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17333;
                                case Properties::West::LOW:
                                    return 17334;
                                case Properties::West::TALL:
                                    return 17335;
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
                                    return 17336;
                                case Properties::West::LOW:
                                    return 17337;
                                case Properties::West::TALL:
                                    return 17338;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17339;
                                case Properties::West::LOW:
                                    return 17340;
                                case Properties::West::TALL:
                                    return 17341;
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
                                    return 17342;
                                case Properties::West::LOW:
                                    return 17343;
                                case Properties::West::TALL:
                                    return 17344;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17345;
                                case Properties::West::LOW:
                                    return 17346;
                                case Properties::West::TALL:
                                    return 17347;
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
                                    return 17348;
                                case Properties::West::LOW:
                                    return 17349;
                                case Properties::West::TALL:
                                    return 17350;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17351;
                                case Properties::West::LOW:
                                    return 17352;
                                case Properties::West::TALL:
                                    return 17353;
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
                                    return 17354;
                                case Properties::West::LOW:
                                    return 17355;
                                case Properties::West::TALL:
                                    return 17356;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17357;
                                case Properties::West::LOW:
                                    return 17358;
                                case Properties::West::TALL:
                                    return 17359;
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
                                    return 17360;
                                case Properties::West::LOW:
                                    return 17361;
                                case Properties::West::TALL:
                                    return 17362;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17363;
                                case Properties::West::LOW:
                                    return 17364;
                                case Properties::West::TALL:
                                    return 17365;
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
                                    return 17366;
                                case Properties::West::LOW:
                                    return 17367;
                                case Properties::West::TALL:
                                    return 17368;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17369;
                                case Properties::West::LOW:
                                    return 17370;
                                case Properties::West::TALL:
                                    return 17371;
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
                                    return 17372;
                                case Properties::West::LOW:
                                    return 17373;
                                case Properties::West::TALL:
                                    return 17374;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17375;
                                case Properties::West::LOW:
                                    return 17376;
                                case Properties::West::TALL:
                                    return 17377;
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
                                    return 17378;
                                case Properties::West::LOW:
                                    return 17379;
                                case Properties::West::TALL:
                                    return 17380;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17381;
                                case Properties::West::LOW:
                                    return 17382;
                                case Properties::West::TALL:
                                    return 17383;
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
                                    return 17384;
                                case Properties::West::LOW:
                                    return 17385;
                                case Properties::West::TALL:
                                    return 17386;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17387;
                                case Properties::West::LOW:
                                    return 17388;
                                case Properties::West::TALL:
                                    return 17389;
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
                                    return 17390;
                                case Properties::West::LOW:
                                    return 17391;
                                case Properties::West::TALL:
                                    return 17392;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17393;
                                case Properties::West::LOW:
                                    return 17394;
                                case Properties::West::TALL:
                                    return 17395;
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
                                    return 17396;
                                case Properties::West::LOW:
                                    return 17397;
                                case Properties::West::TALL:
                                    return 17398;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17399;
                                case Properties::West::LOW:
                                    return 17400;
                                case Properties::West::TALL:
                                    return 17401;
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
                                    return 17402;
                                case Properties::West::LOW:
                                    return 17403;
                                case Properties::West::TALL:
                                    return 17404;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17405;
                                case Properties::West::LOW:
                                    return 17406;
                                case Properties::West::TALL:
                                    return 17407;
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
                                    return 17408;
                                case Properties::West::LOW:
                                    return 17409;
                                case Properties::West::TALL:
                                    return 17410;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17411;
                                case Properties::West::LOW:
                                    return 17412;
                                case Properties::West::TALL:
                                    return 17413;
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
                                    return 17414;
                                case Properties::West::LOW:
                                    return 17415;
                                case Properties::West::TALL:
                                    return 17416;
                                default:
                                    return 0;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17417;
                                case Properties::West::LOW:
                                    return 17418;
                                case Properties::West::TALL:
                                    return 17419;
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
