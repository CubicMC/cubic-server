#include "PrismarineBrickSlab.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PrismarineBrickSlab {
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged) {
            switch (type) {
            case Properties::Type::TOP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10235;
                case Properties::Waterlogged::FALSE:
                    return 10236;
                }
            case Properties::Type::BOTTOM:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10237;
                case Properties::Waterlogged::FALSE:
                    return 10238;
                }
            case Properties::Type::DOUBLE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10239;
                case Properties::Waterlogged::FALSE:
                    return 10240;
                }
            }
            return 0;
        }
    }

}
