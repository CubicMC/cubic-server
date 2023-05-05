#include "BlackBed.hpp"
namespace Blocks {
    namespace BlackBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1877;
                    case Properties::Part::FOOT:
                        return 1878;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1879;
                    case Properties::Part::FOOT:
                        return 1880;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1881;
                    case Properties::Part::FOOT:
                        return 1882;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1883;
                    case Properties::Part::FOOT:
                        return 1884;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1885;
                    case Properties::Part::FOOT:
                        return 1886;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1887;
                    case Properties::Part::FOOT:
                        return 1888;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1889;
                    case Properties::Part::FOOT:
                        return 1890;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1891;
                    case Properties::Part::FOOT:
                        return 1892;
                    }
                }
            }
            return 0;
        }
    }

}
