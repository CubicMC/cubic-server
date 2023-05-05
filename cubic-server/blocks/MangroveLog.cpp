#include "MangroveLog.hpp"
namespace Blocks {
    namespace MangroveLog {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 137;
            case Properties::Axis::Y:
                return 138;
            case Properties::Axis::Z:
                return 139;
            }
            return 0;
        }
    }

}
