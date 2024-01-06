#include "Dimension.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "chat/Message.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"

#include "Teams.hpp"

namespace Scoreboard {
namespace Team {
namespace NametagVisibility {
const std::string getProtocolFlag(const NametagVisibility &flag)
{
    switch (flag) {
    case never:
        return ("never");
        break;
    case hideForOtherTeams:
        return ("hideForOtherTeams");
        break;
    case hideForOwnTeam:
        return ("hideForOwnTeam");
        break;
    case always:
        return ("always");
        break;
    default:
        return ("always");
        break;
    }
    return ("always");
}
}

namespace CollisionRule {
const std::string getProtocolFlag(const CollisionRule &flag)
{
    switch (flag) {
    case always:
        return ("always");
        break;
    case pushOtherTeams:
        return ("pushOtherTeams");
        break;
    case pushOwnTeam:
        return ("pushOwnTeam");
        break;
    case never:
        return ("never");
        break;
    default:
        break;
    }
    return ("always");
}
}

Team::Team(const Scoreboard &scoreboard, const std::string &name):
    _scoreboard(scoreboard),
    _allowFriendlyFire(true),
    _seeFriendlyInvisibles(false),
    _nametagVisibility(NametagVisibility::always),
    _deathMessageVisibility(DeathMessageVisibility::always),
    _collisionRule(CollisionRule::always),
    _name(name),
    _color(Color::White),
    _displayName(name),
    _memberNamePrefix(""),
    _memberNameSuffix("")
{
    LDEBUG("Added team \"{}\"", name);
}

Team::Team(const Scoreboard &scoreboard, const std::string &name, const Color &color):
    _scoreboard(scoreboard),
    _allowFriendlyFire(true),
    _seeFriendlyInvisibles(false),
    _nametagVisibility(NametagVisibility::always),
    _deathMessageVisibility(DeathMessageVisibility::always),
    _collisionRule(CollisionRule::always),
    _name(name),
    _color(color),
    _displayName(name),
    _memberNamePrefix(""),
    _memberNameSuffix("")
{
    LDEBUG("Added team \"{}\"", name);
}

Team::Team(const Scoreboard &scoreboard, const std::string &name, const std::string &displayName):
    _scoreboard(scoreboard),
    _allowFriendlyFire(true),
    _seeFriendlyInvisibles(false),
    _nametagVisibility(NametagVisibility::always),
    _deathMessageVisibility(DeathMessageVisibility::always),
    _collisionRule(CollisionRule::always),
    _name(name),
    _color(Color::White),
    _displayName(displayName),
    _memberNamePrefix(""),
    _memberNameSuffix("")
{
    LDEBUG("Added team \"{}\"", name);
}

Team::Team(const Scoreboard &scoreboard, const std::string &name, const Color &color, const std::string &displayName):
    _scoreboard(scoreboard),
    _allowFriendlyFire(true),
    _seeFriendlyInvisibles(false),
    _nametagVisibility(NametagVisibility::always),
    _deathMessageVisibility(DeathMessageVisibility::always),
    _collisionRule(CollisionRule::always),
    _name(name),
    _color(color),
    _displayName(displayName),
    _memberNamePrefix(""),
    _memberNameSuffix("")
{
    LDEBUG("Added team \"{}\"", name);
}

Team::~Team() { LDEBUG("Removed team \"{}\"", this->_name); }

const std::unordered_set<std::string> &Team::getMembers(void) const noexcept { return (this->_members); }

bool Team::isMember(const std::string &name) const { return (this->_members.contains(name)); }

bool Team::isAllowingFriendlyFire(void) const noexcept { return (this->_allowFriendlyFire); }

bool Team::isSeeingFriendlyInvisibles(void) const noexcept { return (this->_seeFriendlyInvisibles); }

NametagVisibility::NametagVisibility Team::getNametagVisibility(void) const noexcept { return (this->_nametagVisibility); }

DeathMessageVisibility::DeathMessageVisibility Team::getDeathMessageVisibility(void) const noexcept { return (this->_deathMessageVisibility); }

const CollisionRule::CollisionRule &Team::getCollisionRule(void) const noexcept { return (this->_collisionRule); }

const std::string &Team::getName(void) const noexcept { return (this->_name); }

const chat::Message &Team::getDisplayName(void) const noexcept { return (this->_displayName); }

const chat::Message &Team::getPrefix(void) const noexcept { return (this->_memberNamePrefix); }

const chat::Message &Team::getSuffix(void) const noexcept { return (this->_memberNameSuffix); }

const Color &Team::getColor(void) const noexcept { return (this->_color); }

void Team::addMember(const std::string &name)
{
    this->_members.insert(name);
    this->sendJoinTeam(name);
}

void Team::removeMember(const std::string &name)
{
    this->_members.erase(name);
    this->sendLeaveTeam(name);
}

void Team::allowFriendlyFire(bool rule) noexcept
{
    this->_allowFriendlyFire = rule;
    this->sendUpdateTeam();
}

void Team::seeFriendlyInvisibles(bool rule) noexcept
{
    this->_seeFriendlyInvisibles = rule;
    this->sendUpdateTeam();
}

void Team::setNametagVisibility(NametagVisibility::NametagVisibility rule) noexcept
{
    this->_nametagVisibility = rule;
    this->sendUpdateTeam();
}

void Team::setDeathMessageVisibility(DeathMessageVisibility::DeathMessageVisibility rule) noexcept
{ // death message visibility is an internal flag, we should not send it to any client
    this->_deathMessageVisibility = rule;
}

void Team::setCollisionRule(CollisionRule::CollisionRule rule) noexcept
{
    this->_collisionRule = rule;
    this->sendUpdateTeam();
}

void Team::setDisplayName(const chat::Message &displayName) noexcept
{
    this->_displayName = displayName;
    this->sendUpdateTeam();
}

void Team::setPrefix(const chat::Message &prefix) noexcept
{
    this->_memberNamePrefix = prefix;
    this->sendUpdateTeam();
}

void Team::setSuffix(const chat::Message &suffix) noexcept
{
    this->_memberNameSuffix = suffix;
    this->sendUpdateTeam();
}

void Team::setColor(Color color) noexcept
{
    this->_color = color;
    this->sendUpdateTeam();
}

void Team::sendUpdateTeam(void) const
{
    uint8_t friendlyFlags = (0b00000000 | this->_seeFriendlyInvisibles << 1) | this->_allowFriendlyFire;

    // clang-format off
    const protocol::UpdateTeams update {
        this->_name,
        2,
        this->_displayName,
        friendlyFlags,
        NametagVisibility::getProtocolFlag(this->_nametagVisibility),
        CollisionRule::getProtocolFlag(this->_collisionRule),
        this->_color,
        this->_memberNamePrefix,
        this->_memberNameSuffix
    };
    //clang-format on
    for (const auto &[_, world] : this->_scoreboard.getWorldGroup().getWorlds()) {
        for (const auto &[_, dimension] : world->getDimensions()) {
            for (const auto &player : dimension->getPlayers()) {
                player->sendUpdateTeams(update);
            }
        }
    }
}

void Team::sendJoinTeam(const std::string &name) const
{
    // join team packet only sens the name of the team and the entity joining it
    const protocol::UpdateTeams update {this->_name, 3, "", 0, "", "", this->_color, "", "", {name}};
    LDEBUG("{} joined team {}", name, this->_name);
    for (const auto &[_, world] : this->_scoreboard.getWorldGroup().getWorlds()) {
        for (const auto &[_, dimension] : world->getDimensions()) {
            for (const auto &player : dimension->getPlayers()) {
                player->sendUpdateTeams(update);
            }
        }
    }
}

void Team::sendLeaveTeam(const std::string &name) const
{
    // leave team packet only sens the name of the team and the entity leaving it
    const protocol::UpdateTeams update {this->_name, 4, "", 0, "", "", this->_color, "", "", {name}};
    LDEBUG("{} left team {}", name, this->_name);
    for (const auto &[_, world] : this->_scoreboard.getWorldGroup().getWorlds()) {
        for (const auto &[_, dimension] : world->getDimensions()) {
            for (const auto &player : dimension->getPlayers()) {
                player->sendUpdateTeams(update);
            }
        }
    }
}
}
}
