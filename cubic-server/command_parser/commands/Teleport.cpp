#include <array>
#include <functional>
#include <stdexcept>
#include <vector>

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "Teleport.hpp"
#include "World.hpp"
#include "command_parser/selectors/selectors.hpp"
#include "entities/Entity.hpp"
#include "protocol/ClientPackets.hpp"

constexpr char TELEPORT_HELP[] = "/teleport (<location>|<destination>|<targets>)";
constexpr char TP_HELP[] = "/tp -> teleport";

static void execute(const std::vector<std::string> &args, Player *invoker)
{
    if (invoker && !invoker->isOperator())
        return;
    if ((invoker && (args.size() < 1 || args.size() > 4)) || (!invoker && (args.size() != 2 && args.size() != 4)))
        return; // TODO(huntears): Error output

    bool isImplicitTeleportee = args.size() == 1 || args.size() == 3;
    bool isPositionDestination = args.size() == 3 || args.size() == 4;

    std::string destX;
    std::string destY;
    std::string destZ;

    std::string entityDest;

    if (args.size() == 3) {
        destX = args.at(0);
        destY = args.at(1);
        destZ = args.at(2);
    } else if (args.size() == 4) {
        destX = args.at(1);
        destY = args.at(2);
        destZ = args.at(3);
    }

    if (args.size() == 2)
        entityDest = args.at(1);
    else if (args.size() == 1)
        entityDest = args.at(0);

    std::vector<std::reference_wrapper<Entity>> toTeleport;

    if (isImplicitTeleportee)
        toTeleport.push_back(*invoker);
    else if (isSelector(args.at(0))) {
        if (!invoker)
            return; // TODO(huntears): Handle selectors in console
        fillSelector(args.at(0), toTeleport, invoker->getDimension()->getEntities(), invoker->getDimension()->getPlayers(), invoker);
    } else {
        for (auto &[_, client] : Server::getInstance()->getClients()) {
            if (client->getPlayer() && client->getPlayer()->getUsername() == args.at(0)) {
                toTeleport.push_back(*client->getPlayer());
                break;
            }
        }
    }

    if (!isPositionDestination) {
        Player *endPoint = nullptr;
        if (isSelector(entityDest)) {
            if (!isSingleSelector(entityDest))
                return; // TODO(huntears): Error message
            if (!invoker)
                return; // TODO(huntears): Handle selectors in console
            fillSingleSelector(args.at(0), *endPoint, invoker->getDimension()->getEntities(), invoker->getDimension()->getPlayers(), invoker);
        } else {
            for (auto &[_, client] : Server::getInstance()->getClients()) {
                if (client->getPlayer() && client->getPlayer()->getUsername() == entityDest) {
                    endPoint = client->getPlayer().get();
                    break;
                }
            }
        }
        if (endPoint == nullptr)
            return; // TODO(huntears): Error message
        for (Entity &moving : toTeleport) {
            auto finalPos = endPoint->getPosition();
            moving.teleport(finalPos);
            if (moving.getType() == EntityType::Player) {
                auto &player = (Player &) moving;
                auto toSend = fmt::format("Teleported {} to {}", player.getUsername(), endPoint->getUsername());
                if (invoker)
                    invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(toSend, *invoker);
                else
                    LINFO(toSend);
            }
        }
    } else {
        bool isXRelative = destX.at(0) == '~';
        bool isYRelative = destY.at(0) == '~';
        bool isZRelative = destZ.at(0) == '~';

        double X = 0;
        double Y = 0;
        double Z = 0;

        std::string toParseX = destX.substr(isXRelative ? 1 : 0);
        std::string toParseY = destY.substr(isYRelative ? 1 : 0);
        std::string toParseZ = destZ.substr(isZRelative ? 1 : 0);

        try {
            X = toParseX.size() == 0 ? 0 : std::stod(toParseX);
            Y = toParseY.size() == 0 ? 0 : std::stod(toParseY);
            Z = toParseZ.size() == 0 ? 0 : std::stod(toParseZ);
        } catch (const std::invalid_argument &e) {
            LERROR("Bruh");
            return; // TODO(huntears): Error message
        }

        for (Entity &moving : toTeleport) {
            auto position = moving.getPosition();
            auto finalPos = Vector3<double> {
                isXRelative ? position.x + X : X,
                isYRelative ? position.y + Y : Y,
                isZRelative ? position.z + Z : Z,
            };
            moving.teleport(finalPos);
            if (moving.getType() == EntityType::Player) {
                auto &player = (Player &) moving;
                auto toSend = fmt::format("Teleported {} to {}", player.getUsername(), finalPos);
                if (invoker)
                    invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(toSend, *invoker);
                else
                    LINFO(toSend);
            }
        }
    }

    // LINFO("Called a tp!");
}

void command_parser::Teleport::execute(UNUSED std::vector<std::string> &args, Player *invoker) const { return ::execute(args, invoker); }

void command_parser::Tp::execute(UNUSED std::vector<std::string> &args, Player *invoker) const { return ::execute(args, invoker); }

void command_parser::Teleport::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(TELEPORT_HELP, *invoker);
    } else
        LINFO(TELEPORT_HELP);
}

void command_parser::Tp::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(TP_HELP, *invoker);
    } else
        LINFO(TP_HELP);
}

void command_parser::Teleport::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete stop");
}

void command_parser::Tp::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete stop");
}
