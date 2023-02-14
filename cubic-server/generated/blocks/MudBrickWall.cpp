#include "MudBrickWall.hpp"
#include <stdexcept>

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
                                    return 13692;
                                case Properties::West::LOW:
                                    return 13693;
                                case Properties::West::TALL:
                                    return 13694;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13695;
                                case Properties::West::LOW:
                                    return 13696;
                                case Properties::West::TALL:
                                    return 13697;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13698;
                                case Properties::West::LOW:
                                    return 13699;
                                case Properties::West::TALL:
                                    return 13700;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13701;
                                case Properties::West::LOW:
                                    return 13702;
                                case Properties::West::TALL:
                                    return 13703;
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
                                    return 13704;
                                case Properties::West::LOW:
                                    return 13705;
                                case Properties::West::TALL:
                                    return 13706;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13707;
                                case Properties::West::LOW:
                                    return 13708;
                                case Properties::West::TALL:
                                    return 13709;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13710;
                                case Properties::West::LOW:
                                    return 13711;
                                case Properties::West::TALL:
                                    return 13712;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13713;
                                case Properties::West::LOW:
                                    return 13714;
                                case Properties::West::TALL:
                                    return 13715;
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
                                    return 13716;
                                case Properties::West::LOW:
                                    return 13717;
                                case Properties::West::TALL:
                                    return 13718;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13719;
                                case Properties::West::LOW:
                                    return 13720;
                                case Properties::West::TALL:
                                    return 13721;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13722;
                                case Properties::West::LOW:
                                    return 13723;
                                case Properties::West::TALL:
                                    return 13724;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13725;
                                case Properties::West::LOW:
                                    return 13726;
                                case Properties::West::TALL:
                                    return 13727;
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
                                    return 13728;
                                case Properties::West::LOW:
                                    return 13729;
                                case Properties::West::TALL:
                                    return 13730;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13731;
                                case Properties::West::LOW:
                                    return 13732;
                                case Properties::West::TALL:
                                    return 13733;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13734;
                                case Properties::West::LOW:
                                    return 13735;
                                case Properties::West::TALL:
                                    return 13736;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13737;
                                case Properties::West::LOW:
                                    return 13738;
                                case Properties::West::TALL:
                                    return 13739;
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
                                    return 13740;
                                case Properties::West::LOW:
                                    return 13741;
                                case Properties::West::TALL:
                                    return 13742;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13743;
                                case Properties::West::LOW:
                                    return 13744;
                                case Properties::West::TALL:
                                    return 13745;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13746;
                                case Properties::West::LOW:
                                    return 13747;
                                case Properties::West::TALL:
                                    return 13748;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13749;
                                case Properties::West::LOW:
                                    return 13750;
                                case Properties::West::TALL:
                                    return 13751;
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
                                    return 13752;
                                case Properties::West::LOW:
                                    return 13753;
                                case Properties::West::TALL:
                                    return 13754;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13755;
                                case Properties::West::LOW:
                                    return 13756;
                                case Properties::West::TALL:
                                    return 13757;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13758;
                                case Properties::West::LOW:
                                    return 13759;
                                case Properties::West::TALL:
                                    return 13760;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13761;
                                case Properties::West::LOW:
                                    return 13762;
                                case Properties::West::TALL:
                                    return 13763;
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
                                    return 13764;
                                case Properties::West::LOW:
                                    return 13765;
                                case Properties::West::TALL:
                                    return 13766;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13767;
                                case Properties::West::LOW:
                                    return 13768;
                                case Properties::West::TALL:
                                    return 13769;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13770;
                                case Properties::West::LOW:
                                    return 13771;
                                case Properties::West::TALL:
                                    return 13772;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13773;
                                case Properties::West::LOW:
                                    return 13774;
                                case Properties::West::TALL:
                                    return 13775;
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
                                    return 13776;
                                case Properties::West::LOW:
                                    return 13777;
                                case Properties::West::TALL:
                                    return 13778;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13779;
                                case Properties::West::LOW:
                                    return 13780;
                                case Properties::West::TALL:
                                    return 13781;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13782;
                                case Properties::West::LOW:
                                    return 13783;
                                case Properties::West::TALL:
                                    return 13784;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13785;
                                case Properties::West::LOW:
                                    return 13786;
                                case Properties::West::TALL:
                                    return 13787;
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
                                    return 13788;
                                case Properties::West::LOW:
                                    return 13789;
                                case Properties::West::TALL:
                                    return 13790;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13791;
                                case Properties::West::LOW:
                                    return 13792;
                                case Properties::West::TALL:
                                    return 13793;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13794;
                                case Properties::West::LOW:
                                    return 13795;
                                case Properties::West::TALL:
                                    return 13796;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13797;
                                case Properties::West::LOW:
                                    return 13798;
                                case Properties::West::TALL:
                                    return 13799;
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
                                    return 13800;
                                case Properties::West::LOW:
                                    return 13801;
                                case Properties::West::TALL:
                                    return 13802;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13803;
                                case Properties::West::LOW:
                                    return 13804;
                                case Properties::West::TALL:
                                    return 13805;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13806;
                                case Properties::West::LOW:
                                    return 13807;
                                case Properties::West::TALL:
                                    return 13808;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13809;
                                case Properties::West::LOW:
                                    return 13810;
                                case Properties::West::TALL:
                                    return 13811;
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
                                    return 13812;
                                case Properties::West::LOW:
                                    return 13813;
                                case Properties::West::TALL:
                                    return 13814;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13815;
                                case Properties::West::LOW:
                                    return 13816;
                                case Properties::West::TALL:
                                    return 13817;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13818;
                                case Properties::West::LOW:
                                    return 13819;
                                case Properties::West::TALL:
                                    return 13820;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13821;
                                case Properties::West::LOW:
                                    return 13822;
                                case Properties::West::TALL:
                                    return 13823;
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
                                    return 13824;
                                case Properties::West::LOW:
                                    return 13825;
                                case Properties::West::TALL:
                                    return 13826;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13827;
                                case Properties::West::LOW:
                                    return 13828;
                                case Properties::West::TALL:
                                    return 13829;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13830;
                                case Properties::West::LOW:
                                    return 13831;
                                case Properties::West::TALL:
                                    return 13832;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13833;
                                case Properties::West::LOW:
                                    return 13834;
                                case Properties::West::TALL:
                                    return 13835;
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
                                    return 13836;
                                case Properties::West::LOW:
                                    return 13837;
                                case Properties::West::TALL:
                                    return 13838;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13839;
                                case Properties::West::LOW:
                                    return 13840;
                                case Properties::West::TALL:
                                    return 13841;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13842;
                                case Properties::West::LOW:
                                    return 13843;
                                case Properties::West::TALL:
                                    return 13844;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13845;
                                case Properties::West::LOW:
                                    return 13846;
                                case Properties::West::TALL:
                                    return 13847;
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
                                    return 13848;
                                case Properties::West::LOW:
                                    return 13849;
                                case Properties::West::TALL:
                                    return 13850;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13851;
                                case Properties::West::LOW:
                                    return 13852;
                                case Properties::West::TALL:
                                    return 13853;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13854;
                                case Properties::West::LOW:
                                    return 13855;
                                case Properties::West::TALL:
                                    return 13856;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13857;
                                case Properties::West::LOW:
                                    return 13858;
                                case Properties::West::TALL:
                                    return 13859;
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
                                    return 13860;
                                case Properties::West::LOW:
                                    return 13861;
                                case Properties::West::TALL:
                                    return 13862;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13863;
                                case Properties::West::LOW:
                                    return 13864;
                                case Properties::West::TALL:
                                    return 13865;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13866;
                                case Properties::West::LOW:
                                    return 13867;
                                case Properties::West::TALL:
                                    return 13868;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13869;
                                case Properties::West::LOW:
                                    return 13870;
                                case Properties::West::TALL:
                                    return 13871;
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
                                    return 13872;
                                case Properties::West::LOW:
                                    return 13873;
                                case Properties::West::TALL:
                                    return 13874;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13875;
                                case Properties::West::LOW:
                                    return 13876;
                                case Properties::West::TALL:
                                    return 13877;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13878;
                                case Properties::West::LOW:
                                    return 13879;
                                case Properties::West::TALL:
                                    return 13880;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13881;
                                case Properties::West::LOW:
                                    return 13882;
                                case Properties::West::TALL:
                                    return 13883;
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
                                    return 13884;
                                case Properties::West::LOW:
                                    return 13885;
                                case Properties::West::TALL:
                                    return 13886;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13887;
                                case Properties::West::LOW:
                                    return 13888;
                                case Properties::West::TALL:
                                    return 13889;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13890;
                                case Properties::West::LOW:
                                    return 13891;
                                case Properties::West::TALL:
                                    return 13892;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13893;
                                case Properties::West::LOW:
                                    return 13894;
                                case Properties::West::TALL:
                                    return 13895;
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
                                    return 13896;
                                case Properties::West::LOW:
                                    return 13897;
                                case Properties::West::TALL:
                                    return 13898;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13899;
                                case Properties::West::LOW:
                                    return 13900;
                                case Properties::West::TALL:
                                    return 13901;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13902;
                                case Properties::West::LOW:
                                    return 13903;
                                case Properties::West::TALL:
                                    return 13904;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13905;
                                case Properties::West::LOW:
                                    return 13906;
                                case Properties::West::TALL:
                                    return 13907;
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
                                    return 13908;
                                case Properties::West::LOW:
                                    return 13909;
                                case Properties::West::TALL:
                                    return 13910;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13911;
                                case Properties::West::LOW:
                                    return 13912;
                                case Properties::West::TALL:
                                    return 13913;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13914;
                                case Properties::West::LOW:
                                    return 13915;
                                case Properties::West::TALL:
                                    return 13916;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13917;
                                case Properties::West::LOW:
                                    return 13918;
                                case Properties::West::TALL:
                                    return 13919;
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
                                    return 13920;
                                case Properties::West::LOW:
                                    return 13921;
                                case Properties::West::TALL:
                                    return 13922;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13923;
                                case Properties::West::LOW:
                                    return 13924;
                                case Properties::West::TALL:
                                    return 13925;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13926;
                                case Properties::West::LOW:
                                    return 13927;
                                case Properties::West::TALL:
                                    return 13928;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13929;
                                case Properties::West::LOW:
                                    return 13930;
                                case Properties::West::TALL:
                                    return 13931;
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
                                    return 13932;
                                case Properties::West::LOW:
                                    return 13933;
                                case Properties::West::TALL:
                                    return 13934;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13935;
                                case Properties::West::LOW:
                                    return 13936;
                                case Properties::West::TALL:
                                    return 13937;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13938;
                                case Properties::West::LOW:
                                    return 13939;
                                case Properties::West::TALL:
                                    return 13940;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13941;
                                case Properties::West::LOW:
                                    return 13942;
                                case Properties::West::TALL:
                                    return 13943;
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
                                    return 13944;
                                case Properties::West::LOW:
                                    return 13945;
                                case Properties::West::TALL:
                                    return 13946;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13947;
                                case Properties::West::LOW:
                                    return 13948;
                                case Properties::West::TALL:
                                    return 13949;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13950;
                                case Properties::West::LOW:
                                    return 13951;
                                case Properties::West::TALL:
                                    return 13952;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13953;
                                case Properties::West::LOW:
                                    return 13954;
                                case Properties::West::TALL:
                                    return 13955;
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
                                    return 13956;
                                case Properties::West::LOW:
                                    return 13957;
                                case Properties::West::TALL:
                                    return 13958;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13959;
                                case Properties::West::LOW:
                                    return 13960;
                                case Properties::West::TALL:
                                    return 13961;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13962;
                                case Properties::West::LOW:
                                    return 13963;
                                case Properties::West::TALL:
                                    return 13964;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13965;
                                case Properties::West::LOW:
                                    return 13966;
                                case Properties::West::TALL:
                                    return 13967;
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
                                    return 13968;
                                case Properties::West::LOW:
                                    return 13969;
                                case Properties::West::TALL:
                                    return 13970;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13971;
                                case Properties::West::LOW:
                                    return 13972;
                                case Properties::West::TALL:
                                    return 13973;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13974;
                                case Properties::West::LOW:
                                    return 13975;
                                case Properties::West::TALL:
                                    return 13976;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13977;
                                case Properties::West::LOW:
                                    return 13978;
                                case Properties::West::TALL:
                                    return 13979;
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
                                    return 13980;
                                case Properties::West::LOW:
                                    return 13981;
                                case Properties::West::TALL:
                                    return 13982;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13983;
                                case Properties::West::LOW:
                                    return 13984;
                                case Properties::West::TALL:
                                    return 13985;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13986;
                                case Properties::West::LOW:
                                    return 13987;
                                case Properties::West::TALL:
                                    return 13988;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13989;
                                case Properties::West::LOW:
                                    return 13990;
                                case Properties::West::TALL:
                                    return 13991;
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
                                    return 13992;
                                case Properties::West::LOW:
                                    return 13993;
                                case Properties::West::TALL:
                                    return 13994;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13995;
                                case Properties::West::LOW:
                                    return 13996;
                                case Properties::West::TALL:
                                    return 13997;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13998;
                                case Properties::West::LOW:
                                    return 13999;
                                case Properties::West::TALL:
                                    return 14000;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14001;
                                case Properties::West::LOW:
                                    return 14002;
                                case Properties::West::TALL:
                                    return 14003;
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
                                    return 14004;
                                case Properties::West::LOW:
                                    return 14005;
                                case Properties::West::TALL:
                                    return 14006;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14007;
                                case Properties::West::LOW:
                                    return 14008;
                                case Properties::West::TALL:
                                    return 14009;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14010;
                                case Properties::West::LOW:
                                    return 14011;
                                case Properties::West::TALL:
                                    return 14012;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14013;
                                case Properties::West::LOW:
                                    return 14014;
                                case Properties::West::TALL:
                                    return 14015;
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
