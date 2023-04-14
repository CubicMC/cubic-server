#include <fstream>
#include <iostream>
#include <unistd.h>

#include "Player.hpp"
#include "PlayersInterface.hpp"
#include "Server.hpp"
#include "World.hpp"

PlayersInterface::PlayersInterface()
{
    set_shadow_type(Gtk::SHADOW_IN);
    set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    add(this->m_Players_view);

    m_Players = Gtk::TextBuffer::create();
    m_Players->set_text("GUI initialisation...");

    m_Players_view.set_buffer(m_Players);
    m_Players_view.set_wrap_mode(Gtk::WRAP_CHAR);
    m_Players_view.set_editable(false);
    m_Players_view.set_cursor_visible(false);
    m_Players_view.set_vscroll_policy(Gtk::SCROLL_MINIMUM);

    int timeout_value = 1500; // in ms
    sigc::slot<bool> my_slot = sigc::mem_fun(*this, &PlayersInterface::on_timeout);
    Glib::signal_timeout().connect(my_slot, timeout_value);

    show_all_children();
}

bool PlayersInterface::on_timeout()
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

    if (m_Players->get_text().raw() != temp) {
        this->m_Players->set_text(temp.c_str());
        this->m_Nb_players = "Players : " + std::to_string(nb_players);
    }

    return true;
}

std::string PlayersInterface::get_nb_players() { return this->m_Nb_players; }

PlayersInterface::~PlayersInterface() { }
