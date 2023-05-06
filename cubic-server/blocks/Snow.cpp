#include "Snow.hpp"
namespace Blocks {
    namespace Snow {
        BlockId toProtocol(Properties::Layers layers) {
            switch (layers) {
            case Properties::Layers::ONE:
                return 5606;
            case Properties::Layers::TWO:
                return 5607;
            case Properties::Layers::THREE:
                return 5608;
            case Properties::Layers::FOUR:
                return 5609;
            case Properties::Layers::FIVE:
                return 5610;
            case Properties::Layers::SIX:
                return 5611;
            case Properties::Layers::SEVEN:
                return 5612;
            case Properties::Layers::EIGHT:
                return 5613;
            default:
                return 0;
            }
            return 0;
        }
    }

}
