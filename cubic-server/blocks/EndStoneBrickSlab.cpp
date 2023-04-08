#include "EndStoneBrickSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace EndStoneBrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13484;
        case Properties::Waterlogged::FALSE:
            return 13485;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13486;
        case Properties::Waterlogged::FALSE:
            return 13487;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13488;
        case Properties::Waterlogged::FALSE:
            return 13489;
        }
    }
    return 0;
}
}

}
