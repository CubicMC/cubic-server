#include "BlackShulkerBox.hpp"
namespace Blocks {
    namespace BlackShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12033;
            case Properties::Facing::EAST:
                return 12034;
            case Properties::Facing::SOUTH:
                return 12035;
            case Properties::Facing::WEST:
                return 12036;
            case Properties::Facing::UP:
                return 12037;
            case Properties::Facing::DOWN:
                return 12038;
            }
            return 0;
        }
    }

}
