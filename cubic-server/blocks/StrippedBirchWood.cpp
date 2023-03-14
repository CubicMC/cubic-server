#include "StrippedBirchWood.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StrippedBirchWood {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 199;
            case Properties::Axis::Y:
                return 200;
            case Properties::Axis::Z:
                return 201;
            }
            return 0;
        }
    }

}
