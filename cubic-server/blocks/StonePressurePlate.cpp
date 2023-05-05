#include "StonePressurePlate.hpp"
namespace Blocks {
    namespace StonePressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 5486;
            case Properties::Powered::FALSE:
                return 5487;
            }
            return 0;
        }
    }

}
