#include "ManagementInterface.hpp"
#include <string>
#include <iostream>

ManagementInterface::ManagementInterface()
{
    set_title("Cubic Server Interface");
    set_default_size(800, 500);
    set_border_width(10);

    add(m_content);

    m_content.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    m_content.add1(m_players_section);
    m_content.add2(m_logs_section);
    m_content.set_position(380);

    show_all_children();
}

ManagementInterface::~ManagementInterface() {}