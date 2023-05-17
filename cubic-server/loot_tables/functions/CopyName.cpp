#include "CopyName.hpp"

namespace LootTable {
    namespace Function {
        CopyName::CopyName(const nlohmann::json &function):
            Function(function)
        {
            this->setValidity(true);
        }

        void CopyName::apply(void)
        {}

        std::unique_ptr<Function> CopyName::create(const nlohmann::json &function)
        {
            return (std::make_unique<CopyName>(function));
        }
    };
};