#include "OrangeBed.hpp"
#include <stdexcept>

namespace Blocks {
namespace OrangeBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1653;
            case Properties::Part::FOOT:
                return 1654;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1655;
            case Properties::Part::FOOT:
                return 1656;
            }
        }
    case Properties::Facing::SOUTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1657;
            case Properties::Part::FOOT:
                return 1658;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1659;
            case Properties::Part::FOOT:
                return 1660;
            }
        }
    case Properties::Facing::WEST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1661;
            case Properties::Part::FOOT:
                return 1662;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1663;
            case Properties::Part::FOOT:
                return 1664;
            }
        }
    case Properties::Facing::EAST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1665;
            case Properties::Part::FOOT:
                return 1666;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1667;
            case Properties::Part::FOOT:
                return 1668;
            }
        }
    }
    return 0;
}
}

}
