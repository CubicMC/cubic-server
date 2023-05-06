#include "PolishedBlackstoneBrickWall.hpp"
namespace Blocks {
namespace PolishedBlackstoneBrickWall {
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
                            return 19333;
                        case Properties::West::LOW:
                            return 19334;
                        case Properties::West::TALL:
                            return 19335;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19336;
                        case Properties::West::LOW:
                            return 19337;
                        case Properties::West::TALL:
                            return 19338;
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
                            return 19339;
                        case Properties::West::LOW:
                            return 19340;
                        case Properties::West::TALL:
                            return 19341;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19342;
                        case Properties::West::LOW:
                            return 19343;
                        case Properties::West::TALL:
                            return 19344;
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
                            return 19345;
                        case Properties::West::LOW:
                            return 19346;
                        case Properties::West::TALL:
                            return 19347;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19348;
                        case Properties::West::LOW:
                            return 19349;
                        case Properties::West::TALL:
                            return 19350;
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
                            return 19351;
                        case Properties::West::LOW:
                            return 19352;
                        case Properties::West::TALL:
                            return 19353;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19354;
                        case Properties::West::LOW:
                            return 19355;
                        case Properties::West::TALL:
                            return 19356;
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
                            return 19357;
                        case Properties::West::LOW:
                            return 19358;
                        case Properties::West::TALL:
                            return 19359;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19360;
                        case Properties::West::LOW:
                            return 19361;
                        case Properties::West::TALL:
                            return 19362;
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
                            return 19363;
                        case Properties::West::LOW:
                            return 19364;
                        case Properties::West::TALL:
                            return 19365;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19366;
                        case Properties::West::LOW:
                            return 19367;
                        case Properties::West::TALL:
                            return 19368;
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
                            return 19369;
                        case Properties::West::LOW:
                            return 19370;
                        case Properties::West::TALL:
                            return 19371;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19372;
                        case Properties::West::LOW:
                            return 19373;
                        case Properties::West::TALL:
                            return 19374;
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
                            return 19375;
                        case Properties::West::LOW:
                            return 19376;
                        case Properties::West::TALL:
                            return 19377;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19378;
                        case Properties::West::LOW:
                            return 19379;
                        case Properties::West::TALL:
                            return 19380;
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
                            return 19381;
                        case Properties::West::LOW:
                            return 19382;
                        case Properties::West::TALL:
                            return 19383;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19384;
                        case Properties::West::LOW:
                            return 19385;
                        case Properties::West::TALL:
                            return 19386;
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
                            return 19387;
                        case Properties::West::LOW:
                            return 19388;
                        case Properties::West::TALL:
                            return 19389;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19390;
                        case Properties::West::LOW:
                            return 19391;
                        case Properties::West::TALL:
                            return 19392;
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
                            return 19393;
                        case Properties::West::LOW:
                            return 19394;
                        case Properties::West::TALL:
                            return 19395;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19396;
                        case Properties::West::LOW:
                            return 19397;
                        case Properties::West::TALL:
                            return 19398;
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
                            return 19399;
                        case Properties::West::LOW:
                            return 19400;
                        case Properties::West::TALL:
                            return 19401;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19402;
                        case Properties::West::LOW:
                            return 19403;
                        case Properties::West::TALL:
                            return 19404;
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
                            return 19405;
                        case Properties::West::LOW:
                            return 19406;
                        case Properties::West::TALL:
                            return 19407;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19408;
                        case Properties::West::LOW:
                            return 19409;
                        case Properties::West::TALL:
                            return 19410;
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
                            return 19411;
                        case Properties::West::LOW:
                            return 19412;
                        case Properties::West::TALL:
                            return 19413;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19414;
                        case Properties::West::LOW:
                            return 19415;
                        case Properties::West::TALL:
                            return 19416;
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
                            return 19417;
                        case Properties::West::LOW:
                            return 19418;
                        case Properties::West::TALL:
                            return 19419;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19420;
                        case Properties::West::LOW:
                            return 19421;
                        case Properties::West::TALL:
                            return 19422;
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
                            return 19423;
                        case Properties::West::LOW:
                            return 19424;
                        case Properties::West::TALL:
                            return 19425;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19426;
                        case Properties::West::LOW:
                            return 19427;
                        case Properties::West::TALL:
                            return 19428;
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
                            return 19429;
                        case Properties::West::LOW:
                            return 19430;
                        case Properties::West::TALL:
                            return 19431;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19432;
                        case Properties::West::LOW:
                            return 19433;
                        case Properties::West::TALL:
                            return 19434;
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
                            return 19435;
                        case Properties::West::LOW:
                            return 19436;
                        case Properties::West::TALL:
                            return 19437;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19438;
                        case Properties::West::LOW:
                            return 19439;
                        case Properties::West::TALL:
                            return 19440;
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
                            return 19441;
                        case Properties::West::LOW:
                            return 19442;
                        case Properties::West::TALL:
                            return 19443;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19444;
                        case Properties::West::LOW:
                            return 19445;
                        case Properties::West::TALL:
                            return 19446;
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
                            return 19447;
                        case Properties::West::LOW:
                            return 19448;
                        case Properties::West::TALL:
                            return 19449;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19450;
                        case Properties::West::LOW:
                            return 19451;
                        case Properties::West::TALL:
                            return 19452;
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
                            return 19453;
                        case Properties::West::LOW:
                            return 19454;
                        case Properties::West::TALL:
                            return 19455;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19456;
                        case Properties::West::LOW:
                            return 19457;
                        case Properties::West::TALL:
                            return 19458;
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
                            return 19459;
                        case Properties::West::LOW:
                            return 19460;
                        case Properties::West::TALL:
                            return 19461;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19462;
                        case Properties::West::LOW:
                            return 19463;
                        case Properties::West::TALL:
                            return 19464;
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
                            return 19465;
                        case Properties::West::LOW:
                            return 19466;
                        case Properties::West::TALL:
                            return 19467;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19468;
                        case Properties::West::LOW:
                            return 19469;
                        case Properties::West::TALL:
                            return 19470;
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
                            return 19471;
                        case Properties::West::LOW:
                            return 19472;
                        case Properties::West::TALL:
                            return 19473;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19474;
                        case Properties::West::LOW:
                            return 19475;
                        case Properties::West::TALL:
                            return 19476;
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
                            return 19477;
                        case Properties::West::LOW:
                            return 19478;
                        case Properties::West::TALL:
                            return 19479;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19480;
                        case Properties::West::LOW:
                            return 19481;
                        case Properties::West::TALL:
                            return 19482;
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
                            return 19483;
                        case Properties::West::LOW:
                            return 19484;
                        case Properties::West::TALL:
                            return 19485;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19486;
                        case Properties::West::LOW:
                            return 19487;
                        case Properties::West::TALL:
                            return 19488;
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
                            return 19489;
                        case Properties::West::LOW:
                            return 19490;
                        case Properties::West::TALL:
                            return 19491;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19492;
                        case Properties::West::LOW:
                            return 19493;
                        case Properties::West::TALL:
                            return 19494;
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
                            return 19495;
                        case Properties::West::LOW:
                            return 19496;
                        case Properties::West::TALL:
                            return 19497;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19498;
                        case Properties::West::LOW:
                            return 19499;
                        case Properties::West::TALL:
                            return 19500;
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
                            return 19501;
                        case Properties::West::LOW:
                            return 19502;
                        case Properties::West::TALL:
                            return 19503;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19504;
                        case Properties::West::LOW:
                            return 19505;
                        case Properties::West::TALL:
                            return 19506;
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
                            return 19507;
                        case Properties::West::LOW:
                            return 19508;
                        case Properties::West::TALL:
                            return 19509;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19510;
                        case Properties::West::LOW:
                            return 19511;
                        case Properties::West::TALL:
                            return 19512;
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
                            return 19513;
                        case Properties::West::LOW:
                            return 19514;
                        case Properties::West::TALL:
                            return 19515;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19516;
                        case Properties::West::LOW:
                            return 19517;
                        case Properties::West::TALL:
                            return 19518;
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
                            return 19519;
                        case Properties::West::LOW:
                            return 19520;
                        case Properties::West::TALL:
                            return 19521;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19522;
                        case Properties::West::LOW:
                            return 19523;
                        case Properties::West::TALL:
                            return 19524;
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
                            return 19525;
                        case Properties::West::LOW:
                            return 19526;
                        case Properties::West::TALL:
                            return 19527;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19528;
                        case Properties::West::LOW:
                            return 19529;
                        case Properties::West::TALL:
                            return 19530;
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
                            return 19531;
                        case Properties::West::LOW:
                            return 19532;
                        case Properties::West::TALL:
                            return 19533;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19534;
                        case Properties::West::LOW:
                            return 19535;
                        case Properties::West::TALL:
                            return 19536;
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
                            return 19537;
                        case Properties::West::LOW:
                            return 19538;
                        case Properties::West::TALL:
                            return 19539;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19540;
                        case Properties::West::LOW:
                            return 19541;
                        case Properties::West::TALL:
                            return 19542;
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
                            return 19543;
                        case Properties::West::LOW:
                            return 19544;
                        case Properties::West::TALL:
                            return 19545;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19546;
                        case Properties::West::LOW:
                            return 19547;
                        case Properties::West::TALL:
                            return 19548;
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
                            return 19549;
                        case Properties::West::LOW:
                            return 19550;
                        case Properties::West::TALL:
                            return 19551;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19552;
                        case Properties::West::LOW:
                            return 19553;
                        case Properties::West::TALL:
                            return 19554;
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
                            return 19555;
                        case Properties::West::LOW:
                            return 19556;
                        case Properties::West::TALL:
                            return 19557;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19558;
                        case Properties::West::LOW:
                            return 19559;
                        case Properties::West::TALL:
                            return 19560;
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
                            return 19561;
                        case Properties::West::LOW:
                            return 19562;
                        case Properties::West::TALL:
                            return 19563;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19564;
                        case Properties::West::LOW:
                            return 19565;
                        case Properties::West::TALL:
                            return 19566;
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
                            return 19567;
                        case Properties::West::LOW:
                            return 19568;
                        case Properties::West::TALL:
                            return 19569;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19570;
                        case Properties::West::LOW:
                            return 19571;
                        case Properties::West::TALL:
                            return 19572;
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
                            return 19573;
                        case Properties::West::LOW:
                            return 19574;
                        case Properties::West::TALL:
                            return 19575;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19576;
                        case Properties::West::LOW:
                            return 19577;
                        case Properties::West::TALL:
                            return 19578;
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
                            return 19579;
                        case Properties::West::LOW:
                            return 19580;
                        case Properties::West::TALL:
                            return 19581;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19582;
                        case Properties::West::LOW:
                            return 19583;
                        case Properties::West::TALL:
                            return 19584;
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
                            return 19585;
                        case Properties::West::LOW:
                            return 19586;
                        case Properties::West::TALL:
                            return 19587;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19588;
                        case Properties::West::LOW:
                            return 19589;
                        case Properties::West::TALL:
                            return 19590;
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
                            return 19591;
                        case Properties::West::LOW:
                            return 19592;
                        case Properties::West::TALL:
                            return 19593;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19594;
                        case Properties::West::LOW:
                            return 19595;
                        case Properties::West::TALL:
                            return 19596;
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
                            return 19597;
                        case Properties::West::LOW:
                            return 19598;
                        case Properties::West::TALL:
                            return 19599;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19600;
                        case Properties::West::LOW:
                            return 19601;
                        case Properties::West::TALL:
                            return 19602;
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
                            return 19603;
                        case Properties::West::LOW:
                            return 19604;
                        case Properties::West::TALL:
                            return 19605;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19606;
                        case Properties::West::LOW:
                            return 19607;
                        case Properties::West::TALL:
                            return 19608;
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
                            return 19609;
                        case Properties::West::LOW:
                            return 19610;
                        case Properties::West::TALL:
                            return 19611;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19612;
                        case Properties::West::LOW:
                            return 19613;
                        case Properties::West::TALL:
                            return 19614;
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
                            return 19615;
                        case Properties::West::LOW:
                            return 19616;
                        case Properties::West::TALL:
                            return 19617;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19618;
                        case Properties::West::LOW:
                            return 19619;
                        case Properties::West::TALL:
                            return 19620;
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
                            return 19621;
                        case Properties::West::LOW:
                            return 19622;
                        case Properties::West::TALL:
                            return 19623;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19624;
                        case Properties::West::LOW:
                            return 19625;
                        case Properties::West::TALL:
                            return 19626;
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
                            return 19627;
                        case Properties::West::LOW:
                            return 19628;
                        case Properties::West::TALL:
                            return 19629;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19630;
                        case Properties::West::LOW:
                            return 19631;
                        case Properties::West::TALL:
                            return 19632;
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
                            return 19633;
                        case Properties::West::LOW:
                            return 19634;
                        case Properties::West::TALL:
                            return 19635;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19636;
                        case Properties::West::LOW:
                            return 19637;
                        case Properties::West::TALL:
                            return 19638;
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
                            return 19639;
                        case Properties::West::LOW:
                            return 19640;
                        case Properties::West::TALL:
                            return 19641;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19642;
                        case Properties::West::LOW:
                            return 19643;
                        case Properties::West::TALL:
                            return 19644;
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
                            return 19645;
                        case Properties::West::LOW:
                            return 19646;
                        case Properties::West::TALL:
                            return 19647;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19648;
                        case Properties::West::LOW:
                            return 19649;
                        case Properties::West::TALL:
                            return 19650;
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
                            return 19651;
                        case Properties::West::LOW:
                            return 19652;
                        case Properties::West::TALL:
                            return 19653;
                        default:
                            return 0;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 19654;
                        case Properties::West::LOW:
                            return 19655;
                        case Properties::West::TALL:
                            return 19656;
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
