#ifndef CUBICSERVER_INTERFACE_PLAYERSINTERFACE_HPP
#define CUBICSERVER_INTERFACE_PLAYERSINTERFACE_HPP

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

#endif // CUBICSERVER_INTERFACE_PLAYERSINTERFACE_HPP
