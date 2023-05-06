#include "DeadBubbleCoralFan.hpp"
namespace Blocks {
    namespace DeadBubbleCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12209;
            case Properties::Waterlogged::FALSE:
                return 12210;
            default:
                return 0;
            }
            return 0;
        }
    }

}
