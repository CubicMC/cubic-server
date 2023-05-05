#include "JungleLeaves.hpp"
namespace Blocks {
    namespace JungleLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 298;
                    case Properties::Waterlogged::FALSE:
                        return 299;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 300;
                    case Properties::Waterlogged::FALSE:
                        return 301;
                    }
                }
            case Properties::Distance::TWO:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 302;
                    case Properties::Waterlogged::FALSE:
                        return 303;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 304;
                    case Properties::Waterlogged::FALSE:
                        return 305;
                    }
                }
            case Properties::Distance::THREE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 306;
                    case Properties::Waterlogged::FALSE:
                        return 307;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 308;
                    case Properties::Waterlogged::FALSE:
                        return 309;
                    }
                }
            case Properties::Distance::FOUR:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 310;
                    case Properties::Waterlogged::FALSE:
                        return 311;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 312;
                    case Properties::Waterlogged::FALSE:
                        return 313;
                    }
                }
            case Properties::Distance::FIVE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 314;
                    case Properties::Waterlogged::FALSE:
                        return 315;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 316;
                    case Properties::Waterlogged::FALSE:
                        return 317;
                    }
                }
            case Properties::Distance::SIX:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 318;
                    case Properties::Waterlogged::FALSE:
                        return 319;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 320;
                    case Properties::Waterlogged::FALSE:
                        return 321;
                    }
                }
            case Properties::Distance::SEVEN:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 322;
                    case Properties::Waterlogged::FALSE:
                        return 323;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 324;
                    case Properties::Waterlogged::FALSE:
                        return 325;
                    }
                }
            }
            return 0;
        }
    }

}
