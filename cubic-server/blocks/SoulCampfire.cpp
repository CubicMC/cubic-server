#include "SoulCampfire.hpp"
namespace Blocks {
    namespace SoulCampfire {
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17915;
                        case Properties::Waterlogged::FALSE:
                            return 17916;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17917;
                        case Properties::Waterlogged::FALSE:
                            return 17918;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17919;
                        case Properties::Waterlogged::FALSE:
                            return 17920;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17921;
                        case Properties::Waterlogged::FALSE:
                            return 17922;
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17923;
                        case Properties::Waterlogged::FALSE:
                            return 17924;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17925;
                        case Properties::Waterlogged::FALSE:
                            return 17926;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17927;
                        case Properties::Waterlogged::FALSE:
                            return 17928;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17929;
                        case Properties::Waterlogged::FALSE:
                            return 17930;
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17931;
                        case Properties::Waterlogged::FALSE:
                            return 17932;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17933;
                        case Properties::Waterlogged::FALSE:
                            return 17934;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17935;
                        case Properties::Waterlogged::FALSE:
                            return 17936;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17937;
                        case Properties::Waterlogged::FALSE:
                            return 17938;
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17939;
                        case Properties::Waterlogged::FALSE:
                            return 17940;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17941;
                        case Properties::Waterlogged::FALSE:
                            return 17942;
                        }
                    }
                case Properties::Lit::FALSE:
                    switch (signal_fire) {
                    case Properties::Signal_fire::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17943;
                        case Properties::Waterlogged::FALSE:
                            return 17944;
                        }
                    case Properties::Signal_fire::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 17945;
                        case Properties::Waterlogged::FALSE:
                            return 17946;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
