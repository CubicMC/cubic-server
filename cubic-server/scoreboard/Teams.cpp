#include "Teams.hpp"

namespace Scoreboard {
    namespace Team {
        Team::Team(const std::string &name) : _name(name)
        {}

        Team::Team(const std::string &name, const std::string &displayName) : _name(name), _displayName(displayName)
        {}

        Team::~Team()
        {}

        const std::unordered_set<std::string> &Team::getMember(void) const noexcept
        {
            return (this->_members);
        }

        bool Team::isMember(const std::string &name) const
        {
            return (this->_members.contains(name));
        }

        bool Team::isAllowingFriendlyFire(void) const noexcept
        {
            return (this->_allowFriendlyFire);
        }

        bool Team::isSeeingFriendlyInvisibles(void) const noexcept
        {
            return (this->_seeFriendlyInvisibles);
        }

        NametagVisibility::NametagVisibility Team::getNametagVisibility(void) const noexcept
        {
            return (this->_nametagVisibility);
        }

        DeathMessageVisibility::DeathMessageVisibility Team::getDeathMessageVisibility(void) const noexcept
        {
            return (this->_deathMessageVisibility);
        }

        const CollisionRule::CollisionRule &Team::getCollisionRule(void) const noexcept
        {
            return (this->_collisionRule);
        }

        const std::string &Team::getDisplayName(void) const noexcept
        {
            return (this->_displayName);
        }

        const std::string &Team::getPrefix(void) const noexcept
        {
            return (this->_memberNamePrefix);
        }

        const std::string &Team::getSuffix(void) const noexcept
        {
            return (this->_memberNameSuffix);
        }

        const Color &Team::getColor(void) const noexcept
        {
            return (this->_color);
        }

        void Team::addMember(const std::string &name)
        {
            this->_members.insert(name);
        }

        void Team::removeMember(const std::string &name)
        {
            this->_members.erase(name);
        }

        void Team::emptyMembers(void)
        {
            this->_members.clear();
        }

        void Team::allowFriendlyFire(bool rule) noexcept
        {
            this->_allowFriendlyFire = rule;
        }

        void Team::seeFriendlyInvisibles(bool rule) noexcept
        {
            this->_seeFriendlyInvisibles = rule;
        }

        void Team::setNametagVisibility(NametagVisibility::NametagVisibility rule) noexcept
        {
            this->_nametagVisibility = rule;
        }

        void Team::setDeathMessageVisibility(DeathMessageVisibility::DeathMessageVisibility rule) noexcept
        {
            this->_deathMessageVisibility = rule;
        }

        void Team::setCollisionRule(CollisionRule::CollisionRule rule) noexcept
        {
            this->_collisionRule = rule;
        }

        void Team::setDisplayName(const std::string &displayName) noexcept
        {
            this->_displayName = displayName;
        }

        void Team::setPrefix(const std::string &prefix) noexcept
        {
            this->_memberNamePrefix = prefix;
        }

        void Team::setSuffix(const std::string &suffix) noexcept
        {
            this->_memberNameSuffix = suffix;
        }

        void Team::setColor(Color color) noexcept
        {
            this->_color = color;
        }
    };
};