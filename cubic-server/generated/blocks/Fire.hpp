#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Fire {
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
                FIFTEEN
            };
            enum class East {
                TRUE,
                FALSE
            };
            enum class North {
                TRUE,
                FALSE
            };
            enum class South {
                TRUE,
                FALSE
            };
            enum class Up {
                TRUE,
                FALSE
            };
            enum class West {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
