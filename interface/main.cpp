#include "ManagementInterface.hpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.cubicserver.example");

  ManagementInterface window;

  return app->run(window);
}