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

    auto srv = Server();
    /// 
    auto app = Gtk::Application::create(argc, argv, "org.cubicserver.example");
    ManagementInterface window;

    auto InterfaceThread = std::thread({return app->run(window)}, app);
    ///

    srv.launch();
}
