#include "JungleHangingSign.hpp"
namespace Blocks {
    namespace JungleHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 4998;
                    case Properties::Waterlogged::FALSE:
                        return 4999;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5000;
                    case Properties::Waterlogged::FALSE:
                        return 5001;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5002;
                    case Properties::Waterlogged::FALSE:
                        return 5003;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5004;
                    case Properties::Waterlogged::FALSE:
                        return 5005;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5006;
                    case Properties::Waterlogged::FALSE:
                        return 5007;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5008;
                    case Properties::Waterlogged::FALSE:
                        return 5009;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5010;
                    case Properties::Waterlogged::FALSE:
                        return 5011;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5012;
                    case Properties::Waterlogged::FALSE:
                        return 5013;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5014;
                    case Properties::Waterlogged::FALSE:
                        return 5015;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5016;
                    case Properties::Waterlogged::FALSE:
                        return 5017;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5018;
                    case Properties::Waterlogged::FALSE:
                        return 5019;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5020;
                    case Properties::Waterlogged::FALSE:
                        return 5021;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5022;
                    case Properties::Waterlogged::FALSE:
                        return 5023;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5024;
                    case Properties::Waterlogged::FALSE:
                        return 5025;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5026;
                    case Properties::Waterlogged::FALSE:
                        return 5027;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5028;
                    case Properties::Waterlogged::FALSE:
                        return 5029;
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
                        return 5030;
                    case Properties::Waterlogged::FALSE:
                        return 5031;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5032;
                    case Properties::Waterlogged::FALSE:
                        return 5033;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5034;
                    case Properties::Waterlogged::FALSE:
                        return 5035;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5036;
                    case Properties::Waterlogged::FALSE:
                        return 5037;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5038;
                    case Properties::Waterlogged::FALSE:
                        return 5039;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5040;
                    case Properties::Waterlogged::FALSE:
                        return 5041;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5042;
                    case Properties::Waterlogged::FALSE:
                        return 5043;
                    default:
                        return 0;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5044;
                    case Properties::Waterlogged::FALSE:
                        return 5045;
                    default:
                        return 0;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5046;
                    case Properties::Waterlogged::FALSE:
                        return 5047;
                    default:
                        return 0;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5048;
                    case Properties::Waterlogged::FALSE:
                        return 5049;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5050;
                    case Properties::Waterlogged::FALSE:
                        return 5051;
                    default:
                        return 0;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5052;
                    case Properties::Waterlogged::FALSE:
                        return 5053;
                    default:
                        return 0;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5054;
                    case Properties::Waterlogged::FALSE:
                        return 5055;
                    default:
                        return 0;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5056;
                    case Properties::Waterlogged::FALSE:
                        return 5057;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5058;
                    case Properties::Waterlogged::FALSE:
                        return 5059;
                    default:
                        return 0;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5060;
                    case Properties::Waterlogged::FALSE:
                        return 5061;
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
