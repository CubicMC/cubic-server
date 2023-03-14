#include "PolishedBlackstoneWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedBlackstoneWall {
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
                                    return 19770;
                                case Properties::West::LOW:
                                    return 19771;
                                case Properties::West::TALL:
                                    return 19772;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19773;
                                case Properties::West::LOW:
                                    return 19774;
                                case Properties::West::TALL:
                                    return 19775;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19776;
                                case Properties::West::LOW:
                                    return 19777;
                                case Properties::West::TALL:
                                    return 19778;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19779;
                                case Properties::West::LOW:
                                    return 19780;
                                case Properties::West::TALL:
                                    return 19781;
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
                                    return 19782;
                                case Properties::West::LOW:
                                    return 19783;
                                case Properties::West::TALL:
                                    return 19784;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19785;
                                case Properties::West::LOW:
                                    return 19786;
                                case Properties::West::TALL:
                                    return 19787;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19788;
                                case Properties::West::LOW:
                                    return 19789;
                                case Properties::West::TALL:
                                    return 19790;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19791;
                                case Properties::West::LOW:
                                    return 19792;
                                case Properties::West::TALL:
                                    return 19793;
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
                                    return 19794;
                                case Properties::West::LOW:
                                    return 19795;
                                case Properties::West::TALL:
                                    return 19796;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19797;
                                case Properties::West::LOW:
                                    return 19798;
                                case Properties::West::TALL:
                                    return 19799;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19800;
                                case Properties::West::LOW:
                                    return 19801;
                                case Properties::West::TALL:
                                    return 19802;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19803;
                                case Properties::West::LOW:
                                    return 19804;
                                case Properties::West::TALL:
                                    return 19805;
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
                                    return 19806;
                                case Properties::West::LOW:
                                    return 19807;
                                case Properties::West::TALL:
                                    return 19808;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19809;
                                case Properties::West::LOW:
                                    return 19810;
                                case Properties::West::TALL:
                                    return 19811;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19812;
                                case Properties::West::LOW:
                                    return 19813;
                                case Properties::West::TALL:
                                    return 19814;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19815;
                                case Properties::West::LOW:
                                    return 19816;
                                case Properties::West::TALL:
                                    return 19817;
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
                                    return 19818;
                                case Properties::West::LOW:
                                    return 19819;
                                case Properties::West::TALL:
                                    return 19820;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19821;
                                case Properties::West::LOW:
                                    return 19822;
                                case Properties::West::TALL:
                                    return 19823;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19824;
                                case Properties::West::LOW:
                                    return 19825;
                                case Properties::West::TALL:
                                    return 19826;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19827;
                                case Properties::West::LOW:
                                    return 19828;
                                case Properties::West::TALL:
                                    return 19829;
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
                                    return 19830;
                                case Properties::West::LOW:
                                    return 19831;
                                case Properties::West::TALL:
                                    return 19832;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19833;
                                case Properties::West::LOW:
                                    return 19834;
                                case Properties::West::TALL:
                                    return 19835;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19836;
                                case Properties::West::LOW:
                                    return 19837;
                                case Properties::West::TALL:
                                    return 19838;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19839;
                                case Properties::West::LOW:
                                    return 19840;
                                case Properties::West::TALL:
                                    return 19841;
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
                                    return 19842;
                                case Properties::West::LOW:
                                    return 19843;
                                case Properties::West::TALL:
                                    return 19844;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19845;
                                case Properties::West::LOW:
                                    return 19846;
                                case Properties::West::TALL:
                                    return 19847;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19848;
                                case Properties::West::LOW:
                                    return 19849;
                                case Properties::West::TALL:
                                    return 19850;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19851;
                                case Properties::West::LOW:
                                    return 19852;
                                case Properties::West::TALL:
                                    return 19853;
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
                                    return 19854;
                                case Properties::West::LOW:
                                    return 19855;
                                case Properties::West::TALL:
                                    return 19856;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19857;
                                case Properties::West::LOW:
                                    return 19858;
                                case Properties::West::TALL:
                                    return 19859;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19860;
                                case Properties::West::LOW:
                                    return 19861;
                                case Properties::West::TALL:
                                    return 19862;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19863;
                                case Properties::West::LOW:
                                    return 19864;
                                case Properties::West::TALL:
                                    return 19865;
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
                                    return 19866;
                                case Properties::West::LOW:
                                    return 19867;
                                case Properties::West::TALL:
                                    return 19868;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19869;
                                case Properties::West::LOW:
                                    return 19870;
                                case Properties::West::TALL:
                                    return 19871;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19872;
                                case Properties::West::LOW:
                                    return 19873;
                                case Properties::West::TALL:
                                    return 19874;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19875;
                                case Properties::West::LOW:
                                    return 19876;
                                case Properties::West::TALL:
                                    return 19877;
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
                                    return 19878;
                                case Properties::West::LOW:
                                    return 19879;
                                case Properties::West::TALL:
                                    return 19880;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19881;
                                case Properties::West::LOW:
                                    return 19882;
                                case Properties::West::TALL:
                                    return 19883;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19884;
                                case Properties::West::LOW:
                                    return 19885;
                                case Properties::West::TALL:
                                    return 19886;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19887;
                                case Properties::West::LOW:
                                    return 19888;
                                case Properties::West::TALL:
                                    return 19889;
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
                                    return 19890;
                                case Properties::West::LOW:
                                    return 19891;
                                case Properties::West::TALL:
                                    return 19892;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19893;
                                case Properties::West::LOW:
                                    return 19894;
                                case Properties::West::TALL:
                                    return 19895;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19896;
                                case Properties::West::LOW:
                                    return 19897;
                                case Properties::West::TALL:
                                    return 19898;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19899;
                                case Properties::West::LOW:
                                    return 19900;
                                case Properties::West::TALL:
                                    return 19901;
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
                                    return 19902;
                                case Properties::West::LOW:
                                    return 19903;
                                case Properties::West::TALL:
                                    return 19904;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19905;
                                case Properties::West::LOW:
                                    return 19906;
                                case Properties::West::TALL:
                                    return 19907;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19908;
                                case Properties::West::LOW:
                                    return 19909;
                                case Properties::West::TALL:
                                    return 19910;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19911;
                                case Properties::West::LOW:
                                    return 19912;
                                case Properties::West::TALL:
                                    return 19913;
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
                                    return 19914;
                                case Properties::West::LOW:
                                    return 19915;
                                case Properties::West::TALL:
                                    return 19916;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19917;
                                case Properties::West::LOW:
                                    return 19918;
                                case Properties::West::TALL:
                                    return 19919;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19920;
                                case Properties::West::LOW:
                                    return 19921;
                                case Properties::West::TALL:
                                    return 19922;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19923;
                                case Properties::West::LOW:
                                    return 19924;
                                case Properties::West::TALL:
                                    return 19925;
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
                                    return 19926;
                                case Properties::West::LOW:
                                    return 19927;
                                case Properties::West::TALL:
                                    return 19928;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19929;
                                case Properties::West::LOW:
                                    return 19930;
                                case Properties::West::TALL:
                                    return 19931;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19932;
                                case Properties::West::LOW:
                                    return 19933;
                                case Properties::West::TALL:
                                    return 19934;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19935;
                                case Properties::West::LOW:
                                    return 19936;
                                case Properties::West::TALL:
                                    return 19937;
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
                                    return 19938;
                                case Properties::West::LOW:
                                    return 19939;
                                case Properties::West::TALL:
                                    return 19940;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19941;
                                case Properties::West::LOW:
                                    return 19942;
                                case Properties::West::TALL:
                                    return 19943;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19944;
                                case Properties::West::LOW:
                                    return 19945;
                                case Properties::West::TALL:
                                    return 19946;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19947;
                                case Properties::West::LOW:
                                    return 19948;
                                case Properties::West::TALL:
                                    return 19949;
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
                                    return 19950;
                                case Properties::West::LOW:
                                    return 19951;
                                case Properties::West::TALL:
                                    return 19952;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19953;
                                case Properties::West::LOW:
                                    return 19954;
                                case Properties::West::TALL:
                                    return 19955;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19956;
                                case Properties::West::LOW:
                                    return 19957;
                                case Properties::West::TALL:
                                    return 19958;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19959;
                                case Properties::West::LOW:
                                    return 19960;
                                case Properties::West::TALL:
                                    return 19961;
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
                                    return 19962;
                                case Properties::West::LOW:
                                    return 19963;
                                case Properties::West::TALL:
                                    return 19964;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19965;
                                case Properties::West::LOW:
                                    return 19966;
                                case Properties::West::TALL:
                                    return 19967;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19968;
                                case Properties::West::LOW:
                                    return 19969;
                                case Properties::West::TALL:
                                    return 19970;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19971;
                                case Properties::West::LOW:
                                    return 19972;
                                case Properties::West::TALL:
                                    return 19973;
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
                                    return 19974;
                                case Properties::West::LOW:
                                    return 19975;
                                case Properties::West::TALL:
                                    return 19976;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19977;
                                case Properties::West::LOW:
                                    return 19978;
                                case Properties::West::TALL:
                                    return 19979;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19980;
                                case Properties::West::LOW:
                                    return 19981;
                                case Properties::West::TALL:
                                    return 19982;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19983;
                                case Properties::West::LOW:
                                    return 19984;
                                case Properties::West::TALL:
                                    return 19985;
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
                                    return 19986;
                                case Properties::West::LOW:
                                    return 19987;
                                case Properties::West::TALL:
                                    return 19988;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19989;
                                case Properties::West::LOW:
                                    return 19990;
                                case Properties::West::TALL:
                                    return 19991;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19992;
                                case Properties::West::LOW:
                                    return 19993;
                                case Properties::West::TALL:
                                    return 19994;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19995;
                                case Properties::West::LOW:
                                    return 19996;
                                case Properties::West::TALL:
                                    return 19997;
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
                                    return 19998;
                                case Properties::West::LOW:
                                    return 19999;
                                case Properties::West::TALL:
                                    return 20000;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20001;
                                case Properties::West::LOW:
                                    return 20002;
                                case Properties::West::TALL:
                                    return 20003;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20004;
                                case Properties::West::LOW:
                                    return 20005;
                                case Properties::West::TALL:
                                    return 20006;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20007;
                                case Properties::West::LOW:
                                    return 20008;
                                case Properties::West::TALL:
                                    return 20009;
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
                                    return 20010;
                                case Properties::West::LOW:
                                    return 20011;
                                case Properties::West::TALL:
                                    return 20012;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20013;
                                case Properties::West::LOW:
                                    return 20014;
                                case Properties::West::TALL:
                                    return 20015;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20016;
                                case Properties::West::LOW:
                                    return 20017;
                                case Properties::West::TALL:
                                    return 20018;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20019;
                                case Properties::West::LOW:
                                    return 20020;
                                case Properties::West::TALL:
                                    return 20021;
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
                                    return 20022;
                                case Properties::West::LOW:
                                    return 20023;
                                case Properties::West::TALL:
                                    return 20024;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20025;
                                case Properties::West::LOW:
                                    return 20026;
                                case Properties::West::TALL:
                                    return 20027;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20028;
                                case Properties::West::LOW:
                                    return 20029;
                                case Properties::West::TALL:
                                    return 20030;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20031;
                                case Properties::West::LOW:
                                    return 20032;
                                case Properties::West::TALL:
                                    return 20033;
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
                                    return 20034;
                                case Properties::West::LOW:
                                    return 20035;
                                case Properties::West::TALL:
                                    return 20036;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20037;
                                case Properties::West::LOW:
                                    return 20038;
                                case Properties::West::TALL:
                                    return 20039;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20040;
                                case Properties::West::LOW:
                                    return 20041;
                                case Properties::West::TALL:
                                    return 20042;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20043;
                                case Properties::West::LOW:
                                    return 20044;
                                case Properties::West::TALL:
                                    return 20045;
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
                                    return 20046;
                                case Properties::West::LOW:
                                    return 20047;
                                case Properties::West::TALL:
                                    return 20048;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20049;
                                case Properties::West::LOW:
                                    return 20050;
                                case Properties::West::TALL:
                                    return 20051;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20052;
                                case Properties::West::LOW:
                                    return 20053;
                                case Properties::West::TALL:
                                    return 20054;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20055;
                                case Properties::West::LOW:
                                    return 20056;
                                case Properties::West::TALL:
                                    return 20057;
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
                                    return 20058;
                                case Properties::West::LOW:
                                    return 20059;
                                case Properties::West::TALL:
                                    return 20060;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20061;
                                case Properties::West::LOW:
                                    return 20062;
                                case Properties::West::TALL:
                                    return 20063;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20064;
                                case Properties::West::LOW:
                                    return 20065;
                                case Properties::West::TALL:
                                    return 20066;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20067;
                                case Properties::West::LOW:
                                    return 20068;
                                case Properties::West::TALL:
                                    return 20069;
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
                                    return 20070;
                                case Properties::West::LOW:
                                    return 20071;
                                case Properties::West::TALL:
                                    return 20072;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20073;
                                case Properties::West::LOW:
                                    return 20074;
                                case Properties::West::TALL:
                                    return 20075;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20076;
                                case Properties::West::LOW:
                                    return 20077;
                                case Properties::West::TALL:
                                    return 20078;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20079;
                                case Properties::West::LOW:
                                    return 20080;
                                case Properties::West::TALL:
                                    return 20081;
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
                                    return 20082;
                                case Properties::West::LOW:
                                    return 20083;
                                case Properties::West::TALL:
                                    return 20084;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20085;
                                case Properties::West::LOW:
                                    return 20086;
                                case Properties::West::TALL:
                                    return 20087;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20088;
                                case Properties::West::LOW:
                                    return 20089;
                                case Properties::West::TALL:
                                    return 20090;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20091;
                                case Properties::West::LOW:
                                    return 20092;
                                case Properties::West::TALL:
                                    return 20093;
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
