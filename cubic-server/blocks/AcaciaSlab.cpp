#include "AcaciaSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace AcaciaSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10709;
                case Properties::Waterlogged::FALSE:
                    return 10710;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10711;
                case Properties::Waterlogged::FALSE:
                    return 10712;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10713;
                case Properties::Waterlogged::FALSE:
                    return 10714;
                }
            }
            return 0;
        }
    }

}
