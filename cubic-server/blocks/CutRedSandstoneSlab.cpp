#include "CutRedSandstoneSlab.hpp"
namespace Blocks {
    namespace CutRedSandstoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10811;
                case Properties::Waterlogged::FALSE:
                    return 10812;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10813;
                case Properties::Waterlogged::FALSE:
                    return 10814;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10815;
                case Properties::Waterlogged::FALSE:
                    return 10816;
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
