#include "SoulWallTorch.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SoulWallTorch {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 5694;
            case Properties::Facing::SOUTH:
                return 5695;
            case Properties::Facing::WEST:
                return 5696;
            case Properties::Facing::EAST:
                return 5697;
            }
            return 0;
        }
    }

}
