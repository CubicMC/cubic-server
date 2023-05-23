#include "Loot.hpp"
#include "Server.hpp"
#include "loot_tables/LootTables.hpp"
#include "loot_tables/context/Empty.hpp"

void command_parser::Loot::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const
{
}

void command_parser::Loot::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() != 2) {
        //        Server::getInstance()->getLootTableSystem().snitchTables();
        return;
    }

    if (!Server::getInstance()->getLootTableSystem().exists(args[0], args[1])) {
        std::cout << "loot " << args[0] << ':' << args[1] << " noes not exist" << std::endl;
        // Server::getInstance()->getLootTableSystem().snitchTables();
        return;
    }
    LootTable::LootTablePoll poll = Server::getInstance()->getLootTableSystem().get(args[0], args[1]).poll(nullptr);
    for (const auto &[item, count] : poll.getRolledItems()) {
        std::cout << std::to_string(count) << " " << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item) << std::endl;
    }
}

void command_parser::Loot::help(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const
{
    LINFO("/help seed");
}
