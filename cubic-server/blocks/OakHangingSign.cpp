#include "OakHangingSign.hpp"
namespace Blocks {
namespace OakHangingSign {
BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged)
{
    switch (attached) {
    case Properties::Attached::TRUE:
        switch (rotation) {
        case Properties::Rotation::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4742;
            case Properties::Waterlogged::FALSE:
                return 4743;
            default:
                return 0;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4744;
            case Properties::Waterlogged::FALSE:
                return 4745;
            default:
                return 0;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4746;
            case Properties::Waterlogged::FALSE:
                return 4747;
            default:
                return 0;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4748;
            case Properties::Waterlogged::FALSE:
                return 4749;
            default:
                return 0;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4750;
            case Properties::Waterlogged::FALSE:
                return 4751;
            default:
                return 0;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4752;
            case Properties::Waterlogged::FALSE:
                return 4753;
            default:
                return 0;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4754;
            case Properties::Waterlogged::FALSE:
                return 4755;
            default:
                return 0;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4756;
            case Properties::Waterlogged::FALSE:
                return 4757;
            default:
                return 0;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4758;
            case Properties::Waterlogged::FALSE:
                return 4759;
            default:
                return 0;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4760;
            case Properties::Waterlogged::FALSE:
                return 4761;
            default:
                return 0;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4762;
            case Properties::Waterlogged::FALSE:
                return 4763;
            default:
                return 0;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4764;
            case Properties::Waterlogged::FALSE:
                return 4765;
            default:
                return 0;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4766;
            case Properties::Waterlogged::FALSE:
                return 4767;
            default:
                return 0;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4768;
            case Properties::Waterlogged::FALSE:
                return 4769;
            default:
                return 0;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4770;
            case Properties::Waterlogged::FALSE:
                return 4771;
            default:
                return 0;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4772;
            case Properties::Waterlogged::FALSE:
                return 4773;
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
                return 4774;
            case Properties::Waterlogged::FALSE:
                return 4775;
            default:
                return 0;
            }
        case Properties::Rotation::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4776;
            case Properties::Waterlogged::FALSE:
                return 4777;
            default:
                return 0;
            }
        case Properties::Rotation::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4778;
            case Properties::Waterlogged::FALSE:
                return 4779;
            default:
                return 0;
            }
        case Properties::Rotation::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4780;
            case Properties::Waterlogged::FALSE:
                return 4781;
            default:
                return 0;
            }
        case Properties::Rotation::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4782;
            case Properties::Waterlogged::FALSE:
                return 4783;
            default:
                return 0;
            }
        case Properties::Rotation::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4784;
            case Properties::Waterlogged::FALSE:
                return 4785;
            default:
                return 0;
            }
        case Properties::Rotation::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4786;
            case Properties::Waterlogged::FALSE:
                return 4787;
            default:
                return 0;
            }
        case Properties::Rotation::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4788;
            case Properties::Waterlogged::FALSE:
                return 4789;
            default:
                return 0;
            }
        case Properties::Rotation::EIGHT:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4790;
            case Properties::Waterlogged::FALSE:
                return 4791;
            default:
                return 0;
            }
        case Properties::Rotation::NINE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4792;
            case Properties::Waterlogged::FALSE:
                return 4793;
            default:
                return 0;
            }
        case Properties::Rotation::TEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4794;
            case Properties::Waterlogged::FALSE:
                return 4795;
            default:
                return 0;
            }
        case Properties::Rotation::ELEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4796;
            case Properties::Waterlogged::FALSE:
                return 4797;
            default:
                return 0;
            }
        case Properties::Rotation::TWELVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4798;
            case Properties::Waterlogged::FALSE:
                return 4799;
            default:
                return 0;
            }
        case Properties::Rotation::THIRTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4800;
            case Properties::Waterlogged::FALSE:
                return 4801;
            default:
                return 0;
            }
        case Properties::Rotation::FOURTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4802;
            case Properties::Waterlogged::FALSE:
                return 4803;
            default:
                return 0;
            }
        case Properties::Rotation::FIFTEEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 4804;
            case Properties::Waterlogged::FALSE:
                return 4805;
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
