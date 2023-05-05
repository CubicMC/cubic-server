#include "PurpleShulkerBox.hpp"
namespace Blocks {
    namespace PurpleShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12003;
            case Properties::Facing::EAST:
                return 12004;
            case Properties::Facing::SOUTH:
                return 12005;
            case Properties::Facing::WEST:
                return 12006;
            case Properties::Facing::UP:
                return 12007;
            case Properties::Facing::DOWN:
                return 12008;
            }
            return 0;
        }
    }

}
