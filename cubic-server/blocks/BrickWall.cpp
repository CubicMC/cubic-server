#include "BrickWall.hpp"
namespace Blocks {
    namespace BrickWall {
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
                                    return 13532;
                                case Properties::West::LOW:
                                    return 13533;
                                case Properties::West::TALL:
                                    return 13534;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13535;
                                case Properties::West::LOW:
                                    return 13536;
                                case Properties::West::TALL:
                                    return 13537;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13538;
                                case Properties::West::LOW:
                                    return 13539;
                                case Properties::West::TALL:
                                    return 13540;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13541;
                                case Properties::West::LOW:
                                    return 13542;
                                case Properties::West::TALL:
                                    return 13543;
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
                                    return 13544;
                                case Properties::West::LOW:
                                    return 13545;
                                case Properties::West::TALL:
                                    return 13546;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13547;
                                case Properties::West::LOW:
                                    return 13548;
                                case Properties::West::TALL:
                                    return 13549;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13550;
                                case Properties::West::LOW:
                                    return 13551;
                                case Properties::West::TALL:
                                    return 13552;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13553;
                                case Properties::West::LOW:
                                    return 13554;
                                case Properties::West::TALL:
                                    return 13555;
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
                                    return 13556;
                                case Properties::West::LOW:
                                    return 13557;
                                case Properties::West::TALL:
                                    return 13558;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13559;
                                case Properties::West::LOW:
                                    return 13560;
                                case Properties::West::TALL:
                                    return 13561;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13562;
                                case Properties::West::LOW:
                                    return 13563;
                                case Properties::West::TALL:
                                    return 13564;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13565;
                                case Properties::West::LOW:
                                    return 13566;
                                case Properties::West::TALL:
                                    return 13567;
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
                                    return 13568;
                                case Properties::West::LOW:
                                    return 13569;
                                case Properties::West::TALL:
                                    return 13570;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13571;
                                case Properties::West::LOW:
                                    return 13572;
                                case Properties::West::TALL:
                                    return 13573;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13574;
                                case Properties::West::LOW:
                                    return 13575;
                                case Properties::West::TALL:
                                    return 13576;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13577;
                                case Properties::West::LOW:
                                    return 13578;
                                case Properties::West::TALL:
                                    return 13579;
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
                                    return 13580;
                                case Properties::West::LOW:
                                    return 13581;
                                case Properties::West::TALL:
                                    return 13582;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13583;
                                case Properties::West::LOW:
                                    return 13584;
                                case Properties::West::TALL:
                                    return 13585;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13586;
                                case Properties::West::LOW:
                                    return 13587;
                                case Properties::West::TALL:
                                    return 13588;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13589;
                                case Properties::West::LOW:
                                    return 13590;
                                case Properties::West::TALL:
                                    return 13591;
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
                                    return 13592;
                                case Properties::West::LOW:
                                    return 13593;
                                case Properties::West::TALL:
                                    return 13594;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13595;
                                case Properties::West::LOW:
                                    return 13596;
                                case Properties::West::TALL:
                                    return 13597;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13598;
                                case Properties::West::LOW:
                                    return 13599;
                                case Properties::West::TALL:
                                    return 13600;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13601;
                                case Properties::West::LOW:
                                    return 13602;
                                case Properties::West::TALL:
                                    return 13603;
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
                                    return 13604;
                                case Properties::West::LOW:
                                    return 13605;
                                case Properties::West::TALL:
                                    return 13606;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13607;
                                case Properties::West::LOW:
                                    return 13608;
                                case Properties::West::TALL:
                                    return 13609;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13610;
                                case Properties::West::LOW:
                                    return 13611;
                                case Properties::West::TALL:
                                    return 13612;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13613;
                                case Properties::West::LOW:
                                    return 13614;
                                case Properties::West::TALL:
                                    return 13615;
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
                                    return 13616;
                                case Properties::West::LOW:
                                    return 13617;
                                case Properties::West::TALL:
                                    return 13618;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13619;
                                case Properties::West::LOW:
                                    return 13620;
                                case Properties::West::TALL:
                                    return 13621;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13622;
                                case Properties::West::LOW:
                                    return 13623;
                                case Properties::West::TALL:
                                    return 13624;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13625;
                                case Properties::West::LOW:
                                    return 13626;
                                case Properties::West::TALL:
                                    return 13627;
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
                                    return 13628;
                                case Properties::West::LOW:
                                    return 13629;
                                case Properties::West::TALL:
                                    return 13630;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13631;
                                case Properties::West::LOW:
                                    return 13632;
                                case Properties::West::TALL:
                                    return 13633;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13634;
                                case Properties::West::LOW:
                                    return 13635;
                                case Properties::West::TALL:
                                    return 13636;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13637;
                                case Properties::West::LOW:
                                    return 13638;
                                case Properties::West::TALL:
                                    return 13639;
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
                                    return 13640;
                                case Properties::West::LOW:
                                    return 13641;
                                case Properties::West::TALL:
                                    return 13642;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13643;
                                case Properties::West::LOW:
                                    return 13644;
                                case Properties::West::TALL:
                                    return 13645;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13646;
                                case Properties::West::LOW:
                                    return 13647;
                                case Properties::West::TALL:
                                    return 13648;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13649;
                                case Properties::West::LOW:
                                    return 13650;
                                case Properties::West::TALL:
                                    return 13651;
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
                                    return 13652;
                                case Properties::West::LOW:
                                    return 13653;
                                case Properties::West::TALL:
                                    return 13654;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13655;
                                case Properties::West::LOW:
                                    return 13656;
                                case Properties::West::TALL:
                                    return 13657;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13658;
                                case Properties::West::LOW:
                                    return 13659;
                                case Properties::West::TALL:
                                    return 13660;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13661;
                                case Properties::West::LOW:
                                    return 13662;
                                case Properties::West::TALL:
                                    return 13663;
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
                                    return 13664;
                                case Properties::West::LOW:
                                    return 13665;
                                case Properties::West::TALL:
                                    return 13666;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13667;
                                case Properties::West::LOW:
                                    return 13668;
                                case Properties::West::TALL:
                                    return 13669;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13670;
                                case Properties::West::LOW:
                                    return 13671;
                                case Properties::West::TALL:
                                    return 13672;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13673;
                                case Properties::West::LOW:
                                    return 13674;
                                case Properties::West::TALL:
                                    return 13675;
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
                                    return 13676;
                                case Properties::West::LOW:
                                    return 13677;
                                case Properties::West::TALL:
                                    return 13678;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13679;
                                case Properties::West::LOW:
                                    return 13680;
                                case Properties::West::TALL:
                                    return 13681;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13682;
                                case Properties::West::LOW:
                                    return 13683;
                                case Properties::West::TALL:
                                    return 13684;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13685;
                                case Properties::West::LOW:
                                    return 13686;
                                case Properties::West::TALL:
                                    return 13687;
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
                                    return 13688;
                                case Properties::West::LOW:
                                    return 13689;
                                case Properties::West::TALL:
                                    return 13690;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13691;
                                case Properties::West::LOW:
                                    return 13692;
                                case Properties::West::TALL:
                                    return 13693;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13694;
                                case Properties::West::LOW:
                                    return 13695;
                                case Properties::West::TALL:
                                    return 13696;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13697;
                                case Properties::West::LOW:
                                    return 13698;
                                case Properties::West::TALL:
                                    return 13699;
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
                                    return 13700;
                                case Properties::West::LOW:
                                    return 13701;
                                case Properties::West::TALL:
                                    return 13702;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13703;
                                case Properties::West::LOW:
                                    return 13704;
                                case Properties::West::TALL:
                                    return 13705;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13706;
                                case Properties::West::LOW:
                                    return 13707;
                                case Properties::West::TALL:
                                    return 13708;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13709;
                                case Properties::West::LOW:
                                    return 13710;
                                case Properties::West::TALL:
                                    return 13711;
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
                                    return 13712;
                                case Properties::West::LOW:
                                    return 13713;
                                case Properties::West::TALL:
                                    return 13714;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13715;
                                case Properties::West::LOW:
                                    return 13716;
                                case Properties::West::TALL:
                                    return 13717;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13718;
                                case Properties::West::LOW:
                                    return 13719;
                                case Properties::West::TALL:
                                    return 13720;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13721;
                                case Properties::West::LOW:
                                    return 13722;
                                case Properties::West::TALL:
                                    return 13723;
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
                                    return 13724;
                                case Properties::West::LOW:
                                    return 13725;
                                case Properties::West::TALL:
                                    return 13726;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13727;
                                case Properties::West::LOW:
                                    return 13728;
                                case Properties::West::TALL:
                                    return 13729;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13730;
                                case Properties::West::LOW:
                                    return 13731;
                                case Properties::West::TALL:
                                    return 13732;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13733;
                                case Properties::West::LOW:
                                    return 13734;
                                case Properties::West::TALL:
                                    return 13735;
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
                                    return 13736;
                                case Properties::West::LOW:
                                    return 13737;
                                case Properties::West::TALL:
                                    return 13738;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13739;
                                case Properties::West::LOW:
                                    return 13740;
                                case Properties::West::TALL:
                                    return 13741;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13742;
                                case Properties::West::LOW:
                                    return 13743;
                                case Properties::West::TALL:
                                    return 13744;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13745;
                                case Properties::West::LOW:
                                    return 13746;
                                case Properties::West::TALL:
                                    return 13747;
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
                                    return 13748;
                                case Properties::West::LOW:
                                    return 13749;
                                case Properties::West::TALL:
                                    return 13750;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13751;
                                case Properties::West::LOW:
                                    return 13752;
                                case Properties::West::TALL:
                                    return 13753;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13754;
                                case Properties::West::LOW:
                                    return 13755;
                                case Properties::West::TALL:
                                    return 13756;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13757;
                                case Properties::West::LOW:
                                    return 13758;
                                case Properties::West::TALL:
                                    return 13759;
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
                                    return 13760;
                                case Properties::West::LOW:
                                    return 13761;
                                case Properties::West::TALL:
                                    return 13762;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13763;
                                case Properties::West::LOW:
                                    return 13764;
                                case Properties::West::TALL:
                                    return 13765;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13766;
                                case Properties::West::LOW:
                                    return 13767;
                                case Properties::West::TALL:
                                    return 13768;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13769;
                                case Properties::West::LOW:
                                    return 13770;
                                case Properties::West::TALL:
                                    return 13771;
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
                                    return 13772;
                                case Properties::West::LOW:
                                    return 13773;
                                case Properties::West::TALL:
                                    return 13774;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13775;
                                case Properties::West::LOW:
                                    return 13776;
                                case Properties::West::TALL:
                                    return 13777;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13778;
                                case Properties::West::LOW:
                                    return 13779;
                                case Properties::West::TALL:
                                    return 13780;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13781;
                                case Properties::West::LOW:
                                    return 13782;
                                case Properties::West::TALL:
                                    return 13783;
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
                                    return 13784;
                                case Properties::West::LOW:
                                    return 13785;
                                case Properties::West::TALL:
                                    return 13786;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13787;
                                case Properties::West::LOW:
                                    return 13788;
                                case Properties::West::TALL:
                                    return 13789;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13790;
                                case Properties::West::LOW:
                                    return 13791;
                                case Properties::West::TALL:
                                    return 13792;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13793;
                                case Properties::West::LOW:
                                    return 13794;
                                case Properties::West::TALL:
                                    return 13795;
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
                                    return 13796;
                                case Properties::West::LOW:
                                    return 13797;
                                case Properties::West::TALL:
                                    return 13798;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13799;
                                case Properties::West::LOW:
                                    return 13800;
                                case Properties::West::TALL:
                                    return 13801;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13802;
                                case Properties::West::LOW:
                                    return 13803;
                                case Properties::West::TALL:
                                    return 13804;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13805;
                                case Properties::West::LOW:
                                    return 13806;
                                case Properties::West::TALL:
                                    return 13807;
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
                                    return 13808;
                                case Properties::West::LOW:
                                    return 13809;
                                case Properties::West::TALL:
                                    return 13810;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13811;
                                case Properties::West::LOW:
                                    return 13812;
                                case Properties::West::TALL:
                                    return 13813;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13814;
                                case Properties::West::LOW:
                                    return 13815;
                                case Properties::West::TALL:
                                    return 13816;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13817;
                                case Properties::West::LOW:
                                    return 13818;
                                case Properties::West::TALL:
                                    return 13819;
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
                                    return 13820;
                                case Properties::West::LOW:
                                    return 13821;
                                case Properties::West::TALL:
                                    return 13822;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13823;
                                case Properties::West::LOW:
                                    return 13824;
                                case Properties::West::TALL:
                                    return 13825;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13826;
                                case Properties::West::LOW:
                                    return 13827;
                                case Properties::West::TALL:
                                    return 13828;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13829;
                                case Properties::West::LOW:
                                    return 13830;
                                case Properties::West::TALL:
                                    return 13831;
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
                                    return 13832;
                                case Properties::West::LOW:
                                    return 13833;
                                case Properties::West::TALL:
                                    return 13834;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13835;
                                case Properties::West::LOW:
                                    return 13836;
                                case Properties::West::TALL:
                                    return 13837;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13838;
                                case Properties::West::LOW:
                                    return 13839;
                                case Properties::West::TALL:
                                    return 13840;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13841;
                                case Properties::West::LOW:
                                    return 13842;
                                case Properties::West::TALL:
                                    return 13843;
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
                                    return 13844;
                                case Properties::West::LOW:
                                    return 13845;
                                case Properties::West::TALL:
                                    return 13846;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13847;
                                case Properties::West::LOW:
                                    return 13848;
                                case Properties::West::TALL:
                                    return 13849;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13850;
                                case Properties::West::LOW:
                                    return 13851;
                                case Properties::West::TALL:
                                    return 13852;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13853;
                                case Properties::West::LOW:
                                    return 13854;
                                case Properties::West::TALL:
                                    return 13855;
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
