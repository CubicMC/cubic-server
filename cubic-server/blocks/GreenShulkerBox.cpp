#include "GreenShulkerBox.hpp"
namespace Blocks {
    namespace GreenShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12021;
            case Properties::Facing::EAST:
                return 12022;
            case Properties::Facing::SOUTH:
                return 12023;
            case Properties::Facing::WEST:
                return 12024;
            case Properties::Facing::UP:
                return 12025;
            case Properties::Facing::DOWN:
                return 12026;
            }
            return 0;
        }
    }

}
