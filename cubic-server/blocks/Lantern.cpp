#include "Lantern.hpp"
namespace Blocks {
namespace Lantern {
BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged) {
    switch (hanging) {
    case Properties::Hanging::TRUE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 17875;
        case Properties::Waterlogged::FALSE:
            return 17876;
        default:
            return 0;
        }
    case Properties::Hanging::FALSE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 17877;
        case Properties::Waterlogged::FALSE:
            return 17878;
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
