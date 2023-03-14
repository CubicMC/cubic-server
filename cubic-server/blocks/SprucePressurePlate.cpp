#include "SprucePressurePlate.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SprucePressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 5554;
            case Properties::Powered::FALSE:
                return 5555;
            }
            return 0;
        }
    }

}
