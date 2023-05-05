#include "Loom.hpp"
namespace Blocks {
    namespace Loom {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 17776;
            case Properties::Facing::SOUTH:
                return 17777;
            case Properties::Facing::WEST:
                return 17778;
            case Properties::Facing::EAST:
                return 17779;
            }
            return 0;
        }
    }

}
