#include "LightGrayCandleCake.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LightGrayCandleCake {
        BlockId toProtocol(Properties::Lit lit) {
            switch (lit) {
            case Properties::Lit::TRUE:
                return 20387;
            case Properties::Lit::FALSE:
                return 20388;
            }
            return 0;
        }
    }

}
