#include "AndesiteSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace AndesiteSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13508;
        case Properties::Waterlogged::FALSE:
            return 13509;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13510;
        case Properties::Waterlogged::FALSE:
            return 13511;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13512;
        case Properties::Waterlogged::FALSE:
            return 13513;
        }
    }
    return 0;
}
}

}
