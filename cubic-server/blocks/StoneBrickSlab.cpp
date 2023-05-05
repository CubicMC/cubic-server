#include "StoneBrickSlab.hpp"
namespace Blocks {
    namespace StoneBrickSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10781;
                case Properties::Waterlogged::FALSE:
                    return 10782;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10783;
                case Properties::Waterlogged::FALSE:
                    return 10784;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10785;
                case Properties::Waterlogged::FALSE:
                    return 10786;
                }
            }
            return 0;
        }
    }

}
