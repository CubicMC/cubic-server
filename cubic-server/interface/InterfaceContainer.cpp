#include "InterfaceContainer.hpp"

void InterfaceContainer::launch(int argc, char **argv)
{
    this->_app = Gtk::Application::create(argc, argv, "org.cubicserver.example");
    this->_interface = std::make_shared<ManagementInterface>();
    this->_thread = std::thread([this] {
        this->_app->run(*this->_interface);
    });
}

void InterfaceContainer::stop()
{
    if (this->_interface)
        this->_interface->stop();
    if (this->_thread.joinable())
        this->_thread.join();
}
