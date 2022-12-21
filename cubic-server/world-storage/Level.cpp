#include "Level.hpp"

namespace world_storage{
Level::~Level()
{
}

ChunkColumn *Level::addChunkColumn(_2d_pos pos, ChunkColumn *chunkColumn) {
    _chunkColumns.insert({pos, chunkColumn});
    return _chunkColumns.at(pos);
}

ChunkColumn *Level::addChunkColumn(_2d_pos pos) {
    _chunkColumns.insert({pos, new ChunkColumn()});
    return _chunkColumns.at(pos);
}

ChunkColumn *Level::getChunkColumn(_2d_pos pos) {
    return _chunkColumns.at(pos);
}

ChunkColumn *Level::getChunkColumn(int x, int z) {
    _2d_pos pos = {x < 0 ? -1 + int(x/16) : int(x/16), x < 0 ? -1 + int(z/16) : int(z/16)};
    return _chunkColumns.at(pos);
}

void Level::removeChunkColumn(_2d_pos pos) {
    delete _chunkColumns.at(pos);
    _chunkColumns.erase(pos);
}
}
