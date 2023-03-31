#include "SoulLantern.hpp"
#include <stdexcept>

namespace Blocks {
namespace SoulLantern {
BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged)
{
    switch (hanging) {
    case Properties::Hanging::TRUE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 17879;
        case Properties::Waterlogged::FALSE:
            return 17880;
        }
    case Properties::Hanging::FALSE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 17881;
        case Properties::Waterlogged::FALSE:
            return 17882;
        }
    }
    return 0;
}
}

}
