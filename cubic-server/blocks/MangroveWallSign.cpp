#include "MangroveWallSign.hpp"
namespace Blocks {
    namespace MangroveWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4726;
                case Properties::Waterlogged::FALSE:
                    return 4727;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4728;
                case Properties::Waterlogged::FALSE:
                    return 4729;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4730;
                case Properties::Waterlogged::FALSE:
                    return 4731;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4732;
                case Properties::Waterlogged::FALSE:
                    return 4733;
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
