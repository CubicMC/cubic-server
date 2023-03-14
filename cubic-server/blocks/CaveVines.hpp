#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace CaveVines {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN,
                SIXTEEN,
                SEVENTEEN,
                EIGHTEEN,
                NINETEEN,
                TWENTY,
                TWENTY_ONE,
                TWENTY_TWO,
                TWENTY_THREE,
                TWENTY_FOUR,
                TWENTY_FIVE
            };
            enum class Berries {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Berries berries);
    }

}
