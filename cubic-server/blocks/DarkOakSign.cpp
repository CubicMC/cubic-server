#include "DarkOakSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DarkOakSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4410;
                case Properties::Waterlogged::FALSE:
                    return 4411;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4412;
                case Properties::Waterlogged::FALSE:
                    return 4413;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4414;
                case Properties::Waterlogged::FALSE:
                    return 4415;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4416;
                case Properties::Waterlogged::FALSE:
                    return 4417;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4418;
                case Properties::Waterlogged::FALSE:
                    return 4419;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4420;
                case Properties::Waterlogged::FALSE:
                    return 4421;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4422;
                case Properties::Waterlogged::FALSE:
                    return 4423;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4424;
                case Properties::Waterlogged::FALSE:
                    return 4425;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4426;
                case Properties::Waterlogged::FALSE:
                    return 4427;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4428;
                case Properties::Waterlogged::FALSE:
                    return 4429;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4430;
                case Properties::Waterlogged::FALSE:
                    return 4431;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4432;
                case Properties::Waterlogged::FALSE:
                    return 4433;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4434;
                case Properties::Waterlogged::FALSE:
                    return 4435;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4436;
                case Properties::Waterlogged::FALSE:
                    return 4437;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4438;
                case Properties::Waterlogged::FALSE:
                    return 4439;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4440;
                case Properties::Waterlogged::FALSE:
                    return 4441;
                }
            }
            return 0;
        }
    }

}
