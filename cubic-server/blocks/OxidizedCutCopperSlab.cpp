#include "OxidizedCutCopperSlab.hpp"
namespace Blocks {
namespace OxidizedCutCopperSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21022;
        case Properties::Waterlogged::FALSE:
            return 21023;
        default:
            return 0;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21024;
        case Properties::Waterlogged::FALSE:
            return 21025;
        default:
            return 0;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 21026;
        case Properties::Waterlogged::FALSE:
            return 21027;
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
