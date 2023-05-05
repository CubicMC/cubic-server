#include "StrippedJungleLog.hpp"
namespace Blocks {
    namespace StrippedJungleLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 154;
            case Properties::Axis::Y:
                return 155;
            case Properties::Axis::Z:
                return 156;
            }
            return 0;
        }
    }

}
