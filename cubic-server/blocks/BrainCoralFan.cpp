#include "BrainCoralFan.hpp"
namespace Blocks {
    namespace BrainCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12217;
            case Properties::Waterlogged::FALSE:
                return 12218;
            default:
                return 0;
            }
            return 0;
        }
    }

}
