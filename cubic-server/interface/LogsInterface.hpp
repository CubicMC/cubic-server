#ifndef LOGSINTERFACE_HPP
#define LOGSINTERFACE_HPP

#include <gtkmm.h>

class LogsInterface : public Gtk::ScrolledWindow {
    public:
    LogsInterface();
    virtual ~LogsInterface();
    bool on_timeout();

    private:
    bool on_key_press_event(GdkEventKey* event) override;

    protected:
    Gtk::Label m_label;
    Gtk::Entry m_Entry;
    Gtk::Box m_VBox;
};

#endif /* !LOGSINTERFACE_HPP */
