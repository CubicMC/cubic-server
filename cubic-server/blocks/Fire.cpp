#include "Fire.hpp"
#include <stdexcept>

namespace Blocks {
namespace Fire {
BlockId toProtocol(Properties::Age age, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west)
{
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2310;
                        case Properties::West::FALSE:
                            return 2311;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2312;
                        case Properties::West::FALSE:
                            return 2313;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2314;
                        case Properties::West::FALSE:
                            return 2315;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2318;
                        case Properties::West::FALSE:
                            return 2319;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2320;
                        case Properties::West::FALSE:
                            return 2321;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2322;
                        case Properties::West::FALSE:
                            return 2323;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2326;
                        case Properties::West::FALSE:
                            return 2327;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2328;
                        case Properties::West::FALSE:
                            return 2329;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2330;
                        case Properties::West::FALSE:
                            return 2331;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2334;
                        case Properties::West::FALSE:
                            return 2335;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2336;
                        case Properties::West::FALSE:
                            return 2337;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2338;
                        case Properties::West::FALSE:
                            return 2339;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2342;
                        case Properties::West::FALSE:
                            return 2343;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2344;
                        case Properties::West::FALSE:
                            return 2345;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2346;
                        case Properties::West::FALSE:
                            return 2347;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2350;
                        case Properties::West::FALSE:
                            return 2351;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2352;
                        case Properties::West::FALSE:
                            return 2353;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2354;
                        case Properties::West::FALSE:
                            return 2355;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2358;
                        case Properties::West::FALSE:
                            return 2359;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2360;
                        case Properties::West::FALSE:
                            return 2361;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2362;
                        case Properties::West::FALSE:
                            return 2363;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2366;
                        case Properties::West::FALSE:
                            return 2367;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2368;
                        case Properties::West::FALSE:
                            return 2369;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2370;
                        case Properties::West::FALSE:
                            return 2371;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2374;
                        case Properties::West::FALSE:
                            return 2375;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2376;
                        case Properties::West::FALSE:
                            return 2377;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2378;
                        case Properties::West::FALSE:
                            return 2379;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2382;
                        case Properties::West::FALSE:
                            return 2383;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2384;
                        case Properties::West::FALSE:
                            return 2385;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2386;
                        case Properties::West::FALSE:
                            return 2387;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2390;
                        case Properties::West::FALSE:
                            return 2391;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2392;
                        case Properties::West::FALSE:
                            return 2393;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2394;
                        case Properties::West::FALSE:
                            return 2395;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2398;
                        case Properties::West::FALSE:
                            return 2399;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2400;
                        case Properties::West::FALSE:
                            return 2401;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2402;
                        case Properties::West::FALSE:
                            return 2403;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2406;
                        case Properties::West::FALSE:
                            return 2407;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2408;
                        case Properties::West::FALSE:
                            return 2409;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2410;
                        case Properties::West::FALSE:
                            return 2411;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2414;
                        case Properties::West::FALSE:
                            return 2415;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2416;
                        case Properties::West::FALSE:
                            return 2417;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2418;
                        case Properties::West::FALSE:
                            return 2419;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2422;
                        case Properties::West::FALSE:
                            return 2423;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2424;
                        case Properties::West::FALSE:
                            return 2425;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2426;
                        case Properties::West::FALSE:
                            return 2427;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2430;
                        case Properties::West::FALSE:
                            return 2431;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2432;
                        case Properties::West::FALSE:
                            return 2433;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2434;
                        case Properties::West::FALSE:
                            return 2435;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2438;
                        case Properties::West::FALSE:
                            return 2439;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2440;
                        case Properties::West::FALSE:
                            return 2441;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2442;
                        case Properties::West::FALSE:
                            return 2443;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2446;
                        case Properties::West::FALSE:
                            return 2447;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2448;
                        case Properties::West::FALSE:
                            return 2449;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2450;
                        case Properties::West::FALSE:
                            return 2451;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2454;
                        case Properties::West::FALSE:
                            return 2455;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2456;
                        case Properties::West::FALSE:
                            return 2457;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2458;
                        case Properties::West::FALSE:
                            return 2459;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2462;
                        case Properties::West::FALSE:
                            return 2463;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2464;
                        case Properties::West::FALSE:
                            return 2465;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2466;
                        case Properties::West::FALSE:
                            return 2467;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2470;
                        case Properties::West::FALSE:
                            return 2471;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2472;
                        case Properties::West::FALSE:
                            return 2473;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2474;
                        case Properties::West::FALSE:
                            return 2475;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2478;
                        case Properties::West::FALSE:
                            return 2479;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2480;
                        case Properties::West::FALSE:
                            return 2481;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2482;
                        case Properties::West::FALSE:
                            return 2483;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2486;
                        case Properties::West::FALSE:
                            return 2487;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2488;
                        case Properties::West::FALSE:
                            return 2489;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2490;
                        case Properties::West::FALSE:
                            return 2491;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2494;
                        case Properties::West::FALSE:
                            return 2495;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2496;
                        case Properties::West::FALSE:
                            return 2497;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2498;
                        case Properties::West::FALSE:
                            return 2499;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2502;
                        case Properties::West::FALSE:
                            return 2503;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2504;
                        case Properties::West::FALSE:
                            return 2505;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2506;
                        case Properties::West::FALSE:
                            return 2507;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2510;
                        case Properties::West::FALSE:
                            return 2511;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2512;
                        case Properties::West::FALSE:
                            return 2513;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2514;
                        case Properties::West::FALSE:
                            return 2515;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2518;
                        case Properties::West::FALSE:
                            return 2519;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2520;
                        case Properties::West::FALSE:
                            return 2521;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2522;
                        case Properties::West::FALSE:
                            return 2523;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2526;
                        case Properties::West::FALSE:
                            return 2527;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2528;
                        case Properties::West::FALSE:
                            return 2529;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2530;
                        case Properties::West::FALSE:
                            return 2531;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2534;
                        case Properties::West::FALSE:
                            return 2535;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2536;
                        case Properties::West::FALSE:
                            return 2537;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2538;
                        case Properties::West::FALSE:
                            return 2539;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2542;
                        case Properties::West::FALSE:
                            return 2543;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2544;
                        case Properties::West::FALSE:
                            return 2545;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2546;
                        case Properties::West::FALSE:
                            return 2547;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2550;
                        case Properties::West::FALSE:
                            return 2551;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2552;
                        case Properties::West::FALSE:
                            return 2553;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2554;
                        case Properties::West::FALSE:
                            return 2555;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2558;
                        case Properties::West::FALSE:
                            return 2559;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2560;
                        case Properties::West::FALSE:
                            return 2561;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2562;
                        case Properties::West::FALSE:
                            return 2563;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2566;
                        case Properties::West::FALSE:
                            return 2567;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2568;
                        case Properties::West::FALSE:
                            return 2569;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2570;
                        case Properties::West::FALSE:
                            return 2571;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2574;
                        case Properties::West::FALSE:
                            return 2575;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2576;
                        case Properties::West::FALSE:
                            return 2577;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2578;
                        case Properties::West::FALSE:
                            return 2579;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2582;
                        case Properties::West::FALSE:
                            return 2583;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2584;
                        case Properties::West::FALSE:
                            return 2585;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2586;
                        case Properties::West::FALSE:
                            return 2587;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2590;
                        case Properties::West::FALSE:
                            return 2591;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2592;
                        case Properties::West::FALSE:
                            return 2593;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2594;
                        case Properties::West::FALSE:
                            return 2595;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2598;
                        case Properties::West::FALSE:
                            return 2599;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2600;
                        case Properties::West::FALSE:
                            return 2601;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2602;
                        case Properties::West::FALSE:
                            return 2603;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2606;
                        case Properties::West::FALSE:
                            return 2607;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2608;
                        case Properties::West::FALSE:
                            return 2609;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2610;
                        case Properties::West::FALSE:
                            return 2611;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2614;
                        case Properties::West::FALSE:
                            return 2615;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2616;
                        case Properties::West::FALSE:
                            return 2617;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2618;
                        case Properties::West::FALSE:
                            return 2619;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2622;
                        case Properties::West::FALSE:
                            return 2623;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2624;
                        case Properties::West::FALSE:
                            return 2625;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2626;
                        case Properties::West::FALSE:
                            return 2627;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2630;
                        case Properties::West::FALSE:
                            return 2631;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2632;
                        case Properties::West::FALSE:
                            return 2633;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2634;
                        case Properties::West::FALSE:
                            return 2635;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2638;
                        case Properties::West::FALSE:
                            return 2639;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2640;
                        case Properties::West::FALSE:
                            return 2641;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2642;
                        case Properties::West::FALSE:
                            return 2643;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2646;
                        case Properties::West::FALSE:
                            return 2647;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2648;
                        case Properties::West::FALSE:
                            return 2649;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2650;
                        case Properties::West::FALSE:
                            return 2651;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2654;
                        case Properties::West::FALSE:
                            return 2655;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2656;
                        case Properties::West::FALSE:
                            return 2657;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2658;
                        case Properties::West::FALSE:
                            return 2659;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2662;
                        case Properties::West::FALSE:
                            return 2663;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2664;
                        case Properties::West::FALSE:
                            return 2665;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2666;
                        case Properties::West::FALSE:
                            return 2667;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2670;
                        case Properties::West::FALSE:
                            return 2671;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2672;
                        case Properties::West::FALSE:
                            return 2673;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2674;
                        case Properties::West::FALSE:
                            return 2675;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2678;
                        case Properties::West::FALSE:
                            return 2679;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2680;
                        case Properties::West::FALSE:
                            return 2681;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2682;
                        case Properties::West::FALSE:
                            return 2683;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2686;
                        case Properties::West::FALSE:
                            return 2687;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2688;
                        case Properties::West::FALSE:
                            return 2689;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2690;
                        case Properties::West::FALSE:
                            return 2691;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2694;
                        case Properties::West::FALSE:
                            return 2695;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2696;
                        case Properties::West::FALSE:
                            return 2697;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2698;
                        case Properties::West::FALSE:
                            return 2699;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2702;
                        case Properties::West::FALSE:
                            return 2703;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2704;
                        case Properties::West::FALSE:
                            return 2705;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2706;
                        case Properties::West::FALSE:
                            return 2707;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2710;
                        case Properties::West::FALSE:
                            return 2711;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2712;
                        case Properties::West::FALSE:
                            return 2713;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2714;
                        case Properties::West::FALSE:
                            return 2715;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2718;
                        case Properties::West::FALSE:
                            return 2719;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2720;
                        case Properties::West::FALSE:
                            return 2721;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2722;
                        case Properties::West::FALSE:
                            return 2723;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2726;
                        case Properties::West::FALSE:
                            return 2727;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2728;
                        case Properties::West::FALSE:
                            return 2729;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2730;
                        case Properties::West::FALSE:
                            return 2731;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2734;
                        case Properties::West::FALSE:
                            return 2735;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2736;
                        case Properties::West::FALSE:
                            return 2737;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2738;
                        case Properties::West::FALSE:
                            return 2739;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2742;
                        case Properties::West::FALSE:
                            return 2743;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2744;
                        case Properties::West::FALSE:
                            return 2745;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2746;
                        case Properties::West::FALSE:
                            return 2747;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2750;
                        case Properties::West::FALSE:
                            return 2751;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2752;
                        case Properties::West::FALSE:
                            return 2753;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2754;
                        case Properties::West::FALSE:
                            return 2755;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2758;
                        case Properties::West::FALSE:
                            return 2759;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2760;
                        case Properties::West::FALSE:
                            return 2761;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2762;
                        case Properties::West::FALSE:
                            return 2763;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2766;
                        case Properties::West::FALSE:
                            return 2767;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2768;
                        case Properties::West::FALSE:
                            return 2769;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2770;
                        case Properties::West::FALSE:
                            return 2771;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2774;
                        case Properties::West::FALSE:
                            return 2775;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2776;
                        case Properties::West::FALSE:
                            return 2777;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2778;
                        case Properties::West::FALSE:
                            return 2779;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2782;
                        case Properties::West::FALSE:
                            return 2783;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2784;
                        case Properties::West::FALSE:
                            return 2785;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2786;
                        case Properties::West::FALSE:
                            return 2787;
                        }
                    }
                }
            }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2790;
                        case Properties::West::FALSE:
                            return 2791;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2792;
                        case Properties::West::FALSE:
                            return 2793;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2794;
                        case Properties::West::FALSE:
                            return 2795;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2798;
                        case Properties::West::FALSE:
                            return 2799;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2800;
                        case Properties::West::FALSE:
                            return 2801;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2802;
                        case Properties::West::FALSE:
                            return 2803;
                        }
                    }
                }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2806;
                        case Properties::West::FALSE:
                            return 2807;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2808;
                        case Properties::West::FALSE:
                            return 2809;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2810;
                        case Properties::West::FALSE:
                            return 2811;
                        }
                    }
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
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2814;
                        case Properties::West::FALSE:
                            return 2815;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2816;
                        case Properties::West::FALSE:
                            return 2817;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 2818;
                        case Properties::West::FALSE:
                            return 2819;
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
