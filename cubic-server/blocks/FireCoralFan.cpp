#include "FireCoralFan.hpp"
#include <stdexcept>

namespace Blocks {
namespace FireCoralFan {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12221;
    case Properties::Waterlogged::FALSE:
        return 12222;
    }
    return 0;
}
}

}
