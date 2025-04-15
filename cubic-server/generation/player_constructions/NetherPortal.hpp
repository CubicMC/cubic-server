#ifndef CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
#define CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP

#include "math/Vector2.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

#include <array>

/* The minimum & maximum sizes of the portal */
enum class PortalBoundary {
    PORTAL_MIN_WIDTH,
    PORTAL_MIN_HEIGHT,
    PORTAL_MAX_WIDTH,
    PORTAL_MAX_HEIGHT
};

/* The 2 axes defining the portal */
enum class PortalAxis {
    PORTAL_WIDTH,
    PORTAL_HEIGHT
};

/* The horizontal direction of the portal on the X or Z axis */
enum class PortalDirection {
    PORTAL_POS_X,
    PORTAL_NEG_X,
    PORTAL_POS_Z,
    PORTAL_NEG_Z
};

/* Error codes */
enum class PortalError {
    PORTAL_SIZE_OVERFLOW = -1,
    PORTAL_WRONG_DIRECTION = -2,
    PORTAL_WRONG_AXIS = -3
};

/**
 * @brief A Nether Portal is a player construction that acts as a gateway between the Overworld and the Nether dimensions. It is made of Obsidian and ignited with a Flint&Steel.
 * The portal is built like this :
 *      0 0 0 0
 *      0 1 1 0
 *      0 1 1 0
 *      0 1 1 0
 *      0 0 0 0
 *
 * 0 = Obsidian
 * 1 = Air
 *
 * If one of the 1 is ignited (becomes "Fire"), then all the 1 become a "Nether Portal" block
 *
 */
class NetherPortal {
public:
    NetherPortal(std::shared_ptr<Dimension> dim):
        _dim(dim)
    {
    }

    /**
     * @brief
     *
     */
     Vector2<int> setSize(Vector2<int> value);

    /**
     * @brief Sets the direction of the portal
     *
     * @param value The position of the bottom-left corner of the frame
     * @return the value of NetherPortal::dimension (POS_X, NEG_X, POS_Z, NEG_Z)
     */
    int setDirection(int value);

private:
    std::shared_ptr<Dimension> _dim; /**< The dimension where the portal is in */
    Vector2<int> size; /**< The size of the sides of the portal {WIDTH, HEIGHT} */
    PortalDirection direction; /**< The horizontal direction of the portal */
};

#endif // CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
