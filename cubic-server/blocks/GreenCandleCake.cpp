#include "GreenCandleCake.hpp"
namespace Blocks {
    namespace GreenCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20397;
            case Properties::Lit::FALSE:
                return 20398;
            default:
                return 0;
            }
            return 0;
        }
    }

}
