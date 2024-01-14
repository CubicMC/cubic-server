#ifndef CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
#define CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP

#include "blocks.hpp"
#include "generation/generator.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

#include <array>

#define AXIS_UNDEFINED -1
#define AXIS_X 0
#define AXIS_Z 1
#define UNDEFINED_POS -1
#define NEGATIVE_POS 0
#define POSITIVE_POS 1

#define FRAME_WIDTH 4
#define FRAME_HEIGHT 5

struct Frame {
    int axis;
    int direction;
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
     * @brief Get the axis on which the frame is built (x or z)
     *
     * @param pos   The position of the frame
     * @return Frame  The axis and direction of the frame
     */
    Frame getFrame(Position pos);

    /**
     * @brief Build the portal within the already built frame
     *
     * @param pos   The position of the frame
     */
    void buildPortal(Position pos);

    /**
     * @brief Checks every layer of the alleged frame
     *
     * @param pos        The position of the bottom-left corner of the frame
     * @param axis       The axis of the frame (x or z)
     * @return true      There is a frame
     * @return false     There isn't a frame
     */
    bool checkLayers(Position pos, int axis);

private:
    /**
     * The dimension where the portal is in
     */
    std::shared_ptr<Dimension> _dim;
};

#endif // CUBICSERVER_GENERATION_PLAYER_CONSTRUCTIONS_NETHER_PORTAL_HPP
