#include "MangroveHangingSign.hpp"
namespace Blocks {
    namespace MangroveHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5254;
                    case Properties::Waterlogged::FALSE:
                        return 5255;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5256;
                    case Properties::Waterlogged::FALSE:
                        return 5257;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5258;
                    case Properties::Waterlogged::FALSE:
                        return 5259;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5260;
                    case Properties::Waterlogged::FALSE:
                        return 5261;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5262;
                    case Properties::Waterlogged::FALSE:
                        return 5263;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5264;
                    case Properties::Waterlogged::FALSE:
                        return 5265;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5266;
                    case Properties::Waterlogged::FALSE:
                        return 5267;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5268;
                    case Properties::Waterlogged::FALSE:
                        return 5269;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5270;
                    case Properties::Waterlogged::FALSE:
                        return 5271;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5272;
                    case Properties::Waterlogged::FALSE:
                        return 5273;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5274;
                    case Properties::Waterlogged::FALSE:
                        return 5275;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5276;
                    case Properties::Waterlogged::FALSE:
                        return 5277;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5278;
                    case Properties::Waterlogged::FALSE:
                        return 5279;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5280;
                    case Properties::Waterlogged::FALSE:
                        return 5281;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5282;
                    case Properties::Waterlogged::FALSE:
                        return 5283;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5284;
                    case Properties::Waterlogged::FALSE:
                        return 5285;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Attached::FALSE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5286;
                    case Properties::Waterlogged::FALSE:
                        return 5287;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5288;
                    case Properties::Waterlogged::FALSE:
                        return 5289;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5290;
                    case Properties::Waterlogged::FALSE:
                        return 5291;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5292;
                    case Properties::Waterlogged::FALSE:
                        return 5293;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5294;
                    case Properties::Waterlogged::FALSE:
                        return 5295;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5296;
                    case Properties::Waterlogged::FALSE:
                        return 5297;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5298;
                    case Properties::Waterlogged::FALSE:
                        return 5299;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5300;
                    case Properties::Waterlogged::FALSE:
                        return 5301;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5302;
                    case Properties::Waterlogged::FALSE:
                        return 5303;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5304;
                    case Properties::Waterlogged::FALSE:
                        return 5305;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5306;
                    case Properties::Waterlogged::FALSE:
                        return 5307;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5308;
                    case Properties::Waterlogged::FALSE:
                        return 5309;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5310;
                    case Properties::Waterlogged::FALSE:
                        return 5311;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5312;
                    case Properties::Waterlogged::FALSE:
                        return 5313;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5314;
                    case Properties::Waterlogged::FALSE:
                        return 5315;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5316;
                    case Properties::Waterlogged::FALSE:
                        return 5317;
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
