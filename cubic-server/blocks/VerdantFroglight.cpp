#include "VerdantFroglight.hpp"
#include <stdexcept>

namespace Blocks {
namespace VerdantFroglight {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 23224;
    case Properties::Axis::Y:
        return 23225;
    case Properties::Axis::Z:
        return 23226;
    }
    return 0;
}
}

}
