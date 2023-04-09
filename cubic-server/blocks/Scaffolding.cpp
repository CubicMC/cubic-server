#include "Scaffolding.hpp"
#include <stdexcept>

namespace Blocks {
namespace Scaffolding {
BlockId toProtocol(Properties::Bottom bottom, Properties::Distance distance, Properties::Waterlogged waterlogged)
{
    switch (bottom) {
    case Properties::Bottom::TRUE:
        switch (distance) {
        case Properties::Distance::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17744;
            case Properties::Waterlogged::FALSE:
                return 17745;
            }
        case Properties::Distance::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17746;
            case Properties::Waterlogged::FALSE:
                return 17747;
            }
        case Properties::Distance::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17748;
            case Properties::Waterlogged::FALSE:
                return 17749;
            }
        case Properties::Distance::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17750;
            case Properties::Waterlogged::FALSE:
                return 17751;
            }
        case Properties::Distance::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17752;
            case Properties::Waterlogged::FALSE:
                return 17753;
            }
        case Properties::Distance::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17754;
            case Properties::Waterlogged::FALSE:
                return 17755;
            }
        case Properties::Distance::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17756;
            case Properties::Waterlogged::FALSE:
                return 17757;
            }
        case Properties::Distance::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17758;
            case Properties::Waterlogged::FALSE:
                return 17759;
            }
        }
    case Properties::Bottom::FALSE:
        switch (distance) {
        case Properties::Distance::ZERO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17760;
            case Properties::Waterlogged::FALSE:
                return 17761;
            }
        case Properties::Distance::ONE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17762;
            case Properties::Waterlogged::FALSE:
                return 17763;
            }
        case Properties::Distance::TWO:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17764;
            case Properties::Waterlogged::FALSE:
                return 17765;
            }
        case Properties::Distance::THREE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17766;
            case Properties::Waterlogged::FALSE:
                return 17767;
            }
        case Properties::Distance::FOUR:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17768;
            case Properties::Waterlogged::FALSE:
                return 17769;
            }
        case Properties::Distance::FIVE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17770;
            case Properties::Waterlogged::FALSE:
                return 17771;
            }
        case Properties::Distance::SIX:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17772;
            case Properties::Waterlogged::FALSE:
                return 17773;
            }
        case Properties::Distance::SEVEN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 17774;
            case Properties::Waterlogged::FALSE:
                return 17775;
            }
        }
    }
    return 0;
}
}

}
