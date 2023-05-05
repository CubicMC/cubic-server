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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7309;
                                    case Properties::West::FALSE:
                                        return 7310;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7311;
                                    case Properties::West::FALSE:
                                        return 7312;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7313;
                                    case Properties::West::FALSE:
                                        return 7314;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7317;
                                    case Properties::West::FALSE:
                                        return 7318;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7319;
                                    case Properties::West::FALSE:
                                        return 7320;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7321;
                                    case Properties::West::FALSE:
                                        return 7322;
                                    }
                                }
                            }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7325;
                                    case Properties::West::FALSE:
                                        return 7326;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7327;
                                    case Properties::West::FALSE:
                                        return 7328;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7329;
                                    case Properties::West::FALSE:
                                        return 7330;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7333;
                                    case Properties::West::FALSE:
                                        return 7334;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7335;
                                    case Properties::West::FALSE:
                                        return 7336;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7337;
                                    case Properties::West::FALSE:
                                        return 7338;
                                    }
                                }
                            }
                        }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7341;
                                    case Properties::West::FALSE:
                                        return 7342;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7343;
                                    case Properties::West::FALSE:
                                        return 7344;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7345;
                                    case Properties::West::FALSE:
                                        return 7346;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7349;
                                    case Properties::West::FALSE:
                                        return 7350;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7351;
                                    case Properties::West::FALSE:
                                        return 7352;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7353;
                                    case Properties::West::FALSE:
                                        return 7354;
                                    }
                                }
                            }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7357;
                                    case Properties::West::FALSE:
                                        return 7358;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7359;
                                    case Properties::West::FALSE:
                                        return 7360;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7361;
                                    case Properties::West::FALSE:
                                        return 7362;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7365;
                                    case Properties::West::FALSE:
                                        return 7366;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7367;
                                    case Properties::West::FALSE:
                                        return 7368;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7369;
                                    case Properties::West::FALSE:
                                        return 7370;
                                    }
                                }
                            }
                        }
                    }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7373;
                                    case Properties::West::FALSE:
                                        return 7374;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7375;
                                    case Properties::West::FALSE:
                                        return 7376;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7377;
                                    case Properties::West::FALSE:
                                        return 7378;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7381;
                                    case Properties::West::FALSE:
                                        return 7382;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7383;
                                    case Properties::West::FALSE:
                                        return 7384;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7385;
                                    case Properties::West::FALSE:
                                        return 7386;
                                    }
                                }
                            }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7389;
                                    case Properties::West::FALSE:
                                        return 7390;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7391;
                                    case Properties::West::FALSE:
                                        return 7392;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7393;
                                    case Properties::West::FALSE:
                                        return 7394;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7397;
                                    case Properties::West::FALSE:
                                        return 7398;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7399;
                                    case Properties::West::FALSE:
                                        return 7400;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7401;
                                    case Properties::West::FALSE:
                                        return 7402;
                                    }
                                }
                            }
                        }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7405;
                                    case Properties::West::FALSE:
                                        return 7406;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7407;
                                    case Properties::West::FALSE:
                                        return 7408;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7409;
                                    case Properties::West::FALSE:
                                        return 7410;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7413;
                                    case Properties::West::FALSE:
                                        return 7414;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7415;
                                    case Properties::West::FALSE:
                                        return 7416;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7417;
                                    case Properties::West::FALSE:
                                        return 7418;
                                    }
                                }
                            }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7421;
                                    case Properties::West::FALSE:
                                        return 7422;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7423;
                                    case Properties::West::FALSE:
                                        return 7424;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7425;
                                    case Properties::West::FALSE:
                                        return 7426;
                                    }
                                }
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
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7429;
                                    case Properties::West::FALSE:
                                        return 7430;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7431;
                                    case Properties::West::FALSE:
                                        return 7432;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 7433;
                                    case Properties::West::FALSE:
                                        return 7434;
                                    }
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
