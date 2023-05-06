#include "PinkCandleCake.hpp"
namespace Blocks {
    namespace PinkCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20383;
            case Properties::Lit::FALSE:
                return 20384;
            default:
                return 0;
            }
            return 0;
        }
    }

}
