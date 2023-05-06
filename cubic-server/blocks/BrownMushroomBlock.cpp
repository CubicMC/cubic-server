#include "BrownMushroomBlock.hpp"
namespace Blocks {
    namespace BrownMushroomBlock {
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
                                    return 6320;
                                case Properties::West::FALSE:
                                    return 6321;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6322;
                                case Properties::West::FALSE:
                                    return 6323;
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
                                    return 6324;
                                case Properties::West::FALSE:
                                    return 6325;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6326;
                                case Properties::West::FALSE:
                                    return 6327;
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
                                    return 6328;
                                case Properties::West::FALSE:
                                    return 6329;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6330;
                                case Properties::West::FALSE:
                                    return 6331;
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
                                    return 6332;
                                case Properties::West::FALSE:
                                    return 6333;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6334;
                                case Properties::West::FALSE:
                                    return 6335;
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
                                    return 6336;
                                case Properties::West::FALSE:
                                    return 6337;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6338;
                                case Properties::West::FALSE:
                                    return 6339;
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
                                    return 6340;
                                case Properties::West::FALSE:
                                    return 6341;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6342;
                                case Properties::West::FALSE:
                                    return 6343;
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
                                    return 6344;
                                case Properties::West::FALSE:
                                    return 6345;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6346;
                                case Properties::West::FALSE:
                                    return 6347;
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
                                    return 6348;
                                case Properties::West::FALSE:
                                    return 6349;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6350;
                                case Properties::West::FALSE:
                                    return 6351;
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
                                    return 6352;
                                case Properties::West::FALSE:
                                    return 6353;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6354;
                                case Properties::West::FALSE:
                                    return 6355;
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
                                    return 6356;
                                case Properties::West::FALSE:
                                    return 6357;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6358;
                                case Properties::West::FALSE:
                                    return 6359;
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
                                    return 6360;
                                case Properties::West::FALSE:
                                    return 6361;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6362;
                                case Properties::West::FALSE:
                                    return 6363;
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
                                    return 6364;
                                case Properties::West::FALSE:
                                    return 6365;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6366;
                                case Properties::West::FALSE:
                                    return 6367;
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
                                    return 6368;
                                case Properties::West::FALSE:
                                    return 6369;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6370;
                                case Properties::West::FALSE:
                                    return 6371;
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
                                    return 6372;
                                case Properties::West::FALSE:
                                    return 6373;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6374;
                                case Properties::West::FALSE:
                                    return 6375;
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
                                    return 6376;
                                case Properties::West::FALSE:
                                    return 6377;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6378;
                                case Properties::West::FALSE:
                                    return 6379;
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
                                    return 6380;
                                case Properties::West::FALSE:
                                    return 6381;
                                default:
                                    return 0;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6382;
                                case Properties::West::FALSE:
                                    return 6383;
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
