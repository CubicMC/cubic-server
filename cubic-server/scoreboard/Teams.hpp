#ifndef CUBICSERVER_SCOREBOARD_TEAMS_HPP
#define CUBICSERVER_SCOREBOARD_TEAMS_HPP

#include <string>
#include <unordered_set>

namespace Scoreboard {
    namespace Team {
        namespace NametagVisibility {
            enum NametagVisibility {
                never = 0,
                hideForOtherTeams,
                hideForOwnTeam,
                always
            };
        };

        namespace DeathMessageVisibility {
            enum DeathMessageVisibility {
                never = 0,
                hideForOtherTeams,
                hideForOwnTeam,
                always
            };
        };

        namespace CollisionRule {
            enum CollisionRule {
                always = 0,
                pushOwnTeam,
                never,
                pushOtherTeams
            };
        };

        enum Color {
            Unset = -1,
            Black = 0,
            DarkBlue,
            DarkGreen,
            DarkAqua,
            DarkRed,
            DarkPurple,
            Gold,
            Gray,
            DarkGray,
            Blue,
            Green,
            Aqua,
            Red,
            LightPurple,
            Yellow,
            White
        };

        class Team {
        public:
            Team(const std::string &name);
            Team(const std::string &name, const Color &color);
            Team(const std::string &name, const std::string &displayName);
            Team(const std::string &name, const Color &color, const std::string &displayName);
            ~Team();

            const std::unordered_set<std::string> &getMember(void) const noexcept;
            bool isMember(const std::string &name) const;
            bool isAllowingFriendlyFire(void) const noexcept;
            bool isSeeingFriendlyInvisibles(void) const noexcept;
            NametagVisibility::NametagVisibility getNametagVisibility(void) const noexcept;
            DeathMessageVisibility::DeathMessageVisibility getDeathMessageVisibility(void) const noexcept;
            const CollisionRule::CollisionRule &getCollisionRule(void) const noexcept;
            const std::string &getDisplayName(void) const noexcept;
            const std::string &getPrefix(void) const noexcept;
            const std::string &getSuffix(void) const noexcept;
            const Color &getColor(void) const noexcept;

            void addMember(const std::string &name);
            void removeMember(const std::string &name);
            void emptyMembers(void);
            void allowFriendlyFire(bool rule) noexcept;
            void seeFriendlyInvisibles(bool rule) noexcept;
            void setNametagVisibility(NametagVisibility::NametagVisibility rule) noexcept;
            void setDeathMessageVisibility(DeathMessageVisibility::DeathMessageVisibility rule) noexcept;
            void setCollisionRule(CollisionRule::CollisionRule rule) noexcept;
            void setDisplayName(const std::string &displayName) noexcept;
            void setPrefix(const std::string &prefix) noexcept;
            void setSuffix(const std::string &suffix) noexcept;
            void setColor(Color color) noexcept;

        private:
            bool _allowFriendlyFire;
            bool _seeFriendlyInvisibles;
            NametagVisibility::NametagVisibility _nametagVisibility;
            DeathMessageVisibility::DeathMessageVisibility _deathMessageVisibility;
            CollisionRule::CollisionRule _collisionRule;
            const std::string _name;
            Color _color;
            std::string _displayName; // json format
            std::string _memberNamePrefix; // json format
            std::string _memberNameSuffix; // json format
            std::unordered_set<std::string> _members;
        };
    };
};

#endif /* CUBICSERVER_SCOREBOARD_TEAMS_HPP */
