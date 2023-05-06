#include "Anvil.hpp"
namespace Blocks {
    namespace Anvil {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 8711;
            case Properties::Facing::SOUTH:
                return 8712;
            case Properties::Facing::WEST:
                return 8713;
            case Properties::Facing::EAST:
                return 8714;
            default:
                return 0;
            }
            return 0;
        }
    }

}
