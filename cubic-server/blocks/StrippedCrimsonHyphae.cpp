#include "StrippedCrimsonHyphae.hpp"
#include <stdexcept>

namespace Blocks {
namespace StrippedCrimsonHyphae {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 17977;
    case Properties::Axis::Y:
        return 17978;
    case Properties::Axis::Z:
        return 17979;
    }
    return 0;
}
}

}
