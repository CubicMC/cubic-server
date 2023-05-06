#include "BirchFence.hpp"
namespace Blocks {
namespace BirchFence {
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
                        return 11083;
                    case Properties::West::FALSE:
                        return 11084;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11085;
                    case Properties::West::FALSE:
                        return 11086;
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
                        return 11087;
                    case Properties::West::FALSE:
                        return 11088;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11089;
                    case Properties::West::FALSE:
                        return 11090;
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
                        return 11091;
                    case Properties::West::FALSE:
                        return 11092;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11093;
                    case Properties::West::FALSE:
                        return 11094;
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
                        return 11095;
                    case Properties::West::FALSE:
                        return 11096;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11097;
                    case Properties::West::FALSE:
                        return 11098;
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
                        return 11099;
                    case Properties::West::FALSE:
                        return 11100;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11101;
                    case Properties::West::FALSE:
                        return 11102;
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
                        return 11103;
                    case Properties::West::FALSE:
                        return 11104;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11105;
                    case Properties::West::FALSE:
                        return 11106;
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
                        return 11107;
                    case Properties::West::FALSE:
                        return 11108;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11109;
                    case Properties::West::FALSE:
                        return 11110;
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
                        return 11111;
                    case Properties::West::FALSE:
                        return 11112;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11113;
                    case Properties::West::FALSE:
                        return 11114;
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
