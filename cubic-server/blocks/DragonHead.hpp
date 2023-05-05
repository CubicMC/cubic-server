#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace DragonHead {
        namespace Properties {
            enum class Rotation {
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
        BlockId toProtocol(Properties::Rotation rotation);
    }

}
