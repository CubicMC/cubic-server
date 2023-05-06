#include "OrangeStainedGlassPane.hpp"
namespace Blocks {
    namespace OrangeStainedGlassPane {
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
                                return 9008;
                            case Properties::West::FALSE:
                                return 9009;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9010;
                            case Properties::West::FALSE:
                                return 9011;
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
                                return 9012;
                            case Properties::West::FALSE:
                                return 9013;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9014;
                            case Properties::West::FALSE:
                                return 9015;
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
                                return 9016;
                            case Properties::West::FALSE:
                                return 9017;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9018;
                            case Properties::West::FALSE:
                                return 9019;
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
                                return 9020;
                            case Properties::West::FALSE:
                                return 9021;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9022;
                            case Properties::West::FALSE:
                                return 9023;
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
                                return 9024;
                            case Properties::West::FALSE:
                                return 9025;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9026;
                            case Properties::West::FALSE:
                                return 9027;
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
                                return 9028;
                            case Properties::West::FALSE:
                                return 9029;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9030;
                            case Properties::West::FALSE:
                                return 9031;
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
                                return 9032;
                            case Properties::West::FALSE:
                                return 9033;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9034;
                            case Properties::West::FALSE:
                                return 9035;
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
                                return 9036;
                            case Properties::West::FALSE:
                                return 9037;
                            default:
                                return 0;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9038;
                            case Properties::West::FALSE:
                                return 9039;
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
