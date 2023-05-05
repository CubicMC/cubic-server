#include "MudBrickWall.hpp"
namespace Blocks {
    namespace MudBrickWall {
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
                                    return 15476;
                                case Properties::West::LOW:
                                    return 15477;
                                case Properties::West::TALL:
                                    return 15478;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15479;
                                case Properties::West::LOW:
                                    return 15480;
                                case Properties::West::TALL:
                                    return 15481;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15482;
                                case Properties::West::LOW:
                                    return 15483;
                                case Properties::West::TALL:
                                    return 15484;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15485;
                                case Properties::West::LOW:
                                    return 15486;
                                case Properties::West::TALL:
                                    return 15487;
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
                                    return 15488;
                                case Properties::West::LOW:
                                    return 15489;
                                case Properties::West::TALL:
                                    return 15490;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15491;
                                case Properties::West::LOW:
                                    return 15492;
                                case Properties::West::TALL:
                                    return 15493;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15494;
                                case Properties::West::LOW:
                                    return 15495;
                                case Properties::West::TALL:
                                    return 15496;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15497;
                                case Properties::West::LOW:
                                    return 15498;
                                case Properties::West::TALL:
                                    return 15499;
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
                                    return 15500;
                                case Properties::West::LOW:
                                    return 15501;
                                case Properties::West::TALL:
                                    return 15502;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15503;
                                case Properties::West::LOW:
                                    return 15504;
                                case Properties::West::TALL:
                                    return 15505;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15506;
                                case Properties::West::LOW:
                                    return 15507;
                                case Properties::West::TALL:
                                    return 15508;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15509;
                                case Properties::West::LOW:
                                    return 15510;
                                case Properties::West::TALL:
                                    return 15511;
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
                                    return 15512;
                                case Properties::West::LOW:
                                    return 15513;
                                case Properties::West::TALL:
                                    return 15514;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15515;
                                case Properties::West::LOW:
                                    return 15516;
                                case Properties::West::TALL:
                                    return 15517;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15518;
                                case Properties::West::LOW:
                                    return 15519;
                                case Properties::West::TALL:
                                    return 15520;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15521;
                                case Properties::West::LOW:
                                    return 15522;
                                case Properties::West::TALL:
                                    return 15523;
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
                                    return 15524;
                                case Properties::West::LOW:
                                    return 15525;
                                case Properties::West::TALL:
                                    return 15526;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15527;
                                case Properties::West::LOW:
                                    return 15528;
                                case Properties::West::TALL:
                                    return 15529;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15530;
                                case Properties::West::LOW:
                                    return 15531;
                                case Properties::West::TALL:
                                    return 15532;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15533;
                                case Properties::West::LOW:
                                    return 15534;
                                case Properties::West::TALL:
                                    return 15535;
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
                                    return 15536;
                                case Properties::West::LOW:
                                    return 15537;
                                case Properties::West::TALL:
                                    return 15538;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15539;
                                case Properties::West::LOW:
                                    return 15540;
                                case Properties::West::TALL:
                                    return 15541;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15542;
                                case Properties::West::LOW:
                                    return 15543;
                                case Properties::West::TALL:
                                    return 15544;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15545;
                                case Properties::West::LOW:
                                    return 15546;
                                case Properties::West::TALL:
                                    return 15547;
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
                                    return 15548;
                                case Properties::West::LOW:
                                    return 15549;
                                case Properties::West::TALL:
                                    return 15550;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15551;
                                case Properties::West::LOW:
                                    return 15552;
                                case Properties::West::TALL:
                                    return 15553;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15554;
                                case Properties::West::LOW:
                                    return 15555;
                                case Properties::West::TALL:
                                    return 15556;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15557;
                                case Properties::West::LOW:
                                    return 15558;
                                case Properties::West::TALL:
                                    return 15559;
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
                                    return 15560;
                                case Properties::West::LOW:
                                    return 15561;
                                case Properties::West::TALL:
                                    return 15562;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15563;
                                case Properties::West::LOW:
                                    return 15564;
                                case Properties::West::TALL:
                                    return 15565;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15566;
                                case Properties::West::LOW:
                                    return 15567;
                                case Properties::West::TALL:
                                    return 15568;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15569;
                                case Properties::West::LOW:
                                    return 15570;
                                case Properties::West::TALL:
                                    return 15571;
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
                                    return 15572;
                                case Properties::West::LOW:
                                    return 15573;
                                case Properties::West::TALL:
                                    return 15574;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15575;
                                case Properties::West::LOW:
                                    return 15576;
                                case Properties::West::TALL:
                                    return 15577;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15578;
                                case Properties::West::LOW:
                                    return 15579;
                                case Properties::West::TALL:
                                    return 15580;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15581;
                                case Properties::West::LOW:
                                    return 15582;
                                case Properties::West::TALL:
                                    return 15583;
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
                                    return 15584;
                                case Properties::West::LOW:
                                    return 15585;
                                case Properties::West::TALL:
                                    return 15586;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15587;
                                case Properties::West::LOW:
                                    return 15588;
                                case Properties::West::TALL:
                                    return 15589;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15590;
                                case Properties::West::LOW:
                                    return 15591;
                                case Properties::West::TALL:
                                    return 15592;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15593;
                                case Properties::West::LOW:
                                    return 15594;
                                case Properties::West::TALL:
                                    return 15595;
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
                                    return 15596;
                                case Properties::West::LOW:
                                    return 15597;
                                case Properties::West::TALL:
                                    return 15598;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15599;
                                case Properties::West::LOW:
                                    return 15600;
                                case Properties::West::TALL:
                                    return 15601;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15602;
                                case Properties::West::LOW:
                                    return 15603;
                                case Properties::West::TALL:
                                    return 15604;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15605;
                                case Properties::West::LOW:
                                    return 15606;
                                case Properties::West::TALL:
                                    return 15607;
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
                                    return 15608;
                                case Properties::West::LOW:
                                    return 15609;
                                case Properties::West::TALL:
                                    return 15610;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15611;
                                case Properties::West::LOW:
                                    return 15612;
                                case Properties::West::TALL:
                                    return 15613;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15614;
                                case Properties::West::LOW:
                                    return 15615;
                                case Properties::West::TALL:
                                    return 15616;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15617;
                                case Properties::West::LOW:
                                    return 15618;
                                case Properties::West::TALL:
                                    return 15619;
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
                                    return 15620;
                                case Properties::West::LOW:
                                    return 15621;
                                case Properties::West::TALL:
                                    return 15622;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15623;
                                case Properties::West::LOW:
                                    return 15624;
                                case Properties::West::TALL:
                                    return 15625;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15626;
                                case Properties::West::LOW:
                                    return 15627;
                                case Properties::West::TALL:
                                    return 15628;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15629;
                                case Properties::West::LOW:
                                    return 15630;
                                case Properties::West::TALL:
                                    return 15631;
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
                                    return 15632;
                                case Properties::West::LOW:
                                    return 15633;
                                case Properties::West::TALL:
                                    return 15634;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15635;
                                case Properties::West::LOW:
                                    return 15636;
                                case Properties::West::TALL:
                                    return 15637;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15638;
                                case Properties::West::LOW:
                                    return 15639;
                                case Properties::West::TALL:
                                    return 15640;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15641;
                                case Properties::West::LOW:
                                    return 15642;
                                case Properties::West::TALL:
                                    return 15643;
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
                                    return 15644;
                                case Properties::West::LOW:
                                    return 15645;
                                case Properties::West::TALL:
                                    return 15646;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15647;
                                case Properties::West::LOW:
                                    return 15648;
                                case Properties::West::TALL:
                                    return 15649;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15650;
                                case Properties::West::LOW:
                                    return 15651;
                                case Properties::West::TALL:
                                    return 15652;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15653;
                                case Properties::West::LOW:
                                    return 15654;
                                case Properties::West::TALL:
                                    return 15655;
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
                                    return 15656;
                                case Properties::West::LOW:
                                    return 15657;
                                case Properties::West::TALL:
                                    return 15658;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15659;
                                case Properties::West::LOW:
                                    return 15660;
                                case Properties::West::TALL:
                                    return 15661;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15662;
                                case Properties::West::LOW:
                                    return 15663;
                                case Properties::West::TALL:
                                    return 15664;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15665;
                                case Properties::West::LOW:
                                    return 15666;
                                case Properties::West::TALL:
                                    return 15667;
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
                                    return 15668;
                                case Properties::West::LOW:
                                    return 15669;
                                case Properties::West::TALL:
                                    return 15670;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15671;
                                case Properties::West::LOW:
                                    return 15672;
                                case Properties::West::TALL:
                                    return 15673;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15674;
                                case Properties::West::LOW:
                                    return 15675;
                                case Properties::West::TALL:
                                    return 15676;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15677;
                                case Properties::West::LOW:
                                    return 15678;
                                case Properties::West::TALL:
                                    return 15679;
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
                                    return 15680;
                                case Properties::West::LOW:
                                    return 15681;
                                case Properties::West::TALL:
                                    return 15682;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15683;
                                case Properties::West::LOW:
                                    return 15684;
                                case Properties::West::TALL:
                                    return 15685;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15686;
                                case Properties::West::LOW:
                                    return 15687;
                                case Properties::West::TALL:
                                    return 15688;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15689;
                                case Properties::West::LOW:
                                    return 15690;
                                case Properties::West::TALL:
                                    return 15691;
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
                                    return 15692;
                                case Properties::West::LOW:
                                    return 15693;
                                case Properties::West::TALL:
                                    return 15694;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15695;
                                case Properties::West::LOW:
                                    return 15696;
                                case Properties::West::TALL:
                                    return 15697;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15698;
                                case Properties::West::LOW:
                                    return 15699;
                                case Properties::West::TALL:
                                    return 15700;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15701;
                                case Properties::West::LOW:
                                    return 15702;
                                case Properties::West::TALL:
                                    return 15703;
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
                                    return 15704;
                                case Properties::West::LOW:
                                    return 15705;
                                case Properties::West::TALL:
                                    return 15706;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15707;
                                case Properties::West::LOW:
                                    return 15708;
                                case Properties::West::TALL:
                                    return 15709;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15710;
                                case Properties::West::LOW:
                                    return 15711;
                                case Properties::West::TALL:
                                    return 15712;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15713;
                                case Properties::West::LOW:
                                    return 15714;
                                case Properties::West::TALL:
                                    return 15715;
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
                                    return 15716;
                                case Properties::West::LOW:
                                    return 15717;
                                case Properties::West::TALL:
                                    return 15718;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15719;
                                case Properties::West::LOW:
                                    return 15720;
                                case Properties::West::TALL:
                                    return 15721;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15722;
                                case Properties::West::LOW:
                                    return 15723;
                                case Properties::West::TALL:
                                    return 15724;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15725;
                                case Properties::West::LOW:
                                    return 15726;
                                case Properties::West::TALL:
                                    return 15727;
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
                                    return 15728;
                                case Properties::West::LOW:
                                    return 15729;
                                case Properties::West::TALL:
                                    return 15730;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15731;
                                case Properties::West::LOW:
                                    return 15732;
                                case Properties::West::TALL:
                                    return 15733;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15734;
                                case Properties::West::LOW:
                                    return 15735;
                                case Properties::West::TALL:
                                    return 15736;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15737;
                                case Properties::West::LOW:
                                    return 15738;
                                case Properties::West::TALL:
                                    return 15739;
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
                                    return 15740;
                                case Properties::West::LOW:
                                    return 15741;
                                case Properties::West::TALL:
                                    return 15742;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15743;
                                case Properties::West::LOW:
                                    return 15744;
                                case Properties::West::TALL:
                                    return 15745;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15746;
                                case Properties::West::LOW:
                                    return 15747;
                                case Properties::West::TALL:
                                    return 15748;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15749;
                                case Properties::West::LOW:
                                    return 15750;
                                case Properties::West::TALL:
                                    return 15751;
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
                                    return 15752;
                                case Properties::West::LOW:
                                    return 15753;
                                case Properties::West::TALL:
                                    return 15754;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15755;
                                case Properties::West::LOW:
                                    return 15756;
                                case Properties::West::TALL:
                                    return 15757;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15758;
                                case Properties::West::LOW:
                                    return 15759;
                                case Properties::West::TALL:
                                    return 15760;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15761;
                                case Properties::West::LOW:
                                    return 15762;
                                case Properties::West::TALL:
                                    return 15763;
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
                                    return 15764;
                                case Properties::West::LOW:
                                    return 15765;
                                case Properties::West::TALL:
                                    return 15766;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15767;
                                case Properties::West::LOW:
                                    return 15768;
                                case Properties::West::TALL:
                                    return 15769;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15770;
                                case Properties::West::LOW:
                                    return 15771;
                                case Properties::West::TALL:
                                    return 15772;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15773;
                                case Properties::West::LOW:
                                    return 15774;
                                case Properties::West::TALL:
                                    return 15775;
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
                                    return 15776;
                                case Properties::West::LOW:
                                    return 15777;
                                case Properties::West::TALL:
                                    return 15778;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15779;
                                case Properties::West::LOW:
                                    return 15780;
                                case Properties::West::TALL:
                                    return 15781;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15782;
                                case Properties::West::LOW:
                                    return 15783;
                                case Properties::West::TALL:
                                    return 15784;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15785;
                                case Properties::West::LOW:
                                    return 15786;
                                case Properties::West::TALL:
                                    return 15787;
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
                                    return 15788;
                                case Properties::West::LOW:
                                    return 15789;
                                case Properties::West::TALL:
                                    return 15790;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15791;
                                case Properties::West::LOW:
                                    return 15792;
                                case Properties::West::TALL:
                                    return 15793;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15794;
                                case Properties::West::LOW:
                                    return 15795;
                                case Properties::West::TALL:
                                    return 15796;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15797;
                                case Properties::West::LOW:
                                    return 15798;
                                case Properties::West::TALL:
                                    return 15799;
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
