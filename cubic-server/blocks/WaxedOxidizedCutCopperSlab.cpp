#include "WaxedOxidizedCutCopperSlab.hpp"
namespace Blocks {
    namespace WaxedOxidizedCutCopperSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21374;
                case Properties::Waterlogged::FALSE:
                    return 21375;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21376;
                case Properties::Waterlogged::FALSE:
                    return 21377;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21378;
                case Properties::Waterlogged::FALSE:
                    return 21379;
                }
            }
            return 0;
        }
    }

}
