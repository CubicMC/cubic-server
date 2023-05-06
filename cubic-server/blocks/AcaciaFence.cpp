#include "AcaciaFence.hpp"
namespace Blocks {
    namespace AcaciaFence {
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
                                return 11147;
                            case Properties::West::FALSE:
                                return 11148;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11149;
                            case Properties::West::FALSE:
                                return 11150;
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
                                return 11151;
                            case Properties::West::FALSE:
                                return 11152;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11153;
                            case Properties::West::FALSE:
                                return 11154;
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
                                return 11155;
                            case Properties::West::FALSE:
                                return 11156;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11157;
                            case Properties::West::FALSE:
                                return 11158;
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
                                return 11159;
                            case Properties::West::FALSE:
                                return 11160;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11161;
                            case Properties::West::FALSE:
                                return 11162;
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
                                return 11163;
                            case Properties::West::FALSE:
                                return 11164;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11165;
                            case Properties::West::FALSE:
                                return 11166;
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
                                return 11167;
                            case Properties::West::FALSE:
                                return 11168;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11169;
                            case Properties::West::FALSE:
                                return 11170;
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
                                return 11171;
                            case Properties::West::FALSE:
                                return 11172;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11173;
                            case Properties::West::FALSE:
                                return 11174;
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
                                return 11175;
                            case Properties::West::FALSE:
                                return 11176;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 11177;
                            case Properties::West::FALSE:
                                return 11178;
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
