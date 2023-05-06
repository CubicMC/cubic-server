#include "OakSlab.hpp"
namespace Blocks {
    namespace OakSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10685;
                case Properties::Waterlogged::FALSE:
                    return 10686;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10687;
                case Properties::Waterlogged::FALSE:
                    return 10688;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10689;
                case Properties::Waterlogged::FALSE:
                    return 10690;
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
