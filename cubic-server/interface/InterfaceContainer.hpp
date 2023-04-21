#ifndef CUBICSERVER_INTERFACE_INTERFACECONTAINER_HPP
#define CUBICSERVER_INTERFACE_INTERFACECONTAINER_HPP

#include <gtkmm.h>
#include <memory>
#include <thread>

#include "ManagementInterface.hpp"

class InterfaceContainer {
public:
    void launch(int argc, char **argv);
    void stop();

private:
    std::thread _thread;
    std::shared_ptr<ManagementInterface> _interface;
    Glib::RefPtr<Gtk::Application> _app;
};

#endif // CUBICSERVER_INTERFACE_INTERFACECONTAINER_HPP
