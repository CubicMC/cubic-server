#ifndef CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
#define CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP

#include "math/Vector2.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

#include <array>

/* Error codes */
enum class PortalError {
    PORTAL_NONE = 0,
    PORTAL_SIZE_OVERFLOW = -1,
    PORTAL_WRONG_DIRECTION = -2,
    PORTAL_WRONG_AXIS = -3,
    PORTAL_WRONG_BLOCK = -4,
    PORTAL_BAD_PORTAL = -42
};

/* The minimum & maximum sizes of the portal */
enum class PortalBoundary {
    PORTAL_MIN_WIDTH = 4,
    PORTAL_MIN_HEIGHT = 5,
    PORTAL_MAX_WIDTH = 23,
    PORTAL_MAX_HEIGHT = 23,
    PORTAL_WRONG_SIZE = static_cast<std::underlying_type_t<PortalDirection>>(PortalError::PORTAL_BAD_PORTAL)
};

/* The 2 axes defining the portal */
enum class PortalAxis {
    PORTAL_WIDTH,
    PORTAL_HEIGHT,
    PORTAL_WRONG_AXIS = static_cast<std::underlying_type_t<PortalDirection>>(PortalError::PORTAL_WRONG_AXIS)
};

/* The horizontal direction of the portal on the X or Z axis */
enum class PortalDirection {
    PORTAL_POS_X,
    PORTAL_NEG_X,
    PORTAL_POS_Z,
    PORTAL_NEG_Z,
    PORTAL_WRONG_DIRECTION = static_cast<std::underlying_type_t<PortalDirection>>(PortalError::PORTAL_WRONG_DIRECTION)
};

/* The blocks involved at some point in the building of the portal */
enum class PortalBlocks {
    PORTAL_OBSIDIAN = Blocks::Obsidian::toProtocol(),
    PORTAL_NETHER_X = Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::X),
    PORTAL_NETHER_Z = Blocks::NetherPortal::toProtocol(Blocks::NetherPortal::Properties::Axis::Z),
    PORTAL_AIR = Blocks::Air::toProtocol(),
    PORTAL_FIRE = Blocks::Fire::toProtocol(Blocks::Fire::Properties::Age::ZERO, Blocks::Fire::Properties::East::FALSE, Blocks::Fire::Properties::North::FALSE, Blocks::Fire::Properties::South::FALSE, Blocks::Fire::Properties::Up::FALSE, Blocks::Fire::Properties::West::FALSE),
    PORTAL_WRONG_BLOCK = static_cast<std::underlying_type_t<PortalDirection>>(PortalError::PORTAL_WRONG_BLOCK)
}

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
     * @brief Computes the horizontal direction of the portal, meaning if the portal is positionned on the X or Z axis, and whether the coordinates are positives or negatives (POS_X, NEG_X, POS_Z, NEG_Z) (atm, only works when lighting a bottom block)
     *
     * @param pos The position of the ignited block
     * @return A PortalDirection containing the horizontal direction of the portal (POS_X, NEG_X, POS_Z, NEG_Z)
     */
    PortalDirection computeDirection(Position pos);

    /**
     * @brief Computes the two dimentional sizes of the portal (atm, only works when lighting a bottom block)
     *
     * @param pos The position of the ignited block
     * @param direction The direction of the alledged portal on the horizontal axis (X or Z)
     * @return A Vector2<int> containing the width & the height of the portal (respectively): {PORTAL_WIDTH, PORTAL_HEIGHT}
     */
    Vector2<int> computeSize(Position pos, PortalDirection direction);

    /**
     * @brief Build the portal within the already built frame
     *
     * @param pos   The position of the frame
     */
    void buildPortal(Position pos);

private:
    std::shared_ptr<Dimension> _dim; /**< The dimension where the portal is in */
    Vector2<int> _size; /**< The size of the portal {PORTAL_WIDTH, PORTAL_HEIGHT} */
    PortalDirection _direction; /**< The horizontal direction of the portal (POS_X, NEG_X, POS_Z, NEG_Z) */
};

#endif // CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
