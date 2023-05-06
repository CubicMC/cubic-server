#include "CaveVinesPlant.hpp"
namespace Blocks {
namespace CaveVinesPlant {
BlockId toProtocol(Properties::Berries berries) {
    switch (berries) {
    case Properties::Berries::TRUE:
        return 21495;
    case Properties::Berries::FALSE:
        return 21496;
    default:
        return 0;
    }
    return 0;
}
}

}
