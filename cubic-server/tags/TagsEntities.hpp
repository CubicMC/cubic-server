#include <vector>

static const std::vector<std::string> tagsEntities = {
	"arrow,spectral_arrow",
	"drowned,guardian,elder_guardian",
	"tropical_fish,pufferfish,salmon,cod,squid,glow_squid,tadpole",
	"bee",
	"camel,chicken,donkey,horse,llama,mule,pig,ravager,spider,strider,trader_llama,zombie_horse",
	"iron_golem,snow_golem,shulker,allay,bat,bee,blaze,cat,chicken,ghast,phantom,magma_cube,ocelot,parrot,wither",
	"strider,blaze,magma_cube",
	"stray,polar_bear,snow_golem,wither",
	"slime,magma_cube",
	"#arrows,snowball,fireball,small_fireball,egg,trident,dragon_fireball,wither_skull",
	"slime,magma_cube",
	"rabbit,endermite,silverfish,fox",
	"evoker,illusioner,pillager,ravager,vindicator,witch",
	"skeleton,stray,wither_skeleton",
};

enum class Entities {
	ARROWS,
	AXOLOTL_ALWAYS_HOSTILES,
	AXOLOTL_HUNT_TARGETS,
	BEEHIVE_INHABITORS,
	DISMOUNTS_UNDERWATER,
	FALL_DAMAGE_IMMUNE,
	FREEZE_HURTS_EXTRA_TYPES,
	FREEZE_IMMUNE_ENTITY_TYPES,
	FROG_FOOD,
	IMPACT_PROJECTILES,
	NON_CONTROLLING_RIDER,
	POWDER_SNOW_WALKABLE_MOBS,
	RAIDERS,
	SKELETONS,
};