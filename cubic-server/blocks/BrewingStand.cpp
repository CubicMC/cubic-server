#include "BrewingStand.hpp"
namespace Blocks {
namespace BrewingStand {
BlockId toProtocol(Properties::Has_bottle_0 has_bottle_0, Properties::Has_bottle_1 has_bottle_1, Properties::Has_bottle_2 has_bottle_2) {
    switch (has_bottle_0) {
    case Properties::Has_bottle_0::TRUE:
        switch (has_bottle_1) {
        case Properties::Has_bottle_1::TRUE:
            switch (has_bottle_2) {
            case Properties::Has_bottle_2::TRUE:
                return 7160;
            case Properties::Has_bottle_2::FALSE:
                return 7161;
            default:
                return 0;
            }
        case Properties::Has_bottle_1::FALSE:
            switch (has_bottle_2) {
            case Properties::Has_bottle_2::TRUE:
                return 7162;
            case Properties::Has_bottle_2::FALSE:
                return 7163;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Has_bottle_0::FALSE:
        switch (has_bottle_1) {
        case Properties::Has_bottle_1::TRUE:
            switch (has_bottle_2) {
            case Properties::Has_bottle_2::TRUE:
                return 7164;
            case Properties::Has_bottle_2::FALSE:
                return 7165;
            default:
                return 0;
            }
        case Properties::Has_bottle_1::FALSE:
            switch (has_bottle_2) {
            case Properties::Has_bottle_2::TRUE:
                return 7166;
            case Properties::Has_bottle_2::FALSE:
                return 7167;
            default:
                return 0;
            }
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
