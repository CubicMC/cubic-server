#include <iostream>
#include <cstring>

#include "Server.hpp"
#include "ServerPackets.hpp"
#include "ManagementInterface.hpp"

static void print_usage(const char *caller)
{
    std::cout << "Usage:\n\t" << caller << std::endl;
}

int main(int argc, char **argv)
{
    if (argc >= 2 && !strcmp(argv[1], "-h"))
    {
        print_usage(argv[0]);
        return 0;
    }

    auto srv = Server::getInstance();
    ///
    if (false) // Put that to true if you want the gui
        auto InterfaceThread = std::thread(&ManagementInterface::launch, argc, argv);
    ///

    srv->launch();
}
