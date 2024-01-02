#include <memory>
#include <vector>

#include "Player.hpp"
#include "entities/Entity.hpp"
#include "selectors.hpp"

void fillSelector(
    const std::string &selector, std::vector<std::reference_wrapper<Entity>> &out, const std::vector<std::shared_ptr<Entity>> &entities,
    const std::vector<std::shared_ptr<Player>> &players, Player *invoker
)
{
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    if (!isSelector(selector))
        return;
    if (isInvokerRequiredSelector(selector) && !invoker)
        return; // TODO(huntears): Error message

    if (selector == "@a") {
        for (auto &player : players)
            out.push_back(*player);
    } else if (selector == "@s") {
        out.push_back(*invoker);
    } else if (selector == "@p") {
        out.push_back(*invoker); // TODO(huntears): When command blocks are implemented this needs to change
    } else if (selector == "@r") {
        if (players.size() == 0)
            return;
        std::uniform_int_distribution<uint64_t> dis(0, players.size() - 1);
        out.push_back(*players.at(dis(gen)));
        // TODO
    } else if (selector == "@e") {
        for (auto &entity : entities)
            out.push_back(*entity);
    }
}

void fillSingleSelector(
    const std::string &selector, Entity &out, UNUSED const std::vector<std::shared_ptr<Entity>> &entities, const std::vector<std::shared_ptr<Player>> &players, Player *invoker
)
{
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    if (!isSingleSelector(selector))
        return;
    if (isInvokerRequiredSelector(selector) && !invoker)
        return; // TODO(huntears): Error message

    if (selector == "@s") {
        out = *invoker;
    } else if (selector == "@p") {
        out = *invoker; // TODO(huntears): When command blocks are implemented this needs to change
    } else if (selector == "@r") {
        if (players.size() == 0)
            return;
        std::uniform_int_distribution<uint64_t> dis(0, players.size() - 1);
        out = *players.at(dis(gen));
    }
}
