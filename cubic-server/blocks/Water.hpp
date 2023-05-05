#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace Water {
        namespace Properties {
            enum class Level {
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
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Level level);
    }

}
