#include "TallSeagrass.hpp"
namespace Blocks {
namespace TallSeagrass {
BlockId toProtocol(Properties::Half half)
{
    switch (half) {
    case Properties::Half::UPPER:
        return 1958;
    case Properties::Half::LOWER:
        return 1959;
    default:
        return 0;
    }
    return 0;
}
}

}
