#include "MagentaWallBanner.hpp"
namespace Blocks {
    namespace MagentaWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10546;
            case Properties::Facing::SOUTH:
                return 10547;
            case Properties::Facing::WEST:
                return 10548;
            case Properties::Facing::EAST:
                return 10549;
            default:
                return 0;
            }
            return 0;
        }
    }

}
