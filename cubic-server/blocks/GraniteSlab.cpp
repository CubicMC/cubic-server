#include "GraniteSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GraniteSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13502;
                case Properties::Waterlogged::FALSE:
                    return 13503;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13504;
                case Properties::Waterlogged::FALSE:
                    return 13505;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13506;
                case Properties::Waterlogged::FALSE:
                    return 13507;
                }
            }
            return 0;
        }
    }

}
