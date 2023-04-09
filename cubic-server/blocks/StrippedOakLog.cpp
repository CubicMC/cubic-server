#include "StrippedOakLog.hpp"
#include <stdexcept>

namespace Blocks {
namespace StrippedOakLog {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 163;
    case Properties::Axis::Y:
        return 164;
    case Properties::Axis::Z:
        return 165;
    }
    return 0;
}
}

}
