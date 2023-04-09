#include "Bamboo.hpp"
#include <stdexcept>

namespace Blocks {
namespace Bamboo {
BlockId toProtocol(Properties::Age age, Properties::Leaves leaves, Properties::Stage stage)
{
    switch (age) {
    case Properties::Age::ZERO:
        switch (leaves) {
        case Properties::Leaves::NONE:
            switch (stage) {
            case Properties::Stage::ZERO:
                return 12317;
            case Properties::Stage::ONE:
                return 12318;
            }
        case Properties::Leaves::SMALL:
            switch (stage) {
            case Properties::Stage::ZERO:
                return 12319;
            case Properties::Stage::ONE:
                return 12320;
            }
        case Properties::Leaves::LARGE:
            switch (stage) {
            case Properties::Stage::ZERO:
                return 12321;
            case Properties::Stage::ONE:
                return 12322;
            }
        }
    case Properties::Age::ONE:
        switch (leaves) {
        case Properties::Leaves::NONE:
            switch (stage) {
            case Properties::Stage::ZERO:
                return 12323;
            case Properties::Stage::ONE:
                return 12324;
            }
        case Properties::Leaves::SMALL:
            switch (stage) {
            case Properties::Stage::ZERO:
                return 12325;
            case Properties::Stage::ONE:
                return 12326;
            }
        case Properties::Leaves::LARGE:
            switch (stage) {
            case Properties::Stage::ZERO:
                return 12327;
            case Properties::Stage::ONE:
                return 12328;
            }
        }
    }
    return 0;
}
}

}
