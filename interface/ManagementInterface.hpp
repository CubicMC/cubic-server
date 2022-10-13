#ifndef MANAGEMENTINTERFACE_HPP
#define MANAGEMENTINTERFACE_HPP

#include <gtkmm/window.h>
#include <gtkmm/paned.h>

#include "LogsInterface.hpp"
#include "PlayersInterface.hpp"

class ManagementInterface : public Gtk::Window {
    public:
        ManagementInterface();
        virtual ~ManagementInterface();
    protected:
        Gtk::Paned m_content;
        PlayersInterface m_players_section;
        LogsInterface m_logs_section;
};

#endif /* !MANAGEMENTINTERFACE_HPP_ */