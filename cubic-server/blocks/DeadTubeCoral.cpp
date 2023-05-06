#include "DeadTubeCoral.hpp"
namespace Blocks {
namespace DeadTubeCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12185;
    case Properties::Waterlogged::FALSE:
        return 12186;
    default:
        return 0;
    }
    return 0;
}
}

}
