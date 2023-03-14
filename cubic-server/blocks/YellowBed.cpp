#include "YellowBed.hpp"
#include <stdexcept>

namespace Blocks {
    namespace YellowBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1701;
                    case Properties::Part::FOOT:
                        return 1702;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1703;
                    case Properties::Part::FOOT:
                        return 1704;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1705;
                    case Properties::Part::FOOT:
                        return 1706;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1707;
                    case Properties::Part::FOOT:
                        return 1708;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1709;
                    case Properties::Part::FOOT:
                        return 1710;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1711;
                    case Properties::Part::FOOT:
                        return 1712;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1713;
                    case Properties::Part::FOOT:
                        return 1714;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1715;
                    case Properties::Part::FOOT:
                        return 1716;
                    }
                }
            }
            return 0;
        }
    }

}
