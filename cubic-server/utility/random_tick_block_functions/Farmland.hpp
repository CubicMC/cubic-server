#ifndef CUBICSERVER_UTILITY_RANDOMTICKBLOCKFUNCTIONS_FARMLAND_HPP
#define CUBICSERVER_UTILITY_RANDOMTICKBLOCKFUNCTIONS_FARMLAND_HPP

#include "protocol_id_converter/blockIdConverter.hpp"
#include "types.hpp"
#include <memory>

class Dimension;
namespace world_storage {
class ChunkColumn;
}

namespace utility {
void farmland(BlockId, world_storage::ChunkColumn &, const Position &);
} // namespace utility

#endif // CUBICSERVER_UTILITY_RANDOMTICKBLOCKFUNCTIONS_FARMLAND_HPP
