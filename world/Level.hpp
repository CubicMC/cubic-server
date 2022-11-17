#include <unordered_map>

#include "ChunkColumn.hpp"


typedef struct _2d_pos {
    int x;
    int z;
} _2d_pos;

class Level
{
public:
    Level();
    ~Level();

    void addChunkColumn(_2d_pos pos, ChunkColumn& chunkColumn);
    /** Get the chunk from chunk coordinate */
    ChunkColumn& getChunkColumn(_2d_pos pos);
    /** Get the chunk from raw coordinate */
    ChunkColumn& getChunkColumn(int x, int z);
    void removeChunkColumn(_2d_pos pos);

private:
    std::unordered_map<_2d_pos, ChunkColumn&> _chunkColumns;
};
