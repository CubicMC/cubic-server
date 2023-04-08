#include "BirchSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace BirchSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10697;
        case Properties::Waterlogged::FALSE:
            return 10698;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10699;
        case Properties::Waterlogged::FALSE:
            return 10700;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 10701;
        case Properties::Waterlogged::FALSE:
            return 10702;
        }
    }
    return 0;
}
}

}
