#include "Mycelium.hpp"
namespace Blocks {
    namespace Mycelium {
        BlockId toProtocol(Properties::Snowy snowy) {
            switch (snowy) {
            case Properties::Snowy::TRUE:
                return 7039;
            case Properties::Snowy::FALSE:
                return 7040;
            default:
                return 0;
            }
            return 0;
        }
    }

}
