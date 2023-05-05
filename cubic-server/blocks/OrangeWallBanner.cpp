#include "OrangeWallBanner.hpp"
namespace Blocks {
    namespace OrangeWallBanner {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 10542;
            case Properties::Facing::SOUTH:
                return 10543;
            case Properties::Facing::WEST:
                return 10544;
            case Properties::Facing::EAST:
                return 10545;
            }
            return 0;
        }
    }

}
