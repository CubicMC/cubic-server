#include "PolishedDeepslateWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedDeepslateWall {
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
                                    return 20279;
                                case Properties::West::LOW:
                                    return 20280;
                                case Properties::West::TALL:
                                    return 20281;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20282;
                                case Properties::West::LOW:
                                    return 20283;
                                case Properties::West::TALL:
                                    return 20284;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20285;
                                case Properties::West::LOW:
                                    return 20286;
                                case Properties::West::TALL:
                                    return 20287;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20288;
                                case Properties::West::LOW:
                                    return 20289;
                                case Properties::West::TALL:
                                    return 20290;
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
                                    return 20291;
                                case Properties::West::LOW:
                                    return 20292;
                                case Properties::West::TALL:
                                    return 20293;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20294;
                                case Properties::West::LOW:
                                    return 20295;
                                case Properties::West::TALL:
                                    return 20296;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20297;
                                case Properties::West::LOW:
                                    return 20298;
                                case Properties::West::TALL:
                                    return 20299;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20300;
                                case Properties::West::LOW:
                                    return 20301;
                                case Properties::West::TALL:
                                    return 20302;
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
                                    return 20303;
                                case Properties::West::LOW:
                                    return 20304;
                                case Properties::West::TALL:
                                    return 20305;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20306;
                                case Properties::West::LOW:
                                    return 20307;
                                case Properties::West::TALL:
                                    return 20308;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20309;
                                case Properties::West::LOW:
                                    return 20310;
                                case Properties::West::TALL:
                                    return 20311;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20312;
                                case Properties::West::LOW:
                                    return 20313;
                                case Properties::West::TALL:
                                    return 20314;
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
                                    return 20315;
                                case Properties::West::LOW:
                                    return 20316;
                                case Properties::West::TALL:
                                    return 20317;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20318;
                                case Properties::West::LOW:
                                    return 20319;
                                case Properties::West::TALL:
                                    return 20320;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20321;
                                case Properties::West::LOW:
                                    return 20322;
                                case Properties::West::TALL:
                                    return 20323;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20324;
                                case Properties::West::LOW:
                                    return 20325;
                                case Properties::West::TALL:
                                    return 20326;
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
                                    return 20327;
                                case Properties::West::LOW:
                                    return 20328;
                                case Properties::West::TALL:
                                    return 20329;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20330;
                                case Properties::West::LOW:
                                    return 20331;
                                case Properties::West::TALL:
                                    return 20332;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20333;
                                case Properties::West::LOW:
                                    return 20334;
                                case Properties::West::TALL:
                                    return 20335;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20336;
                                case Properties::West::LOW:
                                    return 20337;
                                case Properties::West::TALL:
                                    return 20338;
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
                                    return 20339;
                                case Properties::West::LOW:
                                    return 20340;
                                case Properties::West::TALL:
                                    return 20341;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20342;
                                case Properties::West::LOW:
                                    return 20343;
                                case Properties::West::TALL:
                                    return 20344;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20345;
                                case Properties::West::LOW:
                                    return 20346;
                                case Properties::West::TALL:
                                    return 20347;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20348;
                                case Properties::West::LOW:
                                    return 20349;
                                case Properties::West::TALL:
                                    return 20350;
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
                                    return 20351;
                                case Properties::West::LOW:
                                    return 20352;
                                case Properties::West::TALL:
                                    return 20353;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20354;
                                case Properties::West::LOW:
                                    return 20355;
                                case Properties::West::TALL:
                                    return 20356;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20357;
                                case Properties::West::LOW:
                                    return 20358;
                                case Properties::West::TALL:
                                    return 20359;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20360;
                                case Properties::West::LOW:
                                    return 20361;
                                case Properties::West::TALL:
                                    return 20362;
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
                                    return 20363;
                                case Properties::West::LOW:
                                    return 20364;
                                case Properties::West::TALL:
                                    return 20365;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20366;
                                case Properties::West::LOW:
                                    return 20367;
                                case Properties::West::TALL:
                                    return 20368;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20369;
                                case Properties::West::LOW:
                                    return 20370;
                                case Properties::West::TALL:
                                    return 20371;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20372;
                                case Properties::West::LOW:
                                    return 20373;
                                case Properties::West::TALL:
                                    return 20374;
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
                                    return 20375;
                                case Properties::West::LOW:
                                    return 20376;
                                case Properties::West::TALL:
                                    return 20377;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20378;
                                case Properties::West::LOW:
                                    return 20379;
                                case Properties::West::TALL:
                                    return 20380;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20381;
                                case Properties::West::LOW:
                                    return 20382;
                                case Properties::West::TALL:
                                    return 20383;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20384;
                                case Properties::West::LOW:
                                    return 20385;
                                case Properties::West::TALL:
                                    return 20386;
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
                                    return 20387;
                                case Properties::West::LOW:
                                    return 20388;
                                case Properties::West::TALL:
                                    return 20389;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20390;
                                case Properties::West::LOW:
                                    return 20391;
                                case Properties::West::TALL:
                                    return 20392;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20393;
                                case Properties::West::LOW:
                                    return 20394;
                                case Properties::West::TALL:
                                    return 20395;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20396;
                                case Properties::West::LOW:
                                    return 20397;
                                case Properties::West::TALL:
                                    return 20398;
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
                                    return 20399;
                                case Properties::West::LOW:
                                    return 20400;
                                case Properties::West::TALL:
                                    return 20401;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20402;
                                case Properties::West::LOW:
                                    return 20403;
                                case Properties::West::TALL:
                                    return 20404;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20405;
                                case Properties::West::LOW:
                                    return 20406;
                                case Properties::West::TALL:
                                    return 20407;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20408;
                                case Properties::West::LOW:
                                    return 20409;
                                case Properties::West::TALL:
                                    return 20410;
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
                                    return 20411;
                                case Properties::West::LOW:
                                    return 20412;
                                case Properties::West::TALL:
                                    return 20413;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20414;
                                case Properties::West::LOW:
                                    return 20415;
                                case Properties::West::TALL:
                                    return 20416;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20417;
                                case Properties::West::LOW:
                                    return 20418;
                                case Properties::West::TALL:
                                    return 20419;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20420;
                                case Properties::West::LOW:
                                    return 20421;
                                case Properties::West::TALL:
                                    return 20422;
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
                                    return 20423;
                                case Properties::West::LOW:
                                    return 20424;
                                case Properties::West::TALL:
                                    return 20425;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20426;
                                case Properties::West::LOW:
                                    return 20427;
                                case Properties::West::TALL:
                                    return 20428;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20429;
                                case Properties::West::LOW:
                                    return 20430;
                                case Properties::West::TALL:
                                    return 20431;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20432;
                                case Properties::West::LOW:
                                    return 20433;
                                case Properties::West::TALL:
                                    return 20434;
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
                                    return 20435;
                                case Properties::West::LOW:
                                    return 20436;
                                case Properties::West::TALL:
                                    return 20437;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20438;
                                case Properties::West::LOW:
                                    return 20439;
                                case Properties::West::TALL:
                                    return 20440;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20441;
                                case Properties::West::LOW:
                                    return 20442;
                                case Properties::West::TALL:
                                    return 20443;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20444;
                                case Properties::West::LOW:
                                    return 20445;
                                case Properties::West::TALL:
                                    return 20446;
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
                                    return 20447;
                                case Properties::West::LOW:
                                    return 20448;
                                case Properties::West::TALL:
                                    return 20449;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20450;
                                case Properties::West::LOW:
                                    return 20451;
                                case Properties::West::TALL:
                                    return 20452;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20453;
                                case Properties::West::LOW:
                                    return 20454;
                                case Properties::West::TALL:
                                    return 20455;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20456;
                                case Properties::West::LOW:
                                    return 20457;
                                case Properties::West::TALL:
                                    return 20458;
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
                                    return 20459;
                                case Properties::West::LOW:
                                    return 20460;
                                case Properties::West::TALL:
                                    return 20461;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20462;
                                case Properties::West::LOW:
                                    return 20463;
                                case Properties::West::TALL:
                                    return 20464;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20465;
                                case Properties::West::LOW:
                                    return 20466;
                                case Properties::West::TALL:
                                    return 20467;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20468;
                                case Properties::West::LOW:
                                    return 20469;
                                case Properties::West::TALL:
                                    return 20470;
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
                                    return 20471;
                                case Properties::West::LOW:
                                    return 20472;
                                case Properties::West::TALL:
                                    return 20473;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20474;
                                case Properties::West::LOW:
                                    return 20475;
                                case Properties::West::TALL:
                                    return 20476;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20477;
                                case Properties::West::LOW:
                                    return 20478;
                                case Properties::West::TALL:
                                    return 20479;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20480;
                                case Properties::West::LOW:
                                    return 20481;
                                case Properties::West::TALL:
                                    return 20482;
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
                                    return 20483;
                                case Properties::West::LOW:
                                    return 20484;
                                case Properties::West::TALL:
                                    return 20485;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20486;
                                case Properties::West::LOW:
                                    return 20487;
                                case Properties::West::TALL:
                                    return 20488;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20489;
                                case Properties::West::LOW:
                                    return 20490;
                                case Properties::West::TALL:
                                    return 20491;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20492;
                                case Properties::West::LOW:
                                    return 20493;
                                case Properties::West::TALL:
                                    return 20494;
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
                                    return 20495;
                                case Properties::West::LOW:
                                    return 20496;
                                case Properties::West::TALL:
                                    return 20497;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20498;
                                case Properties::West::LOW:
                                    return 20499;
                                case Properties::West::TALL:
                                    return 20500;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20501;
                                case Properties::West::LOW:
                                    return 20502;
                                case Properties::West::TALL:
                                    return 20503;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20504;
                                case Properties::West::LOW:
                                    return 20505;
                                case Properties::West::TALL:
                                    return 20506;
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
                                    return 20507;
                                case Properties::West::LOW:
                                    return 20508;
                                case Properties::West::TALL:
                                    return 20509;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20510;
                                case Properties::West::LOW:
                                    return 20511;
                                case Properties::West::TALL:
                                    return 20512;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20513;
                                case Properties::West::LOW:
                                    return 20514;
                                case Properties::West::TALL:
                                    return 20515;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20516;
                                case Properties::West::LOW:
                                    return 20517;
                                case Properties::West::TALL:
                                    return 20518;
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
                                    return 20519;
                                case Properties::West::LOW:
                                    return 20520;
                                case Properties::West::TALL:
                                    return 20521;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20522;
                                case Properties::West::LOW:
                                    return 20523;
                                case Properties::West::TALL:
                                    return 20524;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20525;
                                case Properties::West::LOW:
                                    return 20526;
                                case Properties::West::TALL:
                                    return 20527;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20528;
                                case Properties::West::LOW:
                                    return 20529;
                                case Properties::West::TALL:
                                    return 20530;
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
                                    return 20531;
                                case Properties::West::LOW:
                                    return 20532;
                                case Properties::West::TALL:
                                    return 20533;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20534;
                                case Properties::West::LOW:
                                    return 20535;
                                case Properties::West::TALL:
                                    return 20536;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20537;
                                case Properties::West::LOW:
                                    return 20538;
                                case Properties::West::TALL:
                                    return 20539;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20540;
                                case Properties::West::LOW:
                                    return 20541;
                                case Properties::West::TALL:
                                    return 20542;
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
                                    return 20543;
                                case Properties::West::LOW:
                                    return 20544;
                                case Properties::West::TALL:
                                    return 20545;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20546;
                                case Properties::West::LOW:
                                    return 20547;
                                case Properties::West::TALL:
                                    return 20548;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20549;
                                case Properties::West::LOW:
                                    return 20550;
                                case Properties::West::TALL:
                                    return 20551;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20552;
                                case Properties::West::LOW:
                                    return 20553;
                                case Properties::West::TALL:
                                    return 20554;
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
                                    return 20555;
                                case Properties::West::LOW:
                                    return 20556;
                                case Properties::West::TALL:
                                    return 20557;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20558;
                                case Properties::West::LOW:
                                    return 20559;
                                case Properties::West::TALL:
                                    return 20560;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20561;
                                case Properties::West::LOW:
                                    return 20562;
                                case Properties::West::TALL:
                                    return 20563;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20564;
                                case Properties::West::LOW:
                                    return 20565;
                                case Properties::West::TALL:
                                    return 20566;
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
                                    return 20567;
                                case Properties::West::LOW:
                                    return 20568;
                                case Properties::West::TALL:
                                    return 20569;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20570;
                                case Properties::West::LOW:
                                    return 20571;
                                case Properties::West::TALL:
                                    return 20572;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20573;
                                case Properties::West::LOW:
                                    return 20574;
                                case Properties::West::TALL:
                                    return 20575;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20576;
                                case Properties::West::LOW:
                                    return 20577;
                                case Properties::West::TALL:
                                    return 20578;
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
                                    return 20579;
                                case Properties::West::LOW:
                                    return 20580;
                                case Properties::West::TALL:
                                    return 20581;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20582;
                                case Properties::West::LOW:
                                    return 20583;
                                case Properties::West::TALL:
                                    return 20584;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20585;
                                case Properties::West::LOW:
                                    return 20586;
                                case Properties::West::TALL:
                                    return 20587;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20588;
                                case Properties::West::LOW:
                                    return 20589;
                                case Properties::West::TALL:
                                    return 20590;
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
                                    return 20591;
                                case Properties::West::LOW:
                                    return 20592;
                                case Properties::West::TALL:
                                    return 20593;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20594;
                                case Properties::West::LOW:
                                    return 20595;
                                case Properties::West::TALL:
                                    return 20596;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20597;
                                case Properties::West::LOW:
                                    return 20598;
                                case Properties::West::TALL:
                                    return 20599;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20600;
                                case Properties::West::LOW:
                                    return 20601;
                                case Properties::West::TALL:
                                    return 20602;
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
