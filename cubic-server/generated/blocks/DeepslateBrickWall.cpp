#include "DeepslateBrickWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeepslateBrickWall {
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
                                    return 21101;
                                case Properties::West::LOW:
                                    return 21102;
                                case Properties::West::TALL:
                                    return 21103;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21104;
                                case Properties::West::LOW:
                                    return 21105;
                                case Properties::West::TALL:
                                    return 21106;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21107;
                                case Properties::West::LOW:
                                    return 21108;
                                case Properties::West::TALL:
                                    return 21109;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21110;
                                case Properties::West::LOW:
                                    return 21111;
                                case Properties::West::TALL:
                                    return 21112;
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
                                    return 21113;
                                case Properties::West::LOW:
                                    return 21114;
                                case Properties::West::TALL:
                                    return 21115;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21116;
                                case Properties::West::LOW:
                                    return 21117;
                                case Properties::West::TALL:
                                    return 21118;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21119;
                                case Properties::West::LOW:
                                    return 21120;
                                case Properties::West::TALL:
                                    return 21121;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21122;
                                case Properties::West::LOW:
                                    return 21123;
                                case Properties::West::TALL:
                                    return 21124;
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
                                    return 21125;
                                case Properties::West::LOW:
                                    return 21126;
                                case Properties::West::TALL:
                                    return 21127;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21128;
                                case Properties::West::LOW:
                                    return 21129;
                                case Properties::West::TALL:
                                    return 21130;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21131;
                                case Properties::West::LOW:
                                    return 21132;
                                case Properties::West::TALL:
                                    return 21133;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21134;
                                case Properties::West::LOW:
                                    return 21135;
                                case Properties::West::TALL:
                                    return 21136;
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
                                    return 21137;
                                case Properties::West::LOW:
                                    return 21138;
                                case Properties::West::TALL:
                                    return 21139;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21140;
                                case Properties::West::LOW:
                                    return 21141;
                                case Properties::West::TALL:
                                    return 21142;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21143;
                                case Properties::West::LOW:
                                    return 21144;
                                case Properties::West::TALL:
                                    return 21145;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21146;
                                case Properties::West::LOW:
                                    return 21147;
                                case Properties::West::TALL:
                                    return 21148;
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
                                    return 21149;
                                case Properties::West::LOW:
                                    return 21150;
                                case Properties::West::TALL:
                                    return 21151;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21152;
                                case Properties::West::LOW:
                                    return 21153;
                                case Properties::West::TALL:
                                    return 21154;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21155;
                                case Properties::West::LOW:
                                    return 21156;
                                case Properties::West::TALL:
                                    return 21157;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21158;
                                case Properties::West::LOW:
                                    return 21159;
                                case Properties::West::TALL:
                                    return 21160;
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
                                    return 21161;
                                case Properties::West::LOW:
                                    return 21162;
                                case Properties::West::TALL:
                                    return 21163;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21164;
                                case Properties::West::LOW:
                                    return 21165;
                                case Properties::West::TALL:
                                    return 21166;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21167;
                                case Properties::West::LOW:
                                    return 21168;
                                case Properties::West::TALL:
                                    return 21169;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21170;
                                case Properties::West::LOW:
                                    return 21171;
                                case Properties::West::TALL:
                                    return 21172;
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
                                    return 21173;
                                case Properties::West::LOW:
                                    return 21174;
                                case Properties::West::TALL:
                                    return 21175;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21176;
                                case Properties::West::LOW:
                                    return 21177;
                                case Properties::West::TALL:
                                    return 21178;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21179;
                                case Properties::West::LOW:
                                    return 21180;
                                case Properties::West::TALL:
                                    return 21181;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21182;
                                case Properties::West::LOW:
                                    return 21183;
                                case Properties::West::TALL:
                                    return 21184;
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
                                    return 21185;
                                case Properties::West::LOW:
                                    return 21186;
                                case Properties::West::TALL:
                                    return 21187;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21188;
                                case Properties::West::LOW:
                                    return 21189;
                                case Properties::West::TALL:
                                    return 21190;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21191;
                                case Properties::West::LOW:
                                    return 21192;
                                case Properties::West::TALL:
                                    return 21193;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21194;
                                case Properties::West::LOW:
                                    return 21195;
                                case Properties::West::TALL:
                                    return 21196;
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
                                    return 21197;
                                case Properties::West::LOW:
                                    return 21198;
                                case Properties::West::TALL:
                                    return 21199;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21200;
                                case Properties::West::LOW:
                                    return 21201;
                                case Properties::West::TALL:
                                    return 21202;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21203;
                                case Properties::West::LOW:
                                    return 21204;
                                case Properties::West::TALL:
                                    return 21205;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21206;
                                case Properties::West::LOW:
                                    return 21207;
                                case Properties::West::TALL:
                                    return 21208;
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
                                    return 21209;
                                case Properties::West::LOW:
                                    return 21210;
                                case Properties::West::TALL:
                                    return 21211;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21212;
                                case Properties::West::LOW:
                                    return 21213;
                                case Properties::West::TALL:
                                    return 21214;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21215;
                                case Properties::West::LOW:
                                    return 21216;
                                case Properties::West::TALL:
                                    return 21217;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21218;
                                case Properties::West::LOW:
                                    return 21219;
                                case Properties::West::TALL:
                                    return 21220;
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
                                    return 21221;
                                case Properties::West::LOW:
                                    return 21222;
                                case Properties::West::TALL:
                                    return 21223;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21224;
                                case Properties::West::LOW:
                                    return 21225;
                                case Properties::West::TALL:
                                    return 21226;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21227;
                                case Properties::West::LOW:
                                    return 21228;
                                case Properties::West::TALL:
                                    return 21229;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21230;
                                case Properties::West::LOW:
                                    return 21231;
                                case Properties::West::TALL:
                                    return 21232;
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
                                    return 21233;
                                case Properties::West::LOW:
                                    return 21234;
                                case Properties::West::TALL:
                                    return 21235;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21236;
                                case Properties::West::LOW:
                                    return 21237;
                                case Properties::West::TALL:
                                    return 21238;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21239;
                                case Properties::West::LOW:
                                    return 21240;
                                case Properties::West::TALL:
                                    return 21241;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21242;
                                case Properties::West::LOW:
                                    return 21243;
                                case Properties::West::TALL:
                                    return 21244;
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
                                    return 21245;
                                case Properties::West::LOW:
                                    return 21246;
                                case Properties::West::TALL:
                                    return 21247;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21248;
                                case Properties::West::LOW:
                                    return 21249;
                                case Properties::West::TALL:
                                    return 21250;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21251;
                                case Properties::West::LOW:
                                    return 21252;
                                case Properties::West::TALL:
                                    return 21253;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21254;
                                case Properties::West::LOW:
                                    return 21255;
                                case Properties::West::TALL:
                                    return 21256;
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
                                    return 21257;
                                case Properties::West::LOW:
                                    return 21258;
                                case Properties::West::TALL:
                                    return 21259;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21260;
                                case Properties::West::LOW:
                                    return 21261;
                                case Properties::West::TALL:
                                    return 21262;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21263;
                                case Properties::West::LOW:
                                    return 21264;
                                case Properties::West::TALL:
                                    return 21265;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21266;
                                case Properties::West::LOW:
                                    return 21267;
                                case Properties::West::TALL:
                                    return 21268;
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
                                    return 21269;
                                case Properties::West::LOW:
                                    return 21270;
                                case Properties::West::TALL:
                                    return 21271;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21272;
                                case Properties::West::LOW:
                                    return 21273;
                                case Properties::West::TALL:
                                    return 21274;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21275;
                                case Properties::West::LOW:
                                    return 21276;
                                case Properties::West::TALL:
                                    return 21277;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21278;
                                case Properties::West::LOW:
                                    return 21279;
                                case Properties::West::TALL:
                                    return 21280;
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
                                    return 21281;
                                case Properties::West::LOW:
                                    return 21282;
                                case Properties::West::TALL:
                                    return 21283;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21284;
                                case Properties::West::LOW:
                                    return 21285;
                                case Properties::West::TALL:
                                    return 21286;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21287;
                                case Properties::West::LOW:
                                    return 21288;
                                case Properties::West::TALL:
                                    return 21289;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21290;
                                case Properties::West::LOW:
                                    return 21291;
                                case Properties::West::TALL:
                                    return 21292;
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
                                    return 21293;
                                case Properties::West::LOW:
                                    return 21294;
                                case Properties::West::TALL:
                                    return 21295;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21296;
                                case Properties::West::LOW:
                                    return 21297;
                                case Properties::West::TALL:
                                    return 21298;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21299;
                                case Properties::West::LOW:
                                    return 21300;
                                case Properties::West::TALL:
                                    return 21301;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21302;
                                case Properties::West::LOW:
                                    return 21303;
                                case Properties::West::TALL:
                                    return 21304;
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
                                    return 21305;
                                case Properties::West::LOW:
                                    return 21306;
                                case Properties::West::TALL:
                                    return 21307;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21308;
                                case Properties::West::LOW:
                                    return 21309;
                                case Properties::West::TALL:
                                    return 21310;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21311;
                                case Properties::West::LOW:
                                    return 21312;
                                case Properties::West::TALL:
                                    return 21313;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21314;
                                case Properties::West::LOW:
                                    return 21315;
                                case Properties::West::TALL:
                                    return 21316;
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
                                    return 21317;
                                case Properties::West::LOW:
                                    return 21318;
                                case Properties::West::TALL:
                                    return 21319;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21320;
                                case Properties::West::LOW:
                                    return 21321;
                                case Properties::West::TALL:
                                    return 21322;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21323;
                                case Properties::West::LOW:
                                    return 21324;
                                case Properties::West::TALL:
                                    return 21325;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21326;
                                case Properties::West::LOW:
                                    return 21327;
                                case Properties::West::TALL:
                                    return 21328;
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
                                    return 21329;
                                case Properties::West::LOW:
                                    return 21330;
                                case Properties::West::TALL:
                                    return 21331;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21332;
                                case Properties::West::LOW:
                                    return 21333;
                                case Properties::West::TALL:
                                    return 21334;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21335;
                                case Properties::West::LOW:
                                    return 21336;
                                case Properties::West::TALL:
                                    return 21337;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21338;
                                case Properties::West::LOW:
                                    return 21339;
                                case Properties::West::TALL:
                                    return 21340;
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
                                    return 21341;
                                case Properties::West::LOW:
                                    return 21342;
                                case Properties::West::TALL:
                                    return 21343;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21344;
                                case Properties::West::LOW:
                                    return 21345;
                                case Properties::West::TALL:
                                    return 21346;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21347;
                                case Properties::West::LOW:
                                    return 21348;
                                case Properties::West::TALL:
                                    return 21349;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21350;
                                case Properties::West::LOW:
                                    return 21351;
                                case Properties::West::TALL:
                                    return 21352;
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
                                    return 21353;
                                case Properties::West::LOW:
                                    return 21354;
                                case Properties::West::TALL:
                                    return 21355;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21356;
                                case Properties::West::LOW:
                                    return 21357;
                                case Properties::West::TALL:
                                    return 21358;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21359;
                                case Properties::West::LOW:
                                    return 21360;
                                case Properties::West::TALL:
                                    return 21361;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21362;
                                case Properties::West::LOW:
                                    return 21363;
                                case Properties::West::TALL:
                                    return 21364;
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
                                    return 21365;
                                case Properties::West::LOW:
                                    return 21366;
                                case Properties::West::TALL:
                                    return 21367;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21368;
                                case Properties::West::LOW:
                                    return 21369;
                                case Properties::West::TALL:
                                    return 21370;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21371;
                                case Properties::West::LOW:
                                    return 21372;
                                case Properties::West::TALL:
                                    return 21373;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21374;
                                case Properties::West::LOW:
                                    return 21375;
                                case Properties::West::TALL:
                                    return 21376;
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
                                    return 21377;
                                case Properties::West::LOW:
                                    return 21378;
                                case Properties::West::TALL:
                                    return 21379;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21380;
                                case Properties::West::LOW:
                                    return 21381;
                                case Properties::West::TALL:
                                    return 21382;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21383;
                                case Properties::West::LOW:
                                    return 21384;
                                case Properties::West::TALL:
                                    return 21385;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21386;
                                case Properties::West::LOW:
                                    return 21387;
                                case Properties::West::TALL:
                                    return 21388;
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
                                    return 21389;
                                case Properties::West::LOW:
                                    return 21390;
                                case Properties::West::TALL:
                                    return 21391;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21392;
                                case Properties::West::LOW:
                                    return 21393;
                                case Properties::West::TALL:
                                    return 21394;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21395;
                                case Properties::West::LOW:
                                    return 21396;
                                case Properties::West::TALL:
                                    return 21397;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21398;
                                case Properties::West::LOW:
                                    return 21399;
                                case Properties::West::TALL:
                                    return 21400;
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
                                    return 21401;
                                case Properties::West::LOW:
                                    return 21402;
                                case Properties::West::TALL:
                                    return 21403;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21404;
                                case Properties::West::LOW:
                                    return 21405;
                                case Properties::West::TALL:
                                    return 21406;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21407;
                                case Properties::West::LOW:
                                    return 21408;
                                case Properties::West::TALL:
                                    return 21409;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21410;
                                case Properties::West::LOW:
                                    return 21411;
                                case Properties::West::TALL:
                                    return 21412;
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
                                    return 21413;
                                case Properties::West::LOW:
                                    return 21414;
                                case Properties::West::TALL:
                                    return 21415;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21416;
                                case Properties::West::LOW:
                                    return 21417;
                                case Properties::West::TALL:
                                    return 21418;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21419;
                                case Properties::West::LOW:
                                    return 21420;
                                case Properties::West::TALL:
                                    return 21421;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21422;
                                case Properties::West::LOW:
                                    return 21423;
                                case Properties::West::TALL:
                                    return 21424;
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
