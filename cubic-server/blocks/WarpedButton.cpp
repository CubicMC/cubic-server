#include "WarpedButton.hpp"
#include <stdexcept>

namespace Blocks {
namespace WarpedButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18496;
            case Properties::Powered::FALSE:
                return 18497;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18498;
            case Properties::Powered::FALSE:
                return 18499;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18500;
            case Properties::Powered::FALSE:
                return 18501;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18502;
            case Properties::Powered::FALSE:
                return 18503;
            }
        }
    case Properties::Face::WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18504;
            case Properties::Powered::FALSE:
                return 18505;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18506;
            case Properties::Powered::FALSE:
                return 18507;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18508;
            case Properties::Powered::FALSE:
                return 18509;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18510;
            case Properties::Powered::FALSE:
                return 18511;
            }
        }
    case Properties::Face::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18512;
            case Properties::Powered::FALSE:
                return 18513;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18514;
            case Properties::Powered::FALSE:
                return 18515;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18516;
            case Properties::Powered::FALSE:
                return 18517;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18518;
            case Properties::Powered::FALSE:
                return 18519;
            }
        }
    }
    return 0;
}
}

}
