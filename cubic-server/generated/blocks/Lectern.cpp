#include "Lectern.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Lectern {
        BlockId toProtocol(Properties::Facing facing, Properties::Has_book has_book, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16038;
                    case Properties::Powered::FALSE:
                        return 16039;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16040;
                    case Properties::Powered::FALSE:
                        return 16041;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16042;
                    case Properties::Powered::FALSE:
                        return 16043;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16044;
                    case Properties::Powered::FALSE:
                        return 16045;
                    }
                }
            case Properties::Facing::WEST:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16046;
                    case Properties::Powered::FALSE:
                        return 16047;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16048;
                    case Properties::Powered::FALSE:
                        return 16049;
                    }
                }
            case Properties::Facing::EAST:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16050;
                    case Properties::Powered::FALSE:
                        return 16051;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 16052;
                    case Properties::Powered::FALSE:
                        return 16053;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Facing facing;
            Properties::Has_book has_book;
            Properties::Powered powered;
            for (auto prop : properties) {
                if (prop.first == "facing") {
                    if (prop.second == "north") {
                        facing = Properties::Facing::NORTH;
                    } else if (prop.second == "south") {
                        facing = Properties::Facing::SOUTH;
                    } else if (prop.second == "west") {
                        facing = Properties::Facing::WEST;
                    } else if (prop.second == "east") {
                        facing = Properties::Facing::EAST;
                    } else {
                        throw std::runtime_error("Invalid property \"facing\" value");
                    }
                } else if (prop.first == "has_book") {
                    if (prop.second == "true") {
                        has_book = Properties::Has_book::TRUE;
                    } else if (prop.second == "false") {
                        has_book = Properties::Has_book::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"has_book\" value");
                    }
                } else if (prop.first == "powered") {
                    if (prop.second == "true") {
                        powered = Properties::Powered::TRUE;
                    } else if (prop.second == "false") {
                        powered = Properties::Powered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"powered\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, has_book, powered);
        }
    }

}
