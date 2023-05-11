#include "LightGrayStainedGlassPane.hpp"
namespace Blocks {
namespace LightGrayStainedGlassPane {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west)
{
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
                        return 9232;
                    case Properties::West::FALSE:
                        return 9233;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9234;
                    case Properties::West::FALSE:
                        return 9235;
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
                        return 9236;
                    case Properties::West::FALSE:
                        return 9237;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9238;
                    case Properties::West::FALSE:
                        return 9239;
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
                        return 9240;
                    case Properties::West::FALSE:
                        return 9241;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9242;
                    case Properties::West::FALSE:
                        return 9243;
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
                        return 9244;
                    case Properties::West::FALSE:
                        return 9245;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9246;
                    case Properties::West::FALSE:
                        return 9247;
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
                        return 9248;
                    case Properties::West::FALSE:
                        return 9249;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9250;
                    case Properties::West::FALSE:
                        return 9251;
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
                        return 9252;
                    case Properties::West::FALSE:
                        return 9253;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9254;
                    case Properties::West::FALSE:
                        return 9255;
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
                        return 9256;
                    case Properties::West::FALSE:
                        return 9257;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9258;
                    case Properties::West::FALSE:
                        return 9259;
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
                        return 9260;
                    case Properties::West::FALSE:
                        return 9261;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 9262;
                    case Properties::West::FALSE:
                        return 9263;
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
