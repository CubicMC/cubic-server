#include "CobblestoneWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CobblestoneWall {
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
                                    return 6249;
                                case Properties::West::LOW:
                                    return 6250;
                                case Properties::West::TALL:
                                    return 6251;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6252;
                                case Properties::West::LOW:
                                    return 6253;
                                case Properties::West::TALL:
                                    return 6254;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6255;
                                case Properties::West::LOW:
                                    return 6256;
                                case Properties::West::TALL:
                                    return 6257;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6258;
                                case Properties::West::LOW:
                                    return 6259;
                                case Properties::West::TALL:
                                    return 6260;
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
                                    return 6261;
                                case Properties::West::LOW:
                                    return 6262;
                                case Properties::West::TALL:
                                    return 6263;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6264;
                                case Properties::West::LOW:
                                    return 6265;
                                case Properties::West::TALL:
                                    return 6266;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6267;
                                case Properties::West::LOW:
                                    return 6268;
                                case Properties::West::TALL:
                                    return 6269;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6270;
                                case Properties::West::LOW:
                                    return 6271;
                                case Properties::West::TALL:
                                    return 6272;
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
                                    return 6273;
                                case Properties::West::LOW:
                                    return 6274;
                                case Properties::West::TALL:
                                    return 6275;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6276;
                                case Properties::West::LOW:
                                    return 6277;
                                case Properties::West::TALL:
                                    return 6278;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6279;
                                case Properties::West::LOW:
                                    return 6280;
                                case Properties::West::TALL:
                                    return 6281;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6282;
                                case Properties::West::LOW:
                                    return 6283;
                                case Properties::West::TALL:
                                    return 6284;
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
                                    return 6285;
                                case Properties::West::LOW:
                                    return 6286;
                                case Properties::West::TALL:
                                    return 6287;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6288;
                                case Properties::West::LOW:
                                    return 6289;
                                case Properties::West::TALL:
                                    return 6290;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6291;
                                case Properties::West::LOW:
                                    return 6292;
                                case Properties::West::TALL:
                                    return 6293;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6294;
                                case Properties::West::LOW:
                                    return 6295;
                                case Properties::West::TALL:
                                    return 6296;
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
                                    return 6297;
                                case Properties::West::LOW:
                                    return 6298;
                                case Properties::West::TALL:
                                    return 6299;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6300;
                                case Properties::West::LOW:
                                    return 6301;
                                case Properties::West::TALL:
                                    return 6302;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6303;
                                case Properties::West::LOW:
                                    return 6304;
                                case Properties::West::TALL:
                                    return 6305;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6306;
                                case Properties::West::LOW:
                                    return 6307;
                                case Properties::West::TALL:
                                    return 6308;
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
                                    return 6309;
                                case Properties::West::LOW:
                                    return 6310;
                                case Properties::West::TALL:
                                    return 6311;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6312;
                                case Properties::West::LOW:
                                    return 6313;
                                case Properties::West::TALL:
                                    return 6314;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6315;
                                case Properties::West::LOW:
                                    return 6316;
                                case Properties::West::TALL:
                                    return 6317;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6318;
                                case Properties::West::LOW:
                                    return 6319;
                                case Properties::West::TALL:
                                    return 6320;
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
                                    return 6321;
                                case Properties::West::LOW:
                                    return 6322;
                                case Properties::West::TALL:
                                    return 6323;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6324;
                                case Properties::West::LOW:
                                    return 6325;
                                case Properties::West::TALL:
                                    return 6326;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6327;
                                case Properties::West::LOW:
                                    return 6328;
                                case Properties::West::TALL:
                                    return 6329;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6330;
                                case Properties::West::LOW:
                                    return 6331;
                                case Properties::West::TALL:
                                    return 6332;
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
                                    return 6333;
                                case Properties::West::LOW:
                                    return 6334;
                                case Properties::West::TALL:
                                    return 6335;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6336;
                                case Properties::West::LOW:
                                    return 6337;
                                case Properties::West::TALL:
                                    return 6338;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6339;
                                case Properties::West::LOW:
                                    return 6340;
                                case Properties::West::TALL:
                                    return 6341;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6342;
                                case Properties::West::LOW:
                                    return 6343;
                                case Properties::West::TALL:
                                    return 6344;
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
                                    return 6345;
                                case Properties::West::LOW:
                                    return 6346;
                                case Properties::West::TALL:
                                    return 6347;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6348;
                                case Properties::West::LOW:
                                    return 6349;
                                case Properties::West::TALL:
                                    return 6350;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6351;
                                case Properties::West::LOW:
                                    return 6352;
                                case Properties::West::TALL:
                                    return 6353;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6354;
                                case Properties::West::LOW:
                                    return 6355;
                                case Properties::West::TALL:
                                    return 6356;
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
                                    return 6357;
                                case Properties::West::LOW:
                                    return 6358;
                                case Properties::West::TALL:
                                    return 6359;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6360;
                                case Properties::West::LOW:
                                    return 6361;
                                case Properties::West::TALL:
                                    return 6362;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6363;
                                case Properties::West::LOW:
                                    return 6364;
                                case Properties::West::TALL:
                                    return 6365;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6366;
                                case Properties::West::LOW:
                                    return 6367;
                                case Properties::West::TALL:
                                    return 6368;
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
                                    return 6369;
                                case Properties::West::LOW:
                                    return 6370;
                                case Properties::West::TALL:
                                    return 6371;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6372;
                                case Properties::West::LOW:
                                    return 6373;
                                case Properties::West::TALL:
                                    return 6374;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6375;
                                case Properties::West::LOW:
                                    return 6376;
                                case Properties::West::TALL:
                                    return 6377;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6378;
                                case Properties::West::LOW:
                                    return 6379;
                                case Properties::West::TALL:
                                    return 6380;
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
                                    return 6381;
                                case Properties::West::LOW:
                                    return 6382;
                                case Properties::West::TALL:
                                    return 6383;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6384;
                                case Properties::West::LOW:
                                    return 6385;
                                case Properties::West::TALL:
                                    return 6386;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6387;
                                case Properties::West::LOW:
                                    return 6388;
                                case Properties::West::TALL:
                                    return 6389;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6390;
                                case Properties::West::LOW:
                                    return 6391;
                                case Properties::West::TALL:
                                    return 6392;
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
                                    return 6393;
                                case Properties::West::LOW:
                                    return 6394;
                                case Properties::West::TALL:
                                    return 6395;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6396;
                                case Properties::West::LOW:
                                    return 6397;
                                case Properties::West::TALL:
                                    return 6398;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6399;
                                case Properties::West::LOW:
                                    return 6400;
                                case Properties::West::TALL:
                                    return 6401;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6402;
                                case Properties::West::LOW:
                                    return 6403;
                                case Properties::West::TALL:
                                    return 6404;
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
                                    return 6405;
                                case Properties::West::LOW:
                                    return 6406;
                                case Properties::West::TALL:
                                    return 6407;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6408;
                                case Properties::West::LOW:
                                    return 6409;
                                case Properties::West::TALL:
                                    return 6410;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6411;
                                case Properties::West::LOW:
                                    return 6412;
                                case Properties::West::TALL:
                                    return 6413;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6414;
                                case Properties::West::LOW:
                                    return 6415;
                                case Properties::West::TALL:
                                    return 6416;
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
                                    return 6417;
                                case Properties::West::LOW:
                                    return 6418;
                                case Properties::West::TALL:
                                    return 6419;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6420;
                                case Properties::West::LOW:
                                    return 6421;
                                case Properties::West::TALL:
                                    return 6422;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6423;
                                case Properties::West::LOW:
                                    return 6424;
                                case Properties::West::TALL:
                                    return 6425;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6426;
                                case Properties::West::LOW:
                                    return 6427;
                                case Properties::West::TALL:
                                    return 6428;
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
                                    return 6429;
                                case Properties::West::LOW:
                                    return 6430;
                                case Properties::West::TALL:
                                    return 6431;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6432;
                                case Properties::West::LOW:
                                    return 6433;
                                case Properties::West::TALL:
                                    return 6434;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6435;
                                case Properties::West::LOW:
                                    return 6436;
                                case Properties::West::TALL:
                                    return 6437;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6438;
                                case Properties::West::LOW:
                                    return 6439;
                                case Properties::West::TALL:
                                    return 6440;
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
                                    return 6441;
                                case Properties::West::LOW:
                                    return 6442;
                                case Properties::West::TALL:
                                    return 6443;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6444;
                                case Properties::West::LOW:
                                    return 6445;
                                case Properties::West::TALL:
                                    return 6446;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6447;
                                case Properties::West::LOW:
                                    return 6448;
                                case Properties::West::TALL:
                                    return 6449;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6450;
                                case Properties::West::LOW:
                                    return 6451;
                                case Properties::West::TALL:
                                    return 6452;
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
                                    return 6453;
                                case Properties::West::LOW:
                                    return 6454;
                                case Properties::West::TALL:
                                    return 6455;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6456;
                                case Properties::West::LOW:
                                    return 6457;
                                case Properties::West::TALL:
                                    return 6458;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6459;
                                case Properties::West::LOW:
                                    return 6460;
                                case Properties::West::TALL:
                                    return 6461;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6462;
                                case Properties::West::LOW:
                                    return 6463;
                                case Properties::West::TALL:
                                    return 6464;
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
                                    return 6465;
                                case Properties::West::LOW:
                                    return 6466;
                                case Properties::West::TALL:
                                    return 6467;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6468;
                                case Properties::West::LOW:
                                    return 6469;
                                case Properties::West::TALL:
                                    return 6470;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6471;
                                case Properties::West::LOW:
                                    return 6472;
                                case Properties::West::TALL:
                                    return 6473;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6474;
                                case Properties::West::LOW:
                                    return 6475;
                                case Properties::West::TALL:
                                    return 6476;
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
                                    return 6477;
                                case Properties::West::LOW:
                                    return 6478;
                                case Properties::West::TALL:
                                    return 6479;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6480;
                                case Properties::West::LOW:
                                    return 6481;
                                case Properties::West::TALL:
                                    return 6482;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6483;
                                case Properties::West::LOW:
                                    return 6484;
                                case Properties::West::TALL:
                                    return 6485;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6486;
                                case Properties::West::LOW:
                                    return 6487;
                                case Properties::West::TALL:
                                    return 6488;
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
                                    return 6489;
                                case Properties::West::LOW:
                                    return 6490;
                                case Properties::West::TALL:
                                    return 6491;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6492;
                                case Properties::West::LOW:
                                    return 6493;
                                case Properties::West::TALL:
                                    return 6494;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6495;
                                case Properties::West::LOW:
                                    return 6496;
                                case Properties::West::TALL:
                                    return 6497;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6498;
                                case Properties::West::LOW:
                                    return 6499;
                                case Properties::West::TALL:
                                    return 6500;
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
                                    return 6501;
                                case Properties::West::LOW:
                                    return 6502;
                                case Properties::West::TALL:
                                    return 6503;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6504;
                                case Properties::West::LOW:
                                    return 6505;
                                case Properties::West::TALL:
                                    return 6506;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6507;
                                case Properties::West::LOW:
                                    return 6508;
                                case Properties::West::TALL:
                                    return 6509;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6510;
                                case Properties::West::LOW:
                                    return 6511;
                                case Properties::West::TALL:
                                    return 6512;
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
                                    return 6513;
                                case Properties::West::LOW:
                                    return 6514;
                                case Properties::West::TALL:
                                    return 6515;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6516;
                                case Properties::West::LOW:
                                    return 6517;
                                case Properties::West::TALL:
                                    return 6518;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6519;
                                case Properties::West::LOW:
                                    return 6520;
                                case Properties::West::TALL:
                                    return 6521;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6522;
                                case Properties::West::LOW:
                                    return 6523;
                                case Properties::West::TALL:
                                    return 6524;
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
                                    return 6525;
                                case Properties::West::LOW:
                                    return 6526;
                                case Properties::West::TALL:
                                    return 6527;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6528;
                                case Properties::West::LOW:
                                    return 6529;
                                case Properties::West::TALL:
                                    return 6530;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6531;
                                case Properties::West::LOW:
                                    return 6532;
                                case Properties::West::TALL:
                                    return 6533;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6534;
                                case Properties::West::LOW:
                                    return 6535;
                                case Properties::West::TALL:
                                    return 6536;
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
                                    return 6537;
                                case Properties::West::LOW:
                                    return 6538;
                                case Properties::West::TALL:
                                    return 6539;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6540;
                                case Properties::West::LOW:
                                    return 6541;
                                case Properties::West::TALL:
                                    return 6542;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6543;
                                case Properties::West::LOW:
                                    return 6544;
                                case Properties::West::TALL:
                                    return 6545;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6546;
                                case Properties::West::LOW:
                                    return 6547;
                                case Properties::West::TALL:
                                    return 6548;
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
                                    return 6549;
                                case Properties::West::LOW:
                                    return 6550;
                                case Properties::West::TALL:
                                    return 6551;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6552;
                                case Properties::West::LOW:
                                    return 6553;
                                case Properties::West::TALL:
                                    return 6554;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6555;
                                case Properties::West::LOW:
                                    return 6556;
                                case Properties::West::TALL:
                                    return 6557;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6558;
                                case Properties::West::LOW:
                                    return 6559;
                                case Properties::West::TALL:
                                    return 6560;
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
                                    return 6561;
                                case Properties::West::LOW:
                                    return 6562;
                                case Properties::West::TALL:
                                    return 6563;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6564;
                                case Properties::West::LOW:
                                    return 6565;
                                case Properties::West::TALL:
                                    return 6566;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6567;
                                case Properties::West::LOW:
                                    return 6568;
                                case Properties::West::TALL:
                                    return 6569;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 6570;
                                case Properties::West::LOW:
                                    return 6571;
                                case Properties::West::TALL:
                                    return 6572;
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
