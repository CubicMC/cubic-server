#include "PetrifiedOakSlab.hpp"
namespace Blocks {
namespace PetrifiedOakSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10763;
        case Properties::Waterlogged::FALSE:
            return 10764;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10765;
        case Properties::Waterlogged::FALSE:
            return 10766;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10767;
        case Properties::Waterlogged::FALSE:
            return 10768;
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
