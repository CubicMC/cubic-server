#include <cstdint>
#include <vector>
#include <deque>

#define bit_per_block 15

typedef struct blockType {
    uint16_t data : bit_per_block;
};

/** A Nibble is a container with only for bits, like a half of a uint8_t */
typedef struct nibbleType {
    uint8_t data : 4;
};

typedef struct block_entity { // TODO: replace with nbt type
};

typedef struct entity { // TODO: replace with a nbt type
    // tag short air
    // tag string customName
    // tag byte customNameVisible
    // tag float fallDistance
    // tag short fire
    // tag byte glowing
    // tag byte hasVisualFire
    // tag string id
    // tag byte invulnerable
    // tag list motion
    // tag byte noGravity
    // tag byte onGround
    // tag list passengers
    // tag int portalCooldown
    // tag list pos
    // tag list rotation
    // tag byte silent
    // tag list tags
    // tag int ticksFrozen
    // tag int array uuid
};


typedef struct heightType {
    uint8_t data : 9;
};

typedef struct height_map {
    heightType motion_blocking[16*16];
    heightType world_surface[16*16];
};

class ChunkColumn
{
public:
    ChunkColumn();
    ~ChunkColumn();
private:
    blockType _blocks[16*16*16*20];
    nibbleType _skylight[16*16*16*20]; // uint8_t _skylight[(16*320*16)/2];
    nibbleType _blocklight[16*16*16*20]; // uint8_t _blocklight[(16*320*16)/2];
    uint8_t _biomes[4*4*4*20]; // 6 bits per biome ? there is only 0-62 biome in minecraft
    std::vector<block_entity> _blockEntities; // TODO : use tag compound
    int64_t _tick_data;
    std::deque<entity> _entities; // TODO : use tag compound
    height_map _height_map;
};