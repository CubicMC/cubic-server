#include "GrayCandleCake.hpp"
namespace Blocks {
    namespace GrayCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20385;
            case Properties::Lit::FALSE:
                return 20386;
            default:
                return 0;
            }
            return 0;
        }
    }

}
