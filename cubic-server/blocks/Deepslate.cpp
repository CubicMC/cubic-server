#include "Deepslate.hpp"
#include <stdexcept>

namespace Blocks {
namespace Deepslate {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 21562;
    case Properties::Axis::Y:
        return 21563;
    case Properties::Axis::Z:
        return 21564;
    }
    return 0;
}
}

}
