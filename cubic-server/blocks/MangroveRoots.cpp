#include "MangroveRoots.hpp"
#include <stdexcept>

namespace Blocks {
namespace MangroveRoots {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 140;
    case Properties::Waterlogged::FALSE:
        return 141;
    }
    return 0;
}
}

}
