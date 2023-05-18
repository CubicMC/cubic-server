#include "./Scoreboard.hpp"

#include "Server.hpp"
#include "WorldGroup.hpp"
#include "logging/Logger.hpp"

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
        std::cout << "in worldgroup " << name << ":" << std::endl;
        for (const auto &[objective, obj] : worldgroup->getScoreboard().getObjectives()) {
            std::cout << "\t" << objective << std::endl;
            for (const auto &[name, score] : obj->getScores()) {
                std::cout << "\t\t" << name << " " << score.get() << std::endl;
            }
        }
    }
}

void command_parser::Objectives::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void)invoker;
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
    (void)invoker;
    LINFO("help addobjective");
}

/*
    setobjective
*/
void command_parser::SetObjective::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete setobjective");
}

void command_parser::SetObjective::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 3)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        if (worldgroup->getScoreboard().isObjective(args[0]))
            worldgroup->getScoreboard().getObjective(args[0]).setScore(args[1], std::stoi(args[2]));
    }
}

void command_parser::SetObjective::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void)invoker;
    LINFO("help setobjective");
}

/*
    displayobjective
*/
void command_parser::DisplayObjective::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void)invoker;
    LINFO("help displayobjective");
}

void command_parser::DisplayObjective::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 2)
        return;
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        if (worldgroup->getScoreboard().isObjective(args[1]))
            worldgroup->getScoreboard().displayObjective(static_cast<Scoreboard::DisplaySlot>(std::stoi(args[0])), &worldgroup->getScoreboard().getObjective(args[1]));
        else
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
    (void)invoker;
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
        std::cout << "in worldgroup " << name << ":" << std::endl;
        for (const auto &[team, obj] : worldgroup->getScoreboard().getTeams()) {
            std::cout << "\t" << team << ":" << std::endl;
            for (const auto &player : obj->getMembers()) {
                std::cout << "\t\t" << player << std::endl;
            }
        }
    }
}

void command_parser::Teams::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void)invoker;
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
    for (auto &[_, worldgroup] : Server::getInstance()->getWorldGroups()) {
        worldgroup->getScoreboard().addTeam(args[0]);
    }
}

void command_parser::AddTeam::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    (void)invoker;
    LINFO("help jointeam");
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
    (void)invoker;
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
    (void)invoker;
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
    (void)invoker;
    LINFO("help removeteam");
}
