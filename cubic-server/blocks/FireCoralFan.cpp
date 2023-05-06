#include "FireCoralFan.hpp"
namespace Blocks {
namespace FireCoralFan {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12221;
    case Properties::Waterlogged::FALSE:
        return 12222;
    default:
        return 0;
    }
    return 0;
}
}

}
