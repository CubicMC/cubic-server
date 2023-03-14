#include "PolishedBlackstoneButton.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedBlackstoneButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19746;
                    case Properties::Powered::FALSE:
                        return 19747;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19748;
                    case Properties::Powered::FALSE:
                        return 19749;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19750;
                    case Properties::Powered::FALSE:
                        return 19751;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19752;
                    case Properties::Powered::FALSE:
                        return 19753;
                    }
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19754;
                    case Properties::Powered::FALSE:
                        return 19755;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19756;
                    case Properties::Powered::FALSE:
                        return 19757;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19758;
                    case Properties::Powered::FALSE:
                        return 19759;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19760;
                    case Properties::Powered::FALSE:
                        return 19761;
                    }
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19762;
                    case Properties::Powered::FALSE:
                        return 19763;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19764;
                    case Properties::Powered::FALSE:
                        return 19765;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19766;
                    case Properties::Powered::FALSE:
                        return 19767;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 19768;
                    case Properties::Powered::FALSE:
                        return 19769;
                    }
                }
            }
            return 0;
        }
    }

}
