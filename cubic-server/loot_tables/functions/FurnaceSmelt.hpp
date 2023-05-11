#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FURNACESMELT_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FURNACESMELT_HPP

#include "Function.hpp"

namespace LootTable {
    namespace Function {
        class FurnaceSmelt : public Function {
        public:
            FurnaceSmelt(const nlohmann::json &function);
            ~FurnaceSmelt() = default;

            void apply(void) override;

            static std::unique_ptr<Function> create(const nlohmann::json &function);
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FURNACESMELT_HPP
