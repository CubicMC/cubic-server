#ifndef CHUNK_DUMP_TEST_COMMAND_HPP
#define CHUNK_DUMP_TEST_COMMAND_HPP

#include "CommandBase.hpp"

namespace command_parser {
    struct DumpChunk : public CommandBase {
        DumpChunk(): CommandBase("dumpChunk", "/dumpChunk <x> <z> (dumpChunk)") {}

        void autocomplete(std::vector<std::string>& args) const override;
        void execute(std::vector<std::string>& args) const override;
        void help(std::vector<std::string>& args) const override;
    };
}

#endif // CHUNK_DUMP_TEST_COMMAND_HPP
