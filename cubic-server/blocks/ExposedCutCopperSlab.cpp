#include "ExposedCutCopperSlab.hpp"
namespace Blocks {
    namespace ExposedCutCopperSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21034;
                case Properties::Waterlogged::FALSE:
                    return 21035;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21036;
                case Properties::Waterlogged::FALSE:
                    return 21037;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21038;
                case Properties::Waterlogged::FALSE:
                    return 21039;
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
