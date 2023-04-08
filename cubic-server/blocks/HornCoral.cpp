#include "HornCoral.hpp"
#include <stdexcept>

namespace Blocks {
namespace HornCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12203;
    case Properties::Waterlogged::FALSE:
        return 12204;
    }
    return 0;
}
}

}
