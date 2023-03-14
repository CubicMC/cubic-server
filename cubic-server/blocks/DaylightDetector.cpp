#include "DaylightDetector.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DaylightDetector {
        BlockId toProtocol(Properties::Inverted inverted, Properties::Power power) {
            switch (inverted) {
            case Properties::Inverted::TRUE:
                switch (power) {
                case Properties::Power::ZERO:
                    return 8795;
                case Properties::Power::ONE:
                    return 8796;
                case Properties::Power::TWO:
                    return 8797;
                case Properties::Power::THREE:
                    return 8798;
                case Properties::Power::FOUR:
                    return 8799;
                case Properties::Power::FIVE:
                    return 8800;
                case Properties::Power::SIX:
                    return 8801;
                case Properties::Power::SEVEN:
                    return 8802;
                case Properties::Power::EIGHT:
                    return 8803;
                case Properties::Power::NINE:
                    return 8804;
                case Properties::Power::TEN:
                    return 8805;
                case Properties::Power::ELEVEN:
                    return 8806;
                case Properties::Power::TWELVE:
                    return 8807;
                case Properties::Power::THIRTEEN:
                    return 8808;
                case Properties::Power::FOURTEEN:
                    return 8809;
                case Properties::Power::FIFTEEN:
                    return 8810;
                }
            case Properties::Inverted::FALSE:
                switch (power) {
                case Properties::Power::ZERO:
                    return 8811;
                case Properties::Power::ONE:
                    return 8812;
                case Properties::Power::TWO:
                    return 8813;
                case Properties::Power::THREE:
                    return 8814;
                case Properties::Power::FOUR:
                    return 8815;
                case Properties::Power::FIVE:
                    return 8816;
                case Properties::Power::SIX:
                    return 8817;
                case Properties::Power::SEVEN:
                    return 8818;
                case Properties::Power::EIGHT:
                    return 8819;
                case Properties::Power::NINE:
                    return 8820;
                case Properties::Power::TEN:
                    return 8821;
                case Properties::Power::ELEVEN:
                    return 8822;
                case Properties::Power::TWELVE:
                    return 8823;
                case Properties::Power::THIRTEEN:
                    return 8824;
                case Properties::Power::FOURTEEN:
                    return 8825;
                case Properties::Power::FIFTEEN:
                    return 8826;
                }
            }
            return 0;
        }
    }

}
