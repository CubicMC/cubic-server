#include "Vegetation.hpp"

#include <vector>

#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "types.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

std::deque<Position> &Vegetation::getPositions(void)
{
    using namespace world_storage;
    for (int y = CHUNK_HEIGHT_MAX - 5; CHUNK_HEIGHT_MIN <= y; y--) {
        for (int z = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); z < SECTION_WIDTH; z++) {
            auto spawnTries = utility::PseudoRandomGenerator::getInstance()->generateNumber(SECTION_WIDTH / 2, SECTION_WIDTH);
            for (int x = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); x < SECTION_WIDTH; x++) {
                auto block = _chunk.getBlock({x, y, z});
                if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE)) {
                    if (_generator.getBiome(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH) == 0 && spawnTries > 0) {
                        _positions.emplace_back(x, y + 1, z);
                        spawnTries--;
                        if (x < z)
                            x = x + utility::PseudoRandomGenerator::getInstance()->generateNumber(1, SECTION_WIDTH / 2) % SECTION_WIDTH;
                        else
                            z = z + utility::PseudoRandomGenerator::getInstance()->generateNumber(1, SECTION_WIDTH / 2) % SECTION_WIDTH;
                    }
                }
            }
        }
    }
    return _positions;
}

void Vegetation::generateVegetation(std::vector<world_storage::ChunkColumn *>)
{
    while (!_positions.empty()) {
        const auto &VegetationEmplacement = _positions.front();
        _generator.setRandomizer(VegetationEmplacement);
        auto randomizer = _generator.getRandomizer();
        auto Vegetation = getVegetation(VegetationEmplacement);
        for (const auto &block : Vegetation) {
            auto blockID = _chunk.getBlock(VegetationEmplacement);
            if (blockID == Blocks::Air::toProtocol() || (blockID != Blocks::TallGrass::toProtocol(Blocks::TallGrass::Properties::Half::LOWER) && randomizer >= 3)) {
                _chunk.modifyBlock({block.pos.x, block.pos.y, block.pos.z}, block.block);
            } else if (block.block == Blocks::TallGrass::toProtocol(Blocks::TallGrass::Properties::Half::UPPER) && blockID == Blocks::TallGrass::toProtocol(Blocks::TallGrass::Properties::Half::LOWER)) {
                _chunk.modifyBlock({block.pos.x, block.pos.y, block.pos.z}, block.block);
            }
        }
        _positions.pop_front();
    }
}

void Vegetation::placeGrass(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    // Grass noise under -0.6 so the other values of the noise map can be used for the tall grass (fewer tall grass than normal grass)
    if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH).noise2D.grass >=
        -0.6) {
        listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {pos, Blocks::Grass::toProtocol()});
    } else {
        listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {pos, Blocks::TallGrass::toProtocol(Blocks::TallGrass::Properties::Half::LOWER)});
        listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {{pos.x, pos.y + 1, pos.z}, Blocks::TallGrass::toProtocol(Blocks::TallGrass::Properties::Half::UPPER)}
        );
    }
}

void Vegetation::placePoppies(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    // Flowers noise over 0.2 so the other values of the noise map can be used for the dandelions (and other flowers)
    if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH).noise2D.flowers >
        0.2) {
        listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {pos, Blocks::Poppy::toProtocol()});
    }
}

void Vegetation::placeDandelions(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    // Flowers noise under -0.5 so the other values of the noise map can be used for the poppies (and other flowers)
    if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH).noise2D.flowers <=
        -0.5) {
        listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {pos, Blocks::Dandelion::toProtocol()});
    }
}

void Vegetation::placeOxeyeDaisies(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    // Flowers noise under 0.2 so the other values of the noise map can be used for the poppies and dandelions
    if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH).noise2D.flowers <=
        0.2) {
        listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {pos, Blocks::OxeyeDaisy::toProtocol()});
    }
}

const std::vector<generation::Generator::FeatureBlock> Vegetation::getVegetation(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> listOfFeatureBlocks;

    placeGrass(listOfFeatureBlocks, pos);
    placePoppies(listOfFeatureBlocks, pos);
    placeDandelions(listOfFeatureBlocks, pos);

    return listOfFeatureBlocks;
}
