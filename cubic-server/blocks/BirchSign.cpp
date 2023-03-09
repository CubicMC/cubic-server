#include "BirchSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BirchSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4314;
                case Properties::Waterlogged::FALSE:
                    return 4315;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4316;
                case Properties::Waterlogged::FALSE:
                    return 4317;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4318;
                case Properties::Waterlogged::FALSE:
                    return 4319;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4320;
                case Properties::Waterlogged::FALSE:
                    return 4321;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4322;
                case Properties::Waterlogged::FALSE:
                    return 4323;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4324;
                case Properties::Waterlogged::FALSE:
                    return 4325;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4326;
                case Properties::Waterlogged::FALSE:
                    return 4327;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4328;
                case Properties::Waterlogged::FALSE:
                    return 4329;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4330;
                case Properties::Waterlogged::FALSE:
                    return 4331;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4332;
                case Properties::Waterlogged::FALSE:
                    return 4333;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4334;
                case Properties::Waterlogged::FALSE:
                    return 4335;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4336;
                case Properties::Waterlogged::FALSE:
                    return 4337;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4338;
                case Properties::Waterlogged::FALSE:
                    return 4339;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4340;
                case Properties::Waterlogged::FALSE:
                    return 4341;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4342;
                case Properties::Waterlogged::FALSE:
                    return 4343;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4344;
                case Properties::Waterlogged::FALSE:
                    return 4345;
                }
            }
            return 0;
        }
    }

}
