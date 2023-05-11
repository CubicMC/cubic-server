#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETBANNERPATTERN_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETBANNERPATTERN_HPP

#include "Function.hpp"

namespace LootTable {
    namespace Function {
        class SetBannerPattern : public Function {
        public:
            SetBannerPattern(const nlohmann::json &function);
            ~SetBannerPattern() = default;

            void apply(void) override;

            static std::unique_ptr<Function> create(const nlohmann::json &function);
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_SETBANNERPATTERN_HPP
