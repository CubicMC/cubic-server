#include "WarpedPressurePlate.hpp"
namespace Blocks {
namespace WarpedPressurePlate {
BlockId toProtocol(Properties::Powered powered) {
    switch (powered) {
    case Properties::Powered::TRUE:
        return 18054;
    case Properties::Powered::FALSE:
        return 18055;
    default:
        return 0;
    }
    return 0;
}
}

}
