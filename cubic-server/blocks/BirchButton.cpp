#include "BirchButton.hpp"
#include <stdexcept>

namespace Blocks {
namespace BirchButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8427;
            case Properties::Powered::FALSE:
                return 8428;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8429;
            case Properties::Powered::FALSE:
                return 8430;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8431;
            case Properties::Powered::FALSE:
                return 8432;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8433;
            case Properties::Powered::FALSE:
                return 8434;
            }
        }
    case Properties::Face::WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8435;
            case Properties::Powered::FALSE:
                return 8436;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8437;
            case Properties::Powered::FALSE:
                return 8438;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8439;
            case Properties::Powered::FALSE:
                return 8440;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8441;
            case Properties::Powered::FALSE:
                return 8442;
            }
        }
    case Properties::Face::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8443;
            case Properties::Powered::FALSE:
                return 8444;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8445;
            case Properties::Powered::FALSE:
                return 8446;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8447;
            case Properties::Powered::FALSE:
                return 8448;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8449;
            case Properties::Powered::FALSE:
                return 8450;
            }
        }
    }
    return 0;
}
}

}
