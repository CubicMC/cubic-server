#include "DeadTubeCoralFan.hpp"
namespace Blocks {
namespace DeadTubeCoralFan {
BlockId toProtocol(Properties::Waterlogged waterlogged) {
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12205;
    case Properties::Waterlogged::FALSE:
        return 12206;
    default:
        return 0;
    }
    return 0;
}
}

}
