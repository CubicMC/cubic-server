#include "PlayersInterface.hpp"

#include <fstream>
#include <iostream>
#include <unistd.h>

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"

PlayersInterface::PlayersInterface()
{
    set_shadow_type(Gtk::SHADOW_IN);
    set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    add(this->_playersView);

    _players = Gtk::TextBuffer::create();
    _players->set_text("GUI initialisation...");

    _playersView.set_buffer(_players);
    _playersView.set_wrap_mode(Gtk::WRAP_CHAR);
    _playersView.set_editable(false);
    _playersView.set_cursor_visible(false);
    _playersView.set_vscroll_policy(Gtk::SCROLL_MINIMUM);

    int timeoutValue = 1500; // in ms
    sigc::slot<bool> my_slot = sigc::mem_fun(*this, &PlayersInterface::onTimeout);
    Glib::signal_timeout().connect(my_slot, timeoutValue);

    show_all_children();
}

bool PlayersInterface::onTimeout()
{
    std::string temp = "";
    std::string players;
    int nb_players = 0;

    for (auto [_, worldGroup] : Server::getInstance()->getWorldGroups()) {
        for (auto [_, world] : worldGroup->getWorlds()) {
            for (auto [_, dim] : world->getDimensions()) {
                for (auto player : dim->getPlayers()) {
                    temp += player->getUsername() + "\n";
                    nb_players++;
                }
            }
        }
    }

    if (_players->get_text().raw() != temp) {
        this->_players->set_text(temp.c_str());
        this->_nbPlayers = "Players : " + std::to_string(nb_players);
    }

    return true;
}

std::string PlayersInterface::getNbPlayers() { return this->_nbPlayers; }

PlayersInterface::~PlayersInterface() { }
