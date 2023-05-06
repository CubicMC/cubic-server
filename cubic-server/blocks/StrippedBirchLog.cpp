#include "StrippedBirchLog.hpp"
namespace Blocks {
    namespace StrippedBirchLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 151;
            case Properties::Axis::Y:
                return 152;
            case Properties::Axis::Z:
                return 153;
            default:
                return 0;
            }
            return 0;
        }
    }

}
