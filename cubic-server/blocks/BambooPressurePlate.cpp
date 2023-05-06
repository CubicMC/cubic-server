#include "BambooPressurePlate.hpp"
namespace Blocks {
    namespace BambooPressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 5566;
            case Properties::Powered::FALSE:
                return 5567;
            default:
                return 0;
            }
            return 0;
        }
    }

}
