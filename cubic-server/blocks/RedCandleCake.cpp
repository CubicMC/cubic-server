#include "RedCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace RedCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20399;
            case Properties::Lit::FALSE:
                return 20400;
            }
            return 0;
        }
    }

}
