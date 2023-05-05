#include "RedBed.hpp"
namespace Blocks {
    namespace RedBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1861;
                    case Properties::Part::FOOT:
                        return 1862;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1863;
                    case Properties::Part::FOOT:
                        return 1864;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1865;
                    case Properties::Part::FOOT:
                        return 1866;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1867;
                    case Properties::Part::FOOT:
                        return 1868;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1869;
                    case Properties::Part::FOOT:
                        return 1870;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1871;
                    case Properties::Part::FOOT:
                        return 1872;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1873;
                    case Properties::Part::FOOT:
                        return 1874;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1875;
                    case Properties::Part::FOOT:
                        return 1876;
                    }
                }
            }
            return 0;
        }
    }

}
