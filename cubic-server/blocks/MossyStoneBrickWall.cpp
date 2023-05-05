#include "MossyStoneBrickWall.hpp"
namespace Blocks {
    namespace MossyStoneBrickWall {
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
                                    return 14504;
                                case Properties::West::LOW:
                                    return 14505;
                                case Properties::West::TALL:
                                    return 14506;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14507;
                                case Properties::West::LOW:
                                    return 14508;
                                case Properties::West::TALL:
                                    return 14509;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14510;
                                case Properties::West::LOW:
                                    return 14511;
                                case Properties::West::TALL:
                                    return 14512;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14513;
                                case Properties::West::LOW:
                                    return 14514;
                                case Properties::West::TALL:
                                    return 14515;
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
                                    return 14516;
                                case Properties::West::LOW:
                                    return 14517;
                                case Properties::West::TALL:
                                    return 14518;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14519;
                                case Properties::West::LOW:
                                    return 14520;
                                case Properties::West::TALL:
                                    return 14521;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14522;
                                case Properties::West::LOW:
                                    return 14523;
                                case Properties::West::TALL:
                                    return 14524;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14525;
                                case Properties::West::LOW:
                                    return 14526;
                                case Properties::West::TALL:
                                    return 14527;
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
                                    return 14528;
                                case Properties::West::LOW:
                                    return 14529;
                                case Properties::West::TALL:
                                    return 14530;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14531;
                                case Properties::West::LOW:
                                    return 14532;
                                case Properties::West::TALL:
                                    return 14533;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14534;
                                case Properties::West::LOW:
                                    return 14535;
                                case Properties::West::TALL:
                                    return 14536;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14537;
                                case Properties::West::LOW:
                                    return 14538;
                                case Properties::West::TALL:
                                    return 14539;
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
                                    return 14540;
                                case Properties::West::LOW:
                                    return 14541;
                                case Properties::West::TALL:
                                    return 14542;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14543;
                                case Properties::West::LOW:
                                    return 14544;
                                case Properties::West::TALL:
                                    return 14545;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14546;
                                case Properties::West::LOW:
                                    return 14547;
                                case Properties::West::TALL:
                                    return 14548;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14549;
                                case Properties::West::LOW:
                                    return 14550;
                                case Properties::West::TALL:
                                    return 14551;
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
                                    return 14552;
                                case Properties::West::LOW:
                                    return 14553;
                                case Properties::West::TALL:
                                    return 14554;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14555;
                                case Properties::West::LOW:
                                    return 14556;
                                case Properties::West::TALL:
                                    return 14557;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14558;
                                case Properties::West::LOW:
                                    return 14559;
                                case Properties::West::TALL:
                                    return 14560;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14561;
                                case Properties::West::LOW:
                                    return 14562;
                                case Properties::West::TALL:
                                    return 14563;
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
                                    return 14564;
                                case Properties::West::LOW:
                                    return 14565;
                                case Properties::West::TALL:
                                    return 14566;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14567;
                                case Properties::West::LOW:
                                    return 14568;
                                case Properties::West::TALL:
                                    return 14569;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14570;
                                case Properties::West::LOW:
                                    return 14571;
                                case Properties::West::TALL:
                                    return 14572;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14573;
                                case Properties::West::LOW:
                                    return 14574;
                                case Properties::West::TALL:
                                    return 14575;
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
                                    return 14576;
                                case Properties::West::LOW:
                                    return 14577;
                                case Properties::West::TALL:
                                    return 14578;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14579;
                                case Properties::West::LOW:
                                    return 14580;
                                case Properties::West::TALL:
                                    return 14581;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14582;
                                case Properties::West::LOW:
                                    return 14583;
                                case Properties::West::TALL:
                                    return 14584;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14585;
                                case Properties::West::LOW:
                                    return 14586;
                                case Properties::West::TALL:
                                    return 14587;
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
                                    return 14588;
                                case Properties::West::LOW:
                                    return 14589;
                                case Properties::West::TALL:
                                    return 14590;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14591;
                                case Properties::West::LOW:
                                    return 14592;
                                case Properties::West::TALL:
                                    return 14593;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14594;
                                case Properties::West::LOW:
                                    return 14595;
                                case Properties::West::TALL:
                                    return 14596;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14597;
                                case Properties::West::LOW:
                                    return 14598;
                                case Properties::West::TALL:
                                    return 14599;
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
                                    return 14600;
                                case Properties::West::LOW:
                                    return 14601;
                                case Properties::West::TALL:
                                    return 14602;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14603;
                                case Properties::West::LOW:
                                    return 14604;
                                case Properties::West::TALL:
                                    return 14605;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14606;
                                case Properties::West::LOW:
                                    return 14607;
                                case Properties::West::TALL:
                                    return 14608;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14609;
                                case Properties::West::LOW:
                                    return 14610;
                                case Properties::West::TALL:
                                    return 14611;
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
                                    return 14612;
                                case Properties::West::LOW:
                                    return 14613;
                                case Properties::West::TALL:
                                    return 14614;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14615;
                                case Properties::West::LOW:
                                    return 14616;
                                case Properties::West::TALL:
                                    return 14617;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14618;
                                case Properties::West::LOW:
                                    return 14619;
                                case Properties::West::TALL:
                                    return 14620;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14621;
                                case Properties::West::LOW:
                                    return 14622;
                                case Properties::West::TALL:
                                    return 14623;
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
                                    return 14624;
                                case Properties::West::LOW:
                                    return 14625;
                                case Properties::West::TALL:
                                    return 14626;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14627;
                                case Properties::West::LOW:
                                    return 14628;
                                case Properties::West::TALL:
                                    return 14629;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14630;
                                case Properties::West::LOW:
                                    return 14631;
                                case Properties::West::TALL:
                                    return 14632;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14633;
                                case Properties::West::LOW:
                                    return 14634;
                                case Properties::West::TALL:
                                    return 14635;
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
                                    return 14636;
                                case Properties::West::LOW:
                                    return 14637;
                                case Properties::West::TALL:
                                    return 14638;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14639;
                                case Properties::West::LOW:
                                    return 14640;
                                case Properties::West::TALL:
                                    return 14641;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14642;
                                case Properties::West::LOW:
                                    return 14643;
                                case Properties::West::TALL:
                                    return 14644;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14645;
                                case Properties::West::LOW:
                                    return 14646;
                                case Properties::West::TALL:
                                    return 14647;
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
                                    return 14648;
                                case Properties::West::LOW:
                                    return 14649;
                                case Properties::West::TALL:
                                    return 14650;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14651;
                                case Properties::West::LOW:
                                    return 14652;
                                case Properties::West::TALL:
                                    return 14653;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14654;
                                case Properties::West::LOW:
                                    return 14655;
                                case Properties::West::TALL:
                                    return 14656;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14657;
                                case Properties::West::LOW:
                                    return 14658;
                                case Properties::West::TALL:
                                    return 14659;
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
                                    return 14660;
                                case Properties::West::LOW:
                                    return 14661;
                                case Properties::West::TALL:
                                    return 14662;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14663;
                                case Properties::West::LOW:
                                    return 14664;
                                case Properties::West::TALL:
                                    return 14665;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14666;
                                case Properties::West::LOW:
                                    return 14667;
                                case Properties::West::TALL:
                                    return 14668;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14669;
                                case Properties::West::LOW:
                                    return 14670;
                                case Properties::West::TALL:
                                    return 14671;
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
                                    return 14672;
                                case Properties::West::LOW:
                                    return 14673;
                                case Properties::West::TALL:
                                    return 14674;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14675;
                                case Properties::West::LOW:
                                    return 14676;
                                case Properties::West::TALL:
                                    return 14677;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14678;
                                case Properties::West::LOW:
                                    return 14679;
                                case Properties::West::TALL:
                                    return 14680;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14681;
                                case Properties::West::LOW:
                                    return 14682;
                                case Properties::West::TALL:
                                    return 14683;
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
                                    return 14684;
                                case Properties::West::LOW:
                                    return 14685;
                                case Properties::West::TALL:
                                    return 14686;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14687;
                                case Properties::West::LOW:
                                    return 14688;
                                case Properties::West::TALL:
                                    return 14689;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14690;
                                case Properties::West::LOW:
                                    return 14691;
                                case Properties::West::TALL:
                                    return 14692;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14693;
                                case Properties::West::LOW:
                                    return 14694;
                                case Properties::West::TALL:
                                    return 14695;
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
                                    return 14696;
                                case Properties::West::LOW:
                                    return 14697;
                                case Properties::West::TALL:
                                    return 14698;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14699;
                                case Properties::West::LOW:
                                    return 14700;
                                case Properties::West::TALL:
                                    return 14701;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14702;
                                case Properties::West::LOW:
                                    return 14703;
                                case Properties::West::TALL:
                                    return 14704;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14705;
                                case Properties::West::LOW:
                                    return 14706;
                                case Properties::West::TALL:
                                    return 14707;
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
                                    return 14708;
                                case Properties::West::LOW:
                                    return 14709;
                                case Properties::West::TALL:
                                    return 14710;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14711;
                                case Properties::West::LOW:
                                    return 14712;
                                case Properties::West::TALL:
                                    return 14713;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14714;
                                case Properties::West::LOW:
                                    return 14715;
                                case Properties::West::TALL:
                                    return 14716;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14717;
                                case Properties::West::LOW:
                                    return 14718;
                                case Properties::West::TALL:
                                    return 14719;
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
                                    return 14720;
                                case Properties::West::LOW:
                                    return 14721;
                                case Properties::West::TALL:
                                    return 14722;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14723;
                                case Properties::West::LOW:
                                    return 14724;
                                case Properties::West::TALL:
                                    return 14725;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14726;
                                case Properties::West::LOW:
                                    return 14727;
                                case Properties::West::TALL:
                                    return 14728;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14729;
                                case Properties::West::LOW:
                                    return 14730;
                                case Properties::West::TALL:
                                    return 14731;
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
                                    return 14732;
                                case Properties::West::LOW:
                                    return 14733;
                                case Properties::West::TALL:
                                    return 14734;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14735;
                                case Properties::West::LOW:
                                    return 14736;
                                case Properties::West::TALL:
                                    return 14737;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14738;
                                case Properties::West::LOW:
                                    return 14739;
                                case Properties::West::TALL:
                                    return 14740;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14741;
                                case Properties::West::LOW:
                                    return 14742;
                                case Properties::West::TALL:
                                    return 14743;
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
                                    return 14744;
                                case Properties::West::LOW:
                                    return 14745;
                                case Properties::West::TALL:
                                    return 14746;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14747;
                                case Properties::West::LOW:
                                    return 14748;
                                case Properties::West::TALL:
                                    return 14749;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14750;
                                case Properties::West::LOW:
                                    return 14751;
                                case Properties::West::TALL:
                                    return 14752;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14753;
                                case Properties::West::LOW:
                                    return 14754;
                                case Properties::West::TALL:
                                    return 14755;
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
                                    return 14756;
                                case Properties::West::LOW:
                                    return 14757;
                                case Properties::West::TALL:
                                    return 14758;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14759;
                                case Properties::West::LOW:
                                    return 14760;
                                case Properties::West::TALL:
                                    return 14761;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14762;
                                case Properties::West::LOW:
                                    return 14763;
                                case Properties::West::TALL:
                                    return 14764;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14765;
                                case Properties::West::LOW:
                                    return 14766;
                                case Properties::West::TALL:
                                    return 14767;
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
                                    return 14768;
                                case Properties::West::LOW:
                                    return 14769;
                                case Properties::West::TALL:
                                    return 14770;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14771;
                                case Properties::West::LOW:
                                    return 14772;
                                case Properties::West::TALL:
                                    return 14773;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14774;
                                case Properties::West::LOW:
                                    return 14775;
                                case Properties::West::TALL:
                                    return 14776;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14777;
                                case Properties::West::LOW:
                                    return 14778;
                                case Properties::West::TALL:
                                    return 14779;
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
                                    return 14780;
                                case Properties::West::LOW:
                                    return 14781;
                                case Properties::West::TALL:
                                    return 14782;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14783;
                                case Properties::West::LOW:
                                    return 14784;
                                case Properties::West::TALL:
                                    return 14785;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14786;
                                case Properties::West::LOW:
                                    return 14787;
                                case Properties::West::TALL:
                                    return 14788;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14789;
                                case Properties::West::LOW:
                                    return 14790;
                                case Properties::West::TALL:
                                    return 14791;
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
                                    return 14792;
                                case Properties::West::LOW:
                                    return 14793;
                                case Properties::West::TALL:
                                    return 14794;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14795;
                                case Properties::West::LOW:
                                    return 14796;
                                case Properties::West::TALL:
                                    return 14797;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14798;
                                case Properties::West::LOW:
                                    return 14799;
                                case Properties::West::TALL:
                                    return 14800;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14801;
                                case Properties::West::LOW:
                                    return 14802;
                                case Properties::West::TALL:
                                    return 14803;
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
                                    return 14804;
                                case Properties::West::LOW:
                                    return 14805;
                                case Properties::West::TALL:
                                    return 14806;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14807;
                                case Properties::West::LOW:
                                    return 14808;
                                case Properties::West::TALL:
                                    return 14809;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14810;
                                case Properties::West::LOW:
                                    return 14811;
                                case Properties::West::TALL:
                                    return 14812;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14813;
                                case Properties::West::LOW:
                                    return 14814;
                                case Properties::West::TALL:
                                    return 14815;
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
                                    return 14816;
                                case Properties::West::LOW:
                                    return 14817;
                                case Properties::West::TALL:
                                    return 14818;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14819;
                                case Properties::West::LOW:
                                    return 14820;
                                case Properties::West::TALL:
                                    return 14821;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14822;
                                case Properties::West::LOW:
                                    return 14823;
                                case Properties::West::TALL:
                                    return 14824;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14825;
                                case Properties::West::LOW:
                                    return 14826;
                                case Properties::West::TALL:
                                    return 14827;
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
