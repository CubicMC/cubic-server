#include "WaxedExposedCutCopperSlab.hpp"
namespace Blocks {
    namespace WaxedExposedCutCopperSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21386;
                case Properties::Waterlogged::FALSE:
                    return 21387;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21388;
                case Properties::Waterlogged::FALSE:
                    return 21389;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21390;
                case Properties::Waterlogged::FALSE:
                    return 21391;
                }
            }
            return 0;
        }
    }

}
