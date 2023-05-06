#include "CrimsonStem.hpp"
namespace Blocks {
    namespace CrimsonStem {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 17968;
            case Properties::Axis::Y:
                return 17969;
            case Properties::Axis::Z:
                return 17970;
            default:
                return 0;
            }
            return 0;
        }
    }

}
