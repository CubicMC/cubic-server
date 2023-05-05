#include "LightBlueBed.hpp"
namespace Blocks {
    namespace LightBlueBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1685;
                    case Properties::Part::FOOT:
                        return 1686;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1687;
                    case Properties::Part::FOOT:
                        return 1688;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1689;
                    case Properties::Part::FOOT:
                        return 1690;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1691;
                    case Properties::Part::FOOT:
                        return 1692;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1693;
                    case Properties::Part::FOOT:
                        return 1694;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1695;
                    case Properties::Part::FOOT:
                        return 1696;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1697;
                    case Properties::Part::FOOT:
                        return 1698;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1699;
                    case Properties::Part::FOOT:
                        return 1700;
                    }
                }
            }
            return 0;
        }
    }

}
