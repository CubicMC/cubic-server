#include "BlueCandleCake.hpp"
namespace Blocks {
    namespace BlueCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20393;
            case Properties::Lit::FALSE:
                return 20394;
            }
            return 0;
        }
    }

}
