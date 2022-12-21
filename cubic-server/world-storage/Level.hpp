#include <unordered_map>
#include <functional>

#include "ChunkColumn.hpp"

#ifndef LEVEL_HPP
#define LEVEL_HPP

struct _2d_pos {
    int x;
    int z;

    bool operator==(const _2d_pos& other) const {
        return x == other.x && z == other.z;
    }
};

template<>
struct std::hash<_2d_pos>
{
    std::size_t operator()(_2d_pos const& pos) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(pos.x);
        std::size_t h2 = std::hash<int>{}(pos.z);
        return h1 ^ (h2 << 1);
    }
};

namespace world_storage {
class Level
{
public:
    Level();
    ~Level();

    ChunkColumn *addChunkColumn(_2d_pos pos, ChunkColumn *chunkColumn);
    ChunkColumn *addChunkColumn(_2d_pos pos);
    /** Get the chunk from chunk coordinate */
    ChunkColumn *getChunkColumn(_2d_pos pos);
    /** Get the chunk from raw coordinate */
    ChunkColumn *getChunkColumn(int x, int z);
    void removeChunkColumn(_2d_pos pos);

private:
    std::unordered_map<_2d_pos, ChunkColumn *> _chunkColumns;
};
}

#endif // LEVEL_HPP
