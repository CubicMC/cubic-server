#include "JunglePressurePlate.hpp"
namespace Blocks {
namespace JunglePressurePlate {
BlockId toProtocol(Properties::Powered powered) {
    switch (powered) {
    case Properties::Powered::TRUE:
        return 5558;
    case Properties::Powered::FALSE:
        return 5559;
    default:
        return 0;
    }
    return 0;
}
}

}
