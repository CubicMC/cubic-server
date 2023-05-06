#include "QuartzSlab.hpp"
namespace Blocks {
namespace QuartzSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10799;
        case Properties::Waterlogged::FALSE:
            return 10800;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10801;
        case Properties::Waterlogged::FALSE:
            return 10802;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10803;
        case Properties::Waterlogged::FALSE:
            return 10804;
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
