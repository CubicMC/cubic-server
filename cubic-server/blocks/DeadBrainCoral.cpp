#include "DeadBrainCoral.hpp"
namespace Blocks {
namespace DeadBrainCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged) {
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12187;
    case Properties::Waterlogged::FALSE:
        return 12188;
    default:
        return 0;
    }
    return 0;
}
}

}
