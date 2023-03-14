#include "DarkPrismarineSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DarkPrismarineSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10241;
                case Properties::Waterlogged::FALSE:
                    return 10242;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10243;
                case Properties::Waterlogged::FALSE:
                    return 10244;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10245;
                case Properties::Waterlogged::FALSE:
                    return 10246;
                }
            }
            return 0;
        }
    }

}
