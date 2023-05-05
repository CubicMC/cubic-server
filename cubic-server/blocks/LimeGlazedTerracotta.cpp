#include "LimeGlazedTerracotta.hpp"
namespace Blocks {
    namespace LimeGlazedTerracotta {
        BlockId toProtocol(Properties::Facing facing) {
            switch (facing) {
            case Properties::Facing::NORTH:
                return 12059;
            case Properties::Facing::SOUTH:
                return 12060;
            case Properties::Facing::WEST:
                return 12061;
            case Properties::Facing::EAST:
                return 12062;
            }
            return 0;
        }
    }

}
