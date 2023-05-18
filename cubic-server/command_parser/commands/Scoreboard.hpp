#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_SCOREBOARD_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_SCOREBOARD_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Objectives : public CommandBase {
    Objectives():
        CommandBase("objectives", "/objectives", true)
    {
    }

    ~Objectives() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct AddObjective : public CommandBase {
    AddObjective():
        CommandBase("addobjective", "/addobjective", true)
    {
    }

    ~AddObjective() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct SetObjective : public CommandBase {
    SetObjective():
        CommandBase("setobjective", "/setobjective", true)
    {
    }

    ~SetObjective() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct DisplayObjective : public CommandBase {
    DisplayObjective():
        CommandBase("displayobjective", "/displayobjective", true)
    {
    }

    ~DisplayObjective() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct RemoveObjective : public CommandBase {
    RemoveObjective():
        CommandBase("removeobjective", "/removeobjective", true)
    {
    }

    ~RemoveObjective() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct Teams : public CommandBase {
    Teams():
        CommandBase("teams", "/teams", true)
    {
    }

    ~Teams() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct AddTeam : public CommandBase {
    AddTeam():
        CommandBase("addteam", "/addteam", true)
    {
    }

    ~AddTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct JoinTeam : public CommandBase {
    JoinTeam():
        CommandBase("jointeam", "/jointeam", true)
    {
    }

    ~JoinTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct LeaveTeam : public CommandBase {
    LeaveTeam():
        CommandBase("leaveteam", "/leaveteam", true)
    {
    }

    ~LeaveTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct RemoveTeam : public CommandBase {
    RemoveTeam():
        CommandBase("removeteam", "/removeteam", true)
    {
    }

    ~RemoveTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_SCOREBOARD_HPP
