#include "DeadFireCoral.hpp"
namespace Blocks {
    namespace DeadFireCoral {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12191;
            case Properties::Waterlogged::FALSE:
                return 12192;
            default:
                return 0;
            }
            return 0;
        }
    }

}
