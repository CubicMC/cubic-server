#include "DarkOakHangingSign.hpp"
namespace Blocks {
    namespace DarkOakHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5062;
                    case Properties::Waterlogged::FALSE:
                        return 5063;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5064;
                    case Properties::Waterlogged::FALSE:
                        return 5065;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5066;
                    case Properties::Waterlogged::FALSE:
                        return 5067;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5068;
                    case Properties::Waterlogged::FALSE:
                        return 5069;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5070;
                    case Properties::Waterlogged::FALSE:
                        return 5071;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5072;
                    case Properties::Waterlogged::FALSE:
                        return 5073;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5074;
                    case Properties::Waterlogged::FALSE:
                        return 5075;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5076;
                    case Properties::Waterlogged::FALSE:
                        return 5077;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5078;
                    case Properties::Waterlogged::FALSE:
                        return 5079;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5080;
                    case Properties::Waterlogged::FALSE:
                        return 5081;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5082;
                    case Properties::Waterlogged::FALSE:
                        return 5083;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5084;
                    case Properties::Waterlogged::FALSE:
                        return 5085;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5086;
                    case Properties::Waterlogged::FALSE:
                        return 5087;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5088;
                    case Properties::Waterlogged::FALSE:
                        return 5089;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5090;
                    case Properties::Waterlogged::FALSE:
                        return 5091;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5092;
                    case Properties::Waterlogged::FALSE:
                        return 5093;
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
                        return 5094;
                    case Properties::Waterlogged::FALSE:
                        return 5095;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5096;
                    case Properties::Waterlogged::FALSE:
                        return 5097;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5098;
                    case Properties::Waterlogged::FALSE:
                        return 5099;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5100;
                    case Properties::Waterlogged::FALSE:
                        return 5101;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5102;
                    case Properties::Waterlogged::FALSE:
                        return 5103;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5104;
                    case Properties::Waterlogged::FALSE:
                        return 5105;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5106;
                    case Properties::Waterlogged::FALSE:
                        return 5107;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5108;
                    case Properties::Waterlogged::FALSE:
                        return 5109;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5110;
                    case Properties::Waterlogged::FALSE:
                        return 5111;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5112;
                    case Properties::Waterlogged::FALSE:
                        return 5113;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5114;
                    case Properties::Waterlogged::FALSE:
                        return 5115;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5116;
                    case Properties::Waterlogged::FALSE:
                        return 5117;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5118;
                    case Properties::Waterlogged::FALSE:
                        return 5119;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5120;
                    case Properties::Waterlogged::FALSE:
                        return 5121;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5122;
                    case Properties::Waterlogged::FALSE:
                        return 5123;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5124;
                    case Properties::Waterlogged::FALSE:
                        return 5125;
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
