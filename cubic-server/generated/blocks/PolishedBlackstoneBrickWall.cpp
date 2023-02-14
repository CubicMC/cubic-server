#include "PolishedBlackstoneBrickWall.hpp"
#include <stdexcept>

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
                                    return 17549;
                                case Properties::West::LOW:
                                    return 17550;
                                case Properties::West::TALL:
                                    return 17551;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17552;
                                case Properties::West::LOW:
                                    return 17553;
                                case Properties::West::TALL:
                                    return 17554;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17555;
                                case Properties::West::LOW:
                                    return 17556;
                                case Properties::West::TALL:
                                    return 17557;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17558;
                                case Properties::West::LOW:
                                    return 17559;
                                case Properties::West::TALL:
                                    return 17560;
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
                                    return 17561;
                                case Properties::West::LOW:
                                    return 17562;
                                case Properties::West::TALL:
                                    return 17563;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17564;
                                case Properties::West::LOW:
                                    return 17565;
                                case Properties::West::TALL:
                                    return 17566;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17567;
                                case Properties::West::LOW:
                                    return 17568;
                                case Properties::West::TALL:
                                    return 17569;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17570;
                                case Properties::West::LOW:
                                    return 17571;
                                case Properties::West::TALL:
                                    return 17572;
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
                                    return 17573;
                                case Properties::West::LOW:
                                    return 17574;
                                case Properties::West::TALL:
                                    return 17575;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17576;
                                case Properties::West::LOW:
                                    return 17577;
                                case Properties::West::TALL:
                                    return 17578;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17579;
                                case Properties::West::LOW:
                                    return 17580;
                                case Properties::West::TALL:
                                    return 17581;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17582;
                                case Properties::West::LOW:
                                    return 17583;
                                case Properties::West::TALL:
                                    return 17584;
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
                                    return 17585;
                                case Properties::West::LOW:
                                    return 17586;
                                case Properties::West::TALL:
                                    return 17587;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17588;
                                case Properties::West::LOW:
                                    return 17589;
                                case Properties::West::TALL:
                                    return 17590;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17591;
                                case Properties::West::LOW:
                                    return 17592;
                                case Properties::West::TALL:
                                    return 17593;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17594;
                                case Properties::West::LOW:
                                    return 17595;
                                case Properties::West::TALL:
                                    return 17596;
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
                                    return 17597;
                                case Properties::West::LOW:
                                    return 17598;
                                case Properties::West::TALL:
                                    return 17599;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17600;
                                case Properties::West::LOW:
                                    return 17601;
                                case Properties::West::TALL:
                                    return 17602;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17603;
                                case Properties::West::LOW:
                                    return 17604;
                                case Properties::West::TALL:
                                    return 17605;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17606;
                                case Properties::West::LOW:
                                    return 17607;
                                case Properties::West::TALL:
                                    return 17608;
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
                                    return 17609;
                                case Properties::West::LOW:
                                    return 17610;
                                case Properties::West::TALL:
                                    return 17611;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17612;
                                case Properties::West::LOW:
                                    return 17613;
                                case Properties::West::TALL:
                                    return 17614;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17615;
                                case Properties::West::LOW:
                                    return 17616;
                                case Properties::West::TALL:
                                    return 17617;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17618;
                                case Properties::West::LOW:
                                    return 17619;
                                case Properties::West::TALL:
                                    return 17620;
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
                                    return 17621;
                                case Properties::West::LOW:
                                    return 17622;
                                case Properties::West::TALL:
                                    return 17623;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17624;
                                case Properties::West::LOW:
                                    return 17625;
                                case Properties::West::TALL:
                                    return 17626;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17627;
                                case Properties::West::LOW:
                                    return 17628;
                                case Properties::West::TALL:
                                    return 17629;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17630;
                                case Properties::West::LOW:
                                    return 17631;
                                case Properties::West::TALL:
                                    return 17632;
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
                                    return 17633;
                                case Properties::West::LOW:
                                    return 17634;
                                case Properties::West::TALL:
                                    return 17635;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17636;
                                case Properties::West::LOW:
                                    return 17637;
                                case Properties::West::TALL:
                                    return 17638;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17639;
                                case Properties::West::LOW:
                                    return 17640;
                                case Properties::West::TALL:
                                    return 17641;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17642;
                                case Properties::West::LOW:
                                    return 17643;
                                case Properties::West::TALL:
                                    return 17644;
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
                                    return 17645;
                                case Properties::West::LOW:
                                    return 17646;
                                case Properties::West::TALL:
                                    return 17647;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17648;
                                case Properties::West::LOW:
                                    return 17649;
                                case Properties::West::TALL:
                                    return 17650;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17651;
                                case Properties::West::LOW:
                                    return 17652;
                                case Properties::West::TALL:
                                    return 17653;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17654;
                                case Properties::West::LOW:
                                    return 17655;
                                case Properties::West::TALL:
                                    return 17656;
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
                                    return 17657;
                                case Properties::West::LOW:
                                    return 17658;
                                case Properties::West::TALL:
                                    return 17659;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17660;
                                case Properties::West::LOW:
                                    return 17661;
                                case Properties::West::TALL:
                                    return 17662;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17663;
                                case Properties::West::LOW:
                                    return 17664;
                                case Properties::West::TALL:
                                    return 17665;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17666;
                                case Properties::West::LOW:
                                    return 17667;
                                case Properties::West::TALL:
                                    return 17668;
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
                                    return 17669;
                                case Properties::West::LOW:
                                    return 17670;
                                case Properties::West::TALL:
                                    return 17671;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17672;
                                case Properties::West::LOW:
                                    return 17673;
                                case Properties::West::TALL:
                                    return 17674;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17675;
                                case Properties::West::LOW:
                                    return 17676;
                                case Properties::West::TALL:
                                    return 17677;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17678;
                                case Properties::West::LOW:
                                    return 17679;
                                case Properties::West::TALL:
                                    return 17680;
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
                                    return 17681;
                                case Properties::West::LOW:
                                    return 17682;
                                case Properties::West::TALL:
                                    return 17683;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17684;
                                case Properties::West::LOW:
                                    return 17685;
                                case Properties::West::TALL:
                                    return 17686;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17687;
                                case Properties::West::LOW:
                                    return 17688;
                                case Properties::West::TALL:
                                    return 17689;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17690;
                                case Properties::West::LOW:
                                    return 17691;
                                case Properties::West::TALL:
                                    return 17692;
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
                                    return 17693;
                                case Properties::West::LOW:
                                    return 17694;
                                case Properties::West::TALL:
                                    return 17695;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17696;
                                case Properties::West::LOW:
                                    return 17697;
                                case Properties::West::TALL:
                                    return 17698;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17699;
                                case Properties::West::LOW:
                                    return 17700;
                                case Properties::West::TALL:
                                    return 17701;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17702;
                                case Properties::West::LOW:
                                    return 17703;
                                case Properties::West::TALL:
                                    return 17704;
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
                                    return 17705;
                                case Properties::West::LOW:
                                    return 17706;
                                case Properties::West::TALL:
                                    return 17707;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17708;
                                case Properties::West::LOW:
                                    return 17709;
                                case Properties::West::TALL:
                                    return 17710;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17711;
                                case Properties::West::LOW:
                                    return 17712;
                                case Properties::West::TALL:
                                    return 17713;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17714;
                                case Properties::West::LOW:
                                    return 17715;
                                case Properties::West::TALL:
                                    return 17716;
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
                                    return 17717;
                                case Properties::West::LOW:
                                    return 17718;
                                case Properties::West::TALL:
                                    return 17719;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17720;
                                case Properties::West::LOW:
                                    return 17721;
                                case Properties::West::TALL:
                                    return 17722;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17723;
                                case Properties::West::LOW:
                                    return 17724;
                                case Properties::West::TALL:
                                    return 17725;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17726;
                                case Properties::West::LOW:
                                    return 17727;
                                case Properties::West::TALL:
                                    return 17728;
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
                                    return 17729;
                                case Properties::West::LOW:
                                    return 17730;
                                case Properties::West::TALL:
                                    return 17731;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17732;
                                case Properties::West::LOW:
                                    return 17733;
                                case Properties::West::TALL:
                                    return 17734;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17735;
                                case Properties::West::LOW:
                                    return 17736;
                                case Properties::West::TALL:
                                    return 17737;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17738;
                                case Properties::West::LOW:
                                    return 17739;
                                case Properties::West::TALL:
                                    return 17740;
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
                                    return 17741;
                                case Properties::West::LOW:
                                    return 17742;
                                case Properties::West::TALL:
                                    return 17743;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17744;
                                case Properties::West::LOW:
                                    return 17745;
                                case Properties::West::TALL:
                                    return 17746;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17747;
                                case Properties::West::LOW:
                                    return 17748;
                                case Properties::West::TALL:
                                    return 17749;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17750;
                                case Properties::West::LOW:
                                    return 17751;
                                case Properties::West::TALL:
                                    return 17752;
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
                                    return 17753;
                                case Properties::West::LOW:
                                    return 17754;
                                case Properties::West::TALL:
                                    return 17755;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17756;
                                case Properties::West::LOW:
                                    return 17757;
                                case Properties::West::TALL:
                                    return 17758;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17759;
                                case Properties::West::LOW:
                                    return 17760;
                                case Properties::West::TALL:
                                    return 17761;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17762;
                                case Properties::West::LOW:
                                    return 17763;
                                case Properties::West::TALL:
                                    return 17764;
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
                                    return 17765;
                                case Properties::West::LOW:
                                    return 17766;
                                case Properties::West::TALL:
                                    return 17767;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17768;
                                case Properties::West::LOW:
                                    return 17769;
                                case Properties::West::TALL:
                                    return 17770;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17771;
                                case Properties::West::LOW:
                                    return 17772;
                                case Properties::West::TALL:
                                    return 17773;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17774;
                                case Properties::West::LOW:
                                    return 17775;
                                case Properties::West::TALL:
                                    return 17776;
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
                                    return 17777;
                                case Properties::West::LOW:
                                    return 17778;
                                case Properties::West::TALL:
                                    return 17779;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17780;
                                case Properties::West::LOW:
                                    return 17781;
                                case Properties::West::TALL:
                                    return 17782;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17783;
                                case Properties::West::LOW:
                                    return 17784;
                                case Properties::West::TALL:
                                    return 17785;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17786;
                                case Properties::West::LOW:
                                    return 17787;
                                case Properties::West::TALL:
                                    return 17788;
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
                                    return 17789;
                                case Properties::West::LOW:
                                    return 17790;
                                case Properties::West::TALL:
                                    return 17791;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17792;
                                case Properties::West::LOW:
                                    return 17793;
                                case Properties::West::TALL:
                                    return 17794;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17795;
                                case Properties::West::LOW:
                                    return 17796;
                                case Properties::West::TALL:
                                    return 17797;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17798;
                                case Properties::West::LOW:
                                    return 17799;
                                case Properties::West::TALL:
                                    return 17800;
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
                                    return 17801;
                                case Properties::West::LOW:
                                    return 17802;
                                case Properties::West::TALL:
                                    return 17803;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17804;
                                case Properties::West::LOW:
                                    return 17805;
                                case Properties::West::TALL:
                                    return 17806;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17807;
                                case Properties::West::LOW:
                                    return 17808;
                                case Properties::West::TALL:
                                    return 17809;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17810;
                                case Properties::West::LOW:
                                    return 17811;
                                case Properties::West::TALL:
                                    return 17812;
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
                                    return 17813;
                                case Properties::West::LOW:
                                    return 17814;
                                case Properties::West::TALL:
                                    return 17815;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17816;
                                case Properties::West::LOW:
                                    return 17817;
                                case Properties::West::TALL:
                                    return 17818;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17819;
                                case Properties::West::LOW:
                                    return 17820;
                                case Properties::West::TALL:
                                    return 17821;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17822;
                                case Properties::West::LOW:
                                    return 17823;
                                case Properties::West::TALL:
                                    return 17824;
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
                                    return 17825;
                                case Properties::West::LOW:
                                    return 17826;
                                case Properties::West::TALL:
                                    return 17827;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17828;
                                case Properties::West::LOW:
                                    return 17829;
                                case Properties::West::TALL:
                                    return 17830;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17831;
                                case Properties::West::LOW:
                                    return 17832;
                                case Properties::West::TALL:
                                    return 17833;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17834;
                                case Properties::West::LOW:
                                    return 17835;
                                case Properties::West::TALL:
                                    return 17836;
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
                                    return 17837;
                                case Properties::West::LOW:
                                    return 17838;
                                case Properties::West::TALL:
                                    return 17839;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17840;
                                case Properties::West::LOW:
                                    return 17841;
                                case Properties::West::TALL:
                                    return 17842;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17843;
                                case Properties::West::LOW:
                                    return 17844;
                                case Properties::West::TALL:
                                    return 17845;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17846;
                                case Properties::West::LOW:
                                    return 17847;
                                case Properties::West::TALL:
                                    return 17848;
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
                                    return 17849;
                                case Properties::West::LOW:
                                    return 17850;
                                case Properties::West::TALL:
                                    return 17851;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17852;
                                case Properties::West::LOW:
                                    return 17853;
                                case Properties::West::TALL:
                                    return 17854;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17855;
                                case Properties::West::LOW:
                                    return 17856;
                                case Properties::West::TALL:
                                    return 17857;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17858;
                                case Properties::West::LOW:
                                    return 17859;
                                case Properties::West::TALL:
                                    return 17860;
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
                                    return 17861;
                                case Properties::West::LOW:
                                    return 17862;
                                case Properties::West::TALL:
                                    return 17863;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17864;
                                case Properties::West::LOW:
                                    return 17865;
                                case Properties::West::TALL:
                                    return 17866;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17867;
                                case Properties::West::LOW:
                                    return 17868;
                                case Properties::West::TALL:
                                    return 17869;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17870;
                                case Properties::West::LOW:
                                    return 17871;
                                case Properties::West::TALL:
                                    return 17872;
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
