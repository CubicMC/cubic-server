#include "DarkOakButton.hpp"
#include <stdexcept>

namespace Blocks {
namespace DarkOakButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8499;
            case Properties::Powered::FALSE:
                return 8500;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8501;
            case Properties::Powered::FALSE:
                return 8502;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8503;
            case Properties::Powered::FALSE:
                return 8504;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8505;
            case Properties::Powered::FALSE:
                return 8506;
            }
        }
    case Properties::Face::WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8507;
            case Properties::Powered::FALSE:
                return 8508;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8509;
            case Properties::Powered::FALSE:
                return 8510;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8511;
            case Properties::Powered::FALSE:
                return 8512;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8513;
            case Properties::Powered::FALSE:
                return 8514;
            }
        }
    case Properties::Face::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8515;
            case Properties::Powered::FALSE:
                return 8516;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8517;
            case Properties::Powered::FALSE:
                return 8518;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8519;
            case Properties::Powered::FALSE:
                return 8520;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8521;
            case Properties::Powered::FALSE:
                return 8522;
            }
        }
    }
    return 0;
}
}

}
