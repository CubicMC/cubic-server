#include "DarkOakSapling.hpp"
namespace Blocks {
    namespace DarkOakSapling {
        BlockId toProtocol(Properties::Stage stage) {
            switch (stage) {
            case Properties::Stage::ZERO:
                return 34;
            case Properties::Stage::ONE:
                return 35;
            }
            return 0;
        }
    }

}
