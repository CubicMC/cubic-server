#include "BrownCandleCake.hpp"
namespace Blocks {
    namespace BrownCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20395;
            case Properties::Lit::FALSE:
                return 20396;
            }
            return 0;
        }
    }

}
