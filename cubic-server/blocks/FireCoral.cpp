#include "FireCoral.hpp"
#include <stdexcept>

namespace Blocks {
namespace FireCoral {
BlockId toProtocol(Properties::Waterlogged waterlogged)
{
    switch (waterlogged) {
    case Properties::Waterlogged::TRUE:
        return 12201;
    case Properties::Waterlogged::FALSE:
        return 12202;
    }
    return 0;
}
}

}
