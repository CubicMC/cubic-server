#ifndef PLAYERSINTERFACE_HPP
#define PLAYERSINTERFACE_HPP

#include <gtkmm.h>
#include <string>

class PlayersInterface : public Gtk::ScrolledWindow {
    public:
        PlayersInterface();
        ~PlayersInterface();

        bool on_timeout();
        std::string get_nb_players();
    protected:
        Gtk::Label m_label;
        std::string m_nb_players = "Players : --";
};

#endif /* !PLAYERSINTERFACE_HPP */
