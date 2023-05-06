#include "WallTorch.hpp"
namespace Blocks {
    namespace WallTorch {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 2304;
            case Properties::Facing::SOUTH:
                return 2305;
            case Properties::Facing::WEST:
                return 2306;
            case Properties::Facing::EAST:
                return 2307;
            default:
                return 0;
            }
            return 0;
        }
    }

}
