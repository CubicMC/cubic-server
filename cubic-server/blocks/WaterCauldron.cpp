#include "WaterCauldron.hpp"
namespace Blocks {
namespace WaterCauldron {
BlockId toProtocol(Properties::Level level)
{
    switch (level) {
    case Properties::Level::ONE:
        return 7169;
    case Properties::Level::TWO:
        return 7170;
    case Properties::Level::THREE:
        return 7171;
    default:
        return 0;
    }
    return 0;
}
}

}
