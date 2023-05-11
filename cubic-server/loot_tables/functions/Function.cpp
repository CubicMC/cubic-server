#include "Server.hpp"

#include "Function.hpp"

namespace LootTable {
    namespace Function {
        Function::Function(const nlohmann::json &function)
        {
            // get conditions
            if (function.contains("conditions") && \
                function["conditions"].is_array()) {
                for (const auto &condition : function["conditions"]) {
                    std::unique_ptr<Condition::Condition> newCondition = Server::getInstance()->lootTables.createCondition(condition);

                    const auto &it = this->_conditions.insert(this->_conditions.end(), nullptr);
                    it->swap(newCondition);
                }
            }
        };
        
        NoFunctionContructor::NoFunctionContructor(const nlohmann::json &function) : _message("No constructor fitting the function: " + function.dump())
        {}

        const char *NoFunctionContructor::what() const noexcept
        {
            return (this->_message.c_str());
        }
    };
};