#include "DarkOakPressurePlate.hpp"
namespace Blocks {
namespace DarkOakPressurePlate {
BlockId toProtocol(Properties::Powered powered) {
    switch (powered) {
    case Properties::Powered::TRUE:
        return 5562;
    case Properties::Powered::FALSE:
        return 5563;
    default:
        return 0;
    }
    return 0;
}
}

}
