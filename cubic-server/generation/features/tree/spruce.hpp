#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_SPRUCE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_SPRUCE_HPP

#include "generation/generator.hpp"
#include "tree.hpp"

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
    const std::vector<Generator::TreeBlock> getTree(const Position &pos) const override;
    const std::vector<Generator::TreeBlock> getTree(Generator::positionType x, Generator::positionType y, Generator::positionType z) const override;

    const void buildTree(const int treeSize, std::vector<generation::Generator::TreeBlock> &tree, const BlockId &leaf, const BlockId &log) const;
    const void bigLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    const void biggerLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    const void starLayer(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    const void topStarLayers(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    const void repetitivePattern(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log, int treeSize) const;
    const void bottomLeaves(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;

    generation::Generator::TreeSize _treeSize = {5, 9};
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_SPRUCE_HPP