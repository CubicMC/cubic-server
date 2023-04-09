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
    Gtk::TextView m_Players_view;
    Glib::RefPtr<Gtk::TextBuffer> m_Players;
    std::string m_Nb_players = "Players : --";
};

#endif /* !PLAYERSINTERFACE_HPP */
