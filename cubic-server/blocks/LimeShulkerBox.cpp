#include "LimeShulkerBox.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LimeShulkerBox {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 11973;
            case Properties::Facing::EAST:
                return 11974;
            case Properties::Facing::SOUTH:
                return 11975;
            case Properties::Facing::WEST:
                return 11976;
            case Properties::Facing::UP:
                return 11977;
            case Properties::Facing::DOWN:
                return 11978;
            }
            return 0;
        }
    }

}
