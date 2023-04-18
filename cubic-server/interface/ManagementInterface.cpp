#include "ManagementInterface.hpp"

#include <iostream>
#include <string>
#include <unistd.h>

#include "Server.hpp"

ManagementInterface::ManagementInterface()
{
    set_title("Cubic Server Interface");
    set_default_size(900, 550);
    set_border_width(5);
    this->_playersTitle.set_xalign(0);
    this->_playersTitle.set_yalign(0);

    add(this->_content);

    this->_sections.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->_sections.add1(this->_playersSection);
    this->_sections.add2(this->_logsSection);
    this->_sections.set_position(280);

    this->_content.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->_content.add1(this->_playersTitle);
    this->_content.add2(this->_sections);
    this->_content.set_position(25);

    int timeoutValue = 100; // in ms
    sigc::slot<bool> mySlot = sigc::mem_fun(*this, &ManagementInterface::onTimeout);
    Glib::signal_timeout().connect(mySlot, timeoutValue);

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

bool ManagementInterface::onTimeout()
{
    std::string title = this->_playersSection.getNbPlayers();

    this->_playersTitle.set_text(title.c_str());

    return true;
}

void ManagementInterface::stop() { this->close(); }

ManagementInterface::~ManagementInterface() { }
