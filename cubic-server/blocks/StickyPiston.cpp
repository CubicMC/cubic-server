#include "StickyPiston.hpp"
#include <stdexcept>

namespace Blocks {
    namespace StickyPiston {
        BlockId toProtocol(Properties::Extended extended, Properties::Facing facing) {
            switch (extended) {
            case Properties::Extended::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 1941;
                case Properties::Facing::EAST:
                    return 1942;
                case Properties::Facing::SOUTH:
                    return 1943;
                case Properties::Facing::WEST:
                    return 1944;
                case Properties::Facing::UP:
                    return 1945;
                case Properties::Facing::DOWN:
                    return 1946;
                }
            case Properties::Extended::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 1947;
                case Properties::Facing::EAST:
                    return 1948;
                case Properties::Facing::SOUTH:
                    return 1949;
                case Properties::Facing::WEST:
                    return 1950;
                case Properties::Facing::UP:
                    return 1951;
                case Properties::Facing::DOWN:
                    return 1952;
                }
            }
            return 0;
        }
    }

}
