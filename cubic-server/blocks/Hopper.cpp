#include "Hopper.hpp"
namespace Blocks {
    namespace Hopper {
        BlockId toProtocol(Properties::Enabled enabled, Properties::Facing facing) {
            switch (enabled) {
            case Properties::Enabled::TRUE:
                switch (facing) {
                case Properties::Facing::DOWN:
                    return 8829;
                case Properties::Facing::NORTH:
                    return 8830;
                case Properties::Facing::SOUTH:
                    return 8831;
                case Properties::Facing::WEST:
                    return 8832;
                case Properties::Facing::EAST:
                    return 8833;
                default:
                    return 0;
                }
            case Properties::Enabled::FALSE:
                switch (facing) {
                case Properties::Facing::DOWN:
                    return 8834;
                case Properties::Facing::NORTH:
                    return 8835;
                case Properties::Facing::SOUTH:
                    return 8836;
                case Properties::Facing::WEST:
                    return 8837;
                case Properties::Facing::EAST:
                    return 8838;
                default:
                    return 0;
                }
            default:
                return 0;
            }
            return 0;
        }
    }

}
