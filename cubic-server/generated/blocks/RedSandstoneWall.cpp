#include "RedSandstoneWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RedSandstoneWall {
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
                                    return 12396;
                                case Properties::West::LOW:
                                    return 12397;
                                case Properties::West::TALL:
                                    return 12398;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12399;
                                case Properties::West::LOW:
                                    return 12400;
                                case Properties::West::TALL:
                                    return 12401;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12402;
                                case Properties::West::LOW:
                                    return 12403;
                                case Properties::West::TALL:
                                    return 12404;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12405;
                                case Properties::West::LOW:
                                    return 12406;
                                case Properties::West::TALL:
                                    return 12407;
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
                                    return 12408;
                                case Properties::West::LOW:
                                    return 12409;
                                case Properties::West::TALL:
                                    return 12410;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12411;
                                case Properties::West::LOW:
                                    return 12412;
                                case Properties::West::TALL:
                                    return 12413;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12414;
                                case Properties::West::LOW:
                                    return 12415;
                                case Properties::West::TALL:
                                    return 12416;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12417;
                                case Properties::West::LOW:
                                    return 12418;
                                case Properties::West::TALL:
                                    return 12419;
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
                                    return 12420;
                                case Properties::West::LOW:
                                    return 12421;
                                case Properties::West::TALL:
                                    return 12422;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12423;
                                case Properties::West::LOW:
                                    return 12424;
                                case Properties::West::TALL:
                                    return 12425;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12426;
                                case Properties::West::LOW:
                                    return 12427;
                                case Properties::West::TALL:
                                    return 12428;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12429;
                                case Properties::West::LOW:
                                    return 12430;
                                case Properties::West::TALL:
                                    return 12431;
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
                                    return 12432;
                                case Properties::West::LOW:
                                    return 12433;
                                case Properties::West::TALL:
                                    return 12434;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12435;
                                case Properties::West::LOW:
                                    return 12436;
                                case Properties::West::TALL:
                                    return 12437;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12438;
                                case Properties::West::LOW:
                                    return 12439;
                                case Properties::West::TALL:
                                    return 12440;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12441;
                                case Properties::West::LOW:
                                    return 12442;
                                case Properties::West::TALL:
                                    return 12443;
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
                                    return 12444;
                                case Properties::West::LOW:
                                    return 12445;
                                case Properties::West::TALL:
                                    return 12446;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12447;
                                case Properties::West::LOW:
                                    return 12448;
                                case Properties::West::TALL:
                                    return 12449;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12450;
                                case Properties::West::LOW:
                                    return 12451;
                                case Properties::West::TALL:
                                    return 12452;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12453;
                                case Properties::West::LOW:
                                    return 12454;
                                case Properties::West::TALL:
                                    return 12455;
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
                                    return 12456;
                                case Properties::West::LOW:
                                    return 12457;
                                case Properties::West::TALL:
                                    return 12458;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12459;
                                case Properties::West::LOW:
                                    return 12460;
                                case Properties::West::TALL:
                                    return 12461;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12462;
                                case Properties::West::LOW:
                                    return 12463;
                                case Properties::West::TALL:
                                    return 12464;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12465;
                                case Properties::West::LOW:
                                    return 12466;
                                case Properties::West::TALL:
                                    return 12467;
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
                                    return 12468;
                                case Properties::West::LOW:
                                    return 12469;
                                case Properties::West::TALL:
                                    return 12470;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12471;
                                case Properties::West::LOW:
                                    return 12472;
                                case Properties::West::TALL:
                                    return 12473;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12474;
                                case Properties::West::LOW:
                                    return 12475;
                                case Properties::West::TALL:
                                    return 12476;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12477;
                                case Properties::West::LOW:
                                    return 12478;
                                case Properties::West::TALL:
                                    return 12479;
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
                                    return 12480;
                                case Properties::West::LOW:
                                    return 12481;
                                case Properties::West::TALL:
                                    return 12482;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12483;
                                case Properties::West::LOW:
                                    return 12484;
                                case Properties::West::TALL:
                                    return 12485;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12486;
                                case Properties::West::LOW:
                                    return 12487;
                                case Properties::West::TALL:
                                    return 12488;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12489;
                                case Properties::West::LOW:
                                    return 12490;
                                case Properties::West::TALL:
                                    return 12491;
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
                                    return 12492;
                                case Properties::West::LOW:
                                    return 12493;
                                case Properties::West::TALL:
                                    return 12494;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12495;
                                case Properties::West::LOW:
                                    return 12496;
                                case Properties::West::TALL:
                                    return 12497;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12498;
                                case Properties::West::LOW:
                                    return 12499;
                                case Properties::West::TALL:
                                    return 12500;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12501;
                                case Properties::West::LOW:
                                    return 12502;
                                case Properties::West::TALL:
                                    return 12503;
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
                                    return 12504;
                                case Properties::West::LOW:
                                    return 12505;
                                case Properties::West::TALL:
                                    return 12506;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12507;
                                case Properties::West::LOW:
                                    return 12508;
                                case Properties::West::TALL:
                                    return 12509;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12510;
                                case Properties::West::LOW:
                                    return 12511;
                                case Properties::West::TALL:
                                    return 12512;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12513;
                                case Properties::West::LOW:
                                    return 12514;
                                case Properties::West::TALL:
                                    return 12515;
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
                                    return 12516;
                                case Properties::West::LOW:
                                    return 12517;
                                case Properties::West::TALL:
                                    return 12518;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12519;
                                case Properties::West::LOW:
                                    return 12520;
                                case Properties::West::TALL:
                                    return 12521;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12522;
                                case Properties::West::LOW:
                                    return 12523;
                                case Properties::West::TALL:
                                    return 12524;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12525;
                                case Properties::West::LOW:
                                    return 12526;
                                case Properties::West::TALL:
                                    return 12527;
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
                                    return 12528;
                                case Properties::West::LOW:
                                    return 12529;
                                case Properties::West::TALL:
                                    return 12530;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12531;
                                case Properties::West::LOW:
                                    return 12532;
                                case Properties::West::TALL:
                                    return 12533;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12534;
                                case Properties::West::LOW:
                                    return 12535;
                                case Properties::West::TALL:
                                    return 12536;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12537;
                                case Properties::West::LOW:
                                    return 12538;
                                case Properties::West::TALL:
                                    return 12539;
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
                                    return 12540;
                                case Properties::West::LOW:
                                    return 12541;
                                case Properties::West::TALL:
                                    return 12542;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12543;
                                case Properties::West::LOW:
                                    return 12544;
                                case Properties::West::TALL:
                                    return 12545;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12546;
                                case Properties::West::LOW:
                                    return 12547;
                                case Properties::West::TALL:
                                    return 12548;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12549;
                                case Properties::West::LOW:
                                    return 12550;
                                case Properties::West::TALL:
                                    return 12551;
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
                                    return 12552;
                                case Properties::West::LOW:
                                    return 12553;
                                case Properties::West::TALL:
                                    return 12554;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12555;
                                case Properties::West::LOW:
                                    return 12556;
                                case Properties::West::TALL:
                                    return 12557;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12558;
                                case Properties::West::LOW:
                                    return 12559;
                                case Properties::West::TALL:
                                    return 12560;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12561;
                                case Properties::West::LOW:
                                    return 12562;
                                case Properties::West::TALL:
                                    return 12563;
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
                                    return 12564;
                                case Properties::West::LOW:
                                    return 12565;
                                case Properties::West::TALL:
                                    return 12566;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12567;
                                case Properties::West::LOW:
                                    return 12568;
                                case Properties::West::TALL:
                                    return 12569;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12570;
                                case Properties::West::LOW:
                                    return 12571;
                                case Properties::West::TALL:
                                    return 12572;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12573;
                                case Properties::West::LOW:
                                    return 12574;
                                case Properties::West::TALL:
                                    return 12575;
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
                                    return 12576;
                                case Properties::West::LOW:
                                    return 12577;
                                case Properties::West::TALL:
                                    return 12578;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12579;
                                case Properties::West::LOW:
                                    return 12580;
                                case Properties::West::TALL:
                                    return 12581;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12582;
                                case Properties::West::LOW:
                                    return 12583;
                                case Properties::West::TALL:
                                    return 12584;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12585;
                                case Properties::West::LOW:
                                    return 12586;
                                case Properties::West::TALL:
                                    return 12587;
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
                                    return 12588;
                                case Properties::West::LOW:
                                    return 12589;
                                case Properties::West::TALL:
                                    return 12590;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12591;
                                case Properties::West::LOW:
                                    return 12592;
                                case Properties::West::TALL:
                                    return 12593;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12594;
                                case Properties::West::LOW:
                                    return 12595;
                                case Properties::West::TALL:
                                    return 12596;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12597;
                                case Properties::West::LOW:
                                    return 12598;
                                case Properties::West::TALL:
                                    return 12599;
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
                                    return 12600;
                                case Properties::West::LOW:
                                    return 12601;
                                case Properties::West::TALL:
                                    return 12602;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12603;
                                case Properties::West::LOW:
                                    return 12604;
                                case Properties::West::TALL:
                                    return 12605;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12606;
                                case Properties::West::LOW:
                                    return 12607;
                                case Properties::West::TALL:
                                    return 12608;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12609;
                                case Properties::West::LOW:
                                    return 12610;
                                case Properties::West::TALL:
                                    return 12611;
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
                                    return 12612;
                                case Properties::West::LOW:
                                    return 12613;
                                case Properties::West::TALL:
                                    return 12614;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12615;
                                case Properties::West::LOW:
                                    return 12616;
                                case Properties::West::TALL:
                                    return 12617;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12618;
                                case Properties::West::LOW:
                                    return 12619;
                                case Properties::West::TALL:
                                    return 12620;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12621;
                                case Properties::West::LOW:
                                    return 12622;
                                case Properties::West::TALL:
                                    return 12623;
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
                                    return 12624;
                                case Properties::West::LOW:
                                    return 12625;
                                case Properties::West::TALL:
                                    return 12626;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12627;
                                case Properties::West::LOW:
                                    return 12628;
                                case Properties::West::TALL:
                                    return 12629;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12630;
                                case Properties::West::LOW:
                                    return 12631;
                                case Properties::West::TALL:
                                    return 12632;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12633;
                                case Properties::West::LOW:
                                    return 12634;
                                case Properties::West::TALL:
                                    return 12635;
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
                                    return 12636;
                                case Properties::West::LOW:
                                    return 12637;
                                case Properties::West::TALL:
                                    return 12638;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12639;
                                case Properties::West::LOW:
                                    return 12640;
                                case Properties::West::TALL:
                                    return 12641;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12642;
                                case Properties::West::LOW:
                                    return 12643;
                                case Properties::West::TALL:
                                    return 12644;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12645;
                                case Properties::West::LOW:
                                    return 12646;
                                case Properties::West::TALL:
                                    return 12647;
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
                                    return 12648;
                                case Properties::West::LOW:
                                    return 12649;
                                case Properties::West::TALL:
                                    return 12650;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12651;
                                case Properties::West::LOW:
                                    return 12652;
                                case Properties::West::TALL:
                                    return 12653;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12654;
                                case Properties::West::LOW:
                                    return 12655;
                                case Properties::West::TALL:
                                    return 12656;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12657;
                                case Properties::West::LOW:
                                    return 12658;
                                case Properties::West::TALL:
                                    return 12659;
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
                                    return 12660;
                                case Properties::West::LOW:
                                    return 12661;
                                case Properties::West::TALL:
                                    return 12662;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12663;
                                case Properties::West::LOW:
                                    return 12664;
                                case Properties::West::TALL:
                                    return 12665;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12666;
                                case Properties::West::LOW:
                                    return 12667;
                                case Properties::West::TALL:
                                    return 12668;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12669;
                                case Properties::West::LOW:
                                    return 12670;
                                case Properties::West::TALL:
                                    return 12671;
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
                                    return 12672;
                                case Properties::West::LOW:
                                    return 12673;
                                case Properties::West::TALL:
                                    return 12674;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12675;
                                case Properties::West::LOW:
                                    return 12676;
                                case Properties::West::TALL:
                                    return 12677;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12678;
                                case Properties::West::LOW:
                                    return 12679;
                                case Properties::West::TALL:
                                    return 12680;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12681;
                                case Properties::West::LOW:
                                    return 12682;
                                case Properties::West::TALL:
                                    return 12683;
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
                                    return 12684;
                                case Properties::West::LOW:
                                    return 12685;
                                case Properties::West::TALL:
                                    return 12686;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12687;
                                case Properties::West::LOW:
                                    return 12688;
                                case Properties::West::TALL:
                                    return 12689;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12690;
                                case Properties::West::LOW:
                                    return 12691;
                                case Properties::West::TALL:
                                    return 12692;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12693;
                                case Properties::West::LOW:
                                    return 12694;
                                case Properties::West::TALL:
                                    return 12695;
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
                                    return 12696;
                                case Properties::West::LOW:
                                    return 12697;
                                case Properties::West::TALL:
                                    return 12698;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12699;
                                case Properties::West::LOW:
                                    return 12700;
                                case Properties::West::TALL:
                                    return 12701;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12702;
                                case Properties::West::LOW:
                                    return 12703;
                                case Properties::West::TALL:
                                    return 12704;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12705;
                                case Properties::West::LOW:
                                    return 12706;
                                case Properties::West::TALL:
                                    return 12707;
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
                                    return 12708;
                                case Properties::West::LOW:
                                    return 12709;
                                case Properties::West::TALL:
                                    return 12710;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12711;
                                case Properties::West::LOW:
                                    return 12712;
                                case Properties::West::TALL:
                                    return 12713;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12714;
                                case Properties::West::LOW:
                                    return 12715;
                                case Properties::West::TALL:
                                    return 12716;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12717;
                                case Properties::West::LOW:
                                    return 12718;
                                case Properties::West::TALL:
                                    return 12719;
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
