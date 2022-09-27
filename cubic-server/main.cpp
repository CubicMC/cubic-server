#include <iostream>
#include <cstring>

#include "Server.hpp"
#include "ServerPackets.hpp"

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

    auto srv = Server("0.0.0.0", 25565);
    srv.launch();
}
