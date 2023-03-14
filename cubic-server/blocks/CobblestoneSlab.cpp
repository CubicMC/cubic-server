#include "CobblestoneSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CobblestoneSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10769;
                case Properties::Waterlogged::FALSE:
                    return 10770;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10771;
                case Properties::Waterlogged::FALSE:
                    return 10772;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10773;
                case Properties::Waterlogged::FALSE:
                    return 10774;
                }
            }
            return 0;
        }
    }

}
