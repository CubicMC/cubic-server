#include "OakSign.hpp"
namespace Blocks {
    namespace OakSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4250;
                case Properties::Waterlogged::FALSE:
                    return 4251;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4252;
                case Properties::Waterlogged::FALSE:
                    return 4253;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4254;
                case Properties::Waterlogged::FALSE:
                    return 4255;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4256;
                case Properties::Waterlogged::FALSE:
                    return 4257;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4258;
                case Properties::Waterlogged::FALSE:
                    return 4259;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4260;
                case Properties::Waterlogged::FALSE:
                    return 4261;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4262;
                case Properties::Waterlogged::FALSE:
                    return 4263;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4264;
                case Properties::Waterlogged::FALSE:
                    return 4265;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4266;
                case Properties::Waterlogged::FALSE:
                    return 4267;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4268;
                case Properties::Waterlogged::FALSE:
                    return 4269;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4270;
                case Properties::Waterlogged::FALSE:
                    return 4271;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4272;
                case Properties::Waterlogged::FALSE:
                    return 4273;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4274;
                case Properties::Waterlogged::FALSE:
                    return 4275;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4276;
                case Properties::Waterlogged::FALSE:
                    return 4277;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4278;
                case Properties::Waterlogged::FALSE:
                    return 4279;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4280;
                case Properties::Waterlogged::FALSE:
                    return 4281;
                }
            }
            return 0;
        }
    }

}
