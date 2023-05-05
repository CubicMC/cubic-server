#include "AttachedPumpkinStem.hpp"
namespace Blocks {
    namespace AttachedPumpkinStem {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 6583;
            case Properties::Facing::SOUTH:
                return 6584;
            case Properties::Facing::WEST:
                return 6585;
            case Properties::Facing::EAST:
                return 6586;
            }
            return 0;
        }
    }

}
