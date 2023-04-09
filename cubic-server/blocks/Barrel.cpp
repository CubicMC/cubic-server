#include "Barrel.hpp"
#include <stdexcept>

namespace Blocks {
namespace Barrel {
BlockId toProtocol(Properties::Facing facing, Properties::Open open)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (open) {
        case Properties::Open::TRUE:
            return 17780;
        case Properties::Open::FALSE:
            return 17781;
        }
    case Properties::Facing::EAST:
        switch (open) {
        case Properties::Open::TRUE:
            return 17782;
        case Properties::Open::FALSE:
            return 17783;
        }
    case Properties::Facing::SOUTH:
        switch (open) {
        case Properties::Open::TRUE:
            return 17784;
        case Properties::Open::FALSE:
            return 17785;
        }
    case Properties::Facing::WEST:
        switch (open) {
        case Properties::Open::TRUE:
            return 17786;
        case Properties::Open::FALSE:
            return 17787;
        }
    case Properties::Facing::UP:
        switch (open) {
        case Properties::Open::TRUE:
            return 17788;
        case Properties::Open::FALSE:
            return 17789;
        }
    case Properties::Facing::DOWN:
        switch (open) {
        case Properties::Open::TRUE:
            return 17790;
        case Properties::Open::FALSE:
            return 17791;
        }
    }
    return 0;
}
}

}
