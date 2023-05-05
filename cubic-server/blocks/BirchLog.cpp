#include "BirchLog.hpp"
namespace Blocks {
    namespace BirchLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 125;
            case Properties::Axis::Y:
                return 126;
            case Properties::Axis::Z:
                return 127;
            }
            return 0;
        }
    }

}
