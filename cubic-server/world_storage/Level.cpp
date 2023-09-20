#include "Level.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <mutex>
#include <unordered_map>
#include <vector>

namespace world_storage {

Level::~Level() { }

ChunkColumn &Level::addChunkColumn(Position2D pos, ChunkColumn &&chunkColumn)
{
    std::lock_guard _(this->_chunkColumnsMutex);
    _chunkColumns.emplace(pos, std::move(chunkColumn));

    return _chunkColumns.at(pos);
}

ChunkColumn &Level::addChunkColumn(Position2D pos, std::shared_ptr<Dimension> dimension)
{
    std::lock_guard<std::mutex> _(this->chunkColumnsMutex);
    _chunkColumns.emplace(pos, ChunkColumn {pos, dimension});
    return _chunkColumns.at(pos);
}

bool Level::hasChunkColumn(const Position2D &pos) const
{
    std::shared_lock _(_chunkColumnsMutex);
    return _chunkColumns.contains(pos) && _chunkColumns.at(pos).isReady();
}

bool Level::hasChunkColumn(int x, int z) const { return this->hasChunkColumn({x, z}); }

ChunkColumn &Level::getChunkColumn(Position2D pos)
{
    std::shared_lock _(_chunkColumnsMutex);
    return _chunkColumns.at(pos);
}

const ChunkColumn &Level::getChunkColumn(Position2D pos) const
{
    std::shared_lock _(_chunkColumnsMutex);
    return _chunkColumns.at(pos);
}

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

const std::unordered_map<Position2D, ChunkColumn> &Level::getChunkColumns() const
{
    std::lock_guard<std::mutex> _(this->chunkColumnsMutex);
    return _chunkColumns;
}

std::unordered_map<Position2D, ChunkColumn> &Level::getChunkColumns()
{
    std::lock_guard<std::mutex> _(this->chunkColumnsMutex);
    return _chunkColumns;
}

void Level::clear()
{
    std::lock_guard<std::mutex> _(this->chunkColumnsMutex);
    _chunkColumns.clear();
}

void Level::save(const std::string &folder)
{
    auto chunks = this->getChunkColumns();
    std::unordered_map<Position2D, std::vector<ChunkColumn &>> regions;
    
    std::lock_guard _(this->_chunkColumnsMutex);
    
}

} // namespace world_storage
