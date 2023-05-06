#include "BubbleCoralFan.hpp"
namespace Blocks {
    namespace BubbleCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12219;
            case Properties::Waterlogged::FALSE:
                return 12220;
            default:
                return 0;
            }
            return 0;
        }
    }

}
