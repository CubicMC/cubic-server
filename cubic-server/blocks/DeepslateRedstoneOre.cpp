#include "DeepslateRedstoneOre.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeepslateRedstoneOre {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 5570;
            case Properties::Lit::FALSE:
                return 5571;
            }
            return 0;
        }
    }

}
