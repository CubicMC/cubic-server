#include "Jukebox.hpp"
namespace Blocks {
namespace Jukebox {
BlockId toProtocol(Properties::Has_record has_record)
{
    switch (has_record) {
    case Properties::Has_record::TRUE:
        return 5649;
    case Properties::Has_record::FALSE:
        return 5650;
    default:
        return 0;
    }
    return 0;
}
}

}
