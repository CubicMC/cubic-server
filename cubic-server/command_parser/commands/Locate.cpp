#include "Locate.hpp"
#include "Server.hpp"
#include "World.hpp"

#define PI 3.141592653589793

int isValidBiome(int mc, int id)
{
    if (id >= 170 && id <= 173)
        return 1;
    if (id >= 40 && id <= 43)
        return 1;
    if (id == 183 || id == 184)
        return mc;

    switch (id) {
        case 0:
        case 1:
        case 2:
        case 3:                 // windswept_hills
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:              // snowy_plains
        case 14:
        case 16:
        case 21:
        case 23:               // sparse_jungle
        case 24:
        case 25:               // stony_shore
        case 26:
        case 27:
        case 29:
        case 30:
        case 32:          // old_growth_pine_taiga
        case 34:          // windswept_forest
        case 35:
        case 36:
        case 37:
        case 38:   // wooded_badlands
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 129:
        case 131:        // windswept_gravelly_hills
        case 132:
        case 140:
        case 155:         // old_growth_birch_forest
        case 160:        // old_growth_spruce_taiga
        case 163:         // windswept_savanna
        case 165:
        case 168:
        case 174:
        case 175:
        case 177:
        case 178:
        case 179:
        case 182:
        case 180:
        case 181:
            return 1;
        default:
            return 0;
    }
}

static inline int next(uint64_t *rnds, const int bits)
{
    *rnds = (*rnds * 0x5deece66d + 0xb) & ((1ULL << 48) - 1);
    return (int) ((int64_t)*rnds >> (48 - bits));
}

static inline uint64_t nextLong(uint64_t *rnds)
{
    return ((uint64_t) next(rnds, 32) << 32) + next(rnds, 32);
}

static inline double nextDouble(uint64_t *rnds)
{
    uint64_t x = (uint64_t)next(rnds, 26);
    x <<= 27;
    x += next(rnds, 27);
    return (int64_t) x / (double) (1ULL << 53);
}

static inline void setRnds(uint64_t *rnds, uint64_t value)
{
    *rnds = (value ^ 0x5deece66d) & ((1ULL << 48) - 1);
}

void command_parser::Locate::autocomplete(std::vector<std::string>& args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete locate");
}

void command_parser::Locate::execute(std::vector<std::string>& args, Player *invoker) const
{
    Info info;
    if (args.size() < 2)
        return;
    else {
        info.mc = 23; //change second parameters in function of the minecraft version
        info.dim = 1000;
        info.flags = 0;
        info.seed = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getSeed();
        info.sha = 0;

        Pos p;
        p.x = 0;
        p.z = 0;

        StructureIter di;
        di.mc = info.mc;

        uint64_t validB = 0;
        uint64_t validM = 0;
        for (int i = 0; i < 64; i++) {
            if (isValidBiome(di.mc, i))
                validB |= (1ULL << i);
            if (isValidBiome(di.mc, i + 128))
                validM |= (1ULL << i);
        }

        if (&info) { //if minecraft version is up to 1.19.2
            uint64_t lbr = di.rnds;
            uint64_t temp = nextLong(&di.rnds);
            setRnds(&lbr, temp);
        }
        else {
            nextLong(&di.rnds);
            di.pos = di.nextapprox;
        }

        di.ringidx++;
        di.angle += 2 * PI / di.ringmax;

        if (di.ringidx == di.ringmax) {
            di.ringnum++;
            di.ringidx = 0;
            di.ringmax = di.ringmax + 2 * di.ringmax / (di.ringnum + 1);
            if (di.ringmax > 128 - di.index)
                di.ringmax = 128 - di.index;
            di.angle += nextDouble(&di.rnds) * PI * 2.0;
        }
        di.dist = (4.0 * 32.0) + (6.0 * di.ringnum * 32.0) + (nextDouble(&di.rnds) - 0.5) * 32 * 2.5;

        di.nextapprox.x = ((int) round(cos(di.angle) * di.dist) << 4) + 8;
        di.nextapprox.z = ((int) round(sin(di.angle) * di.dist) << 4) + 8;
        di.index++;
        
        std::string message = "The nearest " + args[2] + "is at [" + std::to_string(di.pos.x) + ", ~, " + std::to_string(di.pos.z) + "] (n block away)";
        LINFO(message); //change name of structure, position and distance
    }
}

void command_parser::Locate::help(std::vector<std::string>& args, Player *invoker) const
{
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
            // invoker->sendPlayerChatMessage("/locate structure <structure>"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/locate structure <structure>");
}