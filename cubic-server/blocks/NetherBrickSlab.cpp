#include "NetherBrickSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace NetherBrickSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10793;
        case Properties::Waterlogged::FALSE:
            return 10794;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10795;
        case Properties::Waterlogged::FALSE:
            return 10796;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10797;
        case Properties::Waterlogged::FALSE:
            return 10798;
        }
    }
    return 0;
}
}

}
