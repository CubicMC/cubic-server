#include <vector>

static const std::vector<std::string> tagsBanners = {
	"square_bottom_left,square_bottom_right,square_top_left,square_top_right,stripe_bottom,stripe_top,stripe_left,stripe_right,stripe_center,stripe_middle,stripe_downright,stripe_downleft,small_stripes,cross,straight_cross,triangle_bottom,triangle_top,triangles_bottom,triangles_top,diagonal_left,diagonal_up_right,diagonal_up_left,diagonal_right,circle,rhombus,half_vertical,half_horizontal,half_vertical_right,half_horizontal_bottom,border,curly_border,gradient,gradient_up,bricks",
	"creeper",
	"flower",
	"globe",
	"mojang",
	"piglin",
	"skull",
};

enum class Banners {
	NO_ITEM_REQUIRED,
	PATTERN_ITEM__CREEPER,
	PATTERN_ITEM__FLOWER,
	PATTERN_ITEM__GLOBE,
	PATTERN_ITEM__MOJANG,
	PATTERN_ITEM__PIGLIN,
	PATTERN_ITEM__SKULL,
};