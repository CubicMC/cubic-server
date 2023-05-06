#include "RedStainedGlassPane.hpp"
namespace Blocks {
    namespace RedStainedGlassPane {
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
            switch (east) {
            case Properties::East::TRUE:
                switch (north) {
                case Properties::North::TRUE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9424;
                            case Properties::West::FALSE:
                                return 9425;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9426;
                            case Properties::West::FALSE:
                                return 9427;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9428;
                            case Properties::West::FALSE:
                                return 9429;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9430;
                            case Properties::West::FALSE:
                                return 9431;
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
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9432;
                            case Properties::West::FALSE:
                                return 9433;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9434;
                            case Properties::West::FALSE:
                                return 9435;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9436;
                            case Properties::West::FALSE:
                                return 9437;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9438;
                            case Properties::West::FALSE:
                                return 9439;
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
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9440;
                            case Properties::West::FALSE:
                                return 9441;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9442;
                            case Properties::West::FALSE:
                                return 9443;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9444;
                            case Properties::West::FALSE:
                                return 9445;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9446;
                            case Properties::West::FALSE:
                                return 9447;
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
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9448;
                            case Properties::West::FALSE:
                                return 9449;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9450;
                            case Properties::West::FALSE:
                                return 9451;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9452;
                            case Properties::West::FALSE:
                                return 9453;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9454;
                            case Properties::West::FALSE:
                                return 9455;
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
