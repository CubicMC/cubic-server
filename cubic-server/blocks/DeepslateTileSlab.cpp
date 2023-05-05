#include "DeepslateTileSlab.hpp"
namespace Blocks {
    namespace DeepslateTileSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 22468;
                case Properties::Waterlogged::FALSE:
                    return 22469;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 22470;
                case Properties::Waterlogged::FALSE:
                    return 22471;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 22472;
                case Properties::Waterlogged::FALSE:
                    return 22473;
                }
            }
            return 0;
        }
    }

}
