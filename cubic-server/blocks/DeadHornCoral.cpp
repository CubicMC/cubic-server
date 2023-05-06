#include "DeadHornCoral.hpp"
namespace Blocks {
namespace DeadHornCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged) {
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12193;
    case Properties::Waterlogged::FALSE:
        return 12194;
    default:
        return 0;
    }
    return 0;
}
}

}
