#include "BrickWall.hpp"
#include <stdexcept>

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
                                    return 11748;
                                case Properties::West::LOW:
                                    return 11749;
                                case Properties::West::TALL:
                                    return 11750;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11751;
                                case Properties::West::LOW:
                                    return 11752;
                                case Properties::West::TALL:
                                    return 11753;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11754;
                                case Properties::West::LOW:
                                    return 11755;
                                case Properties::West::TALL:
                                    return 11756;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11757;
                                case Properties::West::LOW:
                                    return 11758;
                                case Properties::West::TALL:
                                    return 11759;
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
                                    return 11760;
                                case Properties::West::LOW:
                                    return 11761;
                                case Properties::West::TALL:
                                    return 11762;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11763;
                                case Properties::West::LOW:
                                    return 11764;
                                case Properties::West::TALL:
                                    return 11765;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11766;
                                case Properties::West::LOW:
                                    return 11767;
                                case Properties::West::TALL:
                                    return 11768;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11769;
                                case Properties::West::LOW:
                                    return 11770;
                                case Properties::West::TALL:
                                    return 11771;
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
                                    return 11772;
                                case Properties::West::LOW:
                                    return 11773;
                                case Properties::West::TALL:
                                    return 11774;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11775;
                                case Properties::West::LOW:
                                    return 11776;
                                case Properties::West::TALL:
                                    return 11777;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11778;
                                case Properties::West::LOW:
                                    return 11779;
                                case Properties::West::TALL:
                                    return 11780;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11781;
                                case Properties::West::LOW:
                                    return 11782;
                                case Properties::West::TALL:
                                    return 11783;
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
                                    return 11784;
                                case Properties::West::LOW:
                                    return 11785;
                                case Properties::West::TALL:
                                    return 11786;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11787;
                                case Properties::West::LOW:
                                    return 11788;
                                case Properties::West::TALL:
                                    return 11789;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11790;
                                case Properties::West::LOW:
                                    return 11791;
                                case Properties::West::TALL:
                                    return 11792;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11793;
                                case Properties::West::LOW:
                                    return 11794;
                                case Properties::West::TALL:
                                    return 11795;
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
                                    return 11796;
                                case Properties::West::LOW:
                                    return 11797;
                                case Properties::West::TALL:
                                    return 11798;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11799;
                                case Properties::West::LOW:
                                    return 11800;
                                case Properties::West::TALL:
                                    return 11801;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11802;
                                case Properties::West::LOW:
                                    return 11803;
                                case Properties::West::TALL:
                                    return 11804;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11805;
                                case Properties::West::LOW:
                                    return 11806;
                                case Properties::West::TALL:
                                    return 11807;
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
                                    return 11808;
                                case Properties::West::LOW:
                                    return 11809;
                                case Properties::West::TALL:
                                    return 11810;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11811;
                                case Properties::West::LOW:
                                    return 11812;
                                case Properties::West::TALL:
                                    return 11813;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11814;
                                case Properties::West::LOW:
                                    return 11815;
                                case Properties::West::TALL:
                                    return 11816;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11817;
                                case Properties::West::LOW:
                                    return 11818;
                                case Properties::West::TALL:
                                    return 11819;
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
                                    return 11820;
                                case Properties::West::LOW:
                                    return 11821;
                                case Properties::West::TALL:
                                    return 11822;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11823;
                                case Properties::West::LOW:
                                    return 11824;
                                case Properties::West::TALL:
                                    return 11825;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11826;
                                case Properties::West::LOW:
                                    return 11827;
                                case Properties::West::TALL:
                                    return 11828;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11829;
                                case Properties::West::LOW:
                                    return 11830;
                                case Properties::West::TALL:
                                    return 11831;
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
                                    return 11832;
                                case Properties::West::LOW:
                                    return 11833;
                                case Properties::West::TALL:
                                    return 11834;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11835;
                                case Properties::West::LOW:
                                    return 11836;
                                case Properties::West::TALL:
                                    return 11837;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11838;
                                case Properties::West::LOW:
                                    return 11839;
                                case Properties::West::TALL:
                                    return 11840;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11841;
                                case Properties::West::LOW:
                                    return 11842;
                                case Properties::West::TALL:
                                    return 11843;
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
                                    return 11844;
                                case Properties::West::LOW:
                                    return 11845;
                                case Properties::West::TALL:
                                    return 11846;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11847;
                                case Properties::West::LOW:
                                    return 11848;
                                case Properties::West::TALL:
                                    return 11849;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11850;
                                case Properties::West::LOW:
                                    return 11851;
                                case Properties::West::TALL:
                                    return 11852;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11853;
                                case Properties::West::LOW:
                                    return 11854;
                                case Properties::West::TALL:
                                    return 11855;
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
                                    return 11856;
                                case Properties::West::LOW:
                                    return 11857;
                                case Properties::West::TALL:
                                    return 11858;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11859;
                                case Properties::West::LOW:
                                    return 11860;
                                case Properties::West::TALL:
                                    return 11861;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11862;
                                case Properties::West::LOW:
                                    return 11863;
                                case Properties::West::TALL:
                                    return 11864;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11865;
                                case Properties::West::LOW:
                                    return 11866;
                                case Properties::West::TALL:
                                    return 11867;
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
                                    return 11868;
                                case Properties::West::LOW:
                                    return 11869;
                                case Properties::West::TALL:
                                    return 11870;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11871;
                                case Properties::West::LOW:
                                    return 11872;
                                case Properties::West::TALL:
                                    return 11873;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11874;
                                case Properties::West::LOW:
                                    return 11875;
                                case Properties::West::TALL:
                                    return 11876;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11877;
                                case Properties::West::LOW:
                                    return 11878;
                                case Properties::West::TALL:
                                    return 11879;
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
                                    return 11880;
                                case Properties::West::LOW:
                                    return 11881;
                                case Properties::West::TALL:
                                    return 11882;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11883;
                                case Properties::West::LOW:
                                    return 11884;
                                case Properties::West::TALL:
                                    return 11885;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11886;
                                case Properties::West::LOW:
                                    return 11887;
                                case Properties::West::TALL:
                                    return 11888;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11889;
                                case Properties::West::LOW:
                                    return 11890;
                                case Properties::West::TALL:
                                    return 11891;
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
                                    return 11892;
                                case Properties::West::LOW:
                                    return 11893;
                                case Properties::West::TALL:
                                    return 11894;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11895;
                                case Properties::West::LOW:
                                    return 11896;
                                case Properties::West::TALL:
                                    return 11897;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11898;
                                case Properties::West::LOW:
                                    return 11899;
                                case Properties::West::TALL:
                                    return 11900;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11901;
                                case Properties::West::LOW:
                                    return 11902;
                                case Properties::West::TALL:
                                    return 11903;
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
                                    return 11904;
                                case Properties::West::LOW:
                                    return 11905;
                                case Properties::West::TALL:
                                    return 11906;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11907;
                                case Properties::West::LOW:
                                    return 11908;
                                case Properties::West::TALL:
                                    return 11909;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11910;
                                case Properties::West::LOW:
                                    return 11911;
                                case Properties::West::TALL:
                                    return 11912;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11913;
                                case Properties::West::LOW:
                                    return 11914;
                                case Properties::West::TALL:
                                    return 11915;
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
                                    return 11916;
                                case Properties::West::LOW:
                                    return 11917;
                                case Properties::West::TALL:
                                    return 11918;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11919;
                                case Properties::West::LOW:
                                    return 11920;
                                case Properties::West::TALL:
                                    return 11921;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11922;
                                case Properties::West::LOW:
                                    return 11923;
                                case Properties::West::TALL:
                                    return 11924;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11925;
                                case Properties::West::LOW:
                                    return 11926;
                                case Properties::West::TALL:
                                    return 11927;
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
                                    return 11928;
                                case Properties::West::LOW:
                                    return 11929;
                                case Properties::West::TALL:
                                    return 11930;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11931;
                                case Properties::West::LOW:
                                    return 11932;
                                case Properties::West::TALL:
                                    return 11933;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11934;
                                case Properties::West::LOW:
                                    return 11935;
                                case Properties::West::TALL:
                                    return 11936;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11937;
                                case Properties::West::LOW:
                                    return 11938;
                                case Properties::West::TALL:
                                    return 11939;
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
                                    return 11940;
                                case Properties::West::LOW:
                                    return 11941;
                                case Properties::West::TALL:
                                    return 11942;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11943;
                                case Properties::West::LOW:
                                    return 11944;
                                case Properties::West::TALL:
                                    return 11945;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11946;
                                case Properties::West::LOW:
                                    return 11947;
                                case Properties::West::TALL:
                                    return 11948;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11949;
                                case Properties::West::LOW:
                                    return 11950;
                                case Properties::West::TALL:
                                    return 11951;
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
                                    return 11952;
                                case Properties::West::LOW:
                                    return 11953;
                                case Properties::West::TALL:
                                    return 11954;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11955;
                                case Properties::West::LOW:
                                    return 11956;
                                case Properties::West::TALL:
                                    return 11957;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11958;
                                case Properties::West::LOW:
                                    return 11959;
                                case Properties::West::TALL:
                                    return 11960;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11961;
                                case Properties::West::LOW:
                                    return 11962;
                                case Properties::West::TALL:
                                    return 11963;
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
                                    return 11964;
                                case Properties::West::LOW:
                                    return 11965;
                                case Properties::West::TALL:
                                    return 11966;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11967;
                                case Properties::West::LOW:
                                    return 11968;
                                case Properties::West::TALL:
                                    return 11969;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11970;
                                case Properties::West::LOW:
                                    return 11971;
                                case Properties::West::TALL:
                                    return 11972;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11973;
                                case Properties::West::LOW:
                                    return 11974;
                                case Properties::West::TALL:
                                    return 11975;
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
                                    return 11976;
                                case Properties::West::LOW:
                                    return 11977;
                                case Properties::West::TALL:
                                    return 11978;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11979;
                                case Properties::West::LOW:
                                    return 11980;
                                case Properties::West::TALL:
                                    return 11981;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11982;
                                case Properties::West::LOW:
                                    return 11983;
                                case Properties::West::TALL:
                                    return 11984;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11985;
                                case Properties::West::LOW:
                                    return 11986;
                                case Properties::West::TALL:
                                    return 11987;
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
                                    return 11988;
                                case Properties::West::LOW:
                                    return 11989;
                                case Properties::West::TALL:
                                    return 11990;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11991;
                                case Properties::West::LOW:
                                    return 11992;
                                case Properties::West::TALL:
                                    return 11993;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11994;
                                case Properties::West::LOW:
                                    return 11995;
                                case Properties::West::TALL:
                                    return 11996;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 11997;
                                case Properties::West::LOW:
                                    return 11998;
                                case Properties::West::TALL:
                                    return 11999;
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
                                    return 12000;
                                case Properties::West::LOW:
                                    return 12001;
                                case Properties::West::TALL:
                                    return 12002;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12003;
                                case Properties::West::LOW:
                                    return 12004;
                                case Properties::West::TALL:
                                    return 12005;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12006;
                                case Properties::West::LOW:
                                    return 12007;
                                case Properties::West::TALL:
                                    return 12008;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12009;
                                case Properties::West::LOW:
                                    return 12010;
                                case Properties::West::TALL:
                                    return 12011;
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
                                    return 12012;
                                case Properties::West::LOW:
                                    return 12013;
                                case Properties::West::TALL:
                                    return 12014;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12015;
                                case Properties::West::LOW:
                                    return 12016;
                                case Properties::West::TALL:
                                    return 12017;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12018;
                                case Properties::West::LOW:
                                    return 12019;
                                case Properties::West::TALL:
                                    return 12020;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12021;
                                case Properties::West::LOW:
                                    return 12022;
                                case Properties::West::TALL:
                                    return 12023;
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
                                    return 12024;
                                case Properties::West::LOW:
                                    return 12025;
                                case Properties::West::TALL:
                                    return 12026;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12027;
                                case Properties::West::LOW:
                                    return 12028;
                                case Properties::West::TALL:
                                    return 12029;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12030;
                                case Properties::West::LOW:
                                    return 12031;
                                case Properties::West::TALL:
                                    return 12032;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12033;
                                case Properties::West::LOW:
                                    return 12034;
                                case Properties::West::TALL:
                                    return 12035;
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
                                    return 12036;
                                case Properties::West::LOW:
                                    return 12037;
                                case Properties::West::TALL:
                                    return 12038;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12039;
                                case Properties::West::LOW:
                                    return 12040;
                                case Properties::West::TALL:
                                    return 12041;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12042;
                                case Properties::West::LOW:
                                    return 12043;
                                case Properties::West::TALL:
                                    return 12044;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12045;
                                case Properties::West::LOW:
                                    return 12046;
                                case Properties::West::TALL:
                                    return 12047;
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
                                    return 12048;
                                case Properties::West::LOW:
                                    return 12049;
                                case Properties::West::TALL:
                                    return 12050;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12051;
                                case Properties::West::LOW:
                                    return 12052;
                                case Properties::West::TALL:
                                    return 12053;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12054;
                                case Properties::West::LOW:
                                    return 12055;
                                case Properties::West::TALL:
                                    return 12056;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12057;
                                case Properties::West::LOW:
                                    return 12058;
                                case Properties::West::TALL:
                                    return 12059;
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
                                    return 12060;
                                case Properties::West::LOW:
                                    return 12061;
                                case Properties::West::TALL:
                                    return 12062;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12063;
                                case Properties::West::LOW:
                                    return 12064;
                                case Properties::West::TALL:
                                    return 12065;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12066;
                                case Properties::West::LOW:
                                    return 12067;
                                case Properties::West::TALL:
                                    return 12068;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12069;
                                case Properties::West::LOW:
                                    return 12070;
                                case Properties::West::TALL:
                                    return 12071;
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
