#include "ChunkColumn.hpp"

#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "blocks.hpp"
#include "generation/overworld.hpp"
#include "logging/Logger.hpp"
#include "types.hpp"

#define APPEND_CHUNK_TO(neighbours, chunkMap, pos2D)                                        \
    if (chunkMap.contains(_chunkPos + pos2D)) {                                             \
        chunkMap.at(_chunkPos + pos2D)._generationLock.lock();                              \
        neighbours.push_back(&chunkMap.at(_chunkPos + pos2D));                              \
    } else {                                                                                \
        _dimension->generateChunk(_chunkPos + pos2D, GenerationState::LOCAL_MODIFICATIONS); \
        chunkMap.at(_chunkPos + pos2D)._generationLock.lock();                              \
        neighbours.push_back(&chunkMap.at(_chunkPos + pos2D));                              \
    }

#define GET_NEIGHBOURS()                                          \
    std::vector<ChunkColumn *> neighbours;                        \
    neighbours.reserve(8);                                        \
    auto chunkColumns = _dimension->getLevel().getChunkColumns(); \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(1, 1))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(0, 1))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(-1, 1))  \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(1, 0))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(-1, 0))  \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(1, -1))  \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(0, -1))  \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(-1, -1))

#define RELEASE_NEIGHBOURS()                 \
    for (auto neighbour : neighbours) {      \
        neighbour->_generationLock.unlock(); \
    }

namespace world_storage {

ChunkColumn::ChunkColumn(const Position2D &chunkPos, std::shared_ptr<Dimension> dimension):
    _chunkPos(chunkPos),
    _currentState(GenerationState::INITIALIZED),
    _dimension(dimension)
{
    for (auto &block : this->_blocks)
        block = 0;
    for (auto &biome : this->_biomes)
        biome = 0;
    for (auto i = 0; i < HEIGHTMAP_ARRAY_SIZE; i++) {
        _heightMap.motionBlocking[i] = std::make_shared<nbt::Long>("", 0);
        _heightMap.worldSurface[i] = std::make_shared<nbt::Long>("", 0);
    }
}

ChunkColumn::ChunkColumn(const ChunkColumn &other):
    _blocks(other._blocks),
    _skyLights(other._skyLights),
    _blockLights(other._blockLights),
    _biomes(other._biomes),
    // _blockEntities(other._blockEntities),
    _tickData(other._tickData),
    _chunkPos(other._chunkPos),
    _heightMap(other._heightMap),
    _currentState(other._currentState),
    _generationLock(),
    _dimension(other._dimension)
{
}

ChunkColumn::~ChunkColumn() { }

void ChunkColumn::updateBlock(Position pos, BlockId id)
{
    // TODO: Move the bitStoring to a separate class
    // Heightmap update
    int blockNumber = pos.x + pos.z * SECTION_WIDTH;
    int startLong = (blockNumber * HEIGHTMAP_BITS) / 64;
    int startOffset = (blockNumber * HEIGHTMAP_BITS) % 64;
    int endLong = ((blockNumber + 1) * HEIGHTMAP_BITS - 1) / 64;

    if (pos.y > _heightMap.motionBlocking.at(startLong)->getValue() >> startOffset) {
        *_heightMap.motionBlocking[startLong] |= (pos.y << startOffset);

        if (startLong != endLong)
            *_heightMap.motionBlocking[endLong] |= (pos.y >> (64 - startOffset));
    }

    // Block update
    _blocks.at(calculateBlockIdx(pos)) = id;
}

BlockId ChunkColumn::getBlock(Position pos) const { return _blocks.at(calculateBlockIdx(pos)); }

const std::array<BlockId, SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getBlocks() const { return _blocks; }

void ChunkColumn::updateSkyLight(Position pos, uint8_t light) { _skyLights.at(calculateBlockIdx(pos)) = light; }

uint8_t ChunkColumn::getSkyLight(Position pos) const { return _skyLights.at(calculateBlockIdx(pos)); }

const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getSkyLights() const { return _skyLights; }

void ChunkColumn::updateBlockLight(Position pos, uint8_t light)
{
    _blockLights.at(calculateBlockIdx(pos)) = light;
    // _blockLights.at(pos.x + pos.z * 16 + pos.y * 16*16) = light;
}

uint8_t ChunkColumn::getBlockLight(Position pos) const
{
    return _blockLights.at(calculateBlockIdx(pos));
    // return _blockLights.at(pos.x + pos.z * 16 + pos.y * 16*16);
}

const std::array<uint8_t, SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getBlockLights() const { return _blockLights; }

void ChunkColumn::updateBiome(Position pos, uint8_t biome) { _biomes.at(calculateBiomeIdx(pos)) = biome; }

uint8_t ChunkColumn::getBiome(Position pos) const { return _biomes.at(calculateBiomeIdx(pos)); }

const std::array<uint8_t, BIOME_SECTION_3D_SIZE * NB_OF_SECTIONS> &ChunkColumn::getBiomes() const { return _biomes; }

int64_t ChunkColumn::getTick() { return _tickData; }

void ChunkColumn::setTick(int64_t tick) { _tickData = tick; }

Position2D ChunkColumn::getChunkPos() const { return _chunkPos; }

bool ChunkColumn::isReady() const { return this->_currentState == GenerationState::READY ? true : false; }

GenerationState ChunkColumn::getState() const { return this->_currentState; }

// void ChunkColumn::updateEntity(std::size_t id, Entity *e) {
//     _entities.at(id) = e;
// }

// void ChunkColumn::updateEntity(u128 uuid, Entity *e) {
// }

// void ChunkColumn::addEntity(Entity *e) { // TODO: entity must be a pointer or a reference ?
//     _entities.push_back(e); // TODO: see which of emplace_back of emplace_front is better or push_back or push_front
//     // _entities.emplace_back(std::make_shared<entity>(e));
// }

// void ChunkColumn::removeEntity(std::size_t id) {
//     _entities.erase(_entities.begin() + id);
// }

// void ChunkColumn::removeEntity(u128 uuid) {
// }

// Entity *ChunkColumn::getEntity(std::size_t id) {
//     return _entities.at(id);
// }

// Entity *ChunkColumn::getEntity(u128 uuid) {
//     return _entities.at(0);
// }

// const std::deque<Entity *> &ChunkColumn::getEntities() {
//     return _entities;
// }

void ChunkColumn::updateHeightMap(void) { }

const HeightMap &ChunkColumn::getHeightMap() const { return _heightMap; }

void ChunkColumn::generate(GenerationState goalState)
{
    _generationLock.lock();
    switch (_dimension->getWorld()->getWorldType()) {
    case WorldType::DEFAULT:
        switch (_dimension->getDimensionType()) {
        case DimensionType::OVERWORLD:
            _generateOverworld(goalState);
            break;
        case DimensionType::NETHER:
            _generateNether(goalState);
            break;
        case DimensionType::END:
            _generateEnd(goalState);
            break;
        default:
            LERROR("Unknown dimension type");
            break;
        }
        break;
    case WorldType::SUPERFLAT:
        _generateFlat(goalState);
        break;
    case WorldType::LARGEBIOME:
    case WorldType::AMPLIFIED:
    case WorldType::SINGLEBIOME:
    case WorldType::DEBUG:
        LERROR("World type not implemented yet");
        break;
    default:
        LERROR("Unknown world type");
        break;
    }
    _generationLock.unlock();
}

void ChunkColumn::_generateOverworld(GenerationState goalState)
{
    static auto generator = generation::Overworld(_dimension->getWorld()->getSeed());

    while (_currentState < goalState) {
        switch (this->_currentState) {
        case GenerationState::INITIALIZED:
            _generateRawGeneration(generator);
            break;
        case GenerationState::RAW_GENERATION:
            _generateLakes(generator);
            break;
        case GenerationState::LAKES:
            _generateLocalModifications(generator);
            break;
        case GenerationState::LOCAL_MODIFICATIONS:
            _generateUndergroundStructures(generator);
            break;
        case GenerationState::UNDERGROUND_STRUCTURES:
            _generateSurfaceStructures(generator);
            break;
        case GenerationState::SURFACE_STRUCTURES:
            _generateStrongholds(generator);
            break;
        case GenerationState::STRONGHOLDS:
            _generateUndergroundOres(generator);
            break;
        case GenerationState::UNDERGROUND_ORES:
            _generateUndergroundDecoration(generator);
            break;
        case GenerationState::UNDERGROUND_DECORATION:
            _generateFluidSprings(generator);
            break;
        case GenerationState::FLUID_SPRINGS:
            _generateVegetalDecoration(generator);
            break;
        case GenerationState::VEGETAL_DECORATION:
            _generateTopLayerModification(generator);
            break;
        case GenerationState::TOP_LAYER_MODIFICATION:
            _currentState = GenerationState::READY;
            break;
        default:
            LERROR("Chunk: ", _chunkPos, " Unknown state");
            break;
        }
    }
}

void ChunkColumn::_generateNether(UNUSED GenerationState goalState) { }

void ChunkColumn::_generateEnd(UNUSED GenerationState goalState) { }

void ChunkColumn::_generateFlat(UNUSED GenerationState goalState)
{
    // TODO: optimize this
    // This take forever because of the Block constructor
    for (int y = 0; y < 11; y++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            for (int x = 0; x < SECTION_WIDTH; x++) {
                if (y == 0) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol());
                } else if (y == 1 || y == 2) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::Dirt::toProtocol());
                } else if (y == 3) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE));
                }
            }
        }
    }
}

void ChunkColumn::_generateRawGeneration(generation::Generator &generator)
{
    // generate blocks
    for (int y = CHUNK_HEIGHT_MIN; y < CHUNK_HEIGHT_MAX; y++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            for (int x = 0; x < SECTION_WIDTH; x++) {
                updateBlock({x, y, z}, generator.getBlock(x + this->_chunkPos.x * SECTION_WIDTH, y, z + this->_chunkPos.z * SECTION_WIDTH));
            }
        }
    }
    // generate bedrock
    int64_t state = (((this->_chunkPos.x * 0x4F9939F508L + this->_chunkPos.z * 0x1EF1565BD5L) ^ 0x5DEECE66DL) * 0x9D89DAE4D6C29D9L + 0x1844E300013E5B56L) & 0xFFFFFFFFFFFFL;
    for (int x = 0; x < SECTION_WIDTH; x++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            updateBlock({x, 0 + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol()); // bedrock
            if (4 <= (state >> 17) % 5)
                updateBlock({x, 1 + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol()); // bedrock
            state = ((state * 0x530F32EB772C5F11L + 0x89712D3873C4CD04L) * 0x9D89DAE4D6C29D9L + 0x1844E300013E5B56L) & 0xFFFFFFFFFFFFL;
        }
    }
    // generate biomes
    for (int y = 0; y < BIOME_HEIGHT_MAX; y++) {
        for (int z = 0; z < BIOME_SECTION_WIDTH; z++) {
            for (int x = 0; x < BIOME_SECTION_WIDTH; x++) {
                // TODO
                updateBiome({x, y + BIOME_HEIGHT_MIN, z}, generator.getBiome(x, y, z));
            }
        }
    }
    _currentState = GenerationState::RAW_GENERATION;
}

void ChunkColumn::_generateLakes(UNUSED generation::Generator &generator)
{
    int waterLevel = 86;

    // TODO: improve this to fill caves
    // generate water
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = waterLevel; 0 < y; y--) {
                if (getBlock({x, y, z}) == 1)
                    break;
                updateBlock({x, y, z}, Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO));
            }
        }
    }
    _currentState = GenerationState::LAKES;
}

void ChunkColumn::_generateLocalModifications(UNUSED generation::Generator &generator)
{
    // generate grass
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            auto lastBlock = 0;
            for (int y = CHUNK_HEIGHT_MAX - 2; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol())
                    continue;
                if (block == Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO)) {
                    lastBlock = Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO);
                    continue;
                }
                if (block == Blocks::Stone::toProtocol() && lastBlock == Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO)) {
                    updateBlock({x, y, z}, Blocks::Sand::toProtocol()); // sand
                    break;
                }
                if (block == Blocks::Stone::toProtocol() && lastBlock == Blocks::Air::toProtocol()) {
                    updateBlock({x, y, z}, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE)); // grass
                    updateBlock({x, y - 1, z}, Blocks::Dirt::toProtocol()); // dirt
                    updateBlock({x, y - 2, z}, Blocks::Dirt::toProtocol()); // dirt
                    break;
                }
            }
        }
    }
    _currentState = GenerationState::LOCAL_MODIFICATIONS;
}

void ChunkColumn::_generateUndergroundStructures(UNUSED generation::Generator &generator) { _currentState = GenerationState::UNDERGROUND_STRUCTURES; }

void ChunkColumn::_generateSurfaceStructures(UNUSED generation::Generator &generator) { _currentState = GenerationState::SURFACE_STRUCTURES; }

void ChunkColumn::_generateStrongholds(UNUSED generation::Generator &generator) { _currentState = GenerationState::STRONGHOLDS; }

void ChunkColumn::_generateUndergroundOres(UNUSED generation::Generator &generator) { _currentState = GenerationState::UNDERGROUND_ORES; }

void ChunkColumn::_generateUndergroundDecoration(UNUSED generation::Generator &generator) { _currentState = GenerationState::UNDERGROUND_DECORATION; }

void ChunkColumn::_generateFluidSprings(UNUSED generation::Generator &generator) { _currentState = GenerationState::FLUID_SPRINGS; }

void ChunkColumn::_generateVegetalDecoration(generation::Generator &generator)
{
    // GET_NEIGHBOURS()
    // find where to generate trees on surface
    std::deque<Position> treeEmplacements;
    for (int z = 0; z < SECTION_WIDTH; z++) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int y = CHUNK_HEIGHT_MAX - 5; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = getBlock({x, y, z});
                if (block == Blocks::Air::toProtocol())
                    continue;
                else {
                    if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE) || block == Blocks::Dirt::toProtocol()) {
                        if (generator.getNoise(x + this->_chunkPos.x * SECTION_WIDTH, y, z + this->_chunkPos.z * SECTION_WIDTH).noise3D.density > 0.5 &&
                            generator.getBiome(x + this->_chunkPos.x * SECTION_WIDTH, y, z + this->_chunkPos.z * SECTION_WIDTH))
                            treeEmplacements.push_back({x, y + 1, z});
                    }
                    break;
                }
            }
        }
    }
    // test if there is place for a tree
    for (auto treeEmplacement = treeEmplacements.begin(); treeEmplacement != treeEmplacements.end(); treeEmplacement++) {
        for (int i = 0; i <= 5; i++) {
            auto block = getBlock({treeEmplacement->x, treeEmplacement->y + i, treeEmplacement->z});
            // Test for transparent blocks (with tags ?)
            if (block != Blocks::Air::toProtocol()) {
                if (treeEmplacement == treeEmplacements.begin()) {
                    treeEmplacements.pop_front();
                    treeEmplacement = treeEmplacements.begin();
                } else {
                    auto previous = treeEmplacement -= 1;
                    treeEmplacements.erase(treeEmplacement);
                    treeEmplacement = previous;
                }
            }
        }
    }
    LDEBUG("There is : " << treeEmplacements.size() << " emplacements for trees in this chunk");
    // generate tree
    for (auto treeEmplacement : treeEmplacements) {
        // auto tree = generator.getTree(treeEmplacement.x + this->_chunkPos.x * SECTION_WIDTH, treeEmplacement.y, treeEmplacement.z + this->_chunkPos.z * SECTION_WIDTH);
        // for (auto block : tree) {
        // updateBlock({treeEmplacement.x + block.x, treeEmplacement.y + block.y, treeEmplacement.z + block.z}, block.block);
        // }
        // this code is for testing only
        updateBlock({treeEmplacement.x, treeEmplacement.y, treeEmplacement.z}, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
    }
    // RELEASE_NEIGHBOURS()
    _currentState = GenerationState::VEGETAL_DECORATION;
}

void ChunkColumn::_generateTopLayerModification(UNUSED generation::Generator &generator)
{
    // GET_NEIGHBOURS()
    // RELEASE_NEIGHBOURS()
    _currentState = GenerationState::TOP_LAYER_MODIFICATION;
}

} // namespace world_storage
