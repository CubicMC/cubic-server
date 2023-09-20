#ifndef REGION_HPP
#define REGION_HPP

#include "ChunkColumn.hpp"
#include "types.hpp"
#include <mutex>

namespace world_storage {
    class Region {
    public:
        Region() = default;
        ~Region() = default;

        void save(const std::string &folder);
        void addChunkColumn(ChunkColumn chunkColumn) {
            _chunkColumns.push_back(std::move(chunkColumn));
        }

    private:
        Position2D _pos;
        std::vector<ChunkColumn> _chunkColumns;
    };
}

#endif // REGION_HPP