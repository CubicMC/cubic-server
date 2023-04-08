#include "TurtleEgg.hpp"
#include <stdexcept>

namespace Blocks {
namespace TurtleEgg {
BlockId toProtocol(Properties::Eggs eggs, Properties::Hatch hatch)
{
    switch (eggs) {
    case Properties::Eggs::ONE:
        switch (hatch) {
        case Properties::Hatch::ZERO:
            return 12163;
        case Properties::Hatch::ONE:
            return 12164;
        case Properties::Hatch::TWO:
            return 12165;
        }
    case Properties::Eggs::TWO:
        switch (hatch) {
        case Properties::Hatch::ZERO:
            return 12166;
        case Properties::Hatch::ONE:
            return 12167;
        case Properties::Hatch::TWO:
            return 12168;
        }
    case Properties::Eggs::THREE:
        switch (hatch) {
        case Properties::Hatch::ZERO:
            return 12169;
        case Properties::Hatch::ONE:
            return 12170;
        case Properties::Hatch::TWO:
            return 12171;
        }
    case Properties::Eggs::FOUR:
        switch (hatch) {
        case Properties::Hatch::ZERO:
            return 12172;
        case Properties::Hatch::ONE:
            return 12173;
        case Properties::Hatch::TWO:
            return 12174;
        }
    }
    return 0;
}
}

}
