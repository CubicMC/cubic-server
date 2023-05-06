#include "Stonecutter.hpp"
namespace Blocks {
    namespace Stonecutter {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 17839;
            case Properties::Facing::SOUTH:
                return 17840;
            case Properties::Facing::WEST:
                return 17841;
            case Properties::Facing::EAST:
                return 17842;
            default:
                return 0;
            }
            return 0;
        }
    }

}
