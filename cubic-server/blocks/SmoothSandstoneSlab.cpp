#include "SmoothSandstoneSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace SmoothSandstoneSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13490;
        case Properties::Waterlogged::FALSE:
            return 13491;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13492;
        case Properties::Waterlogged::FALSE:
            return 13493;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13494;
        case Properties::Waterlogged::FALSE:
            return 13495;
        }
    }
    return 0;
}
}

}
