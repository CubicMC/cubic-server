#include "MossyCobblestoneSlab.hpp"
namespace Blocks {
    namespace MossyCobblestoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13478;
                case Properties::Waterlogged::FALSE:
                    return 13479;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13480;
                case Properties::Waterlogged::FALSE:
                    return 13481;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13482;
                case Properties::Waterlogged::FALSE:
                    return 13483;
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
