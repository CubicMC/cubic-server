#include "SmoothRedSandstoneSlab.hpp"
namespace Blocks {
    namespace SmoothRedSandstoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13460;
                case Properties::Waterlogged::FALSE:
                    return 13461;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13462;
                case Properties::Waterlogged::FALSE:
                    return 13463;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13464;
                case Properties::Waterlogged::FALSE:
                    return 13465;
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
