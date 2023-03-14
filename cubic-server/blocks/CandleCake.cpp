#include "CandleCake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20369;
            case Properties::Lit::FALSE:
                return 20370;
            }
            return 0;
        }
    }

}
