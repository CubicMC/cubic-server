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

void Time::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2) {
        LERROR("Usage : /time <add|query|set> (arg)");
        return;
    }

    if (invoker) {
        if (invoker->isOperator()) {
            if (args[0] == "add") {
                int time = 0;
                if (args[1].back() == 'd') {
                    args[1].pop_back();
                    try {
                        time = std::stod(args[1]) * 24000;
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                } else if (args[1].back() == 's') {
                    args[1].pop_back();
                    try {
                        time = std::stod(args[1]) * 20;
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                } else if (args[1].back() == 't' && args[1] != "midnight" && args[1] != "night") {
                    args[1].pop_back();
                    try {
                        time = std::stoi(args[1]);
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                } else if (std::find_if(args[1].begin(), args[1].end(), [](unsigned char c) {
                               return !std::isdigit(c);
                           }) == args[1].end())
                    try {
                        time = std::stoi(args[1]);
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                else {
                    LERROR("Usage : /time <add|query|set> (arg)");
                    return;
                }
                int added = Server::getInstance()->getWorldGroup("default")->getWorld("default")->addTime(time);
                LINFO("Set the time to " << added);
                // invoker->sendPlayerChatMessage("Set the time to " << added);
            } else if (args[0] == "set") {
                int time = 0;
                if (args[1].back() == 'd') {
                    args[1].pop_back();
                    try {
                        time = std::stod(args[1]) * 24000;
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                } else if (args[1].back() == 's') {
                    args[1].pop_back();
                    try {
                        time = std::stod(args[1]) * 20;
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                } else if (args[1].back() == 't' && args[1] != "midnight" && args[1] != "night") {
                    args[1].pop_back();
                    try {
                        time = std::stoi(args[1]);
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                } else if (std::find_if(args[1].begin(), args[1].end(), [](unsigned char c) {
                               return !std::isdigit(c);
                           }) == args[1].end())
                    try {
                        time = std::stoi(args[1]);
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
                else if (args[1] == "day")
                    time = 1000;
                else if (args[1] == "night")
                    time = 13000;
                else if (args[1] == "noon")
                    time = 6000;
                else if (args[1] == "midnight")
                    time = 18000;
                else {
                    LERROR("Usage : /time <add|query|set> (arg)");
                    return;
                }
                Server::getInstance()->getWorldGroup("default")->getWorld("default")->setTime(time);
                LINFO("Set the time to " << time);
                // invoker->sendPlayerChatMessage("Set the time to " << time);
            } else if (args[0] == "query") {
                int time = 0;
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
    } else {
        if (args[0] == "add") {
            int time = 0;
            if (args[1].back() == 'd') {
                args[1].pop_back();
                try {
                    time = std::stod(args[1]) * 24000;
                } catch (const std::exception &e) {
                    LERROR("Not a number");
                    return;
                }
            } else if (args[1].back() == 's') {
                args[1].pop_back();
                try {
                    time = std::stod(args[1]) * 20;
                } catch (const std::exception &e) {
                    LERROR("Not a number");
                    return;
                }
            } else if (args[1].back() == 't' && args[1] != "midnight" && args[1] != "night") {
                args[1].pop_back();
                if (std::find_if(args[1].begin(), args[1].end(), [](unsigned char c) {
                        return !std::isdigit(c);
                    }) == args[1].end())
                    try {
                        time = std::stoi(args[1]);
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
            } else if (std::find_if(args[1].begin(), args[1].end(), [](unsigned char c) {
                           return !std::isdigit(c);
                       }) == args[1].end())
                try {
                    time = std::stoi(args[1]);
                } catch (const std::exception &e) {
                    LERROR("Not a number");
                    return;
                }
            else {
                LERROR("Usage : /time <add|query|set> (arg)");
                return;
            }
            int added = Server::getInstance()->getWorldGroup("default")->getWorld("default")->addTime(time);
            LINFO("Set the time to " << added);
            // invoker->sendPlayerChatMessage("Set the time to " << added);
        } else if (args[0] == "set") {
            int time = 0;
            if (args[1].back() == 'd') {
                args[1].pop_back();
                try {
                    time = std::stod(args[1]) * 24000;
                } catch (const std::exception &e) {
                    LERROR("Not a number");
                    return;
                }
            } else if (args[1].back() == 's') {
                args[1].pop_back();
                try {
                    time = std::stod(args[1]) * 20;
                } catch (const std::exception &e) {
                    LERROR("Not a number");
                    return;
                }
            } else if (args[1].back() == 't' && args[1] != "midnight" && args[1] != "night") {
                args[1].pop_back();
                if (std::find_if(args[1].begin(), args[1].end(), [](unsigned char c) {
                        return !std::isdigit(c);
                    }) == args[1].end())
                    try {
                        time = std::stoi(args[1]);
                    } catch (const std::exception &e) {
                        LERROR("Not a number");
                        return;
                    }
            } else if (std::find_if(args[1].begin(), args[1].end(), [](unsigned char c) {
                           return !std::isdigit(c);
                       }) == args[1].end())
                try {
                    time = std::stoi(args[1]);
                } catch (const std::exception &e) {
                    LERROR("Not a number");
                    return;
                }
            else if (args[1] == "day")
                time = 1000;
            else if (args[1] == "night")
                time = 13000;
            else if (args[1] == "noon")
                time = 6000;
            else if (args[1] == "midnight")
                time = 18000;
            else {
                LERROR("Usage : /time <add|query|set> (arg)");
                return;
            }
            Server::getInstance()->getWorldGroup("default")->getWorld("default")->setTime(time);
            LINFO("Set the time to " << time);
            // invoker->sendPlayerChatMessage("Set the time to " << time);
        } else if (args[0] == "query") {
            int time = 0;
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
}

void Time::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
        // invoker->sendPlayerChatMessage("/time"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/time set (day|noon|night|midnight|<time>)\n/time add <time>\n        /time query (daytime|gametime|day)");
}