#include <vector>

static const std::vector<std::string> tagsPoi = {
	"armorer,butcher,cartographer,cleric,farmer,fisherman,fletcher,leatherworker,librarian,mason,shepherd,toolsmith,weaponsmith",
	"beehive,bee_nest",
	"#acquirable_job_site,home,meeting",
};

enum class Poi {
	ACQUIRABLE_JOB_SITE,
	BEE_HOME,
	VILLAGE,
};