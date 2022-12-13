#include <iostream>
#include <fstream>
#include <unistd.h>

//#include "Logger.hpp"
#include "PlayersInterface.hpp"

PlayersInterface::PlayersInterface()
{
    set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
    set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    this->m_label.set_justify(Gtk::JUSTIFY_LEFT);
    this->m_label.set_xalign(0);
    this->m_label.set_yalign(0);
    this->m_label.set_text("GUI initialisation...");
    add(this->m_label);

    ///////////////////////////////////////
    // Not working anymore, for some reason

    // int timeout_value = 100; //in ms
    // sigc::slot<bool>my_slot = sigc::mem_fun(*this, &PlayersInterface::on_timeout);
    // Glib::signal_timeout().connect(my_slot, timeout_value);

    ///////////////////////////////////////

    show_all_children();
}

bool PlayersInterface::on_timeout(){
    std::string temp = "";
    int nb_players = 0;
    std::string players;
    std::ifstream file_stream;
    file_stream.open("players.txt", std::ios::out);

    while (std::getline(file_stream, players)) {
        temp += players + "\n";
        nb_players = nb_players + 1;
    }
    this->m_label.set_text(temp);
    this->m_nb_players = "Players : " + std::to_string(nb_players);

 return true;
}

std::string PlayersInterface::get_nb_players(){
    return this->m_nb_players;
}

PlayersInterface::~PlayersInterface()
{
}
