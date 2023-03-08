#include "DeadFireCoralFan.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeadFireCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12211;
            case Properties::Waterlogged::FALSE:
                return 12212;
            }
            return 0;
        }
    }

}
