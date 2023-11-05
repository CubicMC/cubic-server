#include "ChunkColumn.hpp"

#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "blocks.hpp"
#include "generation/features/surface/forestRock.hpp"
#include "generation/features/tree/oak.hpp"
#include "generation/features/tree/spruce.hpp"
#include "generation/features/underground/OreVein.hpp"
#include "generation/overworld.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"
#include "types.hpp"
#include "world_storage/Section.hpp"
#include <cstdlib>
#include <memory>

#define APPEND_CHUNK_TO(neighbours, chunkMap, pos2D)                                                                                 \
    if (chunkMap.contains(_chunkPos + pos2D) && chunkMap.at(_chunkPos + pos2D).getState() >= GenerationState::LOCAL_MODIFICATIONS) { \
        chunkMap.at(_chunkPos + pos2D)._generationLock.lock();                                                                       \
        neighbours.push_back(&chunkMap.at(_chunkPos + pos2D));                                                                       \
    } else {                                                                                                                         \
        /* _dimension->getLevel().chunkColumnsMutex.unlock();                                                                        \
        // _dimension->generateChunk(_chunkPos + pos2D, GenerationState::LOCAL_MODIFICATIONS);                                       \
        // _dimension->getLevel().chunkColumnsMutex.lock();                                                                          \
        // chunkMap.at(_chunkPos + pos2D)._generationLock.lock();                                                                    \
        // neighbours.push_back(&chunkMap.at(_chunkPos + pos2D));*/                                                                  \
    }

#define GET_NEIGHBOURS()                                           \
    std::vector<ChunkColumn *> neighbours;                         \
    neighbours.reserve(8);                                         \
    auto &chunkColumns = _dimension->getLevel().getChunkColumns(); \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(1, 1))    \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(0, 1))    \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(-1, 1))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(1, 0))    \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(-1, 0))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(1, -1))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(0, -1))   \
    APPEND_CHUNK_TO(neighbours, chunkColumns, Position2D(-1, -1))

#define RELEASE_NEIGHBOURS()                 \
    for (auto neighbour : neighbours) {      \
        neighbour->_generationLock.unlock(); \
    }

namespace world_storage {

ChunkColumn::ChunkColumn(const Position2D &chunkPos, std::shared_ptr<Dimension> dimension):
    _chunkPos(chunkPos),
    _heightMap(""),
    _currentState(GenerationState::INITIALIZED),
    _dimension(dimension)
{
    // OOF
    for (auto idx = 0; HEIGHTMAP_ENTRY[idx] != nullptr; idx++) {
        auto listBase = NBT_MAKE(nbt::List, HEIGHTMAP_ENTRY[idx]);
        auto list = std::dynamic_pointer_cast<nbt::List>(listBase);

        for (auto i = 0; i < HEIGHTMAP_ARRAY_SIZE; i++)
            list->push_back(std::make_shared<nbt::Long>("", 0));

        _heightMap.addValue(listBase);
    }
}

ChunkColumn::ChunkColumn(ChunkColumn &&chunk):
    _sections(std::move(chunk._sections)),
    _tickData(chunk._tickData),
    _chunkPos(chunk._chunkPos),
    _heightMap(chunk._heightMap),
    _currentState(chunk._currentState),
    _generationLock(),
    _dimension(chunk._dimension)
{
}

ChunkColumn::~ChunkColumn() { }

void ChunkColumn::updateBlock(const Position &pos, BlockId id)
{
    // TODO: Move the bitStoring to a separate class
    // Heightmap update
    // int blockNumber = pos.x + pos.z * SECTION_WIDTH;
    // int startLong = (blockNumber * HEIGHTMAP_BITS) / 64;
    // int startOffset = (blockNumber * HEIGHTMAP_BITS) % 64;
    // int endLong = ((blockNumber + 1) * HEIGHTMAP_BITS - 1) / 64;

    // if (pos.y > _heightMap.motionBlocking.at(startLong)->getValue() >> startOffset) {
    //     *_heightMap.motionBlocking[startLong] |= (pos.y << startOffset);

    //     if (startLong != endLong)
    //         *_heightMap.motionBlocking[endLong] |= (pos.y >> (64 - startOffset));
    // }

    // Block update
    // LINFO("ChunkColumn updateBlock: ", pos, "[", getSectionIndex(pos), "] -> ", id);
    // LINFO("wtf: " << pos << " " << id);
    _sections.at(getSectionIndex(pos)).updateBlock(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH, id);
    // _blocks.at(calculateBlockIdx(pos)) = id;
}

BlockId ChunkColumn::getBlock(const Position &pos) const { return _sections.at(getSectionIndex(pos)).getBlock(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH); }

uint8_t ChunkColumn::getSkyLight(const Position &pos) const
{
    return _sections.at(getSectionIndex(pos)).getSkyLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH);
}

void ChunkColumn::updateSkyLight(const Position &pos, uint8_t light)
{
    _sections.at(getSectionIndex(pos)).updateSkyLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH, light);
}

void ChunkColumn::updateBlockLight(const Position &pos, uint8_t light)
{
    _sections.at(getSectionIndex(pos)).updateBlockLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH, light);
}

uint8_t ChunkColumn::getBlockLight(const Position &pos) const
{
    return _sections.at(getSectionIndex(pos)).getBlockLight(Position {pos.x, pos.y - CHUNK_HEIGHT_MIN, pos.z} % SECTION_WIDTH);
}

void ChunkColumn::updateBiome(const Position &pos, uint8_t biome)
{
    _sections.at(getBiomeSectionIndex(pos)).updateBiome(Position {pos.x, pos.y - BIOME_HEIGHT_MIN, pos.z} % BIOME_SECTION_WIDTH, biome);
}

uint8_t ChunkColumn::getBiome(const Position &pos) const { return _sections.at(getBiomeSectionIndex(pos)).getBiome(pos % BIOME_SECTION_WIDTH); }

// const std::array<uint8_t, BIOME_SECTION_3D_SIZE * NB_OF_PLAYABLE_SECTIONS> &ChunkColumn::getBiomes() const { return _biomes; }

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

void ChunkColumn::updateHeightMap()
{
    for (auto &section : _sections) {
        for (int x = 0; x < SECTION_WIDTH; x++) {
            for (int z = 0; z < SECTION_WIDTH; z++) {
                for (int y = SECTION_WIDTH - 1; y >= 0; y--) {
                    if (section.getBlock({x, y, z}) != 0) {
                        _heightMap.getValueAs<nbt::List>("WORLD_SURFACE")->getValueAs<nbt::Long>(x + z * SECTION_WIDTH)->setValue(y + 1);
                        break;
                    }
                }
            }
        }
    }
}

void ChunkColumn::recalculateSkyLight()
{
    for (auto &section : _sections) {
        section.recalculateSkyLight();
    }
}

void ChunkColumn::recalculateBlockLight()
{
    for (auto &section : _sections) {
        section.recalculateBlockLight();
    }
}

void ChunkColumn::generate(GenerationState goalState)
{
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
        LERROR("World type not implemented yet");
        break;
    case WorldType::DEBUG:
        _generateDebug(goalState);
        break;
    case WorldType::SUPERFLAT_CUBIC_SERVER:
        _generateFlatCubicServer(goalState);
        break;
    default:
        LERROR("Unknown world type");
        break;
    }
    this->recalculateSkyLight();
}

void ChunkColumn::_generateOverworld(GenerationState goalState)
{
    auto generator = generation::Overworld(_dimension->getWorld()->getSeed());

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

void ChunkColumn::_generateNether(UNUSED GenerationState goalState) { std::lock_guard<std::mutex> _(this->_generationLock); }

void ChunkColumn::_generateEnd(UNUSED GenerationState goalState) { std::lock_guard<std::mutex> _(this->_generationLock); }

void ChunkColumn::_generateFlat(UNUSED GenerationState goalState)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
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
    _currentState = GenerationState::READY;
}

void ChunkColumn::_generateDebug(UNUSED GenerationState goalState)
{
    static size_t block = 0;
    for (int i = 0; i < world_storage::NB_OF_PLAYABLE_SECTIONS; i++) {
        updateBlock({7, 7 + (i << 4) - 64, 7}, block++);
        if (block > 23231)
            block = 0;
    }
    _currentState = GenerationState::READY;
}

void ChunkColumn::_generateFlatCubicServer(UNUSED GenerationState goalState)
{
    for (int y = 0; y < 11; y++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            for (int x = 0; x < SECTION_WIDTH; x++) {
                if (y == 0) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol());
                } else if (y == 1 || y == 2) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::Dirt::toProtocol());
                } else if (y == 3) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE));
                } else if ((y == 4 || y == 5 || y == 6) && z == 8 && x == 8) {
                    updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
                } else if (y == 7 || y == 8) {
                    switch (x + (z * 16)) {
                    case 6 + 6 * 16:
                    case 7 + 6 * 16:
                    case 8 + 6 * 16:
                    case 9 + 6 * 16:
                    case 10 + 6 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 7 * 16:
                    case 7 + 7 * 16:
                    case 8 + 7 * 16:
                    case 9 + 7 * 16:
                    case 10 + 7 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 8 * 16:
                    case 7 + 8 * 16:
                    case 9 + 8 * 16:
                    case 10 + 8 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 9 * 16:
                    case 7 + 9 * 16:
                    case 8 + 9 * 16:
                    case 9 + 9 * 16:
                    case 10 + 9 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 6 + 10 * 16:
                    case 7 + 10 * 16:
                    case 8 + 10 * 16:
                    case 9 + 10 * 16:
                    case 10 + 10 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    case 8 + 8 * 16:
                        updateBlock({x, y + CHUNK_HEIGHT_MIN, z}, Blocks::OakLog::toProtocol(Blocks::OakLog::Properties::Axis::Y));
                        break;
                    }
                } else if (y == 9 || y == 10) {
                    switch (x + (z * 16)) {
                    case 8 + 7 * 16:
                    case 7 + 8 * 16:
                    case 9 + 8 * 16:
                    case 8 + 9 * 16:
                    case 8 + 8 * 16:
                        updateBlock(
                            {x, y + CHUNK_HEIGHT_MIN, z},
                            Blocks::OakLeaves::toProtocol(
                                Blocks::OakLeaves::Properties::Distance::ONE, Blocks::OakLeaves::Properties::Persistent::FALSE, Blocks::OakLeaves::Properties::Waterlogged::FALSE
                            )
                        );
                        break;
                    }
                }
            }
        }
    }
    _currentState = GenerationState::READY;
}

void ChunkColumn::_generateRawGeneration(generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    // generate blocks
    // for (int y = CHUNK_HEIGHT_MIN; y < CHUNK_HEIGHT_MAX; y++) {
    //     for (int z = 0; z < SECTION_WIDTH; z++) {
    //         for (int x = 0; x < SECTION_WIDTH; x++) {
    //             auto block = generator.getBlock(x + this->_chunkPos.x * SECTION_WIDTH, y, z + this->_chunkPos.z * SECTION_WIDTH);
    //             // if (block != Blocks::Air::toProtocol())
    //             updateBlock({x, y, z}, block);
    //         }
    //     }
    // }
    // generate bedrock
    for (int x = 0; x < SECTION_WIDTH; x++) {
        for (int z = 0; z < SECTION_WIDTH; z++) {
            updateBlock({x, 0 + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol()); // last bedrock layer
            for (int y = 1 + CHUNK_HEIGHT_MIN; y <= 4 + CHUNK_HEIGHT_MIN; y++) {
                Position pos = {x + this->_chunkPos.x * SECTION_WIDTH, y, z + this->_chunkPos.z * SECTION_WIDTH};
                generator.setRandomizer(pos);
                auto block = generator.getBlock(pos);
                if (generator.getRandomizer() != 0) {
                    if (block == Blocks::Air::toProtocol() || (abs(pos.x % 8) >= abs(pos.z % 4) && pos.y % 2 != 0)) {
                        if (abs(pos.x) % 3 != abs(pos.z % 5)) {
                            updateBlock({x, 1 + CHUNK_HEIGHT_MIN, z}, Blocks::Bedrock::toProtocol());
                            updateBlock({(x - 2) % SECTION_WIDTH, 1 + CHUNK_HEIGHT_MIN, (z + 1) % SECTION_WIDTH}, Blocks::Bedrock::toProtocol());
                        } else if ((abs(pos.z - x) % generator.getRandomizer() != 0 || abs(pos.x - z) % 2 != 0) && abs(pos.y) % 4 != abs(z - x) % 8 && pos.y % 2 == 0)
                            updateBlock({x, y, (z + 1) % SECTION_WIDTH}, Blocks::Bedrock::toProtocol());
                        if ((abs(pos.z) % 2 != 0 || abs(pos.x) % 2 != 0) || x == z) {
                            updateBlock({x, 2 + CHUNK_HEIGHT_MIN, (z + 1) % SECTION_WIDTH}, Blocks::Bedrock::toProtocol());
                        } else if ((abs(pos.z) != abs(pos.x) + x && abs(pos.z % 4) != z % 2) && pos.y % 2 != 0) {
                            updateBlock({(x + 5) % SECTION_WIDTH, 3 + CHUNK_HEIGHT_MIN, (z - 3) % SECTION_WIDTH}, Blocks::Bedrock::toProtocol());
                            updateBlock({x, y, (z + 2) % SECTION_WIDTH}, Blocks::Bedrock::toProtocol());
                        }
                    } else {
                        if (abs(pos.x) % 3 != 0 && (generator.getRandomizer() == z % 5 && abs(pos.z) % 3 == 2) && abs(pos.y) % 2 == 0)
                            updateBlock({x, y, z}, Blocks::Bedrock::toProtocol());
                    }
                }
            }
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
    std::lock_guard<std::mutex> _(this->_generationLock);
    int waterLevel = 86;

    // TODO: improve this to fill caves
    // generate water
    // for (int z = 0; z < SECTION_WIDTH; z++) {
    //     for (int x = 0; x < SECTION_WIDTH; x++) {
    //         for (int y = waterLevel; 0 < y; y--) {
    //             if (getBlock({x, y, z}) == 1)
    //                 break;
    //             updateBlock({x, y, z}, Blocks::Water::toProtocol(Blocks::Water::Properties::Level::ZERO));
    //         }
    //     }
    // }
    _currentState = GenerationState::LAKES;
}

void ChunkColumn::_generateLocalModifications(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
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
                    if (y - 1 >= CHUNK_HEIGHT_MIN)
                        updateBlock({x, y - 1, z}, Blocks::Dirt::toProtocol()); // dirt
                    if (y - 2 >= CHUNK_HEIGHT_MIN)
                        updateBlock({x, y - 2, z}, Blocks::Dirt::toProtocol()); // dirt
                    break;
                }
            }
        }
    }
    _currentState = GenerationState::LOCAL_MODIFICATIONS;
}

void ChunkColumn::_generateUndergroundStructures(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    _currentState = GenerationState::UNDERGROUND_STRUCTURES;
}

void ChunkColumn::_generateSurfaceStructures(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    _currentState = GenerationState::SURFACE_STRUCTURES;
}

void ChunkColumn::_generateStrongholds(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    _currentState = GenerationState::STRONGHOLDS;
}

void ChunkColumn::_generateUndergroundOres(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    OreVein oreVeins(*this, generator);
    oreVeins.generateBlobs();
    _currentState = GenerationState::UNDERGROUND_ORES;
}

void ChunkColumn::_generateUndergroundDecoration(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    _currentState = GenerationState::UNDERGROUND_DECORATION;
}

void ChunkColumn::_generateFluidSprings(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    _currentState = GenerationState::FLUID_SPRINGS;
}

void ChunkColumn::_generateVegetalDecoration(generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    // GET_NEIGHBOURS() // does not work for now (dead lock)
    generation::trees::OakTree oakTree(*this, generator);
    oakTree.getPosForTreeGeneration();
    while (!oakTree.filterTreeGrowSpace().empty())
        oakTree.generateTree(std::vector<world_storage::ChunkColumn *>());

    // Un-comment this for LE KAYOU & comment the 4 preceding lines

    // generation::trees::SpruceTree spruceTree(*this, generator);
    // spruceTree.getPosForTreeGeneration();
    // while (!spruceTree.filterTreeGrowSpace().empty())
    //     spruceTree.generateTree(std::vector<world_storage::ChunkColumn *>());
    //
    // ForestRock rock(*this, generator);
    // rock.getPosForRockGeneration();
    // while (!rock.filterRockOverlap().empty())
    //     rock.generateRock(std::vector<world_storage::ChunkColumn *>());

    // RELEASE_NEIGHBOURS()
    _currentState = GenerationState::VEGETAL_DECORATION;
}

void ChunkColumn::_generateTopLayerModification(UNUSED generation::Generator &generator)
{
    std::lock_guard<std::mutex> _(this->_generationLock);
    // GET_NEIGHBOURS()
    // RELEASE_NEIGHBOURS()
    _currentState = GenerationState::TOP_LAYER_MODIFICATION;
}

void ChunkColumn::processRandomTick(uint32_t rts)
{
    for (auto &section : _sections) {
        section.processRandomTick(rts, _chunkPos);
    }
}

} // namespace world_storage
