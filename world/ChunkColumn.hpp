#include <cstdint>
#include <array>
#include <vector>
#include <deque>

#define CHUNK_2D_SIZE 16*16
#define CHUNK_3D_SIZE CHUNK_2D_SIZE*16
#define BIOME_3D_SIZE 4*4*4
#define NB_OF_CHUNKS 20


typedef struct block_entity {
} block_entity;

typedef struct entity {
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
} entity;


class ChunkColumn
{
public:
    ChunkColumn();
    ~ChunkColumn();
private:
    std::array<uint16_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blocks;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _skylight;
    std::array<uint8_t, CHUNK_3D_SIZE*NB_OF_CHUNKS> _blocklight;
    std::array<uint8_t, BIOME_3D_SIZE*NB_OF_CHUNKS> _biomes;
    std::vector<block_entity> _blockEntities;
    int64_t _tick_data;
    std::deque<entity> _entities;
    struct height_map {
        std::array<uint16_t, CHUNK_2D_SIZE> motion_blocking;
        std::array<uint16_t, CHUNK_2D_SIZE> world_surface;
    } _height_map;
};