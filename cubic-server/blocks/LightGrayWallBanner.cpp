#include "LightGrayWallBanner.hpp"
namespace Blocks {
    namespace LightGrayWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10570;
            case Properties::Facing::SOUTH:
                return 10571;
            case Properties::Facing::WEST:
                return 10572;
            case Properties::Facing::EAST:
                return 10573;
            default:
                return 0;
            }
            return 0;
        }
    }

}
