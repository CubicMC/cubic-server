#include "OrangeGlazedTerracotta.hpp"
namespace Blocks {
    namespace OrangeGlazedTerracotta {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12043;
            case Properties::Facing::SOUTH:
                return 12044;
            case Properties::Facing::WEST:
                return 12045;
            case Properties::Facing::EAST:
                return 12046;
            default:
                return 0;
            }
            return 0;
        }
    }

}
