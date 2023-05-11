#include "PistonHead.hpp"
namespace Blocks {
namespace PistonHead {
BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Short_ short_)
{
    switch (type) {
    case Properties::Type::NORMAL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1972;
            case Properties::Short_::FALSE:
                return 1974;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1976;
            case Properties::Short_::FALSE:
                return 1978;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1980;
            case Properties::Short_::FALSE:
                return 1982;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1984;
            case Properties::Short_::FALSE:
                return 1986;
            default:
                return 0;
            }
        case Properties::Facing::UP:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1988;
            case Properties::Short_::FALSE:
                return 1990;
            default:
                return 0;
            }
        case Properties::Facing::DOWN:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1992;
            case Properties::Short_::FALSE:
                return 1994;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Type::STICKY:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1973;
            case Properties::Short_::FALSE:
                return 1975;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1977;
            case Properties::Short_::FALSE:
                return 1979;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1981;
            case Properties::Short_::FALSE:
                return 1983;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1985;
            case Properties::Short_::FALSE:
                return 1987;
            default:
                return 0;
            }
        case Properties::Facing::UP:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1989;
            case Properties::Short_::FALSE:
                return 1991;
            default:
                return 0;
            }
        case Properties::Facing::DOWN:
            switch (short_) {
            case Properties::Short_::TRUE:
                return 1993;
            case Properties::Short_::FALSE:
                return 1995;
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
