#include "PluginInterface.hpp"

PluginInterface::PluginInterface() { }

PluginInterface::~PluginInterface() { }

void PluginInterface::load(Server *server) { this->server = server; }
