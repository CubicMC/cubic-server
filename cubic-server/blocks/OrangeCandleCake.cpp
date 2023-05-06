#include "OrangeCandleCake.hpp"
namespace Blocks {
    namespace OrangeCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20373;
            case Properties::Lit::FALSE:
                return 20374;
            default:
                return 0;
            }
            return 0;
        }
    }

}
