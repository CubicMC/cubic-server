#include "LightGrayBed.hpp"
#include <stdexcept>

namespace Blocks {
namespace LightGrayBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1765;
            case Properties::Part::FOOT:
                return 1766;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1767;
            case Properties::Part::FOOT:
                return 1768;
            }
        }
    case Properties::Facing::SOUTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1769;
            case Properties::Part::FOOT:
                return 1770;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1771;
            case Properties::Part::FOOT:
                return 1772;
            }
        }
    case Properties::Facing::WEST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1773;
            case Properties::Part::FOOT:
                return 1774;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1775;
            case Properties::Part::FOOT:
                return 1776;
            }
        }
    case Properties::Facing::EAST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1777;
            case Properties::Part::FOOT:
                return 1778;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1779;
            case Properties::Part::FOOT:
                return 1780;
            }
        }
    }
    return 0;
}
}

}
