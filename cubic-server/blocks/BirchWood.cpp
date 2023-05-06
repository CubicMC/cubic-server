#include "BirchWood.hpp"
namespace Blocks {
    namespace BirchWood {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 178;
            case Properties::Axis::Y:
                return 179;
            case Properties::Axis::Z:
                return 180;
            default:
                return 0;
            }
            return 0;
        }
    }

}
