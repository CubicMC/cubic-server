#include "BrownStainedGlassPane.hpp"
namespace Blocks {
    namespace BrownStainedGlassPane {
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
                                return 9360;
                            case Properties::West::FALSE:
                                return 9361;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9362;
                            case Properties::West::FALSE:
                                return 9363;
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
                                return 9364;
                            case Properties::West::FALSE:
                                return 9365;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9366;
                            case Properties::West::FALSE:
                                return 9367;
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
                                return 9368;
                            case Properties::West::FALSE:
                                return 9369;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9370;
                            case Properties::West::FALSE:
                                return 9371;
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
                                return 9372;
                            case Properties::West::FALSE:
                                return 9373;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9374;
                            case Properties::West::FALSE:
                                return 9375;
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
                                return 9376;
                            case Properties::West::FALSE:
                                return 9377;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9378;
                            case Properties::West::FALSE:
                                return 9379;
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
                                return 9380;
                            case Properties::West::FALSE:
                                return 9381;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9382;
                            case Properties::West::FALSE:
                                return 9383;
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
                                return 9384;
                            case Properties::West::FALSE:
                                return 9385;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9386;
                            case Properties::West::FALSE:
                                return 9387;
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
                                return 9388;
                            case Properties::West::FALSE:
                                return 9389;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9390;
                            case Properties::West::FALSE:
                                return 9391;
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
