#include "StrippedCrimsonStem.hpp"
#include <stdexcept>

namespace Blocks {
namespace StrippedCrimsonStem {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 17971;
    case Properties::Axis::Y:
        return 17972;
    case Properties::Axis::Z:
        return 17973;
    }
    return 0;
}
}

}
