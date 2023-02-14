#include "NetherBrickWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace NetherBrickWall {
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
                                    return 14016;
                                case Properties::West::LOW:
                                    return 14017;
                                case Properties::West::TALL:
                                    return 14018;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14019;
                                case Properties::West::LOW:
                                    return 14020;
                                case Properties::West::TALL:
                                    return 14021;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14022;
                                case Properties::West::LOW:
                                    return 14023;
                                case Properties::West::TALL:
                                    return 14024;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14025;
                                case Properties::West::LOW:
                                    return 14026;
                                case Properties::West::TALL:
                                    return 14027;
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
                                    return 14028;
                                case Properties::West::LOW:
                                    return 14029;
                                case Properties::West::TALL:
                                    return 14030;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14031;
                                case Properties::West::LOW:
                                    return 14032;
                                case Properties::West::TALL:
                                    return 14033;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14034;
                                case Properties::West::LOW:
                                    return 14035;
                                case Properties::West::TALL:
                                    return 14036;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14037;
                                case Properties::West::LOW:
                                    return 14038;
                                case Properties::West::TALL:
                                    return 14039;
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
                                    return 14040;
                                case Properties::West::LOW:
                                    return 14041;
                                case Properties::West::TALL:
                                    return 14042;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14043;
                                case Properties::West::LOW:
                                    return 14044;
                                case Properties::West::TALL:
                                    return 14045;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14046;
                                case Properties::West::LOW:
                                    return 14047;
                                case Properties::West::TALL:
                                    return 14048;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14049;
                                case Properties::West::LOW:
                                    return 14050;
                                case Properties::West::TALL:
                                    return 14051;
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
                                    return 14052;
                                case Properties::West::LOW:
                                    return 14053;
                                case Properties::West::TALL:
                                    return 14054;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14055;
                                case Properties::West::LOW:
                                    return 14056;
                                case Properties::West::TALL:
                                    return 14057;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14058;
                                case Properties::West::LOW:
                                    return 14059;
                                case Properties::West::TALL:
                                    return 14060;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14061;
                                case Properties::West::LOW:
                                    return 14062;
                                case Properties::West::TALL:
                                    return 14063;
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
                                    return 14064;
                                case Properties::West::LOW:
                                    return 14065;
                                case Properties::West::TALL:
                                    return 14066;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14067;
                                case Properties::West::LOW:
                                    return 14068;
                                case Properties::West::TALL:
                                    return 14069;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14070;
                                case Properties::West::LOW:
                                    return 14071;
                                case Properties::West::TALL:
                                    return 14072;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14073;
                                case Properties::West::LOW:
                                    return 14074;
                                case Properties::West::TALL:
                                    return 14075;
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
                                    return 14076;
                                case Properties::West::LOW:
                                    return 14077;
                                case Properties::West::TALL:
                                    return 14078;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14079;
                                case Properties::West::LOW:
                                    return 14080;
                                case Properties::West::TALL:
                                    return 14081;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14082;
                                case Properties::West::LOW:
                                    return 14083;
                                case Properties::West::TALL:
                                    return 14084;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14085;
                                case Properties::West::LOW:
                                    return 14086;
                                case Properties::West::TALL:
                                    return 14087;
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
                                    return 14088;
                                case Properties::West::LOW:
                                    return 14089;
                                case Properties::West::TALL:
                                    return 14090;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14091;
                                case Properties::West::LOW:
                                    return 14092;
                                case Properties::West::TALL:
                                    return 14093;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14094;
                                case Properties::West::LOW:
                                    return 14095;
                                case Properties::West::TALL:
                                    return 14096;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14097;
                                case Properties::West::LOW:
                                    return 14098;
                                case Properties::West::TALL:
                                    return 14099;
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
                                    return 14100;
                                case Properties::West::LOW:
                                    return 14101;
                                case Properties::West::TALL:
                                    return 14102;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14103;
                                case Properties::West::LOW:
                                    return 14104;
                                case Properties::West::TALL:
                                    return 14105;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14106;
                                case Properties::West::LOW:
                                    return 14107;
                                case Properties::West::TALL:
                                    return 14108;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14109;
                                case Properties::West::LOW:
                                    return 14110;
                                case Properties::West::TALL:
                                    return 14111;
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
                                    return 14112;
                                case Properties::West::LOW:
                                    return 14113;
                                case Properties::West::TALL:
                                    return 14114;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14115;
                                case Properties::West::LOW:
                                    return 14116;
                                case Properties::West::TALL:
                                    return 14117;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14118;
                                case Properties::West::LOW:
                                    return 14119;
                                case Properties::West::TALL:
                                    return 14120;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14121;
                                case Properties::West::LOW:
                                    return 14122;
                                case Properties::West::TALL:
                                    return 14123;
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
                                    return 14124;
                                case Properties::West::LOW:
                                    return 14125;
                                case Properties::West::TALL:
                                    return 14126;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14127;
                                case Properties::West::LOW:
                                    return 14128;
                                case Properties::West::TALL:
                                    return 14129;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14130;
                                case Properties::West::LOW:
                                    return 14131;
                                case Properties::West::TALL:
                                    return 14132;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14133;
                                case Properties::West::LOW:
                                    return 14134;
                                case Properties::West::TALL:
                                    return 14135;
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
                                    return 14136;
                                case Properties::West::LOW:
                                    return 14137;
                                case Properties::West::TALL:
                                    return 14138;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14139;
                                case Properties::West::LOW:
                                    return 14140;
                                case Properties::West::TALL:
                                    return 14141;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14142;
                                case Properties::West::LOW:
                                    return 14143;
                                case Properties::West::TALL:
                                    return 14144;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14145;
                                case Properties::West::LOW:
                                    return 14146;
                                case Properties::West::TALL:
                                    return 14147;
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
                                    return 14148;
                                case Properties::West::LOW:
                                    return 14149;
                                case Properties::West::TALL:
                                    return 14150;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14151;
                                case Properties::West::LOW:
                                    return 14152;
                                case Properties::West::TALL:
                                    return 14153;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14154;
                                case Properties::West::LOW:
                                    return 14155;
                                case Properties::West::TALL:
                                    return 14156;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14157;
                                case Properties::West::LOW:
                                    return 14158;
                                case Properties::West::TALL:
                                    return 14159;
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
                                    return 14160;
                                case Properties::West::LOW:
                                    return 14161;
                                case Properties::West::TALL:
                                    return 14162;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14163;
                                case Properties::West::LOW:
                                    return 14164;
                                case Properties::West::TALL:
                                    return 14165;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14166;
                                case Properties::West::LOW:
                                    return 14167;
                                case Properties::West::TALL:
                                    return 14168;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14169;
                                case Properties::West::LOW:
                                    return 14170;
                                case Properties::West::TALL:
                                    return 14171;
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
                                    return 14172;
                                case Properties::West::LOW:
                                    return 14173;
                                case Properties::West::TALL:
                                    return 14174;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14175;
                                case Properties::West::LOW:
                                    return 14176;
                                case Properties::West::TALL:
                                    return 14177;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14178;
                                case Properties::West::LOW:
                                    return 14179;
                                case Properties::West::TALL:
                                    return 14180;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14181;
                                case Properties::West::LOW:
                                    return 14182;
                                case Properties::West::TALL:
                                    return 14183;
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
                                    return 14184;
                                case Properties::West::LOW:
                                    return 14185;
                                case Properties::West::TALL:
                                    return 14186;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14187;
                                case Properties::West::LOW:
                                    return 14188;
                                case Properties::West::TALL:
                                    return 14189;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14190;
                                case Properties::West::LOW:
                                    return 14191;
                                case Properties::West::TALL:
                                    return 14192;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14193;
                                case Properties::West::LOW:
                                    return 14194;
                                case Properties::West::TALL:
                                    return 14195;
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
                                    return 14196;
                                case Properties::West::LOW:
                                    return 14197;
                                case Properties::West::TALL:
                                    return 14198;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14199;
                                case Properties::West::LOW:
                                    return 14200;
                                case Properties::West::TALL:
                                    return 14201;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14202;
                                case Properties::West::LOW:
                                    return 14203;
                                case Properties::West::TALL:
                                    return 14204;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14205;
                                case Properties::West::LOW:
                                    return 14206;
                                case Properties::West::TALL:
                                    return 14207;
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
                                    return 14208;
                                case Properties::West::LOW:
                                    return 14209;
                                case Properties::West::TALL:
                                    return 14210;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14211;
                                case Properties::West::LOW:
                                    return 14212;
                                case Properties::West::TALL:
                                    return 14213;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14214;
                                case Properties::West::LOW:
                                    return 14215;
                                case Properties::West::TALL:
                                    return 14216;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14217;
                                case Properties::West::LOW:
                                    return 14218;
                                case Properties::West::TALL:
                                    return 14219;
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
                                    return 14220;
                                case Properties::West::LOW:
                                    return 14221;
                                case Properties::West::TALL:
                                    return 14222;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14223;
                                case Properties::West::LOW:
                                    return 14224;
                                case Properties::West::TALL:
                                    return 14225;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14226;
                                case Properties::West::LOW:
                                    return 14227;
                                case Properties::West::TALL:
                                    return 14228;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14229;
                                case Properties::West::LOW:
                                    return 14230;
                                case Properties::West::TALL:
                                    return 14231;
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
                                    return 14232;
                                case Properties::West::LOW:
                                    return 14233;
                                case Properties::West::TALL:
                                    return 14234;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14235;
                                case Properties::West::LOW:
                                    return 14236;
                                case Properties::West::TALL:
                                    return 14237;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14238;
                                case Properties::West::LOW:
                                    return 14239;
                                case Properties::West::TALL:
                                    return 14240;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14241;
                                case Properties::West::LOW:
                                    return 14242;
                                case Properties::West::TALL:
                                    return 14243;
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
                                    return 14244;
                                case Properties::West::LOW:
                                    return 14245;
                                case Properties::West::TALL:
                                    return 14246;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14247;
                                case Properties::West::LOW:
                                    return 14248;
                                case Properties::West::TALL:
                                    return 14249;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14250;
                                case Properties::West::LOW:
                                    return 14251;
                                case Properties::West::TALL:
                                    return 14252;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14253;
                                case Properties::West::LOW:
                                    return 14254;
                                case Properties::West::TALL:
                                    return 14255;
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
                                    return 14256;
                                case Properties::West::LOW:
                                    return 14257;
                                case Properties::West::TALL:
                                    return 14258;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14259;
                                case Properties::West::LOW:
                                    return 14260;
                                case Properties::West::TALL:
                                    return 14261;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14262;
                                case Properties::West::LOW:
                                    return 14263;
                                case Properties::West::TALL:
                                    return 14264;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14265;
                                case Properties::West::LOW:
                                    return 14266;
                                case Properties::West::TALL:
                                    return 14267;
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
                                    return 14268;
                                case Properties::West::LOW:
                                    return 14269;
                                case Properties::West::TALL:
                                    return 14270;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14271;
                                case Properties::West::LOW:
                                    return 14272;
                                case Properties::West::TALL:
                                    return 14273;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14274;
                                case Properties::West::LOW:
                                    return 14275;
                                case Properties::West::TALL:
                                    return 14276;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14277;
                                case Properties::West::LOW:
                                    return 14278;
                                case Properties::West::TALL:
                                    return 14279;
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
                                    return 14280;
                                case Properties::West::LOW:
                                    return 14281;
                                case Properties::West::TALL:
                                    return 14282;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14283;
                                case Properties::West::LOW:
                                    return 14284;
                                case Properties::West::TALL:
                                    return 14285;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14286;
                                case Properties::West::LOW:
                                    return 14287;
                                case Properties::West::TALL:
                                    return 14288;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14289;
                                case Properties::West::LOW:
                                    return 14290;
                                case Properties::West::TALL:
                                    return 14291;
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
                                    return 14292;
                                case Properties::West::LOW:
                                    return 14293;
                                case Properties::West::TALL:
                                    return 14294;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14295;
                                case Properties::West::LOW:
                                    return 14296;
                                case Properties::West::TALL:
                                    return 14297;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14298;
                                case Properties::West::LOW:
                                    return 14299;
                                case Properties::West::TALL:
                                    return 14300;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14301;
                                case Properties::West::LOW:
                                    return 14302;
                                case Properties::West::TALL:
                                    return 14303;
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
                                    return 14304;
                                case Properties::West::LOW:
                                    return 14305;
                                case Properties::West::TALL:
                                    return 14306;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14307;
                                case Properties::West::LOW:
                                    return 14308;
                                case Properties::West::TALL:
                                    return 14309;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14310;
                                case Properties::West::LOW:
                                    return 14311;
                                case Properties::West::TALL:
                                    return 14312;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14313;
                                case Properties::West::LOW:
                                    return 14314;
                                case Properties::West::TALL:
                                    return 14315;
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
                                    return 14316;
                                case Properties::West::LOW:
                                    return 14317;
                                case Properties::West::TALL:
                                    return 14318;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14319;
                                case Properties::West::LOW:
                                    return 14320;
                                case Properties::West::TALL:
                                    return 14321;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14322;
                                case Properties::West::LOW:
                                    return 14323;
                                case Properties::West::TALL:
                                    return 14324;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14325;
                                case Properties::West::LOW:
                                    return 14326;
                                case Properties::West::TALL:
                                    return 14327;
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
                                    return 14328;
                                case Properties::West::LOW:
                                    return 14329;
                                case Properties::West::TALL:
                                    return 14330;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14331;
                                case Properties::West::LOW:
                                    return 14332;
                                case Properties::West::TALL:
                                    return 14333;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14334;
                                case Properties::West::LOW:
                                    return 14335;
                                case Properties::West::TALL:
                                    return 14336;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 14337;
                                case Properties::West::LOW:
                                    return 14338;
                                case Properties::West::TALL:
                                    return 14339;
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
