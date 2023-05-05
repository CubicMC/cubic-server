#include "CutCopperSlab.hpp"
namespace Blocks {
    namespace CutCopperSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21040;
                case Properties::Waterlogged::FALSE:
                    return 21041;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21042;
                case Properties::Waterlogged::FALSE:
                    return 21043;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21044;
                case Properties::Waterlogged::FALSE:
                    return 21045;
                }
            }
            return 0;
        }
    }

}
