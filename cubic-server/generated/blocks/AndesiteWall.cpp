#include "AndesiteWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace AndesiteWall {
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
                                    return 14340;
                                case Properties::West::LOW:
                                    return 14341;
                                case Properties::West::TALL:
                                    return 14342;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14343;
                                case Properties::West::LOW:
                                    return 14344;
                                case Properties::West::TALL:
                                    return 14345;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14346;
                                case Properties::West::LOW:
                                    return 14347;
                                case Properties::West::TALL:
                                    return 14348;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14349;
                                case Properties::West::LOW:
                                    return 14350;
                                case Properties::West::TALL:
                                    return 14351;
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
                                    return 14352;
                                case Properties::West::LOW:
                                    return 14353;
                                case Properties::West::TALL:
                                    return 14354;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14355;
                                case Properties::West::LOW:
                                    return 14356;
                                case Properties::West::TALL:
                                    return 14357;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14358;
                                case Properties::West::LOW:
                                    return 14359;
                                case Properties::West::TALL:
                                    return 14360;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14361;
                                case Properties::West::LOW:
                                    return 14362;
                                case Properties::West::TALL:
                                    return 14363;
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
                                    return 14364;
                                case Properties::West::LOW:
                                    return 14365;
                                case Properties::West::TALL:
                                    return 14366;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14367;
                                case Properties::West::LOW:
                                    return 14368;
                                case Properties::West::TALL:
                                    return 14369;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14370;
                                case Properties::West::LOW:
                                    return 14371;
                                case Properties::West::TALL:
                                    return 14372;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14373;
                                case Properties::West::LOW:
                                    return 14374;
                                case Properties::West::TALL:
                                    return 14375;
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
                                    return 14376;
                                case Properties::West::LOW:
                                    return 14377;
                                case Properties::West::TALL:
                                    return 14378;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14379;
                                case Properties::West::LOW:
                                    return 14380;
                                case Properties::West::TALL:
                                    return 14381;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14382;
                                case Properties::West::LOW:
                                    return 14383;
                                case Properties::West::TALL:
                                    return 14384;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14385;
                                case Properties::West::LOW:
                                    return 14386;
                                case Properties::West::TALL:
                                    return 14387;
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
                                    return 14388;
                                case Properties::West::LOW:
                                    return 14389;
                                case Properties::West::TALL:
                                    return 14390;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14391;
                                case Properties::West::LOW:
                                    return 14392;
                                case Properties::West::TALL:
                                    return 14393;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14394;
                                case Properties::West::LOW:
                                    return 14395;
                                case Properties::West::TALL:
                                    return 14396;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14397;
                                case Properties::West::LOW:
                                    return 14398;
                                case Properties::West::TALL:
                                    return 14399;
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
                                    return 14400;
                                case Properties::West::LOW:
                                    return 14401;
                                case Properties::West::TALL:
                                    return 14402;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14403;
                                case Properties::West::LOW:
                                    return 14404;
                                case Properties::West::TALL:
                                    return 14405;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14406;
                                case Properties::West::LOW:
                                    return 14407;
                                case Properties::West::TALL:
                                    return 14408;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14409;
                                case Properties::West::LOW:
                                    return 14410;
                                case Properties::West::TALL:
                                    return 14411;
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
                                    return 14412;
                                case Properties::West::LOW:
                                    return 14413;
                                case Properties::West::TALL:
                                    return 14414;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14415;
                                case Properties::West::LOW:
                                    return 14416;
                                case Properties::West::TALL:
                                    return 14417;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14418;
                                case Properties::West::LOW:
                                    return 14419;
                                case Properties::West::TALL:
                                    return 14420;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14421;
                                case Properties::West::LOW:
                                    return 14422;
                                case Properties::West::TALL:
                                    return 14423;
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
                                    return 14424;
                                case Properties::West::LOW:
                                    return 14425;
                                case Properties::West::TALL:
                                    return 14426;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14427;
                                case Properties::West::LOW:
                                    return 14428;
                                case Properties::West::TALL:
                                    return 14429;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14430;
                                case Properties::West::LOW:
                                    return 14431;
                                case Properties::West::TALL:
                                    return 14432;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14433;
                                case Properties::West::LOW:
                                    return 14434;
                                case Properties::West::TALL:
                                    return 14435;
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
                                    return 14436;
                                case Properties::West::LOW:
                                    return 14437;
                                case Properties::West::TALL:
                                    return 14438;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14439;
                                case Properties::West::LOW:
                                    return 14440;
                                case Properties::West::TALL:
                                    return 14441;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14442;
                                case Properties::West::LOW:
                                    return 14443;
                                case Properties::West::TALL:
                                    return 14444;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14445;
                                case Properties::West::LOW:
                                    return 14446;
                                case Properties::West::TALL:
                                    return 14447;
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
                                    return 14448;
                                case Properties::West::LOW:
                                    return 14449;
                                case Properties::West::TALL:
                                    return 14450;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14451;
                                case Properties::West::LOW:
                                    return 14452;
                                case Properties::West::TALL:
                                    return 14453;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14454;
                                case Properties::West::LOW:
                                    return 14455;
                                case Properties::West::TALL:
                                    return 14456;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14457;
                                case Properties::West::LOW:
                                    return 14458;
                                case Properties::West::TALL:
                                    return 14459;
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
                                    return 14460;
                                case Properties::West::LOW:
                                    return 14461;
                                case Properties::West::TALL:
                                    return 14462;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14463;
                                case Properties::West::LOW:
                                    return 14464;
                                case Properties::West::TALL:
                                    return 14465;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14466;
                                case Properties::West::LOW:
                                    return 14467;
                                case Properties::West::TALL:
                                    return 14468;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14469;
                                case Properties::West::LOW:
                                    return 14470;
                                case Properties::West::TALL:
                                    return 14471;
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
                                    return 14472;
                                case Properties::West::LOW:
                                    return 14473;
                                case Properties::West::TALL:
                                    return 14474;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14475;
                                case Properties::West::LOW:
                                    return 14476;
                                case Properties::West::TALL:
                                    return 14477;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14478;
                                case Properties::West::LOW:
                                    return 14479;
                                case Properties::West::TALL:
                                    return 14480;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14481;
                                case Properties::West::LOW:
                                    return 14482;
                                case Properties::West::TALL:
                                    return 14483;
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
                                    return 14484;
                                case Properties::West::LOW:
                                    return 14485;
                                case Properties::West::TALL:
                                    return 14486;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14487;
                                case Properties::West::LOW:
                                    return 14488;
                                case Properties::West::TALL:
                                    return 14489;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14490;
                                case Properties::West::LOW:
                                    return 14491;
                                case Properties::West::TALL:
                                    return 14492;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14493;
                                case Properties::West::LOW:
                                    return 14494;
                                case Properties::West::TALL:
                                    return 14495;
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
                                    return 14496;
                                case Properties::West::LOW:
                                    return 14497;
                                case Properties::West::TALL:
                                    return 14498;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14499;
                                case Properties::West::LOW:
                                    return 14500;
                                case Properties::West::TALL:
                                    return 14501;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14502;
                                case Properties::West::LOW:
                                    return 14503;
                                case Properties::West::TALL:
                                    return 14504;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14505;
                                case Properties::West::LOW:
                                    return 14506;
                                case Properties::West::TALL:
                                    return 14507;
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
                                    return 14508;
                                case Properties::West::LOW:
                                    return 14509;
                                case Properties::West::TALL:
                                    return 14510;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14511;
                                case Properties::West::LOW:
                                    return 14512;
                                case Properties::West::TALL:
                                    return 14513;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14514;
                                case Properties::West::LOW:
                                    return 14515;
                                case Properties::West::TALL:
                                    return 14516;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14517;
                                case Properties::West::LOW:
                                    return 14518;
                                case Properties::West::TALL:
                                    return 14519;
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
                                    return 14520;
                                case Properties::West::LOW:
                                    return 14521;
                                case Properties::West::TALL:
                                    return 14522;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14523;
                                case Properties::West::LOW:
                                    return 14524;
                                case Properties::West::TALL:
                                    return 14525;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14526;
                                case Properties::West::LOW:
                                    return 14527;
                                case Properties::West::TALL:
                                    return 14528;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14529;
                                case Properties::West::LOW:
                                    return 14530;
                                case Properties::West::TALL:
                                    return 14531;
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
                                    return 14532;
                                case Properties::West::LOW:
                                    return 14533;
                                case Properties::West::TALL:
                                    return 14534;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14535;
                                case Properties::West::LOW:
                                    return 14536;
                                case Properties::West::TALL:
                                    return 14537;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14538;
                                case Properties::West::LOW:
                                    return 14539;
                                case Properties::West::TALL:
                                    return 14540;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14541;
                                case Properties::West::LOW:
                                    return 14542;
                                case Properties::West::TALL:
                                    return 14543;
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
                                    return 14544;
                                case Properties::West::LOW:
                                    return 14545;
                                case Properties::West::TALL:
                                    return 14546;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14547;
                                case Properties::West::LOW:
                                    return 14548;
                                case Properties::West::TALL:
                                    return 14549;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14550;
                                case Properties::West::LOW:
                                    return 14551;
                                case Properties::West::TALL:
                                    return 14552;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14553;
                                case Properties::West::LOW:
                                    return 14554;
                                case Properties::West::TALL:
                                    return 14555;
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
                                    return 14556;
                                case Properties::West::LOW:
                                    return 14557;
                                case Properties::West::TALL:
                                    return 14558;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14559;
                                case Properties::West::LOW:
                                    return 14560;
                                case Properties::West::TALL:
                                    return 14561;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14562;
                                case Properties::West::LOW:
                                    return 14563;
                                case Properties::West::TALL:
                                    return 14564;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14565;
                                case Properties::West::LOW:
                                    return 14566;
                                case Properties::West::TALL:
                                    return 14567;
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
                                    return 14568;
                                case Properties::West::LOW:
                                    return 14569;
                                case Properties::West::TALL:
                                    return 14570;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14571;
                                case Properties::West::LOW:
                                    return 14572;
                                case Properties::West::TALL:
                                    return 14573;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14574;
                                case Properties::West::LOW:
                                    return 14575;
                                case Properties::West::TALL:
                                    return 14576;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14577;
                                case Properties::West::LOW:
                                    return 14578;
                                case Properties::West::TALL:
                                    return 14579;
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
                                    return 14580;
                                case Properties::West::LOW:
                                    return 14581;
                                case Properties::West::TALL:
                                    return 14582;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14583;
                                case Properties::West::LOW:
                                    return 14584;
                                case Properties::West::TALL:
                                    return 14585;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14586;
                                case Properties::West::LOW:
                                    return 14587;
                                case Properties::West::TALL:
                                    return 14588;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14589;
                                case Properties::West::LOW:
                                    return 14590;
                                case Properties::West::TALL:
                                    return 14591;
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
                                    return 14592;
                                case Properties::West::LOW:
                                    return 14593;
                                case Properties::West::TALL:
                                    return 14594;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14595;
                                case Properties::West::LOW:
                                    return 14596;
                                case Properties::West::TALL:
                                    return 14597;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14598;
                                case Properties::West::LOW:
                                    return 14599;
                                case Properties::West::TALL:
                                    return 14600;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14601;
                                case Properties::West::LOW:
                                    return 14602;
                                case Properties::West::TALL:
                                    return 14603;
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
                                    return 14604;
                                case Properties::West::LOW:
                                    return 14605;
                                case Properties::West::TALL:
                                    return 14606;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14607;
                                case Properties::West::LOW:
                                    return 14608;
                                case Properties::West::TALL:
                                    return 14609;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14610;
                                case Properties::West::LOW:
                                    return 14611;
                                case Properties::West::TALL:
                                    return 14612;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14613;
                                case Properties::West::LOW:
                                    return 14614;
                                case Properties::West::TALL:
                                    return 14615;
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
                                    return 14616;
                                case Properties::West::LOW:
                                    return 14617;
                                case Properties::West::TALL:
                                    return 14618;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14619;
                                case Properties::West::LOW:
                                    return 14620;
                                case Properties::West::TALL:
                                    return 14621;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14622;
                                case Properties::West::LOW:
                                    return 14623;
                                case Properties::West::TALL:
                                    return 14624;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14625;
                                case Properties::West::LOW:
                                    return 14626;
                                case Properties::West::TALL:
                                    return 14627;
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
                                    return 14628;
                                case Properties::West::LOW:
                                    return 14629;
                                case Properties::West::TALL:
                                    return 14630;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14631;
                                case Properties::West::LOW:
                                    return 14632;
                                case Properties::West::TALL:
                                    return 14633;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14634;
                                case Properties::West::LOW:
                                    return 14635;
                                case Properties::West::TALL:
                                    return 14636;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14637;
                                case Properties::West::LOW:
                                    return 14638;
                                case Properties::West::TALL:
                                    return 14639;
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
                                    return 14640;
                                case Properties::West::LOW:
                                    return 14641;
                                case Properties::West::TALL:
                                    return 14642;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14643;
                                case Properties::West::LOW:
                                    return 14644;
                                case Properties::West::TALL:
                                    return 14645;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14646;
                                case Properties::West::LOW:
                                    return 14647;
                                case Properties::West::TALL:
                                    return 14648;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14649;
                                case Properties::West::LOW:
                                    return 14650;
                                case Properties::West::TALL:
                                    return 14651;
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
                                    return 14652;
                                case Properties::West::LOW:
                                    return 14653;
                                case Properties::West::TALL:
                                    return 14654;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14655;
                                case Properties::West::LOW:
                                    return 14656;
                                case Properties::West::TALL:
                                    return 14657;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14658;
                                case Properties::West::LOW:
                                    return 14659;
                                case Properties::West::TALL:
                                    return 14660;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14661;
                                case Properties::West::LOW:
                                    return 14662;
                                case Properties::West::TALL:
                                    return 14663;
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
