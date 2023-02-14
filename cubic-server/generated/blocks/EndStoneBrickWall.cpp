#include "EndStoneBrickWall.hpp"
#include <stdexcept>

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
                                    return 15312;
                                case Properties::West::LOW:
                                    return 15313;
                                case Properties::West::TALL:
                                    return 15314;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15315;
                                case Properties::West::LOW:
                                    return 15316;
                                case Properties::West::TALL:
                                    return 15317;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15318;
                                case Properties::West::LOW:
                                    return 15319;
                                case Properties::West::TALL:
                                    return 15320;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15321;
                                case Properties::West::LOW:
                                    return 15322;
                                case Properties::West::TALL:
                                    return 15323;
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
                                    return 15324;
                                case Properties::West::LOW:
                                    return 15325;
                                case Properties::West::TALL:
                                    return 15326;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15327;
                                case Properties::West::LOW:
                                    return 15328;
                                case Properties::West::TALL:
                                    return 15329;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15330;
                                case Properties::West::LOW:
                                    return 15331;
                                case Properties::West::TALL:
                                    return 15332;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15333;
                                case Properties::West::LOW:
                                    return 15334;
                                case Properties::West::TALL:
                                    return 15335;
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
                                    return 15336;
                                case Properties::West::LOW:
                                    return 15337;
                                case Properties::West::TALL:
                                    return 15338;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15339;
                                case Properties::West::LOW:
                                    return 15340;
                                case Properties::West::TALL:
                                    return 15341;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15342;
                                case Properties::West::LOW:
                                    return 15343;
                                case Properties::West::TALL:
                                    return 15344;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15345;
                                case Properties::West::LOW:
                                    return 15346;
                                case Properties::West::TALL:
                                    return 15347;
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
                                    return 15348;
                                case Properties::West::LOW:
                                    return 15349;
                                case Properties::West::TALL:
                                    return 15350;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15351;
                                case Properties::West::LOW:
                                    return 15352;
                                case Properties::West::TALL:
                                    return 15353;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15354;
                                case Properties::West::LOW:
                                    return 15355;
                                case Properties::West::TALL:
                                    return 15356;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15357;
                                case Properties::West::LOW:
                                    return 15358;
                                case Properties::West::TALL:
                                    return 15359;
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
                                    return 15360;
                                case Properties::West::LOW:
                                    return 15361;
                                case Properties::West::TALL:
                                    return 15362;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15363;
                                case Properties::West::LOW:
                                    return 15364;
                                case Properties::West::TALL:
                                    return 15365;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15366;
                                case Properties::West::LOW:
                                    return 15367;
                                case Properties::West::TALL:
                                    return 15368;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15369;
                                case Properties::West::LOW:
                                    return 15370;
                                case Properties::West::TALL:
                                    return 15371;
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
                                    return 15372;
                                case Properties::West::LOW:
                                    return 15373;
                                case Properties::West::TALL:
                                    return 15374;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15375;
                                case Properties::West::LOW:
                                    return 15376;
                                case Properties::West::TALL:
                                    return 15377;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15378;
                                case Properties::West::LOW:
                                    return 15379;
                                case Properties::West::TALL:
                                    return 15380;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15381;
                                case Properties::West::LOW:
                                    return 15382;
                                case Properties::West::TALL:
                                    return 15383;
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
                                    return 15384;
                                case Properties::West::LOW:
                                    return 15385;
                                case Properties::West::TALL:
                                    return 15386;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15387;
                                case Properties::West::LOW:
                                    return 15388;
                                case Properties::West::TALL:
                                    return 15389;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15390;
                                case Properties::West::LOW:
                                    return 15391;
                                case Properties::West::TALL:
                                    return 15392;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15393;
                                case Properties::West::LOW:
                                    return 15394;
                                case Properties::West::TALL:
                                    return 15395;
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
                                    return 15396;
                                case Properties::West::LOW:
                                    return 15397;
                                case Properties::West::TALL:
                                    return 15398;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15399;
                                case Properties::West::LOW:
                                    return 15400;
                                case Properties::West::TALL:
                                    return 15401;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15402;
                                case Properties::West::LOW:
                                    return 15403;
                                case Properties::West::TALL:
                                    return 15404;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15405;
                                case Properties::West::LOW:
                                    return 15406;
                                case Properties::West::TALL:
                                    return 15407;
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
                                    return 15408;
                                case Properties::West::LOW:
                                    return 15409;
                                case Properties::West::TALL:
                                    return 15410;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15411;
                                case Properties::West::LOW:
                                    return 15412;
                                case Properties::West::TALL:
                                    return 15413;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15414;
                                case Properties::West::LOW:
                                    return 15415;
                                case Properties::West::TALL:
                                    return 15416;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15417;
                                case Properties::West::LOW:
                                    return 15418;
                                case Properties::West::TALL:
                                    return 15419;
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
                                    return 15420;
                                case Properties::West::LOW:
                                    return 15421;
                                case Properties::West::TALL:
                                    return 15422;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15423;
                                case Properties::West::LOW:
                                    return 15424;
                                case Properties::West::TALL:
                                    return 15425;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15426;
                                case Properties::West::LOW:
                                    return 15427;
                                case Properties::West::TALL:
                                    return 15428;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15429;
                                case Properties::West::LOW:
                                    return 15430;
                                case Properties::West::TALL:
                                    return 15431;
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
                                    return 15432;
                                case Properties::West::LOW:
                                    return 15433;
                                case Properties::West::TALL:
                                    return 15434;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15435;
                                case Properties::West::LOW:
                                    return 15436;
                                case Properties::West::TALL:
                                    return 15437;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15438;
                                case Properties::West::LOW:
                                    return 15439;
                                case Properties::West::TALL:
                                    return 15440;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15441;
                                case Properties::West::LOW:
                                    return 15442;
                                case Properties::West::TALL:
                                    return 15443;
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
                                    return 15444;
                                case Properties::West::LOW:
                                    return 15445;
                                case Properties::West::TALL:
                                    return 15446;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15447;
                                case Properties::West::LOW:
                                    return 15448;
                                case Properties::West::TALL:
                                    return 15449;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15450;
                                case Properties::West::LOW:
                                    return 15451;
                                case Properties::West::TALL:
                                    return 15452;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15453;
                                case Properties::West::LOW:
                                    return 15454;
                                case Properties::West::TALL:
                                    return 15455;
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
                                    return 15456;
                                case Properties::West::LOW:
                                    return 15457;
                                case Properties::West::TALL:
                                    return 15458;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15459;
                                case Properties::West::LOW:
                                    return 15460;
                                case Properties::West::TALL:
                                    return 15461;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15462;
                                case Properties::West::LOW:
                                    return 15463;
                                case Properties::West::TALL:
                                    return 15464;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15465;
                                case Properties::West::LOW:
                                    return 15466;
                                case Properties::West::TALL:
                                    return 15467;
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
                                    return 15468;
                                case Properties::West::LOW:
                                    return 15469;
                                case Properties::West::TALL:
                                    return 15470;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15471;
                                case Properties::West::LOW:
                                    return 15472;
                                case Properties::West::TALL:
                                    return 15473;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15474;
                                case Properties::West::LOW:
                                    return 15475;
                                case Properties::West::TALL:
                                    return 15476;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15477;
                                case Properties::West::LOW:
                                    return 15478;
                                case Properties::West::TALL:
                                    return 15479;
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
                                    return 15480;
                                case Properties::West::LOW:
                                    return 15481;
                                case Properties::West::TALL:
                                    return 15482;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15483;
                                case Properties::West::LOW:
                                    return 15484;
                                case Properties::West::TALL:
                                    return 15485;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15486;
                                case Properties::West::LOW:
                                    return 15487;
                                case Properties::West::TALL:
                                    return 15488;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15489;
                                case Properties::West::LOW:
                                    return 15490;
                                case Properties::West::TALL:
                                    return 15491;
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
                                    return 15492;
                                case Properties::West::LOW:
                                    return 15493;
                                case Properties::West::TALL:
                                    return 15494;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15495;
                                case Properties::West::LOW:
                                    return 15496;
                                case Properties::West::TALL:
                                    return 15497;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15498;
                                case Properties::West::LOW:
                                    return 15499;
                                case Properties::West::TALL:
                                    return 15500;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15501;
                                case Properties::West::LOW:
                                    return 15502;
                                case Properties::West::TALL:
                                    return 15503;
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
                                    return 15504;
                                case Properties::West::LOW:
                                    return 15505;
                                case Properties::West::TALL:
                                    return 15506;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15507;
                                case Properties::West::LOW:
                                    return 15508;
                                case Properties::West::TALL:
                                    return 15509;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15510;
                                case Properties::West::LOW:
                                    return 15511;
                                case Properties::West::TALL:
                                    return 15512;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15513;
                                case Properties::West::LOW:
                                    return 15514;
                                case Properties::West::TALL:
                                    return 15515;
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
                                    return 15516;
                                case Properties::West::LOW:
                                    return 15517;
                                case Properties::West::TALL:
                                    return 15518;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15519;
                                case Properties::West::LOW:
                                    return 15520;
                                case Properties::West::TALL:
                                    return 15521;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15522;
                                case Properties::West::LOW:
                                    return 15523;
                                case Properties::West::TALL:
                                    return 15524;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15525;
                                case Properties::West::LOW:
                                    return 15526;
                                case Properties::West::TALL:
                                    return 15527;
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
                                    return 15528;
                                case Properties::West::LOW:
                                    return 15529;
                                case Properties::West::TALL:
                                    return 15530;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15531;
                                case Properties::West::LOW:
                                    return 15532;
                                case Properties::West::TALL:
                                    return 15533;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15534;
                                case Properties::West::LOW:
                                    return 15535;
                                case Properties::West::TALL:
                                    return 15536;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15537;
                                case Properties::West::LOW:
                                    return 15538;
                                case Properties::West::TALL:
                                    return 15539;
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
                                    return 15540;
                                case Properties::West::LOW:
                                    return 15541;
                                case Properties::West::TALL:
                                    return 15542;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15543;
                                case Properties::West::LOW:
                                    return 15544;
                                case Properties::West::TALL:
                                    return 15545;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15546;
                                case Properties::West::LOW:
                                    return 15547;
                                case Properties::West::TALL:
                                    return 15548;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15549;
                                case Properties::West::LOW:
                                    return 15550;
                                case Properties::West::TALL:
                                    return 15551;
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
                                    return 15552;
                                case Properties::West::LOW:
                                    return 15553;
                                case Properties::West::TALL:
                                    return 15554;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15555;
                                case Properties::West::LOW:
                                    return 15556;
                                case Properties::West::TALL:
                                    return 15557;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15558;
                                case Properties::West::LOW:
                                    return 15559;
                                case Properties::West::TALL:
                                    return 15560;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15561;
                                case Properties::West::LOW:
                                    return 15562;
                                case Properties::West::TALL:
                                    return 15563;
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
                                    return 15564;
                                case Properties::West::LOW:
                                    return 15565;
                                case Properties::West::TALL:
                                    return 15566;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15567;
                                case Properties::West::LOW:
                                    return 15568;
                                case Properties::West::TALL:
                                    return 15569;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15570;
                                case Properties::West::LOW:
                                    return 15571;
                                case Properties::West::TALL:
                                    return 15572;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15573;
                                case Properties::West::LOW:
                                    return 15574;
                                case Properties::West::TALL:
                                    return 15575;
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
                                    return 15576;
                                case Properties::West::LOW:
                                    return 15577;
                                case Properties::West::TALL:
                                    return 15578;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15579;
                                case Properties::West::LOW:
                                    return 15580;
                                case Properties::West::TALL:
                                    return 15581;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15582;
                                case Properties::West::LOW:
                                    return 15583;
                                case Properties::West::TALL:
                                    return 15584;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15585;
                                case Properties::West::LOW:
                                    return 15586;
                                case Properties::West::TALL:
                                    return 15587;
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
                                    return 15588;
                                case Properties::West::LOW:
                                    return 15589;
                                case Properties::West::TALL:
                                    return 15590;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15591;
                                case Properties::West::LOW:
                                    return 15592;
                                case Properties::West::TALL:
                                    return 15593;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15594;
                                case Properties::West::LOW:
                                    return 15595;
                                case Properties::West::TALL:
                                    return 15596;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15597;
                                case Properties::West::LOW:
                                    return 15598;
                                case Properties::West::TALL:
                                    return 15599;
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
                                    return 15600;
                                case Properties::West::LOW:
                                    return 15601;
                                case Properties::West::TALL:
                                    return 15602;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15603;
                                case Properties::West::LOW:
                                    return 15604;
                                case Properties::West::TALL:
                                    return 15605;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15606;
                                case Properties::West::LOW:
                                    return 15607;
                                case Properties::West::TALL:
                                    return 15608;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15609;
                                case Properties::West::LOW:
                                    return 15610;
                                case Properties::West::TALL:
                                    return 15611;
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
                                    return 15612;
                                case Properties::West::LOW:
                                    return 15613;
                                case Properties::West::TALL:
                                    return 15614;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15615;
                                case Properties::West::LOW:
                                    return 15616;
                                case Properties::West::TALL:
                                    return 15617;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15618;
                                case Properties::West::LOW:
                                    return 15619;
                                case Properties::West::TALL:
                                    return 15620;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15621;
                                case Properties::West::LOW:
                                    return 15622;
                                case Properties::West::TALL:
                                    return 15623;
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
                                    return 15624;
                                case Properties::West::LOW:
                                    return 15625;
                                case Properties::West::TALL:
                                    return 15626;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15627;
                                case Properties::West::LOW:
                                    return 15628;
                                case Properties::West::TALL:
                                    return 15629;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15630;
                                case Properties::West::LOW:
                                    return 15631;
                                case Properties::West::TALL:
                                    return 15632;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15633;
                                case Properties::West::LOW:
                                    return 15634;
                                case Properties::West::TALL:
                                    return 15635;
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
