#ifndef CUBICSERVER_GENERATION_FEATURES_TREE_PINE_HPP
#define CUBICSERVER_GENERATION_FEATURES_TREE_PINE_HPP

#include "generation/generator.hpp"
#include "tree.hpp"

constexpr int MAX_SIZE_LEAVES_LAYER_PINE = 3;

namespace generation::trees {
class PineTree : public Tree {
public:
    PineTree(world_storage::ChunkColumn &chunk, generation::Generator &generator):
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
    const void topLayers(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf) const;
    const void layerWithoutCorner(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log, int layerSize) const;
    const void makeLongPine(std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;
    const void makeMushroomPine(const int treeSize, std::vector<generation::Generator::TreeBlock> &tree, int y, const BlockId &leaf, const BlockId &log) const;

    generation::Generator::TreeSize _treeSize = {6, 10};
};
} // namespace generation::trees

#endif // CUBICSERVER_GENERATION_FEATURES_TREE_PINE_HPP