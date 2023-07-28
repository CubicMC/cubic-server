#include "./Scoreboard.hpp"

#include "Server.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"

/*
    objectives
*/
void command_parser::Objectives::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete addobjective");
}

void command_parser::Objectives::execute(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const
{
    for (auto &[name, worldgroup] : Server::getInstance()->getWorldGroups()) {
        LINFO("in worldgroup {}:", name);
        for (const auto &[objective, obj] : worldgroup->getScoreboard().getObjectives()) {
            LINFO("\t{}", objective);
            for (const auto &[name, score] : obj->getScores()) {
                LINFO("\t\t{} {}", name, score.get());
            }
        }
    }
}

void command_parser::Objectives::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help addobjective");
}

/*
    addobjective
*/
void command_parser::AddObjective::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete addobjective");
}

void command_parser::AddObjective::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().addObjective(args[0], "dummy");
    }
}

void command_parser::AddObjective::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help addobjective");
}

/*
    setscore
*/
void command_parser::SetScore::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete setscore");
}

void command_parser::SetScore::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 3)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        if (worldgroup->getScoreboard().isObjective(args[0]))
            worldgroup->getScoreboard().getObjective(args[0]).setScore(args[1], std::stoi(args[2]));
    }
}

void command_parser::SetScore::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help setscore");
}

/*
    removescore
*/
void command_parser::RemoveScore::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete removescore");
}

void command_parser::RemoveScore::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 2)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        if (worldgroup->getScoreboard().isObjective(args[0]))
            worldgroup->getScoreboard().getObjective(args[0]).deleteScore(args[1]);
    }
}

void command_parser::RemoveScore::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help removescore");
}

/*
    displayobjective
*/
void command_parser::DisplayObjective::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help displayobjective");
}

void command_parser::DisplayObjective::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 1)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        if (args.size() > 1) {
            if (worldgroup->getScoreboard().isObjective(args[1]))
                worldgroup->getScoreboard().displayObjective(static_cast<Scoreboard::DisplaySlot>(std::stoi(args[0])), &worldgroup->getScoreboard().getObjective(args[1]));
            else
                LINFO("no objetive \"{}\"", args[1]);
        } else
            worldgroup->getScoreboard().displayObjective(static_cast<Scoreboard::DisplaySlot>(std::stoi(args[0])), nullptr);
    }
}

void command_parser::DisplayObjective::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete displayobjective");
}

/*
    removeobjective
*/
void command_parser::RemoveObjective::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete removeobjective");
}

void command_parser::RemoveObjective::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().removeObjective(args[0]);
    }
}

void command_parser::RemoveObjective::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help removeobjective");
}

/*
    teams
*/
void command_parser::Teams::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete addobjective");
}

void command_parser::Teams::execute(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const
{
    for (auto &[name, worldgroup] : Server::getInstance()->getWorldGroups()) {
        LINFO("in worldgroup {}:", name);
        for (const auto &[team, obj] : worldgroup->getScoreboard().getTeams()) {
            LINFO("\t{}:", team);
            for (const auto &player : obj->getMembers()) {
                LINFO("\t\t{}", player);
            }
        }
    }
}

void command_parser::Teams::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help addobjective");
}

/*
    addteam
*/
void command_parser::AddTeam::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete addteam");
}

void command_parser::AddTeam::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 1)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().addTeam(args[0], static_cast<Scoreboard::Team::Color>(rand() % 21));
    }
}

void command_parser::AddTeam::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help jointeam");
}

/*
    addteam
*/
void command_parser::ModifyTeam::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete modifyteam");
}

void command_parser::ModifyTeam::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 2)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        if (worldgroup->getScoreboard().isTeam(args[0]))
            worldgroup->getScoreboard().getTeam(args[0]).setColor(static_cast<Scoreboard::Team::Color>(std::stoi(args[1])));
    }
}

void command_parser::ModifyTeam::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help modifyteam");
}

/*
    jointeam
*/
void command_parser::JoinTeam::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete jointeam");
}

void command_parser::JoinTeam::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 2)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().getTeam(args[0]).addMember(args[1]);
    }
}

void command_parser::JoinTeam::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help jointeam");
}

/*
    leaveteam
*/
void command_parser::LeaveTeam::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete leaveteam");
}

void command_parser::LeaveTeam::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 2)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().getTeam(args[0]).removeMember(args[1]);
    }
}

void command_parser::LeaveTeam::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help leaveteam");
}

/*
    removeteam
*/
void command_parser::RemoveTeam::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete removeteam");
}

void command_parser::RemoveTeam::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 1)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().removeTeam(args[0]);
    }
}

void command_parser::RemoveTeam::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void) invoker;
    LINFO("help removeteam");
}
