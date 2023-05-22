#include "Level.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <mutex>

namespace world_storage {

Level::~Level() { }

// ChunkColumn &Level::addChunkColumn(Position2D pos, const ChunkColumn &chunkColumn)
// {
//     _chunkColumnsMutex.lock();
//     _chunkColumns.emplace(pos, chunkColumn);
//     _chunkColumnsMutex.unlock();
//     return _chunkColumns.at(pos);
// }

ChunkColumn &Level::addChunkColumn(Position2D pos, std::shared_ptr<Dimension> dimension)
{
    std::lock_guard<std::mutex> _(this->_chunkColumnsMutex);
    _chunkColumns.emplace(pos, ChunkColumn{pos, dimension});
    return _chunkColumns.at(pos);
}

bool Level::hasChunkColumn(const Position2D &pos) const { return _chunkColumns.contains(pos) && _chunkColumns.at(pos).isReady(); }

bool Level::hasChunkColumn(int x, int z) const { return this->hasChunkColumn({x, z}); }

ChunkColumn &Level::getChunkColumn(Position2D pos) { return _chunkColumns.at(pos); }

const ChunkColumn &Level::getChunkColumn(Position2D pos) const { return _chunkColumns.at(pos); }

ChunkColumn &Level::getChunkColumn(int x, int z) { return this->getChunkColumn({x, z}); }

const ChunkColumn &Level::getChunkColumn(int x, int z) const { return this->getChunkColumn({x, z}); }

// Get the chunk from the block coordinate
ChunkColumn &Level::getChunkColumnFromBlockPos(int x, int z) { return this->getChunkColumn({transformBlockPosToChunkPos(x), transformBlockPosToChunkPos(z)}); }

ChunkColumn &Level::getChunkColumnFromBlockPos(Position2D pos) { return this->getChunkColumn({transformBlockPosToChunkPos(pos.x), transformBlockPosToChunkPos(pos.z)}); }

const ChunkColumn &Level::getChunkColumnFromBlockPos(int x, int z) const { return this->getChunkColumn({transformBlockPosToChunkPos(x), transformBlockPosToChunkPos(z)}); }

const ChunkColumn &Level::getChunkColumnFromBlockPos(Position2D pos) const
{
    return this->getChunkColumn({transformBlockPosToChunkPos(pos.x), transformBlockPosToChunkPos(pos.z)});
}

void Level::removeChunkColumn(Position2D pos) { _chunkColumns.erase(pos); }

void Level::clear()
{
    _chunkColumnsMutex.lock();
    _chunkColumns.clear();
    _chunkColumnsMutex.unlock();
}

} // namespace world_storage
