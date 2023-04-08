#include "AcaciaLog.hpp"
#include <stdexcept>

namespace Blocks {
namespace AcaciaLog {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 131;
    case Properties::Axis::Y:
        return 132;
    case Properties::Axis::Z:
        return 133;
    }
    return 0;
}
}

}
