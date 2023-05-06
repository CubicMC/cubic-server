#include "SmoothSandstoneSlab.hpp"
namespace Blocks {
    namespace SmoothSandstoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13490;
                case Properties::Waterlogged::FALSE:
                    return 13491;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13492;
                case Properties::Waterlogged::FALSE:
                    return 13493;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13494;
                case Properties::Waterlogged::FALSE:
                    return 13495;
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
