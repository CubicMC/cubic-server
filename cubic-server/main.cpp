#include <iostream>
#include <cstring>
#include <unordered_map>
#include <functional>

#include "Server.hpp"
#include "protocol/ServerPackets.hpp"
#include "interface/ManagementInterface.hpp"

bool gui = true;

int print_usage(const char *caller)
{
    std::cout << "Usage:\n\t" << caller << " [FLAGS]"<< std::endl;
    std::cout << "\t\t-h:\t\tDisplays this help." << std::endl;
    std::cout << "\t\t--help:\t\tDisplays this help." << std::endl;
    std::cout << "\t\t--nogui:\tPrevents the GUI from displaying." << std::endl;
    return 1;
}

int hide_gui(const char *no) {
    gui = false;
    return 2;
}

int arg_parser(int argc, char **argv) {
    std::unordered_map<std::string, std::function<int(const char *)>> args;
    int res = 0;

    args["-h"] = std::function<int(const char *)>(print_usage);
    args["--help"] = std::function<int(const char *)>(print_usage);
    args["--nogui"] = std::function<int(const char *)>(hide_gui);

    for(int i = 1; i < argc; i++) {
        std::string flag = argv[i];
        res = std::any_cast<std::function<int(const char *)>>(args[flag])(argv[0]);
        if (res == 1) {
            return res;
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    int check_args = arg_parser(argc, argv);
    std::thread InterfaceThread;

    if (check_args == 1) {
        return 0;
    }

    if (gui) {
        InterfaceThread = std::thread(&ManagementInterface::launch, argc, argv);
    }

    auto srv = Server::getInstance();
    srv->launch();
}
