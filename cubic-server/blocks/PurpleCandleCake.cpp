#include "PurpleCandleCake.hpp"
namespace Blocks {
    namespace PurpleCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20391;
            case Properties::Lit::FALSE:
                return 20392;
            }
            return 0;
        }
    }

}
