#include "BrainCoral.hpp"
namespace Blocks {
namespace BrainCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged) {
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12197;
    case Properties::Waterlogged::FALSE:
        return 12198;
    default:
        return 0;
    }
    return 0;
}
}

}
