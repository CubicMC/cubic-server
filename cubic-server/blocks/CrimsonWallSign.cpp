#include "CrimsonWallSign.hpp"
namespace Blocks {
    namespace CrimsonWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18712;
                case Properties::Waterlogged::FALSE:
                    return 18713;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18714;
                case Properties::Waterlogged::FALSE:
                    return 18715;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18716;
                case Properties::Waterlogged::FALSE:
                    return 18717;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18718;
                case Properties::Waterlogged::FALSE:
                    return 18719;
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
