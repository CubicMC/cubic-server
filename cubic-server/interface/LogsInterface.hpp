#ifndef CUBICSERVER_INTERFACE_LOGSINTERFACE_HPP
#define CUBICSERVER_INTERFACE_LOGSINTERFACE_HPP

#include <gtkmm.h>

#include "logging/logging.hpp"

class LogsInterface : public Gtk::Box {
public:
    LogsInterface();
    virtual ~LogsInterface();

private:
    bool _onLogToDisplay();
    bool on_key_press_event(GdkEventKey *event) override;
    void _onFilterSelected(logging::Registry::LogLevel logLevel);
    void _onResetFilters();
    void _scrollToEnd();
    void _onButtonClicked();

protected:
    Gtk::ScrolledWindow _logsContainer;
    Gtk::TextView _logsView;
    Glib::RefPtr<Gtk::TextBuffer> _logs;
    Glib::RefPtr<Gtk::TextBuffer::Mark> _endMark;
    Gtk::Entry _entry;
    Gtk::Box _VBoxMain, _VBoxLogs;
    Gtk::Frame _frameFilters, _frameSelectedFilter;
    Gtk::ButtonBox _HBoxFilters;
    Gtk::Button _info, _warn, _error, _fatal, _debug, _reset;
    Gtk::Label _selectedFilter;
    logging::Registry::LogLevel _selectedLogLevel;
};

#endif // CUBICSERVER_INTERFACE_LOGSINTERFACE_HPP
