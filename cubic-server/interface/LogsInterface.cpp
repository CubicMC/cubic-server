#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <unistd.h>

#include "LogsInterface.hpp"

LogsInterface::LogsInterface() :
  m_VBox_main(Gtk::ORIENTATION_VERTICAL),
  m_VBox_logs(Gtk::ORIENTATION_VERTICAL),
  m_HBox_filters(Gtk::ORIENTATION_HORIZONTAL),
  m_Info("Info"),
  m_Warn("Warning"),
  m_Error("Error"),
  m_Fatal("Fatal"),
  m_Debug("Debug"),
  m_Reset("↺"),
  m_Selected_logLevel(logging::LogLevel::NONE)
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
    m_HBox_filters.pack_end(m_Reset);
    m_Reset.set_sensitive(false);
    m_HBox_filters.set_border_width(10);
    m_HBox_filters.set_layout(Gtk::BUTTONBOX_SPREAD);

    m_Selected_filter.set_justify(Gtk::JUSTIFY_LEFT);
    m_Selected_filter.set_xalign(0);
    m_Selected_filter.set_yalign(0);
    m_Selected_filter.set_text("No filter selected.");
    m_VBox_logs.pack_start(m_Frame_selectedFilter, Gtk::PACK_EXPAND_PADDING);
    m_Frame_selectedFilter.add(m_Selected_filter);

    m_VBox_logs.pack_end(m_Logs_container);

    m_Debug.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::on_filter_selected), logging::LogLevel::DEBUG));
    m_Info.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::on_filter_selected), logging::LogLevel::INFO));
    m_Warn.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::on_filter_selected), logging::LogLevel::WARNING));
    m_Error.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::on_filter_selected), logging::LogLevel::ERROR));
    m_Fatal.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::on_filter_selected), logging::LogLevel::FATAL));
    m_Reset.signal_clicked().connect(sigc::mem_fun(*this, &LogsInterface::on_reset_filters));

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

    int timeout_value = 400; //in ms
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
    logging::LogLevel logLevel;
    std::string temp = "";
    std::stringstream ss;
    std::queue<logging::LogMessage> q_copy = logging::Logger::get_instance()->get_logs();

    if (m_Selected_logLevel == logging::LogLevel::NONE) {
        while (!q_copy.empty())
        {
            logging::LogMessage front = q_copy.front();
            logLevel = front.get_level();
            ss << front << std::endl;
            temp = ss.str();
            q_copy.pop();
        }
    } else {
        while (!q_copy.empty())
        {
            logging::LogMessage front = q_copy.front();
            logLevel = front.get_level();
            if (logLevel == m_Selected_logLevel) {
                ss << front << std::endl;
                temp = ss.str();
            }
            q_copy.pop();
        }
    }

    if (m_Logs->get_text().raw() != temp) {
        m_Logs->set_text(temp.c_str());
        int timeout_value = 200; //in ms
        sigc::slot<void>slot = sigc::mem_fun(*this, &LogsInterface::scroll_to_end);
        Glib::signal_timeout().connect_once(slot, timeout_value);
    }
    return true;
}

void LogsInterface::scroll_to_end()
{
    m_endMark = m_Logs->create_mark(m_Logs->end());
    m_Logs_view.scroll_to(m_endMark);
}

void LogsInterface::on_filter_selected(logging::LogLevel logLevel)
{
    std::string logLevelFilter = logging::level_to_string(logLevel);
    m_Selected_filter.set_text(logLevelFilter + "has been selected. Only " + logLevelFilter + "messages are shown.");
    m_Reset.set_sensitive(true);
    m_Selected_logLevel = logLevel;
}

void LogsInterface::on_reset_filters()
{
    m_Selected_logLevel = logging::LogLevel::NONE;
    m_Selected_filter.set_text("No filter selected.");
    m_Reset.set_sensitive(false);

}

LogsInterface::~LogsInterface()
{
}
