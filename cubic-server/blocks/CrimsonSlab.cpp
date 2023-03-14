#include "CrimsonSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace CrimsonSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18040;
                case Properties::Waterlogged::FALSE:
                    return 18041;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18042;
                case Properties::Waterlogged::FALSE:
                    return 18043;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18044;
                case Properties::Waterlogged::FALSE:
                    return 18045;
                }
            }
            return 0;
        }
    }

}
