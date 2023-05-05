#include "CrimsonHyphae.hpp"
namespace Blocks {
    namespace CrimsonHyphae {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 17974;
            case Properties::Axis::Y:
                return 17975;
            case Properties::Axis::Z:
                return 17976;
            }
            return 0;
        }
    }

}
