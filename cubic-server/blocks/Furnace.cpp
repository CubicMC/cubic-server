#include "Furnace.hpp"
namespace Blocks {
    namespace Furnace {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 4242;
                case Properties::Lit::FALSE:
                    return 4243;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 4244;
                case Properties::Lit::FALSE:
                    return 4245;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 4246;
                case Properties::Lit::FALSE:
                    return 4247;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 4248;
                case Properties::Lit::FALSE:
                    return 4249;
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
