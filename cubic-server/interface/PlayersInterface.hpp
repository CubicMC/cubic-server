#ifndef PLAYERSINTERFACE_HPP
#define PLAYERSINTERFACE_HPP

#include <gtkmm.h>
#include <string>

class PlayersInterface : public Gtk::ScrolledWindow {
public:
    PlayersInterface();
    ~PlayersInterface();

    bool onTimeout();
    std::string getNbPlayers();

protected:
    Gtk::TextView _playersView;
    Glib::RefPtr<Gtk::TextBuffer> _players;
    std::string _nbPlayers = "Players : --";
};

#endif /* !PLAYERSINTERFACE_HPP */
