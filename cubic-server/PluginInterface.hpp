#ifndef PLUGIN_INTERFACE_HPP
#define PLUGIN_INTERFACE_HPP

#include <vector>
#include <string>

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

    struct player {
        explicit player(PluginInterface *interface) : _intern(interface) {};

        Player *getByID(u128 uuid);
        Player *getByName(std::string name);

        // Checks
        bool isConnected(Player *player) const;
        bool isBanned(Player *player) const;
        bool hasAdvancement(Player *player) const;
        bool hasRecipe(Player *player) const;

        // Interaction
        void playSound(Player *player);
        void kick(Player *player);
        void ban(Player *player);
        void giveAdvancement(Player *player);
        void revokeAdvancement(Player *player);
        void giveRecipe(Player *player);
        void removeRecipe(Player *player);

    private:
        PluginInterface *_intern;
    } player {this};

    struct entity {
        explicit entity(PluginInterface *interface) : _intern(interface) {};

        Entity *getByID();

        // Interactions
        void kill(Entity *entity);
        void despawn(Entity *entity);
        void heal(Entity *entity, float amount);
        void damage(Entity *entity, float amount);
        void ride(Entity *entity);
        void unride(Entity *entity);
        void equip(Entity *entity);
        void unequip(Entity *entity);

    private:
        PluginInterface *_intern;
    } entity {this};

    struct block {
        explicit block(PluginInterface *interface) : _intern(interface) {};

        void getByID();
        void getByPosition();

        // Interactions
        void destroy();
        void place();

    private:
        PluginInterface *_intern;
    } block {this};

    struct inventory {
        explicit inventory(PluginInterface *interface) : _intern(interface) {};

        Inventory *getByID();
        Inventory *getByPosition();

        // Checks
        bool hasItem() const;

        // Interactions
        void addItem();
        void removeItem();
        void clear();

    private:
        PluginInterface *_intern;
    } inventory {this};

    struct chat {
        explicit chat(PluginInterface *interface) : _intern(interface) {};

        Chat *get();

    private:
        PluginInterface *_intern;
    } chat {this};

    struct command {
        explicit command(PluginInterface *interface) : _intern(interface) {};

        void registerCommand();
        void unregisterCommand();
        void raw();

    private:
        PluginInterface *_intern;
    } command {this};
};

#endif
