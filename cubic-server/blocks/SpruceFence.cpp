#include "SpruceFence.hpp"
namespace Blocks {
namespace SpruceFence {
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
                        return 11051;
                    case Properties::West::FALSE:
                        return 11052;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11053;
                    case Properties::West::FALSE:
                        return 11054;
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
                        return 11055;
                    case Properties::West::FALSE:
                        return 11056;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11057;
                    case Properties::West::FALSE:
                        return 11058;
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
                        return 11059;
                    case Properties::West::FALSE:
                        return 11060;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11061;
                    case Properties::West::FALSE:
                        return 11062;
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
                        return 11063;
                    case Properties::West::FALSE:
                        return 11064;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11065;
                    case Properties::West::FALSE:
                        return 11066;
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
                        return 11067;
                    case Properties::West::FALSE:
                        return 11068;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11069;
                    case Properties::West::FALSE:
                        return 11070;
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
                        return 11071;
                    case Properties::West::FALSE:
                        return 11072;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11073;
                    case Properties::West::FALSE:
                        return 11074;
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
                        return 11075;
                    case Properties::West::FALSE:
                        return 11076;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11077;
                    case Properties::West::FALSE:
                        return 11078;
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
                        return 11079;
                    case Properties::West::FALSE:
                        return 11080;
                    default:
                        return 0;
                    }
                case Properties::Waterlogged::FALSE:
                    switch (west) {
                    case Properties::West::TRUE:
                        return 11081;
                    case Properties::West::FALSE:
                        return 11082;
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
