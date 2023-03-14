#include "SculkVein.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SculkVein {
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
            switch (down) {
            case Properties::Down::TRUE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20554;
                                    case Properties::West::FALSE:
                                        return 20555;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20556;
                                    case Properties::West::FALSE:
                                        return 20557;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20558;
                                    case Properties::West::FALSE:
                                        return 20559;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20560;
                                    case Properties::West::FALSE:
                                        return 20561;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20562;
                                    case Properties::West::FALSE:
                                        return 20563;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20564;
                                    case Properties::West::FALSE:
                                        return 20565;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20566;
                                    case Properties::West::FALSE:
                                        return 20567;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20568;
                                    case Properties::West::FALSE:
                                        return 20569;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20570;
                                    case Properties::West::FALSE:
                                        return 20571;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20572;
                                    case Properties::West::FALSE:
                                        return 20573;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20574;
                                    case Properties::West::FALSE:
                                        return 20575;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20576;
                                    case Properties::West::FALSE:
                                        return 20577;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20578;
                                    case Properties::West::FALSE:
                                        return 20579;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20580;
                                    case Properties::West::FALSE:
                                        return 20581;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20582;
                                    case Properties::West::FALSE:
                                        return 20583;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20584;
                                    case Properties::West::FALSE:
                                        return 20585;
                                    }
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
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20586;
                                    case Properties::West::FALSE:
                                        return 20587;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20588;
                                    case Properties::West::FALSE:
                                        return 20589;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20590;
                                    case Properties::West::FALSE:
                                        return 20591;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20592;
                                    case Properties::West::FALSE:
                                        return 20593;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20594;
                                    case Properties::West::FALSE:
                                        return 20595;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20596;
                                    case Properties::West::FALSE:
                                        return 20597;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20598;
                                    case Properties::West::FALSE:
                                        return 20599;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20600;
                                    case Properties::West::FALSE:
                                        return 20601;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20602;
                                    case Properties::West::FALSE:
                                        return 20603;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20604;
                                    case Properties::West::FALSE:
                                        return 20605;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20606;
                                    case Properties::West::FALSE:
                                        return 20607;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20608;
                                    case Properties::West::FALSE:
                                        return 20609;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20610;
                                    case Properties::West::FALSE:
                                        return 20611;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20612;
                                    case Properties::West::FALSE:
                                        return 20613;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20614;
                                    case Properties::West::FALSE:
                                        return 20615;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20616;
                                    case Properties::West::FALSE:
                                        return 20617;
                                    }
                                }
                            }
                        }
                    }
                }
            case Properties::Down::FALSE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20618;
                                    case Properties::West::FALSE:
                                        return 20619;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20620;
                                    case Properties::West::FALSE:
                                        return 20621;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20622;
                                    case Properties::West::FALSE:
                                        return 20623;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20624;
                                    case Properties::West::FALSE:
                                        return 20625;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20626;
                                    case Properties::West::FALSE:
                                        return 20627;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20628;
                                    case Properties::West::FALSE:
                                        return 20629;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20630;
                                    case Properties::West::FALSE:
                                        return 20631;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20632;
                                    case Properties::West::FALSE:
                                        return 20633;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20634;
                                    case Properties::West::FALSE:
                                        return 20635;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20636;
                                    case Properties::West::FALSE:
                                        return 20637;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20638;
                                    case Properties::West::FALSE:
                                        return 20639;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20640;
                                    case Properties::West::FALSE:
                                        return 20641;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20642;
                                    case Properties::West::FALSE:
                                        return 20643;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20644;
                                    case Properties::West::FALSE:
                                        return 20645;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20646;
                                    case Properties::West::FALSE:
                                        return 20647;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20648;
                                    case Properties::West::FALSE:
                                        return 20649;
                                    }
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
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20650;
                                    case Properties::West::FALSE:
                                        return 20651;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20652;
                                    case Properties::West::FALSE:
                                        return 20653;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20654;
                                    case Properties::West::FALSE:
                                        return 20655;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20656;
                                    case Properties::West::FALSE:
                                        return 20657;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20658;
                                    case Properties::West::FALSE:
                                        return 20659;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20660;
                                    case Properties::West::FALSE:
                                        return 20661;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20662;
                                    case Properties::West::FALSE:
                                        return 20663;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20664;
                                    case Properties::West::FALSE:
                                        return 20665;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20666;
                                    case Properties::West::FALSE:
                                        return 20667;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20668;
                                    case Properties::West::FALSE:
                                        return 20669;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20670;
                                    case Properties::West::FALSE:
                                        return 20671;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20672;
                                    case Properties::West::FALSE:
                                        return 20673;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20674;
                                    case Properties::West::FALSE:
                                        return 20675;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20676;
                                    case Properties::West::FALSE:
                                        return 20677;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20678;
                                    case Properties::West::FALSE:
                                        return 20679;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 20680;
                                    case Properties::West::FALSE:
                                        return 20681;
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
