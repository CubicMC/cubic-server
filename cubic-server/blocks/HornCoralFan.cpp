#include "HornCoralFan.hpp"
#include <stdexcept>

namespace Blocks {
namespace HornCoralFan {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12223;
    case Properties::Waterlogged::FALSE:
        return 12224;
    }
    return 0;
}
}

}
