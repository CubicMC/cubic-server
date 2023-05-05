#include "SpruceLog.hpp"
namespace Blocks {
    namespace SpruceLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 122;
            case Properties::Axis::Y:
                return 123;
            case Properties::Axis::Z:
                return 124;
            }
            return 0;
        }
    }

}
