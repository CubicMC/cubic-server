#include "Vegetation.hpp"

#include <vector>

#include "blocks.hpp"
#include "generation/generator.hpp"
#include "logging/logging.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"

std::deque<Position> &Vegetation::getPositions(void)
{
    using namespace world_storage;
    for (int z = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); z < SECTION_WIDTH; z++) {
        for (int x = utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 2); x < SECTION_WIDTH; x++) {
            for (int y = CHUNK_HEIGHT_MAX - 5; CHUNK_HEIGHT_MIN <= y; y--) {
                auto block = _chunk.getBlock({x, y, z});
                if (block == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE)) {
                    if (_generator.getBiome(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH) == 0 &&
                        _generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise2D.continentalness >= 0.8 &&
                        _generator.getNoise(x + _chunk.getChunkPos().x * SECTION_WIDTH, y, z + _chunk.getChunkPos().z * SECTION_WIDTH).noise3D.density >= 0) {
                        // LINFO("vegetation here {}.{}.{}", x, y + 1, z);
                        _positions.emplace_back(x, y + 1, z);
                        x += (SECTION_WIDTH - x % SECTION_WIDTH) - utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 4);
                        z += (SECTION_WIDTH - z % SECTION_WIDTH) - utility::PseudoRandomGenerator::getInstance()->generateNumber(0, SECTION_WIDTH / 4);
                    }
                }
                // break;
            }
        }
    }
    return _positions;
}

void Vegetation::generateVegetation(std::vector<world_storage::ChunkColumn *>)
{
    const auto &VegetationEmplacement = _positions.front();
    _generator.setRandomizer(VegetationEmplacement);
    auto Vegetation = getVegetation(VegetationEmplacement);
    for (const auto &block : Vegetation) {
        // auto bottomBlock = _chunk.getBlock({VegetationEmplacement.x, VegetationEmplacement.y - 1, VegetationEmplacement.z});
        // auto topBlock = _chunk.getBlock({VegetationEmplacement.x, VegetationEmplacement.y + 1, VegetationEmplacement.z});
        // if (bottomBlock == Blocks::GrassBlock::toProtocol(Blocks::GrassBlock::Properties::Snowy::FALSE) && topBlock == Blocks::Air::toProtocol()) {
            _chunk.updateBlock({VegetationEmplacement.x + block.pos.x, VegetationEmplacement.y + block.pos.y, VegetationEmplacement.z + block.pos.z}, block.block);
        // }
    }
    _positions.pop_front();
}

void Vegetation::placeGrass(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    for (int countX = 0; countX <= world_storage::SECTION_WIDTH; countX++) {
        for (int countZ = 0; countZ <= world_storage::SECTION_WIDTH; countZ++) {
            if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH)
                    .noise2D.grass >= 0.4) {
                // LINFO("Grass");
                listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {{countX, 0, countZ}, Blocks::Grass::toProtocol()});
            }
        }
    }
}

void Vegetation::placePoppies(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    for (int countX = 0; countX <= world_storage::SECTION_WIDTH; countX++) {
        for (int countZ = 0; countZ <= world_storage::SECTION_WIDTH; countZ++) {
            if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH)
                    .noise2D.flowers >= 0.2) {
                // LERROR("Poppy");
                listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {{countX, 0, countZ}, Blocks::Poppy::toProtocol()});
                break;
            }
        }
    }
}

void Vegetation::placeDandelions(std::vector<generation::Generator::FeatureBlock> &listOfFeatureBlocks, const Position &pos) const
{
    for (int countX = 0; countX <= world_storage::SECTION_WIDTH; countX++) {
        for (int countZ = 0; countZ <= world_storage::SECTION_WIDTH; countZ++) {
            if (_generator.getNoise(pos.x + _chunk.getChunkPos().x * world_storage::SECTION_WIDTH, pos.y, pos.z + _chunk.getChunkPos().z * world_storage::SECTION_WIDTH)
                    .noise2D.flowers <= -0.5) {
                // LWARN("Dandelion");
                listOfFeatureBlocks.emplace_back(generation::Generator::FeatureBlock {{countX, 0, countZ}, Blocks::Dandelion::toProtocol()});
                break;
            }
        }
    }
}

const std::vector<generation::Generator::FeatureBlock> Vegetation::getVegetation(const Position &pos) const
{
    std::vector<generation::Generator::FeatureBlock> listOfFeatureBlocks;

    if (_generator.getRandomizer() >= 3) {
        placePoppies(listOfFeatureBlocks, pos);
    } else {
        placeDandelions(listOfFeatureBlocks, pos);
    }
    placeGrass(listOfFeatureBlocks, pos);
    return listOfFeatureBlocks;
}
