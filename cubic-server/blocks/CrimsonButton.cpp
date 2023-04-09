#include "CrimsonButton.hpp"
#include <stdexcept>

namespace Blocks {
namespace CrimsonButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18472;
            case Properties::Powered::FALSE:
                return 18473;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18474;
            case Properties::Powered::FALSE:
                return 18475;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18476;
            case Properties::Powered::FALSE:
                return 18477;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18478;
            case Properties::Powered::FALSE:
                return 18479;
            }
        }
    case Properties::Face::WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18480;
            case Properties::Powered::FALSE:
                return 18481;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18482;
            case Properties::Powered::FALSE:
                return 18483;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18484;
            case Properties::Powered::FALSE:
                return 18485;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18486;
            case Properties::Powered::FALSE:
                return 18487;
            }
        }
    case Properties::Face::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18488;
            case Properties::Powered::FALSE:
                return 18489;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18490;
            case Properties::Powered::FALSE:
                return 18491;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18492;
            case Properties::Powered::FALSE:
                return 18493;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18494;
            case Properties::Powered::FALSE:
                return 18495;
            }
        }
    }
    return 0;
}
}

}
