#include "BlueBed.hpp"
#include <stdexcept>

namespace Blocks {
namespace BlueBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1813;
            case Properties::Part::FOOT:
                return 1814;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1815;
            case Properties::Part::FOOT:
                return 1816;
            }
        }
    case Properties::Facing::SOUTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1817;
            case Properties::Part::FOOT:
                return 1818;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1819;
            case Properties::Part::FOOT:
                return 1820;
            }
        }
    case Properties::Facing::WEST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1821;
            case Properties::Part::FOOT:
                return 1822;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1823;
            case Properties::Part::FOOT:
                return 1824;
            }
        }
    case Properties::Facing::EAST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1825;
            case Properties::Part::FOOT:
                return 1826;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1827;
            case Properties::Part::FOOT:
                return 1828;
            }
        }
    }
    return 0;
}
}

}
