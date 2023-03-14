#include "TallGrass.hpp"
#include <stdexcept>

namespace Blocks {
    namespace TallGrass {
        BlockId toProtocol(Properties::Half half) {
            switch (half) {
            case Properties::Half::UPPER:
                return 10278;
            case Properties::Half::LOWER:
                return 10279;
            }
            return 0;
        }
    }

}
