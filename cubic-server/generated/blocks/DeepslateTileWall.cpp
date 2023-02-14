#include "DeepslateTileWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeepslateTileWall {
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
                                    return 20690;
                                case Properties::West::LOW:
                                    return 20691;
                                case Properties::West::TALL:
                                    return 20692;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20693;
                                case Properties::West::LOW:
                                    return 20694;
                                case Properties::West::TALL:
                                    return 20695;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20696;
                                case Properties::West::LOW:
                                    return 20697;
                                case Properties::West::TALL:
                                    return 20698;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20699;
                                case Properties::West::LOW:
                                    return 20700;
                                case Properties::West::TALL:
                                    return 20701;
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
                                    return 20702;
                                case Properties::West::LOW:
                                    return 20703;
                                case Properties::West::TALL:
                                    return 20704;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20705;
                                case Properties::West::LOW:
                                    return 20706;
                                case Properties::West::TALL:
                                    return 20707;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20708;
                                case Properties::West::LOW:
                                    return 20709;
                                case Properties::West::TALL:
                                    return 20710;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20711;
                                case Properties::West::LOW:
                                    return 20712;
                                case Properties::West::TALL:
                                    return 20713;
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
                                    return 20714;
                                case Properties::West::LOW:
                                    return 20715;
                                case Properties::West::TALL:
                                    return 20716;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20717;
                                case Properties::West::LOW:
                                    return 20718;
                                case Properties::West::TALL:
                                    return 20719;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20720;
                                case Properties::West::LOW:
                                    return 20721;
                                case Properties::West::TALL:
                                    return 20722;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20723;
                                case Properties::West::LOW:
                                    return 20724;
                                case Properties::West::TALL:
                                    return 20725;
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
                                    return 20726;
                                case Properties::West::LOW:
                                    return 20727;
                                case Properties::West::TALL:
                                    return 20728;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20729;
                                case Properties::West::LOW:
                                    return 20730;
                                case Properties::West::TALL:
                                    return 20731;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20732;
                                case Properties::West::LOW:
                                    return 20733;
                                case Properties::West::TALL:
                                    return 20734;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20735;
                                case Properties::West::LOW:
                                    return 20736;
                                case Properties::West::TALL:
                                    return 20737;
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
                                    return 20738;
                                case Properties::West::LOW:
                                    return 20739;
                                case Properties::West::TALL:
                                    return 20740;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20741;
                                case Properties::West::LOW:
                                    return 20742;
                                case Properties::West::TALL:
                                    return 20743;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20744;
                                case Properties::West::LOW:
                                    return 20745;
                                case Properties::West::TALL:
                                    return 20746;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20747;
                                case Properties::West::LOW:
                                    return 20748;
                                case Properties::West::TALL:
                                    return 20749;
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
                                    return 20750;
                                case Properties::West::LOW:
                                    return 20751;
                                case Properties::West::TALL:
                                    return 20752;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20753;
                                case Properties::West::LOW:
                                    return 20754;
                                case Properties::West::TALL:
                                    return 20755;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20756;
                                case Properties::West::LOW:
                                    return 20757;
                                case Properties::West::TALL:
                                    return 20758;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20759;
                                case Properties::West::LOW:
                                    return 20760;
                                case Properties::West::TALL:
                                    return 20761;
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
                                    return 20762;
                                case Properties::West::LOW:
                                    return 20763;
                                case Properties::West::TALL:
                                    return 20764;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20765;
                                case Properties::West::LOW:
                                    return 20766;
                                case Properties::West::TALL:
                                    return 20767;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20768;
                                case Properties::West::LOW:
                                    return 20769;
                                case Properties::West::TALL:
                                    return 20770;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20771;
                                case Properties::West::LOW:
                                    return 20772;
                                case Properties::West::TALL:
                                    return 20773;
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
                                    return 20774;
                                case Properties::West::LOW:
                                    return 20775;
                                case Properties::West::TALL:
                                    return 20776;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20777;
                                case Properties::West::LOW:
                                    return 20778;
                                case Properties::West::TALL:
                                    return 20779;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20780;
                                case Properties::West::LOW:
                                    return 20781;
                                case Properties::West::TALL:
                                    return 20782;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20783;
                                case Properties::West::LOW:
                                    return 20784;
                                case Properties::West::TALL:
                                    return 20785;
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
                                    return 20786;
                                case Properties::West::LOW:
                                    return 20787;
                                case Properties::West::TALL:
                                    return 20788;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20789;
                                case Properties::West::LOW:
                                    return 20790;
                                case Properties::West::TALL:
                                    return 20791;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20792;
                                case Properties::West::LOW:
                                    return 20793;
                                case Properties::West::TALL:
                                    return 20794;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20795;
                                case Properties::West::LOW:
                                    return 20796;
                                case Properties::West::TALL:
                                    return 20797;
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
                                    return 20798;
                                case Properties::West::LOW:
                                    return 20799;
                                case Properties::West::TALL:
                                    return 20800;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20801;
                                case Properties::West::LOW:
                                    return 20802;
                                case Properties::West::TALL:
                                    return 20803;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20804;
                                case Properties::West::LOW:
                                    return 20805;
                                case Properties::West::TALL:
                                    return 20806;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20807;
                                case Properties::West::LOW:
                                    return 20808;
                                case Properties::West::TALL:
                                    return 20809;
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
                                    return 20810;
                                case Properties::West::LOW:
                                    return 20811;
                                case Properties::West::TALL:
                                    return 20812;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20813;
                                case Properties::West::LOW:
                                    return 20814;
                                case Properties::West::TALL:
                                    return 20815;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20816;
                                case Properties::West::LOW:
                                    return 20817;
                                case Properties::West::TALL:
                                    return 20818;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20819;
                                case Properties::West::LOW:
                                    return 20820;
                                case Properties::West::TALL:
                                    return 20821;
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
                                    return 20822;
                                case Properties::West::LOW:
                                    return 20823;
                                case Properties::West::TALL:
                                    return 20824;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20825;
                                case Properties::West::LOW:
                                    return 20826;
                                case Properties::West::TALL:
                                    return 20827;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20828;
                                case Properties::West::LOW:
                                    return 20829;
                                case Properties::West::TALL:
                                    return 20830;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20831;
                                case Properties::West::LOW:
                                    return 20832;
                                case Properties::West::TALL:
                                    return 20833;
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
                                    return 20834;
                                case Properties::West::LOW:
                                    return 20835;
                                case Properties::West::TALL:
                                    return 20836;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20837;
                                case Properties::West::LOW:
                                    return 20838;
                                case Properties::West::TALL:
                                    return 20839;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20840;
                                case Properties::West::LOW:
                                    return 20841;
                                case Properties::West::TALL:
                                    return 20842;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20843;
                                case Properties::West::LOW:
                                    return 20844;
                                case Properties::West::TALL:
                                    return 20845;
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
                                    return 20846;
                                case Properties::West::LOW:
                                    return 20847;
                                case Properties::West::TALL:
                                    return 20848;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20849;
                                case Properties::West::LOW:
                                    return 20850;
                                case Properties::West::TALL:
                                    return 20851;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20852;
                                case Properties::West::LOW:
                                    return 20853;
                                case Properties::West::TALL:
                                    return 20854;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20855;
                                case Properties::West::LOW:
                                    return 20856;
                                case Properties::West::TALL:
                                    return 20857;
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
                                    return 20858;
                                case Properties::West::LOW:
                                    return 20859;
                                case Properties::West::TALL:
                                    return 20860;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20861;
                                case Properties::West::LOW:
                                    return 20862;
                                case Properties::West::TALL:
                                    return 20863;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20864;
                                case Properties::West::LOW:
                                    return 20865;
                                case Properties::West::TALL:
                                    return 20866;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20867;
                                case Properties::West::LOW:
                                    return 20868;
                                case Properties::West::TALL:
                                    return 20869;
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
                                    return 20870;
                                case Properties::West::LOW:
                                    return 20871;
                                case Properties::West::TALL:
                                    return 20872;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20873;
                                case Properties::West::LOW:
                                    return 20874;
                                case Properties::West::TALL:
                                    return 20875;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20876;
                                case Properties::West::LOW:
                                    return 20877;
                                case Properties::West::TALL:
                                    return 20878;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20879;
                                case Properties::West::LOW:
                                    return 20880;
                                case Properties::West::TALL:
                                    return 20881;
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
                                    return 20882;
                                case Properties::West::LOW:
                                    return 20883;
                                case Properties::West::TALL:
                                    return 20884;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20885;
                                case Properties::West::LOW:
                                    return 20886;
                                case Properties::West::TALL:
                                    return 20887;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20888;
                                case Properties::West::LOW:
                                    return 20889;
                                case Properties::West::TALL:
                                    return 20890;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20891;
                                case Properties::West::LOW:
                                    return 20892;
                                case Properties::West::TALL:
                                    return 20893;
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
                                    return 20894;
                                case Properties::West::LOW:
                                    return 20895;
                                case Properties::West::TALL:
                                    return 20896;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20897;
                                case Properties::West::LOW:
                                    return 20898;
                                case Properties::West::TALL:
                                    return 20899;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20900;
                                case Properties::West::LOW:
                                    return 20901;
                                case Properties::West::TALL:
                                    return 20902;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20903;
                                case Properties::West::LOW:
                                    return 20904;
                                case Properties::West::TALL:
                                    return 20905;
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
                                    return 20906;
                                case Properties::West::LOW:
                                    return 20907;
                                case Properties::West::TALL:
                                    return 20908;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20909;
                                case Properties::West::LOW:
                                    return 20910;
                                case Properties::West::TALL:
                                    return 20911;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20912;
                                case Properties::West::LOW:
                                    return 20913;
                                case Properties::West::TALL:
                                    return 20914;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20915;
                                case Properties::West::LOW:
                                    return 20916;
                                case Properties::West::TALL:
                                    return 20917;
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
                                    return 20918;
                                case Properties::West::LOW:
                                    return 20919;
                                case Properties::West::TALL:
                                    return 20920;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20921;
                                case Properties::West::LOW:
                                    return 20922;
                                case Properties::West::TALL:
                                    return 20923;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20924;
                                case Properties::West::LOW:
                                    return 20925;
                                case Properties::West::TALL:
                                    return 20926;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20927;
                                case Properties::West::LOW:
                                    return 20928;
                                case Properties::West::TALL:
                                    return 20929;
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
                                    return 20930;
                                case Properties::West::LOW:
                                    return 20931;
                                case Properties::West::TALL:
                                    return 20932;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20933;
                                case Properties::West::LOW:
                                    return 20934;
                                case Properties::West::TALL:
                                    return 20935;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20936;
                                case Properties::West::LOW:
                                    return 20937;
                                case Properties::West::TALL:
                                    return 20938;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20939;
                                case Properties::West::LOW:
                                    return 20940;
                                case Properties::West::TALL:
                                    return 20941;
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
                                    return 20942;
                                case Properties::West::LOW:
                                    return 20943;
                                case Properties::West::TALL:
                                    return 20944;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20945;
                                case Properties::West::LOW:
                                    return 20946;
                                case Properties::West::TALL:
                                    return 20947;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20948;
                                case Properties::West::LOW:
                                    return 20949;
                                case Properties::West::TALL:
                                    return 20950;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20951;
                                case Properties::West::LOW:
                                    return 20952;
                                case Properties::West::TALL:
                                    return 20953;
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
                                    return 20954;
                                case Properties::West::LOW:
                                    return 20955;
                                case Properties::West::TALL:
                                    return 20956;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20957;
                                case Properties::West::LOW:
                                    return 20958;
                                case Properties::West::TALL:
                                    return 20959;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20960;
                                case Properties::West::LOW:
                                    return 20961;
                                case Properties::West::TALL:
                                    return 20962;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20963;
                                case Properties::West::LOW:
                                    return 20964;
                                case Properties::West::TALL:
                                    return 20965;
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
                                    return 20966;
                                case Properties::West::LOW:
                                    return 20967;
                                case Properties::West::TALL:
                                    return 20968;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20969;
                                case Properties::West::LOW:
                                    return 20970;
                                case Properties::West::TALL:
                                    return 20971;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20972;
                                case Properties::West::LOW:
                                    return 20973;
                                case Properties::West::TALL:
                                    return 20974;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20975;
                                case Properties::West::LOW:
                                    return 20976;
                                case Properties::West::TALL:
                                    return 20977;
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
                                    return 20978;
                                case Properties::West::LOW:
                                    return 20979;
                                case Properties::West::TALL:
                                    return 20980;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20981;
                                case Properties::West::LOW:
                                    return 20982;
                                case Properties::West::TALL:
                                    return 20983;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20984;
                                case Properties::West::LOW:
                                    return 20985;
                                case Properties::West::TALL:
                                    return 20986;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20987;
                                case Properties::West::LOW:
                                    return 20988;
                                case Properties::West::TALL:
                                    return 20989;
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
                                    return 20990;
                                case Properties::West::LOW:
                                    return 20991;
                                case Properties::West::TALL:
                                    return 20992;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20993;
                                case Properties::West::LOW:
                                    return 20994;
                                case Properties::West::TALL:
                                    return 20995;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20996;
                                case Properties::West::LOW:
                                    return 20997;
                                case Properties::West::TALL:
                                    return 20998;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20999;
                                case Properties::West::LOW:
                                    return 21000;
                                case Properties::West::TALL:
                                    return 21001;
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
                                    return 21002;
                                case Properties::West::LOW:
                                    return 21003;
                                case Properties::West::TALL:
                                    return 21004;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21005;
                                case Properties::West::LOW:
                                    return 21006;
                                case Properties::West::TALL:
                                    return 21007;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21008;
                                case Properties::West::LOW:
                                    return 21009;
                                case Properties::West::TALL:
                                    return 21010;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 21011;
                                case Properties::West::LOW:
                                    return 21012;
                                case Properties::West::TALL:
                                    return 21013;
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
