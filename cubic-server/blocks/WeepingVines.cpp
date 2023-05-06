#include "WeepingVines.hpp"
namespace Blocks {
    namespace WeepingVines {
        BlockId toProtocol(Properties::Age age) {
            switch (age) {
            case Properties::Age::ZERO:
                return 17983;
            case Properties::Age::ONE:
                return 17984;
            case Properties::Age::TWO:
                return 17985;
            case Properties::Age::THREE:
                return 17986;
            case Properties::Age::FOUR:
                return 17987;
            case Properties::Age::FIVE:
                return 17988;
            case Properties::Age::SIX:
                return 17989;
            case Properties::Age::SEVEN:
                return 17990;
            case Properties::Age::EIGHT:
                return 17991;
            case Properties::Age::NINE:
                return 17992;
            case Properties::Age::TEN:
                return 17993;
            case Properties::Age::ELEVEN:
                return 17994;
            case Properties::Age::TWELVE:
                return 17995;
            case Properties::Age::THIRTEEN:
                return 17996;
            case Properties::Age::FOURTEEN:
                return 17997;
            case Properties::Age::FIFTEEN:
                return 17998;
            case Properties::Age::SIXTEEN:
                return 17999;
            case Properties::Age::SEVENTEEN:
                return 18000;
            case Properties::Age::EIGHTEEN:
                return 18001;
            case Properties::Age::NINETEEN:
                return 18002;
            case Properties::Age::TWENTY:
                return 18003;
            case Properties::Age::TWENTY_ONE:
                return 18004;
            case Properties::Age::TWENTY_TWO:
                return 18005;
            case Properties::Age::TWENTY_THREE:
                return 18006;
            case Properties::Age::TWENTY_FOUR:
                return 18007;
            case Properties::Age::TWENTY_FIVE:
                return 18008;
            default:
                return 0;
            }
            return 0;
        }
    }

}
