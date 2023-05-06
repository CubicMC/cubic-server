#include "PearlescentFroglight.hpp"
namespace Blocks {
    namespace PearlescentFroglight {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 23227;
            case Properties::Axis::Y:
                return 23228;
            case Properties::Axis::Z:
                return 23229;
            default:
                return 0;
            }
            return 0;
        }
    }

}
