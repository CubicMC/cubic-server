#include "DeadTubeCoral.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeadTubeCoral {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12185;
            case Properties::Waterlogged::FALSE:
                return 12186;
            }
            return 0;
        }
    }

}
