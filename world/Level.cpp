#include "Level.hpp"

void Level::addChunkColumn(_2d_pos pos, ChunkColumn &chunkColumn) {
    _chunkColumns.insert({pos, chunkColumn});
}

void Level::addChunkColumn(_2d_pos pos) {
    ChunkColumn chunkColumn;
    _chunkColumns.insert({pos, chunkColumn});
}

ChunkColumn &Level::getChunkColumn(_2d_pos pos) {
    return _chunkColumns.at(pos);
}

ChunkColumn &Level::getChunkColumn(int x, int z) {
    _2d_pos pos = {x < 0 ? -1 + int(x/16) : int(x/16), x < 0 ? -1 + int(z/16) : int(z/16)};
    return _chunkColumns.at(pos);
}

void Level::removeChunkColumn(_2d_pos pos) {
    _chunkColumns.erase(pos);
}