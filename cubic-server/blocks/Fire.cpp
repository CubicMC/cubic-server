#include "Fire.hpp"
namespace Blocks {
    namespace Fire {
        BlockId toProtocol(Properties::Age age, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
            switch (age) {
            case Properties::Age::ZERO:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2308;
                                case Properties::West::FALSE:
                                    return 2309;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2310;
                                case Properties::West::FALSE:
                                    return 2311;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2312;
                                case Properties::West::FALSE:
                                    return 2313;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2314;
                                case Properties::West::FALSE:
                                    return 2315;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2316;
                                case Properties::West::FALSE:
                                    return 2317;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2318;
                                case Properties::West::FALSE:
                                    return 2319;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2320;
                                case Properties::West::FALSE:
                                    return 2321;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2322;
                                case Properties::West::FALSE:
                                    return 2323;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2324;
                                case Properties::West::FALSE:
                                    return 2325;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2326;
                                case Properties::West::FALSE:
                                    return 2327;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2328;
                                case Properties::West::FALSE:
                                    return 2329;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2330;
                                case Properties::West::FALSE:
                                    return 2331;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2332;
                                case Properties::West::FALSE:
                                    return 2333;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2334;
                                case Properties::West::FALSE:
                                    return 2335;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2336;
                                case Properties::West::FALSE:
                                    return 2337;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2338;
                                case Properties::West::FALSE:
                                    return 2339;
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
            case Properties::Age::ONE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2340;
                                case Properties::West::FALSE:
                                    return 2341;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2342;
                                case Properties::West::FALSE:
                                    return 2343;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2344;
                                case Properties::West::FALSE:
                                    return 2345;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2346;
                                case Properties::West::FALSE:
                                    return 2347;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2348;
                                case Properties::West::FALSE:
                                    return 2349;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2350;
                                case Properties::West::FALSE:
                                    return 2351;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2352;
                                case Properties::West::FALSE:
                                    return 2353;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2354;
                                case Properties::West::FALSE:
                                    return 2355;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2356;
                                case Properties::West::FALSE:
                                    return 2357;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2358;
                                case Properties::West::FALSE:
                                    return 2359;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2360;
                                case Properties::West::FALSE:
                                    return 2361;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2362;
                                case Properties::West::FALSE:
                                    return 2363;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2364;
                                case Properties::West::FALSE:
                                    return 2365;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2366;
                                case Properties::West::FALSE:
                                    return 2367;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2368;
                                case Properties::West::FALSE:
                                    return 2369;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2370;
                                case Properties::West::FALSE:
                                    return 2371;
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
            case Properties::Age::TWO:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2372;
                                case Properties::West::FALSE:
                                    return 2373;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2374;
                                case Properties::West::FALSE:
                                    return 2375;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2376;
                                case Properties::West::FALSE:
                                    return 2377;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2378;
                                case Properties::West::FALSE:
                                    return 2379;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2380;
                                case Properties::West::FALSE:
                                    return 2381;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2382;
                                case Properties::West::FALSE:
                                    return 2383;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2384;
                                case Properties::West::FALSE:
                                    return 2385;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2386;
                                case Properties::West::FALSE:
                                    return 2387;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2388;
                                case Properties::West::FALSE:
                                    return 2389;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2390;
                                case Properties::West::FALSE:
                                    return 2391;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2392;
                                case Properties::West::FALSE:
                                    return 2393;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2394;
                                case Properties::West::FALSE:
                                    return 2395;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2396;
                                case Properties::West::FALSE:
                                    return 2397;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2398;
                                case Properties::West::FALSE:
                                    return 2399;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2400;
                                case Properties::West::FALSE:
                                    return 2401;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2402;
                                case Properties::West::FALSE:
                                    return 2403;
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
            case Properties::Age::THREE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2404;
                                case Properties::West::FALSE:
                                    return 2405;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2406;
                                case Properties::West::FALSE:
                                    return 2407;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2408;
                                case Properties::West::FALSE:
                                    return 2409;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2410;
                                case Properties::West::FALSE:
                                    return 2411;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2412;
                                case Properties::West::FALSE:
                                    return 2413;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2414;
                                case Properties::West::FALSE:
                                    return 2415;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2416;
                                case Properties::West::FALSE:
                                    return 2417;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2418;
                                case Properties::West::FALSE:
                                    return 2419;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2420;
                                case Properties::West::FALSE:
                                    return 2421;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2422;
                                case Properties::West::FALSE:
                                    return 2423;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2424;
                                case Properties::West::FALSE:
                                    return 2425;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2426;
                                case Properties::West::FALSE:
                                    return 2427;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2428;
                                case Properties::West::FALSE:
                                    return 2429;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2430;
                                case Properties::West::FALSE:
                                    return 2431;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2432;
                                case Properties::West::FALSE:
                                    return 2433;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2434;
                                case Properties::West::FALSE:
                                    return 2435;
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
            case Properties::Age::FOUR:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2436;
                                case Properties::West::FALSE:
                                    return 2437;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2438;
                                case Properties::West::FALSE:
                                    return 2439;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2440;
                                case Properties::West::FALSE:
                                    return 2441;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2442;
                                case Properties::West::FALSE:
                                    return 2443;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2444;
                                case Properties::West::FALSE:
                                    return 2445;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2446;
                                case Properties::West::FALSE:
                                    return 2447;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2448;
                                case Properties::West::FALSE:
                                    return 2449;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2450;
                                case Properties::West::FALSE:
                                    return 2451;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2452;
                                case Properties::West::FALSE:
                                    return 2453;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2454;
                                case Properties::West::FALSE:
                                    return 2455;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2456;
                                case Properties::West::FALSE:
                                    return 2457;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2458;
                                case Properties::West::FALSE:
                                    return 2459;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2460;
                                case Properties::West::FALSE:
                                    return 2461;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2462;
                                case Properties::West::FALSE:
                                    return 2463;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2464;
                                case Properties::West::FALSE:
                                    return 2465;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2466;
                                case Properties::West::FALSE:
                                    return 2467;
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
            case Properties::Age::FIVE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2468;
                                case Properties::West::FALSE:
                                    return 2469;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2470;
                                case Properties::West::FALSE:
                                    return 2471;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2472;
                                case Properties::West::FALSE:
                                    return 2473;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2474;
                                case Properties::West::FALSE:
                                    return 2475;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2476;
                                case Properties::West::FALSE:
                                    return 2477;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2478;
                                case Properties::West::FALSE:
                                    return 2479;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2480;
                                case Properties::West::FALSE:
                                    return 2481;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2482;
                                case Properties::West::FALSE:
                                    return 2483;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2484;
                                case Properties::West::FALSE:
                                    return 2485;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2486;
                                case Properties::West::FALSE:
                                    return 2487;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2488;
                                case Properties::West::FALSE:
                                    return 2489;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2490;
                                case Properties::West::FALSE:
                                    return 2491;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2492;
                                case Properties::West::FALSE:
                                    return 2493;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2494;
                                case Properties::West::FALSE:
                                    return 2495;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2496;
                                case Properties::West::FALSE:
                                    return 2497;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2498;
                                case Properties::West::FALSE:
                                    return 2499;
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
            case Properties::Age::SIX:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2500;
                                case Properties::West::FALSE:
                                    return 2501;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2502;
                                case Properties::West::FALSE:
                                    return 2503;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2504;
                                case Properties::West::FALSE:
                                    return 2505;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2506;
                                case Properties::West::FALSE:
                                    return 2507;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2508;
                                case Properties::West::FALSE:
                                    return 2509;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2510;
                                case Properties::West::FALSE:
                                    return 2511;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2512;
                                case Properties::West::FALSE:
                                    return 2513;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2514;
                                case Properties::West::FALSE:
                                    return 2515;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2516;
                                case Properties::West::FALSE:
                                    return 2517;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2518;
                                case Properties::West::FALSE:
                                    return 2519;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2520;
                                case Properties::West::FALSE:
                                    return 2521;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2522;
                                case Properties::West::FALSE:
                                    return 2523;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2524;
                                case Properties::West::FALSE:
                                    return 2525;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2526;
                                case Properties::West::FALSE:
                                    return 2527;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2528;
                                case Properties::West::FALSE:
                                    return 2529;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2530;
                                case Properties::West::FALSE:
                                    return 2531;
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
            case Properties::Age::SEVEN:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2532;
                                case Properties::West::FALSE:
                                    return 2533;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2534;
                                case Properties::West::FALSE:
                                    return 2535;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2536;
                                case Properties::West::FALSE:
                                    return 2537;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2538;
                                case Properties::West::FALSE:
                                    return 2539;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2540;
                                case Properties::West::FALSE:
                                    return 2541;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2542;
                                case Properties::West::FALSE:
                                    return 2543;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2544;
                                case Properties::West::FALSE:
                                    return 2545;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2546;
                                case Properties::West::FALSE:
                                    return 2547;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2548;
                                case Properties::West::FALSE:
                                    return 2549;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2550;
                                case Properties::West::FALSE:
                                    return 2551;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2552;
                                case Properties::West::FALSE:
                                    return 2553;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2554;
                                case Properties::West::FALSE:
                                    return 2555;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2556;
                                case Properties::West::FALSE:
                                    return 2557;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2558;
                                case Properties::West::FALSE:
                                    return 2559;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2560;
                                case Properties::West::FALSE:
                                    return 2561;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2562;
                                case Properties::West::FALSE:
                                    return 2563;
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
            case Properties::Age::EIGHT:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2564;
                                case Properties::West::FALSE:
                                    return 2565;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2566;
                                case Properties::West::FALSE:
                                    return 2567;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2568;
                                case Properties::West::FALSE:
                                    return 2569;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2570;
                                case Properties::West::FALSE:
                                    return 2571;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2572;
                                case Properties::West::FALSE:
                                    return 2573;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2574;
                                case Properties::West::FALSE:
                                    return 2575;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2576;
                                case Properties::West::FALSE:
                                    return 2577;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2578;
                                case Properties::West::FALSE:
                                    return 2579;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2580;
                                case Properties::West::FALSE:
                                    return 2581;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2582;
                                case Properties::West::FALSE:
                                    return 2583;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2584;
                                case Properties::West::FALSE:
                                    return 2585;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2586;
                                case Properties::West::FALSE:
                                    return 2587;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2588;
                                case Properties::West::FALSE:
                                    return 2589;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2590;
                                case Properties::West::FALSE:
                                    return 2591;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2592;
                                case Properties::West::FALSE:
                                    return 2593;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2594;
                                case Properties::West::FALSE:
                                    return 2595;
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
            case Properties::Age::NINE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2596;
                                case Properties::West::FALSE:
                                    return 2597;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2598;
                                case Properties::West::FALSE:
                                    return 2599;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2600;
                                case Properties::West::FALSE:
                                    return 2601;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2602;
                                case Properties::West::FALSE:
                                    return 2603;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2604;
                                case Properties::West::FALSE:
                                    return 2605;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2606;
                                case Properties::West::FALSE:
                                    return 2607;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2608;
                                case Properties::West::FALSE:
                                    return 2609;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2610;
                                case Properties::West::FALSE:
                                    return 2611;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2612;
                                case Properties::West::FALSE:
                                    return 2613;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2614;
                                case Properties::West::FALSE:
                                    return 2615;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2616;
                                case Properties::West::FALSE:
                                    return 2617;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2618;
                                case Properties::West::FALSE:
                                    return 2619;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2620;
                                case Properties::West::FALSE:
                                    return 2621;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2622;
                                case Properties::West::FALSE:
                                    return 2623;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2624;
                                case Properties::West::FALSE:
                                    return 2625;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2626;
                                case Properties::West::FALSE:
                                    return 2627;
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
            case Properties::Age::TEN:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2628;
                                case Properties::West::FALSE:
                                    return 2629;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2630;
                                case Properties::West::FALSE:
                                    return 2631;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2632;
                                case Properties::West::FALSE:
                                    return 2633;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2634;
                                case Properties::West::FALSE:
                                    return 2635;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2636;
                                case Properties::West::FALSE:
                                    return 2637;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2638;
                                case Properties::West::FALSE:
                                    return 2639;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2640;
                                case Properties::West::FALSE:
                                    return 2641;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2642;
                                case Properties::West::FALSE:
                                    return 2643;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2644;
                                case Properties::West::FALSE:
                                    return 2645;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2646;
                                case Properties::West::FALSE:
                                    return 2647;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2648;
                                case Properties::West::FALSE:
                                    return 2649;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2650;
                                case Properties::West::FALSE:
                                    return 2651;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2652;
                                case Properties::West::FALSE:
                                    return 2653;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2654;
                                case Properties::West::FALSE:
                                    return 2655;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2656;
                                case Properties::West::FALSE:
                                    return 2657;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2658;
                                case Properties::West::FALSE:
                                    return 2659;
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
            case Properties::Age::ELEVEN:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2660;
                                case Properties::West::FALSE:
                                    return 2661;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2662;
                                case Properties::West::FALSE:
                                    return 2663;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2664;
                                case Properties::West::FALSE:
                                    return 2665;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2666;
                                case Properties::West::FALSE:
                                    return 2667;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2668;
                                case Properties::West::FALSE:
                                    return 2669;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2670;
                                case Properties::West::FALSE:
                                    return 2671;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2672;
                                case Properties::West::FALSE:
                                    return 2673;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2674;
                                case Properties::West::FALSE:
                                    return 2675;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2676;
                                case Properties::West::FALSE:
                                    return 2677;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2678;
                                case Properties::West::FALSE:
                                    return 2679;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2680;
                                case Properties::West::FALSE:
                                    return 2681;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2682;
                                case Properties::West::FALSE:
                                    return 2683;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2684;
                                case Properties::West::FALSE:
                                    return 2685;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2686;
                                case Properties::West::FALSE:
                                    return 2687;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2688;
                                case Properties::West::FALSE:
                                    return 2689;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2690;
                                case Properties::West::FALSE:
                                    return 2691;
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
            case Properties::Age::TWELVE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2692;
                                case Properties::West::FALSE:
                                    return 2693;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2694;
                                case Properties::West::FALSE:
                                    return 2695;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2696;
                                case Properties::West::FALSE:
                                    return 2697;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2698;
                                case Properties::West::FALSE:
                                    return 2699;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2700;
                                case Properties::West::FALSE:
                                    return 2701;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2702;
                                case Properties::West::FALSE:
                                    return 2703;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2704;
                                case Properties::West::FALSE:
                                    return 2705;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2706;
                                case Properties::West::FALSE:
                                    return 2707;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2708;
                                case Properties::West::FALSE:
                                    return 2709;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2710;
                                case Properties::West::FALSE:
                                    return 2711;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2712;
                                case Properties::West::FALSE:
                                    return 2713;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2714;
                                case Properties::West::FALSE:
                                    return 2715;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2716;
                                case Properties::West::FALSE:
                                    return 2717;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2718;
                                case Properties::West::FALSE:
                                    return 2719;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2720;
                                case Properties::West::FALSE:
                                    return 2721;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2722;
                                case Properties::West::FALSE:
                                    return 2723;
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
            case Properties::Age::THIRTEEN:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2724;
                                case Properties::West::FALSE:
                                    return 2725;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2726;
                                case Properties::West::FALSE:
                                    return 2727;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2728;
                                case Properties::West::FALSE:
                                    return 2729;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2730;
                                case Properties::West::FALSE:
                                    return 2731;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2732;
                                case Properties::West::FALSE:
                                    return 2733;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2734;
                                case Properties::West::FALSE:
                                    return 2735;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2736;
                                case Properties::West::FALSE:
                                    return 2737;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2738;
                                case Properties::West::FALSE:
                                    return 2739;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2740;
                                case Properties::West::FALSE:
                                    return 2741;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2742;
                                case Properties::West::FALSE:
                                    return 2743;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2744;
                                case Properties::West::FALSE:
                                    return 2745;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2746;
                                case Properties::West::FALSE:
                                    return 2747;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2748;
                                case Properties::West::FALSE:
                                    return 2749;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2750;
                                case Properties::West::FALSE:
                                    return 2751;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2752;
                                case Properties::West::FALSE:
                                    return 2753;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2754;
                                case Properties::West::FALSE:
                                    return 2755;
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
            case Properties::Age::FOURTEEN:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2756;
                                case Properties::West::FALSE:
                                    return 2757;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2758;
                                case Properties::West::FALSE:
                                    return 2759;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2760;
                                case Properties::West::FALSE:
                                    return 2761;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2762;
                                case Properties::West::FALSE:
                                    return 2763;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2764;
                                case Properties::West::FALSE:
                                    return 2765;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2766;
                                case Properties::West::FALSE:
                                    return 2767;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2768;
                                case Properties::West::FALSE:
                                    return 2769;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2770;
                                case Properties::West::FALSE:
                                    return 2771;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2772;
                                case Properties::West::FALSE:
                                    return 2773;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2774;
                                case Properties::West::FALSE:
                                    return 2775;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2776;
                                case Properties::West::FALSE:
                                    return 2777;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2778;
                                case Properties::West::FALSE:
                                    return 2779;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2780;
                                case Properties::West::FALSE:
                                    return 2781;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2782;
                                case Properties::West::FALSE:
                                    return 2783;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2784;
                                case Properties::West::FALSE:
                                    return 2785;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2786;
                                case Properties::West::FALSE:
                                    return 2787;
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
            case Properties::Age::FIFTEEN:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2788;
                                case Properties::West::FALSE:
                                    return 2789;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2790;
                                case Properties::West::FALSE:
                                    return 2791;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2792;
                                case Properties::West::FALSE:
                                    return 2793;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2794;
                                case Properties::West::FALSE:
                                    return 2795;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2796;
                                case Properties::West::FALSE:
                                    return 2797;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2798;
                                case Properties::West::FALSE:
                                    return 2799;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2800;
                                case Properties::West::FALSE:
                                    return 2801;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2802;
                                case Properties::West::FALSE:
                                    return 2803;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2804;
                                case Properties::West::FALSE:
                                    return 2805;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2806;
                                case Properties::West::FALSE:
                                    return 2807;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2808;
                                case Properties::West::FALSE:
                                    return 2809;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2810;
                                case Properties::West::FALSE:
                                    return 2811;
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
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2812;
                                case Properties::West::FALSE:
                                    return 2813;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2814;
                                case Properties::West::FALSE:
                                    return 2815;
                                default:
                                    return 0;
                                }
                            default:
                                return 0;
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2816;
                                case Properties::West::FALSE:
                                    return 2817;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 2818;
                                case Properties::West::FALSE:
                                    return 2819;
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
