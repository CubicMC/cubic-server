#include "BrainCoral.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BrainCoral {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12197;
            case Properties::Waterlogged::FALSE:
                return 12198;
            }
            return 0;
        }
    }

}
