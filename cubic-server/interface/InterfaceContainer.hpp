#ifndef INTERFACE_CONTAINER_HPP
#define INTERFACE_CONTAINER_HPP

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

#endif
