#include "EndRod.hpp"
namespace Blocks {
    namespace EndRod {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 11723;
            case Properties::Facing::EAST:
                return 11724;
            case Properties::Facing::SOUTH:
                return 11725;
            case Properties::Facing::WEST:
                return 11726;
            case Properties::Facing::UP:
                return 11727;
            case Properties::Facing::DOWN:
                return 11728;
            default:
                return 0;
            }
            return 0;
        }
    }

}
