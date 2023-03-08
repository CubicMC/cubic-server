#include "BubbleCoral.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BubbleCoral {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12199;
            case Properties::Waterlogged::FALSE:
                return 12200;
            }
            return 0;
        }
    }

}
