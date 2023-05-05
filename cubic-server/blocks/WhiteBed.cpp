#include "WhiteBed.hpp"
namespace Blocks {
    namespace WhiteBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1637;
                    case Properties::Part::FOOT:
                        return 1638;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1639;
                    case Properties::Part::FOOT:
                        return 1640;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1641;
                    case Properties::Part::FOOT:
                        return 1642;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1643;
                    case Properties::Part::FOOT:
                        return 1644;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1645;
                    case Properties::Part::FOOT:
                        return 1646;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1647;
                    case Properties::Part::FOOT:
                        return 1648;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1649;
                    case Properties::Part::FOOT:
                        return 1650;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1651;
                    case Properties::Part::FOOT:
                        return 1652;
                    }
                }
            }
            return 0;
        }
    }

}
