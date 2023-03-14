#include "LightGrayGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LightGrayGlazedTerracotta {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12071;
            case Properties::Facing::SOUTH:
                return 12072;
            case Properties::Facing::WEST:
                return 12073;
            case Properties::Facing::EAST:
                return 12074;
            }
            return 0;
        }
    }

}
