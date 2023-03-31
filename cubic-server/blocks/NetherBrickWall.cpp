#include "NetherBrickWall.hpp"
#include <stdexcept>

namespace Blocks {
namespace NetherBrickWall {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west)
{
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
                            return 15800;
                        case Properties::West::LOW:
                            return 15801;
                        case Properties::West::TALL:
                            return 15802;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15803;
                        case Properties::West::LOW:
                            return 15804;
                        case Properties::West::TALL:
                            return 15805;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15806;
                        case Properties::West::LOW:
                            return 15807;
                        case Properties::West::TALL:
                            return 15808;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15809;
                        case Properties::West::LOW:
                            return 15810;
                        case Properties::West::TALL:
                            return 15811;
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
                            return 15812;
                        case Properties::West::LOW:
                            return 15813;
                        case Properties::West::TALL:
                            return 15814;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15815;
                        case Properties::West::LOW:
                            return 15816;
                        case Properties::West::TALL:
                            return 15817;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15818;
                        case Properties::West::LOW:
                            return 15819;
                        case Properties::West::TALL:
                            return 15820;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15821;
                        case Properties::West::LOW:
                            return 15822;
                        case Properties::West::TALL:
                            return 15823;
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
                            return 15824;
                        case Properties::West::LOW:
                            return 15825;
                        case Properties::West::TALL:
                            return 15826;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15827;
                        case Properties::West::LOW:
                            return 15828;
                        case Properties::West::TALL:
                            return 15829;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15830;
                        case Properties::West::LOW:
                            return 15831;
                        case Properties::West::TALL:
                            return 15832;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15833;
                        case Properties::West::LOW:
                            return 15834;
                        case Properties::West::TALL:
                            return 15835;
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
                            return 15836;
                        case Properties::West::LOW:
                            return 15837;
                        case Properties::West::TALL:
                            return 15838;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15839;
                        case Properties::West::LOW:
                            return 15840;
                        case Properties::West::TALL:
                            return 15841;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15842;
                        case Properties::West::LOW:
                            return 15843;
                        case Properties::West::TALL:
                            return 15844;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15845;
                        case Properties::West::LOW:
                            return 15846;
                        case Properties::West::TALL:
                            return 15847;
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
                            return 15848;
                        case Properties::West::LOW:
                            return 15849;
                        case Properties::West::TALL:
                            return 15850;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15851;
                        case Properties::West::LOW:
                            return 15852;
                        case Properties::West::TALL:
                            return 15853;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15854;
                        case Properties::West::LOW:
                            return 15855;
                        case Properties::West::TALL:
                            return 15856;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15857;
                        case Properties::West::LOW:
                            return 15858;
                        case Properties::West::TALL:
                            return 15859;
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
                            return 15860;
                        case Properties::West::LOW:
                            return 15861;
                        case Properties::West::TALL:
                            return 15862;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15863;
                        case Properties::West::LOW:
                            return 15864;
                        case Properties::West::TALL:
                            return 15865;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15866;
                        case Properties::West::LOW:
                            return 15867;
                        case Properties::West::TALL:
                            return 15868;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15869;
                        case Properties::West::LOW:
                            return 15870;
                        case Properties::West::TALL:
                            return 15871;
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
                            return 15872;
                        case Properties::West::LOW:
                            return 15873;
                        case Properties::West::TALL:
                            return 15874;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15875;
                        case Properties::West::LOW:
                            return 15876;
                        case Properties::West::TALL:
                            return 15877;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15878;
                        case Properties::West::LOW:
                            return 15879;
                        case Properties::West::TALL:
                            return 15880;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15881;
                        case Properties::West::LOW:
                            return 15882;
                        case Properties::West::TALL:
                            return 15883;
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
                            return 15884;
                        case Properties::West::LOW:
                            return 15885;
                        case Properties::West::TALL:
                            return 15886;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15887;
                        case Properties::West::LOW:
                            return 15888;
                        case Properties::West::TALL:
                            return 15889;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15890;
                        case Properties::West::LOW:
                            return 15891;
                        case Properties::West::TALL:
                            return 15892;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15893;
                        case Properties::West::LOW:
                            return 15894;
                        case Properties::West::TALL:
                            return 15895;
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
                            return 15896;
                        case Properties::West::LOW:
                            return 15897;
                        case Properties::West::TALL:
                            return 15898;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15899;
                        case Properties::West::LOW:
                            return 15900;
                        case Properties::West::TALL:
                            return 15901;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15902;
                        case Properties::West::LOW:
                            return 15903;
                        case Properties::West::TALL:
                            return 15904;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15905;
                        case Properties::West::LOW:
                            return 15906;
                        case Properties::West::TALL:
                            return 15907;
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
                            return 15908;
                        case Properties::West::LOW:
                            return 15909;
                        case Properties::West::TALL:
                            return 15910;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15911;
                        case Properties::West::LOW:
                            return 15912;
                        case Properties::West::TALL:
                            return 15913;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15914;
                        case Properties::West::LOW:
                            return 15915;
                        case Properties::West::TALL:
                            return 15916;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15917;
                        case Properties::West::LOW:
                            return 15918;
                        case Properties::West::TALL:
                            return 15919;
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
                            return 15920;
                        case Properties::West::LOW:
                            return 15921;
                        case Properties::West::TALL:
                            return 15922;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15923;
                        case Properties::West::LOW:
                            return 15924;
                        case Properties::West::TALL:
                            return 15925;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15926;
                        case Properties::West::LOW:
                            return 15927;
                        case Properties::West::TALL:
                            return 15928;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15929;
                        case Properties::West::LOW:
                            return 15930;
                        case Properties::West::TALL:
                            return 15931;
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
                            return 15932;
                        case Properties::West::LOW:
                            return 15933;
                        case Properties::West::TALL:
                            return 15934;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15935;
                        case Properties::West::LOW:
                            return 15936;
                        case Properties::West::TALL:
                            return 15937;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15938;
                        case Properties::West::LOW:
                            return 15939;
                        case Properties::West::TALL:
                            return 15940;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15941;
                        case Properties::West::LOW:
                            return 15942;
                        case Properties::West::TALL:
                            return 15943;
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
                            return 15944;
                        case Properties::West::LOW:
                            return 15945;
                        case Properties::West::TALL:
                            return 15946;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15947;
                        case Properties::West::LOW:
                            return 15948;
                        case Properties::West::TALL:
                            return 15949;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15950;
                        case Properties::West::LOW:
                            return 15951;
                        case Properties::West::TALL:
                            return 15952;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15953;
                        case Properties::West::LOW:
                            return 15954;
                        case Properties::West::TALL:
                            return 15955;
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
                            return 15956;
                        case Properties::West::LOW:
                            return 15957;
                        case Properties::West::TALL:
                            return 15958;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15959;
                        case Properties::West::LOW:
                            return 15960;
                        case Properties::West::TALL:
                            return 15961;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15962;
                        case Properties::West::LOW:
                            return 15963;
                        case Properties::West::TALL:
                            return 15964;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15965;
                        case Properties::West::LOW:
                            return 15966;
                        case Properties::West::TALL:
                            return 15967;
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
                            return 15968;
                        case Properties::West::LOW:
                            return 15969;
                        case Properties::West::TALL:
                            return 15970;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15971;
                        case Properties::West::LOW:
                            return 15972;
                        case Properties::West::TALL:
                            return 15973;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15974;
                        case Properties::West::LOW:
                            return 15975;
                        case Properties::West::TALL:
                            return 15976;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15977;
                        case Properties::West::LOW:
                            return 15978;
                        case Properties::West::TALL:
                            return 15979;
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
                            return 15980;
                        case Properties::West::LOW:
                            return 15981;
                        case Properties::West::TALL:
                            return 15982;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15983;
                        case Properties::West::LOW:
                            return 15984;
                        case Properties::West::TALL:
                            return 15985;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15986;
                        case Properties::West::LOW:
                            return 15987;
                        case Properties::West::TALL:
                            return 15988;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15989;
                        case Properties::West::LOW:
                            return 15990;
                        case Properties::West::TALL:
                            return 15991;
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
                            return 15992;
                        case Properties::West::LOW:
                            return 15993;
                        case Properties::West::TALL:
                            return 15994;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15995;
                        case Properties::West::LOW:
                            return 15996;
                        case Properties::West::TALL:
                            return 15997;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 15998;
                        case Properties::West::LOW:
                            return 15999;
                        case Properties::West::TALL:
                            return 16000;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16001;
                        case Properties::West::LOW:
                            return 16002;
                        case Properties::West::TALL:
                            return 16003;
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
                            return 16004;
                        case Properties::West::LOW:
                            return 16005;
                        case Properties::West::TALL:
                            return 16006;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16007;
                        case Properties::West::LOW:
                            return 16008;
                        case Properties::West::TALL:
                            return 16009;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16010;
                        case Properties::West::LOW:
                            return 16011;
                        case Properties::West::TALL:
                            return 16012;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16013;
                        case Properties::West::LOW:
                            return 16014;
                        case Properties::West::TALL:
                            return 16015;
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
                            return 16016;
                        case Properties::West::LOW:
                            return 16017;
                        case Properties::West::TALL:
                            return 16018;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16019;
                        case Properties::West::LOW:
                            return 16020;
                        case Properties::West::TALL:
                            return 16021;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16022;
                        case Properties::West::LOW:
                            return 16023;
                        case Properties::West::TALL:
                            return 16024;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16025;
                        case Properties::West::LOW:
                            return 16026;
                        case Properties::West::TALL:
                            return 16027;
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
                            return 16028;
                        case Properties::West::LOW:
                            return 16029;
                        case Properties::West::TALL:
                            return 16030;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16031;
                        case Properties::West::LOW:
                            return 16032;
                        case Properties::West::TALL:
                            return 16033;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16034;
                        case Properties::West::LOW:
                            return 16035;
                        case Properties::West::TALL:
                            return 16036;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16037;
                        case Properties::West::LOW:
                            return 16038;
                        case Properties::West::TALL:
                            return 16039;
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
                            return 16040;
                        case Properties::West::LOW:
                            return 16041;
                        case Properties::West::TALL:
                            return 16042;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16043;
                        case Properties::West::LOW:
                            return 16044;
                        case Properties::West::TALL:
                            return 16045;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16046;
                        case Properties::West::LOW:
                            return 16047;
                        case Properties::West::TALL:
                            return 16048;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16049;
                        case Properties::West::LOW:
                            return 16050;
                        case Properties::West::TALL:
                            return 16051;
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
                            return 16052;
                        case Properties::West::LOW:
                            return 16053;
                        case Properties::West::TALL:
                            return 16054;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16055;
                        case Properties::West::LOW:
                            return 16056;
                        case Properties::West::TALL:
                            return 16057;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16058;
                        case Properties::West::LOW:
                            return 16059;
                        case Properties::West::TALL:
                            return 16060;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16061;
                        case Properties::West::LOW:
                            return 16062;
                        case Properties::West::TALL:
                            return 16063;
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
                            return 16064;
                        case Properties::West::LOW:
                            return 16065;
                        case Properties::West::TALL:
                            return 16066;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16067;
                        case Properties::West::LOW:
                            return 16068;
                        case Properties::West::TALL:
                            return 16069;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16070;
                        case Properties::West::LOW:
                            return 16071;
                        case Properties::West::TALL:
                            return 16072;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16073;
                        case Properties::West::LOW:
                            return 16074;
                        case Properties::West::TALL:
                            return 16075;
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
                            return 16076;
                        case Properties::West::LOW:
                            return 16077;
                        case Properties::West::TALL:
                            return 16078;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16079;
                        case Properties::West::LOW:
                            return 16080;
                        case Properties::West::TALL:
                            return 16081;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16082;
                        case Properties::West::LOW:
                            return 16083;
                        case Properties::West::TALL:
                            return 16084;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16085;
                        case Properties::West::LOW:
                            return 16086;
                        case Properties::West::TALL:
                            return 16087;
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
                            return 16088;
                        case Properties::West::LOW:
                            return 16089;
                        case Properties::West::TALL:
                            return 16090;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16091;
                        case Properties::West::LOW:
                            return 16092;
                        case Properties::West::TALL:
                            return 16093;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16094;
                        case Properties::West::LOW:
                            return 16095;
                        case Properties::West::TALL:
                            return 16096;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16097;
                        case Properties::West::LOW:
                            return 16098;
                        case Properties::West::TALL:
                            return 16099;
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
                            return 16100;
                        case Properties::West::LOW:
                            return 16101;
                        case Properties::West::TALL:
                            return 16102;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16103;
                        case Properties::West::LOW:
                            return 16104;
                        case Properties::West::TALL:
                            return 16105;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16106;
                        case Properties::West::LOW:
                            return 16107;
                        case Properties::West::TALL:
                            return 16108;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16109;
                        case Properties::West::LOW:
                            return 16110;
                        case Properties::West::TALL:
                            return 16111;
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
                            return 16112;
                        case Properties::West::LOW:
                            return 16113;
                        case Properties::West::TALL:
                            return 16114;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16115;
                        case Properties::West::LOW:
                            return 16116;
                        case Properties::West::TALL:
                            return 16117;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16118;
                        case Properties::West::LOW:
                            return 16119;
                        case Properties::West::TALL:
                            return 16120;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 16121;
                        case Properties::West::LOW:
                            return 16122;
                        case Properties::West::TALL:
                            return 16123;
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
