#include "RedSandstoneSlab.hpp"
namespace Blocks {
    namespace RedSandstoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10805;
                case Properties::Waterlogged::FALSE:
                    return 10806;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10807;
                case Properties::Waterlogged::FALSE:
                    return 10808;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10809;
                case Properties::Waterlogged::FALSE:
                    return 10810;
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
