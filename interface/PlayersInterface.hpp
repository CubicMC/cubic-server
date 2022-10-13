#ifndef PLAYERSINTERFACE_HPP
#define PLAYERSINTERFACE_HPP

#include <gtkmm.h>

class PlayersInterface : public Gtk::ScrolledWindow {
    public:
        PlayersInterface();
        ~PlayersInterface();
        bool on_timeout();

        protected:
        Gtk::Label m_label;
};

#endif /* !PLAYERSINTERFACE_HPP */
