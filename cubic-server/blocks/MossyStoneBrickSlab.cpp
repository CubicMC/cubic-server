#include "MossyStoneBrickSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace MossyStoneBrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13466;
        case Properties::Waterlogged::FALSE:
            return 13467;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13468;
        case Properties::Waterlogged::FALSE:
            return 13469;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13470;
        case Properties::Waterlogged::FALSE:
            return 13471;
        }
    }
    return 0;
}
}

}
