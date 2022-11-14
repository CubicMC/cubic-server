#include <unordered_map>

#include "ChunkColumn.hpp"


typedef struct _2d_pos {
    int x;
    int z;
};

class Level
{
public:
    Level();
    ~Level();
private:
    std::unordered_map<_2d_pos, ChunkColumn> _chunkColumns;
};
