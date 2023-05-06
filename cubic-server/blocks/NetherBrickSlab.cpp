#include "NetherBrickSlab.hpp"
namespace Blocks {
namespace NetherBrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10793;
        case Properties::Waterlogged::FALSE:
            return 10794;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10795;
        case Properties::Waterlogged::FALSE:
            return 10796;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10797;
        case Properties::Waterlogged::FALSE:
            return 10798;
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
