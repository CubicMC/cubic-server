#ifndef AE79D862_ED99_4B26_9439_AB07465774BB
#define AE79D862_ED99_4B26_9439_AB07465774BB

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

static const std::array<std::string, 3> SINGLE_SELECTOR = {"@r", "@s", "@p"};
static const std::array<std::string, 2> MULTIPLE_SELECTOR = {"@a", "@e"};
static const std::array<std::string, 2> INVOKER_REQUIRED_SELECTOR = {"@s", "@p"};

constexpr bool isMultipleSelector(const std::string &str) { return std::find(MULTIPLE_SELECTOR.begin(), MULTIPLE_SELECTOR.end(), str) != MULTIPLE_SELECTOR.end(); }

constexpr bool isSingleSelector(const std::string &str) { return std::find(SINGLE_SELECTOR.begin(), SINGLE_SELECTOR.end(), str) != SINGLE_SELECTOR.end(); }

constexpr bool isInvokerRequiredSelector(const std::string &str)
{
    return std::find(INVOKER_REQUIRED_SELECTOR.begin(), INVOKER_REQUIRED_SELECTOR.end(), str) != INVOKER_REQUIRED_SELECTOR.end();
}

constexpr bool isSelector(const std::string &str) { return isMultipleSelector(str) || isSingleSelector(str); }

class Entity;

class Player;

void fillSingleSelector(
    const std::string &selector, Entity &out, const std::vector<std::shared_ptr<Entity>> &entities, const std::vector<std::shared_ptr<Player>> &players, Player *invoker = nullptr
);

void fillSelector(
    const std::string &selector, std::vector<std::reference_wrapper<Entity>> &out, const std::vector<std::shared_ptr<Entity>> &entities,
    const std::vector<std::shared_ptr<Player>> &players, Player *invoker = nullptr
);

#endif /* AE79D862_ED99_4B26_9439_AB07465774BB */
