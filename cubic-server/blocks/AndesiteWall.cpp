#include "AndesiteWall.hpp"
#include <stdexcept>

namespace Blocks {
namespace AndesiteWall {
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
                            return 16124;
                        case Properties::West::LOW:
                            return 16125;
                        case Properties::West::TALL:
                            return 16126;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16127;
                        case Properties::West::LOW:
                            return 16128;
                        case Properties::West::TALL:
                            return 16129;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16130;
                        case Properties::West::LOW:
                            return 16131;
                        case Properties::West::TALL:
                            return 16132;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16133;
                        case Properties::West::LOW:
                            return 16134;
                        case Properties::West::TALL:
                            return 16135;
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
                            return 16136;
                        case Properties::West::LOW:
                            return 16137;
                        case Properties::West::TALL:
                            return 16138;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16139;
                        case Properties::West::LOW:
                            return 16140;
                        case Properties::West::TALL:
                            return 16141;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16142;
                        case Properties::West::LOW:
                            return 16143;
                        case Properties::West::TALL:
                            return 16144;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16145;
                        case Properties::West::LOW:
                            return 16146;
                        case Properties::West::TALL:
                            return 16147;
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
                            return 16148;
                        case Properties::West::LOW:
                            return 16149;
                        case Properties::West::TALL:
                            return 16150;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16151;
                        case Properties::West::LOW:
                            return 16152;
                        case Properties::West::TALL:
                            return 16153;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16154;
                        case Properties::West::LOW:
                            return 16155;
                        case Properties::West::TALL:
                            return 16156;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16157;
                        case Properties::West::LOW:
                            return 16158;
                        case Properties::West::TALL:
                            return 16159;
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
                            return 16160;
                        case Properties::West::LOW:
                            return 16161;
                        case Properties::West::TALL:
                            return 16162;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16163;
                        case Properties::West::LOW:
                            return 16164;
                        case Properties::West::TALL:
                            return 16165;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16166;
                        case Properties::West::LOW:
                            return 16167;
                        case Properties::West::TALL:
                            return 16168;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16169;
                        case Properties::West::LOW:
                            return 16170;
                        case Properties::West::TALL:
                            return 16171;
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
                            return 16172;
                        case Properties::West::LOW:
                            return 16173;
                        case Properties::West::TALL:
                            return 16174;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16175;
                        case Properties::West::LOW:
                            return 16176;
                        case Properties::West::TALL:
                            return 16177;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16178;
                        case Properties::West::LOW:
                            return 16179;
                        case Properties::West::TALL:
                            return 16180;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16181;
                        case Properties::West::LOW:
                            return 16182;
                        case Properties::West::TALL:
                            return 16183;
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
                            return 16184;
                        case Properties::West::LOW:
                            return 16185;
                        case Properties::West::TALL:
                            return 16186;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16187;
                        case Properties::West::LOW:
                            return 16188;
                        case Properties::West::TALL:
                            return 16189;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16190;
                        case Properties::West::LOW:
                            return 16191;
                        case Properties::West::TALL:
                            return 16192;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16193;
                        case Properties::West::LOW:
                            return 16194;
                        case Properties::West::TALL:
                            return 16195;
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
                            return 16196;
                        case Properties::West::LOW:
                            return 16197;
                        case Properties::West::TALL:
                            return 16198;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16199;
                        case Properties::West::LOW:
                            return 16200;
                        case Properties::West::TALL:
                            return 16201;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16202;
                        case Properties::West::LOW:
                            return 16203;
                        case Properties::West::TALL:
                            return 16204;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16205;
                        case Properties::West::LOW:
                            return 16206;
                        case Properties::West::TALL:
                            return 16207;
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
                            return 16208;
                        case Properties::West::LOW:
                            return 16209;
                        case Properties::West::TALL:
                            return 16210;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16211;
                        case Properties::West::LOW:
                            return 16212;
                        case Properties::West::TALL:
                            return 16213;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16214;
                        case Properties::West::LOW:
                            return 16215;
                        case Properties::West::TALL:
                            return 16216;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16217;
                        case Properties::West::LOW:
                            return 16218;
                        case Properties::West::TALL:
                            return 16219;
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
                            return 16220;
                        case Properties::West::LOW:
                            return 16221;
                        case Properties::West::TALL:
                            return 16222;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16223;
                        case Properties::West::LOW:
                            return 16224;
                        case Properties::West::TALL:
                            return 16225;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16226;
                        case Properties::West::LOW:
                            return 16227;
                        case Properties::West::TALL:
                            return 16228;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16229;
                        case Properties::West::LOW:
                            return 16230;
                        case Properties::West::TALL:
                            return 16231;
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
                            return 16232;
                        case Properties::West::LOW:
                            return 16233;
                        case Properties::West::TALL:
                            return 16234;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16235;
                        case Properties::West::LOW:
                            return 16236;
                        case Properties::West::TALL:
                            return 16237;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16238;
                        case Properties::West::LOW:
                            return 16239;
                        case Properties::West::TALL:
                            return 16240;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16241;
                        case Properties::West::LOW:
                            return 16242;
                        case Properties::West::TALL:
                            return 16243;
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
                            return 16244;
                        case Properties::West::LOW:
                            return 16245;
                        case Properties::West::TALL:
                            return 16246;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16247;
                        case Properties::West::LOW:
                            return 16248;
                        case Properties::West::TALL:
                            return 16249;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16250;
                        case Properties::West::LOW:
                            return 16251;
                        case Properties::West::TALL:
                            return 16252;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16253;
                        case Properties::West::LOW:
                            return 16254;
                        case Properties::West::TALL:
                            return 16255;
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
                            return 16256;
                        case Properties::West::LOW:
                            return 16257;
                        case Properties::West::TALL:
                            return 16258;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16259;
                        case Properties::West::LOW:
                            return 16260;
                        case Properties::West::TALL:
                            return 16261;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16262;
                        case Properties::West::LOW:
                            return 16263;
                        case Properties::West::TALL:
                            return 16264;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16265;
                        case Properties::West::LOW:
                            return 16266;
                        case Properties::West::TALL:
                            return 16267;
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
                            return 16268;
                        case Properties::West::LOW:
                            return 16269;
                        case Properties::West::TALL:
                            return 16270;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16271;
                        case Properties::West::LOW:
                            return 16272;
                        case Properties::West::TALL:
                            return 16273;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16274;
                        case Properties::West::LOW:
                            return 16275;
                        case Properties::West::TALL:
                            return 16276;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16277;
                        case Properties::West::LOW:
                            return 16278;
                        case Properties::West::TALL:
                            return 16279;
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
                            return 16280;
                        case Properties::West::LOW:
                            return 16281;
                        case Properties::West::TALL:
                            return 16282;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16283;
                        case Properties::West::LOW:
                            return 16284;
                        case Properties::West::TALL:
                            return 16285;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16286;
                        case Properties::West::LOW:
                            return 16287;
                        case Properties::West::TALL:
                            return 16288;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16289;
                        case Properties::West::LOW:
                            return 16290;
                        case Properties::West::TALL:
                            return 16291;
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
                            return 16292;
                        case Properties::West::LOW:
                            return 16293;
                        case Properties::West::TALL:
                            return 16294;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16295;
                        case Properties::West::LOW:
                            return 16296;
                        case Properties::West::TALL:
                            return 16297;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16298;
                        case Properties::West::LOW:
                            return 16299;
                        case Properties::West::TALL:
                            return 16300;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16301;
                        case Properties::West::LOW:
                            return 16302;
                        case Properties::West::TALL:
                            return 16303;
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
                            return 16304;
                        case Properties::West::LOW:
                            return 16305;
                        case Properties::West::TALL:
                            return 16306;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16307;
                        case Properties::West::LOW:
                            return 16308;
                        case Properties::West::TALL:
                            return 16309;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16310;
                        case Properties::West::LOW:
                            return 16311;
                        case Properties::West::TALL:
                            return 16312;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16313;
                        case Properties::West::LOW:
                            return 16314;
                        case Properties::West::TALL:
                            return 16315;
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
                            return 16316;
                        case Properties::West::LOW:
                            return 16317;
                        case Properties::West::TALL:
                            return 16318;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16319;
                        case Properties::West::LOW:
                            return 16320;
                        case Properties::West::TALL:
                            return 16321;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16322;
                        case Properties::West::LOW:
                            return 16323;
                        case Properties::West::TALL:
                            return 16324;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16325;
                        case Properties::West::LOW:
                            return 16326;
                        case Properties::West::TALL:
                            return 16327;
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
                            return 16328;
                        case Properties::West::LOW:
                            return 16329;
                        case Properties::West::TALL:
                            return 16330;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16331;
                        case Properties::West::LOW:
                            return 16332;
                        case Properties::West::TALL:
                            return 16333;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16334;
                        case Properties::West::LOW:
                            return 16335;
                        case Properties::West::TALL:
                            return 16336;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16337;
                        case Properties::West::LOW:
                            return 16338;
                        case Properties::West::TALL:
                            return 16339;
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
                            return 16340;
                        case Properties::West::LOW:
                            return 16341;
                        case Properties::West::TALL:
                            return 16342;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16343;
                        case Properties::West::LOW:
                            return 16344;
                        case Properties::West::TALL:
                            return 16345;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16346;
                        case Properties::West::LOW:
                            return 16347;
                        case Properties::West::TALL:
                            return 16348;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16349;
                        case Properties::West::LOW:
                            return 16350;
                        case Properties::West::TALL:
                            return 16351;
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
                            return 16352;
                        case Properties::West::LOW:
                            return 16353;
                        case Properties::West::TALL:
                            return 16354;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16355;
                        case Properties::West::LOW:
                            return 16356;
                        case Properties::West::TALL:
                            return 16357;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16358;
                        case Properties::West::LOW:
                            return 16359;
                        case Properties::West::TALL:
                            return 16360;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16361;
                        case Properties::West::LOW:
                            return 16362;
                        case Properties::West::TALL:
                            return 16363;
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
                            return 16364;
                        case Properties::West::LOW:
                            return 16365;
                        case Properties::West::TALL:
                            return 16366;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16367;
                        case Properties::West::LOW:
                            return 16368;
                        case Properties::West::TALL:
                            return 16369;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16370;
                        case Properties::West::LOW:
                            return 16371;
                        case Properties::West::TALL:
                            return 16372;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16373;
                        case Properties::West::LOW:
                            return 16374;
                        case Properties::West::TALL:
                            return 16375;
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
                            return 16376;
                        case Properties::West::LOW:
                            return 16377;
                        case Properties::West::TALL:
                            return 16378;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16379;
                        case Properties::West::LOW:
                            return 16380;
                        case Properties::West::TALL:
                            return 16381;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16382;
                        case Properties::West::LOW:
                            return 16383;
                        case Properties::West::TALL:
                            return 16384;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16385;
                        case Properties::West::LOW:
                            return 16386;
                        case Properties::West::TALL:
                            return 16387;
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
                            return 16388;
                        case Properties::West::LOW:
                            return 16389;
                        case Properties::West::TALL:
                            return 16390;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16391;
                        case Properties::West::LOW:
                            return 16392;
                        case Properties::West::TALL:
                            return 16393;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16394;
                        case Properties::West::LOW:
                            return 16395;
                        case Properties::West::TALL:
                            return 16396;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16397;
                        case Properties::West::LOW:
                            return 16398;
                        case Properties::West::TALL:
                            return 16399;
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
                            return 16400;
                        case Properties::West::LOW:
                            return 16401;
                        case Properties::West::TALL:
                            return 16402;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16403;
                        case Properties::West::LOW:
                            return 16404;
                        case Properties::West::TALL:
                            return 16405;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16406;
                        case Properties::West::LOW:
                            return 16407;
                        case Properties::West::TALL:
                            return 16408;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16409;
                        case Properties::West::LOW:
                            return 16410;
                        case Properties::West::TALL:
                            return 16411;
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
                            return 16412;
                        case Properties::West::LOW:
                            return 16413;
                        case Properties::West::TALL:
                            return 16414;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16415;
                        case Properties::West::LOW:
                            return 16416;
                        case Properties::West::TALL:
                            return 16417;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16418;
                        case Properties::West::LOW:
                            return 16419;
                        case Properties::West::TALL:
                            return 16420;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16421;
                        case Properties::West::LOW:
                            return 16422;
                        case Properties::West::TALL:
                            return 16423;
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
                            return 16424;
                        case Properties::West::LOW:
                            return 16425;
                        case Properties::West::TALL:
                            return 16426;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16427;
                        case Properties::West::LOW:
                            return 16428;
                        case Properties::West::TALL:
                            return 16429;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16430;
                        case Properties::West::LOW:
                            return 16431;
                        case Properties::West::TALL:
                            return 16432;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16433;
                        case Properties::West::LOW:
                            return 16434;
                        case Properties::West::TALL:
                            return 16435;
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
                            return 16436;
                        case Properties::West::LOW:
                            return 16437;
                        case Properties::West::TALL:
                            return 16438;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16439;
                        case Properties::West::LOW:
                            return 16440;
                        case Properties::West::TALL:
                            return 16441;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16442;
                        case Properties::West::LOW:
                            return 16443;
                        case Properties::West::TALL:
                            return 16444;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16445;
                        case Properties::West::LOW:
                            return 16446;
                        case Properties::West::TALL:
                            return 16447;
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
