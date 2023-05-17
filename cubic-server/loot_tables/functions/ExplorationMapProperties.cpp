#include "ExplorationMapProperties.hpp"

namespace LootTable {
    namespace Function {
        ExplorationMapProperties::ExplorationMapProperties(const nlohmann::json &function):
            Function(function)
        {
            this->setValidity(true);
        }

        void ExplorationMapProperties::apply(void)
        {}

        std::unique_ptr<Function> ExplorationMapProperties::create(const nlohmann::json &function)
        {
            return (std::make_unique<ExplorationMapProperties>(function));
        }
    };
};