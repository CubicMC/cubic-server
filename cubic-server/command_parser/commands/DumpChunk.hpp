#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_DUMPCHUNK_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_DUMPCHUNK_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct DumpChunk : public CommandBase {
    DumpChunk():
        CommandBase("dumpChunk", "/dumpChunk <x> <z> (dumpChunk)", false)
    {
    }
    ~DumpChunk() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_DUMPCHUNK_HPP
