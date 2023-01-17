#include "Level.hpp"

namespace world_storage{

Level::~Level()
{
}

ChunkColumn &Level::addChunkColumn(_2d_pos pos, const ChunkColumn &chunkColumn) {
    _chunkColumns.insert({pos, chunkColumn});
    return _chunkColumns.at(pos);
}

ChunkColumn &Level::addChunkColumn(_2d_pos pos)
{
    _chunkColumns.insert({pos, {}});
    return _chunkColumns.at(pos);
}

ChunkColumn &Level::getChunkColumn(_2d_pos pos)
{
    return _chunkColumns.at(pos);
}

const ChunkColumn &Level::getChunkColumn(_2d_pos pos) const
{
    return _chunkColumns.at(pos);
}

ChunkColumn &Level::getChunkColumn(int x, int z)
{
    _2d_pos pos = {x < 0 ? -1 + int(x/16) : int(x/16), x < 0 ? -1 + int(z/16) : int(z/16)};
    return _chunkColumns.at(pos);
}

const ChunkColumn &Level::getChunkColumn(int x, int z) const
{
    _2d_pos pos = {x < 0 ? -1 + int(x/16) : int(x/16), x < 0 ? -1 + int(z/16) : int(z/16)};
    return _chunkColumns.at(pos);
}

void Level::removeChunkColumn(_2d_pos pos) {
    _chunkColumns.erase(pos);
}

}
