#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_SPRUCE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_SPRUCE_HPP

#include "generation/generator.hpp"
#include "tree.hpp"

constexpr int MAX_SIZE_LEAVES_LAYER_SPRUCE = 3;

namespace generation::trees {
class SpruceTree : public Tree {
public:
    SpruceTree(world_storage::ChunkColumn &chunk, generation::Generator &generator):
        Tree(chunk, generator)
    {
    }

    std::deque<Position> &getPosForTreeGeneration() override;
    std::deque<Position> &filterTreeGrowSpace() override;
    void generateTree(std::vector<world_storage::ChunkColumn *>) override;

private:
    const std::vector<Generator::FeatureBlock> getTree(const Position &pos) const override;
    const std::vector<Generator::FeatureBlock> getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const override;

    void buildTree(const int treeSize, std::vector<generation::Generator::FeatureBlock> &tree, const BlockId &leaf, const BlockId &log) const;
    void bigLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    void biggerLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    void starLayer(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    void topStarLayers(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    void repetitivePattern(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log, int treeSize) const;
    void bottomLeaves(std::vector<generation::Generator::FeatureBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;

    generation::Generator::TreeSize _treeSize = {5, 9};
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_SPRUCE_HPP
