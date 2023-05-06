#include "StrippedMangroveLog.hpp"
namespace Blocks {
    namespace StrippedMangroveLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 166;
            case Properties::Axis::Y:
                return 167;
            case Properties::Axis::Z:
                return 168;
            default:
                return 0;
            }
            return 0;
        }
    }

}
