#include "StrippedAcaciaLog.hpp"
namespace Blocks {
    namespace StrippedAcaciaLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 157;
            case Properties::Axis::Y:
                return 158;
            case Properties::Axis::Z:
                return 159;
            default:
                return 0;
            }
            return 0;
        }
    }

}
