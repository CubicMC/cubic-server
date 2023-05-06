#include "TwistingVines.hpp"
namespace Blocks {
namespace TwistingVines {
BlockId toProtocol(Properties::Age age)
{
    switch (age) {
    case Properties::Age::ZERO:
        return 18010;
    case Properties::Age::ONE:
        return 18011;
    case Properties::Age::TWO:
        return 18012;
    case Properties::Age::THREE:
        return 18013;
    case Properties::Age::FOUR:
        return 18014;
    case Properties::Age::FIVE:
        return 18015;
    case Properties::Age::SIX:
        return 18016;
    case Properties::Age::SEVEN:
        return 18017;
    case Properties::Age::EIGHT:
        return 18018;
    case Properties::Age::NINE:
        return 18019;
    case Properties::Age::TEN:
        return 18020;
    case Properties::Age::ELEVEN:
        return 18021;
    case Properties::Age::TWELVE:
        return 18022;
    case Properties::Age::THIRTEEN:
        return 18023;
    case Properties::Age::FOURTEEN:
        return 18024;
    case Properties::Age::FIFTEEN:
        return 18025;
    case Properties::Age::SIXTEEN:
        return 18026;
    case Properties::Age::SEVENTEEN:
        return 18027;
    case Properties::Age::EIGHTEEN:
        return 18028;
    case Properties::Age::NINETEEN:
        return 18029;
    case Properties::Age::TWENTY:
        return 18030;
    case Properties::Age::TWENTY_ONE:
        return 18031;
    case Properties::Age::TWENTY_TWO:
        return 18032;
    case Properties::Age::TWENTY_THREE:
        return 18033;
    case Properties::Age::TWENTY_FOUR:
        return 18034;
    case Properties::Age::TWENTY_FIVE:
        return 18035;
    default:
        return 0;
    }
    return 0;
}
}

}
