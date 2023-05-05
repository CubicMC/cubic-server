#include "PolishedDioriteSlab.hpp"
namespace Blocks {
    namespace PolishedDioriteSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13472;
                case Properties::Waterlogged::FALSE:
                    return 13473;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13474;
                case Properties::Waterlogged::FALSE:
                    return 13475;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13476;
                case Properties::Waterlogged::FALSE:
                    return 13477;
                }
            }
            return 0;
        }
    }

}
