#include "PrismarineWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PrismarineWall {
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
                                    return 12072;
                                case Properties::West::LOW:
                                    return 12073;
                                case Properties::West::TALL:
                                    return 12074;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12075;
                                case Properties::West::LOW:
                                    return 12076;
                                case Properties::West::TALL:
                                    return 12077;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12078;
                                case Properties::West::LOW:
                                    return 12079;
                                case Properties::West::TALL:
                                    return 12080;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12081;
                                case Properties::West::LOW:
                                    return 12082;
                                case Properties::West::TALL:
                                    return 12083;
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
                                    return 12084;
                                case Properties::West::LOW:
                                    return 12085;
                                case Properties::West::TALL:
                                    return 12086;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12087;
                                case Properties::West::LOW:
                                    return 12088;
                                case Properties::West::TALL:
                                    return 12089;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12090;
                                case Properties::West::LOW:
                                    return 12091;
                                case Properties::West::TALL:
                                    return 12092;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12093;
                                case Properties::West::LOW:
                                    return 12094;
                                case Properties::West::TALL:
                                    return 12095;
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
                                    return 12096;
                                case Properties::West::LOW:
                                    return 12097;
                                case Properties::West::TALL:
                                    return 12098;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12099;
                                case Properties::West::LOW:
                                    return 12100;
                                case Properties::West::TALL:
                                    return 12101;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12102;
                                case Properties::West::LOW:
                                    return 12103;
                                case Properties::West::TALL:
                                    return 12104;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12105;
                                case Properties::West::LOW:
                                    return 12106;
                                case Properties::West::TALL:
                                    return 12107;
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
                                    return 12108;
                                case Properties::West::LOW:
                                    return 12109;
                                case Properties::West::TALL:
                                    return 12110;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12111;
                                case Properties::West::LOW:
                                    return 12112;
                                case Properties::West::TALL:
                                    return 12113;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12114;
                                case Properties::West::LOW:
                                    return 12115;
                                case Properties::West::TALL:
                                    return 12116;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12117;
                                case Properties::West::LOW:
                                    return 12118;
                                case Properties::West::TALL:
                                    return 12119;
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
                                    return 12120;
                                case Properties::West::LOW:
                                    return 12121;
                                case Properties::West::TALL:
                                    return 12122;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12123;
                                case Properties::West::LOW:
                                    return 12124;
                                case Properties::West::TALL:
                                    return 12125;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12126;
                                case Properties::West::LOW:
                                    return 12127;
                                case Properties::West::TALL:
                                    return 12128;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12129;
                                case Properties::West::LOW:
                                    return 12130;
                                case Properties::West::TALL:
                                    return 12131;
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
                                    return 12132;
                                case Properties::West::LOW:
                                    return 12133;
                                case Properties::West::TALL:
                                    return 12134;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12135;
                                case Properties::West::LOW:
                                    return 12136;
                                case Properties::West::TALL:
                                    return 12137;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12138;
                                case Properties::West::LOW:
                                    return 12139;
                                case Properties::West::TALL:
                                    return 12140;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12141;
                                case Properties::West::LOW:
                                    return 12142;
                                case Properties::West::TALL:
                                    return 12143;
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
                                    return 12144;
                                case Properties::West::LOW:
                                    return 12145;
                                case Properties::West::TALL:
                                    return 12146;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12147;
                                case Properties::West::LOW:
                                    return 12148;
                                case Properties::West::TALL:
                                    return 12149;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12150;
                                case Properties::West::LOW:
                                    return 12151;
                                case Properties::West::TALL:
                                    return 12152;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12153;
                                case Properties::West::LOW:
                                    return 12154;
                                case Properties::West::TALL:
                                    return 12155;
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
                                    return 12156;
                                case Properties::West::LOW:
                                    return 12157;
                                case Properties::West::TALL:
                                    return 12158;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12159;
                                case Properties::West::LOW:
                                    return 12160;
                                case Properties::West::TALL:
                                    return 12161;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12162;
                                case Properties::West::LOW:
                                    return 12163;
                                case Properties::West::TALL:
                                    return 12164;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12165;
                                case Properties::West::LOW:
                                    return 12166;
                                case Properties::West::TALL:
                                    return 12167;
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
                                    return 12168;
                                case Properties::West::LOW:
                                    return 12169;
                                case Properties::West::TALL:
                                    return 12170;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12171;
                                case Properties::West::LOW:
                                    return 12172;
                                case Properties::West::TALL:
                                    return 12173;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12174;
                                case Properties::West::LOW:
                                    return 12175;
                                case Properties::West::TALL:
                                    return 12176;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12177;
                                case Properties::West::LOW:
                                    return 12178;
                                case Properties::West::TALL:
                                    return 12179;
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
                                    return 12180;
                                case Properties::West::LOW:
                                    return 12181;
                                case Properties::West::TALL:
                                    return 12182;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12183;
                                case Properties::West::LOW:
                                    return 12184;
                                case Properties::West::TALL:
                                    return 12185;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12186;
                                case Properties::West::LOW:
                                    return 12187;
                                case Properties::West::TALL:
                                    return 12188;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12189;
                                case Properties::West::LOW:
                                    return 12190;
                                case Properties::West::TALL:
                                    return 12191;
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
                                    return 12192;
                                case Properties::West::LOW:
                                    return 12193;
                                case Properties::West::TALL:
                                    return 12194;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12195;
                                case Properties::West::LOW:
                                    return 12196;
                                case Properties::West::TALL:
                                    return 12197;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12198;
                                case Properties::West::LOW:
                                    return 12199;
                                case Properties::West::TALL:
                                    return 12200;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12201;
                                case Properties::West::LOW:
                                    return 12202;
                                case Properties::West::TALL:
                                    return 12203;
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
                                    return 12204;
                                case Properties::West::LOW:
                                    return 12205;
                                case Properties::West::TALL:
                                    return 12206;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12207;
                                case Properties::West::LOW:
                                    return 12208;
                                case Properties::West::TALL:
                                    return 12209;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12210;
                                case Properties::West::LOW:
                                    return 12211;
                                case Properties::West::TALL:
                                    return 12212;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12213;
                                case Properties::West::LOW:
                                    return 12214;
                                case Properties::West::TALL:
                                    return 12215;
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
                                    return 12216;
                                case Properties::West::LOW:
                                    return 12217;
                                case Properties::West::TALL:
                                    return 12218;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12219;
                                case Properties::West::LOW:
                                    return 12220;
                                case Properties::West::TALL:
                                    return 12221;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12222;
                                case Properties::West::LOW:
                                    return 12223;
                                case Properties::West::TALL:
                                    return 12224;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12225;
                                case Properties::West::LOW:
                                    return 12226;
                                case Properties::West::TALL:
                                    return 12227;
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
                                    return 12228;
                                case Properties::West::LOW:
                                    return 12229;
                                case Properties::West::TALL:
                                    return 12230;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12231;
                                case Properties::West::LOW:
                                    return 12232;
                                case Properties::West::TALL:
                                    return 12233;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12234;
                                case Properties::West::LOW:
                                    return 12235;
                                case Properties::West::TALL:
                                    return 12236;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12237;
                                case Properties::West::LOW:
                                    return 12238;
                                case Properties::West::TALL:
                                    return 12239;
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
                                    return 12240;
                                case Properties::West::LOW:
                                    return 12241;
                                case Properties::West::TALL:
                                    return 12242;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12243;
                                case Properties::West::LOW:
                                    return 12244;
                                case Properties::West::TALL:
                                    return 12245;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12246;
                                case Properties::West::LOW:
                                    return 12247;
                                case Properties::West::TALL:
                                    return 12248;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12249;
                                case Properties::West::LOW:
                                    return 12250;
                                case Properties::West::TALL:
                                    return 12251;
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
                                    return 12252;
                                case Properties::West::LOW:
                                    return 12253;
                                case Properties::West::TALL:
                                    return 12254;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12255;
                                case Properties::West::LOW:
                                    return 12256;
                                case Properties::West::TALL:
                                    return 12257;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12258;
                                case Properties::West::LOW:
                                    return 12259;
                                case Properties::West::TALL:
                                    return 12260;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12261;
                                case Properties::West::LOW:
                                    return 12262;
                                case Properties::West::TALL:
                                    return 12263;
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
                                    return 12264;
                                case Properties::West::LOW:
                                    return 12265;
                                case Properties::West::TALL:
                                    return 12266;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12267;
                                case Properties::West::LOW:
                                    return 12268;
                                case Properties::West::TALL:
                                    return 12269;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12270;
                                case Properties::West::LOW:
                                    return 12271;
                                case Properties::West::TALL:
                                    return 12272;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12273;
                                case Properties::West::LOW:
                                    return 12274;
                                case Properties::West::TALL:
                                    return 12275;
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
                                    return 12276;
                                case Properties::West::LOW:
                                    return 12277;
                                case Properties::West::TALL:
                                    return 12278;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12279;
                                case Properties::West::LOW:
                                    return 12280;
                                case Properties::West::TALL:
                                    return 12281;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12282;
                                case Properties::West::LOW:
                                    return 12283;
                                case Properties::West::TALL:
                                    return 12284;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12285;
                                case Properties::West::LOW:
                                    return 12286;
                                case Properties::West::TALL:
                                    return 12287;
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
                                    return 12288;
                                case Properties::West::LOW:
                                    return 12289;
                                case Properties::West::TALL:
                                    return 12290;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12291;
                                case Properties::West::LOW:
                                    return 12292;
                                case Properties::West::TALL:
                                    return 12293;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12294;
                                case Properties::West::LOW:
                                    return 12295;
                                case Properties::West::TALL:
                                    return 12296;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12297;
                                case Properties::West::LOW:
                                    return 12298;
                                case Properties::West::TALL:
                                    return 12299;
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
                                    return 12300;
                                case Properties::West::LOW:
                                    return 12301;
                                case Properties::West::TALL:
                                    return 12302;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12303;
                                case Properties::West::LOW:
                                    return 12304;
                                case Properties::West::TALL:
                                    return 12305;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12306;
                                case Properties::West::LOW:
                                    return 12307;
                                case Properties::West::TALL:
                                    return 12308;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12309;
                                case Properties::West::LOW:
                                    return 12310;
                                case Properties::West::TALL:
                                    return 12311;
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
                                    return 12312;
                                case Properties::West::LOW:
                                    return 12313;
                                case Properties::West::TALL:
                                    return 12314;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12315;
                                case Properties::West::LOW:
                                    return 12316;
                                case Properties::West::TALL:
                                    return 12317;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12318;
                                case Properties::West::LOW:
                                    return 12319;
                                case Properties::West::TALL:
                                    return 12320;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12321;
                                case Properties::West::LOW:
                                    return 12322;
                                case Properties::West::TALL:
                                    return 12323;
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
                                    return 12324;
                                case Properties::West::LOW:
                                    return 12325;
                                case Properties::West::TALL:
                                    return 12326;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12327;
                                case Properties::West::LOW:
                                    return 12328;
                                case Properties::West::TALL:
                                    return 12329;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12330;
                                case Properties::West::LOW:
                                    return 12331;
                                case Properties::West::TALL:
                                    return 12332;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12333;
                                case Properties::West::LOW:
                                    return 12334;
                                case Properties::West::TALL:
                                    return 12335;
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
                                    return 12336;
                                case Properties::West::LOW:
                                    return 12337;
                                case Properties::West::TALL:
                                    return 12338;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12339;
                                case Properties::West::LOW:
                                    return 12340;
                                case Properties::West::TALL:
                                    return 12341;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12342;
                                case Properties::West::LOW:
                                    return 12343;
                                case Properties::West::TALL:
                                    return 12344;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12345;
                                case Properties::West::LOW:
                                    return 12346;
                                case Properties::West::TALL:
                                    return 12347;
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
                                    return 12348;
                                case Properties::West::LOW:
                                    return 12349;
                                case Properties::West::TALL:
                                    return 12350;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12351;
                                case Properties::West::LOW:
                                    return 12352;
                                case Properties::West::TALL:
                                    return 12353;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12354;
                                case Properties::West::LOW:
                                    return 12355;
                                case Properties::West::TALL:
                                    return 12356;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12357;
                                case Properties::West::LOW:
                                    return 12358;
                                case Properties::West::TALL:
                                    return 12359;
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
                                    return 12360;
                                case Properties::West::LOW:
                                    return 12361;
                                case Properties::West::TALL:
                                    return 12362;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12363;
                                case Properties::West::LOW:
                                    return 12364;
                                case Properties::West::TALL:
                                    return 12365;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12366;
                                case Properties::West::LOW:
                                    return 12367;
                                case Properties::West::TALL:
                                    return 12368;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12369;
                                case Properties::West::LOW:
                                    return 12370;
                                case Properties::West::TALL:
                                    return 12371;
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
                                    return 12372;
                                case Properties::West::LOW:
                                    return 12373;
                                case Properties::West::TALL:
                                    return 12374;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12375;
                                case Properties::West::LOW:
                                    return 12376;
                                case Properties::West::TALL:
                                    return 12377;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12378;
                                case Properties::West::LOW:
                                    return 12379;
                                case Properties::West::TALL:
                                    return 12380;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12381;
                                case Properties::West::LOW:
                                    return 12382;
                                case Properties::West::TALL:
                                    return 12383;
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
                                    return 12384;
                                case Properties::West::LOW:
                                    return 12385;
                                case Properties::West::TALL:
                                    return 12386;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12387;
                                case Properties::West::LOW:
                                    return 12388;
                                case Properties::West::TALL:
                                    return 12389;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12390;
                                case Properties::West::LOW:
                                    return 12391;
                                case Properties::West::TALL:
                                    return 12392;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12393;
                                case Properties::West::LOW:
                                    return 12394;
                                case Properties::West::TALL:
                                    return 12395;
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
