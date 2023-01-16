#ifndef LOGSINTERFACE_HPP
#define LOGSINTERFACE_HPP

#include <gtkmm.h>

#include "logging/Logger.hpp"

class LogsInterface : public Gtk::Box {
    public:
        LogsInterface();
        virtual ~LogsInterface();

    private:
        bool on_log_to_display();
        bool on_key_press_event(GdkEventKey* event) override;
        void on_filter_selected(logging::LogLevel logLevel);
        void on_reset_filters();

    protected:
        Gtk::ScrolledWindow m_Logs_container;
        Gtk::TextView m_Logs_view;
        Glib::RefPtr<Gtk::TextBuffer> m_Logs;
        Glib::RefPtr<Gtk::TextBuffer::Mark> m_endMark;
        Gtk::Entry m_Entry;
        Gtk::Box m_VBox_main, m_VBox_logs;
        Gtk::Frame m_Frame_filters, m_Frame_selectedFilter;
        Gtk::ButtonBox m_HBox_filters;
        Gtk::Button m_Info, m_Warn, m_Error, m_Fatal, m_Debug, m_Reset;
        Gtk::Label m_Selected_filter;
        logging::LogLevel m_Selected_logLevel;
};

#endif /* !LOGSINTERFACE_HPP */
