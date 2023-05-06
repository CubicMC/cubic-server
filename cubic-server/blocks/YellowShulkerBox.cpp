#include "YellowShulkerBox.hpp"
namespace Blocks {
    namespace YellowShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 11967;
            case Properties::Facing::EAST:
                return 11968;
            case Properties::Facing::SOUTH:
                return 11969;
            case Properties::Facing::WEST:
                return 11970;
            case Properties::Facing::UP:
                return 11971;
            case Properties::Facing::DOWN:
                return 11972;
            default:
                return 0;
            }
            return 0;
        }
    }

}
