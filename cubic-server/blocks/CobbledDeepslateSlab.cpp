#include "CobbledDeepslateSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CobbledDeepslateSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21646;
                case Properties::Waterlogged::FALSE:
                    return 21647;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21648;
                case Properties::Waterlogged::FALSE:
                    return 21649;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21650;
                case Properties::Waterlogged::FALSE:
                    return 21651;
                }
            }
            return 0;
        }
    }

}
