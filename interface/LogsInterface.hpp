#ifndef LOGSINTERFACE_HPP
#define LOGSINTERFACE_HPP

#include <gtkmm.h>

class LogsInterface : public Gtk::ScrolledWindow {
    public:
    LogsInterface();
    virtual ~LogsInterface();
    bool on_timeout();

    protected:
    Gtk::Label m_label;
};

#endif /* !LOGSINTERFACE_HPP */
