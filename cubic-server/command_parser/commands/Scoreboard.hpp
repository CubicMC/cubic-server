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
        CommandBase("addobjective", "/addobjective [objective name]", true)
    {
    }

    ~AddObjective() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct SetScore : public CommandBase {
    SetScore():
        CommandBase("setscore", "/setscore [objective name] [player name] [score]", true)
    {
    }

    ~SetScore() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct RemoveScore : public CommandBase {
    RemoveScore():
        CommandBase("removescore", "/removescore [objective name] [player name]", true)
    {
    }

    ~RemoveScore() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct DisplayObjective : public CommandBase {
    DisplayObjective():
        CommandBase("displayobjective", "/displayobjective [slot] [objective name]", true)
    {
    }

    ~DisplayObjective() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct RemoveObjective : public CommandBase {
    RemoveObjective():
        CommandBase("removeobjective", "/removeobjective [objective name]", true)
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
        CommandBase("addteam", "/addteam [team name]", true)
    {
    }

    ~AddTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct ModifyTeam : public CommandBase {
    ModifyTeam():
        CommandBase("modifyteam", "/modifyteam [team name] [color(1..18)]", true)
    {
    }

    ~ModifyTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct JoinTeam : public CommandBase {
    JoinTeam():
        CommandBase("jointeam", "/jointeam [team name] [player name]", true)
    {
    }

    ~JoinTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct LeaveTeam : public CommandBase {
    LeaveTeam():
        CommandBase("leaveteam", "/leaveteam [team name] [player name]", true)
    {
    }

    ~LeaveTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};

struct RemoveTeam : public CommandBase {
    RemoveTeam():
        CommandBase("removeteam", "/removeteam [team name]", true)
    {
    }

    ~RemoveTeam() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_SCOREBOARD_HPP
