#include "StoneBrickWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StoneBrickWall {
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
                                    return 13368;
                                case Properties::West::LOW:
                                    return 13369;
                                case Properties::West::TALL:
                                    return 13370;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13371;
                                case Properties::West::LOW:
                                    return 13372;
                                case Properties::West::TALL:
                                    return 13373;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13374;
                                case Properties::West::LOW:
                                    return 13375;
                                case Properties::West::TALL:
                                    return 13376;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13377;
                                case Properties::West::LOW:
                                    return 13378;
                                case Properties::West::TALL:
                                    return 13379;
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
                                    return 13380;
                                case Properties::West::LOW:
                                    return 13381;
                                case Properties::West::TALL:
                                    return 13382;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13383;
                                case Properties::West::LOW:
                                    return 13384;
                                case Properties::West::TALL:
                                    return 13385;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13386;
                                case Properties::West::LOW:
                                    return 13387;
                                case Properties::West::TALL:
                                    return 13388;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13389;
                                case Properties::West::LOW:
                                    return 13390;
                                case Properties::West::TALL:
                                    return 13391;
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
                                    return 13392;
                                case Properties::West::LOW:
                                    return 13393;
                                case Properties::West::TALL:
                                    return 13394;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13395;
                                case Properties::West::LOW:
                                    return 13396;
                                case Properties::West::TALL:
                                    return 13397;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13398;
                                case Properties::West::LOW:
                                    return 13399;
                                case Properties::West::TALL:
                                    return 13400;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13401;
                                case Properties::West::LOW:
                                    return 13402;
                                case Properties::West::TALL:
                                    return 13403;
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
                                    return 13404;
                                case Properties::West::LOW:
                                    return 13405;
                                case Properties::West::TALL:
                                    return 13406;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13407;
                                case Properties::West::LOW:
                                    return 13408;
                                case Properties::West::TALL:
                                    return 13409;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13410;
                                case Properties::West::LOW:
                                    return 13411;
                                case Properties::West::TALL:
                                    return 13412;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13413;
                                case Properties::West::LOW:
                                    return 13414;
                                case Properties::West::TALL:
                                    return 13415;
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
                                    return 13416;
                                case Properties::West::LOW:
                                    return 13417;
                                case Properties::West::TALL:
                                    return 13418;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13419;
                                case Properties::West::LOW:
                                    return 13420;
                                case Properties::West::TALL:
                                    return 13421;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13422;
                                case Properties::West::LOW:
                                    return 13423;
                                case Properties::West::TALL:
                                    return 13424;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13425;
                                case Properties::West::LOW:
                                    return 13426;
                                case Properties::West::TALL:
                                    return 13427;
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
                                    return 13428;
                                case Properties::West::LOW:
                                    return 13429;
                                case Properties::West::TALL:
                                    return 13430;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13431;
                                case Properties::West::LOW:
                                    return 13432;
                                case Properties::West::TALL:
                                    return 13433;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13434;
                                case Properties::West::LOW:
                                    return 13435;
                                case Properties::West::TALL:
                                    return 13436;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13437;
                                case Properties::West::LOW:
                                    return 13438;
                                case Properties::West::TALL:
                                    return 13439;
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
                                    return 13440;
                                case Properties::West::LOW:
                                    return 13441;
                                case Properties::West::TALL:
                                    return 13442;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13443;
                                case Properties::West::LOW:
                                    return 13444;
                                case Properties::West::TALL:
                                    return 13445;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13446;
                                case Properties::West::LOW:
                                    return 13447;
                                case Properties::West::TALL:
                                    return 13448;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13449;
                                case Properties::West::LOW:
                                    return 13450;
                                case Properties::West::TALL:
                                    return 13451;
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
                                    return 13452;
                                case Properties::West::LOW:
                                    return 13453;
                                case Properties::West::TALL:
                                    return 13454;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13455;
                                case Properties::West::LOW:
                                    return 13456;
                                case Properties::West::TALL:
                                    return 13457;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13458;
                                case Properties::West::LOW:
                                    return 13459;
                                case Properties::West::TALL:
                                    return 13460;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13461;
                                case Properties::West::LOW:
                                    return 13462;
                                case Properties::West::TALL:
                                    return 13463;
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
                                    return 13464;
                                case Properties::West::LOW:
                                    return 13465;
                                case Properties::West::TALL:
                                    return 13466;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13467;
                                case Properties::West::LOW:
                                    return 13468;
                                case Properties::West::TALL:
                                    return 13469;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13470;
                                case Properties::West::LOW:
                                    return 13471;
                                case Properties::West::TALL:
                                    return 13472;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13473;
                                case Properties::West::LOW:
                                    return 13474;
                                case Properties::West::TALL:
                                    return 13475;
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
                                    return 13476;
                                case Properties::West::LOW:
                                    return 13477;
                                case Properties::West::TALL:
                                    return 13478;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13479;
                                case Properties::West::LOW:
                                    return 13480;
                                case Properties::West::TALL:
                                    return 13481;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13482;
                                case Properties::West::LOW:
                                    return 13483;
                                case Properties::West::TALL:
                                    return 13484;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13485;
                                case Properties::West::LOW:
                                    return 13486;
                                case Properties::West::TALL:
                                    return 13487;
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
                                    return 13488;
                                case Properties::West::LOW:
                                    return 13489;
                                case Properties::West::TALL:
                                    return 13490;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13491;
                                case Properties::West::LOW:
                                    return 13492;
                                case Properties::West::TALL:
                                    return 13493;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13494;
                                case Properties::West::LOW:
                                    return 13495;
                                case Properties::West::TALL:
                                    return 13496;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13497;
                                case Properties::West::LOW:
                                    return 13498;
                                case Properties::West::TALL:
                                    return 13499;
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
                                    return 13500;
                                case Properties::West::LOW:
                                    return 13501;
                                case Properties::West::TALL:
                                    return 13502;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13503;
                                case Properties::West::LOW:
                                    return 13504;
                                case Properties::West::TALL:
                                    return 13505;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13506;
                                case Properties::West::LOW:
                                    return 13507;
                                case Properties::West::TALL:
                                    return 13508;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13509;
                                case Properties::West::LOW:
                                    return 13510;
                                case Properties::West::TALL:
                                    return 13511;
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
                                    return 13512;
                                case Properties::West::LOW:
                                    return 13513;
                                case Properties::West::TALL:
                                    return 13514;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13515;
                                case Properties::West::LOW:
                                    return 13516;
                                case Properties::West::TALL:
                                    return 13517;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13518;
                                case Properties::West::LOW:
                                    return 13519;
                                case Properties::West::TALL:
                                    return 13520;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13521;
                                case Properties::West::LOW:
                                    return 13522;
                                case Properties::West::TALL:
                                    return 13523;
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
                                    return 13524;
                                case Properties::West::LOW:
                                    return 13525;
                                case Properties::West::TALL:
                                    return 13526;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13527;
                                case Properties::West::LOW:
                                    return 13528;
                                case Properties::West::TALL:
                                    return 13529;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13530;
                                case Properties::West::LOW:
                                    return 13531;
                                case Properties::West::TALL:
                                    return 13532;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13533;
                                case Properties::West::LOW:
                                    return 13534;
                                case Properties::West::TALL:
                                    return 13535;
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
                                    return 13536;
                                case Properties::West::LOW:
                                    return 13537;
                                case Properties::West::TALL:
                                    return 13538;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13539;
                                case Properties::West::LOW:
                                    return 13540;
                                case Properties::West::TALL:
                                    return 13541;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13542;
                                case Properties::West::LOW:
                                    return 13543;
                                case Properties::West::TALL:
                                    return 13544;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13545;
                                case Properties::West::LOW:
                                    return 13546;
                                case Properties::West::TALL:
                                    return 13547;
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
                                    return 13548;
                                case Properties::West::LOW:
                                    return 13549;
                                case Properties::West::TALL:
                                    return 13550;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13551;
                                case Properties::West::LOW:
                                    return 13552;
                                case Properties::West::TALL:
                                    return 13553;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13554;
                                case Properties::West::LOW:
                                    return 13555;
                                case Properties::West::TALL:
                                    return 13556;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13557;
                                case Properties::West::LOW:
                                    return 13558;
                                case Properties::West::TALL:
                                    return 13559;
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
                                    return 13560;
                                case Properties::West::LOW:
                                    return 13561;
                                case Properties::West::TALL:
                                    return 13562;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13563;
                                case Properties::West::LOW:
                                    return 13564;
                                case Properties::West::TALL:
                                    return 13565;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13566;
                                case Properties::West::LOW:
                                    return 13567;
                                case Properties::West::TALL:
                                    return 13568;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13569;
                                case Properties::West::LOW:
                                    return 13570;
                                case Properties::West::TALL:
                                    return 13571;
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
                                    return 13572;
                                case Properties::West::LOW:
                                    return 13573;
                                case Properties::West::TALL:
                                    return 13574;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13575;
                                case Properties::West::LOW:
                                    return 13576;
                                case Properties::West::TALL:
                                    return 13577;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13578;
                                case Properties::West::LOW:
                                    return 13579;
                                case Properties::West::TALL:
                                    return 13580;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13581;
                                case Properties::West::LOW:
                                    return 13582;
                                case Properties::West::TALL:
                                    return 13583;
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
                                    return 13584;
                                case Properties::West::LOW:
                                    return 13585;
                                case Properties::West::TALL:
                                    return 13586;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13587;
                                case Properties::West::LOW:
                                    return 13588;
                                case Properties::West::TALL:
                                    return 13589;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13590;
                                case Properties::West::LOW:
                                    return 13591;
                                case Properties::West::TALL:
                                    return 13592;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13593;
                                case Properties::West::LOW:
                                    return 13594;
                                case Properties::West::TALL:
                                    return 13595;
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
                                    return 13596;
                                case Properties::West::LOW:
                                    return 13597;
                                case Properties::West::TALL:
                                    return 13598;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13599;
                                case Properties::West::LOW:
                                    return 13600;
                                case Properties::West::TALL:
                                    return 13601;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13602;
                                case Properties::West::LOW:
                                    return 13603;
                                case Properties::West::TALL:
                                    return 13604;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13605;
                                case Properties::West::LOW:
                                    return 13606;
                                case Properties::West::TALL:
                                    return 13607;
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
                                    return 13608;
                                case Properties::West::LOW:
                                    return 13609;
                                case Properties::West::TALL:
                                    return 13610;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13611;
                                case Properties::West::LOW:
                                    return 13612;
                                case Properties::West::TALL:
                                    return 13613;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13614;
                                case Properties::West::LOW:
                                    return 13615;
                                case Properties::West::TALL:
                                    return 13616;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13617;
                                case Properties::West::LOW:
                                    return 13618;
                                case Properties::West::TALL:
                                    return 13619;
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
                                    return 13620;
                                case Properties::West::LOW:
                                    return 13621;
                                case Properties::West::TALL:
                                    return 13622;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13623;
                                case Properties::West::LOW:
                                    return 13624;
                                case Properties::West::TALL:
                                    return 13625;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13626;
                                case Properties::West::LOW:
                                    return 13627;
                                case Properties::West::TALL:
                                    return 13628;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13629;
                                case Properties::West::LOW:
                                    return 13630;
                                case Properties::West::TALL:
                                    return 13631;
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
                                    return 13632;
                                case Properties::West::LOW:
                                    return 13633;
                                case Properties::West::TALL:
                                    return 13634;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13635;
                                case Properties::West::LOW:
                                    return 13636;
                                case Properties::West::TALL:
                                    return 13637;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13638;
                                case Properties::West::LOW:
                                    return 13639;
                                case Properties::West::TALL:
                                    return 13640;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13641;
                                case Properties::West::LOW:
                                    return 13642;
                                case Properties::West::TALL:
                                    return 13643;
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
                                    return 13644;
                                case Properties::West::LOW:
                                    return 13645;
                                case Properties::West::TALL:
                                    return 13646;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13647;
                                case Properties::West::LOW:
                                    return 13648;
                                case Properties::West::TALL:
                                    return 13649;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13650;
                                case Properties::West::LOW:
                                    return 13651;
                                case Properties::West::TALL:
                                    return 13652;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13653;
                                case Properties::West::LOW:
                                    return 13654;
                                case Properties::West::TALL:
                                    return 13655;
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
                                    return 13656;
                                case Properties::West::LOW:
                                    return 13657;
                                case Properties::West::TALL:
                                    return 13658;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13659;
                                case Properties::West::LOW:
                                    return 13660;
                                case Properties::West::TALL:
                                    return 13661;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13662;
                                case Properties::West::LOW:
                                    return 13663;
                                case Properties::West::TALL:
                                    return 13664;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13665;
                                case Properties::West::LOW:
                                    return 13666;
                                case Properties::West::TALL:
                                    return 13667;
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
                                    return 13668;
                                case Properties::West::LOW:
                                    return 13669;
                                case Properties::West::TALL:
                                    return 13670;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13671;
                                case Properties::West::LOW:
                                    return 13672;
                                case Properties::West::TALL:
                                    return 13673;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13674;
                                case Properties::West::LOW:
                                    return 13675;
                                case Properties::West::TALL:
                                    return 13676;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13677;
                                case Properties::West::LOW:
                                    return 13678;
                                case Properties::West::TALL:
                                    return 13679;
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
                                    return 13680;
                                case Properties::West::LOW:
                                    return 13681;
                                case Properties::West::TALL:
                                    return 13682;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13683;
                                case Properties::West::LOW:
                                    return 13684;
                                case Properties::West::TALL:
                                    return 13685;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13686;
                                case Properties::West::LOW:
                                    return 13687;
                                case Properties::West::TALL:
                                    return 13688;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13689;
                                case Properties::West::LOW:
                                    return 13690;
                                case Properties::West::TALL:
                                    return 13691;
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
