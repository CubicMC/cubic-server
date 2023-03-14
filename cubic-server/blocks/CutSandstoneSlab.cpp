#include "CutSandstoneSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CutSandstoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10757;
                case Properties::Waterlogged::FALSE:
                    return 10758;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10759;
                case Properties::Waterlogged::FALSE:
                    return 10760;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10761;
                case Properties::Waterlogged::FALSE:
                    return 10762;
                }
            }
            return 0;
        }
    }

}
