#include "Vine.hpp"
namespace Blocks {
namespace Vine {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
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
                        return 6607;
                    case Properties::West::FALSE:
                        return 6608;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6609;
                    case Properties::West::FALSE:
                        return 6610;
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
                        return 6611;
                    case Properties::West::FALSE:
                        return 6612;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6613;
                    case Properties::West::FALSE:
                        return 6614;
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
                        return 6615;
                    case Properties::West::FALSE:
                        return 6616;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6617;
                    case Properties::West::FALSE:
                        return 6618;
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
                        return 6619;
                    case Properties::West::FALSE:
                        return 6620;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6621;
                    case Properties::West::FALSE:
                        return 6622;
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
                        return 6623;
                    case Properties::West::FALSE:
                        return 6624;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6625;
                    case Properties::West::FALSE:
                        return 6626;
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
                        return 6627;
                    case Properties::West::FALSE:
                        return 6628;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6629;
                    case Properties::West::FALSE:
                        return 6630;
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
                        return 6631;
                    case Properties::West::FALSE:
                        return 6632;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6633;
                    case Properties::West::FALSE:
                        return 6634;
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
                        return 6635;
                    case Properties::West::FALSE:
                        return 6636;
                    default:
                        return 0;
                    }
                case Properties::Up::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 6637;
                    case Properties::West::FALSE:
                        return 6638;
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
