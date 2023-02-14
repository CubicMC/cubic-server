#include "DioriteWall.hpp"
#include <stdexcept>

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
                                    return 15636;
                                case Properties::West::LOW:
                                    return 15637;
                                case Properties::West::TALL:
                                    return 15638;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15639;
                                case Properties::West::LOW:
                                    return 15640;
                                case Properties::West::TALL:
                                    return 15641;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15642;
                                case Properties::West::LOW:
                                    return 15643;
                                case Properties::West::TALL:
                                    return 15644;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15645;
                                case Properties::West::LOW:
                                    return 15646;
                                case Properties::West::TALL:
                                    return 15647;
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
                                    return 15648;
                                case Properties::West::LOW:
                                    return 15649;
                                case Properties::West::TALL:
                                    return 15650;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15651;
                                case Properties::West::LOW:
                                    return 15652;
                                case Properties::West::TALL:
                                    return 15653;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15654;
                                case Properties::West::LOW:
                                    return 15655;
                                case Properties::West::TALL:
                                    return 15656;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15657;
                                case Properties::West::LOW:
                                    return 15658;
                                case Properties::West::TALL:
                                    return 15659;
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
                                    return 15660;
                                case Properties::West::LOW:
                                    return 15661;
                                case Properties::West::TALL:
                                    return 15662;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15663;
                                case Properties::West::LOW:
                                    return 15664;
                                case Properties::West::TALL:
                                    return 15665;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15666;
                                case Properties::West::LOW:
                                    return 15667;
                                case Properties::West::TALL:
                                    return 15668;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15669;
                                case Properties::West::LOW:
                                    return 15670;
                                case Properties::West::TALL:
                                    return 15671;
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
                                    return 15672;
                                case Properties::West::LOW:
                                    return 15673;
                                case Properties::West::TALL:
                                    return 15674;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15675;
                                case Properties::West::LOW:
                                    return 15676;
                                case Properties::West::TALL:
                                    return 15677;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15678;
                                case Properties::West::LOW:
                                    return 15679;
                                case Properties::West::TALL:
                                    return 15680;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15681;
                                case Properties::West::LOW:
                                    return 15682;
                                case Properties::West::TALL:
                                    return 15683;
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
                                    return 15684;
                                case Properties::West::LOW:
                                    return 15685;
                                case Properties::West::TALL:
                                    return 15686;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15687;
                                case Properties::West::LOW:
                                    return 15688;
                                case Properties::West::TALL:
                                    return 15689;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15690;
                                case Properties::West::LOW:
                                    return 15691;
                                case Properties::West::TALL:
                                    return 15692;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15693;
                                case Properties::West::LOW:
                                    return 15694;
                                case Properties::West::TALL:
                                    return 15695;
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
                                    return 15696;
                                case Properties::West::LOW:
                                    return 15697;
                                case Properties::West::TALL:
                                    return 15698;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15699;
                                case Properties::West::LOW:
                                    return 15700;
                                case Properties::West::TALL:
                                    return 15701;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15702;
                                case Properties::West::LOW:
                                    return 15703;
                                case Properties::West::TALL:
                                    return 15704;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15705;
                                case Properties::West::LOW:
                                    return 15706;
                                case Properties::West::TALL:
                                    return 15707;
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
                                    return 15708;
                                case Properties::West::LOW:
                                    return 15709;
                                case Properties::West::TALL:
                                    return 15710;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15711;
                                case Properties::West::LOW:
                                    return 15712;
                                case Properties::West::TALL:
                                    return 15713;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15714;
                                case Properties::West::LOW:
                                    return 15715;
                                case Properties::West::TALL:
                                    return 15716;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15717;
                                case Properties::West::LOW:
                                    return 15718;
                                case Properties::West::TALL:
                                    return 15719;
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
                                    return 15720;
                                case Properties::West::LOW:
                                    return 15721;
                                case Properties::West::TALL:
                                    return 15722;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15723;
                                case Properties::West::LOW:
                                    return 15724;
                                case Properties::West::TALL:
                                    return 15725;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15726;
                                case Properties::West::LOW:
                                    return 15727;
                                case Properties::West::TALL:
                                    return 15728;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15729;
                                case Properties::West::LOW:
                                    return 15730;
                                case Properties::West::TALL:
                                    return 15731;
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
                                    return 15732;
                                case Properties::West::LOW:
                                    return 15733;
                                case Properties::West::TALL:
                                    return 15734;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15735;
                                case Properties::West::LOW:
                                    return 15736;
                                case Properties::West::TALL:
                                    return 15737;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15738;
                                case Properties::West::LOW:
                                    return 15739;
                                case Properties::West::TALL:
                                    return 15740;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15741;
                                case Properties::West::LOW:
                                    return 15742;
                                case Properties::West::TALL:
                                    return 15743;
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
                                    return 15744;
                                case Properties::West::LOW:
                                    return 15745;
                                case Properties::West::TALL:
                                    return 15746;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15747;
                                case Properties::West::LOW:
                                    return 15748;
                                case Properties::West::TALL:
                                    return 15749;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15750;
                                case Properties::West::LOW:
                                    return 15751;
                                case Properties::West::TALL:
                                    return 15752;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15753;
                                case Properties::West::LOW:
                                    return 15754;
                                case Properties::West::TALL:
                                    return 15755;
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
                                    return 15756;
                                case Properties::West::LOW:
                                    return 15757;
                                case Properties::West::TALL:
                                    return 15758;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15759;
                                case Properties::West::LOW:
                                    return 15760;
                                case Properties::West::TALL:
                                    return 15761;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15762;
                                case Properties::West::LOW:
                                    return 15763;
                                case Properties::West::TALL:
                                    return 15764;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15765;
                                case Properties::West::LOW:
                                    return 15766;
                                case Properties::West::TALL:
                                    return 15767;
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
                                    return 15768;
                                case Properties::West::LOW:
                                    return 15769;
                                case Properties::West::TALL:
                                    return 15770;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15771;
                                case Properties::West::LOW:
                                    return 15772;
                                case Properties::West::TALL:
                                    return 15773;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15774;
                                case Properties::West::LOW:
                                    return 15775;
                                case Properties::West::TALL:
                                    return 15776;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15777;
                                case Properties::West::LOW:
                                    return 15778;
                                case Properties::West::TALL:
                                    return 15779;
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
                                    return 15780;
                                case Properties::West::LOW:
                                    return 15781;
                                case Properties::West::TALL:
                                    return 15782;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15783;
                                case Properties::West::LOW:
                                    return 15784;
                                case Properties::West::TALL:
                                    return 15785;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15786;
                                case Properties::West::LOW:
                                    return 15787;
                                case Properties::West::TALL:
                                    return 15788;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15789;
                                case Properties::West::LOW:
                                    return 15790;
                                case Properties::West::TALL:
                                    return 15791;
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
                                    return 15792;
                                case Properties::West::LOW:
                                    return 15793;
                                case Properties::West::TALL:
                                    return 15794;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15795;
                                case Properties::West::LOW:
                                    return 15796;
                                case Properties::West::TALL:
                                    return 15797;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15798;
                                case Properties::West::LOW:
                                    return 15799;
                                case Properties::West::TALL:
                                    return 15800;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15801;
                                case Properties::West::LOW:
                                    return 15802;
                                case Properties::West::TALL:
                                    return 15803;
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
                                    return 15804;
                                case Properties::West::LOW:
                                    return 15805;
                                case Properties::West::TALL:
                                    return 15806;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15807;
                                case Properties::West::LOW:
                                    return 15808;
                                case Properties::West::TALL:
                                    return 15809;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15810;
                                case Properties::West::LOW:
                                    return 15811;
                                case Properties::West::TALL:
                                    return 15812;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15813;
                                case Properties::West::LOW:
                                    return 15814;
                                case Properties::West::TALL:
                                    return 15815;
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
                                    return 15816;
                                case Properties::West::LOW:
                                    return 15817;
                                case Properties::West::TALL:
                                    return 15818;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15819;
                                case Properties::West::LOW:
                                    return 15820;
                                case Properties::West::TALL:
                                    return 15821;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15822;
                                case Properties::West::LOW:
                                    return 15823;
                                case Properties::West::TALL:
                                    return 15824;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15825;
                                case Properties::West::LOW:
                                    return 15826;
                                case Properties::West::TALL:
                                    return 15827;
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
                                    return 15828;
                                case Properties::West::LOW:
                                    return 15829;
                                case Properties::West::TALL:
                                    return 15830;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15831;
                                case Properties::West::LOW:
                                    return 15832;
                                case Properties::West::TALL:
                                    return 15833;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15834;
                                case Properties::West::LOW:
                                    return 15835;
                                case Properties::West::TALL:
                                    return 15836;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15837;
                                case Properties::West::LOW:
                                    return 15838;
                                case Properties::West::TALL:
                                    return 15839;
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
                                    return 15840;
                                case Properties::West::LOW:
                                    return 15841;
                                case Properties::West::TALL:
                                    return 15842;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15843;
                                case Properties::West::LOW:
                                    return 15844;
                                case Properties::West::TALL:
                                    return 15845;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15846;
                                case Properties::West::LOW:
                                    return 15847;
                                case Properties::West::TALL:
                                    return 15848;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15849;
                                case Properties::West::LOW:
                                    return 15850;
                                case Properties::West::TALL:
                                    return 15851;
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
                                    return 15852;
                                case Properties::West::LOW:
                                    return 15853;
                                case Properties::West::TALL:
                                    return 15854;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15855;
                                case Properties::West::LOW:
                                    return 15856;
                                case Properties::West::TALL:
                                    return 15857;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15858;
                                case Properties::West::LOW:
                                    return 15859;
                                case Properties::West::TALL:
                                    return 15860;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15861;
                                case Properties::West::LOW:
                                    return 15862;
                                case Properties::West::TALL:
                                    return 15863;
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
                                    return 15864;
                                case Properties::West::LOW:
                                    return 15865;
                                case Properties::West::TALL:
                                    return 15866;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15867;
                                case Properties::West::LOW:
                                    return 15868;
                                case Properties::West::TALL:
                                    return 15869;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15870;
                                case Properties::West::LOW:
                                    return 15871;
                                case Properties::West::TALL:
                                    return 15872;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15873;
                                case Properties::West::LOW:
                                    return 15874;
                                case Properties::West::TALL:
                                    return 15875;
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
                                    return 15876;
                                case Properties::West::LOW:
                                    return 15877;
                                case Properties::West::TALL:
                                    return 15878;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15879;
                                case Properties::West::LOW:
                                    return 15880;
                                case Properties::West::TALL:
                                    return 15881;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15882;
                                case Properties::West::LOW:
                                    return 15883;
                                case Properties::West::TALL:
                                    return 15884;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15885;
                                case Properties::West::LOW:
                                    return 15886;
                                case Properties::West::TALL:
                                    return 15887;
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
                                    return 15888;
                                case Properties::West::LOW:
                                    return 15889;
                                case Properties::West::TALL:
                                    return 15890;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15891;
                                case Properties::West::LOW:
                                    return 15892;
                                case Properties::West::TALL:
                                    return 15893;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15894;
                                case Properties::West::LOW:
                                    return 15895;
                                case Properties::West::TALL:
                                    return 15896;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15897;
                                case Properties::West::LOW:
                                    return 15898;
                                case Properties::West::TALL:
                                    return 15899;
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
                                    return 15900;
                                case Properties::West::LOW:
                                    return 15901;
                                case Properties::West::TALL:
                                    return 15902;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15903;
                                case Properties::West::LOW:
                                    return 15904;
                                case Properties::West::TALL:
                                    return 15905;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15906;
                                case Properties::West::LOW:
                                    return 15907;
                                case Properties::West::TALL:
                                    return 15908;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15909;
                                case Properties::West::LOW:
                                    return 15910;
                                case Properties::West::TALL:
                                    return 15911;
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
                                    return 15912;
                                case Properties::West::LOW:
                                    return 15913;
                                case Properties::West::TALL:
                                    return 15914;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15915;
                                case Properties::West::LOW:
                                    return 15916;
                                case Properties::West::TALL:
                                    return 15917;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15918;
                                case Properties::West::LOW:
                                    return 15919;
                                case Properties::West::TALL:
                                    return 15920;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15921;
                                case Properties::West::LOW:
                                    return 15922;
                                case Properties::West::TALL:
                                    return 15923;
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
                                    return 15924;
                                case Properties::West::LOW:
                                    return 15925;
                                case Properties::West::TALL:
                                    return 15926;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15927;
                                case Properties::West::LOW:
                                    return 15928;
                                case Properties::West::TALL:
                                    return 15929;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15930;
                                case Properties::West::LOW:
                                    return 15931;
                                case Properties::West::TALL:
                                    return 15932;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15933;
                                case Properties::West::LOW:
                                    return 15934;
                                case Properties::West::TALL:
                                    return 15935;
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
                                    return 15936;
                                case Properties::West::LOW:
                                    return 15937;
                                case Properties::West::TALL:
                                    return 15938;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15939;
                                case Properties::West::LOW:
                                    return 15940;
                                case Properties::West::TALL:
                                    return 15941;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15942;
                                case Properties::West::LOW:
                                    return 15943;
                                case Properties::West::TALL:
                                    return 15944;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15945;
                                case Properties::West::LOW:
                                    return 15946;
                                case Properties::West::TALL:
                                    return 15947;
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
                                    return 15948;
                                case Properties::West::LOW:
                                    return 15949;
                                case Properties::West::TALL:
                                    return 15950;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15951;
                                case Properties::West::LOW:
                                    return 15952;
                                case Properties::West::TALL:
                                    return 15953;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15954;
                                case Properties::West::LOW:
                                    return 15955;
                                case Properties::West::TALL:
                                    return 15956;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 15957;
                                case Properties::West::LOW:
                                    return 15958;
                                case Properties::West::TALL:
                                    return 15959;
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
