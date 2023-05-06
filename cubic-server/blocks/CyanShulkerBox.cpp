#include "CyanShulkerBox.hpp"
namespace Blocks {
    namespace CyanShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 11997;
            case Properties::Facing::EAST:
                return 11998;
            case Properties::Facing::SOUTH:
                return 11999;
            case Properties::Facing::WEST:
                return 12000;
            case Properties::Facing::UP:
                return 12001;
            case Properties::Facing::DOWN:
                return 12002;
            default:
                return 0;
            }
            return 0;
        }
    }

}
