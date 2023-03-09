#include "JungleSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace JungleSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4378;
                case Properties::Waterlogged::FALSE:
                    return 4379;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4380;
                case Properties::Waterlogged::FALSE:
                    return 4381;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4382;
                case Properties::Waterlogged::FALSE:
                    return 4383;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4384;
                case Properties::Waterlogged::FALSE:
                    return 4385;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4386;
                case Properties::Waterlogged::FALSE:
                    return 4387;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4388;
                case Properties::Waterlogged::FALSE:
                    return 4389;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4390;
                case Properties::Waterlogged::FALSE:
                    return 4391;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4392;
                case Properties::Waterlogged::FALSE:
                    return 4393;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4394;
                case Properties::Waterlogged::FALSE:
                    return 4395;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4396;
                case Properties::Waterlogged::FALSE:
                    return 4397;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4398;
                case Properties::Waterlogged::FALSE:
                    return 4399;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4400;
                case Properties::Waterlogged::FALSE:
                    return 4401;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4402;
                case Properties::Waterlogged::FALSE:
                    return 4403;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4404;
                case Properties::Waterlogged::FALSE:
                    return 4405;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4406;
                case Properties::Waterlogged::FALSE:
                    return 4407;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4408;
                case Properties::Waterlogged::FALSE:
                    return 4409;
                }
            }
            return 0;
        }
    }

}
