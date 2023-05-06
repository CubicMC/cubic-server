#include "MagentaShulkerBox.hpp"
namespace Blocks {
    namespace MagentaShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 11955;
            case Properties::Facing::EAST:
                return 11956;
            case Properties::Facing::SOUTH:
                return 11957;
            case Properties::Facing::WEST:
                return 11958;
            case Properties::Facing::UP:
                return 11959;
            case Properties::Facing::DOWN:
                return 11960;
            default:
                return 0;
            }
            return 0;
        }
    }

}
