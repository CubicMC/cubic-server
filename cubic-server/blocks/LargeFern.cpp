#include "LargeFern.hpp"
namespace Blocks {
namespace LargeFern {
BlockId toProtocol(Properties::Half half)
{
    switch (half) {
    case Properties::Half::UPPER:
        return 10280;
    case Properties::Half::LOWER:
        return 10281;
    default:
        return 0;
    }
    return 0;
}
}

}
