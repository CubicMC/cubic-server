#include "FireCoralWallFan.hpp"
namespace Blocks {
namespace FireCoralWallFan {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12289;
        case Properties::Waterlogged::FALSE:
            return 12290;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12291;
        case Properties::Waterlogged::FALSE:
            return 12292;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12293;
        case Properties::Waterlogged::FALSE:
            return 12294;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 12295;
        case Properties::Waterlogged::FALSE:
            return 12296;
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
