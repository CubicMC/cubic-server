#include "DioriteWall.hpp"
namespace Blocks {
    namespace DioriteWall {
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
                                    return 17420;
                                case Properties::West::LOW:
                                    return 17421;
                                case Properties::West::TALL:
                                    return 17422;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17423;
                                case Properties::West::LOW:
                                    return 17424;
                                case Properties::West::TALL:
                                    return 17425;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17426;
                                case Properties::West::LOW:
                                    return 17427;
                                case Properties::West::TALL:
                                    return 17428;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17429;
                                case Properties::West::LOW:
                                    return 17430;
                                case Properties::West::TALL:
                                    return 17431;
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
                                    return 17432;
                                case Properties::West::LOW:
                                    return 17433;
                                case Properties::West::TALL:
                                    return 17434;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17435;
                                case Properties::West::LOW:
                                    return 17436;
                                case Properties::West::TALL:
                                    return 17437;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17438;
                                case Properties::West::LOW:
                                    return 17439;
                                case Properties::West::TALL:
                                    return 17440;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17441;
                                case Properties::West::LOW:
                                    return 17442;
                                case Properties::West::TALL:
                                    return 17443;
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
                                    return 17444;
                                case Properties::West::LOW:
                                    return 17445;
                                case Properties::West::TALL:
                                    return 17446;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17447;
                                case Properties::West::LOW:
                                    return 17448;
                                case Properties::West::TALL:
                                    return 17449;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17450;
                                case Properties::West::LOW:
                                    return 17451;
                                case Properties::West::TALL:
                                    return 17452;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17453;
                                case Properties::West::LOW:
                                    return 17454;
                                case Properties::West::TALL:
                                    return 17455;
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
                                    return 17456;
                                case Properties::West::LOW:
                                    return 17457;
                                case Properties::West::TALL:
                                    return 17458;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17459;
                                case Properties::West::LOW:
                                    return 17460;
                                case Properties::West::TALL:
                                    return 17461;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17462;
                                case Properties::West::LOW:
                                    return 17463;
                                case Properties::West::TALL:
                                    return 17464;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17465;
                                case Properties::West::LOW:
                                    return 17466;
                                case Properties::West::TALL:
                                    return 17467;
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
                                    return 17468;
                                case Properties::West::LOW:
                                    return 17469;
                                case Properties::West::TALL:
                                    return 17470;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17471;
                                case Properties::West::LOW:
                                    return 17472;
                                case Properties::West::TALL:
                                    return 17473;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17474;
                                case Properties::West::LOW:
                                    return 17475;
                                case Properties::West::TALL:
                                    return 17476;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17477;
                                case Properties::West::LOW:
                                    return 17478;
                                case Properties::West::TALL:
                                    return 17479;
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
                                    return 17480;
                                case Properties::West::LOW:
                                    return 17481;
                                case Properties::West::TALL:
                                    return 17482;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17483;
                                case Properties::West::LOW:
                                    return 17484;
                                case Properties::West::TALL:
                                    return 17485;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17486;
                                case Properties::West::LOW:
                                    return 17487;
                                case Properties::West::TALL:
                                    return 17488;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17489;
                                case Properties::West::LOW:
                                    return 17490;
                                case Properties::West::TALL:
                                    return 17491;
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
                                    return 17492;
                                case Properties::West::LOW:
                                    return 17493;
                                case Properties::West::TALL:
                                    return 17494;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17495;
                                case Properties::West::LOW:
                                    return 17496;
                                case Properties::West::TALL:
                                    return 17497;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17498;
                                case Properties::West::LOW:
                                    return 17499;
                                case Properties::West::TALL:
                                    return 17500;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17501;
                                case Properties::West::LOW:
                                    return 17502;
                                case Properties::West::TALL:
                                    return 17503;
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
                                    return 17504;
                                case Properties::West::LOW:
                                    return 17505;
                                case Properties::West::TALL:
                                    return 17506;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17507;
                                case Properties::West::LOW:
                                    return 17508;
                                case Properties::West::TALL:
                                    return 17509;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17510;
                                case Properties::West::LOW:
                                    return 17511;
                                case Properties::West::TALL:
                                    return 17512;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17513;
                                case Properties::West::LOW:
                                    return 17514;
                                case Properties::West::TALL:
                                    return 17515;
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
                                    return 17516;
                                case Properties::West::LOW:
                                    return 17517;
                                case Properties::West::TALL:
                                    return 17518;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17519;
                                case Properties::West::LOW:
                                    return 17520;
                                case Properties::West::TALL:
                                    return 17521;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17522;
                                case Properties::West::LOW:
                                    return 17523;
                                case Properties::West::TALL:
                                    return 17524;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17525;
                                case Properties::West::LOW:
                                    return 17526;
                                case Properties::West::TALL:
                                    return 17527;
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
                                    return 17528;
                                case Properties::West::LOW:
                                    return 17529;
                                case Properties::West::TALL:
                                    return 17530;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17531;
                                case Properties::West::LOW:
                                    return 17532;
                                case Properties::West::TALL:
                                    return 17533;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17534;
                                case Properties::West::LOW:
                                    return 17535;
                                case Properties::West::TALL:
                                    return 17536;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17537;
                                case Properties::West::LOW:
                                    return 17538;
                                case Properties::West::TALL:
                                    return 17539;
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
                                    return 17540;
                                case Properties::West::LOW:
                                    return 17541;
                                case Properties::West::TALL:
                                    return 17542;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17543;
                                case Properties::West::LOW:
                                    return 17544;
                                case Properties::West::TALL:
                                    return 17545;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17546;
                                case Properties::West::LOW:
                                    return 17547;
                                case Properties::West::TALL:
                                    return 17548;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17549;
                                case Properties::West::LOW:
                                    return 17550;
                                case Properties::West::TALL:
                                    return 17551;
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
                                    return 17552;
                                case Properties::West::LOW:
                                    return 17553;
                                case Properties::West::TALL:
                                    return 17554;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17555;
                                case Properties::West::LOW:
                                    return 17556;
                                case Properties::West::TALL:
                                    return 17557;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17558;
                                case Properties::West::LOW:
                                    return 17559;
                                case Properties::West::TALL:
                                    return 17560;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17561;
                                case Properties::West::LOW:
                                    return 17562;
                                case Properties::West::TALL:
                                    return 17563;
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
                                    return 17564;
                                case Properties::West::LOW:
                                    return 17565;
                                case Properties::West::TALL:
                                    return 17566;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17567;
                                case Properties::West::LOW:
                                    return 17568;
                                case Properties::West::TALL:
                                    return 17569;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17570;
                                case Properties::West::LOW:
                                    return 17571;
                                case Properties::West::TALL:
                                    return 17572;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17573;
                                case Properties::West::LOW:
                                    return 17574;
                                case Properties::West::TALL:
                                    return 17575;
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
                                    return 17576;
                                case Properties::West::LOW:
                                    return 17577;
                                case Properties::West::TALL:
                                    return 17578;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17579;
                                case Properties::West::LOW:
                                    return 17580;
                                case Properties::West::TALL:
                                    return 17581;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17582;
                                case Properties::West::LOW:
                                    return 17583;
                                case Properties::West::TALL:
                                    return 17584;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17585;
                                case Properties::West::LOW:
                                    return 17586;
                                case Properties::West::TALL:
                                    return 17587;
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
                                    return 17588;
                                case Properties::West::LOW:
                                    return 17589;
                                case Properties::West::TALL:
                                    return 17590;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17591;
                                case Properties::West::LOW:
                                    return 17592;
                                case Properties::West::TALL:
                                    return 17593;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17594;
                                case Properties::West::LOW:
                                    return 17595;
                                case Properties::West::TALL:
                                    return 17596;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17597;
                                case Properties::West::LOW:
                                    return 17598;
                                case Properties::West::TALL:
                                    return 17599;
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
                                    return 17600;
                                case Properties::West::LOW:
                                    return 17601;
                                case Properties::West::TALL:
                                    return 17602;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17603;
                                case Properties::West::LOW:
                                    return 17604;
                                case Properties::West::TALL:
                                    return 17605;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17606;
                                case Properties::West::LOW:
                                    return 17607;
                                case Properties::West::TALL:
                                    return 17608;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17609;
                                case Properties::West::LOW:
                                    return 17610;
                                case Properties::West::TALL:
                                    return 17611;
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
                                    return 17612;
                                case Properties::West::LOW:
                                    return 17613;
                                case Properties::West::TALL:
                                    return 17614;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17615;
                                case Properties::West::LOW:
                                    return 17616;
                                case Properties::West::TALL:
                                    return 17617;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17618;
                                case Properties::West::LOW:
                                    return 17619;
                                case Properties::West::TALL:
                                    return 17620;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17621;
                                case Properties::West::LOW:
                                    return 17622;
                                case Properties::West::TALL:
                                    return 17623;
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
                                    return 17624;
                                case Properties::West::LOW:
                                    return 17625;
                                case Properties::West::TALL:
                                    return 17626;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17627;
                                case Properties::West::LOW:
                                    return 17628;
                                case Properties::West::TALL:
                                    return 17629;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17630;
                                case Properties::West::LOW:
                                    return 17631;
                                case Properties::West::TALL:
                                    return 17632;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17633;
                                case Properties::West::LOW:
                                    return 17634;
                                case Properties::West::TALL:
                                    return 17635;
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
                                    return 17636;
                                case Properties::West::LOW:
                                    return 17637;
                                case Properties::West::TALL:
                                    return 17638;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17639;
                                case Properties::West::LOW:
                                    return 17640;
                                case Properties::West::TALL:
                                    return 17641;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17642;
                                case Properties::West::LOW:
                                    return 17643;
                                case Properties::West::TALL:
                                    return 17644;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17645;
                                case Properties::West::LOW:
                                    return 17646;
                                case Properties::West::TALL:
                                    return 17647;
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
                                    return 17648;
                                case Properties::West::LOW:
                                    return 17649;
                                case Properties::West::TALL:
                                    return 17650;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17651;
                                case Properties::West::LOW:
                                    return 17652;
                                case Properties::West::TALL:
                                    return 17653;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17654;
                                case Properties::West::LOW:
                                    return 17655;
                                case Properties::West::TALL:
                                    return 17656;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17657;
                                case Properties::West::LOW:
                                    return 17658;
                                case Properties::West::TALL:
                                    return 17659;
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
                                    return 17660;
                                case Properties::West::LOW:
                                    return 17661;
                                case Properties::West::TALL:
                                    return 17662;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17663;
                                case Properties::West::LOW:
                                    return 17664;
                                case Properties::West::TALL:
                                    return 17665;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17666;
                                case Properties::West::LOW:
                                    return 17667;
                                case Properties::West::TALL:
                                    return 17668;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17669;
                                case Properties::West::LOW:
                                    return 17670;
                                case Properties::West::TALL:
                                    return 17671;
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
                                    return 17672;
                                case Properties::West::LOW:
                                    return 17673;
                                case Properties::West::TALL:
                                    return 17674;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17675;
                                case Properties::West::LOW:
                                    return 17676;
                                case Properties::West::TALL:
                                    return 17677;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17678;
                                case Properties::West::LOW:
                                    return 17679;
                                case Properties::West::TALL:
                                    return 17680;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17681;
                                case Properties::West::LOW:
                                    return 17682;
                                case Properties::West::TALL:
                                    return 17683;
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
                                    return 17684;
                                case Properties::West::LOW:
                                    return 17685;
                                case Properties::West::TALL:
                                    return 17686;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17687;
                                case Properties::West::LOW:
                                    return 17688;
                                case Properties::West::TALL:
                                    return 17689;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17690;
                                case Properties::West::LOW:
                                    return 17691;
                                case Properties::West::TALL:
                                    return 17692;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17693;
                                case Properties::West::LOW:
                                    return 17694;
                                case Properties::West::TALL:
                                    return 17695;
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
                                    return 17696;
                                case Properties::West::LOW:
                                    return 17697;
                                case Properties::West::TALL:
                                    return 17698;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17699;
                                case Properties::West::LOW:
                                    return 17700;
                                case Properties::West::TALL:
                                    return 17701;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17702;
                                case Properties::West::LOW:
                                    return 17703;
                                case Properties::West::TALL:
                                    return 17704;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17705;
                                case Properties::West::LOW:
                                    return 17706;
                                case Properties::West::TALL:
                                    return 17707;
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
                                    return 17708;
                                case Properties::West::LOW:
                                    return 17709;
                                case Properties::West::TALL:
                                    return 17710;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17711;
                                case Properties::West::LOW:
                                    return 17712;
                                case Properties::West::TALL:
                                    return 17713;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17714;
                                case Properties::West::LOW:
                                    return 17715;
                                case Properties::West::TALL:
                                    return 17716;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17717;
                                case Properties::West::LOW:
                                    return 17718;
                                case Properties::West::TALL:
                                    return 17719;
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
                                    return 17720;
                                case Properties::West::LOW:
                                    return 17721;
                                case Properties::West::TALL:
                                    return 17722;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17723;
                                case Properties::West::LOW:
                                    return 17724;
                                case Properties::West::TALL:
                                    return 17725;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17726;
                                case Properties::West::LOW:
                                    return 17727;
                                case Properties::West::TALL:
                                    return 17728;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17729;
                                case Properties::West::LOW:
                                    return 17730;
                                case Properties::West::TALL:
                                    return 17731;
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
                                    return 17732;
                                case Properties::West::LOW:
                                    return 17733;
                                case Properties::West::TALL:
                                    return 17734;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17735;
                                case Properties::West::LOW:
                                    return 17736;
                                case Properties::West::TALL:
                                    return 17737;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17738;
                                case Properties::West::LOW:
                                    return 17739;
                                case Properties::West::TALL:
                                    return 17740;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17741;
                                case Properties::West::LOW:
                                    return 17742;
                                case Properties::West::TALL:
                                    return 17743;
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
