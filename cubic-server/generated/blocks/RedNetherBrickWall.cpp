#include "RedNetherBrickWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RedNetherBrickWall {
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
                                    return 14664;
                                case Properties::West::LOW:
                                    return 14665;
                                case Properties::West::TALL:
                                    return 14666;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14667;
                                case Properties::West::LOW:
                                    return 14668;
                                case Properties::West::TALL:
                                    return 14669;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14670;
                                case Properties::West::LOW:
                                    return 14671;
                                case Properties::West::TALL:
                                    return 14672;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14673;
                                case Properties::West::LOW:
                                    return 14674;
                                case Properties::West::TALL:
                                    return 14675;
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
                                    return 14676;
                                case Properties::West::LOW:
                                    return 14677;
                                case Properties::West::TALL:
                                    return 14678;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14679;
                                case Properties::West::LOW:
                                    return 14680;
                                case Properties::West::TALL:
                                    return 14681;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14682;
                                case Properties::West::LOW:
                                    return 14683;
                                case Properties::West::TALL:
                                    return 14684;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14685;
                                case Properties::West::LOW:
                                    return 14686;
                                case Properties::West::TALL:
                                    return 14687;
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
                                    return 14688;
                                case Properties::West::LOW:
                                    return 14689;
                                case Properties::West::TALL:
                                    return 14690;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14691;
                                case Properties::West::LOW:
                                    return 14692;
                                case Properties::West::TALL:
                                    return 14693;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14694;
                                case Properties::West::LOW:
                                    return 14695;
                                case Properties::West::TALL:
                                    return 14696;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14697;
                                case Properties::West::LOW:
                                    return 14698;
                                case Properties::West::TALL:
                                    return 14699;
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
                                    return 14700;
                                case Properties::West::LOW:
                                    return 14701;
                                case Properties::West::TALL:
                                    return 14702;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14703;
                                case Properties::West::LOW:
                                    return 14704;
                                case Properties::West::TALL:
                                    return 14705;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14706;
                                case Properties::West::LOW:
                                    return 14707;
                                case Properties::West::TALL:
                                    return 14708;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14709;
                                case Properties::West::LOW:
                                    return 14710;
                                case Properties::West::TALL:
                                    return 14711;
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
                                    return 14712;
                                case Properties::West::LOW:
                                    return 14713;
                                case Properties::West::TALL:
                                    return 14714;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14715;
                                case Properties::West::LOW:
                                    return 14716;
                                case Properties::West::TALL:
                                    return 14717;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14718;
                                case Properties::West::LOW:
                                    return 14719;
                                case Properties::West::TALL:
                                    return 14720;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14721;
                                case Properties::West::LOW:
                                    return 14722;
                                case Properties::West::TALL:
                                    return 14723;
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
                                    return 14724;
                                case Properties::West::LOW:
                                    return 14725;
                                case Properties::West::TALL:
                                    return 14726;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14727;
                                case Properties::West::LOW:
                                    return 14728;
                                case Properties::West::TALL:
                                    return 14729;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14730;
                                case Properties::West::LOW:
                                    return 14731;
                                case Properties::West::TALL:
                                    return 14732;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14733;
                                case Properties::West::LOW:
                                    return 14734;
                                case Properties::West::TALL:
                                    return 14735;
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
                                    return 14736;
                                case Properties::West::LOW:
                                    return 14737;
                                case Properties::West::TALL:
                                    return 14738;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14739;
                                case Properties::West::LOW:
                                    return 14740;
                                case Properties::West::TALL:
                                    return 14741;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14742;
                                case Properties::West::LOW:
                                    return 14743;
                                case Properties::West::TALL:
                                    return 14744;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14745;
                                case Properties::West::LOW:
                                    return 14746;
                                case Properties::West::TALL:
                                    return 14747;
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
                                    return 14748;
                                case Properties::West::LOW:
                                    return 14749;
                                case Properties::West::TALL:
                                    return 14750;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14751;
                                case Properties::West::LOW:
                                    return 14752;
                                case Properties::West::TALL:
                                    return 14753;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14754;
                                case Properties::West::LOW:
                                    return 14755;
                                case Properties::West::TALL:
                                    return 14756;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14757;
                                case Properties::West::LOW:
                                    return 14758;
                                case Properties::West::TALL:
                                    return 14759;
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
                                    return 14760;
                                case Properties::West::LOW:
                                    return 14761;
                                case Properties::West::TALL:
                                    return 14762;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14763;
                                case Properties::West::LOW:
                                    return 14764;
                                case Properties::West::TALL:
                                    return 14765;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14766;
                                case Properties::West::LOW:
                                    return 14767;
                                case Properties::West::TALL:
                                    return 14768;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14769;
                                case Properties::West::LOW:
                                    return 14770;
                                case Properties::West::TALL:
                                    return 14771;
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
                                    return 14772;
                                case Properties::West::LOW:
                                    return 14773;
                                case Properties::West::TALL:
                                    return 14774;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14775;
                                case Properties::West::LOW:
                                    return 14776;
                                case Properties::West::TALL:
                                    return 14777;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14778;
                                case Properties::West::LOW:
                                    return 14779;
                                case Properties::West::TALL:
                                    return 14780;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14781;
                                case Properties::West::LOW:
                                    return 14782;
                                case Properties::West::TALL:
                                    return 14783;
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
                                    return 14784;
                                case Properties::West::LOW:
                                    return 14785;
                                case Properties::West::TALL:
                                    return 14786;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14787;
                                case Properties::West::LOW:
                                    return 14788;
                                case Properties::West::TALL:
                                    return 14789;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14790;
                                case Properties::West::LOW:
                                    return 14791;
                                case Properties::West::TALL:
                                    return 14792;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14793;
                                case Properties::West::LOW:
                                    return 14794;
                                case Properties::West::TALL:
                                    return 14795;
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
                                    return 14796;
                                case Properties::West::LOW:
                                    return 14797;
                                case Properties::West::TALL:
                                    return 14798;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14799;
                                case Properties::West::LOW:
                                    return 14800;
                                case Properties::West::TALL:
                                    return 14801;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14802;
                                case Properties::West::LOW:
                                    return 14803;
                                case Properties::West::TALL:
                                    return 14804;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14805;
                                case Properties::West::LOW:
                                    return 14806;
                                case Properties::West::TALL:
                                    return 14807;
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
                                    return 14808;
                                case Properties::West::LOW:
                                    return 14809;
                                case Properties::West::TALL:
                                    return 14810;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14811;
                                case Properties::West::LOW:
                                    return 14812;
                                case Properties::West::TALL:
                                    return 14813;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14814;
                                case Properties::West::LOW:
                                    return 14815;
                                case Properties::West::TALL:
                                    return 14816;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14817;
                                case Properties::West::LOW:
                                    return 14818;
                                case Properties::West::TALL:
                                    return 14819;
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
                                    return 14820;
                                case Properties::West::LOW:
                                    return 14821;
                                case Properties::West::TALL:
                                    return 14822;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14823;
                                case Properties::West::LOW:
                                    return 14824;
                                case Properties::West::TALL:
                                    return 14825;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14826;
                                case Properties::West::LOW:
                                    return 14827;
                                case Properties::West::TALL:
                                    return 14828;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14829;
                                case Properties::West::LOW:
                                    return 14830;
                                case Properties::West::TALL:
                                    return 14831;
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
                                    return 14832;
                                case Properties::West::LOW:
                                    return 14833;
                                case Properties::West::TALL:
                                    return 14834;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14835;
                                case Properties::West::LOW:
                                    return 14836;
                                case Properties::West::TALL:
                                    return 14837;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14838;
                                case Properties::West::LOW:
                                    return 14839;
                                case Properties::West::TALL:
                                    return 14840;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14841;
                                case Properties::West::LOW:
                                    return 14842;
                                case Properties::West::TALL:
                                    return 14843;
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
                                    return 14844;
                                case Properties::West::LOW:
                                    return 14845;
                                case Properties::West::TALL:
                                    return 14846;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14847;
                                case Properties::West::LOW:
                                    return 14848;
                                case Properties::West::TALL:
                                    return 14849;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14850;
                                case Properties::West::LOW:
                                    return 14851;
                                case Properties::West::TALL:
                                    return 14852;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14853;
                                case Properties::West::LOW:
                                    return 14854;
                                case Properties::West::TALL:
                                    return 14855;
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
                                    return 14856;
                                case Properties::West::LOW:
                                    return 14857;
                                case Properties::West::TALL:
                                    return 14858;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14859;
                                case Properties::West::LOW:
                                    return 14860;
                                case Properties::West::TALL:
                                    return 14861;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14862;
                                case Properties::West::LOW:
                                    return 14863;
                                case Properties::West::TALL:
                                    return 14864;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14865;
                                case Properties::West::LOW:
                                    return 14866;
                                case Properties::West::TALL:
                                    return 14867;
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
                                    return 14868;
                                case Properties::West::LOW:
                                    return 14869;
                                case Properties::West::TALL:
                                    return 14870;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14871;
                                case Properties::West::LOW:
                                    return 14872;
                                case Properties::West::TALL:
                                    return 14873;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14874;
                                case Properties::West::LOW:
                                    return 14875;
                                case Properties::West::TALL:
                                    return 14876;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14877;
                                case Properties::West::LOW:
                                    return 14878;
                                case Properties::West::TALL:
                                    return 14879;
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
                                    return 14880;
                                case Properties::West::LOW:
                                    return 14881;
                                case Properties::West::TALL:
                                    return 14882;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14883;
                                case Properties::West::LOW:
                                    return 14884;
                                case Properties::West::TALL:
                                    return 14885;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14886;
                                case Properties::West::LOW:
                                    return 14887;
                                case Properties::West::TALL:
                                    return 14888;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14889;
                                case Properties::West::LOW:
                                    return 14890;
                                case Properties::West::TALL:
                                    return 14891;
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
                                    return 14892;
                                case Properties::West::LOW:
                                    return 14893;
                                case Properties::West::TALL:
                                    return 14894;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14895;
                                case Properties::West::LOW:
                                    return 14896;
                                case Properties::West::TALL:
                                    return 14897;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14898;
                                case Properties::West::LOW:
                                    return 14899;
                                case Properties::West::TALL:
                                    return 14900;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14901;
                                case Properties::West::LOW:
                                    return 14902;
                                case Properties::West::TALL:
                                    return 14903;
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
                                    return 14904;
                                case Properties::West::LOW:
                                    return 14905;
                                case Properties::West::TALL:
                                    return 14906;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14907;
                                case Properties::West::LOW:
                                    return 14908;
                                case Properties::West::TALL:
                                    return 14909;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14910;
                                case Properties::West::LOW:
                                    return 14911;
                                case Properties::West::TALL:
                                    return 14912;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14913;
                                case Properties::West::LOW:
                                    return 14914;
                                case Properties::West::TALL:
                                    return 14915;
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
                                    return 14916;
                                case Properties::West::LOW:
                                    return 14917;
                                case Properties::West::TALL:
                                    return 14918;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14919;
                                case Properties::West::LOW:
                                    return 14920;
                                case Properties::West::TALL:
                                    return 14921;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14922;
                                case Properties::West::LOW:
                                    return 14923;
                                case Properties::West::TALL:
                                    return 14924;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14925;
                                case Properties::West::LOW:
                                    return 14926;
                                case Properties::West::TALL:
                                    return 14927;
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
                                    return 14928;
                                case Properties::West::LOW:
                                    return 14929;
                                case Properties::West::TALL:
                                    return 14930;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14931;
                                case Properties::West::LOW:
                                    return 14932;
                                case Properties::West::TALL:
                                    return 14933;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14934;
                                case Properties::West::LOW:
                                    return 14935;
                                case Properties::West::TALL:
                                    return 14936;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14937;
                                case Properties::West::LOW:
                                    return 14938;
                                case Properties::West::TALL:
                                    return 14939;
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
                                    return 14940;
                                case Properties::West::LOW:
                                    return 14941;
                                case Properties::West::TALL:
                                    return 14942;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14943;
                                case Properties::West::LOW:
                                    return 14944;
                                case Properties::West::TALL:
                                    return 14945;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14946;
                                case Properties::West::LOW:
                                    return 14947;
                                case Properties::West::TALL:
                                    return 14948;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14949;
                                case Properties::West::LOW:
                                    return 14950;
                                case Properties::West::TALL:
                                    return 14951;
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
                                    return 14952;
                                case Properties::West::LOW:
                                    return 14953;
                                case Properties::West::TALL:
                                    return 14954;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14955;
                                case Properties::West::LOW:
                                    return 14956;
                                case Properties::West::TALL:
                                    return 14957;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14958;
                                case Properties::West::LOW:
                                    return 14959;
                                case Properties::West::TALL:
                                    return 14960;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14961;
                                case Properties::West::LOW:
                                    return 14962;
                                case Properties::West::TALL:
                                    return 14963;
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
                                    return 14964;
                                case Properties::West::LOW:
                                    return 14965;
                                case Properties::West::TALL:
                                    return 14966;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14967;
                                case Properties::West::LOW:
                                    return 14968;
                                case Properties::West::TALL:
                                    return 14969;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14970;
                                case Properties::West::LOW:
                                    return 14971;
                                case Properties::West::TALL:
                                    return 14972;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14973;
                                case Properties::West::LOW:
                                    return 14974;
                                case Properties::West::TALL:
                                    return 14975;
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
                                    return 14976;
                                case Properties::West::LOW:
                                    return 14977;
                                case Properties::West::TALL:
                                    return 14978;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14979;
                                case Properties::West::LOW:
                                    return 14980;
                                case Properties::West::TALL:
                                    return 14981;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14982;
                                case Properties::West::LOW:
                                    return 14983;
                                case Properties::West::TALL:
                                    return 14984;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14985;
                                case Properties::West::LOW:
                                    return 14986;
                                case Properties::West::TALL:
                                    return 14987;
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
