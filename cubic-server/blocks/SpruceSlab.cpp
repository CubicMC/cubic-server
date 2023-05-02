#include "SpruceSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace SpruceSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10691;
        case Properties::Waterlogged::FALSE:
            return 10692;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10693;
        case Properties::Waterlogged::FALSE:
            return 10694;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10695;
        case Properties::Waterlogged::FALSE:
            return 10696;
        }
    }
    return 0;
}
}

}
