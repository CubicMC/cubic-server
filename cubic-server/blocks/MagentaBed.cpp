#include "MagentaBed.hpp"
#include <stdexcept>

namespace Blocks {
namespace MagentaBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1669;
            case Properties::Part::FOOT:
                return 1670;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1671;
            case Properties::Part::FOOT:
                return 1672;
            }
        }
    case Properties::Facing::SOUTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1673;
            case Properties::Part::FOOT:
                return 1674;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1675;
            case Properties::Part::FOOT:
                return 1676;
            }
        }
    case Properties::Facing::WEST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1677;
            case Properties::Part::FOOT:
                return 1678;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1679;
            case Properties::Part::FOOT:
                return 1680;
            }
        }
    case Properties::Facing::EAST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1681;
            case Properties::Part::FOOT:
                return 1682;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1683;
            case Properties::Part::FOOT:
                return 1684;
            }
        }
    }
    return 0;
}
}

}
