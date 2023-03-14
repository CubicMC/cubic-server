#include "Sunflower.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Sunflower {
        BlockId toProtocol(Properties::Half half) {
            switch (half) {
            case Properties::Half::UPPER:
                return 10270;
            case Properties::Half::LOWER:
                return 10271;
            }
            return 0;
        }
    }

}
