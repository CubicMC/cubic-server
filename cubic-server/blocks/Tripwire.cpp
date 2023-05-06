#include "Tripwire.hpp"
namespace Blocks {
    namespace Tripwire {
        BlockId toProtocol(Properties::Attached attached, Properties::Disarmed disarmed, Properties::East east, Properties::North north, Properties::Powered powered, Properties::South south, Properties::West west) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (disarmed) {
                case Properties::Disarmed::TRUE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7307;
                                    case Properties::West::FALSE:
                                        return 7308;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7309;
                                    case Properties::West::FALSE:
                                        return 7310;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7311;
                                    case Properties::West::FALSE:
                                        return 7312;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7313;
                                    case Properties::West::FALSE:
                                        return 7314;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7315;
                                    case Properties::West::FALSE:
                                        return 7316;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7317;
                                    case Properties::West::FALSE:
                                        return 7318;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7319;
                                    case Properties::West::FALSE:
                                        return 7320;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7321;
                                    case Properties::West::FALSE:
                                        return 7322;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7323;
                                    case Properties::West::FALSE:
                                        return 7324;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7325;
                                    case Properties::West::FALSE:
                                        return 7326;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7327;
                                    case Properties::West::FALSE:
                                        return 7328;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7329;
                                    case Properties::West::FALSE:
                                        return 7330;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7331;
                                    case Properties::West::FALSE:
                                        return 7332;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7333;
                                    case Properties::West::FALSE:
                                        return 7334;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7335;
                                    case Properties::West::FALSE:
                                        return 7336;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7337;
                                    case Properties::West::FALSE:
                                        return 7338;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Disarmed::FALSE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7339;
                                    case Properties::West::FALSE:
                                        return 7340;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7341;
                                    case Properties::West::FALSE:
                                        return 7342;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7343;
                                    case Properties::West::FALSE:
                                        return 7344;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7345;
                                    case Properties::West::FALSE:
                                        return 7346;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7347;
                                    case Properties::West::FALSE:
                                        return 7348;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7349;
                                    case Properties::West::FALSE:
                                        return 7350;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7351;
                                    case Properties::West::FALSE:
                                        return 7352;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7353;
                                    case Properties::West::FALSE:
                                        return 7354;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7355;
                                    case Properties::West::FALSE:
                                        return 7356;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7357;
                                    case Properties::West::FALSE:
                                        return 7358;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7359;
                                    case Properties::West::FALSE:
                                        return 7360;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7361;
                                    case Properties::West::FALSE:
                                        return 7362;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7363;
                                    case Properties::West::FALSE:
                                        return 7364;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7365;
                                    case Properties::West::FALSE:
                                        return 7366;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7367;
                                    case Properties::West::FALSE:
                                        return 7368;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7369;
                                    case Properties::West::FALSE:
                                        return 7370;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Attached::FALSE:
                switch (disarmed) {
                case Properties::Disarmed::TRUE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7371;
                                    case Properties::West::FALSE:
                                        return 7372;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7373;
                                    case Properties::West::FALSE:
                                        return 7374;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7375;
                                    case Properties::West::FALSE:
                                        return 7376;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7377;
                                    case Properties::West::FALSE:
                                        return 7378;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7379;
                                    case Properties::West::FALSE:
                                        return 7380;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7381;
                                    case Properties::West::FALSE:
                                        return 7382;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7383;
                                    case Properties::West::FALSE:
                                        return 7384;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7385;
                                    case Properties::West::FALSE:
                                        return 7386;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7387;
                                    case Properties::West::FALSE:
                                        return 7388;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7389;
                                    case Properties::West::FALSE:
                                        return 7390;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7391;
                                    case Properties::West::FALSE:
                                        return 7392;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7393;
                                    case Properties::West::FALSE:
                                        return 7394;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7395;
                                    case Properties::West::FALSE:
                                        return 7396;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7397;
                                    case Properties::West::FALSE:
                                        return 7398;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7399;
                                    case Properties::West::FALSE:
                                        return 7400;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7401;
                                    case Properties::West::FALSE:
                                        return 7402;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Disarmed::FALSE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7403;
                                    case Properties::West::FALSE:
                                        return 7404;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7405;
                                    case Properties::West::FALSE:
                                        return 7406;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7407;
                                    case Properties::West::FALSE:
                                        return 7408;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7409;
                                    case Properties::West::FALSE:
                                        return 7410;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7411;
                                    case Properties::West::FALSE:
                                        return 7412;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7413;
                                    case Properties::West::FALSE:
                                        return 7414;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7415;
                                    case Properties::West::FALSE:
                                        return 7416;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7417;
                                    case Properties::West::FALSE:
                                        return 7418;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7419;
                                    case Properties::West::FALSE:
                                        return 7420;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7421;
                                    case Properties::West::FALSE:
                                        return 7422;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7423;
                                    case Properties::West::FALSE:
                                        return 7424;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7425;
                                    case Properties::West::FALSE:
                                        return 7426;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7427;
                                    case Properties::West::FALSE:
                                        return 7428;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7429;
                                    case Properties::West::FALSE:
                                        return 7430;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7431;
                                    case Properties::West::FALSE:
                                        return 7432;
                                    default:
                                        return 0;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7433;
                                    case Properties::West::FALSE:
                                        return 7434;
                                    default:
                                        return 0;
                                    }
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
            return 0;
        }
    }

}
