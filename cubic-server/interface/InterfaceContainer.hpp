#ifndef INTERFACE_CONTAINER_HPP
#define INTERFACE_CONTAINER_HPP

#include <gtkmm.h>
#include <thread>
#include <memory>

#include "ManagementInterface.hpp"

class InterfaceContainer
{
public:
    void launch(int argc, char **argv);
    void stop();

private:
    std::thread _thread;
    std::shared_ptr<ManagementInterface> _interface;
    Glib::RefPtr<Gtk::Application> _app;
};

#endif
