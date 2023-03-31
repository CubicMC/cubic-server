#include "PolishedAndesiteSlab.hpp"
#include <stdexcept>

namespace Blocks {
namespace PolishedAndesiteSlab {
BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::TOP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13520;
        case Properties::Waterlogged::FALSE:
            return 13521;
        }
    case Properties::Type::BOTTOM:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13522;
        case Properties::Waterlogged::FALSE:
            return 13523;
        }
    case Properties::Type::DOUBLE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 13524;
        case Properties::Waterlogged::FALSE:
            return 13525;
        }
    }
    return 0;
}
}

}
