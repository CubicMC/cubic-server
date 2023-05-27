#ifndef CUBICSERVER_WORLDSTORAGE_LEVEL_HPP
#define CUBICSERVER_WORLDSTORAGE_LEVEL_HPP

#include <shared_mutex>
#include <unordered_map>

#include "ChunkColumn.hpp"
#include "types.hpp"

constexpr int transformBlockPosToChunkPos(int64_t x) { return x < 0 ? -1 + int64_t((x + 1) / 16) : int64_t(x / 16); }
constexpr int transformChunkPosToRegionPos(int64_t x) { return x < 0 ? -1 + int64_t(x + 1) / 32 : int64_t(x / 32); }

namespace world_storage {

class Level {
public:
    Level() = default;
    ~Level();

    ChunkColumn &addChunkColumn(Position2D pos, ChunkColumn &&chunkColumn);
    // ChunkColumn &addChunkColumn(Position2D pos, ChunkColumn &chunkColumn);

    ChunkColumn &addChunkColumn(Position2D pos);

    bool hasChunkColumn(const Position2D &pos) const;
    bool hasChunkColumn(int x, int z) const;

    /** Get the chunk from chunk coordinate */
    ChunkColumn &getChunkColumn(Position2D pos);
    ChunkColumn &getChunkColumn(int x, int z);
    const ChunkColumn &getChunkColumn(Position2D pos) const;
    const ChunkColumn &getChunkColumn(int x, int z) const;

    /** Get the chunk from raw coordinate */
    ChunkColumn &getChunkColumnFromBlockPos(int x, int z);
    ChunkColumn &getChunkColumnFromBlockPos(Position2D pos);
    const ChunkColumn &getChunkColumnFromBlockPos(int x, int z) const;
    const ChunkColumn &getChunkColumnFromBlockPos(Position2D pos) const;

    void removeChunkColumn(Position2D pos);

private:
    mutable std::shared_mutex _chunkColumnsMutex;
    std::unordered_map<Position2D, ChunkColumn> _chunkColumns;
};

}

#endif // CUBICSERVER_WORLDSTORAGE_LEVEL_HPP
