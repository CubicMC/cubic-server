#include "BrownWallBanner.hpp"
namespace Blocks {
    namespace BrownWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10586;
            case Properties::Facing::SOUTH:
                return 10587;
            case Properties::Facing::WEST:
                return 10588;
            case Properties::Facing::EAST:
                return 10589;
            default:
                return 0;
            }
            return 0;
        }
    }

}
