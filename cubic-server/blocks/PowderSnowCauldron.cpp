#include "PowderSnowCauldron.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PowderSnowCauldron {
        BlockId toProtocol(Properties::Level level) {
            switch (level) {
            case Properties::Level::ONE:
                return 7173;
            case Properties::Level::TWO:
                return 7174;
            case Properties::Level::THREE:
                return 7175;
            }
            return 0;
        }
    }

}
