#include "PolishedBlackstoneSlab.hpp"
namespace Blocks {
    namespace PolishedBlackstoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 19738;
                case Properties::Waterlogged::FALSE:
                    return 19739;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 19740;
                case Properties::Waterlogged::FALSE:
                    return 19741;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 19742;
                case Properties::Waterlogged::FALSE:
                    return 19743;
                }
            }
            return 0;
        }
    }

}
