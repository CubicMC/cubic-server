#include "AcaciaWallHangingSign.hpp"
namespace Blocks {
namespace AcaciaWallHangingSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5406;
        case Properties::Waterlogged::FALSE:
            return 5407;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5408;
        case Properties::Waterlogged::FALSE:
            return 5409;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5410;
        case Properties::Waterlogged::FALSE:
            return 5411;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5412;
        case Properties::Waterlogged::FALSE:
            return 5413;
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
