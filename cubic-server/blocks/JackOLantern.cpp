#include "JackOLantern.hpp"
namespace Blocks {
    namespace JackOLantern {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 5705;
            case Properties::Facing::SOUTH:
                return 5706;
            case Properties::Facing::WEST:
                return 5707;
            case Properties::Facing::EAST:
                return 5708;
            default:
                return 0;
            }
            return 0;
        }
    }

}
