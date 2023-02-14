#include "MossyCobblestoneWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MossyCobblestoneWall {
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
                                    return 6573;
                                case Properties::West::LOW:
                                    return 6574;
                                case Properties::West::TALL:
                                    return 6575;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6576;
                                case Properties::West::LOW:
                                    return 6577;
                                case Properties::West::TALL:
                                    return 6578;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6579;
                                case Properties::West::LOW:
                                    return 6580;
                                case Properties::West::TALL:
                                    return 6581;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6582;
                                case Properties::West::LOW:
                                    return 6583;
                                case Properties::West::TALL:
                                    return 6584;
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
                                    return 6585;
                                case Properties::West::LOW:
                                    return 6586;
                                case Properties::West::TALL:
                                    return 6587;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6588;
                                case Properties::West::LOW:
                                    return 6589;
                                case Properties::West::TALL:
                                    return 6590;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6591;
                                case Properties::West::LOW:
                                    return 6592;
                                case Properties::West::TALL:
                                    return 6593;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6594;
                                case Properties::West::LOW:
                                    return 6595;
                                case Properties::West::TALL:
                                    return 6596;
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
                                    return 6597;
                                case Properties::West::LOW:
                                    return 6598;
                                case Properties::West::TALL:
                                    return 6599;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6600;
                                case Properties::West::LOW:
                                    return 6601;
                                case Properties::West::TALL:
                                    return 6602;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6603;
                                case Properties::West::LOW:
                                    return 6604;
                                case Properties::West::TALL:
                                    return 6605;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6606;
                                case Properties::West::LOW:
                                    return 6607;
                                case Properties::West::TALL:
                                    return 6608;
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
                                    return 6609;
                                case Properties::West::LOW:
                                    return 6610;
                                case Properties::West::TALL:
                                    return 6611;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6612;
                                case Properties::West::LOW:
                                    return 6613;
                                case Properties::West::TALL:
                                    return 6614;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6615;
                                case Properties::West::LOW:
                                    return 6616;
                                case Properties::West::TALL:
                                    return 6617;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6618;
                                case Properties::West::LOW:
                                    return 6619;
                                case Properties::West::TALL:
                                    return 6620;
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
                                    return 6621;
                                case Properties::West::LOW:
                                    return 6622;
                                case Properties::West::TALL:
                                    return 6623;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6624;
                                case Properties::West::LOW:
                                    return 6625;
                                case Properties::West::TALL:
                                    return 6626;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6627;
                                case Properties::West::LOW:
                                    return 6628;
                                case Properties::West::TALL:
                                    return 6629;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6630;
                                case Properties::West::LOW:
                                    return 6631;
                                case Properties::West::TALL:
                                    return 6632;
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
                                    return 6633;
                                case Properties::West::LOW:
                                    return 6634;
                                case Properties::West::TALL:
                                    return 6635;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6636;
                                case Properties::West::LOW:
                                    return 6637;
                                case Properties::West::TALL:
                                    return 6638;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6639;
                                case Properties::West::LOW:
                                    return 6640;
                                case Properties::West::TALL:
                                    return 6641;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6642;
                                case Properties::West::LOW:
                                    return 6643;
                                case Properties::West::TALL:
                                    return 6644;
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
                                    return 6645;
                                case Properties::West::LOW:
                                    return 6646;
                                case Properties::West::TALL:
                                    return 6647;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6648;
                                case Properties::West::LOW:
                                    return 6649;
                                case Properties::West::TALL:
                                    return 6650;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6651;
                                case Properties::West::LOW:
                                    return 6652;
                                case Properties::West::TALL:
                                    return 6653;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6654;
                                case Properties::West::LOW:
                                    return 6655;
                                case Properties::West::TALL:
                                    return 6656;
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
                                    return 6657;
                                case Properties::West::LOW:
                                    return 6658;
                                case Properties::West::TALL:
                                    return 6659;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6660;
                                case Properties::West::LOW:
                                    return 6661;
                                case Properties::West::TALL:
                                    return 6662;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6663;
                                case Properties::West::LOW:
                                    return 6664;
                                case Properties::West::TALL:
                                    return 6665;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6666;
                                case Properties::West::LOW:
                                    return 6667;
                                case Properties::West::TALL:
                                    return 6668;
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
                                    return 6669;
                                case Properties::West::LOW:
                                    return 6670;
                                case Properties::West::TALL:
                                    return 6671;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6672;
                                case Properties::West::LOW:
                                    return 6673;
                                case Properties::West::TALL:
                                    return 6674;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6675;
                                case Properties::West::LOW:
                                    return 6676;
                                case Properties::West::TALL:
                                    return 6677;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6678;
                                case Properties::West::LOW:
                                    return 6679;
                                case Properties::West::TALL:
                                    return 6680;
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
                                    return 6681;
                                case Properties::West::LOW:
                                    return 6682;
                                case Properties::West::TALL:
                                    return 6683;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6684;
                                case Properties::West::LOW:
                                    return 6685;
                                case Properties::West::TALL:
                                    return 6686;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6687;
                                case Properties::West::LOW:
                                    return 6688;
                                case Properties::West::TALL:
                                    return 6689;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6690;
                                case Properties::West::LOW:
                                    return 6691;
                                case Properties::West::TALL:
                                    return 6692;
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
                                    return 6693;
                                case Properties::West::LOW:
                                    return 6694;
                                case Properties::West::TALL:
                                    return 6695;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6696;
                                case Properties::West::LOW:
                                    return 6697;
                                case Properties::West::TALL:
                                    return 6698;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6699;
                                case Properties::West::LOW:
                                    return 6700;
                                case Properties::West::TALL:
                                    return 6701;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6702;
                                case Properties::West::LOW:
                                    return 6703;
                                case Properties::West::TALL:
                                    return 6704;
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
                                    return 6705;
                                case Properties::West::LOW:
                                    return 6706;
                                case Properties::West::TALL:
                                    return 6707;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6708;
                                case Properties::West::LOW:
                                    return 6709;
                                case Properties::West::TALL:
                                    return 6710;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6711;
                                case Properties::West::LOW:
                                    return 6712;
                                case Properties::West::TALL:
                                    return 6713;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6714;
                                case Properties::West::LOW:
                                    return 6715;
                                case Properties::West::TALL:
                                    return 6716;
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
                                    return 6717;
                                case Properties::West::LOW:
                                    return 6718;
                                case Properties::West::TALL:
                                    return 6719;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6720;
                                case Properties::West::LOW:
                                    return 6721;
                                case Properties::West::TALL:
                                    return 6722;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6723;
                                case Properties::West::LOW:
                                    return 6724;
                                case Properties::West::TALL:
                                    return 6725;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6726;
                                case Properties::West::LOW:
                                    return 6727;
                                case Properties::West::TALL:
                                    return 6728;
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
                                    return 6729;
                                case Properties::West::LOW:
                                    return 6730;
                                case Properties::West::TALL:
                                    return 6731;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6732;
                                case Properties::West::LOW:
                                    return 6733;
                                case Properties::West::TALL:
                                    return 6734;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6735;
                                case Properties::West::LOW:
                                    return 6736;
                                case Properties::West::TALL:
                                    return 6737;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6738;
                                case Properties::West::LOW:
                                    return 6739;
                                case Properties::West::TALL:
                                    return 6740;
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
                                    return 6741;
                                case Properties::West::LOW:
                                    return 6742;
                                case Properties::West::TALL:
                                    return 6743;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6744;
                                case Properties::West::LOW:
                                    return 6745;
                                case Properties::West::TALL:
                                    return 6746;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6747;
                                case Properties::West::LOW:
                                    return 6748;
                                case Properties::West::TALL:
                                    return 6749;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6750;
                                case Properties::West::LOW:
                                    return 6751;
                                case Properties::West::TALL:
                                    return 6752;
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
                                    return 6753;
                                case Properties::West::LOW:
                                    return 6754;
                                case Properties::West::TALL:
                                    return 6755;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6756;
                                case Properties::West::LOW:
                                    return 6757;
                                case Properties::West::TALL:
                                    return 6758;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6759;
                                case Properties::West::LOW:
                                    return 6760;
                                case Properties::West::TALL:
                                    return 6761;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6762;
                                case Properties::West::LOW:
                                    return 6763;
                                case Properties::West::TALL:
                                    return 6764;
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
                                    return 6765;
                                case Properties::West::LOW:
                                    return 6766;
                                case Properties::West::TALL:
                                    return 6767;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6768;
                                case Properties::West::LOW:
                                    return 6769;
                                case Properties::West::TALL:
                                    return 6770;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6771;
                                case Properties::West::LOW:
                                    return 6772;
                                case Properties::West::TALL:
                                    return 6773;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6774;
                                case Properties::West::LOW:
                                    return 6775;
                                case Properties::West::TALL:
                                    return 6776;
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
                                    return 6777;
                                case Properties::West::LOW:
                                    return 6778;
                                case Properties::West::TALL:
                                    return 6779;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6780;
                                case Properties::West::LOW:
                                    return 6781;
                                case Properties::West::TALL:
                                    return 6782;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6783;
                                case Properties::West::LOW:
                                    return 6784;
                                case Properties::West::TALL:
                                    return 6785;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6786;
                                case Properties::West::LOW:
                                    return 6787;
                                case Properties::West::TALL:
                                    return 6788;
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
                                    return 6789;
                                case Properties::West::LOW:
                                    return 6790;
                                case Properties::West::TALL:
                                    return 6791;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6792;
                                case Properties::West::LOW:
                                    return 6793;
                                case Properties::West::TALL:
                                    return 6794;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6795;
                                case Properties::West::LOW:
                                    return 6796;
                                case Properties::West::TALL:
                                    return 6797;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6798;
                                case Properties::West::LOW:
                                    return 6799;
                                case Properties::West::TALL:
                                    return 6800;
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
                                    return 6801;
                                case Properties::West::LOW:
                                    return 6802;
                                case Properties::West::TALL:
                                    return 6803;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6804;
                                case Properties::West::LOW:
                                    return 6805;
                                case Properties::West::TALL:
                                    return 6806;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6807;
                                case Properties::West::LOW:
                                    return 6808;
                                case Properties::West::TALL:
                                    return 6809;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6810;
                                case Properties::West::LOW:
                                    return 6811;
                                case Properties::West::TALL:
                                    return 6812;
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
                                    return 6813;
                                case Properties::West::LOW:
                                    return 6814;
                                case Properties::West::TALL:
                                    return 6815;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6816;
                                case Properties::West::LOW:
                                    return 6817;
                                case Properties::West::TALL:
                                    return 6818;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6819;
                                case Properties::West::LOW:
                                    return 6820;
                                case Properties::West::TALL:
                                    return 6821;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6822;
                                case Properties::West::LOW:
                                    return 6823;
                                case Properties::West::TALL:
                                    return 6824;
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
                                    return 6825;
                                case Properties::West::LOW:
                                    return 6826;
                                case Properties::West::TALL:
                                    return 6827;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6828;
                                case Properties::West::LOW:
                                    return 6829;
                                case Properties::West::TALL:
                                    return 6830;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6831;
                                case Properties::West::LOW:
                                    return 6832;
                                case Properties::West::TALL:
                                    return 6833;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6834;
                                case Properties::West::LOW:
                                    return 6835;
                                case Properties::West::TALL:
                                    return 6836;
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
                                    return 6837;
                                case Properties::West::LOW:
                                    return 6838;
                                case Properties::West::TALL:
                                    return 6839;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6840;
                                case Properties::West::LOW:
                                    return 6841;
                                case Properties::West::TALL:
                                    return 6842;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6843;
                                case Properties::West::LOW:
                                    return 6844;
                                case Properties::West::TALL:
                                    return 6845;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6846;
                                case Properties::West::LOW:
                                    return 6847;
                                case Properties::West::TALL:
                                    return 6848;
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
                                    return 6849;
                                case Properties::West::LOW:
                                    return 6850;
                                case Properties::West::TALL:
                                    return 6851;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6852;
                                case Properties::West::LOW:
                                    return 6853;
                                case Properties::West::TALL:
                                    return 6854;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6855;
                                case Properties::West::LOW:
                                    return 6856;
                                case Properties::West::TALL:
                                    return 6857;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6858;
                                case Properties::West::LOW:
                                    return 6859;
                                case Properties::West::TALL:
                                    return 6860;
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
                                    return 6861;
                                case Properties::West::LOW:
                                    return 6862;
                                case Properties::West::TALL:
                                    return 6863;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6864;
                                case Properties::West::LOW:
                                    return 6865;
                                case Properties::West::TALL:
                                    return 6866;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6867;
                                case Properties::West::LOW:
                                    return 6868;
                                case Properties::West::TALL:
                                    return 6869;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6870;
                                case Properties::West::LOW:
                                    return 6871;
                                case Properties::West::TALL:
                                    return 6872;
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
                                    return 6873;
                                case Properties::West::LOW:
                                    return 6874;
                                case Properties::West::TALL:
                                    return 6875;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6876;
                                case Properties::West::LOW:
                                    return 6877;
                                case Properties::West::TALL:
                                    return 6878;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6879;
                                case Properties::West::LOW:
                                    return 6880;
                                case Properties::West::TALL:
                                    return 6881;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6882;
                                case Properties::West::LOW:
                                    return 6883;
                                case Properties::West::TALL:
                                    return 6884;
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
                                    return 6885;
                                case Properties::West::LOW:
                                    return 6886;
                                case Properties::West::TALL:
                                    return 6887;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6888;
                                case Properties::West::LOW:
                                    return 6889;
                                case Properties::West::TALL:
                                    return 6890;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6891;
                                case Properties::West::LOW:
                                    return 6892;
                                case Properties::West::TALL:
                                    return 6893;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6894;
                                case Properties::West::LOW:
                                    return 6895;
                                case Properties::West::TALL:
                                    return 6896;
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
