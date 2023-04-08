#include "OakButton.hpp"
#include <stdexcept>

namespace Blocks {
namespace OakButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8379;
            case Properties::Powered::FALSE:
                return 8380;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8381;
            case Properties::Powered::FALSE:
                return 8382;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8383;
            case Properties::Powered::FALSE:
                return 8384;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8385;
            case Properties::Powered::FALSE:
                return 8386;
            }
        }
    case Properties::Face::WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8387;
            case Properties::Powered::FALSE:
                return 8388;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8389;
            case Properties::Powered::FALSE:
                return 8390;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8391;
            case Properties::Powered::FALSE:
                return 8392;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8393;
            case Properties::Powered::FALSE:
                return 8394;
            }
        }
    case Properties::Face::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8395;
            case Properties::Powered::FALSE:
                return 8396;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8397;
            case Properties::Powered::FALSE:
                return 8398;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8399;
            case Properties::Powered::FALSE:
                return 8400;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8401;
            case Properties::Powered::FALSE:
                return 8402;
            }
        }
    }
    return 0;
}
}

}
