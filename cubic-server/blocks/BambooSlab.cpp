#include "BambooSlab.hpp"
namespace Blocks {
    namespace BambooSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10727;
                case Properties::Waterlogged::FALSE:
                    return 10728;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10729;
                case Properties::Waterlogged::FALSE:
                    return 10730;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10731;
                case Properties::Waterlogged::FALSE:
                    return 10732;
                }
            }
            return 0;
        }
    }

}
