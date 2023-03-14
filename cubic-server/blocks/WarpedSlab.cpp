#include "WarpedSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WarpedSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18046;
                case Properties::Waterlogged::FALSE:
                    return 18047;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18048;
                case Properties::Waterlogged::FALSE:
                    return 18049;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18050;
                case Properties::Waterlogged::FALSE:
                    return 18051;
                }
            }
            return 0;
        }
    }

}
