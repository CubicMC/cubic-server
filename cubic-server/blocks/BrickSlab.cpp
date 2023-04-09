#include "BrickSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace BrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10775;
        case Properties::Waterlogged::FALSE:
            return 10776;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10777;
        case Properties::Waterlogged::FALSE:
            return 10778;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10779;
        case Properties::Waterlogged::FALSE:
            return 10780;
        }
    }
    return 0;
}
}

}
