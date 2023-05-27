#include "LogsInterface.hpp"
#include "logging/logging.hpp"

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unistd.h>

LogsInterface::LogsInterface():
    _VBoxMain(Gtk::ORIENTATION_VERTICAL),
    _VBoxLogs(Gtk::ORIENTATION_VERTICAL),
    _HBoxFilters(Gtk::ORIENTATION_HORIZONTAL),
    _info("Info"),
    _warn("Warning"),
    _error("Error"),
    _fatal("Fatal"),
    _debug("Debug"),
    _reset("↺"),
    _selectedLogLevel(logging::Registry::LogLevel::off)
{
    pack_start(_VBoxMain, Gtk::PACK_EXPAND_WIDGET);

    _VBoxMain.pack_start(_VBoxLogs);
    _VBoxLogs.pack_start(_frameFilters, Gtk::PACK_SHRINK);
    _frameFilters.add(_HBoxFilters);

    _HBoxFilters.pack_start(_info);
    _HBoxFilters.pack_start(_warn);
    _HBoxFilters.pack_start(_error);
    _HBoxFilters.pack_start(_fatal);
    _HBoxFilters.pack_start(_debug);
    _HBoxFilters.pack_end(_reset);
    _reset.set_sensitive(false);
    _HBoxFilters.set_border_width(10);
    _HBoxFilters.set_layout(Gtk::BUTTONBOX_SPREAD);

    _selectedFilter.set_justify(Gtk::JUSTIFY_LEFT);
    _selectedFilter.set_xalign(0);
    _selectedFilter.set_yalign(0);
    _selectedFilter.set_text("No filter selected.");
    _VBoxLogs.pack_start(_frameSelectedFilter, Gtk::PACK_EXPAND_PADDING);
    _frameSelectedFilter.add(_selectedFilter);

    _VBoxLogs.pack_end(_logsContainer);

    _debug.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::_onFilterSelected), logging::Registry::LogLevel::debug));
    _info.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::_onFilterSelected), logging::Registry::LogLevel::info));
    _warn.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::_onFilterSelected), logging::Registry::LogLevel::warn));
    _error.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::_onFilterSelected), logging::Registry::LogLevel::err));
    _fatal.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &LogsInterface::_onFilterSelected), logging::Registry::LogLevel::critical));
    _reset.signal_clicked().connect(sigc::mem_fun(*this, &LogsInterface::_onResetFilters));

    _logsContainer.add(_logsView);
    _logsContainer.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    _logsContainer.set_min_content_height(380);
    _logs = Gtk::TextBuffer::create();
    _logs->set_text("GUI initialisation...");

    _logsView.set_buffer(_logs);
    _logsView.set_wrap_mode(Gtk::WRAP_CHAR);
    _logsView.set_editable(false);
    _logsView.set_cursor_visible(false);
    _logsView.set_vscroll_policy(Gtk::SCROLL_MINIMUM);

    _entry.set_max_length(700);
    _entry.set_valign(Gtk::ALIGN_END);
    _entry.set_placeholder_text("Enter your command here...");
    _entry.select_region(0, _entry.get_text_length());

    // Is supposed to activate the Enter key event, but the event is not caught
    // at all. /!\ To do when handling command parsing.
    _entry.set_activates_default(true);

    _VBoxMain.pack_end(_entry);

    int timeout_value = 400; // in ms
    sigc::slot<bool> my_slot = sigc::mem_fun(*this, &LogsInterface::_onLogToDisplay);
    Glib::signal_timeout().connect(my_slot, timeout_value);
}

bool LogsInterface::on_key_press_event(GdkEventKey *event)
{
    if (event->keyval == GDK_KEY_KP_Enter) {
        // Supposed to add the input to the logs (interface side only) when 'ENTER'
        // is pressed. /!\ To do when handling command parsing.
        _logs->set_text(_logs->get_text() + "\n" + _entry.get_text());
        _endMark = _logs->create_mark(_logs->end());
        _logsView.scroll_to(_endMark);
        _entry.set_text("");
        return true;
    }

    if (event->keyval == GDK_KEY_Escape) {
        // Add the input to the logs (interface side only) when 'ESC' pressed
        _logs->set_text(_logs->get_text() + "\n" + _entry.get_text());
        _endMark = _logs->create_mark(_logs->end());
        _logsView.scroll_to(_endMark);
        _entry.set_text("");
        return true;
    }

    return false;
}

bool LogsInterface::_onLogToDisplay()
{
    logging::Registry::LogLevel logLevel;
    std::string temp = "";
    std::stringstream ss;
    auto q_copy = logging::instance().getMessages();

    if (_selectedLogLevel == logging::Registry::LogLevel::off) {
        while (!q_copy.empty()) {
            auto front = q_copy.front();
            logLevel = front.level;
            ss << front.message << std::endl;
            temp = ss.str();
            q_copy.pop();
        }
    } else {
        while (!q_copy.empty()) {
            auto front = q_copy.front();
            logLevel = front.level;
            if (logLevel == _selectedLogLevel) {
                ss << front.message << std::endl;
                temp = ss.str();
            }
            q_copy.pop();
        }
    }

    if (_logs->get_text().raw() != temp) {
        _logs->set_text(temp.c_str());
        int timeout_value = 200; // in ms
        sigc::slot<void> slot = sigc::mem_fun(*this, &LogsInterface::_scrollToEnd);
        Glib::signal_timeout().connect_once(slot, timeout_value);
    }
    return true;
}

void LogsInterface::_scrollToEnd()
{
    _endMark = _logs->create_mark(_logs->end());
    _logsView.scroll_to(_endMark);
}

void LogsInterface::_onFilterSelected(logging::Registry::LogLevel logLevel)
{
    auto logLevelFilter = std::string(logging::levelToString(logLevel));
    _selectedFilter.set_text(std::string(logLevelFilter + "has been selected. Only " + logLevelFilter + "messages are shown.").c_str());
    _reset.set_sensitive(true);
    _selectedLogLevel = logLevel;
}

void LogsInterface::_onResetFilters()
{
    _selectedLogLevel = logging::Registry::LogLevel::off;
    _selectedFilter.set_text("No filter selected.");
    _reset.set_sensitive(false);
}

LogsInterface::~LogsInterface() { }
