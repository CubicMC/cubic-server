#include "BambooSign.hpp"
namespace Blocks {
    namespace BambooSign {
        BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (rotation) {
            case Properties::Rotation::ZERO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4474;
                case Properties::Waterlogged::FALSE:
                    return 4475;
                }
            case Properties::Rotation::ONE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4476;
                case Properties::Waterlogged::FALSE:
                    return 4477;
                }
            case Properties::Rotation::TWO:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4478;
                case Properties::Waterlogged::FALSE:
                    return 4479;
                }
            case Properties::Rotation::THREE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4480;
                case Properties::Waterlogged::FALSE:
                    return 4481;
                }
            case Properties::Rotation::FOUR:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4482;
                case Properties::Waterlogged::FALSE:
                    return 4483;
                }
            case Properties::Rotation::FIVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4484;
                case Properties::Waterlogged::FALSE:
                    return 4485;
                }
            case Properties::Rotation::SIX:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4486;
                case Properties::Waterlogged::FALSE:
                    return 4487;
                }
            case Properties::Rotation::SEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4488;
                case Properties::Waterlogged::FALSE:
                    return 4489;
                }
            case Properties::Rotation::EIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4490;
                case Properties::Waterlogged::FALSE:
                    return 4491;
                }
            case Properties::Rotation::NINE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4492;
                case Properties::Waterlogged::FALSE:
                    return 4493;
                }
            case Properties::Rotation::TEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4494;
                case Properties::Waterlogged::FALSE:
                    return 4495;
                }
            case Properties::Rotation::ELEVEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4496;
                case Properties::Waterlogged::FALSE:
                    return 4497;
                }
            case Properties::Rotation::TWELVE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4498;
                case Properties::Waterlogged::FALSE:
                    return 4499;
                }
            case Properties::Rotation::THIRTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4500;
                case Properties::Waterlogged::FALSE:
                    return 4501;
                }
            case Properties::Rotation::FOURTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4502;
                case Properties::Waterlogged::FALSE:
                    return 4503;
                }
            case Properties::Rotation::FIFTEEN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4504;
                case Properties::Waterlogged::FALSE:
                    return 4505;
                }
            }
            return 0;
        }
    }

}
