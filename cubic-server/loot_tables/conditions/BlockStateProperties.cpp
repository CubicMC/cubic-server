#include "BlockStateProperties.hpp"

namespace LootTable {
    namespace Condition {
        BlockStateProperties::BlockStateProperties(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool BlockStateProperties::verify(void)
        {
            return (true);
        }

        std::unique_ptr<Condition> BlockStateProperties::create(const nlohmann::json &condition)
        {
            return (std::make_unique<BlockStateProperties>(condition));
        }
    };
};