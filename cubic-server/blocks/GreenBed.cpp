#include "GreenBed.hpp"
namespace Blocks {
    namespace GreenBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1845;
                    case Properties::Part::FOOT:
                        return 1846;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1847;
                    case Properties::Part::FOOT:
                        return 1848;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1849;
                    case Properties::Part::FOOT:
                        return 1850;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1851;
                    case Properties::Part::FOOT:
                        return 1852;
                    }
                }
            case Properties::Facing::WEST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1853;
                    case Properties::Part::FOOT:
                        return 1854;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1855;
                    case Properties::Part::FOOT:
                        return 1856;
                    }
                }
            case Properties::Facing::EAST:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1857;
                    case Properties::Part::FOOT:
                        return 1858;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1859;
                    case Properties::Part::FOOT:
                        return 1860;
                    }
                }
            }
            return 0;
        }
    }

}
