#ifndef CUBICSERVER_SCOREBOARD_TEAMS_HPP
#define CUBICSERVER_SCOREBOARD_TEAMS_HPP

#include <string>
#include <unordered_set>

#include "chat/Message.hpp"
#include "protocol/ClientPackets.hpp"

namespace Scoreboard {
class Scoreboard;

namespace Team {
namespace NametagVisibility {
enum NametagVisibility {
    never = 0,
    hideForOtherTeams,
    hideForOwnTeam,
    always
};
const std::string getProtocolFlag(const NametagVisibility &flag);
}

namespace DeathMessageVisibility {
enum DeathMessageVisibility {
    never = 0,
    hideForOtherTeams,
    hideForOwnTeam,
    always
};
}

namespace CollisionRule {
enum CollisionRule {
    always = 0,
    pushOwnTeam,
    never,
    pushOtherTeams
};
const std::string getProtocolFlag(const CollisionRule &flag);
}

using Color = protocol::UpdateTeams::Color;

class Team {
public:
    Team(const Scoreboard &scoreboard, const std::string &name);
    Team(const Scoreboard &scoreboard, const std::string &name, const Color &color);
    Team(const Scoreboard &scoreboard, const std::string &name, const std::string &displayName);
    Team(const Scoreboard &scoreboard, const std::string &name, const Color &color, const std::string &displayName);
    ~Team();

    // getters
    const std::unordered_set<std::string> &getMembers(void) const noexcept;
    bool isMember(const std::string &name) const;
    bool isAllowingFriendlyFire(void) const noexcept;
    bool isSeeingFriendlyInvisibles(void) const noexcept;
    NametagVisibility::NametagVisibility getNametagVisibility(void) const noexcept;
    DeathMessageVisibility::DeathMessageVisibility getDeathMessageVisibility(void) const noexcept;
    const CollisionRule::CollisionRule &getCollisionRule(void) const noexcept;
    const std::string &getName(void) const noexcept;
    const chat::Message &getDisplayName(void) const noexcept;
    const chat::Message &getPrefix(void) const noexcept;
    const chat::Message &getSuffix(void) const noexcept;
    const Color &getColor(void) const noexcept;

    // setters
    void addMember(const std::string &name);
    void removeMember(const std::string &name);
    void allowFriendlyFire(bool rule) noexcept;
    void seeFriendlyInvisibles(bool rule) noexcept;
    void setNametagVisibility(NametagVisibility::NametagVisibility rule) noexcept;
    void setDeathMessageVisibility(DeathMessageVisibility::DeathMessageVisibility rule) noexcept;
    void setCollisionRule(CollisionRule::CollisionRule rule) noexcept;
    void setDisplayName(const chat::Message &displayName) noexcept;
    void setPrefix(const chat::Message &prefix) noexcept;
    void setSuffix(const chat::Message &suffix) noexcept;
    void setColor(Color color) noexcept;

    // protocol functions
    void sendUpdateTeam(void) const;
    void sendJoinTeam(const std::string &name) const;
    void sendLeaveTeam(const std::string &name) const;

private:
    const Scoreboard &_scoreboard;
    bool _allowFriendlyFire;
    bool _seeFriendlyInvisibles;
    NametagVisibility::NametagVisibility _nametagVisibility;
    DeathMessageVisibility::DeathMessageVisibility _deathMessageVisibility;
    CollisionRule::CollisionRule _collisionRule;
    const std::string _name;
    Color _color;
    chat::Message _displayName; // json format
    chat::Message _memberNamePrefix; // json format
    chat::Message _memberNameSuffix; // json format
    std::unordered_set<std::string> _members;
};
}
}

#endif /* CUBICSERVER_SCOREBOARD_TEAMS_HPP */
