#include "OakLog.hpp"
#include <stdexcept>

namespace Blocks {
namespace OakLog {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 119;
    case Properties::Axis::Y:
        return 120;
    case Properties::Axis::Z:
        return 121;
    }
    return 0;
}
}

}
