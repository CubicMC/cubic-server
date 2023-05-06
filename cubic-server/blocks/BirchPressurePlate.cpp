#include "BirchPressurePlate.hpp"
namespace Blocks {
    namespace BirchPressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 5556;
            case Properties::Powered::FALSE:
                return 5557;
            default:
                return 0;
            }
            return 0;
        }
    }

}
