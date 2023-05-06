#include "WarpedHangingSign.hpp"
namespace Blocks {
    namespace WarpedHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5190;
                    case Properties::Waterlogged::FALSE:
                        return 5191;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5192;
                    case Properties::Waterlogged::FALSE:
                        return 5193;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5194;
                    case Properties::Waterlogged::FALSE:
                        return 5195;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5196;
                    case Properties::Waterlogged::FALSE:
                        return 5197;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5198;
                    case Properties::Waterlogged::FALSE:
                        return 5199;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5200;
                    case Properties::Waterlogged::FALSE:
                        return 5201;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5202;
                    case Properties::Waterlogged::FALSE:
                        return 5203;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5204;
                    case Properties::Waterlogged::FALSE:
                        return 5205;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5206;
                    case Properties::Waterlogged::FALSE:
                        return 5207;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5208;
                    case Properties::Waterlogged::FALSE:
                        return 5209;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5210;
                    case Properties::Waterlogged::FALSE:
                        return 5211;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5212;
                    case Properties::Waterlogged::FALSE:
                        return 5213;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5214;
                    case Properties::Waterlogged::FALSE:
                        return 5215;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5216;
                    case Properties::Waterlogged::FALSE:
                        return 5217;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5218;
                    case Properties::Waterlogged::FALSE:
                        return 5219;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5220;
                    case Properties::Waterlogged::FALSE:
                        return 5221;
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
                        return 5222;
                    case Properties::Waterlogged::FALSE:
                        return 5223;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5224;
                    case Properties::Waterlogged::FALSE:
                        return 5225;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5226;
                    case Properties::Waterlogged::FALSE:
                        return 5227;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5228;
                    case Properties::Waterlogged::FALSE:
                        return 5229;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5230;
                    case Properties::Waterlogged::FALSE:
                        return 5231;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5232;
                    case Properties::Waterlogged::FALSE:
                        return 5233;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5234;
                    case Properties::Waterlogged::FALSE:
                        return 5235;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5236;
                    case Properties::Waterlogged::FALSE:
                        return 5237;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5238;
                    case Properties::Waterlogged::FALSE:
                        return 5239;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5240;
                    case Properties::Waterlogged::FALSE:
                        return 5241;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5242;
                    case Properties::Waterlogged::FALSE:
                        return 5243;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5244;
                    case Properties::Waterlogged::FALSE:
                        return 5245;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5246;
                    case Properties::Waterlogged::FALSE:
                        return 5247;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5248;
                    case Properties::Waterlogged::FALSE:
                        return 5249;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5250;
                    case Properties::Waterlogged::FALSE:
                        return 5251;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5252;
                    case Properties::Waterlogged::FALSE:
                        return 5253;
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
