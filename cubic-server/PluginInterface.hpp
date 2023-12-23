#ifndef PLUGIN_INTERFACE_HPP
#define PLUGIN_INTERFACE_HPP

#include <string>
#include <vector>

#include "types.hpp"

class Server;

class Player;
class Entity;
class LivingEntity;
class Block;
class Inventory;
class Chat;

template<typename T>
class Vector3;

class PluginInterface {
public:
    PluginInterface();
    virtual ~PluginInterface();

    void load(Server *server);
    Server *server;
};

#endif
