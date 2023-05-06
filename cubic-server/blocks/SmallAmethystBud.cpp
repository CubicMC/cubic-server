#include "SmallAmethystBud.hpp"
namespace Blocks {
namespace SmallAmethystBud {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20441;
        case Properties::Waterlogged::FALSE:
            return 20442;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20443;
        case Properties::Waterlogged::FALSE:
            return 20444;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20445;
        case Properties::Waterlogged::FALSE:
            return 20446;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20447;
        case Properties::Waterlogged::FALSE:
            return 20448;
        default:
            return 0;
        }
    case Properties::Facing::UP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20449;
        case Properties::Waterlogged::FALSE:
            return 20450;
        default:
            return 0;
        }
    case Properties::Facing::DOWN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20451;
        case Properties::Waterlogged::FALSE:
            return 20452;
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
