#include "PlayerWallHead.hpp"
namespace Blocks {
    namespace PlayerWallHead {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 8647;
            case Properties::Facing::SOUTH:
                return 8648;
            case Properties::Facing::WEST:
                return 8649;
            case Properties::Facing::EAST:
                return 8650;
            }
            return 0;
        }
    }

}
