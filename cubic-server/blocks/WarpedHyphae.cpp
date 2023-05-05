#include "WarpedHyphae.hpp"
namespace Blocks {
    namespace WarpedHyphae {
        BlockId toProtocol(Properties::Axis axis) {
            switch (axis) {
            case Properties::Axis::X:
                return 17957;
            case Properties::Axis::Y:
                return 17958;
            case Properties::Axis::Z:
                return 17959;
            }
            return 0;
        }
    }

}
