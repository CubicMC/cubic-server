#include "BambooMosaicSlab.hpp"
namespace Blocks {
namespace BambooMosaicSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10733;
        case Properties::Waterlogged::FALSE:
            return 10734;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10735;
        case Properties::Waterlogged::FALSE:
            return 10736;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10737;
        case Properties::Waterlogged::FALSE:
            return 10738;
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
