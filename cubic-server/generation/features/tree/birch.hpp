#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_BIRCH_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_BIRCH_HPP

#include "generation/generator.hpp"
#include "tree.hpp"

namespace generation::trees {
class BirchTree : public Tree {
public:
    BirchTree(world_storage::ChunkColumn &chunk, generation::Generator &generator):
        Tree(chunk, generator)
    {
    }

    std::deque<Position> &getPosForTreeGeneration() override;
    std::deque<Position> &filterTreeGrowSpace() override;
    void generateTree(std::vector<world_storage::ChunkColumn *>) override;

private:
    const std::vector<Generator::FeatureBlock> getTree(const Position &pos) const override;
    const std::vector<Generator::FeatureBlock> getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const override;
    generation::Generator::TreeSize _treeSize = {5, 7};
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_BIRCH_HPP
