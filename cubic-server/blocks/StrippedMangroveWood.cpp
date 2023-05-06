#include "StrippedMangroveWood.hpp"
namespace Blocks {
    namespace StrippedMangroveWood {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 211;
            case Properties::Axis::Y:
                return 212;
            case Properties::Axis::Z:
                return 213;
            default:
                return 0;
            }
            return 0;
        }
    }

}
