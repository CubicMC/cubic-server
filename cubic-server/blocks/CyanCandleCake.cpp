#include "CyanCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CyanCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20389;
            case Properties::Lit::FALSE:
                return 20390;
            }
            return 0;
        }
    }

}
