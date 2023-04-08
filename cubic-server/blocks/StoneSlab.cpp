#include "StoneSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace StoneSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10739;
        case Properties::Waterlogged::FALSE:
            return 10740;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10741;
        case Properties::Waterlogged::FALSE:
            return 10742;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10743;
        case Properties::Waterlogged::FALSE:
            return 10744;
        }
    }
    return 0;
}
}

}
