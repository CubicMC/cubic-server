#include "SpruceHangingSign.hpp"
namespace Blocks {
namespace SpruceHangingSign {
BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged)
{
    switch (attached) {
    case Properties::Attached::TRUE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4806;
            case Properties::Waterlogged::FALSE:
                return 4807;
            default:
                return 0;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4808;
            case Properties::Waterlogged::FALSE:
                return 4809;
            default:
                return 0;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4810;
            case Properties::Waterlogged::FALSE:
                return 4811;
            default:
                return 0;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4812;
            case Properties::Waterlogged::FALSE:
                return 4813;
            default:
                return 0;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4814;
            case Properties::Waterlogged::FALSE:
                return 4815;
            default:
                return 0;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4816;
            case Properties::Waterlogged::FALSE:
                return 4817;
            default:
                return 0;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4818;
            case Properties::Waterlogged::FALSE:
                return 4819;
            default:
                return 0;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4820;
            case Properties::Waterlogged::FALSE:
                return 4821;
            default:
                return 0;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4822;
            case Properties::Waterlogged::FALSE:
                return 4823;
            default:
                return 0;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4824;
            case Properties::Waterlogged::FALSE:
                return 4825;
            default:
                return 0;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4826;
            case Properties::Waterlogged::FALSE:
                return 4827;
            default:
                return 0;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4828;
            case Properties::Waterlogged::FALSE:
                return 4829;
            default:
                return 0;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4830;
            case Properties::Waterlogged::FALSE:
                return 4831;
            default:
                return 0;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4832;
            case Properties::Waterlogged::FALSE:
                return 4833;
            default:
                return 0;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4834;
            case Properties::Waterlogged::FALSE:
                return 4835;
            default:
                return 0;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4836;
            case Properties::Waterlogged::FALSE:
                return 4837;
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
                return 4838;
            case Properties::Waterlogged::FALSE:
                return 4839;
            default:
                return 0;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4840;
            case Properties::Waterlogged::FALSE:
                return 4841;
            default:
                return 0;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4842;
            case Properties::Waterlogged::FALSE:
                return 4843;
            default:
                return 0;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4844;
            case Properties::Waterlogged::FALSE:
                return 4845;
            default:
                return 0;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4846;
            case Properties::Waterlogged::FALSE:
                return 4847;
            default:
                return 0;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4848;
            case Properties::Waterlogged::FALSE:
                return 4849;
            default:
                return 0;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4850;
            case Properties::Waterlogged::FALSE:
                return 4851;
            default:
                return 0;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4852;
            case Properties::Waterlogged::FALSE:
                return 4853;
            default:
                return 0;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4854;
            case Properties::Waterlogged::FALSE:
                return 4855;
            default:
                return 0;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4856;
            case Properties::Waterlogged::FALSE:
                return 4857;
            default:
                return 0;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4858;
            case Properties::Waterlogged::FALSE:
                return 4859;
            default:
                return 0;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4860;
            case Properties::Waterlogged::FALSE:
                return 4861;
            default:
                return 0;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4862;
            case Properties::Waterlogged::FALSE:
                return 4863;
            default:
                return 0;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4864;
            case Properties::Waterlogged::FALSE:
                return 4865;
            default:
                return 0;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4866;
            case Properties::Waterlogged::FALSE:
                return 4867;
            default:
                return 0;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4868;
            case Properties::Waterlogged::FALSE:
                return 4869;
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
