#include "BubbleColumn.hpp"
namespace Blocks {
    namespace BubbleColumn {
        BlockId toProtocol(Properties::Drag drag) {
            switch (drag) {
            case Properties::Drag::TRUE:
                return 12332;
            case Properties::Drag::FALSE:
                return 12333;
            default:
                return 0;
            }
            return 0;
        }
    }

}
