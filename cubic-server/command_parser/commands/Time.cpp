#include "Time.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"

using namespace command_parser;

void Time::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete time");
}

int setTimeFromArg(std::string value, int multiplier)
{
    int time = 0;
    try {
        if (value.back() == 'd' || value.back() == 's' || value.back() == 't')
            value.pop_back();
        time = std::stod(value) * multiplier;
        return time;
    } catch (const std::exception &e) {
        LERROR("Not a number");
        return -1;
    }
}

int setMultiplier(char arg)
{
    if (arg == 'd') {
        return 24000;
    } else if (arg == 's') {
        return 20;
    } else if (arg == 't') {
        return 1;
    }
    return -1;
}

int setTimeToAdd(std::string timeToAdd)
{
    int time = 0;
    if (std::find_if(timeToAdd.begin(), timeToAdd.end(), [](unsigned char c) {
            return !std::isdigit(c);
        }) == timeToAdd.end())
        time = setTimeFromArg(timeToAdd, 1);
    else {
        if (timeToAdd.back() == 'd' || timeToAdd.back() == 's' || timeToAdd.back() == 't') {
            time = setTimeFromArg(timeToAdd, setMultiplier(timeToAdd.back()));
            return time;
        }
        LERROR("Usage : /time <add|query|set> (arg)");
        return -1;
    }
    return time;
}

int setTimeToSet(std::string timeToSet)
{
    int time = 0;
    if (std::find_if(timeToSet.begin(), timeToSet.end(), [](unsigned char c) {
            return !std::isdigit(c);
        }) == timeToSet.end())
        time = setTimeFromArg(timeToSet, 1);
    else if (timeToSet == "day")
        time = 1000;
    else if (timeToSet == "night")
        time = 13000;
    else if (timeToSet == "noon")
        time = 6000;
    else if (timeToSet == "midnight")
        time = 18000;
    else {
        if (timeToSet.back() == 'd' || timeToSet.back() == 's' || (timeToSet.back() == 't' && timeToSet != "midnight" && timeToSet != "night")) {
            time = setTimeFromArg(timeToSet, setMultiplier(timeToSet.back()));
            return time;
        }
        LERROR("Usage : /time <add|query|set> (arg)");
        return -1;
    }
    return time;
}

void checkArgsTime(std::vector<std::string> &args)
{
    int time = 0;
    if (args[0] == "add") {
        time = setTimeToAdd(args[1]);
        if (time != -1) {
            int added = Server::getInstance()->getWorldGroup("default")->getWorld("default")->addTime(time);
            LINFO("Set the time to " << added);
            // invoker->sendPlayerChatMessage("Set the time to " << added);
        }
    } else if (args[0] == "set") {
        time = setTimeToSet(args[1]);
        if (time != -1) {
            Server::getInstance()->getWorldGroup("default")->getWorld("default")->setTime(time);
            LINFO("Set the time to " << time);
            // invoker->sendPlayerChatMessage("Set the time to " << time);
        }
    } else if (args[0] == "query") {
        if (args[1] == "daytime")
            time = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getTime() % 24000;
        else if (args[1] == "gametime")
            time = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getAge() % INT_MAX;
        else if (args[1] == "day")
            time = (Server::getInstance()->getWorldGroup("default")->getWorld("default")->getTime() / 24000) % INT_MAX;
        else {
            LERROR("Usage : /time <add|query|set> (arg)");
            return;
        }
        LINFO("The time is " << time);
        // invoker->sendPlayerChatMessage("The time is " << time);
    }
}

void Time::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2) {
        LERROR("Usage : /time <add|query|set> (arg)");
        return;
    }

    if (invoker) {
        if (invoker->isOperator()) {
            checkArgsTime(args);
        }
    } else {
        checkArgsTime(args);
    }
}

void Time::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
        // invoker->sendPlayerChatMessage("/time"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/time set (day|noon|night|midnight|<time>)\n/time add <time>\n        /time query (daytime|gametime|day)");
}