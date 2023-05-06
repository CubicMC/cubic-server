#include "PolishedBlackstonePressurePlate.hpp"
namespace Blocks {
namespace PolishedBlackstonePressurePlate {
BlockId toProtocol(Properties::Powered powered) {
    switch (powered) {
    case Properties::Powered::TRUE:
        return 19744;
    case Properties::Powered::FALSE:
        return 19745;
    default:
        return 0;
    }
    return 0;
}
}

}
