#include "help.hpp"

namespace help {

    void help(std::vector<std::string>& args) {
        logging::Logger::get_instance()->info("/help [<command>]");
    }

    void execute(std::vector<std::string>& args) {
        if (args.empty()) {
            for (auto &command : allCommands) {
                logging::Logger::get_instance()->info(command);
            }
        }
        else {
            if (helps.find(args[0]) != helps.end()) {
                helps.at(args[0])(args);
            } else {
                logging::Logger::get_instance()->info("Unknown command or insufficient permissions");
            }
        }
    }
}