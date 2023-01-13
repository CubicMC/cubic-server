#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <unistd.h>

#include "logging/Logger.hpp"
#include "LogsInterface.hpp"

LogsInterface::LogsInterface() :
  m_VBox_main(Gtk::ORIENTATION_VERTICAL),
  m_VBox_logs(Gtk::ORIENTATION_VERTICAL),
  m_HBox_filters(Gtk::ORIENTATION_HORIZONTAL),
  m_Info("Info"),
  m_Warn("Warning"),
  m_Error("Error"),
  m_Fatal("Fatal"),
  m_Debug("Debug")
{
    pack_start(m_VBox_main, Gtk::PACK_EXPAND_WIDGET);

    m_VBox_main.pack_start(m_VBox_logs);
    m_VBox_logs.pack_start(m_Frame_filters, Gtk::PACK_SHRINK);
    m_Frame_filters.add(m_HBox_filters);

    m_HBox_filters.pack_start(m_Info);
    m_HBox_filters.pack_start(m_Warn);
    m_HBox_filters.pack_start(m_Error);
    m_HBox_filters.pack_start(m_Fatal);
    m_HBox_filters.pack_start(m_Debug);
    m_HBox_filters.set_border_width(10);
    m_HBox_filters.set_layout(Gtk::BUTTONBOX_SPREAD);

    m_VBox_logs.pack_end(m_Logs_container);

    m_Logs_container.add(m_Logs_view);
    m_Logs_container.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    m_Logs_container.set_min_content_height(380);
    m_Logs = Gtk::TextBuffer::create();
    m_Logs->set_text("GUI initialisation...");

    m_Logs_view.set_buffer(m_Logs);
    m_Logs_view.set_wrap_mode(Gtk::WRAP_CHAR);
    m_Logs_view.set_editable(false);
    m_Logs_view.set_cursor_visible(false);
    m_Logs_view.set_vscroll_policy(Gtk::SCROLL_MINIMUM);

    m_Entry.set_max_length(700);
    m_Entry.set_valign(Gtk::ALIGN_END);
    m_Entry.set_placeholder_text("Enter your command here...");
    m_Entry.select_region(0, m_Entry.get_text_length());

    // Is supposed to activate the Enter key event, but the event is not caught
    // at all. /!\ To do when handling command parsing.
    m_Entry.set_activates_default(true);

    m_VBox_main.pack_end(m_Entry);

    int timeout_value = 100; //in ms
    sigc::slot<bool>my_slot = sigc::mem_fun(*this, &LogsInterface::on_log_to_display);
    Glib::signal_timeout().connect(my_slot, timeout_value);
}

bool LogsInterface::on_key_press_event(GdkEventKey* event)
{
    if (event->keyval == GDK_KEY_KP_Enter)
    {
        // Supposed to add the input to the logs (interface side only) when 'ENTER'
        // is pressed. /!\ To do when handling command parsing.
        m_Logs->set_text(m_Logs->get_text() + "\n" + m_Entry.get_text());
        m_endMark = m_Logs->create_mark(m_Logs->end());
        m_Logs_view.scroll_to(m_endMark);
        m_Entry.set_text("");
        return true;
    }

    if(event->keyval == GDK_KEY_Escape)
    {
        // Add the input to the logs (interface side only) when 'ESC' pressed
        m_Logs->set_text(m_Logs->get_text() + "\n" + m_Entry.get_text());
        m_endMark = m_Logs->create_mark(m_Logs->end());
        m_Logs_view.scroll_to(m_endMark);
        m_Entry.set_text("");
        return true;
    }

    return false;
}

bool LogsInterface::on_log_to_display()
{
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

    if (m_Logs->get_text().raw() != temp) {
        m_Logs->set_text(temp.c_str());
        m_endMark = m_Logs->create_mark(m_Logs->end());
        m_Logs_view.scroll_to(m_endMark);
    }

    return true;
}

void LogsInterface::on_button_clicked()
{
    return;
}

LogsInterface::~LogsInterface()
{
}
