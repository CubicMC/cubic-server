#include "SpruceButton.hpp"
namespace Blocks {
    namespace SpruceButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8403;
                    case Properties::Powered::FALSE:
                        return 8404;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8405;
                    case Properties::Powered::FALSE:
                        return 8406;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8407;
                    case Properties::Powered::FALSE:
                        return 8408;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8409;
                    case Properties::Powered::FALSE:
                        return 8410;
                    }
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8411;
                    case Properties::Powered::FALSE:
                        return 8412;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8413;
                    case Properties::Powered::FALSE:
                        return 8414;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8415;
                    case Properties::Powered::FALSE:
                        return 8416;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8417;
                    case Properties::Powered::FALSE:
                        return 8418;
                    }
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8419;
                    case Properties::Powered::FALSE:
                        return 8420;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8421;
                    case Properties::Powered::FALSE:
                        return 8422;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8423;
                    case Properties::Powered::FALSE:
                        return 8424;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8425;
                    case Properties::Powered::FALSE:
                        return 8426;
                    }
                }
            }
            return 0;
        }
    }

}
