#include "Farmland.hpp"
namespace Blocks {
    namespace Farmland {
        BlockId toProtocol(Properties::Moisture moisture) {
            switch (moisture) {
            case Properties::Moisture::ZERO:
                return 4234;
            case Properties::Moisture::ONE:
                return 4235;
            case Properties::Moisture::TWO:
                return 4236;
            case Properties::Moisture::THREE:
                return 4237;
            case Properties::Moisture::FOUR:
                return 4238;
            case Properties::Moisture::FIVE:
                return 4239;
            case Properties::Moisture::SIX:
                return 4240;
            case Properties::Moisture::SEVEN:
                return 4241;
            }
            return 0;
        }
    }

}
