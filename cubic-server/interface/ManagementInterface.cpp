#include "ManagementInterface.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

ManagementInterface::ManagementInterface()
{
    set_title("Cubic Server Interface");
    set_default_size(800, 500);
    set_border_width(10);
    this->m_players_title.set_xalign(0);
    this->m_players_title.set_yalign(0);

    add(this->m_content);

    this->m_sections.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_sections.add1(this->m_players_section);
    this->m_sections.add2(this->m_logs_section);
    this->m_sections.set_position(380);

    this->m_content.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_content.add1(this->m_players_title);
    this->m_content.add2(this->m_sections);
    this->m_content.set_position(25);

    int timeout_value = 100; //in ms
    sigc::slot<bool>my_slot = sigc::mem_fun(*this, &ManagementInterface::on_timeout);
    Glib::signal_timeout().connect(my_slot, timeout_value);

    show_all_children();
}

bool ManagementInterface::on_timeout(){
    std::string title = this->m_players_section.get_nb_players();

    this->m_players_title.set_text(title.c_str());

 return true;
}

int ManagementInterface::launch(int argc, char **argv){
    auto app = Gtk::Application::create(argc, argv, "org.cubicserver.example");
    ManagementInterface window;

    return app->run(window);
}

ManagementInterface::~ManagementInterface() {}
