#include "CrimsonPressurePlate.hpp"
namespace Blocks {
    namespace CrimsonPressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18052;
            case Properties::Powered::FALSE:
                return 18053;
            default:
                return 0;
            }
            return 0;
        }
    }

}
