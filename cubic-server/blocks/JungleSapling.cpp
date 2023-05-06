#include "JungleSapling.hpp"
namespace Blocks {
    namespace JungleSapling {
        BlockId toProtocol(Properties::Stage stage) {
            switch (stage) {
            case Properties::Stage::ZERO:
                return 30;
            case Properties::Stage::ONE:
                return 31;
            default:
                return 0;
            }
            return 0;
        }
    }

}
