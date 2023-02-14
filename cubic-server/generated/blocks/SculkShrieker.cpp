#include "SculkShrieker.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SculkShrieker {
        BlockId toProtocol(Properties::Can_summon can_summon, Properties::Shrieking shrieking, Properties::Waterlogged waterlogged) {
            switch (can_summon) {
            case Properties::Can_summon::TRUE:
                switch (shrieking) {
                case Properties::Shrieking::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18900;
                    case Properties::Waterlogged::FALSE:
                        return 18901;
                    }
                case Properties::Shrieking::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18902;
                    case Properties::Waterlogged::FALSE:
                        return 18903;
                    }
                }
            case Properties::Can_summon::FALSE:
                switch (shrieking) {
                case Properties::Shrieking::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18904;
                    case Properties::Waterlogged::FALSE:
                        return 18905;
                    }
                case Properties::Shrieking::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 18906;
                    case Properties::Waterlogged::FALSE:
                        return 18907;
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 3)
            throw std::runtime_error("Invalid number of properties");
            Properties::Can_summon can_summon;
            Properties::Shrieking shrieking;
            Properties::Waterlogged waterlogged;
            for (auto prop : properties) {
                if (prop.first == "can_summon") {
                    if (prop.second == "true") {
                        can_summon = Properties::Can_summon::TRUE;
                    } else if (prop.second == "false") {
                        can_summon = Properties::Can_summon::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"can_summon\" value");
                    }
                } else if (prop.first == "shrieking") {
                    if (prop.second == "true") {
                        shrieking = Properties::Shrieking::TRUE;
                    } else if (prop.second == "false") {
                        shrieking = Properties::Shrieking::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"shrieking\" value");
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
            return toProtocol(can_summon, shrieking, waterlogged);
        }
    }

}
