#include "LightBlueShulkerBox.hpp"
namespace Blocks {
    namespace LightBlueShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 11961;
            case Properties::Facing::EAST:
                return 11962;
            case Properties::Facing::SOUTH:
                return 11963;
            case Properties::Facing::WEST:
                return 11964;
            case Properties::Facing::UP:
                return 11965;
            case Properties::Facing::DOWN:
                return 11966;
            default:
                return 0;
            }
            return 0;
        }
    }

}
