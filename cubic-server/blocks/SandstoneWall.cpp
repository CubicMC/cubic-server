#include "SandstoneWall.hpp"
namespace Blocks {
    namespace SandstoneWall {
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
                                    return 16772;
                                case Properties::West::LOW:
                                    return 16773;
                                case Properties::West::TALL:
                                    return 16774;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16775;
                                case Properties::West::LOW:
                                    return 16776;
                                case Properties::West::TALL:
                                    return 16777;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16778;
                                case Properties::West::LOW:
                                    return 16779;
                                case Properties::West::TALL:
                                    return 16780;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16781;
                                case Properties::West::LOW:
                                    return 16782;
                                case Properties::West::TALL:
                                    return 16783;
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
                                    return 16784;
                                case Properties::West::LOW:
                                    return 16785;
                                case Properties::West::TALL:
                                    return 16786;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16787;
                                case Properties::West::LOW:
                                    return 16788;
                                case Properties::West::TALL:
                                    return 16789;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16790;
                                case Properties::West::LOW:
                                    return 16791;
                                case Properties::West::TALL:
                                    return 16792;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16793;
                                case Properties::West::LOW:
                                    return 16794;
                                case Properties::West::TALL:
                                    return 16795;
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
                                    return 16796;
                                case Properties::West::LOW:
                                    return 16797;
                                case Properties::West::TALL:
                                    return 16798;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16799;
                                case Properties::West::LOW:
                                    return 16800;
                                case Properties::West::TALL:
                                    return 16801;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16802;
                                case Properties::West::LOW:
                                    return 16803;
                                case Properties::West::TALL:
                                    return 16804;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16805;
                                case Properties::West::LOW:
                                    return 16806;
                                case Properties::West::TALL:
                                    return 16807;
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
                                    return 16808;
                                case Properties::West::LOW:
                                    return 16809;
                                case Properties::West::TALL:
                                    return 16810;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16811;
                                case Properties::West::LOW:
                                    return 16812;
                                case Properties::West::TALL:
                                    return 16813;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16814;
                                case Properties::West::LOW:
                                    return 16815;
                                case Properties::West::TALL:
                                    return 16816;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16817;
                                case Properties::West::LOW:
                                    return 16818;
                                case Properties::West::TALL:
                                    return 16819;
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
                                    return 16820;
                                case Properties::West::LOW:
                                    return 16821;
                                case Properties::West::TALL:
                                    return 16822;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16823;
                                case Properties::West::LOW:
                                    return 16824;
                                case Properties::West::TALL:
                                    return 16825;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16826;
                                case Properties::West::LOW:
                                    return 16827;
                                case Properties::West::TALL:
                                    return 16828;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16829;
                                case Properties::West::LOW:
                                    return 16830;
                                case Properties::West::TALL:
                                    return 16831;
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
                                    return 16832;
                                case Properties::West::LOW:
                                    return 16833;
                                case Properties::West::TALL:
                                    return 16834;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16835;
                                case Properties::West::LOW:
                                    return 16836;
                                case Properties::West::TALL:
                                    return 16837;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16838;
                                case Properties::West::LOW:
                                    return 16839;
                                case Properties::West::TALL:
                                    return 16840;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16841;
                                case Properties::West::LOW:
                                    return 16842;
                                case Properties::West::TALL:
                                    return 16843;
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
                                    return 16844;
                                case Properties::West::LOW:
                                    return 16845;
                                case Properties::West::TALL:
                                    return 16846;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16847;
                                case Properties::West::LOW:
                                    return 16848;
                                case Properties::West::TALL:
                                    return 16849;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16850;
                                case Properties::West::LOW:
                                    return 16851;
                                case Properties::West::TALL:
                                    return 16852;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16853;
                                case Properties::West::LOW:
                                    return 16854;
                                case Properties::West::TALL:
                                    return 16855;
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
                                    return 16856;
                                case Properties::West::LOW:
                                    return 16857;
                                case Properties::West::TALL:
                                    return 16858;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16859;
                                case Properties::West::LOW:
                                    return 16860;
                                case Properties::West::TALL:
                                    return 16861;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16862;
                                case Properties::West::LOW:
                                    return 16863;
                                case Properties::West::TALL:
                                    return 16864;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16865;
                                case Properties::West::LOW:
                                    return 16866;
                                case Properties::West::TALL:
                                    return 16867;
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
                                    return 16868;
                                case Properties::West::LOW:
                                    return 16869;
                                case Properties::West::TALL:
                                    return 16870;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16871;
                                case Properties::West::LOW:
                                    return 16872;
                                case Properties::West::TALL:
                                    return 16873;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16874;
                                case Properties::West::LOW:
                                    return 16875;
                                case Properties::West::TALL:
                                    return 16876;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16877;
                                case Properties::West::LOW:
                                    return 16878;
                                case Properties::West::TALL:
                                    return 16879;
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
                                    return 16880;
                                case Properties::West::LOW:
                                    return 16881;
                                case Properties::West::TALL:
                                    return 16882;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16883;
                                case Properties::West::LOW:
                                    return 16884;
                                case Properties::West::TALL:
                                    return 16885;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16886;
                                case Properties::West::LOW:
                                    return 16887;
                                case Properties::West::TALL:
                                    return 16888;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16889;
                                case Properties::West::LOW:
                                    return 16890;
                                case Properties::West::TALL:
                                    return 16891;
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
                                    return 16892;
                                case Properties::West::LOW:
                                    return 16893;
                                case Properties::West::TALL:
                                    return 16894;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16895;
                                case Properties::West::LOW:
                                    return 16896;
                                case Properties::West::TALL:
                                    return 16897;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16898;
                                case Properties::West::LOW:
                                    return 16899;
                                case Properties::West::TALL:
                                    return 16900;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16901;
                                case Properties::West::LOW:
                                    return 16902;
                                case Properties::West::TALL:
                                    return 16903;
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
                                    return 16904;
                                case Properties::West::LOW:
                                    return 16905;
                                case Properties::West::TALL:
                                    return 16906;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16907;
                                case Properties::West::LOW:
                                    return 16908;
                                case Properties::West::TALL:
                                    return 16909;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16910;
                                case Properties::West::LOW:
                                    return 16911;
                                case Properties::West::TALL:
                                    return 16912;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16913;
                                case Properties::West::LOW:
                                    return 16914;
                                case Properties::West::TALL:
                                    return 16915;
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
                                    return 16916;
                                case Properties::West::LOW:
                                    return 16917;
                                case Properties::West::TALL:
                                    return 16918;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16919;
                                case Properties::West::LOW:
                                    return 16920;
                                case Properties::West::TALL:
                                    return 16921;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16922;
                                case Properties::West::LOW:
                                    return 16923;
                                case Properties::West::TALL:
                                    return 16924;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16925;
                                case Properties::West::LOW:
                                    return 16926;
                                case Properties::West::TALL:
                                    return 16927;
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
                                    return 16928;
                                case Properties::West::LOW:
                                    return 16929;
                                case Properties::West::TALL:
                                    return 16930;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16931;
                                case Properties::West::LOW:
                                    return 16932;
                                case Properties::West::TALL:
                                    return 16933;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16934;
                                case Properties::West::LOW:
                                    return 16935;
                                case Properties::West::TALL:
                                    return 16936;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16937;
                                case Properties::West::LOW:
                                    return 16938;
                                case Properties::West::TALL:
                                    return 16939;
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
                                    return 16940;
                                case Properties::West::LOW:
                                    return 16941;
                                case Properties::West::TALL:
                                    return 16942;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16943;
                                case Properties::West::LOW:
                                    return 16944;
                                case Properties::West::TALL:
                                    return 16945;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16946;
                                case Properties::West::LOW:
                                    return 16947;
                                case Properties::West::TALL:
                                    return 16948;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16949;
                                case Properties::West::LOW:
                                    return 16950;
                                case Properties::West::TALL:
                                    return 16951;
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
                                    return 16952;
                                case Properties::West::LOW:
                                    return 16953;
                                case Properties::West::TALL:
                                    return 16954;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16955;
                                case Properties::West::LOW:
                                    return 16956;
                                case Properties::West::TALL:
                                    return 16957;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16958;
                                case Properties::West::LOW:
                                    return 16959;
                                case Properties::West::TALL:
                                    return 16960;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16961;
                                case Properties::West::LOW:
                                    return 16962;
                                case Properties::West::TALL:
                                    return 16963;
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
                                    return 16964;
                                case Properties::West::LOW:
                                    return 16965;
                                case Properties::West::TALL:
                                    return 16966;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16967;
                                case Properties::West::LOW:
                                    return 16968;
                                case Properties::West::TALL:
                                    return 16969;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16970;
                                case Properties::West::LOW:
                                    return 16971;
                                case Properties::West::TALL:
                                    return 16972;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16973;
                                case Properties::West::LOW:
                                    return 16974;
                                case Properties::West::TALL:
                                    return 16975;
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
                                    return 16976;
                                case Properties::West::LOW:
                                    return 16977;
                                case Properties::West::TALL:
                                    return 16978;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16979;
                                case Properties::West::LOW:
                                    return 16980;
                                case Properties::West::TALL:
                                    return 16981;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16982;
                                case Properties::West::LOW:
                                    return 16983;
                                case Properties::West::TALL:
                                    return 16984;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16985;
                                case Properties::West::LOW:
                                    return 16986;
                                case Properties::West::TALL:
                                    return 16987;
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
                                    return 16988;
                                case Properties::West::LOW:
                                    return 16989;
                                case Properties::West::TALL:
                                    return 16990;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16991;
                                case Properties::West::LOW:
                                    return 16992;
                                case Properties::West::TALL:
                                    return 16993;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16994;
                                case Properties::West::LOW:
                                    return 16995;
                                case Properties::West::TALL:
                                    return 16996;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 16997;
                                case Properties::West::LOW:
                                    return 16998;
                                case Properties::West::TALL:
                                    return 16999;
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
                                    return 17000;
                                case Properties::West::LOW:
                                    return 17001;
                                case Properties::West::TALL:
                                    return 17002;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17003;
                                case Properties::West::LOW:
                                    return 17004;
                                case Properties::West::TALL:
                                    return 17005;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17006;
                                case Properties::West::LOW:
                                    return 17007;
                                case Properties::West::TALL:
                                    return 17008;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17009;
                                case Properties::West::LOW:
                                    return 17010;
                                case Properties::West::TALL:
                                    return 17011;
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
                                    return 17012;
                                case Properties::West::LOW:
                                    return 17013;
                                case Properties::West::TALL:
                                    return 17014;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17015;
                                case Properties::West::LOW:
                                    return 17016;
                                case Properties::West::TALL:
                                    return 17017;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17018;
                                case Properties::West::LOW:
                                    return 17019;
                                case Properties::West::TALL:
                                    return 17020;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17021;
                                case Properties::West::LOW:
                                    return 17022;
                                case Properties::West::TALL:
                                    return 17023;
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
                                    return 17024;
                                case Properties::West::LOW:
                                    return 17025;
                                case Properties::West::TALL:
                                    return 17026;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17027;
                                case Properties::West::LOW:
                                    return 17028;
                                case Properties::West::TALL:
                                    return 17029;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17030;
                                case Properties::West::LOW:
                                    return 17031;
                                case Properties::West::TALL:
                                    return 17032;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17033;
                                case Properties::West::LOW:
                                    return 17034;
                                case Properties::West::TALL:
                                    return 17035;
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
                                    return 17036;
                                case Properties::West::LOW:
                                    return 17037;
                                case Properties::West::TALL:
                                    return 17038;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17039;
                                case Properties::West::LOW:
                                    return 17040;
                                case Properties::West::TALL:
                                    return 17041;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17042;
                                case Properties::West::LOW:
                                    return 17043;
                                case Properties::West::TALL:
                                    return 17044;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17045;
                                case Properties::West::LOW:
                                    return 17046;
                                case Properties::West::TALL:
                                    return 17047;
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
                                    return 17048;
                                case Properties::West::LOW:
                                    return 17049;
                                case Properties::West::TALL:
                                    return 17050;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17051;
                                case Properties::West::LOW:
                                    return 17052;
                                case Properties::West::TALL:
                                    return 17053;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17054;
                                case Properties::West::LOW:
                                    return 17055;
                                case Properties::West::TALL:
                                    return 17056;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17057;
                                case Properties::West::LOW:
                                    return 17058;
                                case Properties::West::TALL:
                                    return 17059;
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
                                    return 17060;
                                case Properties::West::LOW:
                                    return 17061;
                                case Properties::West::TALL:
                                    return 17062;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17063;
                                case Properties::West::LOW:
                                    return 17064;
                                case Properties::West::TALL:
                                    return 17065;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17066;
                                case Properties::West::LOW:
                                    return 17067;
                                case Properties::West::TALL:
                                    return 17068;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17069;
                                case Properties::West::LOW:
                                    return 17070;
                                case Properties::West::TALL:
                                    return 17071;
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
                                    return 17072;
                                case Properties::West::LOW:
                                    return 17073;
                                case Properties::West::TALL:
                                    return 17074;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17075;
                                case Properties::West::LOW:
                                    return 17076;
                                case Properties::West::TALL:
                                    return 17077;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17078;
                                case Properties::West::LOW:
                                    return 17079;
                                case Properties::West::TALL:
                                    return 17080;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17081;
                                case Properties::West::LOW:
                                    return 17082;
                                case Properties::West::TALL:
                                    return 17083;
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
                                    return 17084;
                                case Properties::West::LOW:
                                    return 17085;
                                case Properties::West::TALL:
                                    return 17086;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17087;
                                case Properties::West::LOW:
                                    return 17088;
                                case Properties::West::TALL:
                                    return 17089;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17090;
                                case Properties::West::LOW:
                                    return 17091;
                                case Properties::West::TALL:
                                    return 17092;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 17093;
                                case Properties::West::LOW:
                                    return 17094;
                                case Properties::West::TALL:
                                    return 17095;
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
