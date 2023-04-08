#include "BrownBed.hpp"
#include <stdexcept>

namespace Blocks {
namespace BrownBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1829;
            case Properties::Part::FOOT:
                return 1830;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1831;
            case Properties::Part::FOOT:
                return 1832;
            }
        }
    case Properties::Facing::SOUTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1833;
            case Properties::Part::FOOT:
                return 1834;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1835;
            case Properties::Part::FOOT:
                return 1836;
            }
        }
    case Properties::Facing::WEST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1837;
            case Properties::Part::FOOT:
                return 1838;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1839;
            case Properties::Part::FOOT:
                return 1840;
            }
        }
    case Properties::Facing::EAST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1841;
            case Properties::Part::FOOT:
                return 1842;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1843;
            case Properties::Part::FOOT:
                return 1844;
            }
        }
    }
    return 0;
}
}

}
