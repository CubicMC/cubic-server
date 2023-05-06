#include "LimeCandleCake.hpp"
namespace Blocks {
    namespace LimeCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20381;
            case Properties::Lit::FALSE:
                return 20382;
            default:
                return 0;
            }
            return 0;
        }
    }

}
