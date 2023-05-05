#include "BlueShulkerBox.hpp"
namespace Blocks {
    namespace BlueShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12009;
            case Properties::Facing::EAST:
                return 12010;
            case Properties::Facing::SOUTH:
                return 12011;
            case Properties::Facing::WEST:
                return 12012;
            case Properties::Facing::UP:
                return 12013;
            case Properties::Facing::DOWN:
                return 12014;
            }
            return 0;
        }
    }

}
