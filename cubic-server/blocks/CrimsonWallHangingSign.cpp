#include "CrimsonWallHangingSign.hpp"
namespace Blocks {
    namespace CrimsonWallHangingSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5438;
                case Properties::Waterlogged::FALSE:
                    return 5439;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5440;
                case Properties::Waterlogged::FALSE:
                    return 5441;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5442;
                case Properties::Waterlogged::FALSE:
                    return 5443;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5444;
                case Properties::Waterlogged::FALSE:
                    return 5445;
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
