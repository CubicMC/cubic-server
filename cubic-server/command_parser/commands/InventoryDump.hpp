#ifndef INVENTORY_DUMP_COMMAND_HPP
#define INVENTORY_DUMP_COMMAND_HPP

#include "CommandBase.hpp"
#include "Player.hpp"
#include "logging/logging.hpp"

namespace command_parser {

class InventoryDump : public CommandBase {
public:
    InventoryDump():
        CommandBase("inventorydump", "/inventorydump (entity)", true)
    {
    }

    inline void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    inline void execute(std::vector<std::string> &args, Player *invoker) const override;
    inline void help(std::vector<std::string> &args, Player *invoker) const override;
};

} // namespace command_parser

inline void command_parser::InventoryDump::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

inline void command_parser::InventoryDump::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker) {
        LINFO("J'ai la flemme de chercher un joueur");
        return;
    }
    auto inventory = invoker->getInventory();
    for (uint64_t i = 0; i < inventory->size(); ++i) {
        LINFO("Item[{}]: {} {} x{}", i, inventory->at(i).present, inventory->at(i).itemID, inventory->at(i).itemCount);
    }
}

inline void command_parser::InventoryDump::help(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

#endif // INVENTORY_DUMP_COMMAND_HPP
