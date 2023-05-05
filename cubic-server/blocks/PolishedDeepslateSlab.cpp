#include "PolishedDeepslateSlab.hpp"
namespace Blocks {
    namespace PolishedDeepslateSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 22057;
                case Properties::Waterlogged::FALSE:
                    return 22058;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 22059;
                case Properties::Waterlogged::FALSE:
                    return 22060;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 22061;
                case Properties::Waterlogged::FALSE:
                    return 22062;
                }
            }
            return 0;
        }
    }

}
