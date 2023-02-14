#include "CobbledDeepslateWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CobbledDeepslateWall {
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
                                    return 19868;
                                case Properties::West::LOW:
                                    return 19869;
                                case Properties::West::TALL:
                                    return 19870;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19871;
                                case Properties::West::LOW:
                                    return 19872;
                                case Properties::West::TALL:
                                    return 19873;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19874;
                                case Properties::West::LOW:
                                    return 19875;
                                case Properties::West::TALL:
                                    return 19876;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19877;
                                case Properties::West::LOW:
                                    return 19878;
                                case Properties::West::TALL:
                                    return 19879;
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
                                    return 19880;
                                case Properties::West::LOW:
                                    return 19881;
                                case Properties::West::TALL:
                                    return 19882;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19883;
                                case Properties::West::LOW:
                                    return 19884;
                                case Properties::West::TALL:
                                    return 19885;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19886;
                                case Properties::West::LOW:
                                    return 19887;
                                case Properties::West::TALL:
                                    return 19888;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19889;
                                case Properties::West::LOW:
                                    return 19890;
                                case Properties::West::TALL:
                                    return 19891;
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
                                    return 19892;
                                case Properties::West::LOW:
                                    return 19893;
                                case Properties::West::TALL:
                                    return 19894;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19895;
                                case Properties::West::LOW:
                                    return 19896;
                                case Properties::West::TALL:
                                    return 19897;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19898;
                                case Properties::West::LOW:
                                    return 19899;
                                case Properties::West::TALL:
                                    return 19900;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19901;
                                case Properties::West::LOW:
                                    return 19902;
                                case Properties::West::TALL:
                                    return 19903;
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
                                    return 19904;
                                case Properties::West::LOW:
                                    return 19905;
                                case Properties::West::TALL:
                                    return 19906;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19907;
                                case Properties::West::LOW:
                                    return 19908;
                                case Properties::West::TALL:
                                    return 19909;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19910;
                                case Properties::West::LOW:
                                    return 19911;
                                case Properties::West::TALL:
                                    return 19912;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19913;
                                case Properties::West::LOW:
                                    return 19914;
                                case Properties::West::TALL:
                                    return 19915;
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
                                    return 19916;
                                case Properties::West::LOW:
                                    return 19917;
                                case Properties::West::TALL:
                                    return 19918;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19919;
                                case Properties::West::LOW:
                                    return 19920;
                                case Properties::West::TALL:
                                    return 19921;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19922;
                                case Properties::West::LOW:
                                    return 19923;
                                case Properties::West::TALL:
                                    return 19924;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19925;
                                case Properties::West::LOW:
                                    return 19926;
                                case Properties::West::TALL:
                                    return 19927;
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
                                    return 19928;
                                case Properties::West::LOW:
                                    return 19929;
                                case Properties::West::TALL:
                                    return 19930;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19931;
                                case Properties::West::LOW:
                                    return 19932;
                                case Properties::West::TALL:
                                    return 19933;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19934;
                                case Properties::West::LOW:
                                    return 19935;
                                case Properties::West::TALL:
                                    return 19936;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19937;
                                case Properties::West::LOW:
                                    return 19938;
                                case Properties::West::TALL:
                                    return 19939;
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
                                    return 19940;
                                case Properties::West::LOW:
                                    return 19941;
                                case Properties::West::TALL:
                                    return 19942;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19943;
                                case Properties::West::LOW:
                                    return 19944;
                                case Properties::West::TALL:
                                    return 19945;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19946;
                                case Properties::West::LOW:
                                    return 19947;
                                case Properties::West::TALL:
                                    return 19948;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19949;
                                case Properties::West::LOW:
                                    return 19950;
                                case Properties::West::TALL:
                                    return 19951;
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
                                    return 19952;
                                case Properties::West::LOW:
                                    return 19953;
                                case Properties::West::TALL:
                                    return 19954;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19955;
                                case Properties::West::LOW:
                                    return 19956;
                                case Properties::West::TALL:
                                    return 19957;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19958;
                                case Properties::West::LOW:
                                    return 19959;
                                case Properties::West::TALL:
                                    return 19960;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19961;
                                case Properties::West::LOW:
                                    return 19962;
                                case Properties::West::TALL:
                                    return 19963;
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
                                    return 19964;
                                case Properties::West::LOW:
                                    return 19965;
                                case Properties::West::TALL:
                                    return 19966;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19967;
                                case Properties::West::LOW:
                                    return 19968;
                                case Properties::West::TALL:
                                    return 19969;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19970;
                                case Properties::West::LOW:
                                    return 19971;
                                case Properties::West::TALL:
                                    return 19972;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19973;
                                case Properties::West::LOW:
                                    return 19974;
                                case Properties::West::TALL:
                                    return 19975;
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
                                    return 19976;
                                case Properties::West::LOW:
                                    return 19977;
                                case Properties::West::TALL:
                                    return 19978;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19979;
                                case Properties::West::LOW:
                                    return 19980;
                                case Properties::West::TALL:
                                    return 19981;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19982;
                                case Properties::West::LOW:
                                    return 19983;
                                case Properties::West::TALL:
                                    return 19984;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19985;
                                case Properties::West::LOW:
                                    return 19986;
                                case Properties::West::TALL:
                                    return 19987;
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
                                    return 19988;
                                case Properties::West::LOW:
                                    return 19989;
                                case Properties::West::TALL:
                                    return 19990;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19991;
                                case Properties::West::LOW:
                                    return 19992;
                                case Properties::West::TALL:
                                    return 19993;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19994;
                                case Properties::West::LOW:
                                    return 19995;
                                case Properties::West::TALL:
                                    return 19996;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 19997;
                                case Properties::West::LOW:
                                    return 19998;
                                case Properties::West::TALL:
                                    return 19999;
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
                                    return 20000;
                                case Properties::West::LOW:
                                    return 20001;
                                case Properties::West::TALL:
                                    return 20002;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20003;
                                case Properties::West::LOW:
                                    return 20004;
                                case Properties::West::TALL:
                                    return 20005;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20006;
                                case Properties::West::LOW:
                                    return 20007;
                                case Properties::West::TALL:
                                    return 20008;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20009;
                                case Properties::West::LOW:
                                    return 20010;
                                case Properties::West::TALL:
                                    return 20011;
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
                                    return 20012;
                                case Properties::West::LOW:
                                    return 20013;
                                case Properties::West::TALL:
                                    return 20014;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20015;
                                case Properties::West::LOW:
                                    return 20016;
                                case Properties::West::TALL:
                                    return 20017;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20018;
                                case Properties::West::LOW:
                                    return 20019;
                                case Properties::West::TALL:
                                    return 20020;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20021;
                                case Properties::West::LOW:
                                    return 20022;
                                case Properties::West::TALL:
                                    return 20023;
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
                                    return 20024;
                                case Properties::West::LOW:
                                    return 20025;
                                case Properties::West::TALL:
                                    return 20026;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20027;
                                case Properties::West::LOW:
                                    return 20028;
                                case Properties::West::TALL:
                                    return 20029;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20030;
                                case Properties::West::LOW:
                                    return 20031;
                                case Properties::West::TALL:
                                    return 20032;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20033;
                                case Properties::West::LOW:
                                    return 20034;
                                case Properties::West::TALL:
                                    return 20035;
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
                                    return 20036;
                                case Properties::West::LOW:
                                    return 20037;
                                case Properties::West::TALL:
                                    return 20038;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20039;
                                case Properties::West::LOW:
                                    return 20040;
                                case Properties::West::TALL:
                                    return 20041;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20042;
                                case Properties::West::LOW:
                                    return 20043;
                                case Properties::West::TALL:
                                    return 20044;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20045;
                                case Properties::West::LOW:
                                    return 20046;
                                case Properties::West::TALL:
                                    return 20047;
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
                                    return 20048;
                                case Properties::West::LOW:
                                    return 20049;
                                case Properties::West::TALL:
                                    return 20050;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20051;
                                case Properties::West::LOW:
                                    return 20052;
                                case Properties::West::TALL:
                                    return 20053;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20054;
                                case Properties::West::LOW:
                                    return 20055;
                                case Properties::West::TALL:
                                    return 20056;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20057;
                                case Properties::West::LOW:
                                    return 20058;
                                case Properties::West::TALL:
                                    return 20059;
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
                                    return 20060;
                                case Properties::West::LOW:
                                    return 20061;
                                case Properties::West::TALL:
                                    return 20062;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20063;
                                case Properties::West::LOW:
                                    return 20064;
                                case Properties::West::TALL:
                                    return 20065;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20066;
                                case Properties::West::LOW:
                                    return 20067;
                                case Properties::West::TALL:
                                    return 20068;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20069;
                                case Properties::West::LOW:
                                    return 20070;
                                case Properties::West::TALL:
                                    return 20071;
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
                                    return 20072;
                                case Properties::West::LOW:
                                    return 20073;
                                case Properties::West::TALL:
                                    return 20074;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20075;
                                case Properties::West::LOW:
                                    return 20076;
                                case Properties::West::TALL:
                                    return 20077;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20078;
                                case Properties::West::LOW:
                                    return 20079;
                                case Properties::West::TALL:
                                    return 20080;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20081;
                                case Properties::West::LOW:
                                    return 20082;
                                case Properties::West::TALL:
                                    return 20083;
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
                                    return 20084;
                                case Properties::West::LOW:
                                    return 20085;
                                case Properties::West::TALL:
                                    return 20086;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20087;
                                case Properties::West::LOW:
                                    return 20088;
                                case Properties::West::TALL:
                                    return 20089;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20090;
                                case Properties::West::LOW:
                                    return 20091;
                                case Properties::West::TALL:
                                    return 20092;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20093;
                                case Properties::West::LOW:
                                    return 20094;
                                case Properties::West::TALL:
                                    return 20095;
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
                                    return 20096;
                                case Properties::West::LOW:
                                    return 20097;
                                case Properties::West::TALL:
                                    return 20098;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20099;
                                case Properties::West::LOW:
                                    return 20100;
                                case Properties::West::TALL:
                                    return 20101;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20102;
                                case Properties::West::LOW:
                                    return 20103;
                                case Properties::West::TALL:
                                    return 20104;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20105;
                                case Properties::West::LOW:
                                    return 20106;
                                case Properties::West::TALL:
                                    return 20107;
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
                                    return 20108;
                                case Properties::West::LOW:
                                    return 20109;
                                case Properties::West::TALL:
                                    return 20110;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20111;
                                case Properties::West::LOW:
                                    return 20112;
                                case Properties::West::TALL:
                                    return 20113;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20114;
                                case Properties::West::LOW:
                                    return 20115;
                                case Properties::West::TALL:
                                    return 20116;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20117;
                                case Properties::West::LOW:
                                    return 20118;
                                case Properties::West::TALL:
                                    return 20119;
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
                                    return 20120;
                                case Properties::West::LOW:
                                    return 20121;
                                case Properties::West::TALL:
                                    return 20122;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20123;
                                case Properties::West::LOW:
                                    return 20124;
                                case Properties::West::TALL:
                                    return 20125;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20126;
                                case Properties::West::LOW:
                                    return 20127;
                                case Properties::West::TALL:
                                    return 20128;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20129;
                                case Properties::West::LOW:
                                    return 20130;
                                case Properties::West::TALL:
                                    return 20131;
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
                                    return 20132;
                                case Properties::West::LOW:
                                    return 20133;
                                case Properties::West::TALL:
                                    return 20134;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20135;
                                case Properties::West::LOW:
                                    return 20136;
                                case Properties::West::TALL:
                                    return 20137;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20138;
                                case Properties::West::LOW:
                                    return 20139;
                                case Properties::West::TALL:
                                    return 20140;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20141;
                                case Properties::West::LOW:
                                    return 20142;
                                case Properties::West::TALL:
                                    return 20143;
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
                                    return 20144;
                                case Properties::West::LOW:
                                    return 20145;
                                case Properties::West::TALL:
                                    return 20146;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20147;
                                case Properties::West::LOW:
                                    return 20148;
                                case Properties::West::TALL:
                                    return 20149;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20150;
                                case Properties::West::LOW:
                                    return 20151;
                                case Properties::West::TALL:
                                    return 20152;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20153;
                                case Properties::West::LOW:
                                    return 20154;
                                case Properties::West::TALL:
                                    return 20155;
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
                                    return 20156;
                                case Properties::West::LOW:
                                    return 20157;
                                case Properties::West::TALL:
                                    return 20158;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20159;
                                case Properties::West::LOW:
                                    return 20160;
                                case Properties::West::TALL:
                                    return 20161;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20162;
                                case Properties::West::LOW:
                                    return 20163;
                                case Properties::West::TALL:
                                    return 20164;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20165;
                                case Properties::West::LOW:
                                    return 20166;
                                case Properties::West::TALL:
                                    return 20167;
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
                                    return 20168;
                                case Properties::West::LOW:
                                    return 20169;
                                case Properties::West::TALL:
                                    return 20170;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20171;
                                case Properties::West::LOW:
                                    return 20172;
                                case Properties::West::TALL:
                                    return 20173;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20174;
                                case Properties::West::LOW:
                                    return 20175;
                                case Properties::West::TALL:
                                    return 20176;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20177;
                                case Properties::West::LOW:
                                    return 20178;
                                case Properties::West::TALL:
                                    return 20179;
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
                                    return 20180;
                                case Properties::West::LOW:
                                    return 20181;
                                case Properties::West::TALL:
                                    return 20182;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20183;
                                case Properties::West::LOW:
                                    return 20184;
                                case Properties::West::TALL:
                                    return 20185;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20186;
                                case Properties::West::LOW:
                                    return 20187;
                                case Properties::West::TALL:
                                    return 20188;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 20189;
                                case Properties::West::LOW:
                                    return 20190;
                                case Properties::West::TALL:
                                    return 20191;
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
