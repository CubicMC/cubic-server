#include "AcaciaSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace AcaciaSign {
BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged)
{
    switch (rotation) {
    case Properties::Rotation::ZERO:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4346;
        case Properties::Waterlogged::FALSE:
            return 4347;
        }
    case Properties::Rotation::ONE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4348;
        case Properties::Waterlogged::FALSE:
            return 4349;
        }
    case Properties::Rotation::TWO:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4350;
        case Properties::Waterlogged::FALSE:
            return 4351;
        }
    case Properties::Rotation::THREE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4352;
        case Properties::Waterlogged::FALSE:
            return 4353;
        }
    case Properties::Rotation::FOUR:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4354;
        case Properties::Waterlogged::FALSE:
            return 4355;
        }
    case Properties::Rotation::FIVE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4356;
        case Properties::Waterlogged::FALSE:
            return 4357;
        }
    case Properties::Rotation::SIX:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4358;
        case Properties::Waterlogged::FALSE:
            return 4359;
        }
    case Properties::Rotation::SEVEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4360;
        case Properties::Waterlogged::FALSE:
            return 4361;
        }
    case Properties::Rotation::EIGHT:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4362;
        case Properties::Waterlogged::FALSE:
            return 4363;
        }
    case Properties::Rotation::NINE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4364;
        case Properties::Waterlogged::FALSE:
            return 4365;
        }
    case Properties::Rotation::TEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4366;
        case Properties::Waterlogged::FALSE:
            return 4367;
        }
    case Properties::Rotation::ELEVEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4368;
        case Properties::Waterlogged::FALSE:
            return 4369;
        }
    case Properties::Rotation::TWELVE:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4370;
        case Properties::Waterlogged::FALSE:
            return 4371;
        }
    case Properties::Rotation::THIRTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4372;
        case Properties::Waterlogged::FALSE:
            return 4373;
        }
    case Properties::Rotation::FOURTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4374;
        case Properties::Waterlogged::FALSE:
            return 4375;
        }
    case Properties::Rotation::FIFTEEN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4376;
        case Properties::Waterlogged::FALSE:
            return 4377;
        }
    }
    return 0;
}
}

}
