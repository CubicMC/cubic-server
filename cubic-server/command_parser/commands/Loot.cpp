#include "Loot.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "loot_tables/LootTables.hpp"
#include "loot_tables/context/Empty.hpp"

void command_parser::Loot::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void command_parser::Loot::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() != 2) {
        //        Server::getInstance()->getLootTableSystem().snitchTables();
        return;
    }

    if (!Server::getInstance()->getLootTableSystem().exists(args[0], args[1])) {
        LWARN("loot {} :{} does not exist", args[0], args[1]);
        // Server::getInstance()->getLootTableSystem().snitchTables();
        return;
    }
    LootTable::LootTablePoll poll = Server::getInstance()->getLootTableSystem().get(args[0], args[1]).poll(nullptr);
    for (const auto &[item, count] : poll.getRolledItems()) {
        LINFO("{} {}", std::to_string(count), Server::getInstance()->getItemConverter().fromProtocolIdToItem(item));
    }
}

void command_parser::Loot::help(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { LINFO(this->_help); }
