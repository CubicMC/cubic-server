#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <unistd.h>

#include "logging/Logger.hpp"
#include "LogsInterface.hpp"

LogsInterface::LogsInterface()
{
    set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
    set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    add(m_label);

    m_label.set_xalign(0);
    m_label.set_yalign(0);
    m_label.set_text("GUI initialisation...");

    int timeout_value = 100; //in ms
    sigc::slot<bool>my_slot = sigc::mem_fun(*this, &LogsInterface::on_timeout);
    Glib::signal_timeout().connect(my_slot, timeout_value);

    show_all_children();
}

bool LogsInterface::on_timeout(){
    std::string temp = "";
    std::stringstream ss;
    std::queue<logging::LogMessage> q_copy = logging::Logger::get_instance()->get_logs();

    while (!q_copy.empty())
    {
        logging::LogMessage front = q_copy.front();
        ss << front << std::endl;
        temp = ss.str();
        q_copy.pop();
    }
    m_label.set_text(temp);

 return true;
}

LogsInterface::~LogsInterface()
{
}
