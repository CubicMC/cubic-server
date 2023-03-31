#include "DeadBrainCoral.hpp"
#include <stdexcept>

namespace Blocks {
namespace DeadBrainCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12187;
    case Properties::Waterlogged::FALSE:
        return 12188;
    }
    return 0;
}
}

}
