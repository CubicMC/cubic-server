#include "PurpurSlab.hpp"
namespace Blocks {
    namespace PurpurSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10817;
                case Properties::Waterlogged::FALSE:
                    return 10818;
                default:
                    return 0;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10819;
                case Properties::Waterlogged::FALSE:
                    return 10820;
                default:
                    return 0;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10821;
                case Properties::Waterlogged::FALSE:
                    return 10822;
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
