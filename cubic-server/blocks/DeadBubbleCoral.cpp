#include "DeadBubbleCoral.hpp"
namespace Blocks {
    namespace DeadBubbleCoral {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12189;
            case Properties::Waterlogged::FALSE:
                return 12190;
            }
            return 0;
        }
    }

}
