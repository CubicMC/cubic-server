#include "PointedDripstone.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PointedDripstone {
        BlockId toProtocol(Properties::Thickness thickness, Properties::Vertical_direction vertical_direction, Properties::Waterlogged waterlogged) {
            switch (thickness) {
            case Properties::Thickness::TIP_MERGE:
                switch (vertical_direction) {
                case Properties::Vertical_direction::UP:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19638;
                    case Properties::Waterlogged::FALSE:
                        return 19639;
                    }
                case Properties::Vertical_direction::DOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19640;
                    case Properties::Waterlogged::FALSE:
                        return 19641;
                    }
                }
            case Properties::Thickness::TIP:
                switch (vertical_direction) {
                case Properties::Vertical_direction::UP:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19642;
                    case Properties::Waterlogged::FALSE:
                        return 19643;
                    }
                case Properties::Vertical_direction::DOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19644;
                    case Properties::Waterlogged::FALSE:
                        return 19645;
                    }
                }
            case Properties::Thickness::FRUSTUM:
                switch (vertical_direction) {
                case Properties::Vertical_direction::UP:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19646;
                    case Properties::Waterlogged::FALSE:
                        return 19647;
                    }
                case Properties::Vertical_direction::DOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19648;
                    case Properties::Waterlogged::FALSE:
                        return 19649;
                    }
                }
            case Properties::Thickness::MIDDLE:
                switch (vertical_direction) {
                case Properties::Vertical_direction::UP:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19650;
                    case Properties::Waterlogged::FALSE:
                        return 19651;
                    }
                case Properties::Vertical_direction::DOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19652;
                    case Properties::Waterlogged::FALSE:
                        return 19653;
                    }
                }
            case Properties::Thickness::BASE:
                switch (vertical_direction) {
                case Properties::Vertical_direction::UP:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19654;
                    case Properties::Waterlogged::FALSE:
                        return 19655;
                    }
                case Properties::Vertical_direction::DOWN:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 19656;
                    case Properties::Waterlogged::FALSE:
                        return 19657;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Thickness thickness;
            Properties::Vertical_direction vertical_direction;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "thickness") {
                    if (prop.second == "tip_merge") {
                        thickness = Properties::Thickness::TIP_MERGE;
                    } else if (prop.second == "tip") {
                        thickness = Properties::Thickness::TIP;
                    } else if (prop.second == "frustum") {
                        thickness = Properties::Thickness::FRUSTUM;
                    } else if (prop.second == "middle") {
                        thickness = Properties::Thickness::MIDDLE;
                    } else if (prop.second == "base") {
                        thickness = Properties::Thickness::BASE;
                    } else {
                        throw std::runtime_error("Invalid property \"thickness\" value");
                    }
                } else if (prop.first == "vertical_direction") {
                    if (prop.second == "up") {
                        vertical_direction = Properties::Vertical_direction::UP;
                    } else if (prop.second == "down") {
                        vertical_direction = Properties::Vertical_direction::DOWN;
                    } else {
                        throw std::runtime_error("Invalid property \"vertical_direction\" value");
                    }
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(thickness, vertical_direction, waterlogged);
        }
    }

}
