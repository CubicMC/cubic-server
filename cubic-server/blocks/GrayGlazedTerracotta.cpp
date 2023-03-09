#include "GrayGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GrayGlazedTerracotta {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12067;
            case Properties::Facing::SOUTH:
                return 12068;
            case Properties::Facing::WEST:
                return 12069;
            case Properties::Facing::EAST:
                return 12070;
            }
            return 0;
        }
    }

}
