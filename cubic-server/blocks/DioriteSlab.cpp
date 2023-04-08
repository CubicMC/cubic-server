#include "DioriteSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace DioriteSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13526;
        case Properties::Waterlogged::FALSE:
            return 13527;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13528;
        case Properties::Waterlogged::FALSE:
            return 13529;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13530;
        case Properties::Waterlogged::FALSE:
            return 13531;
        }
    }
    return 0;
}
}

}
