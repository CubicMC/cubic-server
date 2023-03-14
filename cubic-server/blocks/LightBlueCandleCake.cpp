#include "LightBlueCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LightBlueCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20377;
            case Properties::Lit::FALSE:
                return 20378;
            }
            return 0;
        }
    }

}
