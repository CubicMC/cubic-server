#include "Bell.hpp"
#include <stdexcept>

namespace Blocks {
namespace Bell {
BlockId toProtocol(Properties::Attachment attachment, Properties::Facing facing, Properties::Powered powered)
{
    switch (attachment) {
    case Properties::Attachment::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17843;
            case Properties::Powered::FALSE:
                return 17844;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17845;
            case Properties::Powered::FALSE:
                return 17846;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17847;
            case Properties::Powered::FALSE:
                return 17848;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17849;
            case Properties::Powered::FALSE:
                return 17850;
            }
        }
    case Properties::Attachment::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17851;
            case Properties::Powered::FALSE:
                return 17852;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17853;
            case Properties::Powered::FALSE:
                return 17854;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17855;
            case Properties::Powered::FALSE:
                return 17856;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17857;
            case Properties::Powered::FALSE:
                return 17858;
            }
        }
    case Properties::Attachment::SINGLE_WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17859;
            case Properties::Powered::FALSE:
                return 17860;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17861;
            case Properties::Powered::FALSE:
                return 17862;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17863;
            case Properties::Powered::FALSE:
                return 17864;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17865;
            case Properties::Powered::FALSE:
                return 17866;
            }
        }
    case Properties::Attachment::DOUBLE_WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17867;
            case Properties::Powered::FALSE:
                return 17868;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17869;
            case Properties::Powered::FALSE:
                return 17870;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17871;
            case Properties::Powered::FALSE:
                return 17872;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 17873;
            case Properties::Powered::FALSE:
                return 17874;
            }
        }
    }
    return 0;
}
}

}
