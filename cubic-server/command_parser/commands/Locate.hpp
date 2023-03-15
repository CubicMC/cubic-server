#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_LOCATE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_LOCATE_HPP

#include "CommandBase.hpp"

struct Info {
    int mc;
    int dim;
    uint32_t flags;
    uint64_t seed;
    uint64_t sha;
};

struct Pos {
    int x, z;
};

struct StructureIter {
    Pos pos;        // accurate location of current structure
    Pos nextapprox; // approxmimate location (+/-112 blocks) of next structure
    int index;      // structure index counter
    int ringnum;    // ring number for index
    int ringmax;    // max index within ring
    int ringidx;    // index within ring
    double angle;   // next angle within ring
    double dist;    // next distance from origin (in chunks)
    uint64_t rnds;  // random number seed (48 bit)
    int mc;         // minecraft version
};

namespace command_parser {
struct Locate : public CommandBase {
    Locate() : CommandBase("locate", "/locate structure <structure>", false) {}

    void autocomplete(std::vector<std::string>& args, Player *invoker) const override;
    void execute(std::vector<std::string>& args, Player *invoker) const override;
    void help(std::vector<std::string>& args, Player *invoker) const override;
};
}

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_LOCATE_HPP