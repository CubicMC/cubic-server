#include "WarpedPressurePlate.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WarpedPressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18054;
            case Properties::Powered::FALSE:
                return 18055;
            }
            return 0;
        }
    }

}
