#include "WaxedCutCopperSlab.hpp"
namespace Blocks {
    namespace WaxedCutCopperSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21392;
                case Properties::Waterlogged::FALSE:
                    return 21393;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21394;
                case Properties::Waterlogged::FALSE:
                    return 21395;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21396;
                case Properties::Waterlogged::FALSE:
                    return 21397;
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
