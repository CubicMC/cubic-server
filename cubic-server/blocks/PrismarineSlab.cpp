#include "PrismarineSlab.hpp"
namespace Blocks {
    namespace PrismarineSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10229;
                case Properties::Waterlogged::FALSE:
                    return 10230;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10231;
                case Properties::Waterlogged::FALSE:
                    return 10232;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10233;
                case Properties::Waterlogged::FALSE:
                    return 10234;
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
