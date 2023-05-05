#include "CrimsonHangingSign.hpp"
namespace Blocks {
    namespace CrimsonHangingSign {
        BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5126;
                    case Properties::Waterlogged::FALSE:
                        return 5127;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5128;
                    case Properties::Waterlogged::FALSE:
                        return 5129;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5130;
                    case Properties::Waterlogged::FALSE:
                        return 5131;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5132;
                    case Properties::Waterlogged::FALSE:
                        return 5133;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5134;
                    case Properties::Waterlogged::FALSE:
                        return 5135;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5136;
                    case Properties::Waterlogged::FALSE:
                        return 5137;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5138;
                    case Properties::Waterlogged::FALSE:
                        return 5139;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5140;
                    case Properties::Waterlogged::FALSE:
                        return 5141;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5142;
                    case Properties::Waterlogged::FALSE:
                        return 5143;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5144;
                    case Properties::Waterlogged::FALSE:
                        return 5145;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5146;
                    case Properties::Waterlogged::FALSE:
                        return 5147;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5148;
                    case Properties::Waterlogged::FALSE:
                        return 5149;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5150;
                    case Properties::Waterlogged::FALSE:
                        return 5151;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5152;
                    case Properties::Waterlogged::FALSE:
                        return 5153;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5154;
                    case Properties::Waterlogged::FALSE:
                        return 5155;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5156;
                    case Properties::Waterlogged::FALSE:
                        return 5157;
                    }
                }
            case Properties::Attached::FALSE:
                switch (rotation) {
                case Properties::Rotation::ZERO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5158;
                    case Properties::Waterlogged::FALSE:
                        return 5159;
                    }
                case Properties::Rotation::ONE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5160;
                    case Properties::Waterlogged::FALSE:
                        return 5161;
                    }
                case Properties::Rotation::TWO:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5162;
                    case Properties::Waterlogged::FALSE:
                        return 5163;
                    }
                case Properties::Rotation::THREE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5164;
                    case Properties::Waterlogged::FALSE:
                        return 5165;
                    }
                case Properties::Rotation::FOUR:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5166;
                    case Properties::Waterlogged::FALSE:
                        return 5167;
                    }
                case Properties::Rotation::FIVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5168;
                    case Properties::Waterlogged::FALSE:
                        return 5169;
                    }
                case Properties::Rotation::SIX:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5170;
                    case Properties::Waterlogged::FALSE:
                        return 5171;
                    }
                case Properties::Rotation::SEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5172;
                    case Properties::Waterlogged::FALSE:
                        return 5173;
                    }
                case Properties::Rotation::EIGHT:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5174;
                    case Properties::Waterlogged::FALSE:
                        return 5175;
                    }
                case Properties::Rotation::NINE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5176;
                    case Properties::Waterlogged::FALSE:
                        return 5177;
                    }
                case Properties::Rotation::TEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5178;
                    case Properties::Waterlogged::FALSE:
                        return 5179;
                    }
                case Properties::Rotation::ELEVEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5180;
                    case Properties::Waterlogged::FALSE:
                        return 5181;
                    }
                case Properties::Rotation::TWELVE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5182;
                    case Properties::Waterlogged::FALSE:
                        return 5183;
                    }
                case Properties::Rotation::THIRTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5184;
                    case Properties::Waterlogged::FALSE:
                        return 5185;
                    }
                case Properties::Rotation::FOURTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5186;
                    case Properties::Waterlogged::FALSE:
                        return 5187;
                    }
                case Properties::Rotation::FIFTEEN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 5188;
                    case Properties::Waterlogged::FALSE:
                        return 5189;
                    }
                }
            }
            return 0;
        }
    }

}
