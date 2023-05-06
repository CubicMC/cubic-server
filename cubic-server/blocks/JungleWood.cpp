#include "JungleWood.hpp"
namespace Blocks {
    namespace JungleWood {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 181;
            case Properties::Axis::Y:
                return 182;
            case Properties::Axis::Z:
                return 183;
            default:
                return 0;
            }
            return 0;
        }
    }

}
