#include "RedSandstoneWall.hpp"
namespace Blocks {
    namespace RedSandstoneWall {
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
                                    return 14180;
                                case Properties::West::LOW:
                                    return 14181;
                                case Properties::West::TALL:
                                    return 14182;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14183;
                                case Properties::West::LOW:
                                    return 14184;
                                case Properties::West::TALL:
                                    return 14185;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14186;
                                case Properties::West::LOW:
                                    return 14187;
                                case Properties::West::TALL:
                                    return 14188;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14189;
                                case Properties::West::LOW:
                                    return 14190;
                                case Properties::West::TALL:
                                    return 14191;
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
                                    return 14192;
                                case Properties::West::LOW:
                                    return 14193;
                                case Properties::West::TALL:
                                    return 14194;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14195;
                                case Properties::West::LOW:
                                    return 14196;
                                case Properties::West::TALL:
                                    return 14197;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14198;
                                case Properties::West::LOW:
                                    return 14199;
                                case Properties::West::TALL:
                                    return 14200;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14201;
                                case Properties::West::LOW:
                                    return 14202;
                                case Properties::West::TALL:
                                    return 14203;
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
                                    return 14204;
                                case Properties::West::LOW:
                                    return 14205;
                                case Properties::West::TALL:
                                    return 14206;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14207;
                                case Properties::West::LOW:
                                    return 14208;
                                case Properties::West::TALL:
                                    return 14209;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14210;
                                case Properties::West::LOW:
                                    return 14211;
                                case Properties::West::TALL:
                                    return 14212;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14213;
                                case Properties::West::LOW:
                                    return 14214;
                                case Properties::West::TALL:
                                    return 14215;
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
                                    return 14216;
                                case Properties::West::LOW:
                                    return 14217;
                                case Properties::West::TALL:
                                    return 14218;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14219;
                                case Properties::West::LOW:
                                    return 14220;
                                case Properties::West::TALL:
                                    return 14221;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14222;
                                case Properties::West::LOW:
                                    return 14223;
                                case Properties::West::TALL:
                                    return 14224;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14225;
                                case Properties::West::LOW:
                                    return 14226;
                                case Properties::West::TALL:
                                    return 14227;
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
                                    return 14228;
                                case Properties::West::LOW:
                                    return 14229;
                                case Properties::West::TALL:
                                    return 14230;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14231;
                                case Properties::West::LOW:
                                    return 14232;
                                case Properties::West::TALL:
                                    return 14233;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14234;
                                case Properties::West::LOW:
                                    return 14235;
                                case Properties::West::TALL:
                                    return 14236;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14237;
                                case Properties::West::LOW:
                                    return 14238;
                                case Properties::West::TALL:
                                    return 14239;
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
                                    return 14240;
                                case Properties::West::LOW:
                                    return 14241;
                                case Properties::West::TALL:
                                    return 14242;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14243;
                                case Properties::West::LOW:
                                    return 14244;
                                case Properties::West::TALL:
                                    return 14245;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14246;
                                case Properties::West::LOW:
                                    return 14247;
                                case Properties::West::TALL:
                                    return 14248;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14249;
                                case Properties::West::LOW:
                                    return 14250;
                                case Properties::West::TALL:
                                    return 14251;
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
                                    return 14252;
                                case Properties::West::LOW:
                                    return 14253;
                                case Properties::West::TALL:
                                    return 14254;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14255;
                                case Properties::West::LOW:
                                    return 14256;
                                case Properties::West::TALL:
                                    return 14257;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14258;
                                case Properties::West::LOW:
                                    return 14259;
                                case Properties::West::TALL:
                                    return 14260;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14261;
                                case Properties::West::LOW:
                                    return 14262;
                                case Properties::West::TALL:
                                    return 14263;
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
                                    return 14264;
                                case Properties::West::LOW:
                                    return 14265;
                                case Properties::West::TALL:
                                    return 14266;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14267;
                                case Properties::West::LOW:
                                    return 14268;
                                case Properties::West::TALL:
                                    return 14269;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14270;
                                case Properties::West::LOW:
                                    return 14271;
                                case Properties::West::TALL:
                                    return 14272;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14273;
                                case Properties::West::LOW:
                                    return 14274;
                                case Properties::West::TALL:
                                    return 14275;
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
                                    return 14276;
                                case Properties::West::LOW:
                                    return 14277;
                                case Properties::West::TALL:
                                    return 14278;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14279;
                                case Properties::West::LOW:
                                    return 14280;
                                case Properties::West::TALL:
                                    return 14281;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14282;
                                case Properties::West::LOW:
                                    return 14283;
                                case Properties::West::TALL:
                                    return 14284;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14285;
                                case Properties::West::LOW:
                                    return 14286;
                                case Properties::West::TALL:
                                    return 14287;
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
                                    return 14288;
                                case Properties::West::LOW:
                                    return 14289;
                                case Properties::West::TALL:
                                    return 14290;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14291;
                                case Properties::West::LOW:
                                    return 14292;
                                case Properties::West::TALL:
                                    return 14293;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14294;
                                case Properties::West::LOW:
                                    return 14295;
                                case Properties::West::TALL:
                                    return 14296;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14297;
                                case Properties::West::LOW:
                                    return 14298;
                                case Properties::West::TALL:
                                    return 14299;
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
                                    return 14300;
                                case Properties::West::LOW:
                                    return 14301;
                                case Properties::West::TALL:
                                    return 14302;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14303;
                                case Properties::West::LOW:
                                    return 14304;
                                case Properties::West::TALL:
                                    return 14305;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14306;
                                case Properties::West::LOW:
                                    return 14307;
                                case Properties::West::TALL:
                                    return 14308;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14309;
                                case Properties::West::LOW:
                                    return 14310;
                                case Properties::West::TALL:
                                    return 14311;
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
                                    return 14312;
                                case Properties::West::LOW:
                                    return 14313;
                                case Properties::West::TALL:
                                    return 14314;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14315;
                                case Properties::West::LOW:
                                    return 14316;
                                case Properties::West::TALL:
                                    return 14317;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14318;
                                case Properties::West::LOW:
                                    return 14319;
                                case Properties::West::TALL:
                                    return 14320;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14321;
                                case Properties::West::LOW:
                                    return 14322;
                                case Properties::West::TALL:
                                    return 14323;
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
                                    return 14324;
                                case Properties::West::LOW:
                                    return 14325;
                                case Properties::West::TALL:
                                    return 14326;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14327;
                                case Properties::West::LOW:
                                    return 14328;
                                case Properties::West::TALL:
                                    return 14329;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14330;
                                case Properties::West::LOW:
                                    return 14331;
                                case Properties::West::TALL:
                                    return 14332;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14333;
                                case Properties::West::LOW:
                                    return 14334;
                                case Properties::West::TALL:
                                    return 14335;
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
                                    return 14336;
                                case Properties::West::LOW:
                                    return 14337;
                                case Properties::West::TALL:
                                    return 14338;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14339;
                                case Properties::West::LOW:
                                    return 14340;
                                case Properties::West::TALL:
                                    return 14341;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14342;
                                case Properties::West::LOW:
                                    return 14343;
                                case Properties::West::TALL:
                                    return 14344;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14345;
                                case Properties::West::LOW:
                                    return 14346;
                                case Properties::West::TALL:
                                    return 14347;
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
                                    return 14348;
                                case Properties::West::LOW:
                                    return 14349;
                                case Properties::West::TALL:
                                    return 14350;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14351;
                                case Properties::West::LOW:
                                    return 14352;
                                case Properties::West::TALL:
                                    return 14353;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14354;
                                case Properties::West::LOW:
                                    return 14355;
                                case Properties::West::TALL:
                                    return 14356;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14357;
                                case Properties::West::LOW:
                                    return 14358;
                                case Properties::West::TALL:
                                    return 14359;
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
                                    return 14360;
                                case Properties::West::LOW:
                                    return 14361;
                                case Properties::West::TALL:
                                    return 14362;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14363;
                                case Properties::West::LOW:
                                    return 14364;
                                case Properties::West::TALL:
                                    return 14365;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14366;
                                case Properties::West::LOW:
                                    return 14367;
                                case Properties::West::TALL:
                                    return 14368;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14369;
                                case Properties::West::LOW:
                                    return 14370;
                                case Properties::West::TALL:
                                    return 14371;
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
                                    return 14372;
                                case Properties::West::LOW:
                                    return 14373;
                                case Properties::West::TALL:
                                    return 14374;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14375;
                                case Properties::West::LOW:
                                    return 14376;
                                case Properties::West::TALL:
                                    return 14377;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14378;
                                case Properties::West::LOW:
                                    return 14379;
                                case Properties::West::TALL:
                                    return 14380;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14381;
                                case Properties::West::LOW:
                                    return 14382;
                                case Properties::West::TALL:
                                    return 14383;
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
                                    return 14384;
                                case Properties::West::LOW:
                                    return 14385;
                                case Properties::West::TALL:
                                    return 14386;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14387;
                                case Properties::West::LOW:
                                    return 14388;
                                case Properties::West::TALL:
                                    return 14389;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14390;
                                case Properties::West::LOW:
                                    return 14391;
                                case Properties::West::TALL:
                                    return 14392;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14393;
                                case Properties::West::LOW:
                                    return 14394;
                                case Properties::West::TALL:
                                    return 14395;
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
                                    return 14396;
                                case Properties::West::LOW:
                                    return 14397;
                                case Properties::West::TALL:
                                    return 14398;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14399;
                                case Properties::West::LOW:
                                    return 14400;
                                case Properties::West::TALL:
                                    return 14401;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14402;
                                case Properties::West::LOW:
                                    return 14403;
                                case Properties::West::TALL:
                                    return 14404;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14405;
                                case Properties::West::LOW:
                                    return 14406;
                                case Properties::West::TALL:
                                    return 14407;
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
                                    return 14408;
                                case Properties::West::LOW:
                                    return 14409;
                                case Properties::West::TALL:
                                    return 14410;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14411;
                                case Properties::West::LOW:
                                    return 14412;
                                case Properties::West::TALL:
                                    return 14413;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14414;
                                case Properties::West::LOW:
                                    return 14415;
                                case Properties::West::TALL:
                                    return 14416;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14417;
                                case Properties::West::LOW:
                                    return 14418;
                                case Properties::West::TALL:
                                    return 14419;
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
                                    return 14420;
                                case Properties::West::LOW:
                                    return 14421;
                                case Properties::West::TALL:
                                    return 14422;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14423;
                                case Properties::West::LOW:
                                    return 14424;
                                case Properties::West::TALL:
                                    return 14425;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14426;
                                case Properties::West::LOW:
                                    return 14427;
                                case Properties::West::TALL:
                                    return 14428;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14429;
                                case Properties::West::LOW:
                                    return 14430;
                                case Properties::West::TALL:
                                    return 14431;
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
                                    return 14432;
                                case Properties::West::LOW:
                                    return 14433;
                                case Properties::West::TALL:
                                    return 14434;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14435;
                                case Properties::West::LOW:
                                    return 14436;
                                case Properties::West::TALL:
                                    return 14437;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14438;
                                case Properties::West::LOW:
                                    return 14439;
                                case Properties::West::TALL:
                                    return 14440;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14441;
                                case Properties::West::LOW:
                                    return 14442;
                                case Properties::West::TALL:
                                    return 14443;
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
                                    return 14444;
                                case Properties::West::LOW:
                                    return 14445;
                                case Properties::West::TALL:
                                    return 14446;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14447;
                                case Properties::West::LOW:
                                    return 14448;
                                case Properties::West::TALL:
                                    return 14449;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14450;
                                case Properties::West::LOW:
                                    return 14451;
                                case Properties::West::TALL:
                                    return 14452;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14453;
                                case Properties::West::LOW:
                                    return 14454;
                                case Properties::West::TALL:
                                    return 14455;
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
                                    return 14456;
                                case Properties::West::LOW:
                                    return 14457;
                                case Properties::West::TALL:
                                    return 14458;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14459;
                                case Properties::West::LOW:
                                    return 14460;
                                case Properties::West::TALL:
                                    return 14461;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14462;
                                case Properties::West::LOW:
                                    return 14463;
                                case Properties::West::TALL:
                                    return 14464;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14465;
                                case Properties::West::LOW:
                                    return 14466;
                                case Properties::West::TALL:
                                    return 14467;
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
                                    return 14468;
                                case Properties::West::LOW:
                                    return 14469;
                                case Properties::West::TALL:
                                    return 14470;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14471;
                                case Properties::West::LOW:
                                    return 14472;
                                case Properties::West::TALL:
                                    return 14473;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14474;
                                case Properties::West::LOW:
                                    return 14475;
                                case Properties::West::TALL:
                                    return 14476;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14477;
                                case Properties::West::LOW:
                                    return 14478;
                                case Properties::West::TALL:
                                    return 14479;
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
                                    return 14480;
                                case Properties::West::LOW:
                                    return 14481;
                                case Properties::West::TALL:
                                    return 14482;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14483;
                                case Properties::West::LOW:
                                    return 14484;
                                case Properties::West::TALL:
                                    return 14485;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14486;
                                case Properties::West::LOW:
                                    return 14487;
                                case Properties::West::TALL:
                                    return 14488;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14489;
                                case Properties::West::LOW:
                                    return 14490;
                                case Properties::West::TALL:
                                    return 14491;
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
                                    return 14492;
                                case Properties::West::LOW:
                                    return 14493;
                                case Properties::West::TALL:
                                    return 14494;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14495;
                                case Properties::West::LOW:
                                    return 14496;
                                case Properties::West::TALL:
                                    return 14497;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14498;
                                case Properties::West::LOW:
                                    return 14499;
                                case Properties::West::TALL:
                                    return 14500;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14501;
                                case Properties::West::LOW:
                                    return 14502;
                                case Properties::West::TALL:
                                    return 14503;
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
