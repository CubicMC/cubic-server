#include "BambooBlock.hpp"
namespace Blocks {
    namespace BambooBlock {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 145;
            case Properties::Axis::Y:
                return 146;
            case Properties::Axis::Z:
                return 147;
            }
            return 0;
        }
    }

}
