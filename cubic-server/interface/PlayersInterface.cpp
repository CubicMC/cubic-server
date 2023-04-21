#include "PlayersInterface.hpp"

#include <fstream>
#include <iostream>
#include <unistd.h>

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
    int nbPlayers = 0;
    std::vector<Player *> playersListCopy; // How can I get it ?

    for (auto world : Server::getInstance()->getWorldGroup("default")->getWorlds()) {
        if (world.second->getPlayers().size() != 0) {
            if (playersListCopy.size() == 0) {
                for (auto player : world.second->getPlayers()) {
                    playersListCopy.push_back(player);
                }
            } else {
                playersListCopy.insert(playersListCopy.end(), world.second->getPlayers().begin(), world.second->getPlayers().end());
            }
        }
    }

    if (playersListCopy.size() != 0) {
        for (auto player : playersListCopy) {
            temp += player->getUsername() + "\n";
            nbPlayers = nbPlayers + 1;
        }
    }

    if (_players->get_text().raw() != temp) {
        this->_players->set_text(temp.c_str());
        this->_nbPlayers = "Players : " + std::to_string(nbPlayers);
    }

    return true;
}

std::string PlayersInterface::getNbPlayers() { return this->_nbPlayers; }

PlayersInterface::~PlayersInterface() { }
