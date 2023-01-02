#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_HELP_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_HELP_HPP

#include "logging/logger.hpp"

#include <vector>
#include <unordered_map>
#include <functional>
#include <string>

namespace help {
    void help(std::vector<std::string>& args) {
        logging::Logger::get_instance()->info("/help [<command>]");
    }

    //TODO: Move this code
    const std::unordered_map<std::string, std::function<void(std::vector<std::string>&)>> helps {
            {"help", help::help}
    };

    const std::vector<std::string> allCommands = {
        "/advancement (grant|revoke)",
        "/attribute <target> <attribute> (get|base|modifier)",
        "/execute (run|if|unless|as|at|store|positioned|rotated|facing|align|anchored|in)",
        "/bossbar (add|remove|list|set|get)",
        "/clear [<targets>]",
        "/clone <begin> <end> <destination> [replace|masked|filtered]",
        "/data (merge|get|remove|modify)",
        "/datapack (enable|disable|list)",
        "/debug (start|stop|function)",
        "/defaultgamemode (survival|creative|adventure|spectator)",
        "/difficulty [peaceful|easy|normal|hard]",
        "/effect (clear|give)",
        "/me <action>",
        "/enchant <targets> <enchantment> [<level>]",
        "/experience (add|set|query)",
        "/xp -> experience",
        "/fill <from> <to> <block> [replace|keep|outline|hollow|destroy]",
        "/forceload (add|remove|query)",
        "/function <name>",
        "/gamemode (survival|creative|adventure|spectator)",
        "/gamerule (announceAdvancements|commandBlockOutput|disableElytraMovementCheck|disableRaids|doDaylightCycle|doEntityDrops|doFireTick|doImmediateRespawn|doInsomnia|doLimitedCrafting|doMobLoot|doMobSpawning|doPatrolSpawning|doTileDrops|doTraderSpawning|doWardenSpawning|doWeatherCycle|drowningDamage|fallDamage|fireDamage|forgiveDeadPlayers|freezeDamage|keepInventory|logAdminCommands|maxCommandChainLength|maxEntityCramming|mobGriefing|naturalRegeneration|playersSleepingPercentage|randomTickSpeed|reducedDebugInfo|sendCommandFeedback|showDeathMessages|spawnRadius|spectatorsGenerateChunks|universalAnger)",
        "/give <targets> <item> [<count>]",
        "/help [<command>]",
        "/item (replace|modify)",
        "/kick <targets> [<reason>]",
        "/kill [<targets>]",
        "/list [uuids]",
        "/locate (structure|biome|poi)",
        "/loot (replace|insert|give|spawn)",
        "/msg <targets> <message>",
        "/tell -> msg",
        "/w -> msg",
        "/particle <name> [<pos>]",
        "/place (feature|jigsaw|structure|template)",
        "/playsound <sound> (master|music|record|weather|block|hostile|neutral|player|ambient|voice)",
        "/reload",
        "/recipe (give|take)",
        "/say <message>",
        "/schedule (function|clear)",
        "/scoreboard (objectives|players)",
        "/seed",
        "/setblock <pos> <block> [destroy|keep|replace]",
        "/spawnpoint [<targets>]",
        "/setworldspawn [<pos>]",
        "/spectate [<target>]",
        "/spreadplayers <center> <spreadDistance> <maxRange> (<respectTeams>|under)",
        "/stopsound <targets> [*|master|music|record|weather|block|hostile|neutral|player|ambient|voice]",
        "/summon <entity> [<pos>]",
        "/tag <targets> (add|remove|list)",
        "/team (list|add|remove|empty|join|leave|modify)",
        "/teammsg <message>",
        "/tm -> teammsg",
        "/teleport (<location>|<destination>|<targets>)",
        "/tp -> teleport",
        "/tellraw <targets> <message>",
        "/time (set|add|query)",
        "/title <targets> (clear|reset|title|subtitle|actionbar|times)",
        "/trigger <objective> [add|set]",
        "/weather (clear|rain|thunder)",
        "/worldborder (add|set|center|damage|get|warning)",
        "/jfr (start|stop)",
        "/ban-ip <target> [<reason>]",
        "/banlist [ips|players]",
        "/ban <targets> [<reason>]",
        "/deop <targets>",
        "/op <targets>",
        "/pardon <targets>",
        "/pardon-ip <target>",
        "/perf (start|stop)",
        "/save-all [flush]",
        "/save-off",
        "/save-on",
        "/setidletimeout <minutes>",
        "/stop",
        "/whitelist (on|off|list|add|remove|reload)"
    };

    void execute(std::vector<std::string>& args) {
        if (args.empty()) {
            for (auto &command : allCommands) {
                logging::Logger::get_instance()->info(command);
            }
        }
        else {
            if (helps.find(args[0]) != helps.end()) {
                helps.at(args[0])(args);
            } else {
                logging::Logger::get_instance()->info("Unknown command or insufficient permissions");
            }
        }
    }
}

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_HELP_HPP
