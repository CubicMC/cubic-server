#include "ManagementInterface.hpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.cubicserver.example");

  ManagementInterface window;

  //Shows the window and returns when it is closed.
  return app->run(window);
}