#include "Loot.hpp"
#include "Server.hpp"
#include "loot_tables/LootTables.hpp"
#include "loot_tables/context/Empty.hpp"

void command_parser::Loot::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    (void) args;
}

void command_parser::Loot::execute(std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    if (args.size() != 2) {
        //        Server::getInstance()->lootTables.snitchTables();
        return;
    }

    if (!Server::getInstance()->lootTables.exists(args[0], args[1])) {
        std::cout << "loot " << args[0] << ':' << args[1] << " noes not exist" << std::endl;
        // Server::getInstance()->lootTables.snitchTables();
        return;
    }
    LootTable::LootTablePoll poll = Server::getInstance()->lootTables.get(args[0], args[1]).poll(nullptr);
    for (const auto &[item, count] : poll.getRolledItems()) {
        std::cout << std::to_string(count) << " " << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item) << std::endl;
    }
}

void command_parser::Loot::help(std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    (void) args;
    LINFO("/help seed");
}
