#include "StrippedBambooBlock.hpp"
#include <stdexcept>

namespace Blocks {
namespace StrippedBambooBlock {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 169;
    case Properties::Axis::Y:
        return 170;
    case Properties::Axis::Z:
        return 171;
    }
    return 0;
}
}

}
