#include "SpruceSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace SpruceSign {
BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged)
{
    switch (rotation) {
    case Properties::Rotation::ZERO:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4282;
        case Properties::Waterlogged::FALSE:
            return 4283;
        }
    case Properties::Rotation::ONE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4284;
        case Properties::Waterlogged::FALSE:
            return 4285;
        }
    case Properties::Rotation::TWO:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4286;
        case Properties::Waterlogged::FALSE:
            return 4287;
        }
    case Properties::Rotation::THREE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4288;
        case Properties::Waterlogged::FALSE:
            return 4289;
        }
    case Properties::Rotation::FOUR:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4290;
        case Properties::Waterlogged::FALSE:
            return 4291;
        }
    case Properties::Rotation::FIVE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4292;
        case Properties::Waterlogged::FALSE:
            return 4293;
        }
    case Properties::Rotation::SIX:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4294;
        case Properties::Waterlogged::FALSE:
            return 4295;
        }
    case Properties::Rotation::SEVEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4296;
        case Properties::Waterlogged::FALSE:
            return 4297;
        }
    case Properties::Rotation::EIGHT:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4298;
        case Properties::Waterlogged::FALSE:
            return 4299;
        }
    case Properties::Rotation::NINE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4300;
        case Properties::Waterlogged::FALSE:
            return 4301;
        }
    case Properties::Rotation::TEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4302;
        case Properties::Waterlogged::FALSE:
            return 4303;
        }
    case Properties::Rotation::ELEVEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4304;
        case Properties::Waterlogged::FALSE:
            return 4305;
        }
    case Properties::Rotation::TWELVE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4306;
        case Properties::Waterlogged::FALSE:
            return 4307;
        }
    case Properties::Rotation::THIRTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4308;
        case Properties::Waterlogged::FALSE:
            return 4309;
        }
    case Properties::Rotation::FOURTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4310;
        case Properties::Waterlogged::FALSE:
            return 4311;
        }
    case Properties::Rotation::FIFTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4312;
        case Properties::Waterlogged::FALSE:
            return 4313;
        }
    }
    return 0;
}
}

}
