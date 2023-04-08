#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace ChiseledBookshelf {
namespace Properties {
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Slot_0_occupied {
    TRUE,
    FALSE
};
enum class Slot_1_occupied {
    TRUE,
    FALSE
};
enum class Slot_2_occupied {
    TRUE,
    FALSE
};
enum class Slot_3_occupied {
    TRUE,
    FALSE
};
enum class Slot_4_occupied {
    TRUE,
    FALSE
};
enum class Slot_5_occupied {
    TRUE,
    FALSE
};
}
BlockId toProtocol(
    Properties::Facing facing, Properties::Slot_0_occupied slot_0_occupied, Properties::Slot_1_occupied slot_1_occupied, Properties::Slot_2_occupied slot_2_occupied,
    Properties::Slot_3_occupied slot_3_occupied, Properties::Slot_4_occupied slot_4_occupied, Properties::Slot_5_occupied slot_5_occupied
);
}

}
