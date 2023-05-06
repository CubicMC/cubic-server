#include "JungleSlab.hpp"
namespace Blocks {
namespace JungleSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10703;
        case Properties::Waterlogged::FALSE:
            return 10704;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10705;
        case Properties::Waterlogged::FALSE:
            return 10706;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10707;
        case Properties::Waterlogged::FALSE:
            return 10708;
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
