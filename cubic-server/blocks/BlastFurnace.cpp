#include "BlastFurnace.hpp"
namespace Blocks {
    namespace BlastFurnace {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 17800;
                case Properties::Lit::FALSE:
                    return 17801;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 17802;
                case Properties::Lit::FALSE:
                    return 17803;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 17804;
                case Properties::Lit::FALSE:
                    return 17805;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    return 17806;
                case Properties::Lit::FALSE:
                    return 17807;
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
