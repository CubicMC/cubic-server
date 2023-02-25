#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>

#include "ManagementInterface.hpp"
#include "Server.hpp"

ManagementInterface::ManagementInterface()
{
    set_title("Cubic Server Interface");
    set_default_size(900, 550);
    set_border_width(5);
    this->m_players_title.set_xalign(0);
    this->m_players_title.set_yalign(0);

    add(this->m_content);

    this->m_sections.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_sections.add1(this->m_players_section);
    this->m_sections.add2(this->m_logs_section);
    this->m_sections.set_position(280);

    this->m_content.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_content.add1(this->m_players_title);
    this->m_content.add2(this->m_sections);
    this->m_content.set_position(25);

    int timeout_value = 100; //in ms
    sigc::slot<bool>my_slot = sigc::mem_fun(*this, &ManagementInterface::on_timeout);
    Glib::signal_timeout().connect(my_slot, timeout_value);

    show_all_children();
}

bool ManagementInterface::on_delete_event(GdkEventAny *event)
{
    if (event->type != GDK_DELETE || !Server::getInstance()->isRunning())
        return false;

    Gtk::MessageDialog dialog("Quit ?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
    dialog.set_title("Quit ?");
    dialog.set_message("Are you sure you want to quit ?");
    dialog.set_secondary_text("All players will be disconnected and the world will be saved.");
    dialog.set_default_response(Gtk::RESPONSE_YES);

    int result = dialog.run();

    if (result == Gtk::RESPONSE_YES)
        Server::getInstance()->stop();

    return true;
}

bool ManagementInterface::on_timeout()
{
    std::string title = this->m_players_section.get_nb_players();

    this->m_players_title.set_text(title.c_str());

    return true;
}

void ManagementInterface::stop()
{
    this->close();
}

ManagementInterface::~ManagementInterface() {}
