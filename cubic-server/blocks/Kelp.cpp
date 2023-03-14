#include "Kelp.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Kelp {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 12135;
            case Properties::Age::ONE:
                return 12136;
            case Properties::Age::TWO:
                return 12137;
            case Properties::Age::THREE:
                return 12138;
            case Properties::Age::FOUR:
                return 12139;
            case Properties::Age::FIVE:
                return 12140;
            case Properties::Age::SIX:
                return 12141;
            case Properties::Age::SEVEN:
                return 12142;
            case Properties::Age::EIGHT:
                return 12143;
            case Properties::Age::NINE:
                return 12144;
            case Properties::Age::TEN:
                return 12145;
            case Properties::Age::ELEVEN:
                return 12146;
            case Properties::Age::TWELVE:
                return 12147;
            case Properties::Age::THIRTEEN:
                return 12148;
            case Properties::Age::FOURTEEN:
                return 12149;
            case Properties::Age::FIFTEEN:
                return 12150;
            case Properties::Age::SIXTEEN:
                return 12151;
            case Properties::Age::SEVENTEEN:
                return 12152;
            case Properties::Age::EIGHTEEN:
                return 12153;
            case Properties::Age::NINETEEN:
                return 12154;
            case Properties::Age::TWENTY:
                return 12155;
            case Properties::Age::TWENTY_ONE:
                return 12156;
            case Properties::Age::TWENTY_TWO:
                return 12157;
            case Properties::Age::TWENTY_THREE:
                return 12158;
            case Properties::Age::TWENTY_FOUR:
                return 12159;
            case Properties::Age::TWENTY_FIVE:
                return 12160;
            }
            return 0;
        }
    }

}
