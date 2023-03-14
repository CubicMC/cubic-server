#include "BrownGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BrownGlazedTerracotta {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12087;
            case Properties::Facing::SOUTH:
                return 12088;
            case Properties::Facing::WEST:
                return 12089;
            case Properties::Facing::EAST:
                return 12090;
            }
            return 0;
        }
    }

}
