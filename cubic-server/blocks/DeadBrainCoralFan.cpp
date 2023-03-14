#include "DeadBrainCoralFan.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeadBrainCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12207;
            case Properties::Waterlogged::FALSE:
                return 12208;
            }
            return 0;
        }
    }

}
