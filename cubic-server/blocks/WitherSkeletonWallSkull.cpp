#include "WitherSkeletonWallSkull.hpp"
namespace Blocks {
    namespace WitherSkeletonWallSkull {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 8607;
            case Properties::Facing::SOUTH:
                return 8608;
            case Properties::Facing::WEST:
                return 8609;
            case Properties::Facing::EAST:
                return 8610;
            }
            return 0;
        }
    }

}
