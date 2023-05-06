#include "BlackCandleCake.hpp"
namespace Blocks {
    namespace BlackCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20401;
            case Properties::Lit::FALSE:
                return 20402;
            default:
                return 0;
            }
            return 0;
        }
    }

}
