#ifndef A5E95914_3DC3_4AC3_A2FB_9A3E3E2CB929
#define A5E95914_3DC3_4AC3_A2FB_9A3E3E2CB929

#include "CommandBase.hpp"

namespace command_parser {
struct Teleport : public CommandBase {
    Teleport():
        CommandBase("teleport", "/teleport", true)
    {
    }

    ~Teleport() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct Tp : public CommandBase {
    Tp():
        CommandBase("tp", "/tp", true)
    {
    }

    ~Tp() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif /* A5E95914_3DC3_4AC3_A2FB_9A3E3E2CB929 */
