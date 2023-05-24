#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_RELOAD_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_RELOAD_HPP

#include "CommandBase.hpp"

/*
**  Reload command always success and displays
**  "Successfully reloaded loot tables, advancements
**  and functions".
**
**  If one of the reloaded file contain an error,
**  the file is skipped and the last working version
**  of the file is loaded instead.
**  If no file was loaded before, the file containing
**  the error is skipped without being replaced.
**
**  The command is supposed to reload the server
**  without stopping it nor affecting the players
**  except if the whitelist is to be enforced.
**
**  Files to be reloaded:
**
**   - config.yml
**   - whitelist.txt
**   - .minecraft/saves/(world)/datapacks
**   - plugins
*/

namespace command_parser {
struct Reload : public CommandBase {
    Reload():
        CommandBase("reload", "/reload", true)
    {
    }

    ~Reload() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_RELOAD_HPP
