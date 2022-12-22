#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

//#include "Logger.hpp"
#include "LogsInterface.hpp"

LogsInterface::LogsInterface() :
  m_VBox(Gtk::ORIENTATION_VERTICAL)
{
    set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
    set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    add(m_VBox);

    m_VBox.pack_start(m_label);
    m_label.set_xalign(0);
    m_label.set_yalign(0);
    m_label.set_line_wrap();
    m_label.set_text("GUI initialisation...");

    m_Entry.set_max_length(50);
    m_Entry.set_valign(Gtk::ALIGN_END);
    m_Entry.set_placeholder_text("Enter your command here...");
    m_Entry.select_region(0, m_Entry.get_text_length());

    // Is supposed to activate the Enter key event, but the event is not caught
    // at all. /!\ To do when handling command parsing.
    m_Entry.set_activates_default(true);

    m_VBox.pack_end(m_Entry);

    ///////////////////////////////////////
    // Not working anymore, for some reason

    // int timeout_value = 100; //in ms
    // sigc::slot<bool>my_slot = sigc::mem_fun(*this, &LogsInterface::on_timeout);
    // Glib::signal_timeout().connect(my_slot, timeout_value);

    ///////////////////////////////////////

    show_all_children();
}

bool LogsInterface::on_key_press_event(GdkEventKey* event)
{
    if (event->keyval == GDK_KEY_KP_Enter)
    {
        // Supposed to add the input to the logs (interface side only) when 'ENTER'
        // is pressed. /!\ To do when handling command parsing.
        m_label.set_text(m_label.get_text() + "\n" + m_Entry.get_text());
        m_Entry.set_text("");
        return true;
    }

    if(event->keyval == GDK_KEY_Escape)
    {
        // Add the input to the logs (interface side only) when 'ESC' pressed
        m_label.set_text(m_label.get_text() + "\n" + m_Entry.get_text());
        m_Entry.set_text("");
        return true;
    }

    return false;
}

bool LogsInterface::on_timeout(){
    std::string temp = "";
    std::string logs;
    std::ifstream file_stream;
    file_stream.open(/*logging::Logger::get_instance().get_file_path()*/"logs.txt", std::ios::out);

    while (std::getline(file_stream, logs)) {
        temp += logs + "\n";
    }
    m_label.set_text(temp);

 return true;
}

LogsInterface::~LogsInterface()
{
}
