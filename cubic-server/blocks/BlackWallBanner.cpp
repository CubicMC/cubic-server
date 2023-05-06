#include "BlackWallBanner.hpp"
namespace Blocks {
    namespace BlackWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10598;
            case Properties::Facing::SOUTH:
                return 10599;
            case Properties::Facing::WEST:
                return 10600;
            case Properties::Facing::EAST:
                return 10601;
            default:
                return 0;
            }
            return 0;
        }
    }

}
