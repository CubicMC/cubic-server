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

    bool onTimeout();
    void stop();

protected:
    virtual bool on_delete_event(GdkEventAny *event) override;

protected:
    Gtk::Paned _content;
    Gtk::Paned _sections;
    Gtk::Label _playersTitle;
    PlayersInterface _playersSection;
    LogsInterface _logsSection;
};

#endif /* !MANAGEMENTINTERFACE_HPP_ */
