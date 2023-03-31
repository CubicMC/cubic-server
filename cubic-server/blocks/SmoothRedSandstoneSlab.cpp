#include "SmoothRedSandstoneSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace SmoothRedSandstoneSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13460;
        case Properties::Waterlogged::FALSE:
            return 13461;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13462;
        case Properties::Waterlogged::FALSE:
            return 13463;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13464;
        case Properties::Waterlogged::FALSE:
            return 13465;
        }
    }
    return 0;
}
}

}
