#include "OakPressurePlate.hpp"
namespace Blocks {
    namespace OakPressurePlate {
        BlockId toProtocol(Properties::Powered powered) {
            switch (powered) {
            case Properties::Powered::TRUE:
                return 5552;
            case Properties::Powered::FALSE:
                return 5553;
            }
            return 0;
        }
    }

}
