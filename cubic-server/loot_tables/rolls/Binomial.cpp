#include "Server.hpp"

#include "Binomial.hpp"

namespace LootTable {
    namespace Roll {
        Binomial::Binomial(const nlohmann::json &roll)
        {
            this->_n = roll["n"].get<nlohmann::json::number_integer_t>();
            this->_p = roll["p"].get<nlohmann::json::number_float_t>();
        }

        const RollResult Binomial::poll(void)
        {
            return (RollResult(this->_n, this->_p));
        }

        std::unique_ptr<Roll> Binomial::creator(const nlohmann::json &roll)
        {
            return (std::make_unique<Binomial>(roll));
        }

        bool Binomial::isOfType(const nlohmann::json &roll)
        {
            return (
                roll.is_object() && \
                roll.contains("n") && \
                roll.contains("p") && \
                roll["p"].is_number_unsigned() && \
                roll["n"].is_number_unsigned()
            );
        }
    };
};