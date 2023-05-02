#include "SculkShrieker.hpp"
#include <stdexcept>

namespace Blocks {
namespace SculkShrieker {
BlockId toProtocol(Properties::Can_summon can_summon, Properties::Shrieking shrieking, Properties::Waterlogged waterlogged)
{
    switch (can_summon) {
    case Properties::Can_summon::TRUE:
        switch (shrieking) {
        case Properties::Shrieking::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20684;
            case Properties::Waterlogged::FALSE:
                return 20685;
            }
        case Properties::Shrieking::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20686;
            case Properties::Waterlogged::FALSE:
                return 20687;
            }
        }
    case Properties::Can_summon::FALSE:
        switch (shrieking) {
        case Properties::Shrieking::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20688;
            case Properties::Waterlogged::FALSE:
                return 20689;
            }
        case Properties::Shrieking::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20690;
            case Properties::Waterlogged::FALSE:
                return 20691;
            }
        }
    }
    return 0;
}
}

}
