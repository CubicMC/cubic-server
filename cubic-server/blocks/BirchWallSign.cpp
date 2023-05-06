#include "BirchWallSign.hpp"
namespace Blocks {
    namespace BirchWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4694;
                case Properties::Waterlogged::FALSE:
                    return 4695;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4696;
                case Properties::Waterlogged::FALSE:
                    return 4697;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4698;
                case Properties::Waterlogged::FALSE:
                    return 4699;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4700;
                case Properties::Waterlogged::FALSE:
                    return 4701;
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
