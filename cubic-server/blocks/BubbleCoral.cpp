#include "BubbleCoral.hpp"
namespace Blocks {
namespace BubbleCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged) {
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12199;
    case Properties::Waterlogged::FALSE:
        return 12200;
    default:
        return 0;
    }
    return 0;
}
}

}
