#include "StrippedMangroveLog.hpp"
#include <stdexcept>

namespace Blocks {
namespace StrippedMangroveLog {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 166;
    case Properties::Axis::Y:
        return 167;
    case Properties::Axis::Z:
        return 168;
    }
    return 0;
}
}

}
