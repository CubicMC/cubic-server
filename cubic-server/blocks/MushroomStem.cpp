#include "MushroomStem.hpp"
namespace Blocks {
namespace MushroomStem {
BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
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
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6448;
                        case Properties::West::FALSE:
                            return 6449;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6450;
                        case Properties::West::FALSE:
                            return 6451;
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
                            return 6452;
                        case Properties::West::FALSE:
                            return 6453;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6454;
                        case Properties::West::FALSE:
                            return 6455;
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
                            return 6456;
                        case Properties::West::FALSE:
                            return 6457;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6458;
                        case Properties::West::FALSE:
                            return 6459;
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
                            return 6460;
                        case Properties::West::FALSE:
                            return 6461;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6462;
                        case Properties::West::FALSE:
                            return 6463;
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
                            return 6464;
                        case Properties::West::FALSE:
                            return 6465;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6466;
                        case Properties::West::FALSE:
                            return 6467;
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
                            return 6468;
                        case Properties::West::FALSE:
                            return 6469;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6470;
                        case Properties::West::FALSE:
                            return 6471;
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
                            return 6472;
                        case Properties::West::FALSE:
                            return 6473;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6474;
                        case Properties::West::FALSE:
                            return 6475;
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
                            return 6476;
                        case Properties::West::FALSE:
                            return 6477;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6478;
                        case Properties::West::FALSE:
                            return 6479;
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
    case Properties::Down::FALSE:
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
                            return 6480;
                        case Properties::West::FALSE:
                            return 6481;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6482;
                        case Properties::West::FALSE:
                            return 6483;
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
                            return 6484;
                        case Properties::West::FALSE:
                            return 6485;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6486;
                        case Properties::West::FALSE:
                            return 6487;
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
                            return 6488;
                        case Properties::West::FALSE:
                            return 6489;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6490;
                        case Properties::West::FALSE:
                            return 6491;
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
                            return 6492;
                        case Properties::West::FALSE:
                            return 6493;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6494;
                        case Properties::West::FALSE:
                            return 6495;
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
                            return 6496;
                        case Properties::West::FALSE:
                            return 6497;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6498;
                        case Properties::West::FALSE:
                            return 6499;
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
                            return 6500;
                        case Properties::West::FALSE:
                            return 6501;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6502;
                        case Properties::West::FALSE:
                            return 6503;
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
                            return 6504;
                        case Properties::West::FALSE:
                            return 6505;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6506;
                        case Properties::West::FALSE:
                            return 6507;
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
                            return 6508;
                        case Properties::West::FALSE:
                            return 6509;
                        default:
                            return 0;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6510;
                        case Properties::West::FALSE:
                            return 6511;
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
