#include "BrownShulkerBox.hpp"
namespace Blocks {
    namespace BrownShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12015;
            case Properties::Facing::EAST:
                return 12016;
            case Properties::Facing::SOUTH:
                return 12017;
            case Properties::Facing::WEST:
                return 12018;
            case Properties::Facing::UP:
                return 12019;
            case Properties::Facing::DOWN:
                return 12020;
            default:
                return 0;
            }
            return 0;
        }
    }

}
