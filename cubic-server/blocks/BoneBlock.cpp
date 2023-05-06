#include "BoneBlock.hpp"
namespace Blocks {
    namespace BoneBlock {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 11921;
            case Properties::Axis::Y:
                return 11922;
            case Properties::Axis::Z:
                return 11923;
            default:
                return 0;
            }
            return 0;
        }
    }

}
