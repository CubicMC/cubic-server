#include "PinkWallBanner.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PinkWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10562;
            case Properties::Facing::SOUTH:
                return 10563;
            case Properties::Facing::WEST:
                return 10564;
            case Properties::Facing::EAST:
                return 10565;
            }
            return 0;
        }
    }

}
