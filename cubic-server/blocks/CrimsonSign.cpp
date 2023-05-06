#include "CrimsonSign.hpp"
namespace Blocks {
    namespace CrimsonSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18648;
                case Properties::Waterlogged::FALSE:
                    return 18649;
                default:
                    return 0;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18650;
                case Properties::Waterlogged::FALSE:
                    return 18651;
                default:
                    return 0;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18652;
                case Properties::Waterlogged::FALSE:
                    return 18653;
                default:
                    return 0;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18654;
                case Properties::Waterlogged::FALSE:
                    return 18655;
                default:
                    return 0;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18656;
                case Properties::Waterlogged::FALSE:
                    return 18657;
                default:
                    return 0;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18658;
                case Properties::Waterlogged::FALSE:
                    return 18659;
                default:
                    return 0;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18660;
                case Properties::Waterlogged::FALSE:
                    return 18661;
                default:
                    return 0;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18662;
                case Properties::Waterlogged::FALSE:
                    return 18663;
                default:
                    return 0;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18664;
                case Properties::Waterlogged::FALSE:
                    return 18665;
                default:
                    return 0;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18666;
                case Properties::Waterlogged::FALSE:
                    return 18667;
                default:
                    return 0;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18668;
                case Properties::Waterlogged::FALSE:
                    return 18669;
                default:
                    return 0;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18670;
                case Properties::Waterlogged::FALSE:
                    return 18671;
                default:
                    return 0;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18672;
                case Properties::Waterlogged::FALSE:
                    return 18673;
                default:
                    return 0;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18674;
                case Properties::Waterlogged::FALSE:
                    return 18675;
                default:
                    return 0;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18676;
                case Properties::Waterlogged::FALSE:
                    return 18677;
                default:
                    return 0;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18678;
                case Properties::Waterlogged::FALSE:
                    return 18679;
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
