#include "Light.hpp"
namespace Blocks {
namespace Light {
BlockId toProtocol(Properties::Level level, Properties::Waterlogged waterlogged) {
    switch (level) {
    case Properties::Level::ZERO:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9890;
        case Properties::Waterlogged::FALSE:
            return 9891;
        default:
            return 0;
        }
    case Properties::Level::ONE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9892;
        case Properties::Waterlogged::FALSE:
            return 9893;
        default:
            return 0;
        }
    case Properties::Level::TWO:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9894;
        case Properties::Waterlogged::FALSE:
            return 9895;
        default:
            return 0;
        }
    case Properties::Level::THREE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9896;
        case Properties::Waterlogged::FALSE:
            return 9897;
        default:
            return 0;
        }
    case Properties::Level::FOUR:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9898;
        case Properties::Waterlogged::FALSE:
            return 9899;
        default:
            return 0;
        }
    case Properties::Level::FIVE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9900;
        case Properties::Waterlogged::FALSE:
            return 9901;
        default:
            return 0;
        }
    case Properties::Level::SIX:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9902;
        case Properties::Waterlogged::FALSE:
            return 9903;
        default:
            return 0;
        }
    case Properties::Level::SEVEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9904;
        case Properties::Waterlogged::FALSE:
            return 9905;
        default:
            return 0;
        }
    case Properties::Level::EIGHT:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9906;
        case Properties::Waterlogged::FALSE:
            return 9907;
        default:
            return 0;
        }
    case Properties::Level::NINE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9908;
        case Properties::Waterlogged::FALSE:
            return 9909;
        default:
            return 0;
        }
    case Properties::Level::TEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9910;
        case Properties::Waterlogged::FALSE:
            return 9911;
        default:
            return 0;
        }
    case Properties::Level::ELEVEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9912;
        case Properties::Waterlogged::FALSE:
            return 9913;
        default:
            return 0;
        }
    case Properties::Level::TWELVE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9914;
        case Properties::Waterlogged::FALSE:
            return 9915;
        default:
            return 0;
        }
    case Properties::Level::THIRTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9916;
        case Properties::Waterlogged::FALSE:
            return 9917;
        default:
            return 0;
        }
    case Properties::Level::FOURTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9918;
        case Properties::Waterlogged::FALSE:
            return 9919;
        default:
            return 0;
        }
    case Properties::Level::FIFTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 9920;
        case Properties::Waterlogged::FALSE:
            return 9921;
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
