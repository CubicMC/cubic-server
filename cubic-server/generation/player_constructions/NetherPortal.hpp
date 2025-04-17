#ifndef CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
#define CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP

#include "math/Vector2.hpp"
#include "blocks.hpp"
#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

#include <array>
#include <unistd.h>

/* Error codes */
enum class PortalError {
    PORTAL_OUT_OF_BOUNDARIES = -1,
    PORTAL_WRONG_DIRECTION = -2,
    PORTAL_WRONG_SIZE = -3,
    PORTAL_WRONG_BLOCK = -4,
    PORTAL_BAD_PORTAL = -42,
    PORTAL_NONE = -84
};

/* The minimum & maximum sizes of the portal */
enum class PortalBoundary {
    PORTAL_MIN_WIDTH = 4,
    PORTAL_MIN_HEIGHT = 5,
    PORTAL_MAX_WIDTH = 23,
    PORTAL_MAX_HEIGHT = 23,
    PORTAL_OUT_OF_BOUNDARIES = static_cast<int>(PortalError::PORTAL_OUT_OF_BOUNDARIES)
};

/* The 2 dimensions defining the portal */
enum class PortalSize {
    PORTAL_WIDTH,
    PORTAL_HEIGHT,
    PORTAL_WRONG_SIZE = static_cast<int>(PortalError::PORTAL_WRONG_SIZE)
};

/* The horizontal direction of the portal (on the X or Z axis) */
enum class PortalDirection {
    PORTAL_X_AXIS,
    PORTAL_Z_AXIS,
    PORTAL_WRONG_DIRECTION = static_cast<int>(PortalError::PORTAL_WRONG_DIRECTION)
};

/* The location of ignition of the portal (see schema on PR) */
enum class PortalIgnition {
    PORTAL_TOP_CENTER,
    PORTAL_LEFT_CENTER,
    PORTAL_RIGHT_CENTER,
    PORTAL_BOTTOM_CENTER,
    PORTAL_TOP_RIGHT_CORNER,
    PORTAL_TOP_LEFT_CORNER,
    PORTAL_BOTTOM_RIGHT_CORNER,
    PORTAL_BOTTOM_LEFT_CORNER,
    PORTAL_NONE = static_cast<int>(PortalError::PORTAL_NONE)
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
    NetherPortal(std::shared_ptr<Dimension> dim, Position pos):
        _dim(dim),
        _pos(pos)
    {
        setIgnitedBlock();
        setLeftCornerPosition();
        setDirection();
        setSize();
    }

    /**
     * @brief Sets _ignitedBlock to (TOP_CENTER, LEFT_CENTER, RIGHT_CENTER, BOTTOM_CENTER, TOP_RIGHT_CORNER, TOP_LEFT_CORNER, BOTTOM_RIGHT_CORNER, BOTTOM_LEFT_CORNER, NONE) depending on which side of the alleged frame the ignited block is located
     *
     */
    void setIgnitedBlock();
    
    /**
     * @brief Sets _bottomLeftCorner to the position of the leftmost obsidian block on the bottom side of the portal, from the inner part of the portal (the corner block, if obsidian, isn't taken into account)
     *
     */
    void setBottomLeftCorner();

    /**
     * @brief Sets _direction to the horizontal direction of the portal, meaning if the portal is positionned on the X or Z axis, and whether the coordinates are positives or negatives (POS_X, NEG_X, POS_Z, NEG_Z) (atm, only works when lighting a bottom block)
     *
     */
    void setDirection();

    /**
     * @brief Sets _size to the two dimentional sizes of the portal (atm, only works when lighting a bottom block)
     *
     */
    void setSize();

    /**
     * @brief Open the portal within the frame
     *
     * @param pos The position of the fire block created by the Flint&Steel
     */
    void openPortal();

private:
    std::shared_ptr<Dimension> _dim; /**< The dimension where the portal is in */
    Position _pos; /**< The position of the fire block created by the Flint&Steel */
    PortalIgnition _ignitedBlock; /**< The side of the alleged frame the ignited block is located */
    Position _bottomLeftCorner; /**< The position of the bottom-left block under the inner frame (used for calculations) */
    PortalDirection _direction; /**< The horizontal direction of the portal (X or Z) */
    Vector2<int> _size; /**< The size of the inner part of the portal {PORTAL_WIDTH, PORTAL_HEIGHT} */
};

#endif // CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
