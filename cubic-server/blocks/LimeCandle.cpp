#include "LimeCandle.hpp"
namespace Blocks {
    namespace LimeCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20193;
                    case Properties::Waterlogged::FALSE:
                        return 20194;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20195;
                    case Properties::Waterlogged::FALSE:
                        return 20196;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20197;
                    case Properties::Waterlogged::FALSE:
                        return 20198;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20199;
                    case Properties::Waterlogged::FALSE:
                        return 20200;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20201;
                    case Properties::Waterlogged::FALSE:
                        return 20202;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20203;
                    case Properties::Waterlogged::FALSE:
                        return 20204;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20205;
                    case Properties::Waterlogged::FALSE:
                        return 20206;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20207;
                    case Properties::Waterlogged::FALSE:
                        return 20208;
                    }
                }
            }
            return 0;
        }
    }

}
