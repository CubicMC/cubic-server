#include "BeeNest.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BeeNest {
        BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 18769;
                case Properties::Honey_level::ONE:
                    return 18770;
                case Properties::Honey_level::TWO:
                    return 18771;
                case Properties::Honey_level::THREE:
                    return 18772;
                case Properties::Honey_level::FOUR:
                    return 18773;
                case Properties::Honey_level::FIVE:
                    return 18774;
                }
            case Properties::Facing::SOUTH:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 18775;
                case Properties::Honey_level::ONE:
                    return 18776;
                case Properties::Honey_level::TWO:
                    return 18777;
                case Properties::Honey_level::THREE:
                    return 18778;
                case Properties::Honey_level::FOUR:
                    return 18779;
                case Properties::Honey_level::FIVE:
                    return 18780;
                }
            case Properties::Facing::WEST:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 18781;
                case Properties::Honey_level::ONE:
                    return 18782;
                case Properties::Honey_level::TWO:
                    return 18783;
                case Properties::Honey_level::THREE:
                    return 18784;
                case Properties::Honey_level::FOUR:
                    return 18785;
                case Properties::Honey_level::FIVE:
                    return 18786;
                }
            case Properties::Facing::EAST:
                switch (honey_level) {
                case Properties::Honey_level::ZERO:
                    return 18787;
                case Properties::Honey_level::ONE:
                    return 18788;
                case Properties::Honey_level::TWO:
                    return 18789;
                case Properties::Honey_level::THREE:
                    return 18790;
                case Properties::Honey_level::FOUR:
                    return 18791;
                case Properties::Honey_level::FIVE:
                    return 18792;
                }
            }
            return 0;
        }
    }

}
