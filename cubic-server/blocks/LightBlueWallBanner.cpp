#include "LightBlueWallBanner.hpp"
namespace Blocks {
    namespace LightBlueWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10550;
            case Properties::Facing::SOUTH:
                return 10551;
            case Properties::Facing::WEST:
                return 10552;
            case Properties::Facing::EAST:
                return 10553;
            }
            return 0;
        }
    }

}
