#include "WhiteCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WhiteCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20371;
            case Properties::Lit::FALSE:
                return 20372;
            }
            return 0;
        }
    }

}
