#include "Loot.hpp"
#include "Server.hpp"
#include "LootTables.hpp"

void command_parser::Loot::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
}

void command_parser::Loot::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2) {
        Server::getInstance()->lootTables.snitchTables();        
        return;
    }

    LootTablePoll loot;

    if (!Server::getInstance()->lootTables.exists(args[0], args[1])) {
        std::cout << "loot " << args[0] << ':' << args[1] << " noes not exist" << std::endl;
        Server::getInstance()->lootTables.snitchTables();
    }
    if (Server::getInstance()->lootTables.exists(args[0], args[1]) && Server::getInstance()->lootTables.poll(loot, args[0], args[1])) {
        for (const auto &item : loot) {
            std::cout << std::to_string(item.second) << " " << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item.first) << std::endl;
        }
    } else {
        std::cout << "failed to loot :(" << std::endl;
    }
}

void command_parser::Loot::help(std::vector<std::string> &args, Player *invoker) const
{
    LINFO("/help seed");
}
