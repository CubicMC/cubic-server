#include "RoseBush.hpp"
namespace Blocks {
namespace RoseBush {
BlockId toProtocol(Properties::Half half)
{
    switch (half) {
    case Properties::Half::UPPER:
        return 10274;
    case Properties::Half::LOWER:
        return 10275;
    default:
        return 0;
    }
    return 0;
}
}

}
