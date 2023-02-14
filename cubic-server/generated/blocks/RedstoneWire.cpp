#include "RedstoneWire.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RedstoneWire {
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::Power power, Properties::South south, Properties::West west) {
            switch (east) {
            case Properties::East::UP:
                switch (north) {
                case Properties::North::UP:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2312;
                            case Properties::West::SIDE:
                                return 2313;
                            case Properties::West::NONE:
                                return 2314;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2315;
                            case Properties::West::SIDE:
                                return 2316;
                            case Properties::West::NONE:
                                return 2317;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2318;
                            case Properties::West::SIDE:
                                return 2319;
                            case Properties::West::NONE:
                                return 2320;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2321;
                            case Properties::West::SIDE:
                                return 2322;
                            case Properties::West::NONE:
                                return 2323;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2324;
                            case Properties::West::SIDE:
                                return 2325;
                            case Properties::West::NONE:
                                return 2326;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2327;
                            case Properties::West::SIDE:
                                return 2328;
                            case Properties::West::NONE:
                                return 2329;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2330;
                            case Properties::West::SIDE:
                                return 2331;
                            case Properties::West::NONE:
                                return 2332;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2333;
                            case Properties::West::SIDE:
                                return 2334;
                            case Properties::West::NONE:
                                return 2335;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2336;
                            case Properties::West::SIDE:
                                return 2337;
                            case Properties::West::NONE:
                                return 2338;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2339;
                            case Properties::West::SIDE:
                                return 2340;
                            case Properties::West::NONE:
                                return 2341;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2342;
                            case Properties::West::SIDE:
                                return 2343;
                            case Properties::West::NONE:
                                return 2344;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2345;
                            case Properties::West::SIDE:
                                return 2346;
                            case Properties::West::NONE:
                                return 2347;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2348;
                            case Properties::West::SIDE:
                                return 2349;
                            case Properties::West::NONE:
                                return 2350;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2351;
                            case Properties::West::SIDE:
                                return 2352;
                            case Properties::West::NONE:
                                return 2353;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2354;
                            case Properties::West::SIDE:
                                return 2355;
                            case Properties::West::NONE:
                                return 2356;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2357;
                            case Properties::West::SIDE:
                                return 2358;
                            case Properties::West::NONE:
                                return 2359;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2360;
                            case Properties::West::SIDE:
                                return 2361;
                            case Properties::West::NONE:
                                return 2362;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2363;
                            case Properties::West::SIDE:
                                return 2364;
                            case Properties::West::NONE:
                                return 2365;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2366;
                            case Properties::West::SIDE:
                                return 2367;
                            case Properties::West::NONE:
                                return 2368;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2369;
                            case Properties::West::SIDE:
                                return 2370;
                            case Properties::West::NONE:
                                return 2371;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2372;
                            case Properties::West::SIDE:
                                return 2373;
                            case Properties::West::NONE:
                                return 2374;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2375;
                            case Properties::West::SIDE:
                                return 2376;
                            case Properties::West::NONE:
                                return 2377;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2378;
                            case Properties::West::SIDE:
                                return 2379;
                            case Properties::West::NONE:
                                return 2380;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2381;
                            case Properties::West::SIDE:
                                return 2382;
                            case Properties::West::NONE:
                                return 2383;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2384;
                            case Properties::West::SIDE:
                                return 2385;
                            case Properties::West::NONE:
                                return 2386;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2387;
                            case Properties::West::SIDE:
                                return 2388;
                            case Properties::West::NONE:
                                return 2389;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2390;
                            case Properties::West::SIDE:
                                return 2391;
                            case Properties::West::NONE:
                                return 2392;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2393;
                            case Properties::West::SIDE:
                                return 2394;
                            case Properties::West::NONE:
                                return 2395;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2396;
                            case Properties::West::SIDE:
                                return 2397;
                            case Properties::West::NONE:
                                return 2398;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2399;
                            case Properties::West::SIDE:
                                return 2400;
                            case Properties::West::NONE:
                                return 2401;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2402;
                            case Properties::West::SIDE:
                                return 2403;
                            case Properties::West::NONE:
                                return 2404;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2405;
                            case Properties::West::SIDE:
                                return 2406;
                            case Properties::West::NONE:
                                return 2407;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2408;
                            case Properties::West::SIDE:
                                return 2409;
                            case Properties::West::NONE:
                                return 2410;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2411;
                            case Properties::West::SIDE:
                                return 2412;
                            case Properties::West::NONE:
                                return 2413;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2414;
                            case Properties::West::SIDE:
                                return 2415;
                            case Properties::West::NONE:
                                return 2416;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2417;
                            case Properties::West::SIDE:
                                return 2418;
                            case Properties::West::NONE:
                                return 2419;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2420;
                            case Properties::West::SIDE:
                                return 2421;
                            case Properties::West::NONE:
                                return 2422;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2423;
                            case Properties::West::SIDE:
                                return 2424;
                            case Properties::West::NONE:
                                return 2425;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2426;
                            case Properties::West::SIDE:
                                return 2427;
                            case Properties::West::NONE:
                                return 2428;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2429;
                            case Properties::West::SIDE:
                                return 2430;
                            case Properties::West::NONE:
                                return 2431;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2432;
                            case Properties::West::SIDE:
                                return 2433;
                            case Properties::West::NONE:
                                return 2434;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2435;
                            case Properties::West::SIDE:
                                return 2436;
                            case Properties::West::NONE:
                                return 2437;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2438;
                            case Properties::West::SIDE:
                                return 2439;
                            case Properties::West::NONE:
                                return 2440;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2441;
                            case Properties::West::SIDE:
                                return 2442;
                            case Properties::West::NONE:
                                return 2443;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2444;
                            case Properties::West::SIDE:
                                return 2445;
                            case Properties::West::NONE:
                                return 2446;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2447;
                            case Properties::West::SIDE:
                                return 2448;
                            case Properties::West::NONE:
                                return 2449;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2450;
                            case Properties::West::SIDE:
                                return 2451;
                            case Properties::West::NONE:
                                return 2452;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2453;
                            case Properties::West::SIDE:
                                return 2454;
                            case Properties::West::NONE:
                                return 2455;
                            }
                        }
                    }
                case Properties::North::SIDE:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2456;
                            case Properties::West::SIDE:
                                return 2457;
                            case Properties::West::NONE:
                                return 2458;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2459;
                            case Properties::West::SIDE:
                                return 2460;
                            case Properties::West::NONE:
                                return 2461;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2462;
                            case Properties::West::SIDE:
                                return 2463;
                            case Properties::West::NONE:
                                return 2464;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2465;
                            case Properties::West::SIDE:
                                return 2466;
                            case Properties::West::NONE:
                                return 2467;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2468;
                            case Properties::West::SIDE:
                                return 2469;
                            case Properties::West::NONE:
                                return 2470;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2471;
                            case Properties::West::SIDE:
                                return 2472;
                            case Properties::West::NONE:
                                return 2473;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2474;
                            case Properties::West::SIDE:
                                return 2475;
                            case Properties::West::NONE:
                                return 2476;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2477;
                            case Properties::West::SIDE:
                                return 2478;
                            case Properties::West::NONE:
                                return 2479;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2480;
                            case Properties::West::SIDE:
                                return 2481;
                            case Properties::West::NONE:
                                return 2482;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2483;
                            case Properties::West::SIDE:
                                return 2484;
                            case Properties::West::NONE:
                                return 2485;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2486;
                            case Properties::West::SIDE:
                                return 2487;
                            case Properties::West::NONE:
                                return 2488;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2489;
                            case Properties::West::SIDE:
                                return 2490;
                            case Properties::West::NONE:
                                return 2491;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2492;
                            case Properties::West::SIDE:
                                return 2493;
                            case Properties::West::NONE:
                                return 2494;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2495;
                            case Properties::West::SIDE:
                                return 2496;
                            case Properties::West::NONE:
                                return 2497;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2498;
                            case Properties::West::SIDE:
                                return 2499;
                            case Properties::West::NONE:
                                return 2500;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2501;
                            case Properties::West::SIDE:
                                return 2502;
                            case Properties::West::NONE:
                                return 2503;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2504;
                            case Properties::West::SIDE:
                                return 2505;
                            case Properties::West::NONE:
                                return 2506;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2507;
                            case Properties::West::SIDE:
                                return 2508;
                            case Properties::West::NONE:
                                return 2509;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2510;
                            case Properties::West::SIDE:
                                return 2511;
                            case Properties::West::NONE:
                                return 2512;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2513;
                            case Properties::West::SIDE:
                                return 2514;
                            case Properties::West::NONE:
                                return 2515;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2516;
                            case Properties::West::SIDE:
                                return 2517;
                            case Properties::West::NONE:
                                return 2518;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2519;
                            case Properties::West::SIDE:
                                return 2520;
                            case Properties::West::NONE:
                                return 2521;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2522;
                            case Properties::West::SIDE:
                                return 2523;
                            case Properties::West::NONE:
                                return 2524;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2525;
                            case Properties::West::SIDE:
                                return 2526;
                            case Properties::West::NONE:
                                return 2527;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2528;
                            case Properties::West::SIDE:
                                return 2529;
                            case Properties::West::NONE:
                                return 2530;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2531;
                            case Properties::West::SIDE:
                                return 2532;
                            case Properties::West::NONE:
                                return 2533;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2534;
                            case Properties::West::SIDE:
                                return 2535;
                            case Properties::West::NONE:
                                return 2536;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2537;
                            case Properties::West::SIDE:
                                return 2538;
                            case Properties::West::NONE:
                                return 2539;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2540;
                            case Properties::West::SIDE:
                                return 2541;
                            case Properties::West::NONE:
                                return 2542;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2543;
                            case Properties::West::SIDE:
                                return 2544;
                            case Properties::West::NONE:
                                return 2545;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2546;
                            case Properties::West::SIDE:
                                return 2547;
                            case Properties::West::NONE:
                                return 2548;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2549;
                            case Properties::West::SIDE:
                                return 2550;
                            case Properties::West::NONE:
                                return 2551;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2552;
                            case Properties::West::SIDE:
                                return 2553;
                            case Properties::West::NONE:
                                return 2554;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2555;
                            case Properties::West::SIDE:
                                return 2556;
                            case Properties::West::NONE:
                                return 2557;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2558;
                            case Properties::West::SIDE:
                                return 2559;
                            case Properties::West::NONE:
                                return 2560;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2561;
                            case Properties::West::SIDE:
                                return 2562;
                            case Properties::West::NONE:
                                return 2563;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2564;
                            case Properties::West::SIDE:
                                return 2565;
                            case Properties::West::NONE:
                                return 2566;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2567;
                            case Properties::West::SIDE:
                                return 2568;
                            case Properties::West::NONE:
                                return 2569;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2570;
                            case Properties::West::SIDE:
                                return 2571;
                            case Properties::West::NONE:
                                return 2572;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2573;
                            case Properties::West::SIDE:
                                return 2574;
                            case Properties::West::NONE:
                                return 2575;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2576;
                            case Properties::West::SIDE:
                                return 2577;
                            case Properties::West::NONE:
                                return 2578;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2579;
                            case Properties::West::SIDE:
                                return 2580;
                            case Properties::West::NONE:
                                return 2581;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2582;
                            case Properties::West::SIDE:
                                return 2583;
                            case Properties::West::NONE:
                                return 2584;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2585;
                            case Properties::West::SIDE:
                                return 2586;
                            case Properties::West::NONE:
                                return 2587;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2588;
                            case Properties::West::SIDE:
                                return 2589;
                            case Properties::West::NONE:
                                return 2590;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2591;
                            case Properties::West::SIDE:
                                return 2592;
                            case Properties::West::NONE:
                                return 2593;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2594;
                            case Properties::West::SIDE:
                                return 2595;
                            case Properties::West::NONE:
                                return 2596;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2597;
                            case Properties::West::SIDE:
                                return 2598;
                            case Properties::West::NONE:
                                return 2599;
                            }
                        }
                    }
                case Properties::North::NONE:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2600;
                            case Properties::West::SIDE:
                                return 2601;
                            case Properties::West::NONE:
                                return 2602;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2603;
                            case Properties::West::SIDE:
                                return 2604;
                            case Properties::West::NONE:
                                return 2605;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2606;
                            case Properties::West::SIDE:
                                return 2607;
                            case Properties::West::NONE:
                                return 2608;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2609;
                            case Properties::West::SIDE:
                                return 2610;
                            case Properties::West::NONE:
                                return 2611;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2612;
                            case Properties::West::SIDE:
                                return 2613;
                            case Properties::West::NONE:
                                return 2614;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2615;
                            case Properties::West::SIDE:
                                return 2616;
                            case Properties::West::NONE:
                                return 2617;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2618;
                            case Properties::West::SIDE:
                                return 2619;
                            case Properties::West::NONE:
                                return 2620;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2621;
                            case Properties::West::SIDE:
                                return 2622;
                            case Properties::West::NONE:
                                return 2623;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2624;
                            case Properties::West::SIDE:
                                return 2625;
                            case Properties::West::NONE:
                                return 2626;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2627;
                            case Properties::West::SIDE:
                                return 2628;
                            case Properties::West::NONE:
                                return 2629;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2630;
                            case Properties::West::SIDE:
                                return 2631;
                            case Properties::West::NONE:
                                return 2632;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2633;
                            case Properties::West::SIDE:
                                return 2634;
                            case Properties::West::NONE:
                                return 2635;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2636;
                            case Properties::West::SIDE:
                                return 2637;
                            case Properties::West::NONE:
                                return 2638;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2639;
                            case Properties::West::SIDE:
                                return 2640;
                            case Properties::West::NONE:
                                return 2641;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2642;
                            case Properties::West::SIDE:
                                return 2643;
                            case Properties::West::NONE:
                                return 2644;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2645;
                            case Properties::West::SIDE:
                                return 2646;
                            case Properties::West::NONE:
                                return 2647;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2648;
                            case Properties::West::SIDE:
                                return 2649;
                            case Properties::West::NONE:
                                return 2650;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2651;
                            case Properties::West::SIDE:
                                return 2652;
                            case Properties::West::NONE:
                                return 2653;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2654;
                            case Properties::West::SIDE:
                                return 2655;
                            case Properties::West::NONE:
                                return 2656;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2657;
                            case Properties::West::SIDE:
                                return 2658;
                            case Properties::West::NONE:
                                return 2659;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2660;
                            case Properties::West::SIDE:
                                return 2661;
                            case Properties::West::NONE:
                                return 2662;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2663;
                            case Properties::West::SIDE:
                                return 2664;
                            case Properties::West::NONE:
                                return 2665;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2666;
                            case Properties::West::SIDE:
                                return 2667;
                            case Properties::West::NONE:
                                return 2668;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2669;
                            case Properties::West::SIDE:
                                return 2670;
                            case Properties::West::NONE:
                                return 2671;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2672;
                            case Properties::West::SIDE:
                                return 2673;
                            case Properties::West::NONE:
                                return 2674;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2675;
                            case Properties::West::SIDE:
                                return 2676;
                            case Properties::West::NONE:
                                return 2677;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2678;
                            case Properties::West::SIDE:
                                return 2679;
                            case Properties::West::NONE:
                                return 2680;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2681;
                            case Properties::West::SIDE:
                                return 2682;
                            case Properties::West::NONE:
                                return 2683;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2684;
                            case Properties::West::SIDE:
                                return 2685;
                            case Properties::West::NONE:
                                return 2686;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2687;
                            case Properties::West::SIDE:
                                return 2688;
                            case Properties::West::NONE:
                                return 2689;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2690;
                            case Properties::West::SIDE:
                                return 2691;
                            case Properties::West::NONE:
                                return 2692;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2693;
                            case Properties::West::SIDE:
                                return 2694;
                            case Properties::West::NONE:
                                return 2695;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2696;
                            case Properties::West::SIDE:
                                return 2697;
                            case Properties::West::NONE:
                                return 2698;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2699;
                            case Properties::West::SIDE:
                                return 2700;
                            case Properties::West::NONE:
                                return 2701;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2702;
                            case Properties::West::SIDE:
                                return 2703;
                            case Properties::West::NONE:
                                return 2704;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2705;
                            case Properties::West::SIDE:
                                return 2706;
                            case Properties::West::NONE:
                                return 2707;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2708;
                            case Properties::West::SIDE:
                                return 2709;
                            case Properties::West::NONE:
                                return 2710;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2711;
                            case Properties::West::SIDE:
                                return 2712;
                            case Properties::West::NONE:
                                return 2713;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2714;
                            case Properties::West::SIDE:
                                return 2715;
                            case Properties::West::NONE:
                                return 2716;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2717;
                            case Properties::West::SIDE:
                                return 2718;
                            case Properties::West::NONE:
                                return 2719;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2720;
                            case Properties::West::SIDE:
                                return 2721;
                            case Properties::West::NONE:
                                return 2722;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2723;
                            case Properties::West::SIDE:
                                return 2724;
                            case Properties::West::NONE:
                                return 2725;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2726;
                            case Properties::West::SIDE:
                                return 2727;
                            case Properties::West::NONE:
                                return 2728;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2729;
                            case Properties::West::SIDE:
                                return 2730;
                            case Properties::West::NONE:
                                return 2731;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2732;
                            case Properties::West::SIDE:
                                return 2733;
                            case Properties::West::NONE:
                                return 2734;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2735;
                            case Properties::West::SIDE:
                                return 2736;
                            case Properties::West::NONE:
                                return 2737;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2738;
                            case Properties::West::SIDE:
                                return 2739;
                            case Properties::West::NONE:
                                return 2740;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2741;
                            case Properties::West::SIDE:
                                return 2742;
                            case Properties::West::NONE:
                                return 2743;
                            }
                        }
                    }
                }
            case Properties::East::SIDE:
                switch (north) {
                case Properties::North::UP:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2744;
                            case Properties::West::SIDE:
                                return 2745;
                            case Properties::West::NONE:
                                return 2746;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2747;
                            case Properties::West::SIDE:
                                return 2748;
                            case Properties::West::NONE:
                                return 2749;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2750;
                            case Properties::West::SIDE:
                                return 2751;
                            case Properties::West::NONE:
                                return 2752;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2753;
                            case Properties::West::SIDE:
                                return 2754;
                            case Properties::West::NONE:
                                return 2755;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2756;
                            case Properties::West::SIDE:
                                return 2757;
                            case Properties::West::NONE:
                                return 2758;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2759;
                            case Properties::West::SIDE:
                                return 2760;
                            case Properties::West::NONE:
                                return 2761;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2762;
                            case Properties::West::SIDE:
                                return 2763;
                            case Properties::West::NONE:
                                return 2764;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2765;
                            case Properties::West::SIDE:
                                return 2766;
                            case Properties::West::NONE:
                                return 2767;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2768;
                            case Properties::West::SIDE:
                                return 2769;
                            case Properties::West::NONE:
                                return 2770;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2771;
                            case Properties::West::SIDE:
                                return 2772;
                            case Properties::West::NONE:
                                return 2773;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2774;
                            case Properties::West::SIDE:
                                return 2775;
                            case Properties::West::NONE:
                                return 2776;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2777;
                            case Properties::West::SIDE:
                                return 2778;
                            case Properties::West::NONE:
                                return 2779;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2780;
                            case Properties::West::SIDE:
                                return 2781;
                            case Properties::West::NONE:
                                return 2782;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2783;
                            case Properties::West::SIDE:
                                return 2784;
                            case Properties::West::NONE:
                                return 2785;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2786;
                            case Properties::West::SIDE:
                                return 2787;
                            case Properties::West::NONE:
                                return 2788;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2789;
                            case Properties::West::SIDE:
                                return 2790;
                            case Properties::West::NONE:
                                return 2791;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2792;
                            case Properties::West::SIDE:
                                return 2793;
                            case Properties::West::NONE:
                                return 2794;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2795;
                            case Properties::West::SIDE:
                                return 2796;
                            case Properties::West::NONE:
                                return 2797;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2798;
                            case Properties::West::SIDE:
                                return 2799;
                            case Properties::West::NONE:
                                return 2800;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2801;
                            case Properties::West::SIDE:
                                return 2802;
                            case Properties::West::NONE:
                                return 2803;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2804;
                            case Properties::West::SIDE:
                                return 2805;
                            case Properties::West::NONE:
                                return 2806;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2807;
                            case Properties::West::SIDE:
                                return 2808;
                            case Properties::West::NONE:
                                return 2809;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2810;
                            case Properties::West::SIDE:
                                return 2811;
                            case Properties::West::NONE:
                                return 2812;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2813;
                            case Properties::West::SIDE:
                                return 2814;
                            case Properties::West::NONE:
                                return 2815;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2816;
                            case Properties::West::SIDE:
                                return 2817;
                            case Properties::West::NONE:
                                return 2818;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2819;
                            case Properties::West::SIDE:
                                return 2820;
                            case Properties::West::NONE:
                                return 2821;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2822;
                            case Properties::West::SIDE:
                                return 2823;
                            case Properties::West::NONE:
                                return 2824;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2825;
                            case Properties::West::SIDE:
                                return 2826;
                            case Properties::West::NONE:
                                return 2827;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2828;
                            case Properties::West::SIDE:
                                return 2829;
                            case Properties::West::NONE:
                                return 2830;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2831;
                            case Properties::West::SIDE:
                                return 2832;
                            case Properties::West::NONE:
                                return 2833;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2834;
                            case Properties::West::SIDE:
                                return 2835;
                            case Properties::West::NONE:
                                return 2836;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2837;
                            case Properties::West::SIDE:
                                return 2838;
                            case Properties::West::NONE:
                                return 2839;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2840;
                            case Properties::West::SIDE:
                                return 2841;
                            case Properties::West::NONE:
                                return 2842;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2843;
                            case Properties::West::SIDE:
                                return 2844;
                            case Properties::West::NONE:
                                return 2845;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2846;
                            case Properties::West::SIDE:
                                return 2847;
                            case Properties::West::NONE:
                                return 2848;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2849;
                            case Properties::West::SIDE:
                                return 2850;
                            case Properties::West::NONE:
                                return 2851;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2852;
                            case Properties::West::SIDE:
                                return 2853;
                            case Properties::West::NONE:
                                return 2854;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2855;
                            case Properties::West::SIDE:
                                return 2856;
                            case Properties::West::NONE:
                                return 2857;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2858;
                            case Properties::West::SIDE:
                                return 2859;
                            case Properties::West::NONE:
                                return 2860;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2861;
                            case Properties::West::SIDE:
                                return 2862;
                            case Properties::West::NONE:
                                return 2863;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2864;
                            case Properties::West::SIDE:
                                return 2865;
                            case Properties::West::NONE:
                                return 2866;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2867;
                            case Properties::West::SIDE:
                                return 2868;
                            case Properties::West::NONE:
                                return 2869;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2870;
                            case Properties::West::SIDE:
                                return 2871;
                            case Properties::West::NONE:
                                return 2872;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2873;
                            case Properties::West::SIDE:
                                return 2874;
                            case Properties::West::NONE:
                                return 2875;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2876;
                            case Properties::West::SIDE:
                                return 2877;
                            case Properties::West::NONE:
                                return 2878;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2879;
                            case Properties::West::SIDE:
                                return 2880;
                            case Properties::West::NONE:
                                return 2881;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2882;
                            case Properties::West::SIDE:
                                return 2883;
                            case Properties::West::NONE:
                                return 2884;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2885;
                            case Properties::West::SIDE:
                                return 2886;
                            case Properties::West::NONE:
                                return 2887;
                            }
                        }
                    }
                case Properties::North::SIDE:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2888;
                            case Properties::West::SIDE:
                                return 2889;
                            case Properties::West::NONE:
                                return 2890;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2891;
                            case Properties::West::SIDE:
                                return 2892;
                            case Properties::West::NONE:
                                return 2893;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2894;
                            case Properties::West::SIDE:
                                return 2895;
                            case Properties::West::NONE:
                                return 2896;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2897;
                            case Properties::West::SIDE:
                                return 2898;
                            case Properties::West::NONE:
                                return 2899;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2900;
                            case Properties::West::SIDE:
                                return 2901;
                            case Properties::West::NONE:
                                return 2902;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2903;
                            case Properties::West::SIDE:
                                return 2904;
                            case Properties::West::NONE:
                                return 2905;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2906;
                            case Properties::West::SIDE:
                                return 2907;
                            case Properties::West::NONE:
                                return 2908;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2909;
                            case Properties::West::SIDE:
                                return 2910;
                            case Properties::West::NONE:
                                return 2911;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2912;
                            case Properties::West::SIDE:
                                return 2913;
                            case Properties::West::NONE:
                                return 2914;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2915;
                            case Properties::West::SIDE:
                                return 2916;
                            case Properties::West::NONE:
                                return 2917;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2918;
                            case Properties::West::SIDE:
                                return 2919;
                            case Properties::West::NONE:
                                return 2920;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2921;
                            case Properties::West::SIDE:
                                return 2922;
                            case Properties::West::NONE:
                                return 2923;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2924;
                            case Properties::West::SIDE:
                                return 2925;
                            case Properties::West::NONE:
                                return 2926;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2927;
                            case Properties::West::SIDE:
                                return 2928;
                            case Properties::West::NONE:
                                return 2929;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2930;
                            case Properties::West::SIDE:
                                return 2931;
                            case Properties::West::NONE:
                                return 2932;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2933;
                            case Properties::West::SIDE:
                                return 2934;
                            case Properties::West::NONE:
                                return 2935;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2936;
                            case Properties::West::SIDE:
                                return 2937;
                            case Properties::West::NONE:
                                return 2938;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2939;
                            case Properties::West::SIDE:
                                return 2940;
                            case Properties::West::NONE:
                                return 2941;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2942;
                            case Properties::West::SIDE:
                                return 2943;
                            case Properties::West::NONE:
                                return 2944;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2945;
                            case Properties::West::SIDE:
                                return 2946;
                            case Properties::West::NONE:
                                return 2947;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2948;
                            case Properties::West::SIDE:
                                return 2949;
                            case Properties::West::NONE:
                                return 2950;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2951;
                            case Properties::West::SIDE:
                                return 2952;
                            case Properties::West::NONE:
                                return 2953;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2954;
                            case Properties::West::SIDE:
                                return 2955;
                            case Properties::West::NONE:
                                return 2956;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2957;
                            case Properties::West::SIDE:
                                return 2958;
                            case Properties::West::NONE:
                                return 2959;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2960;
                            case Properties::West::SIDE:
                                return 2961;
                            case Properties::West::NONE:
                                return 2962;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2963;
                            case Properties::West::SIDE:
                                return 2964;
                            case Properties::West::NONE:
                                return 2965;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2966;
                            case Properties::West::SIDE:
                                return 2967;
                            case Properties::West::NONE:
                                return 2968;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2969;
                            case Properties::West::SIDE:
                                return 2970;
                            case Properties::West::NONE:
                                return 2971;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2972;
                            case Properties::West::SIDE:
                                return 2973;
                            case Properties::West::NONE:
                                return 2974;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2975;
                            case Properties::West::SIDE:
                                return 2976;
                            case Properties::West::NONE:
                                return 2977;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2978;
                            case Properties::West::SIDE:
                                return 2979;
                            case Properties::West::NONE:
                                return 2980;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2981;
                            case Properties::West::SIDE:
                                return 2982;
                            case Properties::West::NONE:
                                return 2983;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2984;
                            case Properties::West::SIDE:
                                return 2985;
                            case Properties::West::NONE:
                                return 2986;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2987;
                            case Properties::West::SIDE:
                                return 2988;
                            case Properties::West::NONE:
                                return 2989;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2990;
                            case Properties::West::SIDE:
                                return 2991;
                            case Properties::West::NONE:
                                return 2992;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2993;
                            case Properties::West::SIDE:
                                return 2994;
                            case Properties::West::NONE:
                                return 2995;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 2996;
                            case Properties::West::SIDE:
                                return 2997;
                            case Properties::West::NONE:
                                return 2998;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 2999;
                            case Properties::West::SIDE:
                                return 3000;
                            case Properties::West::NONE:
                                return 3001;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3002;
                            case Properties::West::SIDE:
                                return 3003;
                            case Properties::West::NONE:
                                return 3004;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3005;
                            case Properties::West::SIDE:
                                return 3006;
                            case Properties::West::NONE:
                                return 3007;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3008;
                            case Properties::West::SIDE:
                                return 3009;
                            case Properties::West::NONE:
                                return 3010;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3011;
                            case Properties::West::SIDE:
                                return 3012;
                            case Properties::West::NONE:
                                return 3013;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3014;
                            case Properties::West::SIDE:
                                return 3015;
                            case Properties::West::NONE:
                                return 3016;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3017;
                            case Properties::West::SIDE:
                                return 3018;
                            case Properties::West::NONE:
                                return 3019;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3020;
                            case Properties::West::SIDE:
                                return 3021;
                            case Properties::West::NONE:
                                return 3022;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3023;
                            case Properties::West::SIDE:
                                return 3024;
                            case Properties::West::NONE:
                                return 3025;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3026;
                            case Properties::West::SIDE:
                                return 3027;
                            case Properties::West::NONE:
                                return 3028;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3029;
                            case Properties::West::SIDE:
                                return 3030;
                            case Properties::West::NONE:
                                return 3031;
                            }
                        }
                    }
                case Properties::North::NONE:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3032;
                            case Properties::West::SIDE:
                                return 3033;
                            case Properties::West::NONE:
                                return 3034;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3035;
                            case Properties::West::SIDE:
                                return 3036;
                            case Properties::West::NONE:
                                return 3037;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3038;
                            case Properties::West::SIDE:
                                return 3039;
                            case Properties::West::NONE:
                                return 3040;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3041;
                            case Properties::West::SIDE:
                                return 3042;
                            case Properties::West::NONE:
                                return 3043;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3044;
                            case Properties::West::SIDE:
                                return 3045;
                            case Properties::West::NONE:
                                return 3046;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3047;
                            case Properties::West::SIDE:
                                return 3048;
                            case Properties::West::NONE:
                                return 3049;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3050;
                            case Properties::West::SIDE:
                                return 3051;
                            case Properties::West::NONE:
                                return 3052;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3053;
                            case Properties::West::SIDE:
                                return 3054;
                            case Properties::West::NONE:
                                return 3055;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3056;
                            case Properties::West::SIDE:
                                return 3057;
                            case Properties::West::NONE:
                                return 3058;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3059;
                            case Properties::West::SIDE:
                                return 3060;
                            case Properties::West::NONE:
                                return 3061;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3062;
                            case Properties::West::SIDE:
                                return 3063;
                            case Properties::West::NONE:
                                return 3064;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3065;
                            case Properties::West::SIDE:
                                return 3066;
                            case Properties::West::NONE:
                                return 3067;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3068;
                            case Properties::West::SIDE:
                                return 3069;
                            case Properties::West::NONE:
                                return 3070;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3071;
                            case Properties::West::SIDE:
                                return 3072;
                            case Properties::West::NONE:
                                return 3073;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3074;
                            case Properties::West::SIDE:
                                return 3075;
                            case Properties::West::NONE:
                                return 3076;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3077;
                            case Properties::West::SIDE:
                                return 3078;
                            case Properties::West::NONE:
                                return 3079;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3080;
                            case Properties::West::SIDE:
                                return 3081;
                            case Properties::West::NONE:
                                return 3082;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3083;
                            case Properties::West::SIDE:
                                return 3084;
                            case Properties::West::NONE:
                                return 3085;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3086;
                            case Properties::West::SIDE:
                                return 3087;
                            case Properties::West::NONE:
                                return 3088;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3089;
                            case Properties::West::SIDE:
                                return 3090;
                            case Properties::West::NONE:
                                return 3091;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3092;
                            case Properties::West::SIDE:
                                return 3093;
                            case Properties::West::NONE:
                                return 3094;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3095;
                            case Properties::West::SIDE:
                                return 3096;
                            case Properties::West::NONE:
                                return 3097;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3098;
                            case Properties::West::SIDE:
                                return 3099;
                            case Properties::West::NONE:
                                return 3100;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3101;
                            case Properties::West::SIDE:
                                return 3102;
                            case Properties::West::NONE:
                                return 3103;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3104;
                            case Properties::West::SIDE:
                                return 3105;
                            case Properties::West::NONE:
                                return 3106;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3107;
                            case Properties::West::SIDE:
                                return 3108;
                            case Properties::West::NONE:
                                return 3109;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3110;
                            case Properties::West::SIDE:
                                return 3111;
                            case Properties::West::NONE:
                                return 3112;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3113;
                            case Properties::West::SIDE:
                                return 3114;
                            case Properties::West::NONE:
                                return 3115;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3116;
                            case Properties::West::SIDE:
                                return 3117;
                            case Properties::West::NONE:
                                return 3118;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3119;
                            case Properties::West::SIDE:
                                return 3120;
                            case Properties::West::NONE:
                                return 3121;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3122;
                            case Properties::West::SIDE:
                                return 3123;
                            case Properties::West::NONE:
                                return 3124;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3125;
                            case Properties::West::SIDE:
                                return 3126;
                            case Properties::West::NONE:
                                return 3127;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3128;
                            case Properties::West::SIDE:
                                return 3129;
                            case Properties::West::NONE:
                                return 3130;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3131;
                            case Properties::West::SIDE:
                                return 3132;
                            case Properties::West::NONE:
                                return 3133;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3134;
                            case Properties::West::SIDE:
                                return 3135;
                            case Properties::West::NONE:
                                return 3136;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3137;
                            case Properties::West::SIDE:
                                return 3138;
                            case Properties::West::NONE:
                                return 3139;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3140;
                            case Properties::West::SIDE:
                                return 3141;
                            case Properties::West::NONE:
                                return 3142;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3143;
                            case Properties::West::SIDE:
                                return 3144;
                            case Properties::West::NONE:
                                return 3145;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3146;
                            case Properties::West::SIDE:
                                return 3147;
                            case Properties::West::NONE:
                                return 3148;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3149;
                            case Properties::West::SIDE:
                                return 3150;
                            case Properties::West::NONE:
                                return 3151;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3152;
                            case Properties::West::SIDE:
                                return 3153;
                            case Properties::West::NONE:
                                return 3154;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3155;
                            case Properties::West::SIDE:
                                return 3156;
                            case Properties::West::NONE:
                                return 3157;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3158;
                            case Properties::West::SIDE:
                                return 3159;
                            case Properties::West::NONE:
                                return 3160;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3161;
                            case Properties::West::SIDE:
                                return 3162;
                            case Properties::West::NONE:
                                return 3163;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3164;
                            case Properties::West::SIDE:
                                return 3165;
                            case Properties::West::NONE:
                                return 3166;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3167;
                            case Properties::West::SIDE:
                                return 3168;
                            case Properties::West::NONE:
                                return 3169;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3170;
                            case Properties::West::SIDE:
                                return 3171;
                            case Properties::West::NONE:
                                return 3172;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3173;
                            case Properties::West::SIDE:
                                return 3174;
                            case Properties::West::NONE:
                                return 3175;
                            }
                        }
                    }
                }
            case Properties::East::NONE:
                switch (north) {
                case Properties::North::UP:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3176;
                            case Properties::West::SIDE:
                                return 3177;
                            case Properties::West::NONE:
                                return 3178;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3179;
                            case Properties::West::SIDE:
                                return 3180;
                            case Properties::West::NONE:
                                return 3181;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3182;
                            case Properties::West::SIDE:
                                return 3183;
                            case Properties::West::NONE:
                                return 3184;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3185;
                            case Properties::West::SIDE:
                                return 3186;
                            case Properties::West::NONE:
                                return 3187;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3188;
                            case Properties::West::SIDE:
                                return 3189;
                            case Properties::West::NONE:
                                return 3190;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3191;
                            case Properties::West::SIDE:
                                return 3192;
                            case Properties::West::NONE:
                                return 3193;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3194;
                            case Properties::West::SIDE:
                                return 3195;
                            case Properties::West::NONE:
                                return 3196;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3197;
                            case Properties::West::SIDE:
                                return 3198;
                            case Properties::West::NONE:
                                return 3199;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3200;
                            case Properties::West::SIDE:
                                return 3201;
                            case Properties::West::NONE:
                                return 3202;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3203;
                            case Properties::West::SIDE:
                                return 3204;
                            case Properties::West::NONE:
                                return 3205;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3206;
                            case Properties::West::SIDE:
                                return 3207;
                            case Properties::West::NONE:
                                return 3208;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3209;
                            case Properties::West::SIDE:
                                return 3210;
                            case Properties::West::NONE:
                                return 3211;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3212;
                            case Properties::West::SIDE:
                                return 3213;
                            case Properties::West::NONE:
                                return 3214;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3215;
                            case Properties::West::SIDE:
                                return 3216;
                            case Properties::West::NONE:
                                return 3217;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3218;
                            case Properties::West::SIDE:
                                return 3219;
                            case Properties::West::NONE:
                                return 3220;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3221;
                            case Properties::West::SIDE:
                                return 3222;
                            case Properties::West::NONE:
                                return 3223;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3224;
                            case Properties::West::SIDE:
                                return 3225;
                            case Properties::West::NONE:
                                return 3226;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3227;
                            case Properties::West::SIDE:
                                return 3228;
                            case Properties::West::NONE:
                                return 3229;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3230;
                            case Properties::West::SIDE:
                                return 3231;
                            case Properties::West::NONE:
                                return 3232;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3233;
                            case Properties::West::SIDE:
                                return 3234;
                            case Properties::West::NONE:
                                return 3235;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3236;
                            case Properties::West::SIDE:
                                return 3237;
                            case Properties::West::NONE:
                                return 3238;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3239;
                            case Properties::West::SIDE:
                                return 3240;
                            case Properties::West::NONE:
                                return 3241;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3242;
                            case Properties::West::SIDE:
                                return 3243;
                            case Properties::West::NONE:
                                return 3244;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3245;
                            case Properties::West::SIDE:
                                return 3246;
                            case Properties::West::NONE:
                                return 3247;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3248;
                            case Properties::West::SIDE:
                                return 3249;
                            case Properties::West::NONE:
                                return 3250;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3251;
                            case Properties::West::SIDE:
                                return 3252;
                            case Properties::West::NONE:
                                return 3253;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3254;
                            case Properties::West::SIDE:
                                return 3255;
                            case Properties::West::NONE:
                                return 3256;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3257;
                            case Properties::West::SIDE:
                                return 3258;
                            case Properties::West::NONE:
                                return 3259;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3260;
                            case Properties::West::SIDE:
                                return 3261;
                            case Properties::West::NONE:
                                return 3262;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3263;
                            case Properties::West::SIDE:
                                return 3264;
                            case Properties::West::NONE:
                                return 3265;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3266;
                            case Properties::West::SIDE:
                                return 3267;
                            case Properties::West::NONE:
                                return 3268;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3269;
                            case Properties::West::SIDE:
                                return 3270;
                            case Properties::West::NONE:
                                return 3271;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3272;
                            case Properties::West::SIDE:
                                return 3273;
                            case Properties::West::NONE:
                                return 3274;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3275;
                            case Properties::West::SIDE:
                                return 3276;
                            case Properties::West::NONE:
                                return 3277;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3278;
                            case Properties::West::SIDE:
                                return 3279;
                            case Properties::West::NONE:
                                return 3280;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3281;
                            case Properties::West::SIDE:
                                return 3282;
                            case Properties::West::NONE:
                                return 3283;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3284;
                            case Properties::West::SIDE:
                                return 3285;
                            case Properties::West::NONE:
                                return 3286;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3287;
                            case Properties::West::SIDE:
                                return 3288;
                            case Properties::West::NONE:
                                return 3289;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3290;
                            case Properties::West::SIDE:
                                return 3291;
                            case Properties::West::NONE:
                                return 3292;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3293;
                            case Properties::West::SIDE:
                                return 3294;
                            case Properties::West::NONE:
                                return 3295;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3296;
                            case Properties::West::SIDE:
                                return 3297;
                            case Properties::West::NONE:
                                return 3298;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3299;
                            case Properties::West::SIDE:
                                return 3300;
                            case Properties::West::NONE:
                                return 3301;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3302;
                            case Properties::West::SIDE:
                                return 3303;
                            case Properties::West::NONE:
                                return 3304;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3305;
                            case Properties::West::SIDE:
                                return 3306;
                            case Properties::West::NONE:
                                return 3307;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3308;
                            case Properties::West::SIDE:
                                return 3309;
                            case Properties::West::NONE:
                                return 3310;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3311;
                            case Properties::West::SIDE:
                                return 3312;
                            case Properties::West::NONE:
                                return 3313;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3314;
                            case Properties::West::SIDE:
                                return 3315;
                            case Properties::West::NONE:
                                return 3316;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3317;
                            case Properties::West::SIDE:
                                return 3318;
                            case Properties::West::NONE:
                                return 3319;
                            }
                        }
                    }
                case Properties::North::SIDE:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3320;
                            case Properties::West::SIDE:
                                return 3321;
                            case Properties::West::NONE:
                                return 3322;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3323;
                            case Properties::West::SIDE:
                                return 3324;
                            case Properties::West::NONE:
                                return 3325;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3326;
                            case Properties::West::SIDE:
                                return 3327;
                            case Properties::West::NONE:
                                return 3328;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3329;
                            case Properties::West::SIDE:
                                return 3330;
                            case Properties::West::NONE:
                                return 3331;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3332;
                            case Properties::West::SIDE:
                                return 3333;
                            case Properties::West::NONE:
                                return 3334;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3335;
                            case Properties::West::SIDE:
                                return 3336;
                            case Properties::West::NONE:
                                return 3337;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3338;
                            case Properties::West::SIDE:
                                return 3339;
                            case Properties::West::NONE:
                                return 3340;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3341;
                            case Properties::West::SIDE:
                                return 3342;
                            case Properties::West::NONE:
                                return 3343;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3344;
                            case Properties::West::SIDE:
                                return 3345;
                            case Properties::West::NONE:
                                return 3346;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3347;
                            case Properties::West::SIDE:
                                return 3348;
                            case Properties::West::NONE:
                                return 3349;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3350;
                            case Properties::West::SIDE:
                                return 3351;
                            case Properties::West::NONE:
                                return 3352;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3353;
                            case Properties::West::SIDE:
                                return 3354;
                            case Properties::West::NONE:
                                return 3355;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3356;
                            case Properties::West::SIDE:
                                return 3357;
                            case Properties::West::NONE:
                                return 3358;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3359;
                            case Properties::West::SIDE:
                                return 3360;
                            case Properties::West::NONE:
                                return 3361;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3362;
                            case Properties::West::SIDE:
                                return 3363;
                            case Properties::West::NONE:
                                return 3364;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3365;
                            case Properties::West::SIDE:
                                return 3366;
                            case Properties::West::NONE:
                                return 3367;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3368;
                            case Properties::West::SIDE:
                                return 3369;
                            case Properties::West::NONE:
                                return 3370;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3371;
                            case Properties::West::SIDE:
                                return 3372;
                            case Properties::West::NONE:
                                return 3373;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3374;
                            case Properties::West::SIDE:
                                return 3375;
                            case Properties::West::NONE:
                                return 3376;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3377;
                            case Properties::West::SIDE:
                                return 3378;
                            case Properties::West::NONE:
                                return 3379;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3380;
                            case Properties::West::SIDE:
                                return 3381;
                            case Properties::West::NONE:
                                return 3382;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3383;
                            case Properties::West::SIDE:
                                return 3384;
                            case Properties::West::NONE:
                                return 3385;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3386;
                            case Properties::West::SIDE:
                                return 3387;
                            case Properties::West::NONE:
                                return 3388;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3389;
                            case Properties::West::SIDE:
                                return 3390;
                            case Properties::West::NONE:
                                return 3391;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3392;
                            case Properties::West::SIDE:
                                return 3393;
                            case Properties::West::NONE:
                                return 3394;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3395;
                            case Properties::West::SIDE:
                                return 3396;
                            case Properties::West::NONE:
                                return 3397;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3398;
                            case Properties::West::SIDE:
                                return 3399;
                            case Properties::West::NONE:
                                return 3400;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3401;
                            case Properties::West::SIDE:
                                return 3402;
                            case Properties::West::NONE:
                                return 3403;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3404;
                            case Properties::West::SIDE:
                                return 3405;
                            case Properties::West::NONE:
                                return 3406;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3407;
                            case Properties::West::SIDE:
                                return 3408;
                            case Properties::West::NONE:
                                return 3409;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3410;
                            case Properties::West::SIDE:
                                return 3411;
                            case Properties::West::NONE:
                                return 3412;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3413;
                            case Properties::West::SIDE:
                                return 3414;
                            case Properties::West::NONE:
                                return 3415;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3416;
                            case Properties::West::SIDE:
                                return 3417;
                            case Properties::West::NONE:
                                return 3418;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3419;
                            case Properties::West::SIDE:
                                return 3420;
                            case Properties::West::NONE:
                                return 3421;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3422;
                            case Properties::West::SIDE:
                                return 3423;
                            case Properties::West::NONE:
                                return 3424;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3425;
                            case Properties::West::SIDE:
                                return 3426;
                            case Properties::West::NONE:
                                return 3427;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3428;
                            case Properties::West::SIDE:
                                return 3429;
                            case Properties::West::NONE:
                                return 3430;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3431;
                            case Properties::West::SIDE:
                                return 3432;
                            case Properties::West::NONE:
                                return 3433;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3434;
                            case Properties::West::SIDE:
                                return 3435;
                            case Properties::West::NONE:
                                return 3436;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3437;
                            case Properties::West::SIDE:
                                return 3438;
                            case Properties::West::NONE:
                                return 3439;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3440;
                            case Properties::West::SIDE:
                                return 3441;
                            case Properties::West::NONE:
                                return 3442;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3443;
                            case Properties::West::SIDE:
                                return 3444;
                            case Properties::West::NONE:
                                return 3445;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3446;
                            case Properties::West::SIDE:
                                return 3447;
                            case Properties::West::NONE:
                                return 3448;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3449;
                            case Properties::West::SIDE:
                                return 3450;
                            case Properties::West::NONE:
                                return 3451;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3452;
                            case Properties::West::SIDE:
                                return 3453;
                            case Properties::West::NONE:
                                return 3454;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3455;
                            case Properties::West::SIDE:
                                return 3456;
                            case Properties::West::NONE:
                                return 3457;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3458;
                            case Properties::West::SIDE:
                                return 3459;
                            case Properties::West::NONE:
                                return 3460;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3461;
                            case Properties::West::SIDE:
                                return 3462;
                            case Properties::West::NONE:
                                return 3463;
                            }
                        }
                    }
                case Properties::North::NONE:
                    switch (power) {
                    case Properties::Power::ZERO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3464;
                            case Properties::West::SIDE:
                                return 3465;
                            case Properties::West::NONE:
                                return 3466;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3467;
                            case Properties::West::SIDE:
                                return 3468;
                            case Properties::West::NONE:
                                return 3469;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3470;
                            case Properties::West::SIDE:
                                return 3471;
                            case Properties::West::NONE:
                                return 3472;
                            }
                        }
                    case Properties::Power::ONE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3473;
                            case Properties::West::SIDE:
                                return 3474;
                            case Properties::West::NONE:
                                return 3475;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3476;
                            case Properties::West::SIDE:
                                return 3477;
                            case Properties::West::NONE:
                                return 3478;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3479;
                            case Properties::West::SIDE:
                                return 3480;
                            case Properties::West::NONE:
                                return 3481;
                            }
                        }
                    case Properties::Power::TWO:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3482;
                            case Properties::West::SIDE:
                                return 3483;
                            case Properties::West::NONE:
                                return 3484;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3485;
                            case Properties::West::SIDE:
                                return 3486;
                            case Properties::West::NONE:
                                return 3487;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3488;
                            case Properties::West::SIDE:
                                return 3489;
                            case Properties::West::NONE:
                                return 3490;
                            }
                        }
                    case Properties::Power::THREE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3491;
                            case Properties::West::SIDE:
                                return 3492;
                            case Properties::West::NONE:
                                return 3493;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3494;
                            case Properties::West::SIDE:
                                return 3495;
                            case Properties::West::NONE:
                                return 3496;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3497;
                            case Properties::West::SIDE:
                                return 3498;
                            case Properties::West::NONE:
                                return 3499;
                            }
                        }
                    case Properties::Power::FOUR:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3500;
                            case Properties::West::SIDE:
                                return 3501;
                            case Properties::West::NONE:
                                return 3502;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3503;
                            case Properties::West::SIDE:
                                return 3504;
                            case Properties::West::NONE:
                                return 3505;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3506;
                            case Properties::West::SIDE:
                                return 3507;
                            case Properties::West::NONE:
                                return 3508;
                            }
                        }
                    case Properties::Power::FIVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3509;
                            case Properties::West::SIDE:
                                return 3510;
                            case Properties::West::NONE:
                                return 3511;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3512;
                            case Properties::West::SIDE:
                                return 3513;
                            case Properties::West::NONE:
                                return 3514;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3515;
                            case Properties::West::SIDE:
                                return 3516;
                            case Properties::West::NONE:
                                return 3517;
                            }
                        }
                    case Properties::Power::SIX:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3518;
                            case Properties::West::SIDE:
                                return 3519;
                            case Properties::West::NONE:
                                return 3520;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3521;
                            case Properties::West::SIDE:
                                return 3522;
                            case Properties::West::NONE:
                                return 3523;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3524;
                            case Properties::West::SIDE:
                                return 3525;
                            case Properties::West::NONE:
                                return 3526;
                            }
                        }
                    case Properties::Power::SEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3527;
                            case Properties::West::SIDE:
                                return 3528;
                            case Properties::West::NONE:
                                return 3529;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3530;
                            case Properties::West::SIDE:
                                return 3531;
                            case Properties::West::NONE:
                                return 3532;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3533;
                            case Properties::West::SIDE:
                                return 3534;
                            case Properties::West::NONE:
                                return 3535;
                            }
                        }
                    case Properties::Power::EIGHT:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3536;
                            case Properties::West::SIDE:
                                return 3537;
                            case Properties::West::NONE:
                                return 3538;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3539;
                            case Properties::West::SIDE:
                                return 3540;
                            case Properties::West::NONE:
                                return 3541;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3542;
                            case Properties::West::SIDE:
                                return 3543;
                            case Properties::West::NONE:
                                return 3544;
                            }
                        }
                    case Properties::Power::NINE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3545;
                            case Properties::West::SIDE:
                                return 3546;
                            case Properties::West::NONE:
                                return 3547;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3548;
                            case Properties::West::SIDE:
                                return 3549;
                            case Properties::West::NONE:
                                return 3550;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3551;
                            case Properties::West::SIDE:
                                return 3552;
                            case Properties::West::NONE:
                                return 3553;
                            }
                        }
                    case Properties::Power::TEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3554;
                            case Properties::West::SIDE:
                                return 3555;
                            case Properties::West::NONE:
                                return 3556;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3557;
                            case Properties::West::SIDE:
                                return 3558;
                            case Properties::West::NONE:
                                return 3559;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3560;
                            case Properties::West::SIDE:
                                return 3561;
                            case Properties::West::NONE:
                                return 3562;
                            }
                        }
                    case Properties::Power::ELEVEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3563;
                            case Properties::West::SIDE:
                                return 3564;
                            case Properties::West::NONE:
                                return 3565;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3566;
                            case Properties::West::SIDE:
                                return 3567;
                            case Properties::West::NONE:
                                return 3568;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3569;
                            case Properties::West::SIDE:
                                return 3570;
                            case Properties::West::NONE:
                                return 3571;
                            }
                        }
                    case Properties::Power::TWELVE:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3572;
                            case Properties::West::SIDE:
                                return 3573;
                            case Properties::West::NONE:
                                return 3574;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3575;
                            case Properties::West::SIDE:
                                return 3576;
                            case Properties::West::NONE:
                                return 3577;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3578;
                            case Properties::West::SIDE:
                                return 3579;
                            case Properties::West::NONE:
                                return 3580;
                            }
                        }
                    case Properties::Power::THIRTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3581;
                            case Properties::West::SIDE:
                                return 3582;
                            case Properties::West::NONE:
                                return 3583;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3584;
                            case Properties::West::SIDE:
                                return 3585;
                            case Properties::West::NONE:
                                return 3586;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3587;
                            case Properties::West::SIDE:
                                return 3588;
                            case Properties::West::NONE:
                                return 3589;
                            }
                        }
                    case Properties::Power::FOURTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3590;
                            case Properties::West::SIDE:
                                return 3591;
                            case Properties::West::NONE:
                                return 3592;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3593;
                            case Properties::West::SIDE:
                                return 3594;
                            case Properties::West::NONE:
                                return 3595;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3596;
                            case Properties::West::SIDE:
                                return 3597;
                            case Properties::West::NONE:
                                return 3598;
                            }
                        }
                    case Properties::Power::FIFTEEN:
                        switch (south) {
                        case Properties::South::UP:
                            switch (west) {
                            case Properties::West::UP:
                                return 3599;
                            case Properties::West::SIDE:
                                return 3600;
                            case Properties::West::NONE:
                                return 3601;
                            }
                        case Properties::South::SIDE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3602;
                            case Properties::West::SIDE:
                                return 3603;
                            case Properties::West::NONE:
                                return 3604;
                            }
                        case Properties::South::NONE:
                            switch (west) {
                            case Properties::West::UP:
                                return 3605;
                            case Properties::West::SIDE:
                                return 3606;
                            case Properties::West::NONE:
                                return 3607;
                            }
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 5)
            throw std::runtime_error("Invalid number of properties");
            Properties::East east;
            Properties::North north;
            Properties::Power power;
            Properties::South south;
            Properties::West west;
            for (auto prop : properties) {
                if (prop.first == "east") {
                    if (prop.second == "up") {
                        east = Properties::East::UP;
                    } else if (prop.second == "side") {
                        east = Properties::East::SIDE;
                    } else if (prop.second == "none") {
                        east = Properties::East::NONE;
                    } else {
                        throw std::runtime_error("Invalid property \"east\" value");
                    }
                } else if (prop.first == "north") {
                    if (prop.second == "up") {
                        north = Properties::North::UP;
                    } else if (prop.second == "side") {
                        north = Properties::North::SIDE;
                    } else if (prop.second == "none") {
                        north = Properties::North::NONE;
                    } else {
                        throw std::runtime_error("Invalid property \"north\" value");
                    }
                } else if (prop.first == "power") {
                    if (prop.second == "0") {
                        power = Properties::Power::ZERO;
                    } else if (prop.second == "1") {
                        power = Properties::Power::ONE;
                    } else if (prop.second == "2") {
                        power = Properties::Power::TWO;
                    } else if (prop.second == "3") {
                        power = Properties::Power::THREE;
                    } else if (prop.second == "4") {
                        power = Properties::Power::FOUR;
                    } else if (prop.second == "5") {
                        power = Properties::Power::FIVE;
                    } else if (prop.second == "6") {
                        power = Properties::Power::SIX;
                    } else if (prop.second == "7") {
                        power = Properties::Power::SEVEN;
                    } else if (prop.second == "8") {
                        power = Properties::Power::EIGHT;
                    } else if (prop.second == "9") {
                        power = Properties::Power::NINE;
                    } else if (prop.second == "10") {
                        power = Properties::Power::TEN;
                    } else if (prop.second == "11") {
                        power = Properties::Power::ELEVEN;
                    } else if (prop.second == "12") {
                        power = Properties::Power::TWELVE;
                    } else if (prop.second == "13") {
                        power = Properties::Power::THIRTEEN;
                    } else if (prop.second == "14") {
                        power = Properties::Power::FOURTEEN;
                    } else if (prop.second == "15") {
                        power = Properties::Power::FIFTEEN;
                    } else {
                        throw std::runtime_error("Invalid property \"power\" value");
                    }
                } else if (prop.first == "south") {
                    if (prop.second == "up") {
                        south = Properties::South::UP;
                    } else if (prop.second == "side") {
                        south = Properties::South::SIDE;
                    } else if (prop.second == "none") {
                        south = Properties::South::NONE;
                    } else {
                        throw std::runtime_error("Invalid property \"south\" value");
                    }
                } else if (prop.first == "west") {
                    if (prop.second == "up") {
                        west = Properties::West::UP;
                    } else if (prop.second == "side") {
                        west = Properties::West::SIDE;
                    } else if (prop.second == "none") {
                        west = Properties::West::NONE;
                    } else {
                        throw std::runtime_error("Invalid property \"west\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(east, north, power, south, west);
        }
    }

}
