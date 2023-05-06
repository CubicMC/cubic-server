#include "CrimsonSlab.hpp"
namespace Blocks {
    namespace CrimsonSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18040;
                case Properties::Waterlogged::FALSE:
                    return 18041;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18042;
                case Properties::Waterlogged::FALSE:
                    return 18043;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18044;
                case Properties::Waterlogged::FALSE:
                    return 18045;
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
