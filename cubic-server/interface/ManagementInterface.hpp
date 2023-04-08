#ifndef MANAGEMENTINTERFACE_HPP
#define MANAGEMENTINTERFACE_HPP

#include <gtkmm.h>
#include <memory>
#include <thread>

#include "LogsInterface.hpp"
#include "PlayersInterface.hpp"

class ManagementInterface : public Gtk::Window {
public:
    ManagementInterface();
    virtual ~ManagementInterface();

    bool on_timeout();
    void stop();

protected:
    virtual bool on_delete_event(GdkEventAny *event) override;

protected:
    Gtk::Paned m_content;
    Gtk::Paned m_sections;
    Gtk::Label m_players_title;
    PlayersInterface m_players_section;
    LogsInterface m_logs_section;
};

#endif /* !MANAGEMENTINTERFACE_HPP_ */
