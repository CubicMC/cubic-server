#include "Time.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"

using namespace command_parser;

void Time::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete time");
}

int setTimeFromArg(std::string value, int multiplier, Player *invoker)
{
    int time = 0;
    try {
        if (value.back() == 'd' || value.back() == 's' || value.back() == 't')
            value.pop_back();
        time = std::stod(value) * multiplier;
        return time;
    } catch (const std::exception &e) {
        LERROR("Expected float");
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Expected float", *invoker);
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

int setTimeToAdd(std::string timeToAdd, Player *invoker)
{
    int time = 0;
    if (std::find_if(timeToAdd.begin(), timeToAdd.end(), [](unsigned char c) {
            return !std::isdigit(c);
        }) == timeToAdd.end())
        time = setTimeFromArg(timeToAdd, 1, invoker);
    else {
        if ((timeToAdd.back() == 'd' || timeToAdd.back() == 's' || timeToAdd.back() == 't') && timeToAdd.front() != '-') {
            time = setTimeFromArg(timeToAdd, setMultiplier(timeToAdd.back()), invoker);
            return time;
        } else if (timeToAdd.front() == '-') {
            LERROR("Tick count must be non-negative");
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Tick count must be non-negative", *invoker);
            return -1;
        }
        LERROR("Expected float");
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Expected float", *invoker);
        return -1;
    }
    return time;
}

int setTimeToSet(const std::string &timeToSet, Player *invoker)
{
    int time = 0;
    if (std::find_if(timeToSet.begin(), timeToSet.end(), [](unsigned char c) {
            return !std::isdigit(c);
        }) == timeToSet.end())
        time = setTimeFromArg(timeToSet, 1, invoker);
    else if (timeToSet == "day")
        time = 1000;
    else if (timeToSet == "night")
        time = 13000;
    else if (timeToSet == "noon")
        time = 6000;
    else if (timeToSet == "midnight")
        time = 18000;
    else {
        if (timeToSet.back() == 'd' || timeToSet.back() == 's' || (timeToSet.back() == 't' && timeToSet != "midnight" && timeToSet != "night" && timeToSet.front() != '-')) {
            time = setTimeFromArg(timeToSet, setMultiplier(timeToSet.back()), invoker);
            return time;
        } else if (timeToSet.front() == '-') {
            LERROR("Tick count must be non-negative");
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Tick count must be non-negative", *invoker);
            return -1;
        }
        LERROR("Expected float");
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Expected float", *invoker);
        return -1;
    }
    return time;
}

void checkArgsTime(std::vector<std::string> &args, Player *invoker)
{
    int time = 0;
    if (args[0] == "add") {
        time = setTimeToAdd(args[1], invoker);
        if (time != -1) {
            int added = Server::getInstance()->getWorldGroup("default")->getWorld("default")->addTime(time);
            LINFO("Set the time to {}", added);
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Set the time to " + std::to_string(added), *invoker);
        }
    } else if (args[0] == "set") {
        time = setTimeToSet(args[1], invoker);
        if (time != -1) {
            Server::getInstance()->getWorldGroup("default")->getWorld("default")->setTime(time);
            LINFO("Set the time to {}", time);
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Set the time to " + std::to_string(time), *invoker);
        }
    } else if (args[0] == "query") {
        if (args[1] == "daytime")
            time = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getTime() % 24000;
        else if (args[1] == "gametime")
            time = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getAge() % INT_MAX;
        else if (args[1] == "day")
            time = (Server::getInstance()->getWorldGroup("default")->getWorld("default")->getTime() / 24000) % INT_MAX;
        else {
            LERROR("Incorrect argument for command");
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Incorrect argument for command", *invoker);
            return;
        }
        LINFO("The time is {}", time);
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("The time is " + std::to_string(time), *invoker);
    }
}

void Time::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2) {
        return;
    }

    if (invoker) {
        if (invoker->isOperator()) {
            checkArgsTime(args, invoker);
        }
    } else {
        checkArgsTime(args, invoker);
    }
}

void Time::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
        // invoker->sendPlayerChatMessage("/time"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/time set (day|noon|night|midnight|<time>)\n/time add <time>\n        /time query (daytime|gametime|day)");
}
