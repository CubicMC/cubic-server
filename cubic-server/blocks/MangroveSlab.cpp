#include "MangroveSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace MangroveSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10721;
        case Properties::Waterlogged::FALSE:
            return 10722;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10723;
        case Properties::Waterlogged::FALSE:
            return 10724;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10725;
        case Properties::Waterlogged::FALSE:
            return 10726;
        }
    }
    return 0;
}
}

}
