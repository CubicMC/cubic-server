#include "Observer.hpp"
#include <stdexcept>

namespace Blocks {
namespace Observer {
BlockId toProtocol(Properties::Facing facing, Properties::Powered powered)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (powered) {
        case Properties::Powered::TRUE:
            return 11925;
        case Properties::Powered::FALSE:
            return 11926;
        }
    case Properties::Facing::EAST:
        switch (powered) {
        case Properties::Powered::TRUE:
            return 11927;
        case Properties::Powered::FALSE:
            return 11928;
        }
    case Properties::Facing::SOUTH:
        switch (powered) {
        case Properties::Powered::TRUE:
            return 11929;
        case Properties::Powered::FALSE:
            return 11930;
        }
    case Properties::Facing::WEST:
        switch (powered) {
        case Properties::Powered::TRUE:
            return 11931;
        case Properties::Powered::FALSE:
            return 11932;
        }
    case Properties::Facing::UP:
        switch (powered) {
        case Properties::Powered::TRUE:
            return 11933;
        case Properties::Powered::FALSE:
            return 11934;
        }
    case Properties::Facing::DOWN:
        switch (powered) {
        case Properties::Powered::TRUE:
            return 11935;
        case Properties::Powered::FALSE:
            return 11936;
        }
    }
    return 0;
}
}

}
